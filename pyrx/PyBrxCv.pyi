from __future__ import annotations
from typing import *
from pyrx import Ap as PyAp
from pyrx import Br as PyBr
from pyrx import Db as PyDb
from pyrx import Ed as PyEd
from pyrx import Ge as PyGe
from pyrx import Gi as PyGi
from pyrx import Gs as PyGs
from pyrx import Pl as PyPl
from pyrx import Rx as PyRx
from pyrx import Sm as PySm
from pyrx import Ax as PyAx
from pyrx import Cv as PyBrxCv
from pyrx import Bim as PyBrxBim
from pyrx import Brx as PyBrx
import wx

T = TypeVar("T")

class _BoostPythonEnumMeta(type):
    # This is not a real class, it is just for better type hints

    def __call__(cls: type[T], value: int) -> T: ...

class _BoostPythonEnum(int, metaclass=_BoostPythonEnumMeta):
    # This is not a real class, it is just for better type hints

    values: ClassVar[dict[int, Self]]
    names: ClassVar[dict[str, Self]]

    name: str
Decreasing: StationEquationType  # 1
Increasing: StationEquationType  # 0
eAddBoundaries: TinSurfaceDefinitionType  # 10
eAddBreaklines: TinSurfaceDefinitionType  # 9
eAddDrawingObjects: TinSurfaceDefinitionType  # 22
eAddLine: TinSurfaceDefinitionType  # 16
eAddLines: TinSurfaceDefinitionType  # 17
eAddPoint: TinSurfaceDefinitionType  # 2
eAddPointClouds: TinSurfaceDefinitionType  # 28
eAddPointFiles: TinSurfaceDefinitionType  # 26
eAddPointGroups: TinSurfaceDefinitionType  # 27
eAddPoints: TinSurfaceDefinitionType  # 3
eAddWalls: TinSurfaceDefinitionType  # 11
eAlignment: Civil3dEntityType  # 0
eAlignmentsLabels: Civil3dLabels  # 2
eAllLabels: Civil3dLabels  # 255
eAngle: VAlignmentParameterConstraint  # 4
eArc: VAlignmentElementType  # 2
eArc_BestFit: HAlignmentParameterConstraint  # 310
eArc_CenterPassThrough: HAlignmentParameterConstraint  # 302
eArc_CenterRadius: HAlignmentParameterConstraint  # 301
eArc_PassThrough: HAlignmentParameterConstraint  # 307
eArc_PassThroughAttachToEnd: HAlignmentParameterConstraint  # 304
eArc_PassThroughDirection: HAlignmentParameterConstraint  # 305
eArc_PassThroughRadius: HAlignmentParameterConstraint  # 303
eArc_PointOnTangent: HAlignmentParameterConstraint  # 309
eArc_Radius: HAlignmentParameterConstraint  # 306
eArc_RadiusAndLength: HAlignmentParameterConstraint  # 308
eArc_ThreePoints: HAlignmentParameterConstraint  # 300
eAutomatic: VAlignmentParameterConstraint  # 5
eBlock: DrawingObjectType  # 2
eBlockAttachmentBottomCenter: BlockAttachment  # 7
eBlockAttachmentBottomLeft: BlockAttachment  # 6
eBlockAttachmentBottomRight: BlockAttachment  # 8
eBlockAttachmentInsertionPoint: BlockAttachment  # 9
eBlockAttachmentMiddleCenter: BlockAttachment  # 4
eBlockAttachmentMiddleLeft: BlockAttachment  # 3
eBlockAttachmentMiddleRight: BlockAttachment  # 5
eBlockAttachmentTopCenter: BlockAttachment  # 1
eBlockAttachmentTopLeft: BlockAttachment  # 0
eBlockAttachmentTopRight: BlockAttachment  # 2
eBorderTypeCircular: BorderType  # 2
eBorderTypeRectangular: BorderType  # 0
eBorderTypeRoundedRectangular: BorderType  # 1
eBoth: VAlignmentTangencyConstraint  # 4
eBrxCvDataTypeAngle: CvDataType  # 7
eBrxCvDataTypeArea: CvDataType  # 9
eBrxCvDataTypeAzimuth: CvDataType  # 10
eBrxCvDataTypeBool: CvDataType  # 1
eBrxCvDataTypeDate: CvDataType  # 4
eBrxCvDataTypeDirection: CvDataType  # 11
eBrxCvDataTypeDistance: CvDataType  # 12
eBrxCvDataTypeElevation: CvDataType  # 13
eBrxCvDataTypeInteger: CvDataType  # 3
eBrxCvDataTypeLatitude: CvDataType  # 15
eBrxCvDataTypeLinear: CvDataType  # 5
eBrxCvDataTypeLongitude: CvDataType  # 16
eBrxCvDataTypeNone: CvDataType  # 0
eBrxCvDataTypeRatio: CvDataType  # 8
eBrxCvDataTypeRotation: CvDataType  # 17
eBrxCvDataTypeSlope: CvDataType  # 14
eBrxCvDataTypeSpeed: CvDataType  # 19
eBrxCvDataTypeStation: CvDataType  # 6
eBrxCvDataTypeString: CvDataType  # 2
eBrxCvDataTypeVolume: CvDataType  # 18
eCenterline: Civil3dAlignmentType  # 0
eChordLength: ArcParameterType  # 3
eCivilPoint: DrawingObjectType  # 7
eClothoid: SpiralParameterType  # 0
eCompound: ArcType  # 0
eContourLabel: StyleManagerType  # 4
eCreateFromC3D: TinSurfaceDefinitionType  # 36
eCreateFromContours: TinSurfaceDefinitionType  # 38
eCreateFromCorridor: TinSurfaceDefinitionType  # 35
eCreateFromFaces: TinSurfaceDefinitionType  # 21
eCreateMerged: TinSurfaceDefinitionType  # 32
eCreateSnapshot: TinSurfaceDefinitionType  # 23
eCreateTypedSnapshot: TinSurfaceDefinitionType  # 34
eCubicParabola: SpiralParameterType  # 0
eCurbReturn: Civil3dAlignmentType  # 2
eCurveAngle: ArcParameterType  # 7
eCurveCurveReverseCurve: HAlignmentElementType  # 19
eCurveLabel: StyleManagerType  # 2
eCurveLength: ArcParameterType  # 4
eCurveLineCurve: HAlignmentElementType  # 17
eCurveReverseCurve: HAlignmentElementType  # 18
eCurveSpiral: HAlignmentElementType  # 9
eCurveSpiralSpiral: HAlignmentElementType  # 16
eCurveThroughPoint: ArcParameterType  # 8
eCustomSymbolFrameCircle: CustomSymbol  # 32
eCustomSymbolFrameSquare: CustomSymbol  # 64
eCustomSymbolSpotCross: CustomSymbol  # 2
eCustomSymbolSpotCross45: CustomSymbol  # 3
eCustomSymbolSpotEmpty: CustomSymbol  # 1
eCustomSymbolSpotPoint: CustomSymbol  # 0
eCustomSymbolSpotVerticalLine: CustomSymbol  # 4
eDefaultLabels: Civil3dLabels  # 6
eDeform: TinSurfaceDefinitionType  # 30
eDegreeOfCurve: ArcParameterType  # 1
eDeleteEdge: TinSurfaceDefinitionType  # 14
eDeleteEdges: TinSurfaceDefinitionType  # 15
eDeletePoint: TinSurfaceDefinitionType  # 4
eDeletePoints: TinSurfaceDefinitionType  # 5
eDirectionLeft: SpiralDirectionType  # 1
eDirectionRight: SpiralDirectionType  # 0
eDisplayModeAsComposed: DisplayMode  # 0
eDisplayModeStackedText: DisplayMode  # 1
eDisplayOrientationModel: DisplayOrientation  # 1
eDisplayOrientationPlan: DisplayOrientation  # 0
eDisplayOrientationProfile: DisplayOrientation  # 2
eDisplayOrientationSection: DisplayOrientation  # 3
eDynamicSurface: VAlignmentType  # 2
eElementExtensions: HAlignmentVisualStyle  # 4
eElements: VAlignmentVisualStyle  # 1
eExtensions: VAlignmentVisualStyle  # 4
eExternalDist: ArcParameterType  # 5
eFace: DrawingObjectType  # 5
eFixed: VAlignmentTangencyConstraint  # 1
eForcedInsertionBottom: ForcedInsertion  # 2
eForcedInsertionNone: ForcedInsertion  # 0
eForcedInsertionTop: ForcedInsertion  # 1
eGradingAccurate: GradingCalculationMethod  # 0
eGradingDrawDaylight: GradingVisualStyle  # 4
eGradingDrawNothing: GradingVisualStyle  # 0
eGradingDrawRays: GradingVisualStyle  # 2
eGradingDrawSurface: GradingVisualStyle  # 1
eGradingFast: GradingCalculationMethod  # 1
eGradingGradingOutsideSurface: GradingStatus  # 64
eGradingIncorrectInputData: GradingStatus  # 4
eGradingInputDataMissing: GradingStatus  # 2048
eGradingInputDataOutsideSurface: GradingStatus  # 32
eGradingInvalidInput: GradingStatus  # 4096
eGradingInvalidRule: GradingStatus  # 8192
eGradingMultipleOffsetResult: GradingStatus  # 256
eGradingNoStatus: GradingStatus  # 0
eGradingOffsetFailed: GradingStatus  # 128
eGradingOk: GradingStatus  # 1
eGradingRuleMissing: GradingStatus  # 16
eGradingSideLeft: GradingSide  # 0
eGradingSideNone: GradingSide  # -1
eGradingSideRight: GradingSide  # 1
eGradingSurfaceMissing: GradingStatus  # 8
eGradingTimeout: GradingStatus  # 16384
eGradingTypeNone: GradingType  # -1
eGradingTypeSlopeOffset: GradingType  # 1
eGradingTypeSlopeSurface: GradingType  # 0
eGradingUnknownError: GradingStatus  # 1024
eGradingUpdateNeeded: GradingStatus  # 2
eGradingZeroGrading: GradingStatus  # 512
eGroupDefinitions: TinSurfaceDefinitionType  # 29
eIFC: TinSurfaceDefinitionType  # 33
eInCurve: SpiralCurveType  # 0
eLabelAnchorBottomCenter: LabelAnchor  # 10
eLabelAnchorBottomLeft: LabelAnchor  # 9
eLabelAnchorBottomRight: LabelAnchor  # 11
eLabelAnchorCurveCenter: LabelAnchor  # 13
eLabelAnchorCurvePI: LabelAnchor  # 14
eLabelAnchorEnd: LabelAnchor  # 2
eLabelAnchorFeatureLocation: LabelAnchor  # 69
eLabelAnchorInsertionPoint: LabelAnchor  # 12
eLabelAnchorMiddle: LabelAnchor  # 1
eLabelAnchorMiddleCenter: LabelAnchor  # 7
eLabelAnchorMiddleLeft: LabelAnchor  # 6
eLabelAnchorMiddleRight: LabelAnchor  # 8
eLabelAnchorStart: LabelAnchor  # 0
eLabelAnchorTopCenter: LabelAnchor  # 4
eLabelAnchorTopLeft: LabelAnchor  # 3
eLabelAnchorTopRight: LabelAnchor  # 5
eLabelAnchors: LabelAnchor  # 0
eLandXML: TinSurfaceDefinitionType  # 25
eLayout: VAlignmentType  # 0
eLeaderAttachmentBottomOfBottomLine: LeaderAttachment  # 4
eLeaderAttachmentMiddle: LeaderAttachment  # 2
eLeaderAttachmentMiddleOfBottomLine: LeaderAttachment  # 3
eLeaderAttachmentMiddleOfTopLine: LeaderAttachment  # 1
eLeaderAttachmentTopOfTopLine: LeaderAttachment  # 0
eLeaderTypeSpline: LeaderType  # 1
eLeaderTypeStraight: LeaderType  # 0
eLength: VAlignmentParameterConstraint  # 3
eLengthTypeFixed: LengthType  # 0
eLengthTypePercentage: LengthType  # 1
eLine: DrawingObjectType  # 4
eLineLabel: StyleManagerType  # 1
eLineSpiral: HAlignmentElementType  # 7
eLine_BestFit: HAlignmentParameterConstraint  # 203
eLine_Length: HAlignmentParameterConstraint  # 202
eLine_ThroughPoint: HAlignmentParameterConstraint  # 201
eLine_TwoPoints: HAlignmentParameterConstraint  # 200
eMerge: TinSurfaceDefinitionType  # 13
eMiddleOrdinate: ArcParameterType  # 6
eMinimizeFlatAreas: TinSurfaceDefinitionType  # 39
eMiscellaneous: Civil3dAlignmentType  # 4
eModifyPointElevation: TinSurfaceDefinitionType  # 18
eModifyPointsElevation: TinSurfaceDefinitionType  # 19
eModifyPointsElevations: TinSurfaceDefinitionType  # 20
eMovePoint: TinSurfaceDefinitionType  # 7
eMovePoints: TinSurfaceDefinitionType  # 8
eMultipleSegments: HAlignmentElementType  # 11
eNext: VAlignmentTangencyConstraint  # 3
eNoEntity: Civil3dEntityType  # -1
eNoLabels: Civil3dLabels  # 0
eNone: TinSurfaceDefinitionType  # 0
eNotAlignment: Civil3dAlignmentType  # -1
eNotProfile: Civil3dProfileType  # -1
eOffset: Civil3dAlignmentType  # 1
eOrientationReferenceObject: OrientationRef  # 0
eOrientationReferenceStartLeaderAtMarker: OrientationRef  # 9
eOrientationReferenceView: OrientationRef  # 1
eOrientationReferenceWCS: OrientationRef  # 2
eOutCurve: SpiralCurveType  # 1
ePI: HAlignmentElementType  # 100
ePVI: VAlignmentElementType  # 100
eParabola: VAlignmentElementType  # 3
eParamA: SpiralParameterType2  # 0
eParamLength: SpiralParameterType2  # 1
ePassThroughPoints: VAlignmentParameterConstraint  # 1
ePoint: DrawingObjectType  # 1
ePointLabel: StyleManagerType  # 3
ePointOnTangent: VAlignmentParameterConstraint  # 6
ePolyline: DrawingObjectType  # 6
ePrevious: VAlignmentTangencyConstraint  # 2
eProfile: Civil3dEntityType  # 1
eProfileView: Civil3dEntityType  # 3
eQuick: Civil3dProfileType  # 3
eRadius: VAlignmentParameterConstraint  # 2
eRail: Civil3dAlignmentType  # 3
eRemoveBelowAboveElevation: TinSurfaceDefinitionType  # 41
eRemoveOuterEdges: TinSurfaceDefinitionType  # 37
eReverse: ArcType  # 1
eRiseLower: TinSurfaceDefinitionType  # 24
eSCS_PointOnTangent: HAlignmentParameterConstraint  # 412
eSCS_SpiralAVal: HAlignmentParameterConstraint  # 411
eSCS_SpiralAValRadius: HAlignmentParameterConstraint  # 410
eSCS_SpiralAValRadiusArcLength: HAlignmentParameterConstraint  # 409
eSCS_SpiralAValRadiusPassThrough: HAlignmentParameterConstraint  # 408
eSCS_SpiralInAValRadiusSpiralOutAVal: HAlignmentParameterConstraint  # 407
eSCS_SpiralInAValSpiralOutAVal: HAlignmentParameterConstraint  # 406
eSCS_SpiralInLengthSpiralOutLength: HAlignmentParameterConstraint  # 405
eSCS_SpiralInRadiusSpiralOut: HAlignmentParameterConstraint  # 400
eSCS_SpiralLength: HAlignmentParameterConstraint  # 404
eSCS_SpiralLengthRadius: HAlignmentParameterConstraint  # 403
eSCS_SpiralLengthRadiusArcLength: HAlignmentParameterConstraint  # 402
eSCS_SpiralLengthRadiusPassThrough: HAlignmentParameterConstraint  # 401
eSSCSS_Sp1AValSp2AValPt1Pt2: HAlignmentParameterConstraint  # 703
eSSCSS_Sp1AValSp2AValRadiusPt: HAlignmentParameterConstraint  # 702
eSSCSS_Sp1LenSp2LenPt1Pt2: HAlignmentParameterConstraint  # 701
eSSCSS_Sp1LenSp2LenRadiusPt: HAlignmentParameterConstraint  # 700
eSTS_SpiralAValTangentLength: HAlignmentParameterConstraint  # 606
eSTS_SpiralAValTangentPassThrough : HAlignmentParameterConstraint  # 605
eSTS_SpiralInAValSpiralOutAVal: HAlignmentParameterConstraint  # 602
eSTS_SpiralInLengthSpiralOutLength: HAlignmentParameterConstraint  # 600
eSTS_SpiralLengthTangentLength: HAlignmentParameterConstraint  # 604
eSTS_SpiralLengthTangentPassThrough: HAlignmentParameterConstraint  # 603
eSTS_TangentLength: HAlignmentParameterConstraint  # 601
eScalingTypeAbsoluteUnits: ScalingType  # 2
eScalingTypeDrawingScale: ScalingType  # 0
eScalingTypeFixedScale: ScalingType  # 1
eScalingTypeRelativeToScreen: ScalingType  # 3
eSlopeDegrees: GradingSlopeFormat  # 1
eSlopeNoFormat: GradingSlopeFormat  # -1
eSlopePercent: GradingSlopeFormat  # 2
eSlopeRadians: GradingSlopeFormat  # 3
eSlopeRiseRun: GradingSlopeFormat  # 0
eSmoothen: TinSurfaceDefinitionType  # 31
eSolidTypeSurfaceDepth: TinSurfaceSolidType  # 2
eSolidTypeSurfaceElevation: TinSurfaceSolidType  # 1
eSolidTypeSurfaceSurface: TinSurfaceSolidType  # 0
eSpiral: HAlignmentElementType  # 3
eSpiralCurve: HAlignmentElementType  # 8
eSpiralCurveSpiral: HAlignmentElementType  # 4
eSpiralCurveSpiralCurveSpiral: HAlignmentElementType  # 12
eSpiralCurveSpiralSpiralCurveSpiral: HAlignmentElementType  # 13
eSpiralLine: HAlignmentElementType  # 6
eSpiralLineSpiral: HAlignmentElementType  # 5
eSpiralSpiral: HAlignmentElementType  # 14
eSpiralSpiralCurve: HAlignmentElementType  # 15
eSpiralSpiralCurveSpiralSpiral: HAlignmentElementType  # 10
eSpiral_StartPointDirRadiusLength: HAlignmentParameterConstraint  # 500
eSpiral_StartPointDirStartAndEndRadiusLength: HAlignmentParameterConstraint  # 501
eStaticSurface: VAlignmentType  # 1
eSurfaceElevationLabel: StyleManagerType  # 6
eSurfaceLabels: Civil3dLabels  # 1
eSurfaceSlopeLabel: StyleManagerType  # 5
eSwapEdge: TinSurfaceDefinitionType  # 6
eSymbolStyle: StyleManagerType  # 0
eSymbolTypeACADPoint: SymbolType  # 0
eSymbolTypeBlock: SymbolType  # 2
eSymbolTypeCustom: SymbolType  # 1
eSymbolTypeVerticalLine: SymbolType  # 3
eTangent: VAlignmentElementType  # 1
eTangentExtensions: HAlignmentVisualStyle  # 2
eTangentLength: ArcParameterType  # 2
eTangents: VAlignmentVisualStyle  # 2
eText: DrawingObjectType  # 3
eTinBoundary: TinConstraintType  # 1
eTinBreakline: TinConstraintType  # 0
eTinBreaklineNormal: TinBreaklineType  # 0
eTinElevationMax: BreaklineIntersectionElevation  # 2
eTinElevationMid: BreaklineIntersectionElevation  # 3
eTinElevationMin: BreaklineIntersectionElevation  # 1
eTinHide: TinBoundaryType  # 1
eTinNonDestructive: TinBreaklineType  # 1
eTinNotAllowed: BreaklineIntersectionElevation  # 0
eTinOuter: TinBoundaryType  # 2
eTinShow: TinBoundaryType  # 0
eTinStyleBoundaryLine: TinSurfaceStyle  # 1
eTinStyleContours: TinSurfaceStyle  # 8
eTinStyleElevationTooltip: TinSurfaceStyle  # 16
eTinStyleNone: TinSurfaceStyle  # 0
eTinStylePoints: TinSurfaceStyle  # 2
eTinStyleTriangles: TinSurfaceStyle  # 4
eTinSurface: Civil3dEntityType  # 2
eTinSurfaceAll: TinSurfaceIntersectType  # 1
eTinSurfaceFirstOnly: TinSurfaceIntersectType  # 0
eTinSurfaceMeshDepth: TinSurfaceMeshType  # 2
eTinSurfaceMeshElevation: TinSurfaceMeshType  # 1
eTinSurfaceMeshSurface: TinSurfaceMeshType  # 0
eTinVolumeBaseComparison: VolumeSurfaceType  # 0
eTinVolumeToDepth: VolumeSurfaceType  # 2
eTinVolumeToElevation: VolumeSurfaceType  # 1
eTinWall: TinConstraintType  # 2
eTinWallLeft: TinWallSide  # 0
eTinWallNormal: TinWallType  # 0
eTinWallProjected: TinWallType  # 1
eTinWallRight: TinWallSide  # 1
eTransform: TinSurfaceDefinitionType  # 1
eTrianglesVisibility: TinSurfaceDefinitionType  # 40
eUnattachedLabels: Civil3dLabels  # 4
eUndefined: VAlignmentParameterConstraint  # 0
eUnknown: DrawingObjectType  # 0
eVolume: TinSurfaceDefinitionType  # 12
class ArcParameterType(_BoostPythonEnum):
    eRadius: ClassVar[Self]  # 0
    eDegreeOfCurve: ClassVar[Self]  # 1
    eTangentLength: ClassVar[Self]  # 2
    eChordLength: ClassVar[Self]  # 3
    eCurveLength: ClassVar[Self]  # 4
    eExternalDist: ClassVar[Self]  # 5
    eMiddleOrdinate: ClassVar[Self]  # 6
    eCurveAngle: ClassVar[Self]  # 7
    eCurveThroughPoint: ClassVar[Self]  # 8
class ArcType(_BoostPythonEnum):
    eCompound: ClassVar[Self]  # 0
    eReverse: ClassVar[Self]  # 1
class BlockAttachment(_BoostPythonEnum):
    eBlockAttachmentTopLeft: ClassVar[Self]  # 0
    eBlockAttachmentTopCenter: ClassVar[Self]  # 1
    eBlockAttachmentTopRight: ClassVar[Self]  # 2
    eBlockAttachmentMiddleLeft: ClassVar[Self]  # 3
    eBlockAttachmentMiddleCenter: ClassVar[Self]  # 4
    eBlockAttachmentMiddleRight: ClassVar[Self]  # 5
    eBlockAttachmentBottomLeft: ClassVar[Self]  # 6
    eBlockAttachmentBottomCenter: ClassVar[Self]  # 7
    eBlockAttachmentBottomRight: ClassVar[Self]  # 8
    eBlockAttachmentInsertionPoint: ClassVar[Self]  # 9
class BorderType(_BoostPythonEnum):
    eBorderTypeRectangular: ClassVar[Self]  # 0
    eBorderTypeRoundedRectangular: ClassVar[Self]  # 1
    eBorderTypeCircular: ClassVar[Self]  # 2
class BreaklineIntersectionElevation(_BoostPythonEnum):
    eTinNotAllowed: ClassVar[Self]  # 0
    eTinElevationMin: ClassVar[Self]  # 1
    eTinElevationMax: ClassVar[Self]  # 2
    eTinElevationMid: ClassVar[Self]  # 3
class Civil3dAlignmentType(_BoostPythonEnum):
    eNotAlignment: ClassVar[Self]  # -1
    eCenterline: ClassVar[Self]  # 0
    eOffset: ClassVar[Self]  # 1
    eCurbReturn: ClassVar[Self]  # 2
    eRail: ClassVar[Self]  # 3
    eMiscellaneous: ClassVar[Self]  # 4
class Civil3dEntityType(_BoostPythonEnum):
    eNoEntity: ClassVar[Self]  # -1
    eAlignment: ClassVar[Self]  # 0
    eProfile: ClassVar[Self]  # 1
    eTinSurface: ClassVar[Self]  # 2
    eProfileView: ClassVar[Self]  # 3
class Civil3dLabels(_BoostPythonEnum):
    eNoLabels: ClassVar[Self]  # 0
    eSurfaceLabels: ClassVar[Self]  # 1
    eAlignmentsLabels: ClassVar[Self]  # 2
    eUnattachedLabels: ClassVar[Self]  # 4
    eDefaultLabels: ClassVar[Self]  # 6
    eAllLabels: ClassVar[Self]  # 255
class Civil3dProfileType(_BoostPythonEnum):
    eNotProfile: ClassVar[Self]  # -1
    eLayout: ClassVar[Self]  # 0
    eStaticSurface: ClassVar[Self]  # 1
    eDynamicSurface: ClassVar[Self]  # 2
    eQuick: ClassVar[Self]  # 3
class CustomSymbol(_BoostPythonEnum):
    eCustomSymbolSpotPoint: ClassVar[Self]  # 0
    eCustomSymbolSpotEmpty: ClassVar[Self]  # 1
    eCustomSymbolSpotCross: ClassVar[Self]  # 2
    eCustomSymbolSpotCross45: ClassVar[Self]  # 3
    eCustomSymbolSpotVerticalLine: ClassVar[Self]  # 4
    eCustomSymbolFrameCircle: ClassVar[Self]  # 32
    eCustomSymbolFrameSquare: ClassVar[Self]  # 64
class CvCivil3dConverter:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, sourceDb: PyDb.Database, targetDb: PyDb.Database, doLabels: PyBrxCv.Civil3dLabels, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def attachedLabels(self, civilEntity: PyBrxCv.CvCivil3dEntityInfo, /) -> list[PyDb.ObjectId]:
        pass
    @staticmethod
    def className() -> str:
        pass
    def convert(self, entitiesToConvert : list, /) -> list:
        pass
    def getCivilEntities(self, /) -> list[PyBrxCv.CvCivil3dEntityInfo]:
        pass
    def getInsertedEntities(self, /) -> list[PyDb.ObjectId]:
        pass
    def unattachedLabels(self, /) -> list[PyDb.ObjectId]:
        pass
class CvCivil3dEntityInfo:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def alignmentType(self, /) -> Civil3dAlignmentType:
        pass
    def baseAlignment(self, /) -> CvCivil3dEntityInfo:
        pass
    def baseSurface(self, /) -> CvCivil3dEntityInfo:
        pass
    @staticmethod
    def className() -> str:
        pass
    def description(self, /) -> str:
        pass
    def isNull(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def objectId(self, /) -> PyDb.ObjectId:
        pass
    def profileType(self, /) -> Civil3dProfileType:
        pass
    def profiles(self, /) -> list[PyBrxCv.CvCivil3dEntityInfo]:
        pass
    def type(self, /) -> Civil3dEntityType:
        pass
class CvDataType(_BoostPythonEnum):
    eBrxCvDataTypeNone: ClassVar[Self]  # 0
    eBrxCvDataTypeBool: ClassVar[Self]  # 1
    eBrxCvDataTypeString: ClassVar[Self]  # 2
    eBrxCvDataTypeInteger: ClassVar[Self]  # 3
    eBrxCvDataTypeDate: ClassVar[Self]  # 4
    eBrxCvDataTypeLinear: ClassVar[Self]  # 5
    eBrxCvDataTypeStation: ClassVar[Self]  # 6
    eBrxCvDataTypeAngle: ClassVar[Self]  # 7
    eBrxCvDataTypeRatio: ClassVar[Self]  # 8
    eBrxCvDataTypeArea: ClassVar[Self]  # 9
    eBrxCvDataTypeAzimuth: ClassVar[Self]  # 10
    eBrxCvDataTypeDirection: ClassVar[Self]  # 11
    eBrxCvDataTypeDistance: ClassVar[Self]  # 12
    eBrxCvDataTypeElevation: ClassVar[Self]  # 13
    eBrxCvDataTypeSlope: ClassVar[Self]  # 14
    eBrxCvDataTypeLatitude: ClassVar[Self]  # 15
    eBrxCvDataTypeLongitude: ClassVar[Self]  # 16
    eBrxCvDataTypeRotation: ClassVar[Self]  # 17
    eBrxCvDataTypeVolume: ClassVar[Self]  # 18
    eBrxCvDataTypeSpeed: ClassVar[Self]  # 19
class CvDb3dAlignment(PyBrxCv.CvDbCurve):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def baseHAlignment(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDb3dAlignment:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDb3dAlignment:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getPointsArray(self, /) -> list[PyGe.Point3d]:
        pass
    def length(self, /) -> float:
        pass
    def setBaseHAlignment(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def setVAlignment(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def vAlignment(self, /) -> PyDb.ObjectId:
        pass
class CvDbCurve(PyDb.Curve):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbCurve:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbCurve:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, val : str, /) -> bool:
        pass
    def setName(self, val : str, /) -> bool:
        pass
class CvDbCurveLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbCurveLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbCurveLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbCurveLabelStyleManager:
        pass
class CvDbEntity(PyDb.Entity):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbEntity:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbEntity:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, val : str, /) -> bool:
        pass
    def setName(self, val : str, /) -> bool:
        pass
class CvDbFileFormatManager(PyBrxCv.CvDbObjectManager):
    def __init__(self, id:  PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def allFileFormats(self, /) -> list[PyDb.ObjectId]:
        pass
    def applicableFileFormats(self, val : str, /) -> list[PyDb.ObjectId]:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbFileFormatManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbFileFormatManager:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManager(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbFileFormatManager:
        pass
class CvDbGrading(PyBrxCv.CvDbEntity):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbGrading:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbGrading:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getCalculationCurve(self, /) -> PyGe.Curve3d:
        pass
    def getCalculationMethod(self, /) -> GradingCalculationMethod:
        pass
    def getGradingVisualStyle(self, /) -> GradingVisualStyle:
        pass
    def getInputEntityId(self, /) -> PyDb.ObjectId:
        pass
    def getIsAssociative(self, /) -> bool:
        pass
    def getIsDrawInfill(self, /) -> bool:
        pass
    def getMidOrdinateDist(self, /) -> float:
        pass
    def getRegionEnd(self, /) -> float:
        pass
    def getRegionStart(self, /) -> float:
        pass
    def getSegmentMaxAngle(self, /) -> float:
        pass
    def getSegmentMaxLength(self, /) -> float:
        pass
    def isClosed(self, /) -> bool:
        pass
    def resultDayLight(self, /) -> list[[PyGe.Point3d]]:
        pass
    def rule(self, /) -> CvGradingRule:
        pass
    def setCalculationMethod(self, val : PyBrxCv.GradingCalculationMethod, /) -> bool:
        pass
    def setDrawInfill(self, val : bool, /) -> GradingStatus:
        pass
    def setGradingVisualStyle(self, val : PyBrxCv.GradingVisualStyle, /) -> bool:
        pass
    def setInputData(self, curve: PyGe.Curve3d, /) -> GradingStatus:
        pass
    def setInputDataId(self, id : PyDb.ObjectId, /) -> GradingStatus:
        pass
    def setIsAssociative(self, val : bool, /) -> bool:
        pass
    def setMidOrdinateDist(self, val : float, /) -> GradingStatus:
        pass
    def setRegionEnd(self, val : float, /) -> GradingStatus:
        pass
    def setRegionStart(self, val : float, /) -> GradingStatus:
        pass
    def setRule(self, val : PyBrxCv.CvGradingRule, /) -> GradingStatus:
        pass
    def setSegmentMaxAngle(self, val : float, /) -> GradingStatus:
        pass
    def setSegmentMaxLength(self, val : float, /) -> GradingStatus:
        pass
    def targetSurface(self, /) -> PyDb.ObjectId:
        pass
    def update(self, val : bool, /) -> GradingStatus:
        pass
class CvDbHAlignment(PyBrxCv.CvDbCurve):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addArcAuto(self, prevId: int, nextId: int, /) -> int:
        pass
    @overload
    def addArcBetween(self, prevId: int, nextId: int, passThroughPoint: PyGe.Point2d, /) -> int: ...
    @overload
    def addArcBetween(self, prevId: int, nextId: int, parameter: float, paramType: PyBrxCv.EArcParameterType, isGreaterThan180: bool, arcType: PyBrxCv.ArcType, /) -> int: ...
    def addArcBetween(self, *args) -> int:
        pass
    @overload
    def addArcFixed(self, center: PyGe.Point2d, radius: float, clockwise: bool, /) -> int: ...
    @overload
    def addArcFixed(self, startPoint: PyGe.Point2d, midPoint: PyGe.Point2d, endPoint: PyGe.Point2d, /) -> int: ...
    def addArcFixed(self, *args) -> int:
        pass
    @overload
    def addArcFrom(self, prevId: int, passThroughPoint: PyGe.Point2d, /) -> int: ...
    @overload
    def addArcFrom(self, prevId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d, /) -> int: ...
    @overload
    def addArcFrom(self, prevId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType, /) -> int: ...
    @overload
    def addArcFrom(self, prevId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool, /) -> int: ...
    def addArcFrom(self, *args) -> int:
        pass
    @overload
    def addArcTo(self, nextId: int, passThroughPoint: PyGe.Point2d, /) -> int: ...
    @overload
    def addArcTo(self, nextId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d, /) -> int: ...
    @overload
    def addArcTo(self, nextId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType, /) -> int: ...
    @overload
    def addArcTo(self, nextId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool, /) -> int: ...
    def addArcTo(self, *args) -> int:
        pass
    def addCSSTo(self, nextId: int, spiral1Param: float, spiral2Param: float, spiralParamType, radius: float, passThroughPoint: PyGe.Point2d, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    @overload
    def addCSTo(self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    @overload
    def addCSTo(self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    def addCSTo(self, *args) -> int:
        pass
    def addLineBetween(self, prevId: int, nextId: int, /) -> int:
        pass
    @overload
    def addLineFixed(self, prevId : int, length: float, /) -> int: ...
    @overload
    def addLineFixed(self, start: PyGe.Point2d, end: PyGe.Point2d, /) -> int: ...
    def addLineFixed(self, *args) -> int:
        pass
    @overload
    def addLineFrom(self, prevId : int, length: float, /) -> int: ...
    @overload
    def addLineFrom(self, prevId : int, to: PyGe.Point2d, /) -> int: ...
    def addLineFrom(self, *args) -> int:
        pass
    @overload
    def addLineTo(self, nextId : int, length: float, /) -> int: ...
    @overload
    def addLineTo(self, nextId : int, to: PyGe.Point2d, /) -> int: ...
    def addLineTo(self, *args) -> int:
        pass
    @overload
    def addSCFrom(self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    @overload
    def addSCFrom(self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    def addSCFrom(self, *args) -> int:
        pass
    def addSCSAuto(self, prevId: int, nextId: int, /) -> int:
        pass
    def addSCSBetween(self, prevId: int, nextId: int, spiral1: float, spiral2: float, spiralType: PyBrxCv.SpiralParameterType, radius: float, spiralDef: PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    def addSSBetween(self, prevId: int, nextId: int, spiralRatio: float, spiralParamType : PyBrxCv.SpiralParameterType, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    def addSSCFrom(self, prevId: int, spiral1Param: float, spiral2Param: float, spiralParamType, radius: float, passThroughPoint: PyGe.Point2d, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    @overload
    def addSTFrom(self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    @overload
    def addSTFrom(self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    def addSTFrom(self, *args) -> int:
        pass
    def addSTSBetween(self, prevId: int, nextId: int, spiral1Param: float, spiral2Param: float, spiralType : PyBrxCv.SpiralParameterType, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    def addSpiralBetween(self, prevId: int, nextId: int, spiralDef: PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    def addSpiralFrom(self, prevId: int, radius: float, length: float, isClockwise: bool, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    def addSpiralTo(self, nextId: int, radius: float, length: float, isClockwise: bool, spiralDef : PyBrxCv.SpiralDefinitionType, /) -> int:
        pass
    @overload
    def addTSTo(self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    @overload
    def addTSTo(self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType, /) -> int: ...
    def addTSTo(self, *args) -> int:
        pass
    def alignment3dAt(self, index: int, /) -> PyDb.ObjectId:
        pass
    def alignment3dCount(self, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignment:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbHAlignment:
        pass
    def curveAtPI(self, pi: PyBrxCv.CvDbHAlignmentPI, /) -> int:
        pass
    def curveElementColor(self, /) -> int:
        pass
    def deleteElement(self, id: int, /) -> bool:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def elementAtId(self, Id: int, /) -> CvDbHAlignmentElement:
        pass
    def elementAtStation(self, station: float, /) -> CvDbHAlignmentElement:
        pass
    def elementCount(self, /) -> int:
        pass
    def elementExtensionColor(self, /) -> int:
        pass
    def firstElementId(self, /) -> int:
        pass
    def firstLineElementId(self, /) -> int:
        pass
    def getElementId(self, gsMarker: int, /) -> int:
        pass
    def getPIsArray(self, /) -> list[PyBrxCv.CvDbHAlignmentPI]:
        pass
    def getPointAtStation(self, station: float, /) -> tuple[bool,PyGe.Point2d]:
        pass
    def getRadius(self, param: float, /) -> float:
        pass
    @overload
    def getStationAtPoint(self, station: PyGe.Point2d, /) -> tuple[bool,float,float]: ...
    @overload
    def getStationAtPoint(self, station: PyGe.Point2d,fromStation: float, toStation: float, /) -> tuple[bool,float,float]: ...
    def getStationAtPoint(self, *args) -> tuple[bool,float,float]:
        pass
    def getUnorderedElementIds(self, /) -> list[int]:
        pass
    def insertLineFixed(self, start: PyGe.Point2d, end: PyGe.Point2d, prevId: int, /) -> int:
        pass
    def lastElementId(self, /) -> int:
        pass
    def length(self, /) -> float:
        pass
    def lineElementColor(self, /) -> int:
        pass
    def nextLineElementId(self, Id: int, /) -> int:
        pass
    def previousLineElementId(self, Id: int, /) -> int:
        pass
    def setCurveElementColor(self, colACI: int, /) -> bool:
        pass
    def setElementExtensionColor(self, colACI: int, /) -> bool:
        pass
    def setLineElementColor(self, colACI: int, /) -> bool:
        pass
    def setSpiralElementColor(self, colACI: int, /) -> bool:
        pass
    def setStationEquations(self, val: PyBrxCv.CvStationEquations, /) -> bool:
        pass
    def setStyle(self, style: int, /) -> bool:
        pass
    def setTangentExtensionColor(self, colACI: int, /) -> bool:
        pass
    def spiralElementColor(self, /) -> int:
        pass
    def stationEquations(self, /) -> CvStationEquations:
        pass
    def style(self, /) -> int:
        pass
    def tangentExtensionColor(self, /) -> int:
        pass
    def update(self, /) -> bool:
        pass
    def verticalAlignmentAt(self, index: int, /) -> PyDb.ObjectId:
        pass
    def verticalAlignmentCount(self, /) -> int:
        pass
    def verticalAlignmentViewAt(self, index: int, /) -> PyDb.ObjectId:
        pass
    def verticalAlignmentViewCount(self, /) -> int:
        pass
class CvDbHAlignmentArc(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentArc:
        pass
    def center(self, /) -> PyGe.Point2d:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def isClockwise(self, /) -> bool:
        pass
    def isCompound(self, /) -> bool:
        pass
    def isLessThan180(self, /) -> bool:
        pass
    def paramLength(self, /) -> float:
        pass
    def passThroughPoint1(self, /) -> PyGe.Point2d:
        pass
    def passThroughPoint2(self, /) -> PyGe.Point2d:
        pass
    def passThroughPoint3(self, /) -> PyGe.Point2d:
        pass
    def radius(self, /) -> float:
        pass
    def setCenter(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setClockwise(self, val : bool, /) -> bool:
        pass
    def setCompound(self, val : bool, /) -> bool:
        pass
    def setLessThan180(self, val : bool, /) -> bool:
        pass
    def setParamLength(self, val : float, /) -> bool:
        pass
    def setPassThroughPoint1(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setPassThroughPoint2(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setPassThroughPoint3(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setRadius(self, val : float, /) -> bool:
        pass
class CvDbHAlignmentCurve(PyBrxCv.CvDbHAlignmentElement):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentCurve:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def endPoint(self, /) -> PyGe.Point2d:
        pass
    def endStation(self, /) -> float:
        pass
    def length(self, /) -> float:
        pass
    def startPoint(self, /) -> PyGe.Point2d:
        pass
    def startStation(self, /) -> float:
        pass
class CvDbHAlignmentElement(PyBrxCv.CvDbSubObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentElement:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def id(self, /) -> int:
        pass
    def isSubentity(self, /) -> bool:
        pass
    def nextId(self, /) -> int:
        pass
    def parameterConstraint(self, /) -> HAlignmentParameterConstraint:
        pass
    def previousId(self, /) -> int:
        pass
    def setNextId(self, val : int, /) -> bool:
        pass
    def setParameterConstraint(self, val : PyBrxCv.EParameterConstraint, /) -> bool:
        pass
    def setPreviousId(self, val : int, /) -> bool:
        pass
    def setTangencyConstraint(self, val : PyBrxCv.ETangencyConstraint, /) -> bool:
        pass
    def tangencyConstraint(self, /) -> HAlignmentTangencyConstraint:
        pass
    def type(self, /) -> HAlignmentElementType:
        pass
class CvDbHAlignmentLine(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentLine:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def paramLength(self, /) -> float:
        pass
    def passThroughPoint1(self, /) -> PyGe.Point2d:
        pass
    def passThroughPoint2(self, /) -> PyGe.Point2d:
        pass
    def setParamLength(self, val : float, /) -> bool:
        pass
    def setPassThroughPoint1(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setPassThroughPoint2(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbHAlignmentPI(PyBrxCv.CvDbHAlignmentElement):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentPI:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def location(self, /) -> PyGe.Point2d:
        pass
class CvDbHAlignmentSCS(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def arc(self, /) -> CvDbHAlignmentArc:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentSCS:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def spiralIn(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiralOut(self, /) -> CvDbHAlignmentSpiral:
        pass
class CvDbHAlignmentSSCSS(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def arc(self, /) -> CvDbHAlignmentArc:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentSSCSS:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def spiral1(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiral2(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiral3(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiral4(self, /) -> CvDbHAlignmentSpiral:
        pass
class CvDbHAlignmentSTS(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentSTS:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def line(self, /) -> CvDbHAlignmentLine:
        pass
    def spiralIn(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiralOut(self, /) -> CvDbHAlignmentSpiral:
        pass
    def spiralRatio(self, /) -> float:
        pass
class CvDbHAlignmentSpiral(PyBrxCv.CvDbHAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbHAlignmentSpiral:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def endDirection(self, /) -> float:
        pass
    def isCompound(self, /) -> bool:
        pass
    def paramA(self, /) -> float:
        pass
    def paramLength(self, /) -> float:
        pass
    def radiusIn(self, /) -> float:
        pass
    def radiusOut(self, /) -> float:
        pass
    def setClockwise(self, val : bool, /) -> bool:
        pass
    def setCompound(self, val : float, /) -> bool:
        pass
    def setEndDirection(self, val : float, /) -> bool:
        pass
    def setParamA(self, val : float, /) -> bool:
        pass
    def setParamLength(self, val : float, /) -> bool:
        pass
    def setRadiusIn(self, val : float, /) -> bool:
        pass
    def setRadiusOut(self, val : float, /) -> bool:
        pass
    def setSpiralCurveType(self, val : PyBrxCv.ESpiralCurveType, /) -> bool:
        pass
    def setSpiralDefinition(self, val : PyBrxCv.ESpiralDefinitionType, /) -> bool:
        pass
    def spiralCurveType(self, /) -> SpiralCurveType:
        pass
    def spiralDefinition(self, /) -> SpiralDefinitionTypeSpiral:
        pass
    def startDirection(self, /) -> float:
        pass
class CvDbLabelStyle(PyBrxCv.CvDbStyle):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, metric: bool, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addComponent(self, val: PyBrxCv.CvDbLabelStyleComponent, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLabelStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
    def componentAt(self, index: int, /) -> CvDbLabelStyleComponent:
        pass
    def componentCount(self, /) -> int:
        pass
    def components(self, /) -> list[PyBrxCv.CvDbLabelStyleComponent]:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def draggedStateBackgroundMask(self, /) -> bool:
        pass
    def draggedStateBorderAndLeaderGap(self, /) -> float:
        pass
    def draggedStateBorderAndLeaderGapExprIndex(self, /) -> int:
        pass
    def draggedStateBorderIsVisible(self, /) -> bool:
        pass
    def draggedStateBorderType(self, /) -> BorderType:
        pass
    def draggedStateColor(self, /) -> PyDb.Color:
        pass
    def draggedStateDisplayMode(self, /) -> DisplayMode:
        pass
    def draggedStateLeaderArrowHeadSize(self, /) -> float:
        pass
    def draggedStateLeaderArrowHeadSizeExprIndex(self, /) -> int:
        pass
    def draggedStateLeaderArrowHeadStyle(self, /) -> PyDb.ObjectId:
        pass
    def draggedStateLeaderAttachment(self, /) -> LeaderAttachment:
        pass
    def draggedStateLeaderColor(self, /) -> PyDb.Color:
        pass
    def draggedStateLeaderIsVisible(self, /) -> bool:
        pass
    def draggedStateLeaderJustification(self, /) -> bool:
        pass
    def draggedStateLeaderLinetype(self, /) -> PyDb.ObjectId:
        pass
    def draggedStateLeaderLineweight(self, /) -> PyDb.LineWeight:
        pass
    def draggedStateLeaderTail(self, /) -> bool:
        pass
    def draggedStateLeaderType(self, /) -> LeaderType:
        pass
    def draggedStateLinetype(self, /) -> PyDb.ObjectId:
        pass
    def draggedStateLineweight(self, /) -> PyDb.LineWeight:
        pass
    def draggedStateMaximumTextWidth(self, /) -> float:
        pass
    def draggedStateMaximumTextWidthExprIndex(self, /) -> int:
        pass
    def draggedStateTagDisplayMode(self, /) -> bool:
        pass
    def draggedStateTextHeight(self, /) -> float:
        pass
    def draggedStateTextHeightExprIndex(self, /) -> int:
        pass
    def expressionAt(self, index: int, /) -> tuple[str,str]:
        pass
    def expressionCount(self, /) -> int:
        pass
    def flipAnchorsWithText(self, /) -> bool:
        pass
    def forceInsideCurve(self, /) -> bool:
        pass
    def forcedInsertion(self, /) -> ForcedInsertion:
        pass
    def isVisible(self, /) -> bool:
        pass
    def layer(self, /) -> PyDb.ObjectId:
        pass
    def moveComponent(self, _from: int, _to:int, /) -> None:
        pass
    def orientationReference(self, /) -> OrientationRef:
        pass
    def planReadable(self, /) -> bool:
        pass
    def readabilityBias(self, /) -> float:
        pass
    def removeComponent(self, val: int|PyBrxCv.CvDbLabelStyleComponent, /) -> None:
        pass
    def setDraggedStateBackgroundMask(self, val: bool, /) -> None:
        pass
    def setDraggedStateBorderAndLeaderGap(self, val: float, /) -> None:
        pass
    def setDraggedStateBorderAndLeaderGapExprIndex(self, val: int, /) -> None:
        pass
    def setDraggedStateBorderType(self, val: BorderType, /) -> None:
        pass
    def setDraggedStateBorderVisibility(self, val: bool, /) -> None:
        pass
    def setDraggedStateColor(self, val: PyDb.Color, /) -> None:
        pass
    def setDraggedStateDisplayMode(self, val: DisplayMode, /) -> None:
        pass
    def setDraggedStateLeaderArrowHeadSize(self, val: float, /) -> None:
        pass
    def setDraggedStateLeaderArrowHeadSizeExprIndex(self, val: int, /) -> None:
        pass
    def setDraggedStateLeaderArrowHeadStyle(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setDraggedStateLeaderAttachment(self, val: LeaderAttachment, /) -> None:
        pass
    def setDraggedStateLeaderColor(self, val: PyDb.Color, /) -> None:
        pass
    def setDraggedStateLeaderJustification(self, val: bool, /) -> None:
        pass
    def setDraggedStateLeaderLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setDraggedStateLeaderLineweight(self, val: PyDb.LineWeight, /) -> None:
        pass
    def setDraggedStateLeaderTail(self, val: bool, /) -> None:
        pass
    def setDraggedStateLeaderType(self, val: LeaderType, /) -> None:
        pass
    def setDraggedStateLeaderVisibility(self, val: bool, /) -> None:
        pass
    def setDraggedStateLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setDraggedStateLineweight(self, val: PyDb.LineWeight, /) -> None:
        pass
    def setDraggedStateMaximumTextWidth(self, val: float, /) -> None:
        pass
    def setDraggedStateMaximumTextWidthExprIndex(self, val: int, /) -> None:
        pass
    def setDraggedStateTagDisplayMode(self, val: bool, /) -> None:
        pass
    def setDraggedStateTextHeight(self, val: float, /) -> None:
        pass
    def setDraggedStateTextHeightExprIndex(self, val: int, /) -> None:
        pass
    def setExpressionAt(self, index: int, name: str, expr:str, val: PyBrxCv.DataType, /) -> None:
        pass
    def setFlipAnchorsWithText(self, val: bool, /) -> None:
        pass
    def setForceInsideCurve(self, val: bool, /) -> None:
        pass
    def setForcedInsertion(self, val: ForcedInsertion, /) -> None:
        pass
    def setLayer(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setOrientationReference(self, val: PyBrxCv.OrientationRef, /) -> None:
        pass
    def setPlanReadable(self, val: bool, /) -> None:
        pass
    def setReadabilityBias(self, val: float, /) -> None:
        pass
    def setTextStyle(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setVisibility(self, val: bool, /) -> None:
        pass
    def textStyle(self, /) -> PyDb.ObjectId:
        pass
class CvDbLabelStyleArrow(PyBrxCv.CvDbLabelStyleComponent):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def angle(self, /) -> float:
        pass
    def angleExprIndex(self, /) -> int:
        pass
    def arrowHeadSize(self, /) -> float:
        pass
    def arrowHeadStyle(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLabelStyleArrow:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def isFixedLength(self, /) -> bool:
        pass
    def length(self, /) -> float:
        pass
    def lengthExprIndex(self, /) -> int:
        pass
    def linetype(self, /) -> PyDb.ObjectId:
        pass
    def lineweight(self, /) -> PyDb.LineWeight:
        pass
    def offset(self, /) -> PyGe.Vector2d:
        pass
    def setAngle(self, val: float, /) -> None:
        pass
    def setAngleExprIndex(self, val: int, /) -> None:
        pass
    def setArrowHeadSize(self, val: float, /) -> None:
        pass
    def setArrowHeadSizeExprIndex(self, val: int, /) -> None:
        pass
    def setArrowHeadStyle(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setFixedLength(self, val: bool, /) -> None:
        pass
    def setLength(self, val: float, /) -> None:
        pass
    def setLengthExprIndex(self, val: int, /) -> None:
        pass
    def setLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setLineweight(self, val: PyDb.LineWeight, /) -> None:
        pass
    def setOffset(self, val: PyGe.Vector2d, /) -> None:
        pass
class CvDbLabelStyleBlock(PyBrxCv.CvDbLabelStyleComponent):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def angle(self, /) -> float:
        pass
    def angleExprIndex(self, /) -> int:
        pass
    def attachment(self, /) -> BlockAttachment:
        pass
    def blockId(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLabelStyleBlock:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def height(self, /) -> float:
        pass
    def heightExprIndex(self, /) -> int:
        pass
    def linetype(self, /) -> PyDb.ObjectId:
        pass
    def lineweight(self, /) -> PyDb.LineWeight:
        pass
    def offset(self, /) -> PyGe.Vector2d:
        pass
    def setAngle(self, val: float, /) -> None:
        pass
    def setAngleExprIndex(self, val: int, /) -> None:
        pass
    def setAttachment(self, attachment: PyBrxCv.BlockAttachment, /) -> None:
        pass
    def setBlockId(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setHeight(self, val: float, /) -> None:
        pass
    def setHeightExprIndex(self, val: int, /) -> None:
        pass
    def setLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setLineweight(self, lineWeight: PyDb.LineWeight, /) -> None:
        pass
    def setOffset(self, val: PyGe.Vector2d, /) -> None:
        pass
class CvDbLabelStyleComponent(PyBrxCv.CvDbSubObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def anchorIndex(self, /) -> int:
        pass
    def anchorPoint(self, /) -> LabelAnchor:
        pass
    def color(self, /) -> PyDb.Color:
        pass
    def displaySetting(self, /) -> bool:
        pass
    def setAnchorIndex(self, val : int, /) -> None:
        pass
    def setAnchorPoint(self, val : PyBrxCv.LabelAnchor, /) -> None:
        pass
    def setColor(self, clr: PyDb.Color, /) -> None:
        pass
    def setVisible(self, val: bool, /) -> None:
        pass
class CvDbLabelStyleLine(PyBrxCv.CvDbLabelStyleComponent):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def angle(self, /) -> float:
        pass
    def angleExprIndex(self, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLabelStyleLine:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def endPointAnchorIndex(self, /) -> int:
        pass
    def endPointAnchorPoint(self, /) -> LabelAnchor:
        pass
    def endPointOffset(self, /) -> PyGe.Vector2d:
        pass
    def length(self, /) -> float:
        pass
    def lengthExprIndex(self, /) -> int:
        pass
    def lengthPercentage(self, /) -> float:
        pass
    def lengthPercentageExprIndex(self, /) -> int:
        pass
    def lengthType(self, /) -> LengthType:
        pass
    def linetype(self, /) -> PyDb.ObjectId:
        pass
    def lineweight(self, /) -> PyDb.LineWeight:
        pass
    def setAngle(self, val: float, /) -> None:
        pass
    def setAngleExprIndex(self, val: int, /) -> None:
        pass
    def setEndPointAnchorIndex(self, val: int, /) -> None:
        pass
    def setEndPointAnchorPoint(self,  val : PyBrxCv.LabelAnchor, /) -> None:
        pass
    def setEndPointOffset(self, val: PyGe.Vector2d, /) -> None:
        pass
    def setLength(self, val: float, /) -> None:
        pass
    def setLengthExprIndex(self, val: int, /) -> None:
        pass
    def setLengthPercentage(self, val: float, /) -> None:
        pass
    def setLengthPercentageExprIndex(self, val: int, /) -> None:
        pass
    def setLengthType(self,  val : PyBrxCv.LengthType, /) -> None:
        pass
    def setLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setLineweight(self, id: PyDb.LineWeight, /) -> None:
        pass
    def setStartPointOffset(self, val: PyGe.Vector2d, /) -> None:
        pass
    def setUseEndPointAnchor(self, val: bool, /) -> None:
        pass
    def startPointOffset(self, /) -> PyGe.Vector2d:
        pass
    def useEndPointAnchor(self, /) -> bool:
        pass
class CvDbLabelStyleText(PyBrxCv.CvDbLabelStyleComponent):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def allowCurvedText(self, /) -> bool:
        pass
    def borderBackgroudMask(self, /) -> bool:
        pass
    def borderColor(self, /) -> PyDb.Color:
        pass
    def borderGap(self, /) -> float:
        pass
    def borderGapExprIndex(self, /) -> int:
        pass
    def borderIsVisible(self, /) -> bool:
        pass
    def borderLinetype(self, /) -> PyDb.ObjectId:
        pass
    def borderLineweight(self, val: PyDb.LineWeight, /) -> PyDb.LineWeight:
        pass
    def borderType(self, /) -> BorderType:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLabelStyleText:
        pass
    @staticmethod
    def className() -> str:
        pass
    def contents(self, /) -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def setAllowCurvedText(self, val: bool, /) -> None:
        pass
    def setBorderBackgroudMask(self, val: bool, /) -> None:
        pass
    def setBorderColor(self, val: PyDb.Color, /) -> None:
        pass
    def setBorderGap(self, val: float, /) -> None:
        pass
    def setBorderGapExprIndex(self, val: int, /) -> None:
        pass
    def setBorderLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setBorderLineweight(self, /) -> None:
        pass
    def setBorderType(self, val: BorderType, /) -> None:
        pass
    def setBorderVisibility(self, val: bool, /) -> None:
        pass
    def setContents(self, val: str, /) -> None:
        pass
    def setTextAngle(self, val: float, /) -> None:
        pass
    def setTextAngleExprIndex(self, val: int, /) -> None:
        pass
    def setTextAttachment(self, val: PyDb.MTextAttachmentPoint, /) -> None:
        pass
    def setTextHeight(self, val: float, /) -> None:
        pass
    def setTextHeightExprIndex(self, val: int, /) -> None:
        pass
    def setTextHorizontalAlignment(self, val: PyDb.TextHorzMode, /) -> None:
        pass
    def setTextLinetype(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setTextLineweight(self, val: PyDb.LineWeight, /) -> None:
        pass
    def setTextMaximumWidth(self, val: float, /) -> None:
        pass
    def setTextMaximumWidthExprIndex(self, val: int, /) -> None:
        pass
    def setTextOffset(self, val: PyGe.Vector2d, /) -> None:
        pass
    def textAngle(self, /) -> float:
        pass
    def textAngleExprIndex(self, /) -> int:
        pass
    def textAttachment(self, /) -> PyDb.MTextAttachmentPoint:
        pass
    def textHeight(self, /) -> float:
        pass
    def textHeightExprIndex(self, /) -> int:
        pass
    def textHorizontalAlignment(self, /) -> PyDb.TextHorzMode:
        pass
    def textLinetype(self, /) -> PyDb.ObjectId:
        pass
    def textLineweight(self, /) -> PyDb.LineWeight:
        pass
    def textMaximumWidth(self, /) -> float:
        pass
    def textMaximumWidthExprIndex(self, /) -> int:
        pass
    def textOffset(self, /) -> PyGe.Vector2d:
        pass
class CvDbLineLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbLineLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbLineLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbLineLabelStyleManager:
        pass
class CvDbObject(PyDb.DbObject):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbObject:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbObject:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, val : str, /) -> bool:
        pass
    def setName(self, val : str, /) -> bool:
        pass
class CvDbObjectManager(PyBrxCv.CvDbObject):
    def __contains__(self, id : str|PyDb.ObjectId, /) -> bool:
        pass
    def __getitem__(self, val : int|str, /) -> PyDb.ObjectId:
        pass
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbObjectManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbObjectManager:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def elementCount(self, /) -> int:
        pass
    def has(self, id : str|PyDb.ObjectId, /) -> bool:
        pass
    def idAt(self, val : int|str, /) -> PyDb.ObjectId:
        pass
    def ids(self, /) -> list[PyDb.ObjectId]:
        pass
    def nameAt(self, val : int, /) -> str:
        pass
    def names(self, /) -> list[str]:
        pass
    def remove(self, id : str|PyDb.ObjectId, /) -> bool:
        pass
    def toDict(self, /) -> dict:
        pass
class CvDbPoint(PyBrxCv.CvDbEntity):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def assignPointToPointGroup(cvpoint: PyBrxCv.CvDbPoint,groupid: PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def assignPointsToPointGroup(cvpoint: list[PyBrxCv.CvDbPoint],groupid: PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def assignStylesToPoints(cvpoint: list[PyBrxCv.CvDbPoint],symbolStyleId: PyDb.ObjectId,labelStyleId: PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbPoint:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbPoint:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def easting(self, /) -> float:
        pass
    def elevation(self, /) -> float:
        pass
    def fullDescription(self, /) -> str:
        pass
    @staticmethod
    def importPointsFromFile(files: list[str],fmtid: PyDb.ObjectId, /) -> list[PyBrxCv.CvDbPoint]:
        pass
    def isLabelDragged(self, /) -> bool:
        pass
    def isLabelPinned(self, /) -> bool:
        pass
    def labelId(self, /) -> PyDb.ObjectId:
        pass
    def labelLeaderVertices(self, /) -> list[PyGe.Point3d]:
        pass
    def labelPosition(self, /) -> PyGe.Point3d:
        pass
    def labelRotation(self, /) -> float:
        pass
    def northing(self, /) -> float:
        pass
    def number(self, /) -> int:
        pass
    def pointGroupsIds(self, /) -> list[PyDb.ObjectId]:
        pass
    def pointGroupsNames(self, /) -> list[str]:
        pass
    def position(self, /) -> PyGe.Point3d:
        pass
    def rawDescription(self, /) -> str:
        pass
    def referencedEntityAt(self, val : int, /) -> CvDbPointReferencedEntity:
        pass
    def referencedEntityCount(self, /) -> int:
        pass
    def resetLabel(self, /) -> bool:
        pass
    def setEasting(self, val : float, /) -> bool:
        pass
    def setElevation(self, val : float, /) -> bool:
        pass
    def setFullDescription(self, val : str, /) -> bool:
        pass
    def setLabelId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def setLabelLeaderVertices(self, vertices : list[PyGe.Point3d], /) -> bool:
        pass
    def setLabelPinned(self, val : bool, /) -> bool:
        pass
    def setLabelPosition(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def setLabelRotation(self, val : float, /) -> bool:
        pass
    def setNorthing(self, val : float, /) -> bool:
        pass
    def setNumber(self, val : int, /) -> bool:
        pass
    def setPosition(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def setRawDescription(self, val : str, /) -> bool:
        pass
    def setSymbolId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def setSymbolRotation(self, val : float, /) -> bool:
        pass
    def symbolId(self, /) -> PyDb.ObjectId:
        pass
    def symbolRotation(self, /) -> float:
        pass
    def update(self, /) -> bool:
        pass
class CvDbPointGroup(PyBrxCv.CvDbObject):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbPointGroup:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbPointGroup:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def excludeElevations(self, /) -> str:
        pass
    def excludeFullDescriptions(self, /) -> str:
        pass
    def excludeNames(self, /) -> str:
        pass
    def excludeNumbers(self, /) -> str:
        pass
    def excludeRawDescriptions(self, /) -> str:
        pass
    def excludeUserAttributesKeys(self, /) -> str:
        pass
    def excludeUserAttributesValues(self, /) -> str:
        pass
    def hasPoint(self, val : int, /) -> PyDb.ObjectId:
        pass
    def includeElevations(self, /) -> str:
        pass
    def includeFullDescriptions(self, /) -> str:
        pass
    def includeNames(self, /) -> str:
        pass
    def includeNumbers(self, /) -> str:
        pass
    def includeRawDescriptions(self, /) -> str:
        pass
    def includeUserAttributesKeys(self, /) -> str:
        pass
    def includeUserAttributesValues(self, /) -> str:
        pass
    def isApplicable(self, /) -> bool:
        pass
    def isEditable(self, /) -> bool:
        pass
    def pointCount(self, /) -> int:
        pass
    def pointIds(self, /) -> list[PyDb.ObjectId]:
        pass
    def setExcludeElevations(self, filter : str, /) -> bool:
        pass
    def setExcludeFullDescriptions(self, filter : str, /) -> bool:
        pass
    def setExcludeNames(self, filter : str, /) -> bool:
        pass
    def setExcludeNumbers(self, filter : str, /) -> bool:
        pass
    def setExcludeRawDescriptions(self, filter : str, /) -> bool:
        pass
    def setExcludeUserAttributesKeys(self, filter : str, /) -> bool:
        pass
    def setIncludeElevations(self, filter : str, /) -> bool:
        pass
    def setIncludeFullDescriptions(self, filter : str, /) -> bool:
        pass
    def setIncludeNames(self, filter : str, /) -> bool:
        pass
    def setIncludeNumbers(self, filter : str, /) -> bool:
        pass
    def setIncludeRawDescriptions(self, filter : str, /) -> bool:
        pass
    def setIncludeUserAttributesKeys(self, filter : str, /) -> bool:
        pass
    def setIncludeUserAttributesValues(self, filter : str, /) -> bool:
        pass
    def update(self, /) -> bool:
        pass
    def updateNeeded(self, /) -> bool:
        pass
class CvDbPointGroupManager(PyBrxCv.CvDbObjectManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbPointGroupManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbPointGroupManager:
        pass
    def createPointGroup(self, val : str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    def groupsWithPoint(self, val : int, /) -> list[PyDb.ObjectId]:
        pass
    def nextPointNumber(self, /) -> int:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbPointGroupManager:
        pass
    def setNextPointNumber(self, val : int, /) -> bool:
        pass
    def updatePointGroups(self, /) -> int:
        pass
class CvDbPointLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbPointLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbPointLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbPointLabelStyleManager:
        pass
class CvDbPointReferencedEntity(PyBrxCv.CvDbSubObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbPointReferencedEntity:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def id(self, /) -> PyDb.ObjectId:
        pass
    def setId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def type(self, /) -> PyRx.RxClass:
        pass
class CvDbStyle(PyBrxCv.CvDbObject):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createdBy(self, /) -> str:
        pass
    def createdDate(self, /) -> PyDb.Date:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def displaySetting(self, orientation: PyBrxCv.DisplayOrientation, partName: str, /) -> CvDbStylePartDisplaySettings:
        pass
    def displaySettings(self, orientation: PyBrxCv.DisplayOrientation, /) -> list[PyBrxCv.CvDbStylePartDisplaySettings]:
        pass
    def lastEditedBy(self, /) -> str:
        pass
    def lastEditedDate(self, /) -> PyDb.Date:
        pass
    def setCreatedBy(self, filter : str, /) -> None:
        pass
class CvDbStyleManager(PyBrxCv.CvDbObjectManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbStyleManager:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManager(db: PyDb.Database,styleType: PyBrxCv.StyleManagerType, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode,styleType: PyBrxCv.StyleManagerType, /) -> CvDbObjectManager:
        pass
class CvDbStylePartDisplaySettings(PyBrxCv.CvDbSubObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def color(self, /) -> PyDb.Color:
        pass
    def displaySetting(self, /) -> bool:
        pass
    def layer(self, /) -> PyDb.ObjectId:
        pass
    def lineType(self, /) -> PyDb.ObjectId:
        pass
    def lineTypeScale(self, /) -> float:
        pass
    def lineWeight(self, /) -> PyDb.LineWeight:
        pass
    def plotStyleNameId(self, /) -> PyDb.ObjectId:
        pass
    def plotStyleNameType(self, /) -> PyDb.PlotStyleNameType:
        pass
    def setColor(self, clr: PyDb.Color, /) -> None:
        pass
    def setLayer(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setLineType(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setLineTypeScale(self, val: float, /) -> None:
        pass
    def setLineWeight(self, val: PyDb.LineWeight, /) -> None:
        pass
    def setPlotStyleNameId(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setPlotStyleNameType(self, val: PyDb.PlotStyleNameType, /) -> None:
        pass
    def setVisible(self, val: bool, /) -> None:
        pass
class CvDbSubObject(PyRx.RxObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSubObject:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, val : str, /) -> bool:
        pass
    def setName(self, val : str, /) -> bool:
        pass
class CvDbSurfaceContourLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSurfaceContourLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbSurfaceContourLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbSurfaceContourLabelStyleManager:
        pass
class CvDbSurfaceElevationLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSurfaceElevationLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbSurfaceElevationLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbSurfaceElevationLabelStyleManager:
        pass
class CvDbSurfaceSlopeLabelStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSurfaceSlopeLabelStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbSurfaceSlopeLabelStyleManager:
        pass
    def createLabelStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbSurfaceSlopeLabelStyleManager:
        pass
class CvDbSymbolStyle(PyBrxCv.CvDbStyle):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, metric: bool, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def asPDMODE(self, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSymbolStyle:
        pass
    def circleFrame(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def customSymbol(self, /) -> CustomSymbol:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def fixedScale(self, /) -> PyGe.Scale3d:
        pass
    def maximumSize(self, /) -> float:
        pass
    def orientationReference(self, /) -> OrientationRef:
        pass
    def rotationAngle(self, /) -> float:
        pass
    def scalingType(self, /) -> ScalingType:
        pass
    def setCircleFrame(self, val: bool, /) -> None:
        pass
    def setCustomSymbol(self, val: PyBrxCv.CustomSymbol, /) -> None:
        pass
    def setFixedScale(self, scale: PyGe.Scale3d, /) -> None:
        pass
    def setMaximumSize(self, val: float, /) -> None:
        pass
    def setOrientationReference(self, val: PyBrxCv.OrientationRef, /) -> None:
        pass
    def setPDMODE(self, val: int, /) -> None:
        pass
    def setRotationAngle(self, val: float, /) -> None:
        pass
    def setScalingType(self, val: PyBrxCv.ScalingType, /) -> None:
        pass
    def setSize(self, val: float, /) -> None:
        pass
    def setSquareFrame(self, val: bool, /) -> None:
        pass
    def setSymbolBlockId(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setSymbolType(self, val: PyBrxCv.SymbolType, /) -> None:
        pass
    def size(self, /) -> float:
        pass
    def squareFrame(self, /) -> bool:
        pass
    def symbolBlockId(self, /) -> PyDb.ObjectId:
        pass
    def symbolType(self, /) -> SymbolType:
        pass
class CvDbSymbolStyleManager(PyBrxCv.CvDbStyleManager):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbSymbolStyleManager:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbSymbolStyleManager:
        pass
    def createSymbolStyle(self, name: str, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    @staticmethod
    def getManagerId(db: PyDb.Database, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def managerId() -> str:
        pass
    @staticmethod
    def openManager(db: PyDb.Database,mode: PyDb.OpenMode, /) -> CvDbSymbolStyleManager:
        pass
class CvDbTinSurface(PyBrxCv.CvDbEntity):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addConstraint(self, constraint : PyBrxCv.CvDbTinSurfaceConstraint, addReactor : bool, /) -> bool:
        pass
    def addConstraints(self, constraints : list[PyBrxCv.CvDbTinSurfaceConstraint], addReactor : bool, /) -> bool:
        pass
    def addDefinition(self, ref : PyBrxCv.CvDbTinSurfaceDefinition, /) -> int:
        pass
    def addPoint(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def addPoints(self, pts : list[PyGe.Point3d], /) -> bool:
        pass
    def area2d(self, visibleOnly : bool=False, /) -> float:
        pass
    def area3d(self, visibleOnly : bool=False, /) -> float:
        pass
    def boundingBox(self, /) -> tuple[PyGe.Point2d,PyGe.Point2d]:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurface:
        pass
    def changePointsElevations(self, pts : list[PyGe.Point3d], newZValues : list[float], /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbTinSurface:
        pass
    def closestPointTo(self, pt : PyGe.Point3d, /) -> PyGe.Point3d:
        pass
    def contains(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def contoursAtElevation(self, elevation : float, /) -> list[[PyGe.Point3d]]:
        pass
    def createSnapshot(self, /) -> int:
        pass
    def definitionAt(self, index : int, /) -> CvDbTinSurfaceDefinition:
        pass
    def definitionCount(self, /) -> int:
        pass
    def definitionIndex(self, ref : PyBrxCv.CvDbTinSurfaceDefinition, /) -> tuple[bool,int]:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def drapeId(self, id : PyDb.ObjectId, /) -> list[[PyGe.Point3d]]:
        pass
    def drapePoints(self, pts : list[PyGe.Point3d], /) -> list[[PyGe.Point3d]]:
        pass
    def elevationAtPoint(self, pt : PyGe.Point3d, /) -> tuple[bool,float]:
        pass
    def eraseConstraint(self, id : PyDb.ObjectId | int, removeReactor : bool, /) -> bool:
        pass
    def eraseConstraints(self, int64ids : list[int], removeReactor : bool, /) -> bool:
        pass
    def eraseConstraintsIds(self, ids : list[PyDb.ObjectId], removeReactor : bool, /) -> bool:
        pass
    def findDefinition(self, id : int, /) -> CvDbTinSurfaceDefinition:
        pass
    def findTinPointAt(self, pt : PyGe.Point3d, /) -> tuple[bool,PyBrxCv.CvTinPoint]:
        pass
    def findTinTrianglesAt(self, pt : PyGe.Point3d, /) -> list[PyBrx.CvTinTriangle]:
        pass
    def getBorders(self, /) -> list[[PyGe.Point3d]]:
        pass
    def getConstraint(self, id : PyDb.ObjectId|int, /) -> CvDbTinSurfaceConstraint:
        pass
    def getConstraints(self, /) -> list[PyBrxCv.CvDbTinSurfaceConstraint]:
        pass
    def getPoints(self, visibleOnly : bool=False, /) -> list[PyGe.Point3d]:
        pass
    def getPointsInsidePolygon(self, pts : list[PyGe.Point3d], includeOnEdge : bool, /) -> list[PyGe.Point3d]:
        pass
    def getTinPoints(self, /) -> list[PyBrx.CvTinPoint]:
        pass
    def hasSnapshot(self, /) -> bool:
        pass
    def initialize(self, min : PyGe.Point3d, max : PyGe.Point3d, numOfPoints : int, /) -> None:
        pass
    def insertDefinitionAt(self, index : int, ref : PyBrxCv.CvDbTinSurfaceDefinition, /) -> int:
        pass
    def intersectionsWithLine(self, start : PyGe.Point3d, end : PyGe.Point3d, type : PyBrxCv.TinSurfaceIntersectType, visibleOnly : bool, /) -> tuple[bool,[PyGe.Point3d]]:
        pass
    def isAssociative(self, /) -> bool:
        pass
    def isAutoUpdate(self, /) -> bool:
        pass
    def isRebuildPossible(self, /) -> bool:
        pass
    def isSnapshotUpdateNeeded(self, /) -> bool:
        pass
    def isUpdateNeeded(self, /) -> bool:
        pass
    def majorContours(self, /) -> list[[PyGe.Point3d]]:
        pass
    def majorContoursColor(self, /) -> tuple[bool,int]:
        pass
    def majorContoursInterval(self, /) -> tuple[bool,int]:
        pass
    def maxElevation(self, visibleOnly : bool=False, /) -> float:
        pass
    def merge(self, other : PyBrxCv.CvDbTinSurface, /) -> bool:
        pass
    def mergeSurfaces(theOne: PyBrxCv.CvDbTinSurface,theOther: PyBrxCv.CvDbTinSurface, /) -> CvDbTinSurface:
        pass
    def minElevation(self, visibleOnly : bool=False, /) -> float:
        pass
    def minorContours(self, /) -> list[[PyGe.Point3d]]:
        pass
    def minorContoursColor(self, /) -> tuple[bool,int]:
        pass
    def minorContoursInterval(self, /) -> tuple[bool,int]:
        pass
    def moveDefinition(self, _from : int, _to : int, /) -> int:
        pass
    def movePoint(self, _from : PyGe.Point3d, _to : PyGe.Point3d, /) -> bool:
        pass
    def movePoints(self, _from : list[PyGe.Point3d], _to : list[PyGe.Point3d], /) -> bool:
        pass
    def pointsCount(self, visibleOnly : bool=False, /) -> int:
        pass
    def raiseSurface(self, offset : float, /) -> bool:
        pass
    def rebuild(self, val : bool, /) -> bool:
        pass
    def rebuildSnapshot(self, /) -> bool:
        pass
    def removeAllDefinitions(self, /) -> int:
        pass
    def removeDefinitionAt(self, index: int, /) -> bool:
        pass
    def removePoint(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def removePoints(self, pts : list[PyGe.Point3d], /) -> bool:
        pass
    def removeSnapshot(self, /) -> bool:
        pass
    def setAssociative(self, isAssociative : bool, /) -> bool:
        pass
    def setIsAutoUpdate(self, autoUpdateOn : bool, /) -> bool:
        pass
    def setMajorContoursColor(self, colorIndex : int, /) -> bool:
        pass
    def setMajorContoursInterval(self, interval : float, /) -> bool:
        pass
    def setMinorContoursColor(self, colorIndex : int, /) -> bool:
        pass
    def setMinorContoursInterval(self, interval : float, /) -> bool:
        pass
    def setStyle(self, style : PyBrxCv.TinSurfaceStyle, /) -> bool:
        pass
    def setSurfaceElevation(self, elevation : float, /) -> bool:
        pass
    @overload
    def solid3d(self, surface: PyBrxCv.CvDbTinSurface, /) -> PyDb.Solid3d: ...
    @overload
    def solid3d(self, surfaceType: PyBrxCv.TinSurfaceMeshType, thickness: float, /) -> PyDb.Solid3d: ...
    def solid3d(self, *args) -> PyDb.Solid3d:
        pass
    def style(self, /) -> TinSurfaceStyle:
        pass
    @overload
    def subDMesh(self, /) -> PyDb.SubDMesh: ...
    @overload
    def subDMesh(self, surface: PyBrxCv.CvDbTinSurface, /) -> PyDb.SubDMesh: ...
    @overload
    def subDMesh(self, surfaceType: PyBrxCv.TinSurfaceMeshType, depthOrElevation: float, /) -> PyDb.SubDMesh: ...
    def subDMesh(self, *args) -> PyDb.SubDMesh:
        pass
    def swapEdge(self, pt : PyGe.Point3d, /) -> bool:
        pass
    def tinTriangles(self, /) -> list[PyBrx.CvTinTriangle]:
        pass
    def triangles(self, visibleOnly : bool=False, /) -> list[PyBrx.CvTinTriangle]:
        pass
    def trianglesCount(self, visibleOnly : bool=False, /) -> int:
        pass
    def updateConstraint(self, val : PyBrxCv.CvDbTinSurfaceConstraint, /) -> bool:
        pass
    def updateObjectData(self, /) -> None:
        pass
class CvDbTinSurfaceBoundary(PyBrxCv.CvDbTinSurfaceConstraint):
    def __init__(self, type: PyBrxCv.TinBoundaryType, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def wallType(self, /) -> TinBoundaryType:
        pass
class CvDbTinSurfaceBreakline(PyBrxCv.CvDbTinSurfaceConstraint):
    def __init__(self, type: PyBrxCv.TinBreaklineType, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def intersectionElevation(self, /) -> BreaklineIntersectionElevation:
        pass
    def setIntersectionElevation(self, val : PyBrxCv.TinBreaklineType, /) -> None:
        pass
class CvDbTinSurfaceConstraint:
    def __init__(self, type: PyBrxCv.TinConstraintType, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def constraintType(self, /) -> TinConstraintType:
        pass
    def data(self, /) -> list[PyGe.Point3d]:
        pass
    def id(self, /) -> int:
        pass
    def isDbResident(self, /) -> bool:
        pass
    def midOrdinateDistance(self, /) -> float:
        pass
    def setData(self, intId : int, pts : list[PyGe.Point3d], /) -> None:
        pass
    def setDataId(self, id : PyDb.ObjectId, midOrdinateDist : float, /) -> None:
        pass
    def setIsDbResident(self, val : bool, /) -> None:
        pass
    def setMidOrdinateDistance(self, val : float, /) -> None:
        pass
class CvDbTinSurfaceDefinition(PyBrxCv.CvDbSubObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinition:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def id(self, /) -> int:
        pass
    def isEnabled(self, /) -> bool:
        pass
    def isReadOnly(self, /) -> bool:
        pass
    def isSubDefinition(self, /) -> bool:
        pass
    def isUpdateNeeded(self, /) -> bool:
        pass
    def isValid(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, desc : str, /) -> bool:
        pass
    def setEnabled(self, val : bool, /) -> bool:
        pass
    def setName(self, name : str, /) -> bool:
        pass
    def setReadOnly(self, val : bool, /) -> bool:
        pass
    def type(self, /) -> TinSurfaceDefinitionType:
        pass
class CvDbTinSurfaceDefinitionAddDrawingObjects(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addEntity(self, entity: PyDb.Entity, /) -> bool:
        pass
    def addEntityId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddDrawingObjects:
        pass
    @staticmethod
    def className() -> str:
        pass
    def crossingsElevation(self, /) -> TinIntersectionElevation:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def drawingObjectAt(self, idx : int, /) -> tuple[bool,PyBrx.DrawingObjectTypet,[PyGe.Point3d]]:
        pass
    def drawingObjectsCount(self, /) -> int:
        pass
    def isApplyEdges(self, /) -> bool:
        pass
    def removeAllDrawingObjects(self, /) -> bool:
        pass
    def removeDrawingObjectAt(self, idx : int, /) -> bool:
        pass
    def setCrossingsElevation(self, val : PyBrxCv.TinIntersectionElevation, /) -> bool:
        pass
    def setIsApplyEdges(self, val : bool, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddFromFiles(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddFromFiles:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def fileFormatId(self, /) -> PyDb.ObjectId:
        pass
    def filesPaths(self, /) -> list[str]:
        pass
    def setFileFormatId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def setFilesPaths(self, val : list[str], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddFromPointClouds(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddFromPointClouds:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def pcObjectIds(self, /) -> list[PyDb.ObjectId]:
        pass
    def setPcObjectIds(self, val : list[PyDb.ObjectId], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddLine(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddLine:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def line(self, /) -> PyGe.LineSeg2d:
        pass
    def setLine(self, line : PyGe.LineSeg2d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddLines(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddLines:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def lines(self, /) -> list[PyGe.LineSeg3d]:
        pass
    def setLines(self, lines : list[PyGe.LineSeg2d], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddPoint(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddPoint:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def position(self, /) -> PyGe.Point3d:
        pass
    def setPosition(self, pt : PyGe.Point3d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddPointGroups(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddPointGroups:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def pointGroupsIds(self, /) -> list[PyDb.ObjectId]:
        pass
    def setPointGroupsIds(self, val : list[PyDb.ObjectId], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionAddPoints(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionAddPoints:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def positions(self, /) -> list[PyGe.Point2d]:
        pass
    def setPositions(self, pt : list[PyGe.Point3d], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionCreateFromC3D(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionCreateFromC3D:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def filePath(self, /) -> str:
        pass
    def setFilePath(self, val : str, /) -> bool:
        pass
    def setSurfaceName(self, val : str, /) -> bool:
        pass
    def surfaceName(self, /) -> str:
        pass
class CvDbTinSurfaceDefinitionCreateFromFaces(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionCreateFromFaces:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def faceAt(self, /) -> tuple[bool,PyDb.Face]:
        pass
    def facesCount(self, /) -> int:
        pass
    def isApplyEdgesVisibility(self, /) -> bool:
        pass
    def points(self, /) -> list[PyGe.Point3d]:
        pass
    def setIsApplyEdgesVisibility(self, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionCreateFromLandXML(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionCreateFromLandXML:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def dwgUnits(self, /) -> PyDb.UnitsValue:
        pass
    def filePath(self, /) -> str:
        pass
    def scaleToDwgUnits(self, /) -> bool:
        pass
    def setFilePath(self, val : str, /) -> bool:
        pass
    def setScaleToDwgUnits(self, val : bool, /) -> bool:
        pass
    def setSurfaceName(self, val : str, /) -> bool:
        pass
    def surfaceName(self, /) -> str:
        pass
class CvDbTinSurfaceDefinitionDeleteEdge(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionDeleteEdge:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def position(self, /) -> PyGe.Point2d:
        pass
    def setPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionDeleteEdges(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addPolygon(self, edgePolygon : list[PyGe.Point2d], includeIntersected : bool, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionDeleteEdges:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def polygonAt(self, index : int, /) -> tuple[bool,[PyGe.Point2d]]:
        pass
    def polygonsCount(self, /) -> int:
        pass
    def removeAllPolygons(self, /) -> bool:
        pass
    def removePolygonAt(self, index : int, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionDeletePoint(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionDeletePoint:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def position(self, /) -> PyGe.Point2d:
        pass
    def setPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionGroupDefs(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addSubDefinition(self, val : PyBrxCv.CvDbTinSurfaceDefinition, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionGroupDefs:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def findSubDefinition(self, defid : int, /) -> int:
        pass
    def getSubDefinitionAt(self, index : int, /) -> CvDbTinSurfaceDefinition:
        pass
    def numSubDefinitions(self, /) -> int:
        pass
    def removeSubDefinitionAt(self, index : int, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionModifyPointElevation(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionModifyPointElevation:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def elevation(self, /) -> float:
        pass
    def isDeltaElevation(self, /) -> bool:
        pass
    def position(self, /) -> PyGe.Point2d:
        pass
    def setElevation(self, val : float, /) -> bool:
        pass
    def setIsDeltaElevation(self, val : float, /) -> bool:
        pass
    def setPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionModifyPointsElevation(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionModifyPointsElevation:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def elevation(self, /) -> float:
        pass
    def isDeltaElevation(self, /) -> bool:
        pass
    def positions(self, /) -> list[PyGe.Point2d]:
        pass
    def setElevation(self, val : float, /) -> bool:
        pass
    def setPositions(self, pt : list[PyGe.Point2d], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionModifyPointsElevations(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addPointElevation(self, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionModifyPointsElevations:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def pointElevationAt(self, /) -> tuple[bool,PyGe.Point2d]:
        pass
    def pointElevationsCount(self, /) -> int:
        pass
    def removeAllPointElevations(self, /) -> bool:
        pass
    def removePointElevationAt(self, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionMovePoint(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionMovePoint:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def fromPosition(self, /) -> PyGe.Point2d:
        pass
    def setFromPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setToPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def toPosition(self, /) -> PyGe.Point2d:
        pass
class CvDbTinSurfaceDefinitionMovePoints(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionMovePoints:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def displacement(self, /) -> PyGe.Vector2d:
        pass
    def fromPoints(self, /) -> list[PyGe.Point2d]:
        pass
    def setDisplacement(self, vec : PyGe.Vector3d, /) -> bool:
        pass
    def setFromPoints(self, pt : list[PyGe.Point2d], /) -> bool:
        pass
class CvDbTinSurfaceDefinitionRemoveElevations(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionRemoveElevations:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def removeAbove(self, /) -> bool:
        pass
    def removeAboveElevation(self, /) -> float:
        pass
    def removeBelow(self, /) -> bool:
        pass
    def removeBelowElevation(self, /) -> float:
        pass
    def removedPointsCount(self, /) -> int:
        pass
    def setRemoveAbove(self, val : bool, /) -> bool:
        pass
    def setRemoveAboveElevation(self, val : float, /) -> bool:
        pass
    def setRemoveBelow(self, val : bool, /) -> bool:
        pass
    def setRemoveBelowElevation(self, val : float, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionRemoveOuterEdges(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionRemoveOuterEdges:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def maxAdjAngle(self, /) -> float:
        pass
    def maxEdgeLength(self, /) -> float:
        pass
    def minEdgeLength(self, /) -> float:
        pass
    def setMaxAdjAngle(self, val : float, /) -> bool:
        pass
    def setMaxEdgeLength(self, val : float, /) -> bool:
        pass
    def setMinEdgeLength(self, val : float, /) -> bool:
        pass
    def setUseMaxAdjAngle(self, val : bool, /) -> bool:
        pass
    def setUseMaxEdgeLength(self, val : bool, /) -> bool:
        pass
    def setUseMinEdgeLength(self, val : bool, /) -> bool:
        pass
    def useMaxAdjAngle(self, /) -> bool:
        pass
    def useMaxEdgeLength(self, /) -> bool:
        pass
    def useMinEdgeLength(self, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionRiseLower(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionRiseLower:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def offset(self, /) -> float:
        pass
    def setOffset(self, val : float, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionSwapEdge(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionSwapEdge:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def position(self, /) -> PyGe.Point2d:
        pass
    def setPosition(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbTinSurfaceDefinitionTransform(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionTransform:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def setTransformationMatrix(self, xform : PyGe.Matrix3d, /) -> bool:
        pass
    def transformationMatrix(self, /) -> PyGe.Matrix3d:
        pass
class CvDbTinSurfaceDefinitionTrianglesVisibility(PyBrxCv.CvDbTinSurfaceDefinition):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbTinSurfaceDefinitionTrianglesVisibility:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def positions(self, /) -> list[PyGe.Point2d]:
        pass
    def setPositions(self, val : list[PyGe.Point2d], /) -> bool:
        pass
    def setVisible(self, val : bool, /) -> bool:
        pass
    def visible(self, /) -> bool:
        pass
class CvDbTinSurfaceWall(PyBrxCv.CvDbTinSurfaceConstraint):
    def __init__(self, type: PyBrxCv.TinWallType, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def setHeight(self, val : float, /) -> None:
        pass
    def setWallSide(self, val : PyBrxCv.TinWallSide, /) -> None:
        pass
    def wallSide(self, /) -> TinWallSide:
        pass
    def wallType(self, /) -> TinWallType:
        pass
class CvDbVAlignment(PyBrxCv.CvDbCurve):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addArcAuto(self, prevId: int, nextId: int, /) -> int:
        pass
    def addArcBetween(self, prevId: int, nextId: int, radius: float, /) -> int:
        pass
    def addParabolaAuto(self, prevId: int, nextId: int, /) -> int:
        pass
    def addParabolaBetween(self, prevId: int, nextId: int, radius: float, /) -> int:
        pass
    def addTangentFixed(self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, /) -> int:
        pass
    def baseHAlignment(self, /) -> PyDb.ObjectId:
        pass
    def baseSurface(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignment:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbVAlignment:
        pass
    def curveAtPVI(self, pvi: PyBrxCv.CvDbVAlignmentPVI, /) -> int:
        pass
    def curveElementColor(self, /) -> int:
        pass
    def deleteElement(self, id: int, /) -> bool:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def elementAtId(self, id: int, /) -> CvDbVAlignmentElement:
        pass
    def elementCount(self, /) -> int:
        pass
    def elevationMax(self, /) -> float:
        pass
    def elevationMin(self, /) -> float:
        pass
    def firstElementId(self, /) -> int:
        pass
    def firstTangentElementId(self, /) -> int:
        pass
    def getElementId(self, gsMarker: int, /) -> int:
        pass
    def getElevationAt(self, station: float, /) -> tuple[bool,float]:
        pass
    def getElevations(self, /) -> list[PyGe.Point2d]:
        pass
    def getPVIsArrays(self, /) -> list[PyBrxCv.CvDbVAlignmentPVI]:
        pass
    def getRadius(self, param: float, /) -> float:
        pass
    def getUnorderedElementIds(self, /) -> list[int]:
        pass
    def insertTangentFixed(self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, val: int, /) -> int:
        pass
    def lastElementId(self, /) -> int:
        pass
    def length(self, /) -> float:
        pass
    def lineElementColor(self, /) -> int:
        pass
    def nextTangentElementId(self, id: int, /) -> int:
        pass
    def previousTangentElementId(self, id: int, /) -> int:
        pass
    def pviAtCurve(self, curve: PyBrxCv.CvDbVAlignmentCurve, /) -> CvDbVAlignmentPVI:
        pass
    def setBaseHAlignment(self, id: PyDb.ObjectId, /) -> bool:
        pass
    def setBaseSurface(self, id: PyDb.ObjectId, /) -> bool:
        pass
    def setCurveElementColor(self, val: int, /) -> bool:
        pass
    def setLineElementColor(self, val: int, /) -> bool:
        pass
    def setStyle(self, val: int, /) -> bool:
        pass
    def setTangentPolygonColor(self, val: int, /) -> bool:
        pass
    def setType(self, val: VAlignmentType, /) -> bool:
        pass
    def style(self, /) -> int:
        pass
    def tangentPolygonColor(self, /) -> int:
        pass
    def type(self, /) -> VAlignmentType:
        pass
    def update(self, updateDependencies: bool, /) -> bool:
        pass
class CvDbVAlignmentArc(PyBrxCv.CvDbVAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentArc:
        pass
    def center(self, /) -> PyGe.Point2d:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def gradeIn(self, /) -> float:
        pass
    def gradeOut(self, /) -> float:
        pass
    def isClockwise(self, /) -> bool:
        pass
    def radius(self, /) -> float:
        pass
    def setCenter(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setClockwise(self, val : bool, /) -> bool:
        pass
    def setRadius(self, val : float, /) -> bool:
        pass
class CvDbVAlignmentCurve(PyBrxCv.CvDbVAlignmentElement):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentCurve:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def endPoint(self, /) -> PyGe.Point2d:
        pass
    def length(self, /) -> float:
        pass
    def startPoint(self, /) -> PyGe.Point2d:
        pass
class CvDbVAlignmentElement(PyBrxCv.CvDbSubObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentElement:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def id(self, /) -> int:
        pass
    def nextId(self, /) -> int:
        pass
    def parameterConstraint(self, /) -> VAlignmentParameterConstraint:
        pass
    def previousId(self, /) -> int:
        pass
    def setNextId(self, val : int, /) -> bool:
        pass
    def setParameterConstraint(self, val : PyBrxCv.VAlignmentParameterConstraint, /) -> bool:
        pass
    def setPreviousId(self, val : int, /) -> bool:
        pass
    def setTangencyConstraint(self, val : PyBrxCv.VAlignmentTangencyConstraint, /) -> bool:
        pass
    def tangencyConstraint(self, /) -> VAlignmentTangencyConstraint:
        pass
    def type(self, /) -> VAlignmentElementType:
        pass
class CvDbVAlignmentPVI(PyBrxCv.CvDbVAlignmentElement):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentPVI:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def location(self, /) -> PyGe.Point2d:
        pass
class CvDbVAlignmentParabola(PyBrxCv.CvDbVAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentParabola:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def gradeIn(self, /) -> float:
        pass
    def gradeOut(self, /) -> float:
        pass
    def radius(self, /) -> float:
        pass
    def setRadius(self, val : float, /) -> bool:
        pass
class CvDbVAlignmentTangent(PyBrxCv.CvDbVAlignmentCurve):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentTangent:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def passThroughPoint1(self, /) -> PyGe.Point2d:
        pass
    def passThroughPoint2(self, /) -> PyGe.Point2d:
        pass
    def setPassThroughPoint1(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setPassThroughPoint2(self, pt : PyGe.Point2d, /) -> bool:
        pass
class CvDbVAlignmentView(PyBrxCv.CvDbView):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentView:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbVAlignmentView:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def update(self, bUpdateDependencies : bool=True, updateOrigin : bool=True, /) -> bool:
        pass
class CvDbView(PyBrxCv.CvDbEntity):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addGraph(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def baseElevation(self, /) -> float:
        pass
    def baseHAlignment(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbView:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbView:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def fromWCSPoint2d(self, pt : PyGe.Point2d, /) -> PyGe.Point2d:
        pass
    def fromWCSX(self, val : float, /) -> float:
        pass
    def fromWCSY(self, val : float, /) -> float:
        pass
    def graphAt(self, val : int, /) -> PyDb.ObjectId:
        pass
    def graphCount(self, /) -> int:
        pass
    def height(self, /) -> float:
        pass
    def horizontalScale(self, /) -> float:
        pass
    def length(self, /) -> float:
        pass
    def origin(self, /) -> PyGe.Point2d:
        pass
    def removeGraph(self, id: PyDb.ObjectId, /) -> bool:
        pass
    def setBaseElevation(self, val : float, /) -> bool:
        pass
    def setBaseHAlignment(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def setHeight(self, val : float, /) -> bool:
        pass
    def setHorizontalScale(self, val : float, /) -> bool:
        pass
    def setLength(self, val : float, /) -> bool:
        pass
    def setOrigin(self, pt : PyGe.Point2d, /) -> bool:
        pass
    def setVerticalScale(self, val : float, /) -> bool:
        pass
    def toWCSPoint2d(self, pt : PyGe.Point2d, /) -> PyGe.Point2d:
        pass
    def toWCSX(self, val : float, /) -> float:
        pass
    def toWCSY(self, val : float, /) -> float:
        pass
    def verticalScale(self, /) -> float:
        pass
class CvDbVolumeSurface(PyBrxCv.CvDbTinSurface):
    def __init__(self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def baseSurfaceObjectId(self, /) -> PyDb.ObjectId:
        pass
    def boundingPolygon(self, /) -> list[PyGe.Point3d]:
        pass
    def boundingPolygonObjectId(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyRx.RxObject, /) -> CvDbVolumeSurface:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def cloneFrom(otherObject: PyRx.RxObject, /) -> CvDbVolumeSurface:
        pass
    def comparisonSurfaceObjectId(self, /) -> PyDb.ObjectId:
        pass
    def cutVolume(self, /) -> float:
        pass
    def depthElevation(self, /) -> float:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def fillVolume(self, /) -> float:
        pass
    @overload
    def initialize(self, baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d], /) -> bool: ...
    @overload
    def initialize(self, baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d], midOrdinateDist: float, /) -> bool: ...
    @overload
    def initialize(self, baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygon: list[PyGe.Poin3d], /) -> bool: ...
    @overload
    def initialize(self, baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygonId: PyDb.ObjectId, midOrdinateDist: float, /) -> bool: ...
    def initialize(self, *args) -> bool:
        pass
    def type(self, /) -> VolumeSurfaceType:
        pass
class CvGradingRule:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxCv.CvGradingRule, /) -> CvGradingRule:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def convertRadToSlope() -> float:
        pass
    @staticmethod
    def convertSlopeToRad() -> float:
        pass
    def isNull(self, /) -> bool:
        pass
    def release(self, /) -> bool:
        pass
    def setSide(self, format : int, /) -> bool:
        pass
    def setSlopeFormat(self, format : int, /) -> bool:
        pass
    def side(self, /) -> GradingSide:
        pass
    def slopeFormat(self, /) -> GradingSlopeFormat:
        pass
    def type(self, /) -> GradingType:
        pass
class CvGradingSlopeOffsetRule(PyBrxCv.CvGradingRule):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxCv.CvGradingRule, /) -> CvGradingSlopeOffsetRule:
        pass
    @staticmethod
    def className() -> str:
        pass
    def offset(self, /) -> float:
        pass
    def setOffset(self, offset : float, /) -> bool:
        pass
    def setSlope(self, slope : float, /) -> bool:
        pass
    def slope(self, /) -> float:
        pass
class CvGradingSlopeSurfaceRule(PyBrxCv.CvGradingRule):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxCv.CvGradingRule, /) -> CvGradingSlopeSurfaceRule:
        pass
    @staticmethod
    def className() -> str:
        pass
    def cutSlope(self, /) -> float:
        pass
    def fillSlope(self, /) -> float:
        pass
    def setCutSlope(self, val : float, /) -> bool:
        pass
    def setFillSlope(self, val : float, /) -> bool:
        pass
    def setSurfaceId(self, id : PyDb.ObjectId, /) -> bool:
        pass
    def surfaceId(self, /) -> PyDb.ObjectId:
        pass
class CvStationEquation:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, rawStation: float, stationForward: float, type: StationEquationType, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def getRawStation(self, /) -> float:
        pass
    def getStationForward(self, /) -> float:
        pass
    def getType(self, /) -> StationEquationType:
        pass
    def isNull(self, /) -> bool:
        pass
    def setRawStation(self, val : float, /) -> bool:
        pass
    def setStationForward(self, val : float, /) -> bool:
        pass
    def setType(self, val : PyBrxCv.EStationEquationType, /) -> bool:
        pass
class CvStationEquations:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, alignment: PyBrxCv.CvDbHAlignment, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addStationEquation(self, equation : PyBrxCv.CvStationEquation, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getLengthFromRawStation(self, rawStation : float, /) -> float:
        pass
    def getRawStation(self, station : float, /) -> list[float]:
        pass
    def getRawStationFromLength(self, length : float, /) -> float:
        pass
    def getRefRawStartingStation(self, /) -> float:
        pass
    def getRefStartingLength(self, /) -> float:
        pass
    def getStartingStation(self, /) -> float:
        pass
    def getStation(self, rawStation : float, /) -> float:
        pass
    def getStationBack(self, idx : int, /) -> float:
        pass
    def getStationEquation(self, idx : int, /) -> CvStationEquation:
        pass
    def removeAllStationEquations(self, /) -> bool:
        pass
    def removeStationEquation(self, idx : int, /) -> bool:
        pass
    def setRefRawStartingStation(self, rawStartingStation : float, /) -> bool:
        pass
    def setRefStartingLength(self, startingStation : float, /) -> bool:
        pass
    def stationEquationsCount(self, /) -> int:
        pass
    def update(self, /) -> bool:
        pass
class CvTinPoint:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def isValid(self, /) -> bool:
        pass
    def location(self, /) -> PyGe.Point3d:
        pass
    def triangleWithPoint(self, /) -> CvTinTriangle:
        pass
class CvTinTriangle:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def isValid(self, /) -> bool:
        pass
    def isVisible(self, /) -> bool:
        pass
    def locationAt(self, index: int, /) -> PyGe.Point3d:
        pass
    def neighborAt(self, index: int, /) -> CvTinTriangle:
        pass
    def pointAt(self, index: int, /) -> CvTinPoint:
        pass
class DisplayMode(_BoostPythonEnum):
    eDisplayModeAsComposed: ClassVar[Self]  # 0
    eDisplayModeStackedText: ClassVar[Self]  # 1
class DisplayOrientation(_BoostPythonEnum):
    eDisplayOrientationPlan: ClassVar[Self]  # 0
    eDisplayOrientationModel: ClassVar[Self]  # 1
    eDisplayOrientationProfile: ClassVar[Self]  # 2
    eDisplayOrientationSection: ClassVar[Self]  # 3
class DrawingObjectType(_BoostPythonEnum):
    eUnknown: ClassVar[Self]  # 0
    ePoint: ClassVar[Self]  # 1
    eBlock: ClassVar[Self]  # 2
    eText: ClassVar[Self]  # 3
    eLine: ClassVar[Self]  # 4
    eFace: ClassVar[Self]  # 5
    ePolyline: ClassVar[Self]  # 6
    eCivilPoint: ClassVar[Self]  # 7
class ForcedInsertion(_BoostPythonEnum):
    eForcedInsertionNone: ClassVar[Self]  # 0
    eForcedInsertionTop: ClassVar[Self]  # 1
    eForcedInsertionBottom: ClassVar[Self]  # 2
class GradingCalculationMethod(_BoostPythonEnum):
    eGradingAccurate: ClassVar[Self]  # 0
    eGradingFast: ClassVar[Self]  # 1
class GradingSide(_BoostPythonEnum):
    eGradingSideNone: ClassVar[Self]  # -1
    eGradingSideLeft: ClassVar[Self]  # 0
    eGradingSideRight: ClassVar[Self]  # 1
class GradingSlopeFormat(_BoostPythonEnum):
    eSlopeNoFormat: ClassVar[Self]  # -1
    eSlopeRiseRun: ClassVar[Self]  # 0
    eSlopeDegrees: ClassVar[Self]  # 1
    eSlopePercent: ClassVar[Self]  # 2
    eSlopeRadians: ClassVar[Self]  # 3
class GradingStatus(_BoostPythonEnum):
    eGradingNoStatus: ClassVar[Self]  # 0
    eGradingOk: ClassVar[Self]  # 1
    eGradingUpdateNeeded: ClassVar[Self]  # 2
    eGradingIncorrectInputData: ClassVar[Self]  # 4
    eGradingSurfaceMissing: ClassVar[Self]  # 8
    eGradingRuleMissing: ClassVar[Self]  # 16
    eGradingInputDataOutsideSurface: ClassVar[Self]  # 32
    eGradingGradingOutsideSurface: ClassVar[Self]  # 64
    eGradingOffsetFailed: ClassVar[Self]  # 128
    eGradingMultipleOffsetResult: ClassVar[Self]  # 256
    eGradingZeroGrading: ClassVar[Self]  # 512
    eGradingUnknownError: ClassVar[Self]  # 1024
    eGradingInputDataMissing: ClassVar[Self]  # 2048
    eGradingInvalidInput: ClassVar[Self]  # 4096
    eGradingInvalidRule: ClassVar[Self]  # 8192
    eGradingTimeout: ClassVar[Self]  # 16384
class GradingType(_BoostPythonEnum):
    eGradingTypeNone: ClassVar[Self]  # -1
    eGradingTypeSlopeSurface: ClassVar[Self]  # 0
    eGradingTypeSlopeOffset: ClassVar[Self]  # 1
class GradingVisualStyle(_BoostPythonEnum):
    eGradingDrawNothing: ClassVar[Self]  # 0
    eGradingDrawSurface: ClassVar[Self]  # 1
    eGradingDrawRays: ClassVar[Self]  # 2
    eGradingDrawDaylight: ClassVar[Self]  # 4
class HAlignmentElementType(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eLine: ClassVar[Self]  # 1
    eArc: ClassVar[Self]  # 2
    eSpiral: ClassVar[Self]  # 3
    eSpiralCurveSpiral: ClassVar[Self]  # 4
    eSpiralLineSpiral: ClassVar[Self]  # 5
    eSpiralLine: ClassVar[Self]  # 6
    eLineSpiral: ClassVar[Self]  # 7
    eSpiralCurve: ClassVar[Self]  # 8
    eCurveSpiral: ClassVar[Self]  # 9
    eSpiralSpiralCurveSpiralSpiral: ClassVar[Self]  # 10
    eMultipleSegments: ClassVar[Self]  # 11
    eSpiralCurveSpiralCurveSpiral: ClassVar[Self]  # 12
    eSpiralCurveSpiralSpiralCurveSpiral: ClassVar[Self]  # 13
    eSpiralSpiral: ClassVar[Self]  # 14
    eSpiralSpiralCurve: ClassVar[Self]  # 15
    eCurveSpiralSpiral: ClassVar[Self]  # 16
    eCurveLineCurve: ClassVar[Self]  # 17
    eCurveReverseCurve: ClassVar[Self]  # 18
    eCurveCurveReverseCurve: ClassVar[Self]  # 19
    ePI: ClassVar[Self]  # 100
class HAlignmentParameterConstraint(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eAutomatic: ClassVar[Self]  # 100
    eLine_TwoPoints: ClassVar[Self]  # 200
    eLine_ThroughPoint: ClassVar[Self]  # 201
    eLine_Length: ClassVar[Self]  # 202
    eLine_BestFit: ClassVar[Self]  # 203
    eArc_ThreePoints: ClassVar[Self]  # 300
    eArc_CenterRadius: ClassVar[Self]  # 301
    eArc_CenterPassThrough: ClassVar[Self]  # 302
    eArc_PassThroughRadius: ClassVar[Self]  # 303
    eArc_PassThroughAttachToEnd: ClassVar[Self]  # 304
    eArc_PassThroughDirection: ClassVar[Self]  # 305
    eArc_Radius: ClassVar[Self]  # 306
    eArc_PassThrough: ClassVar[Self]  # 307
    eArc_RadiusAndLength: ClassVar[Self]  # 308
    eArc_PointOnTangent: ClassVar[Self]  # 309
    eArc_BestFit: ClassVar[Self]  # 310
    eSCS_SpiralInRadiusSpiralOut: ClassVar[Self]  # 400
    eSCS_SpiralLengthRadiusPassThrough: ClassVar[Self]  # 401
    eSCS_SpiralLengthRadiusArcLength: ClassVar[Self]  # 402
    eSCS_SpiralLengthRadius: ClassVar[Self]  # 403
    eSCS_SpiralLength: ClassVar[Self]  # 404
    eSCS_SpiralInLengthSpiralOutLength: ClassVar[Self]  # 405
    eSCS_SpiralInAValSpiralOutAVal: ClassVar[Self]  # 406
    eSCS_SpiralInAValRadiusSpiralOutAVal: ClassVar[Self]  # 407
    eSCS_SpiralAValRadiusPassThrough: ClassVar[Self]  # 408
    eSCS_SpiralAValRadiusArcLength: ClassVar[Self]  # 409
    eSCS_SpiralAValRadius: ClassVar[Self]  # 410
    eSCS_SpiralAVal: ClassVar[Self]  # 411
    eSCS_PointOnTangent: ClassVar[Self]  # 412
    eSpiral_StartPointDirRadiusLength: ClassVar[Self]  # 500
    eSpiral_StartPointDirStartAndEndRadiusLength: ClassVar[Self]  # 501
    eSTS_SpiralInLengthSpiralOutLength: ClassVar[Self]  # 600
    eSTS_TangentLength: ClassVar[Self]  # 601
    eSTS_SpiralInAValSpiralOutAVal: ClassVar[Self]  # 602
    eSTS_SpiralLengthTangentPassThrough: ClassVar[Self]  # 603
    eSTS_SpiralLengthTangentLength: ClassVar[Self]  # 604
    eSTS_SpiralAValTangentPassThrough : ClassVar[Self]  # 605
    eSTS_SpiralAValTangentLength: ClassVar[Self]  # 606
    eSSCSS_Sp1LenSp2LenRadiusPt: ClassVar[Self]  # 700
    eSSCSS_Sp1LenSp2LenPt1Pt2: ClassVar[Self]  # 701
    eSSCSS_Sp1AValSp2AValRadiusPt: ClassVar[Self]  # 702
    eSSCSS_Sp1AValSp2AValPt1Pt2: ClassVar[Self]  # 703
class HAlignmentTangencyConstraint(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eFixed: ClassVar[Self]  # 1
    ePrevious: ClassVar[Self]  # 2
    eNext: ClassVar[Self]  # 3
    eBoth: ClassVar[Self]  # 4
class HAlignmentVisualStyle(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eElements: ClassVar[Self]  # 1
    eTangentExtensions: ClassVar[Self]  # 2
    eElementExtensions: ClassVar[Self]  # 4
class LabelAnchor(_BoostPythonEnum):
    eLabelAnchors: ClassVar[Self]  # 0
    eLabelAnchorStart: ClassVar[Self]  # 0
    eLabelAnchorMiddle: ClassVar[Self]  # 1
    eLabelAnchorEnd: ClassVar[Self]  # 2
    eLabelAnchorTopLeft: ClassVar[Self]  # 3
    eLabelAnchorTopCenter: ClassVar[Self]  # 4
    eLabelAnchorTopRight: ClassVar[Self]  # 5
    eLabelAnchorMiddleLeft: ClassVar[Self]  # 6
    eLabelAnchorMiddleCenter: ClassVar[Self]  # 7
    eLabelAnchorMiddleRight: ClassVar[Self]  # 8
    eLabelAnchorBottomLeft: ClassVar[Self]  # 9
    eLabelAnchorBottomCenter: ClassVar[Self]  # 10
    eLabelAnchorBottomRight: ClassVar[Self]  # 11
    eLabelAnchorInsertionPoint: ClassVar[Self]  # 12
    eLabelAnchorCurveCenter: ClassVar[Self]  # 13
    eLabelAnchorCurvePI: ClassVar[Self]  # 14
    eLabelAnchorFeatureLocation: ClassVar[Self]  # 69
class LeaderAttachment(_BoostPythonEnum):
    eLeaderAttachmentTopOfTopLine: ClassVar[Self]  # 0
    eLeaderAttachmentMiddleOfTopLine: ClassVar[Self]  # 1
    eLeaderAttachmentMiddle: ClassVar[Self]  # 2
    eLeaderAttachmentMiddleOfBottomLine: ClassVar[Self]  # 3
    eLeaderAttachmentBottomOfBottomLine: ClassVar[Self]  # 4
class LeaderType(_BoostPythonEnum):
    eLeaderTypeStraight: ClassVar[Self]  # 0
    eLeaderTypeSpline: ClassVar[Self]  # 1
class LengthType(_BoostPythonEnum):
    eLengthTypeFixed: ClassVar[Self]  # 0
    eLengthTypePercentage: ClassVar[Self]  # 1
class OrientationRef(_BoostPythonEnum):
    eOrientationReferenceObject: ClassVar[Self]  # 0
    eOrientationReferenceView: ClassVar[Self]  # 1
    eOrientationReferenceWCS: ClassVar[Self]  # 2
    eOrientationReferenceStartLeaderAtMarker: ClassVar[Self]  # 9
class ScalingType(_BoostPythonEnum):
    eScalingTypeDrawingScale: ClassVar[Self]  # 0
    eScalingTypeFixedScale: ClassVar[Self]  # 1
    eScalingTypeAbsoluteUnits: ClassVar[Self]  # 2
    eScalingTypeRelativeToScreen: ClassVar[Self]  # 3
class SpiralCurveType(_BoostPythonEnum):
    eInCurve: ClassVar[Self]  # 0
    eOutCurve: ClassVar[Self]  # 1
class SpiralDefinitionType(_BoostPythonEnum):
    eClothoid: ClassVar[Self]  # 0
    eCubicParabola: ClassVar[Self]  # 1
class SpiralDefinitionTypeSpiral(_BoostPythonEnum):
    eClothoid: ClassVar[Self]  # 0
    eCubicParabola: ClassVar[Self]  # 1
class SpiralDirectionType(_BoostPythonEnum):
    eDirectionRight: ClassVar[Self]  # 0
    eDirectionLeft: ClassVar[Self]  # 1
class SpiralParameterType(_BoostPythonEnum):
    eClothoid: ClassVar[Self]  # 0
    eCubicParabola: ClassVar[Self]  # 0
class SpiralParameterType2(_BoostPythonEnum):
    eParamA: ClassVar[Self]  # 0
    eParamLength: ClassVar[Self]  # 1
class StationEquationType(_BoostPythonEnum):
    Increasing: ClassVar[Self]  # 0
    Decreasing: ClassVar[Self]  # 1
class StyleManagerType(_BoostPythonEnum):
    eSymbolStyle: ClassVar[Self]  # 0
    eLineLabel: ClassVar[Self]  # 1
    eCurveLabel: ClassVar[Self]  # 2
    ePointLabel: ClassVar[Self]  # 3
    eContourLabel: ClassVar[Self]  # 4
    eSurfaceSlopeLabel: ClassVar[Self]  # 5
    eSurfaceElevationLabel: ClassVar[Self]  # 6
class SymbolType(_BoostPythonEnum):
    eSymbolTypeACADPoint: ClassVar[Self]  # 0
    eSymbolTypeCustom: ClassVar[Self]  # 1
    eSymbolTypeBlock: ClassVar[Self]  # 2
    eSymbolTypeVerticalLine: ClassVar[Self]  # 3
class TinBoundaryType(_BoostPythonEnum):
    eTinShow: ClassVar[Self]  # 0
    eTinHide: ClassVar[Self]  # 1
    eTinOuter: ClassVar[Self]  # 2
class TinBreaklineType(_BoostPythonEnum):
    eTinBreaklineNormal: ClassVar[Self]  # 0
    eTinNonDestructive: ClassVar[Self]  # 1
class TinConstraintType(_BoostPythonEnum):
    eTinBreakline: ClassVar[Self]  # 0
    eTinBoundary: ClassVar[Self]  # 1
    eTinWall: ClassVar[Self]  # 2
class TinIntersectionElevation(_BoostPythonEnum):
    eTinNotAllowed: ClassVar[Self]  # 0
    eTinElevationMin: ClassVar[Self]  # 1
    eTinElevationMax: ClassVar[Self]  # 2
    eTinElevationMid: ClassVar[Self]  # 3
class TinSurfaceDefinitionType(_BoostPythonEnum):
    eNone: ClassVar[Self]  # 0
    eTransform: ClassVar[Self]  # 1
    eAddPoint: ClassVar[Self]  # 2
    eAddPoints: ClassVar[Self]  # 3
    eDeletePoint: ClassVar[Self]  # 4
    eDeletePoints: ClassVar[Self]  # 5
    eSwapEdge: ClassVar[Self]  # 6
    eMovePoint: ClassVar[Self]  # 7
    eMovePoints: ClassVar[Self]  # 8
    eAddBreaklines: ClassVar[Self]  # 9
    eAddBoundaries: ClassVar[Self]  # 10
    eAddWalls: ClassVar[Self]  # 11
    eVolume: ClassVar[Self]  # 12
    eMerge: ClassVar[Self]  # 13
    eDeleteEdge: ClassVar[Self]  # 14
    eDeleteEdges: ClassVar[Self]  # 15
    eAddLine: ClassVar[Self]  # 16
    eAddLines: ClassVar[Self]  # 17
    eModifyPointElevation: ClassVar[Self]  # 18
    eModifyPointsElevation: ClassVar[Self]  # 19
    eModifyPointsElevations: ClassVar[Self]  # 20
    eCreateFromFaces: ClassVar[Self]  # 21
    eAddDrawingObjects: ClassVar[Self]  # 22
    eCreateSnapshot: ClassVar[Self]  # 23
    eRiseLower: ClassVar[Self]  # 24
    eLandXML: ClassVar[Self]  # 25
    eAddPointFiles: ClassVar[Self]  # 26
    eAddPointGroups: ClassVar[Self]  # 27
    eAddPointClouds: ClassVar[Self]  # 28
    eGroupDefinitions: ClassVar[Self]  # 29
    eDeform: ClassVar[Self]  # 30
    eSmoothen: ClassVar[Self]  # 31
    eCreateMerged: ClassVar[Self]  # 32
    eIFC: ClassVar[Self]  # 33
    eCreateTypedSnapshot: ClassVar[Self]  # 34
    eCreateFromCorridor: ClassVar[Self]  # 35
    eCreateFromC3D: ClassVar[Self]  # 36
    eRemoveOuterEdges: ClassVar[Self]  # 37
    eCreateFromContours: ClassVar[Self]  # 38
    eMinimizeFlatAreas: ClassVar[Self]  # 39
    eTrianglesVisibility: ClassVar[Self]  # 40
    eRemoveBelowAboveElevation: ClassVar[Self]  # 41
class TinSurfaceIntersectType(_BoostPythonEnum):
    eTinSurfaceFirstOnly: ClassVar[Self]  # 0
    eTinSurfaceAll: ClassVar[Self]  # 1
class TinSurfaceMeshType(_BoostPythonEnum):
    eTinSurfaceMeshSurface: ClassVar[Self]  # 0
    eTinSurfaceMeshElevation: ClassVar[Self]  # 1
    eTinSurfaceMeshDepth: ClassVar[Self]  # 2
class TinSurfaceSolidType(_BoostPythonEnum):
    eSolidTypeSurfaceSurface: ClassVar[Self]  # 0
    eSolidTypeSurfaceElevation: ClassVar[Self]  # 1
    eSolidTypeSurfaceDepth: ClassVar[Self]  # 2
class TinSurfaceStyle(_BoostPythonEnum):
    eTinStyleNone: ClassVar[Self]  # 0
    eTinStyleBoundaryLine: ClassVar[Self]  # 1
    eTinStylePoints: ClassVar[Self]  # 2
    eTinStyleTriangles: ClassVar[Self]  # 4
    eTinStyleContours: ClassVar[Self]  # 8
    eTinStyleElevationTooltip: ClassVar[Self]  # 16
class TinWallSide(_BoostPythonEnum):
    eTinWallLeft: ClassVar[Self]  # 0
    eTinWallRight: ClassVar[Self]  # 1
class TinWallType(_BoostPythonEnum):
    eTinWallNormal: ClassVar[Self]  # 0
    eTinWallProjected: ClassVar[Self]  # 1
class VAlignmentElementType(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eTangent: ClassVar[Self]  # 1
    eArc: ClassVar[Self]  # 2
    eParabola: ClassVar[Self]  # 3
    ePVI: ClassVar[Self]  # 100
class VAlignmentParameterConstraint(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    ePassThroughPoints: ClassVar[Self]  # 1
    eRadius: ClassVar[Self]  # 2
    eLength: ClassVar[Self]  # 3
    eAngle: ClassVar[Self]  # 4
    eAutomatic: ClassVar[Self]  # 5
    ePointOnTangent: ClassVar[Self]  # 6
class VAlignmentTangencyConstraint(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eFixed: ClassVar[Self]  # 1
    ePrevious: ClassVar[Self]  # 2
    eNext: ClassVar[Self]  # 3
    eBoth: ClassVar[Self]  # 4
class VAlignmentType(_BoostPythonEnum):
    eLayout: ClassVar[Self]  # 0
    eStaticSurface: ClassVar[Self]  # 1
    eDynamicSurface: ClassVar[Self]  # 2
    eAutomatic: ClassVar[Self]  # 3
class VAlignmentVisualStyle(_BoostPythonEnum):
    eElements: ClassVar[Self]  # 1
    eTangents: ClassVar[Self]  # 2
    eExtensions: ClassVar[Self]  # 4
class VolumeSurfaceType(_BoostPythonEnum):
    eTinVolumeBaseComparison: ClassVar[Self]  # 0
    eTinVolumeToElevation: ClassVar[Self]  # 1
    eTinVolumeToDepth: ClassVar[Self]  # 2
