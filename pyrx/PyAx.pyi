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
ac0degrees: AcPlotRotation  # 0
ac100_1: AcPlotScale  # 32
ac10_1: AcPlotScale  # 31
ac180degrees: AcPlotRotation  # 2
ac1_1: AcPlotScale  # 16
ac1_10: AcPlotScale  # 21
ac1_100: AcPlotScale  # 27
ac1_128in_1f: AcPlotScale  # 1
ac1_16: AcPlotScale  # 22
ac1_16in_1ft: AcPlotScale  # 4
ac1_2: AcPlotScale  # 17
ac1_20: AcPlotScale  # 23
ac1_2in_1ft: AcPlotScale  # 10
ac1_30: AcPlotScale  # 24
ac1_32in_1ft: AcPlotScale  # 3
ac1_4: AcPlotScale  # 18
ac1_40: AcPlotScale  # 25
ac1_4in_1ft: AcPlotScale  # 8
ac1_5: AcPlotScale  # 19
ac1_50: AcPlotScale  # 26
ac1_64in_1ft: AcPlotScale  # 2
ac1_8: AcPlotScale  # 20
ac1_8in_1ft: AcPlotScale  # 6
ac1ft_1ft: AcPlotScale  # 15
ac1in_1ft: AcPlotScale  # 12
ac2000_Template: AcSaveAsType  # 14
ac2000_dwg: AcSaveAsType  # 12
ac2000_dxf: AcSaveAsType  # 13
ac2004_Template: AcSaveAsType  # 26
ac2004_dwg: AcSaveAsType  # 24
ac2004_dxf: AcSaveAsType  # 25
ac2007_Template: AcSaveAsType  # 38
ac2007_dwg: AcSaveAsType  # 36
ac2007_dxf: AcSaveAsType  # 37
ac2010_Template: AcSaveAsType  # 50
ac2010_dwg: AcSaveAsType  # 48
ac2010_dxf: AcSaveAsType  # 49
ac2013_Template: AcSaveAsType  # 62
ac2013_dwg: AcSaveAsType  # 60
ac2013_dxf: AcSaveAsType  # 61
ac2018_Template: AcSaveAsType  # 66
ac2018_dwg: AcSaveAsType  # 64
ac2018_dxf: AcSaveAsType  # 65
ac270degrees: AcPlotRotation  # 3
ac2_1: AcPlotScale  # 28
ac3_16in_1ft: AcPlotScale  # 7
ac3_32in_1ft: AcPlotScale  # 5
ac3_4in_1ft: AcPlotScale  # 11
ac3_8in_1ft: AcPlotScale  # 9
ac3in_1ft: AcPlotScale  # 13
ac4_1: AcPlotScale  # 29
ac6in_1ft: AcPlotScale  # 14
ac8_1: AcPlotScale  # 30
ac90degrees: AcPlotRotation  # 1
acAbove: AcDimVerticalJustification  # 1
acActiveViewport: AcRegenType  # 0
acAlignPntAcquisitionAutomatic: AcAlignmentPointAcquisition  # 0
acAlignPntAcquisitionShiftToAcquire: AcAlignmentPointAcquisition  # 1
acAlignmentAligned: AcAlignment  # 3
acAlignmentBottomCenter: AcAlignment  # 13
acAlignmentBottomLeft: AcAlignment  # 12
acAlignmentBottomRight: AcAlignment  # 14
acAlignmentCenter: AcAlignment  # 1
acAlignmentFit: AcAlignment  # 5
acAlignmentLeft: AcAlignment  # 0
acAlignmentMiddle: AcAlignment  # 4
acAlignmentMiddleCenter: AcAlignment  # 10
acAlignmentMiddleLeft: AcAlignment  # 9
acAlignmentMiddleRight: AcAlignment  # 11
acAlignmentRight: AcAlignment  # 2
acAlignmentTopCenter: AcAlignment  # 7
acAlignmentTopLeft: AcAlignment  # 6
acAlignmentTopRight: AcAlignment  # 8
acAllViewports: AcRegenType  # 1
acAngular: AcDynamicBlockReferencePropertyUnitsType  # 1
acAny: AcBlockScaling  # 0
acArchitectural: AcUnits  # 4
acArea: AcDynamicBlockReferencePropertyUnitsType  # 3
acArrowArchTick: AcDimArrowheadType  # 4
acArrowBoxBlank: AcDimArrowheadType  # 14
acArrowBoxFilled: AcDimArrowheadType  # 15
acArrowClosed: AcDimArrowheadType  # 2
acArrowClosedBlank: AcDimArrowheadType  # 1
acArrowDatumBlank: AcDimArrowheadType  # 16
acArrowDatumFilled: AcDimArrowheadType  # 17
acArrowDefault: AcDimArrowheadType  # 0
acArrowDot: AcDimArrowheadType  # 3
acArrowDotBlank: AcDimArrowheadType  # 12
acArrowDotSmall: AcDimArrowheadType  # 11
acArrowIntegral: AcDimArrowheadType  # 18
acArrowNone: AcDimArrowheadType  # 19
acArrowOblique: AcDimArrowheadType  # 5
acArrowOpen: AcDimArrowheadType  # 6
acArrowOpen30: AcDimArrowheadType  # 10
acArrowOpen90: AcDimArrowheadType  # 9
acArrowOrigin: AcDimArrowheadType  # 7
acArrowOrigin2: AcDimArrowheadType  # 8
acArrowSmall: AcDimArrowheadType  # 13
acArrowUserDefined: AcDimArrowheadType  # 20
acAttachmentAllLine: AcTextAttachmentType  # 8
acAttachmentBottomLine: AcTextAttachmentType  # 7
acAttachmentBottomOfBottom: AcTextAttachmentType  # 6
acAttachmentBottomOfTop: AcTextAttachmentType  # 2
acAttachmentBottomOfTopLine: AcTextAttachmentType  # 3
acAttachmentCenter: AcVerticalTextAttachmentType  # 0
acAttachmentHorizontal: AcTextAttachmentDirection  # 0
acAttachmentLinedCenter: AcVerticalTextAttachmentType  # 1
acAttachmentMiddle: AcTextAttachmentType  # 4
acAttachmentMiddleOfBottom: AcTextAttachmentType  # 5
acAttachmentMiddleOfTop: AcTextAttachmentType  # 1
acAttachmentPointBottomCenter: AcAttachmentPoint  # 8
acAttachmentPointBottomLeft: AcAttachmentPoint  # 7
acAttachmentPointBottomRight: AcAttachmentPoint  # 9
acAttachmentPointMiddleCenter: AcAttachmentPoint  # 5
acAttachmentPointMiddleLeft: AcAttachmentPoint  # 4
acAttachmentPointMiddleRight: AcAttachmentPoint  # 6
acAttachmentPointTopCenter: AcAttachmentPoint  # 2
acAttachmentPointTopLeft: AcAttachmentPoint  # 1
acAttachmentPointTopRight: AcAttachmentPoint  # 3
acAttachmentTopOfTop: AcTextAttachmentType  # 0
acAttachmentVertical: AcTextAttachmentDirection  # 1
acAttributeModeConstant: AcAttributeMode  # 2
acAttributeModeInvisible: AcAttributeMode  # 1
acAttributeModeLockPosition: AcAttributeMode  # 16
acAttributeModeMultipleLine: AcAttributeMode  # 32
acAttributeModeNormal: AcAttributeMode  # 0
acAttributeModePreset: AcAttributeMode  # 8
acAttributeModeVerify: AcAttributeMode  # 4
acBaseMenuGroup: AcMenuGroupType  # 0
acBezierSurfaceMesh: AcPolymeshType  # 8
acBlockBox: AcPredefBlockType  # 3
acBlockCircle: AcPredefBlockType  # 2
acBlockContent: AcMLeaderContentType  # 1
acBlockHexagon: AcPredefBlockType  # 4
acBlockImperial: AcPredefBlockType  # 0
acBlockSlot: AcPredefBlockType  # 1
acBlockTriangle: AcPredefBlockType  # 5
acBlockUserDefined: AcPredefBlockType  # 6
acBlue: AcColor  # 5
acBottom: AcMLineJustification  # 2
acBottomToTop: AcDrawingDirection  # 4
acByBlock: AcColor  # 0
acByLayer: AcColor  # 256
acByStyle: AcDrawingDirection  # 5
acChord: AcSplineKnotParameterizationType  # 0
acColorMethodByACI: AcColorMethod  # 195
acColorMethodByBlock: AcColorMethod  # 193
acColorMethodByLayer: AcColorMethod  # 192
acColorMethodByRGB: AcColorMethod  # 194
acColorMethodForeground: AcColorMethod  # 197
acConnectBase: AcBlockConnectionType  # 1
acConnectExtents: AcBlockConnectionType  # 0
acControlVertices: AcSplineMethodType  # 1
acCubicSpline3DPoly: Ac3DPolylineType  # 2
acCubicSplinePoly: AcPolylineType  # 3
acCubicSurfaceMesh: AcPolymeshType  # 6
acCustomParameterization: AcSplineKnotParameterizationType  # 15
acCyan: AcColor  # 4
acDecimal: AcUnits  # 2
acDefaultUnits: AcUnits  # -1
acDegreeMinuteSeconds: AcAngleUnits  # 1
acDegrees: AcAngleUnits  # 0
acDemandLoadDisabled: AcXRefDemandLoad  # 0
acDemandLoadEnabled: AcXRefDemandLoad  # 1
acDemandLoadEnabledWithCopy: AcXRefDemandLoad  # 2
acDisplay: AcPlotType  # 0
acDisplayDCS: AcCoordinateSystem  # 2
acDistance: AcDynamicBlockReferencePropertyUnitsType  # 2
acEdRepeatLastCommand: AcDrawingAreaSCMEdit  # 0
acEdSCM: AcDrawingAreaSCMEdit  # 1
acEnableSCM: AcDrawingAreaSCMCommand  # 2
acEnableSCMOptions: AcDrawingAreaSCMCommand  # 1
acEngineering: AcUnits  # 3
acEnter: AcDrawingAreaSCMCommand  # 0
acExtendBoth: AcExtendOption  # 3
acExtendNone: AcExtendOption  # 0
acExtendOtherEntity: AcExtendOption  # 2
acExtendThisEntity: AcExtendOption  # 1
acExtents: AcPlotType  # 1
acFit: AcSplineMethodType  # 0
acFitCurvePoly: AcPolylineType  # 1
acFontBold: AcTextFontStyle  # 2
acFontBoldItalic: AcTextFontStyle  # 3
acFontItalic: AcTextFontStyle  # 1
acFontRegular: AcTextFontStyle  # 0
acFractional: AcUnits  # 5
acFullPreview: AcPreviewMode  # 1
acGradientObject: AcHatchObjectType  # 1
acGrads: AcAngleUnits  # 2
acGreen: AcColor  # 3
acHatchLoopTypeDefault: AcLoopType  # 0
acHatchLoopTypeDerived: AcLoopType  # 4
acHatchLoopTypeExternal: AcLoopType  # 1
acHatchLoopTypePolyline: AcLoopType  # 2
acHatchLoopTypeTextbox: AcLoopType  # 8
acHatchObject: AcHatchObjectType  # 0
acHatchPatternTypeCustomDefined: AcPatternType  # 2
acHatchPatternTypePreDefined: AcPatternType  # 1
acHatchPatternTypeUserDefined: AcPatternType  # 0
acHatchStyleIgnore: AcHatchStyle  # 2
acHatchStyleNormal: AcHatchStyle  # 0
acHatchStyleOuter: AcHatchStyle  # 1
acHide: AcSplineFrameType  # 1
acHorizontalAlignmentAligned: AcHorizontalAlignment  # 3
acHorizontalAlignmentCenter: AcHorizontalAlignment  # 1
acHorizontalAlignmentFit: AcHorizontalAlignment  # 5
acHorizontalAlignmentLeft: AcHorizontalAlignment  # 0
acHorizontalAlignmentMiddle: AcHorizontalAlignment  # 4
acHorizontalAlignmentRight: AcHorizontalAlignment  # 2
acInVisibleLeader: AcMLeaderType  # 0
acInches: AcPlotPaperUnits  # 0
acInsertUnitsAngstroms: AcInsertUnits  # 11
acInsertUnitsAstronomicalUnits: AcInsertUnits  # 18
acInsertUnitsCentimeters: AcInsertUnits  # 5
acInsertUnitsDecameters: AcInsertUnits  # 15
acInsertUnitsDecimeters: AcInsertUnits  # 14
acInsertUnitsFeet: AcInsertUnits  # 2
acInsertUnitsGigameters: AcInsertUnits  # 17
acInsertUnitsHectometers: AcInsertUnits  # 16
acInsertUnitsInches: AcInsertUnits  # 1
acInsertUnitsKilometers: AcInsertUnits  # 7
acInsertUnitsLightYears: AcInsertUnits  # 19
acInsertUnitsMeters: AcInsertUnits  # 6
acInsertUnitsMicroinches: AcInsertUnits  # 8
acInsertUnitsMicrons: AcInsertUnits  # 13
acInsertUnitsMiles: AcInsertUnits  # 3
acInsertUnitsMillimeters: AcInsertUnits  # 4
acInsertUnitsMils: AcInsertUnits  # 9
acInsertUnitsNanometers: AcInsertUnits  # 12
acInsertUnitsParsecs: AcInsertUnits  # 20
acInsertUnitsUSSurveyFeet: AcInsertUnits  # 21
acInsertUnitsUSSurveyInch: AcInsertUnits  # 22
acInsertUnitsUSSurveyMile: AcInsertUnits  # 24
acInsertUnitsUSSurveyYard: AcInsertUnits  # 23
acInsertUnitsUnitless: AcInsertUnits  # 0
acInsertUnitsYards: AcInsertUnits  # 10
acIntersection: AcBooleanType  # 1
acJIS: AcDimVerticalJustification  # 3
acKeyboardEntry: AcKeyboardPriority  # 1
acKeyboardEntryExceptScripts: AcKeyboardPriority  # 2
acKeyboardRunningObjSnap: AcKeyboardPriority  # 0
acLayout: AcPlotType  # 5
acLeftToRight: AcDrawingDirection  # 1
acLimits: AcPlotType  # 2
acLineNoArrow: AcLeaderType  # 0
acLineSpacingStyleAtLeast: AcLineSpacingStyle  # 1
acLineSpacingStyleExactly: AcLineSpacingStyle  # 2
acLineWithArrow: AcLeaderType  # 2
acLnWt000: AcLineWeight  # 0
acLnWt005: AcLineWeight  # 5
acLnWt009: AcLineWeight  # 9
acLnWt013: AcLineWeight  # 13
acLnWt015: AcLineWeight  # 15
acLnWt018: AcLineWeight  # 18
acLnWt020: AcLineWeight  # 20
acLnWt025: AcLineWeight  # 25
acLnWt030: AcLineWeight  # 30
acLnWt035: AcLineWeight  # 35
acLnWt040: AcLineWeight  # 40
acLnWt050: AcLineWeight  # 50
acLnWt053: AcLineWeight  # 53
acLnWt060: AcLineWeight  # 60
acLnWt070: AcLineWeight  # 70
acLnWt080: AcLineWeight  # 80
acLnWt090: AcLineWeight  # 90
acLnWt100: AcLineWeight  # 100
acLnWt106: AcLineWeight  # 106
acLnWt120: AcLineWeight  # 120
acLnWt140: AcLineWeight  # 140
acLnWt158: AcLineWeight  # 158
acLnWt200: AcLineWeight  # 200
acLnWt211: AcLineWeight  # 211
acLnWtByBlock: AcLineWeight  # -2
acLnWtByLayer: AcLineWeight  # -1
acLnWtByLwDefault: AcLineWeight  # -3
acMTextContent: AcMLeaderContentType  # 2
acMagenta: AcColor  # 6
acMax: AcWindowState  # 3
acMenuFileCompiled: AcMenuFileType  # 0
acMenuFileSource: AcMenuFileType  # 1
acMenuItem: AcMenuItemType  # 0
acMenuSeparator: AcMenuItemType  # 1
acMenuSubMenu: AcMenuItemType  # 2
acMillimeters: AcPlotPaperUnits  # 1
acMin: AcWindowState  # 2
acModelSpace: AcActiveSpace  # 1
acNative: AcSaveAsType  # 64
acNoUnits: AcDynamicBlockReferencePropertyUnitsType  # 0
acNoneContent: AcMLeaderContentType  # 0
acNorm: AcWindowState  # 1
acOCS: AcCoordinateSystem  # 4
acOQGraphics: AcOleQuality  # 2
acOQHighPhoto: AcOleQuality  # 4
acOQLineArt: AcOleQuality  # 0
acOQPhoto: AcOleQuality  # 3
acOQText: AcOleQuality  # 1
acOutside: AcDimVerticalJustification  # 2
acPaperSpace: AcActiveSpace  # 0
acPaperSpaceDCS: AcCoordinateSystem  # 3
acPartialMenuGroup: AcMenuGroupType  # 1
acPartialPreview: AcPreviewMode  # 0
acPenWidth013: AcISOPenWidth  # 13
acPenWidth018: AcISOPenWidth  # 18
acPenWidth025: AcISOPenWidth  # 25
acPenWidth035: AcISOPenWidth  # 35
acPenWidth050: AcISOPenWidth  # 50
acPenWidth070: AcISOPenWidth  # 70
acPenWidth100: AcISOPenWidth  # 100
acPenWidth140: AcISOPenWidth  # 140
acPenWidth200: AcISOPenWidth  # 200
acPenWidthUnk: AcISOPenWidth  # -1
acPixels: AcPlotPaperUnits  # 2
acPreferenceClassic: AcKeyboardAccelerator  # 1
acPrinterAlertOnce: AcPrinterSpoolAlert  # 1
acPrinterAlwaysAlert: AcPrinterSpoolAlert  # 0
acPrinterNeverAlert: AcPrinterSpoolAlert  # 3
acPrinterNeverAlertLogOnce: AcPrinterSpoolAlert  # 2
acProxyBoundingBox: AcProxyImage  # 2
acProxyNotShow: AcProxyImage  # 0
acProxyShow: AcProxyImage  # 1
acQuadSpline3DPoly: Ac3DPolylineType  # 1
acQuadSplinePoly: AcPolylineType  # 2
acQuadSurfaceMesh: AcPolymeshType  # 5
acR12_dxf: AcSaveAsType  # 1
acR13_dwg: AcSaveAsType  # 4
acR13_dxf: AcSaveAsType  # 5
acR14_dwg: AcSaveAsType  # 8
acR14_dxf: AcSaveAsType  # 9
acR15_Template: AcSaveAsType  # 14
acR15_dwg: AcSaveAsType  # 12
acR15_dxf: AcSaveAsType  # 13
acR18_Template: AcSaveAsType  # 26
acR18_dwg: AcSaveAsType  # 24
acR18_dxf: AcSaveAsType  # 25
acRadians: AcAngleUnits  # 3
acRed: AcColor  # 1
acRepeatLastCommand: AcDrawingAreaSCMDefault  # 0
acRightToLeft: AcDrawingDirection  # 2
acSCM: AcDrawingAreaSCMDefault  # 1
acScaleToFit: AcPlotScale  # 0
acScientific: AcUnits  # 1
acSectionGenerationDestinationFile: AcSectionGeneration  # 64
acSectionGenerationDestinationNewBlock: AcSectionGeneration  # 16
acSectionGenerationDestinationReplaceBlock: AcSectionGeneration  # 32
acSectionGenerationSourceAllObjects: AcSectionGeneration  # 1
acSectionGenerationSourceSelectedObjects: AcSectionGeneration  # 2
acSelectionSetAll: AcSelect  # 5
acSelectionSetCrossing: AcSelect  # 1
acSelectionSetCrossingPolygon: AcSelect  # 7
acSelectionSetFence: AcSelect  # 2
acSelectionSetLast: AcSelect  # 4
acSelectionSetWindow: AcSelect  # 0
acSelectionSetWindowPolygon: AcSelect  # 6
acShow: AcSplineFrameType  # 0
acSimple3DPoly: Ac3DPolylineType  # 0
acSimpleMesh: AcPolymeshType  # 0
acSimplePoly: AcPolylineType  # 0
acSplineLeader: AcMLeaderType  # 2
acSplineNoArrow: AcLeaderType  # 1
acSplineWithArrow: AcLeaderType  # 3
acSqrtChord: AcSplineKnotParameterizationType  # 1
acStraightLeader: AcMLeaderType  # 1
acSubtraction: AcBooleanType  # 2
acToolbarButton: AcToolbarItemType  # 0
acToolbarControl: AcToolbarItemType  # 2
acToolbarDockBottom: AcToolbarDockStatus  # 1
acToolbarDockLeft: AcToolbarDockStatus  # 2
acToolbarDockRight: AcToolbarDockStatus  # 3
acToolbarDockTop: AcToolbarDockStatus  # 0
acToolbarFloating: AcToolbarDockStatus  # 4
acToolbarFlyout: AcToolbarItemType  # 3
acToolbarSeparator: AcToolbarItemType  # 1
acTop: AcMLineJustification  # 0
acTopToBottom: AcDrawingDirection  # 3
acUCS: AcCoordinateSystem  # 1
acUnder: AcDimVerticalJustification  # 4
acUniform: AcBlockScaling  # 1
acUniformParam: AcSplineKnotParameterizationType  # 2
acUnion: AcBooleanType  # 0
acUnknown: AcSaveAsType  # -1
acVertCentered: AcDimVerticalJustification  # 0
acVerticalAlignmentBaseline: AcVerticalAlignment  # 0
acVerticalAlignmentBottom: AcVerticalAlignment  # 1
acVerticalAlignmentMiddle: AcVerticalAlignment  # 2
acVerticalAlignmentTop: AcVerticalAlignment  # 3
acView: AcPlotType  # 3
acVp100_1: AcViewportScale  # 18
acVp10_1: AcViewportScale  # 17
acVp1_1: AcViewportScale  # 2
acVp1_10: AcViewportScale  # 7
acVp1_100: AcViewportScale  # 13
acVp1_128in_1ft: AcViewportScale  # 19
acVp1_16: AcViewportScale  # 8
acVp1_16in_1ft: AcViewportScale  # 22
acVp1_2: AcViewportScale  # 3
acVp1_20: AcViewportScale  # 9
acVp1_2in_1ft: AcViewportScale  # 28
acVp1_30: AcViewportScale  # 10
acVp1_32in_1ft: AcViewportScale  # 21
acVp1_4: AcViewportScale  # 4
acVp1_40: AcViewportScale  # 11
acVp1_4in_1ft: AcViewportScale  # 26
acVp1_5: AcViewportScale  # 5
acVp1_50: AcViewportScale  # 12
acVp1_64in_1ft: AcViewportScale  # 20
acVp1_8: AcViewportScale  # 6
acVp1_8in_1ft: AcViewportScale  # 24
acVp1and1_2in_1ft: AcViewportScale  # 31
acVp1ft_1ft: AcViewportScale  # 34
acVp1in_1ft: AcViewportScale  # 30
acVp2_1: AcViewportScale  # 14
acVp3_16in_1ft: AcViewportScale  # 25
acVp3_32in_1ft: AcViewportScale  # 23
acVp3_4in_1ft: AcViewportScale  # 29
acVp3_8in_1ft: AcViewportScale  # 27
acVp3in_1ft: AcViewportScale  # 32
acVp4_1: AcViewportScale  # 15
acVp6in_1ft: AcViewportScale  # 33
acVp8_1: AcViewportScale  # 16
acVpCustomScale: AcViewportScale  # 1
acVpScaleToFit: AcViewportScale  # 0
acWhite: AcColor  # 7
acWindow: AcPlotType  # 4
acWorld: AcCoordinateSystem  # 0
acYellow: AcColor  # 2
acZero: AcMLineJustification  # 1
acZoomScaledAbsolute: AcZoomScaleType  # 0
acZoomScaledRelative: AcZoomScaleType  # 1
acZoomScaledRelativePSpace: AcZoomScaleType  # 2
class Ac3DPolylineType(_BoostPythonEnum):
    acSimple3DPoly: ClassVar[Self]  # 0
    acQuadSpline3DPoly: ClassVar[Self]  # 1
    acCubicSpline3DPoly: ClassVar[Self]  # 2
class AcActiveSpace(_BoostPythonEnum):
    acPaperSpace: ClassVar[Self]  # 0
    acModelSpace: ClassVar[Self]  # 1
class AcAlignment(_BoostPythonEnum):
    acAlignmentLeft: ClassVar[Self]  # 0
    acAlignmentCenter: ClassVar[Self]  # 1
    acAlignmentRight: ClassVar[Self]  # 2
    acAlignmentAligned: ClassVar[Self]  # 3
    acAlignmentMiddle: ClassVar[Self]  # 4
    acAlignmentFit: ClassVar[Self]  # 5
    acAlignmentTopLeft: ClassVar[Self]  # 6
    acAlignmentTopCenter: ClassVar[Self]  # 7
    acAlignmentTopRight: ClassVar[Self]  # 8
    acAlignmentMiddleLeft: ClassVar[Self]  # 9
    acAlignmentMiddleCenter: ClassVar[Self]  # 10
    acAlignmentMiddleRight: ClassVar[Self]  # 11
    acAlignmentBottomLeft: ClassVar[Self]  # 12
    acAlignmentBottomCenter: ClassVar[Self]  # 13
    acAlignmentBottomRight: ClassVar[Self]  # 14
class AcAlignmentPointAcquisition(_BoostPythonEnum):
    acAlignPntAcquisitionAutomatic: ClassVar[Self]  # 0
    acAlignPntAcquisitionShiftToAcquire: ClassVar[Self]  # 1
class AcAngleUnits(_BoostPythonEnum):
    acDegrees: ClassVar[Self]  # 0
    acDegreeMinuteSeconds: ClassVar[Self]  # 1
    acGrads: ClassVar[Self]  # 2
    acRadians: ClassVar[Self]  # 3
class AcAttachmentPoint(_BoostPythonEnum):
    acAttachmentPointTopLeft: ClassVar[Self]  # 1
    acAttachmentPointTopCenter: ClassVar[Self]  # 2
    acAttachmentPointTopRight: ClassVar[Self]  # 3
    acAttachmentPointMiddleLeft: ClassVar[Self]  # 4
    acAttachmentPointMiddleCenter: ClassVar[Self]  # 5
    acAttachmentPointMiddleRight: ClassVar[Self]  # 6
    acAttachmentPointBottomLeft: ClassVar[Self]  # 7
    acAttachmentPointBottomCenter: ClassVar[Self]  # 8
    acAttachmentPointBottomRight: ClassVar[Self]  # 9
class AcAttributeMode(_BoostPythonEnum):
    acAttributeModeNormal: ClassVar[Self]  # 0
    acAttributeModeInvisible: ClassVar[Self]  # 1
    acAttributeModeConstant: ClassVar[Self]  # 2
    acAttributeModeVerify: ClassVar[Self]  # 4
    acAttributeModePreset: ClassVar[Self]  # 8
    acAttributeModeLockPosition: ClassVar[Self]  # 16
    acAttributeModeMultipleLine: ClassVar[Self]  # 32
class AcBlockConnectionType(_BoostPythonEnum):
    acConnectExtents: ClassVar[Self]  # 0
    acConnectBase: ClassVar[Self]  # 1
class AcBlockScaling(_BoostPythonEnum):
    acAny: ClassVar[Self]  # 0
    acUniform: ClassVar[Self]  # 1
class AcBooleanType(_BoostPythonEnum):
    acUnion: ClassVar[Self]  # 0
    acIntersection: ClassVar[Self]  # 1
    acSubtraction: ClassVar[Self]  # 2
class AcColor(_BoostPythonEnum):
    acByBlock: ClassVar[Self]  # 0
    acRed: ClassVar[Self]  # 1
    acYellow: ClassVar[Self]  # 2
    acGreen: ClassVar[Self]  # 3
    acCyan: ClassVar[Self]  # 4
    acBlue: ClassVar[Self]  # 5
    acMagenta: ClassVar[Self]  # 6
    acWhite: ClassVar[Self]  # 7
    acByLayer: ClassVar[Self]  # 256
class AcColorMethod(_BoostPythonEnum):
    acColorMethodByLayer: ClassVar[Self]  # 192
    acColorMethodByBlock: ClassVar[Self]  # 193
    acColorMethodByRGB: ClassVar[Self]  # 194
    acColorMethodByACI: ClassVar[Self]  # 195
    acColorMethodForeground: ClassVar[Self]  # 197
class AcCoordinateSystem(_BoostPythonEnum):
    acWorld: ClassVar[Self]  # 0
    acUCS: ClassVar[Self]  # 1
    acDisplayDCS: ClassVar[Self]  # 2
    acPaperSpaceDCS: ClassVar[Self]  # 3
    acOCS: ClassVar[Self]  # 4
class AcDimArrowheadType(_BoostPythonEnum):
    acArrowDefault: ClassVar[Self]  # 0
    acArrowClosedBlank: ClassVar[Self]  # 1
    acArrowClosed: ClassVar[Self]  # 2
    acArrowDot: ClassVar[Self]  # 3
    acArrowArchTick: ClassVar[Self]  # 4
    acArrowOblique: ClassVar[Self]  # 5
    acArrowOpen: ClassVar[Self]  # 6
    acArrowOrigin: ClassVar[Self]  # 7
    acArrowOrigin2: ClassVar[Self]  # 8
    acArrowOpen90: ClassVar[Self]  # 9
    acArrowOpen30: ClassVar[Self]  # 10
    acArrowDotSmall: ClassVar[Self]  # 11
    acArrowDotBlank: ClassVar[Self]  # 12
    acArrowSmall: ClassVar[Self]  # 13
    acArrowBoxBlank: ClassVar[Self]  # 14
    acArrowBoxFilled: ClassVar[Self]  # 15
    acArrowDatumBlank: ClassVar[Self]  # 16
    acArrowDatumFilled: ClassVar[Self]  # 17
    acArrowIntegral: ClassVar[Self]  # 18
    acArrowNone: ClassVar[Self]  # 19
    acArrowUserDefined: ClassVar[Self]  # 20
class AcDimVerticalJustification(_BoostPythonEnum):
    acVertCentered: ClassVar[Self]  # 0
    acAbove: ClassVar[Self]  # 1
    acOutside: ClassVar[Self]  # 2
    acJIS: ClassVar[Self]  # 3
    acUnder: ClassVar[Self]  # 4
class AcDrawingAreaSCMCommand(_BoostPythonEnum):
    acEnter: ClassVar[Self]  # 0
    acEnableSCMOptions: ClassVar[Self]  # 1
    acEnableSCM: ClassVar[Self]  # 2
class AcDrawingAreaSCMDefault(_BoostPythonEnum):
    acRepeatLastCommand: ClassVar[Self]  # 0
    acSCM: ClassVar[Self]  # 1
class AcDrawingAreaSCMEdit(_BoostPythonEnum):
    acEdRepeatLastCommand: ClassVar[Self]  # 0
    acEdSCM: ClassVar[Self]  # 1
class AcDrawingDirection(_BoostPythonEnum):
    acLeftToRight: ClassVar[Self]  # 1
    acRightToLeft: ClassVar[Self]  # 2
    acTopToBottom: ClassVar[Self]  # 3
    acBottomToTop: ClassVar[Self]  # 4
    acByStyle: ClassVar[Self]  # 5
class AcDynamicBlockReferencePropertyUnitsType(_BoostPythonEnum):
    acNoUnits: ClassVar[Self]  # 0
    acAngular: ClassVar[Self]  # 1
    acDistance: ClassVar[Self]  # 2
    acArea: ClassVar[Self]  # 3
class AcExtendOption(_BoostPythonEnum):
    acExtendNone: ClassVar[Self]  # 0
    acExtendThisEntity: ClassVar[Self]  # 1
    acExtendOtherEntity: ClassVar[Self]  # 2
    acExtendBoth: ClassVar[Self]  # 3
class AcHatchObjectType(_BoostPythonEnum):
    acHatchObject: ClassVar[Self]  # 0
    acGradientObject: ClassVar[Self]  # 1
class AcHatchStyle(_BoostPythonEnum):
    acHatchStyleNormal: ClassVar[Self]  # 0
    acHatchStyleOuter: ClassVar[Self]  # 1
    acHatchStyleIgnore: ClassVar[Self]  # 2
class AcHorizontalAlignment(_BoostPythonEnum):
    acHorizontalAlignmentLeft: ClassVar[Self]  # 0
    acHorizontalAlignmentCenter: ClassVar[Self]  # 1
    acHorizontalAlignmentRight: ClassVar[Self]  # 2
    acHorizontalAlignmentAligned: ClassVar[Self]  # 3
    acHorizontalAlignmentMiddle: ClassVar[Self]  # 4
    acHorizontalAlignmentFit: ClassVar[Self]  # 5
class AcISOPenWidth(_BoostPythonEnum):
    acPenWidth013: ClassVar[Self]  # 13
    acPenWidth018: ClassVar[Self]  # 18
    acPenWidth025: ClassVar[Self]  # 25
    acPenWidth035: ClassVar[Self]  # 35
    acPenWidth050: ClassVar[Self]  # 50
    acPenWidth070: ClassVar[Self]  # 70
    acPenWidth100: ClassVar[Self]  # 100
    acPenWidth140: ClassVar[Self]  # 140
    acPenWidth200: ClassVar[Self]  # 200
    acPenWidthUnk: ClassVar[Self]  # -1
class AcInsertUnits(_BoostPythonEnum):
    acInsertUnitsUnitless: ClassVar[Self]  # 0
    acInsertUnitsInches: ClassVar[Self]  # 1
    acInsertUnitsFeet: ClassVar[Self]  # 2
    acInsertUnitsMiles: ClassVar[Self]  # 3
    acInsertUnitsMillimeters: ClassVar[Self]  # 4
    acInsertUnitsCentimeters: ClassVar[Self]  # 5
    acInsertUnitsMeters: ClassVar[Self]  # 6
    acInsertUnitsKilometers: ClassVar[Self]  # 7
    acInsertUnitsMicroinches: ClassVar[Self]  # 8
    acInsertUnitsMils: ClassVar[Self]  # 9
    acInsertUnitsYards: ClassVar[Self]  # 10
    acInsertUnitsAngstroms: ClassVar[Self]  # 11
    acInsertUnitsNanometers: ClassVar[Self]  # 12
    acInsertUnitsMicrons: ClassVar[Self]  # 13
    acInsertUnitsDecimeters: ClassVar[Self]  # 14
    acInsertUnitsDecameters: ClassVar[Self]  # 15
    acInsertUnitsHectometers: ClassVar[Self]  # 16
    acInsertUnitsGigameters: ClassVar[Self]  # 17
    acInsertUnitsAstronomicalUnits: ClassVar[Self]  # 18
    acInsertUnitsLightYears: ClassVar[Self]  # 19
    acInsertUnitsParsecs: ClassVar[Self]  # 20
    acInsertUnitsUSSurveyFeet: ClassVar[Self]  # 21
    acInsertUnitsUSSurveyInch: ClassVar[Self]  # 22
    acInsertUnitsUSSurveyYard: ClassVar[Self]  # 23
    acInsertUnitsUSSurveyMile: ClassVar[Self]  # 24
class AcKeyboardAccelerator(_BoostPythonEnum):
    acPreferenceClassic: ClassVar[Self]  # 1
class AcKeyboardPriority(_BoostPythonEnum):
    acKeyboardRunningObjSnap: ClassVar[Self]  # 0
    acKeyboardEntry: ClassVar[Self]  # 1
    acKeyboardEntryExceptScripts: ClassVar[Self]  # 2
class AcLeaderType(_BoostPythonEnum):
    acLineNoArrow: ClassVar[Self]  # 0
    acSplineNoArrow: ClassVar[Self]  # 1
    acLineWithArrow: ClassVar[Self]  # 2
    acSplineWithArrow: ClassVar[Self]  # 3
class AcLineSpacingStyle(_BoostPythonEnum):
    acLineSpacingStyleAtLeast: ClassVar[Self]  # 1
    acLineSpacingStyleExactly: ClassVar[Self]  # 2
class AcLineWeight(_BoostPythonEnum):
    acLnWt000: ClassVar[Self]  # 0
    acLnWt005: ClassVar[Self]  # 5
    acLnWt009: ClassVar[Self]  # 9
    acLnWt013: ClassVar[Self]  # 13
    acLnWt015: ClassVar[Self]  # 15
    acLnWt018: ClassVar[Self]  # 18
    acLnWt020: ClassVar[Self]  # 20
    acLnWt025: ClassVar[Self]  # 25
    acLnWt030: ClassVar[Self]  # 30
    acLnWt035: ClassVar[Self]  # 35
    acLnWt040: ClassVar[Self]  # 40
    acLnWt050: ClassVar[Self]  # 50
    acLnWt053: ClassVar[Self]  # 53
    acLnWt060: ClassVar[Self]  # 60
    acLnWt070: ClassVar[Self]  # 70
    acLnWt080: ClassVar[Self]  # 80
    acLnWt090: ClassVar[Self]  # 90
    acLnWt100: ClassVar[Self]  # 100
    acLnWt106: ClassVar[Self]  # 106
    acLnWt120: ClassVar[Self]  # 120
    acLnWt140: ClassVar[Self]  # 140
    acLnWt158: ClassVar[Self]  # 158
    acLnWt200: ClassVar[Self]  # 200
    acLnWt211: ClassVar[Self]  # 211
    acLnWtByLayer: ClassVar[Self]  # -1
    acLnWtByBlock: ClassVar[Self]  # -2
    acLnWtByLwDefault: ClassVar[Self]  # -3
class AcLoopType(_BoostPythonEnum):
    acHatchLoopTypeDefault: ClassVar[Self]  # 0
    acHatchLoopTypeExternal: ClassVar[Self]  # 1
    acHatchLoopTypePolyline: ClassVar[Self]  # 2
    acHatchLoopTypeDerived: ClassVar[Self]  # 4
    acHatchLoopTypeTextbox: ClassVar[Self]  # 8
class AcMLeaderContentType(_BoostPythonEnum):
    acNoneContent: ClassVar[Self]  # 0
    acBlockContent: ClassVar[Self]  # 1
    acMTextContent: ClassVar[Self]  # 2
class AcMLeaderType(_BoostPythonEnum):
    acStraightLeader: ClassVar[Self]  # 1
    acSplineLeader: ClassVar[Self]  # 2
    acInVisibleLeader: ClassVar[Self]  # 0
class AcMLineJustification(_BoostPythonEnum):
    acTop: ClassVar[Self]  # 0
    acZero: ClassVar[Self]  # 1
    acBottom: ClassVar[Self]  # 2
class AcMenuFileType(_BoostPythonEnum):
    acMenuFileCompiled: ClassVar[Self]  # 0
    acMenuFileSource: ClassVar[Self]  # 1
class AcMenuGroupType(_BoostPythonEnum):
    acBaseMenuGroup: ClassVar[Self]  # 0
    acPartialMenuGroup: ClassVar[Self]  # 1
class AcMenuItemType(_BoostPythonEnum):
    acMenuItem: ClassVar[Self]  # 0
    acMenuSeparator: ClassVar[Self]  # 1
    acMenuSubMenu: ClassVar[Self]  # 2
class AcOleQuality(_BoostPythonEnum):
    acOQLineArt: ClassVar[Self]  # 0
    acOQText: ClassVar[Self]  # 1
    acOQGraphics: ClassVar[Self]  # 2
    acOQPhoto: ClassVar[Self]  # 3
    acOQHighPhoto: ClassVar[Self]  # 4
class AcPatternType(_BoostPythonEnum):
    acHatchPatternTypeUserDefined: ClassVar[Self]  # 0
    acHatchPatternTypePreDefined: ClassVar[Self]  # 1
    acHatchPatternTypeCustomDefined: ClassVar[Self]  # 2
class AcPlotPaperUnits(_BoostPythonEnum):
    acInches: ClassVar[Self]  # 0
    acMillimeters: ClassVar[Self]  # 1
    acPixels: ClassVar[Self]  # 2
class AcPlotRotation(_BoostPythonEnum):
    ac0degrees: ClassVar[Self]  # 0
    ac90degrees: ClassVar[Self]  # 1
    ac180degrees: ClassVar[Self]  # 2
    ac270degrees: ClassVar[Self]  # 3
class AcPlotScale(_BoostPythonEnum):
    acScaleToFit: ClassVar[Self]  # 0
    ac1_128in_1f: ClassVar[Self]  # 1
    ac1_64in_1ft: ClassVar[Self]  # 2
    ac1_32in_1ft: ClassVar[Self]  # 3
    ac1_16in_1ft: ClassVar[Self]  # 4
    ac3_32in_1ft: ClassVar[Self]  # 5
    ac1_8in_1ft: ClassVar[Self]  # 6
    ac3_16in_1ft: ClassVar[Self]  # 7
    ac1_4in_1ft: ClassVar[Self]  # 8
    ac3_8in_1ft: ClassVar[Self]  # 9
    ac1_2in_1ft: ClassVar[Self]  # 10
    ac3_4in_1ft: ClassVar[Self]  # 11
    ac1in_1ft: ClassVar[Self]  # 12
    ac3in_1ft: ClassVar[Self]  # 13
    ac6in_1ft: ClassVar[Self]  # 14
    ac1ft_1ft: ClassVar[Self]  # 15
    ac1_1: ClassVar[Self]  # 16
    ac1_2: ClassVar[Self]  # 17
    ac1_4: ClassVar[Self]  # 18
    ac1_5: ClassVar[Self]  # 19
    ac1_8: ClassVar[Self]  # 20
    ac1_10: ClassVar[Self]  # 21
    ac1_16: ClassVar[Self]  # 22
    ac1_20: ClassVar[Self]  # 23
    ac1_30: ClassVar[Self]  # 24
    ac1_40: ClassVar[Self]  # 25
    ac1_50: ClassVar[Self]  # 26
    ac1_100: ClassVar[Self]  # 27
    ac2_1: ClassVar[Self]  # 28
    ac4_1: ClassVar[Self]  # 29
    ac8_1: ClassVar[Self]  # 30
    ac10_1: ClassVar[Self]  # 31
    ac100_1: ClassVar[Self]  # 32
class AcPlotType(_BoostPythonEnum):
    acDisplay: ClassVar[Self]  # 0
    acExtents: ClassVar[Self]  # 1
    acLimits: ClassVar[Self]  # 2
    acView: ClassVar[Self]  # 3
    acWindow: ClassVar[Self]  # 4
    acLayout: ClassVar[Self]  # 5
class AcPolylineType(_BoostPythonEnum):
    acSimplePoly: ClassVar[Self]  # 0
    acFitCurvePoly: ClassVar[Self]  # 1
    acQuadSplinePoly: ClassVar[Self]  # 2
    acCubicSplinePoly: ClassVar[Self]  # 3
class AcPolymeshType(_BoostPythonEnum):
    acSimpleMesh: ClassVar[Self]  # 0
    acQuadSurfaceMesh: ClassVar[Self]  # 5
    acCubicSurfaceMesh: ClassVar[Self]  # 6
    acBezierSurfaceMesh: ClassVar[Self]  # 8
class AcPredefBlockType(_BoostPythonEnum):
    acBlockImperial: ClassVar[Self]  # 0
    acBlockSlot: ClassVar[Self]  # 1
    acBlockCircle: ClassVar[Self]  # 2
    acBlockBox: ClassVar[Self]  # 3
    acBlockHexagon: ClassVar[Self]  # 4
    acBlockTriangle: ClassVar[Self]  # 5
    acBlockUserDefined: ClassVar[Self]  # 6
class AcPreviewMode(_BoostPythonEnum):
    acPartialPreview: ClassVar[Self]  # 0
    acFullPreview: ClassVar[Self]  # 1
class AcPrinterSpoolAlert(_BoostPythonEnum):
    acPrinterAlwaysAlert: ClassVar[Self]  # 0
    acPrinterAlertOnce: ClassVar[Self]  # 1
    acPrinterNeverAlertLogOnce: ClassVar[Self]  # 2
    acPrinterNeverAlert: ClassVar[Self]  # 3
class AcProxyImage(_BoostPythonEnum):
    acProxyNotShow: ClassVar[Self]  # 0
    acProxyShow: ClassVar[Self]  # 1
    acProxyBoundingBox: ClassVar[Self]  # 2
class AcRegenType(_BoostPythonEnum):
    acActiveViewport: ClassVar[Self]  # 0
    acAllViewports: ClassVar[Self]  # 1
class AcSaveAsType(_BoostPythonEnum):
    acUnknown: ClassVar[Self]  # -1
    acR12_dxf: ClassVar[Self]  # 1
    acR13_dwg: ClassVar[Self]  # 4
    acR13_dxf: ClassVar[Self]  # 5
    acR14_dwg: ClassVar[Self]  # 8
    acR14_dxf: ClassVar[Self]  # 9
    ac2000_dwg: ClassVar[Self]  # 12
    ac2000_dxf: ClassVar[Self]  # 13
    ac2000_Template: ClassVar[Self]  # 14
    ac2004_dwg: ClassVar[Self]  # 24
    ac2004_dxf: ClassVar[Self]  # 25
    ac2004_Template: ClassVar[Self]  # 26
    ac2007_dwg: ClassVar[Self]  # 36
    ac2007_dxf: ClassVar[Self]  # 37
    ac2007_Template: ClassVar[Self]  # 38
    ac2010_dwg: ClassVar[Self]  # 48
    ac2010_dxf: ClassVar[Self]  # 49
    ac2010_Template: ClassVar[Self]  # 50
    ac2013_dwg: ClassVar[Self]  # 60
    ac2013_dxf: ClassVar[Self]  # 61
    ac2013_Template: ClassVar[Self]  # 62
    ac2018_dwg: ClassVar[Self]  # 64
    ac2018_dxf: ClassVar[Self]  # 65
    ac2018_Template: ClassVar[Self]  # 66
    acNative: ClassVar[Self]  # 64
    acR15_dwg: ClassVar[Self]  # 12
    acR15_dxf: ClassVar[Self]  # 13
    acR15_Template: ClassVar[Self]  # 14
    acR18_dwg: ClassVar[Self]  # 24
    acR18_dxf: ClassVar[Self]  # 25
    acR18_Template: ClassVar[Self]  # 26
class AcSectionGeneration(_BoostPythonEnum):
    acSectionGenerationSourceAllObjects: ClassVar[Self]  # 1
    acSectionGenerationSourceSelectedObjects: ClassVar[Self]  # 2
    acSectionGenerationDestinationNewBlock: ClassVar[Self]  # 16
    acSectionGenerationDestinationReplaceBlock: ClassVar[Self]  # 32
    acSectionGenerationDestinationFile: ClassVar[Self]  # 64
class AcSelect(_BoostPythonEnum):
    acSelectionSetWindow: ClassVar[Self]  # 0
    acSelectionSetCrossing: ClassVar[Self]  # 1
    acSelectionSetFence: ClassVar[Self]  # 2
    acSelectionSetLast: ClassVar[Self]  # 4
    acSelectionSetAll: ClassVar[Self]  # 5
    acSelectionSetWindowPolygon: ClassVar[Self]  # 6
    acSelectionSetCrossingPolygon: ClassVar[Self]  # 7
class AcSplineFrameType(_BoostPythonEnum):
    acShow: ClassVar[Self]  # 0
    acHide: ClassVar[Self]  # 1
class AcSplineKnotParameterizationType(_BoostPythonEnum):
    acChord: ClassVar[Self]  # 0
    acSqrtChord: ClassVar[Self]  # 1
    acUniformParam: ClassVar[Self]  # 2
    acCustomParameterization: ClassVar[Self]  # 15
class AcSplineMethodType(_BoostPythonEnum):
    acFit: ClassVar[Self]  # 0
    acControlVertices: ClassVar[Self]  # 1
class AcTextAttachmentDirection(_BoostPythonEnum):
    acAttachmentHorizontal: ClassVar[Self]  # 0
    acAttachmentVertical: ClassVar[Self]  # 1
class AcTextAttachmentType(_BoostPythonEnum):
    acAttachmentTopOfTop: ClassVar[Self]  # 0
    acAttachmentMiddleOfTop: ClassVar[Self]  # 1
    acAttachmentBottomOfTop: ClassVar[Self]  # 2
    acAttachmentBottomOfTopLine: ClassVar[Self]  # 3
    acAttachmentMiddle: ClassVar[Self]  # 4
    acAttachmentMiddleOfBottom: ClassVar[Self]  # 5
    acAttachmentBottomOfBottom: ClassVar[Self]  # 6
    acAttachmentBottomLine: ClassVar[Self]  # 7
    acAttachmentAllLine: ClassVar[Self]  # 8
class AcTextFontStyle(_BoostPythonEnum):
    acFontRegular: ClassVar[Self]  # 0
    acFontItalic: ClassVar[Self]  # 1
    acFontBold: ClassVar[Self]  # 2
    acFontBoldItalic: ClassVar[Self]  # 3
class AcToolbarDockStatus(_BoostPythonEnum):
    acToolbarDockTop: ClassVar[Self]  # 0
    acToolbarDockBottom: ClassVar[Self]  # 1
    acToolbarDockLeft: ClassVar[Self]  # 2
    acToolbarDockRight: ClassVar[Self]  # 3
    acToolbarFloating: ClassVar[Self]  # 4
class AcToolbarItemType(_BoostPythonEnum):
    acToolbarButton: ClassVar[Self]  # 0
    acToolbarSeparator: ClassVar[Self]  # 1
    acToolbarControl: ClassVar[Self]  # 2
    acToolbarFlyout: ClassVar[Self]  # 3
class AcUnits(_BoostPythonEnum):
    acDefaultUnits: ClassVar[Self]  # -1
    acScientific: ClassVar[Self]  # 1
    acDecimal: ClassVar[Self]  # 2
    acEngineering: ClassVar[Self]  # 3
    acArchitectural: ClassVar[Self]  # 4
    acFractional: ClassVar[Self]  # 5
class AcVerticalAlignment(_BoostPythonEnum):
    acVerticalAlignmentBaseline: ClassVar[Self]  # 0
    acVerticalAlignmentBottom: ClassVar[Self]  # 1
    acVerticalAlignmentMiddle: ClassVar[Self]  # 2
    acVerticalAlignmentTop: ClassVar[Self]  # 3
class AcVerticalTextAttachmentType(_BoostPythonEnum):
    acAttachmentCenter: ClassVar[Self]  # 0
    acAttachmentLinedCenter: ClassVar[Self]  # 1
class AcViewportScale(_BoostPythonEnum):
    acVpScaleToFit: ClassVar[Self]  # 0
    acVpCustomScale: ClassVar[Self]  # 1
    acVp1_1: ClassVar[Self]  # 2
    acVp1_2: ClassVar[Self]  # 3
    acVp1_4: ClassVar[Self]  # 4
    acVp1_5: ClassVar[Self]  # 5
    acVp1_8: ClassVar[Self]  # 6
    acVp1_10: ClassVar[Self]  # 7
    acVp1_16: ClassVar[Self]  # 8
    acVp1_20: ClassVar[Self]  # 9
    acVp1_30: ClassVar[Self]  # 10
    acVp1_40: ClassVar[Self]  # 11
    acVp1_50: ClassVar[Self]  # 12
    acVp1_100: ClassVar[Self]  # 13
    acVp2_1: ClassVar[Self]  # 14
    acVp4_1: ClassVar[Self]  # 15
    acVp8_1: ClassVar[Self]  # 16
    acVp10_1: ClassVar[Self]  # 17
    acVp100_1: ClassVar[Self]  # 18
    acVp1_128in_1ft: ClassVar[Self]  # 19
    acVp1_64in_1ft: ClassVar[Self]  # 20
    acVp1_32in_1ft: ClassVar[Self]  # 21
    acVp1_16in_1ft: ClassVar[Self]  # 22
    acVp3_32in_1ft: ClassVar[Self]  # 23
    acVp1_8in_1ft: ClassVar[Self]  # 24
    acVp3_16in_1ft: ClassVar[Self]  # 25
    acVp1_4in_1ft: ClassVar[Self]  # 26
    acVp3_8in_1ft: ClassVar[Self]  # 27
    acVp1_2in_1ft: ClassVar[Self]  # 28
    acVp3_4in_1ft: ClassVar[Self]  # 29
    acVp1in_1ft: ClassVar[Self]  # 30
    acVp1and1_2in_1ft: ClassVar[Self]  # 31
    acVp3in_1ft: ClassVar[Self]  # 32
    acVp6in_1ft: ClassVar[Self]  # 33
    acVp1ft_1ft: ClassVar[Self]  # 34
class AcWindowState(_BoostPythonEnum):
    acNorm: ClassVar[Self]  # 1
    acMin: ClassVar[Self]  # 2
    acMax: ClassVar[Self]  # 3
class AcXRefDemandLoad(_BoostPythonEnum):
    acDemandLoadDisabled: ClassVar[Self]  # 0
    acDemandLoadEnabled: ClassVar[Self]  # 1
    acDemandLoadEnabledWithCopy: ClassVar[Self]  # 2
class AcZoomScaleType(_BoostPythonEnum):
    acZoomScaledAbsolute: ClassVar[Self]  # 0
    acZoomScaledRelative: ClassVar[Self]  # 1
    acZoomScaledRelativePSpace: ClassVar[Self]  # 2
class Acad3DFace(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> Acad3DFace:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def invisibleEdge(self, index:int, /) -> bool:
        pass
    def setCoordinate(self, index:int, point:PyGe.Point3d, /) -> None:
        pass
    def setCoordinates(self, p1:PyGe.Point3d, p2:PyGe.Point3d, p3:PyGe.Point3d, p4:PyGe.Point3d, /) -> None:
        pass
    def setInvisibleEdge(self, index:int, flag:bool, /) -> None:
        pass
class Acad3DPolyline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def appendVertex(self, vertex:PyGe.Point3d, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> Acad3DPolyline:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def explode(self, /) -> list:
        pass
    def getType(self, /) -> Ac3DPolylineType:
        pass
    def isClosed(self, /) -> bool:
        pass
    def length(self, /) -> float:
        pass
    def setClosed(self, val:bool, /) -> None:
        pass
    def setCoordinate(self, index:int, point:PyGe.Point3d, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setType(self, val:PyAx.Ac3DPolylineType, /) -> None:
        pass
class Acad3DSolid(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def boolean(self, val:PyAx.AcBooleanType, solid:PyAx.Acad3DSolid, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> Acad3DSolid:
        pass
    def centroid(self, /) -> PyGe.Point3d:
        pass
    def checkInterference(self, solid:PyAx.Acad3DSolid, createInterferenceSolid:bool, /) -> tuple:
        pass
    @staticmethod
    def className() -> str:
        pass
    def history(self, /) -> bool:
        pass
    def momentOfInertia(self, /) -> PyGe.Point3d:
        pass
    def position(self, /) -> PyGe.Point3d:
        pass
    def principalDirections(self, /) -> tuple:
        pass
    def principalMoments(self, /) -> PyGe.Point3d:
        pass
    def productOfInertia(self, /) -> PyGe.Point3d:
        pass
    def radiiOfGyration(self, /) -> PyGe.Point3d:
        pass
    def sectionSolid(self, p1:PyGe.GePoint3d, p2:PyGe.GePoint3d, p3:PyGe.GePoint3d, /) -> AcadRegion:
        pass
    def setHistory(self, val:bool, /) -> None:
        pass
    def setPosition(self, val:PyGe.GePoint3d, /) -> None:
        pass
    def setShowHistory(self, val:bool, /) -> None:
        pass
    def showHistory(self, /) -> bool:
        pass
    def sliceSolid(self, p1:PyGe.GePoint3d, p2:PyGe.GePoint3d, p3:PyGe.GePoint3d, negative:bool, /) -> Acad3DSolid:
        pass
    def solidType(self, /) -> str:
        pass
    def volume(self, /) -> float:
        pass
class AcadAcCmColor:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, r: int, g: int, b: int, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def blue(self, /) -> int:
        pass
    def bookName(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def colorIndex(self, /) -> AcColor:
        pass
    def colorMethod(self, /) -> AcColorMethod:
        pass
    def colorName(self, /) -> str:
        pass
    def entityColor(self, /) -> int:
        pass
    def green(self, /) -> int:
        pass
    def red(self, /) -> int:
        pass
    def setColorBookColor(self, colorName:str, bookName:str, /) -> None:
        pass
    def setColorIndex(self, flags:PyAx.AcColor, /) -> None:
        pass
    def setColorMethod(self, flags:PyAx.AcColorMethod, /) -> None:
        pass
    def setEntityColor(self, val:int, /) -> None:
        pass
    def setNames(self, colorName:str, bookName:str, /) -> None:
        pass
    def setRGB(self, red:int, green:int, blue:int, /) -> None:
        pass
class AcadApplication:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def acadState(self, /) -> AcadState:
        pass
    def activeDocument(self, /) -> AcadDocument:
        pass
    def caption(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def documents(self, /) -> AcadDocuments:
        pass
    def eval(self, sval: str, /) -> None:
        pass
    def fullName(self, /) -> str:
        pass
    def getHWND(self, /) -> int:
        pass
    def getHeight(self, /) -> int:
        pass
    def getName(self, /) -> str:
        pass
    def getPath(self, /) -> str:
        pass
    def getWidth(self, /) -> int:
        pass
    def getWindowLeft(self, /) -> int:
        pass
    def getWindowState(self, /) -> AcWindowState:
        pass
    def getWindowTop(self, /) -> int:
        pass
    def isVisible(self, /) -> bool:
        pass
    def listArx(self, /) -> list:
        pass
    def loadArx(self, arx: str, /) -> None:
        pass
    def loadDVB(self, dvb: str, /) -> None:
        pass
    def localeId(self, /) -> int:
        pass
    def menuBar(self, /) -> AcadMenuBar:
        pass
    def menuGroups(self, /) -> AcadMenuGroups:
        pass
    def preferences(self, /) -> AcadPreferences:
        pass
    def quit(self, /) -> None:
        pass
    def runMacro(self, macro: str, /) -> None:
        pass
    def setActiveDocument(self, doc : PyAx.AcadDocument, /) -> None:
        pass
    def setCaption(self, caption:str, /) -> None:
        pass
    def setHeight(self, height: int, /) -> None:
        pass
    def setVisible(self, visible: bool, /) -> None:
        pass
    def setWidth(self, width: int, /) -> None:
        pass
    def setWindowLeft(self, left: int, /) -> None:
        pass
    def setWindowState(self, state: PyAx.AcWindowState, /) -> None:
        pass
    def setWindowTop(self, top: int, /) -> None:
        pass
    def unloadArx(self, arx: str, /) -> None:
        pass
    def unloadDVB(self, dvb: str, /) -> None:
        pass
    def update(self, /) -> None:
        pass
    def version(self, /) -> str:
        pass
    def zoomAll(self, /) -> None:
        pass
    def zoomCenter(self, pt: PyGe.Point3d, magnify: float, /) -> None:
        pass
    def zoomExtents(self, /) -> None:
        pass
    def zoomPickWindow(self, /) -> None:
        pass
    def zoomPrevious(self, /) -> None:
        pass
    def zoomScaled(self, magnify: float, scaletype: PyAx.AcZoomScaleType, /) -> None:
        pass
class AcadArc(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def arcLength(self, /) -> float:
        pass
    def area(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadArc:
        pass
    def center(self, /) -> PyGe.Point3d:
        pass
    @staticmethod
    def className() -> str:
        pass
    def endAngle(self, /) -> float:
        pass
    def endPoint(self, /) -> PyGe.Point3d:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def radius(self, /) -> float:
        pass
    def setCenter(self, val:PyGe.Point3d, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRadius(self, val:float, /) -> None:
        pass
    def setStartAngle(self, val:float, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def startAngle(self, /) -> float:
        pass
    def startPoint(self, /) -> PyGe.Point3d:
        pass
    def thickness(self, /) -> float:
        pass
    def totalAngle(self, /) -> float:
        pass
class AcadAttribute(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def alignment(self, /) -> AcAlignment:
        pass
    def backward(self, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadAttribute:
        pass
    @staticmethod
    def className() -> str:
        pass
    def constant(self, /) -> bool:
        pass
    def fieldLength(self, /) -> int:
        pass
    def height(self, /) -> float:
        pass
    def horizontalAlignment(self, /) -> AcHorizontalAlignment:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def invisible(self, /) -> bool:
        pass
    def isMTextAttribute(self, /) -> bool:
        pass
    def lockPosition(self, /) -> bool:
        pass
    def mode(self, /) -> int:
        pass
    def mtextAttributeContent(self, /) -> str:
        pass
    def mtextBoundaryWidth(self, /) -> float:
        pass
    def mtextDrawingDirection(self, /) -> AcDrawingDirection:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def obliqueAngle(self, /) -> float:
        pass
    def preset(self, /) -> bool:
        pass
    def promptString(self, /) -> str:
        pass
    def rotation(self, /) -> float:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setAlignment(self, val:PyAx.AcAlignment, /) -> None:
        pass
    def setBackward(self, val:bool, /) -> None:
        pass
    def setConstant(self, val:bool, /) -> None:
        pass
    def setFieldLength(self, val:int, /) -> None:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setHorizontalAlignment(self, val:PyAx.AcHorizontalAlignment, /) -> None:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setInvisible(self, val:bool, /) -> None:
        pass
    def setIsMTextAttribute(self, val:bool, /) -> None:
        pass
    def setLockPosition(self, val:bool, /) -> None:
        pass
    def setMTextAttributeContent(self, val:str, /) -> None:
        pass
    def setMTextBoundaryWidth(self, val:float, /) -> None:
        pass
    def setMTextDrawingDirection(self, val:PyAx.AcDrawingDirection, /) -> None:
        pass
    def setMode(self, val:int, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setPreset(self, val:bool, /) -> None:
        pass
    def setPromptString(self, val:str, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTagString(self, val:str, /) -> None:
        pass
    def setTextAlignmentPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setTextGenerationFlag(self, val:int, /) -> None:
        pass
    def setTextString(self, val:str, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def setUpsideDown(self, val:bool, /) -> None:
        pass
    def setVerify(self, val:bool, /) -> None:
        pass
    def setVerticalAlignment(self, val:PyAx.AcVerticalAlignment, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def tagString(self, /) -> str:
        pass
    def textAlignmentPoint(self, val:float, /) -> PyGe.Point3d:
        pass
    def textGenerationFlag(self, /) -> int:
        pass
    def textString(self, /) -> str:
        pass
    def thickness(self, /) -> float:
        pass
    def updateMTextAttribute(self, /) -> None:
        pass
    def upsideDown(self, /) -> bool:
        pass
    def verify(self, /) -> bool:
        pass
    def verticalAlignment(self, /) -> AcVerticalAlignment:
        pass
class AcadAttributeReference(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def alignment(self, /) -> AcAlignment:
        pass
    def backward(self, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadAttributeReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def constant(self, /) -> bool:
        pass
    def fieldLength(self, /) -> int:
        pass
    def height(self, /) -> float:
        pass
    def horizontalAlignment(self, /) -> AcHorizontalAlignment:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def invisible(self, /) -> bool:
        pass
    def isMTextAttribute(self, /) -> bool:
        pass
    def lockPosition(self, /) -> bool:
        pass
    def mtextAttributeContent(self, /) -> str:
        pass
    def mtextBoundaryWidth(self, /) -> float:
        pass
    def mtextDrawingDirection(self, /) -> AcDrawingDirection:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def obliqueAngle(self, /) -> float:
        pass
    def rotation(self, /) -> float:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setAlignment(self, val:PyAx.AcAlignment, /) -> None:
        pass
    def setBackward(self, val:bool, /) -> None:
        pass
    def setFieldLength(self, val:int, /) -> None:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setHorizontalAlignment(self, val:PyAx.AcHorizontalAlignment, /) -> None:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setInvisible(self, val:bool, /) -> None:
        pass
    def setIsMTextAttribute(self, val:bool, /) -> None:
        pass
    def setMTextAttributeContent(self, val:str, /) -> None:
        pass
    def setMTextBoundaryWidth(self, val:float, /) -> None:
        pass
    def setMTextDrawingDirection(self, val:PyAx.AcDrawingDirection, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTagString(self, val:str, /) -> None:
        pass
    def setTextAlignmentPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setTextGenerationFlag(self, val:int, /) -> None:
        pass
    def setTextString(self, val:str, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def setUpsideDown(self, val:bool, /) -> None:
        pass
    def setVerticalAlignment(self, val:PyAx.AcVerticalAlignment, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def tagString(self, /) -> str:
        pass
    def textAlignmentPoint(self, val:float, /) -> PyGe.Point3d:
        pass
    def textGenerationFlag(self, /) -> int:
        pass
    def textString(self, /) -> str:
        pass
    def thickness(self, /) -> float:
        pass
    def updateMTextAttribute(self, /) -> None:
        pass
    def upsideDown(self, /) -> bool:
        pass
    def verticalAlignment(self, /) -> AcVerticalAlignment:
        pass
class AcadBlock(PyAx.AcadObject):
    def __getitem__(self, index: int, /) -> AcadEntity:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __iter__(self, /) -> object:
        pass
    def __reduce__(self, /):
        pass
    def add3DFace(self, p1:PyGe.Point3d, p2:PyGe.Point3d, p3:PyGe.Point3d, p4:PyGe.Point3d, /) -> Acad3DFace:
        pass
    def add3DMesh(self, M:int, N:int, points:Iterable[PyGe.Point3d], /) -> AcadPolygonMesh:
        pass
    def add3DPoly(self, points:Iterable[PyGe.Point3d], /) -> Acad3DPolyline:
        pass
    def addArc(self, canter:PyGe.Point3d, radius:float, startAngle:float, endAngle:float, /) -> AcadArc:
        pass
    def addAttribute(self, height:float, mode:PyAx.AcAttributeMode, prompt:str, insertionPoint:PyGe.Point3d, tag:str, value:str, /) -> AcadAttribute:
        pass
    def addBox(self, origin:PyGe.Point3d, length:float, width:float, height:float, /) -> Acad3DSolid:
        pass
    def addCircle(self, canter:PyGe.Point3d, radius:float, /) -> AcadCircle:
        pass
    def addCone(self, canter:PyGe.Point3d, baseRadius:float, height:float, /) -> Acad3DSolid:
        pass
    def addCustomObject(self, name:str, /) -> AcadObject:
        pass
    def addCylinder(self, canter:PyGe.Point3d, radius:float, height:float, /) -> Acad3DSolid:
        pass
    def addDim3PointAngular(self, angleVertex:PyGe.Point3d, firstEndPoint:PyGe.Point3d, secondEndPoint:PyGe.Point3d, textPosition:PyGe.Point3d, /) -> AcadDim3PointAngular:
        pass
    def addDimAligned(self, extLine1Point:PyGe.Point3d, extLine2Point:PyGe.Point3d, textPosition:PyGe.Point3d, /) -> AcadDimAligned:
        pass
    def addDimAngular(self, angleVertex:PyGe.Point3d, firstEndPoint:PyGe.Point3d, secondEndPoint:PyGe.Point3d, textPosition:PyGe.Point3d, /) -> AcadDimAngular:
        pass
    def addDimArc(self, arcCenter:PyGe.Point3d, firstEndPoint:PyGe.Point3d, secondEndPoint:PyGe.Point3d, arcPoint:PyGe.Point3d, /) -> AcadDimArcLength:
        pass
    def addDimDiametric(self, chordPoint:PyGe.Point3d, farChordPoint:PyGe.Point3d, leaderLength:float, /) -> AcadDimDiametric:
        pass
    def addDimOrdinate(self, definitionPoint:PyGe.Point3d, leaderEndPoint:PyGe.Point3d, UseXAxis:int, /) -> AcadDimOrdinate:
        pass
    def addDimRadial(self, center:PyGe.Point3d, chordPoint:PyGe.Point3d, leaderLength:float, /) -> AcadDimRadial:
        pass
    def addDimRadialLarge(self, center:PyGe.Point3d, chordPoint:PyGe.Point3d, overrideCenter:PyGe.Point3d, jogPoint:PyGe.Point3d, jogAngle:float, /) -> AcadDimRadialLarge:
        pass
    def addDimRotated(self, extLine1Point:PyGe.Point3d, extLine2Point:PyGe.Point3d, dimLineLocation:PyGe.Point3d, rotationAngle:float, /) -> AcadDimRotated:
        pass
    def addEllipse(self, center:PyGe.Point3d, majorAxis:PyGe.Vector3d, radiusRatio:float, /) -> AcadEllipse:
        pass
    def addEllipticalCone(self, center:PyGe.Point3d, majorRadius:float, minorRadius:float, height:float, /) -> Acad3DSolid:
        pass
    def addEllipticalCylinder(self, center:PyGe.Point3d, majorRadius:float, minorRadius:float, height:float, /) -> Acad3DSolid:
        pass
    def addExtrudedSolid(self, region:PyAx.AcadRegion, height:float, taperAngle:float, /) -> Acad3DSolid:
        pass
    def addExtrudedSolidAlongPath(self, region:PyAx.AcadRegion, path:PyAx.AcadEntity, /) -> Acad3DSolid:
        pass
    def addHatch(self, patternType:int, patternName:str, associativity:bool, ht:PyAx.AcHatchObjectType, /) -> AcadHatch:
        pass
    def addLeader(self, points:Iterable[PyGe.Point3d], annotation:PyAx.AcadEntity, leaderType:PyAx.AcLeaderType, /) -> AcadLeader:
        pass
    def addLightWeightPolyline(self, points:Iterable[PyGe.Point2d], /) -> AcadLWPolyline:
        pass
    def addLine(self, startPoint:PyGe.Point3d, endPoint:PyGe.Point3d, /) -> AcadLine:
        pass
    def addMInsertBlock(self, point:PyGe.Point3d, name:str, rotation:float, numRows:int, numCols:int, rowSpacing:int, rolumnSpacing:int, /) -> AcadMInsertBlock:
        pass
    def addMLeader(self, points:Iterable[PyGe.Point3d], /) -> AcadMLeader:
        pass
    def addMLine(self, points:Iterable[PyGe.Point3d], /) -> AcadMLine:
        pass
    def addMText(self, insertionPoint:PyGe.Point3d, width:float, textVal:str, /) -> AcadMText:
        pass
    def addPoint(self, point:PyGe.Point3d, /) -> AcadPoint:
        pass
    def addPolyfaceMesh(self, points:Iterable[PyGe.Point3d], faces:Iterable[int], /) -> AcadPolyfaceMesh:
        pass
    def addPolyline(self, points:Iterable[PyGe.Point3d], /) -> AcadPolyline:
        pass
    def addRaster(self, imageFileName:str, insertionPoint:PyGe.Point3d, scaleFactor:float, rotationAngle:float, /) -> AcadRasterImage:
        pass
    def addRay(self, p1:PyGe.Point3d, p2:PyGe.Point3d, /) -> AcadRay:
        pass
    def addRegion(self, curves:PyAx.AcadEntity, /) -> list:
        pass
    def addRevolvedSolid(self, region:PyAx.AcadRegion, axisPoint:PyGe.Point3d, axisDir:PyGe.Vector3d, angle:float, /) -> Acad3DSolid:
        pass
    def addSection(self, fromPoint:PyGe.Point3d, toPoint:PyGe.Point3d, planeVector:PyGe.Vector3d, /) -> AcadSection:
        pass
    def addShape(self, name:str, insertionPoint:PyGe.Point3d, scaleFactor:float, rotationAngle:float, /) -> AcadShape:
        pass
    def addSolid(self, p1:PyGe.Point3d, p2:PyGe.Point3d, p3:PyGe.Point3d, p4:PyGe.Point3d, /) -> AcadSolid:
        pass
    def addSphere(self, center:PyGe.Point3d, radius:float, /) -> Acad3DSolid:
        pass
    def addSpline(self, points:Iterable[PyGe.Point3d], startTangent:PyGe.Vector3d, endTangent:PyGe.Vector3d, /) -> AcadSpline:
        pass
    def addTable(self, insertionPoint:PyGe.Point3d, numRows:int, numColumns:int, rowHeight:float, colWidth:float, /) -> AcadTable:
        pass
    def addText(self, textValue:str, insertionPoint:PyGe.Point3d, height:float, /) -> AcadText:
        pass
    def addTolerance(self, textValue:str, insertionPoint:PyGe.Point3d, direction:PyGe.Vector3d, /) -> AcadTolerance:
        pass
    def addTorus(self, center:PyGe.Point3d, torusRadius:float, tubeRadius:float, /) -> Acad3DSolid:
        pass
    def addWedge(self, center:PyGe.Point3d, length:float, width:float, height:float, /) -> Acad3DSolid:
        pass
    def addXline(self, p1:PyGe.Point3d, p2:PyGe.Point3d, /) -> AcadXline:
        pass
    def attachExternalReference(self, path:str, name:str, insertionPoint:PyGe.Point3d, scale:PyGe.Scale3d, rotation:float, bOverlay:bool, /) -> AcadExternalReference:
        pass
    def bind(self, bPrefixName:bool, /) -> None:
        pass
    def blockScaling(self, /) -> AcBlockScaling:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadBlock:
        pass
    @staticmethod
    def className() -> str:
        pass
    def comments(self, /) -> str:
        pass
    def count(self, /) -> int:
        pass
    def detach(self, /) -> None:
        pass
    def entities(self, /) -> list:
        pass
    def insertBlock(self, insertionPoint:PyGe.Point3d, name:str, scale:PyGe.Scale3d, rotation:float, /) -> AcadBlockReference:
        pass
    def isDynamicBlock(self, /) -> bool:
        pass
    def isExplodable(self, /) -> bool:
        pass
    def isLayout(self, /) -> bool:
        pass
    def isXRef(self, /) -> bool:
        pass
    def item(index: int, /) -> AcadEntity:
        pass
    def layout(self, /) -> AcadLayout:
        pass
    def name(self, /) -> str:
        pass
    def origin(self, /) -> PyGe.Point3d:
        pass
    def path(self, /) -> str:
        pass
    def reload(self, /) -> None:
        pass
    def setBlockScaling(self, blockScaling:PyAx.AcBlockScaling, /) -> None:
        pass
    def setComments(self, comments:str, /) -> None:
        pass
    def setExplodable(self, explodable:bool, /) -> None:
        pass
    def setName(self, name:str, /) -> None:
        pass
    def setOrigin(self, origin:PyGe.Point3d, /) -> None:
        pass
    def setPath(self, path:str, /) -> None:
        pass
    def setUnits(self, units:PyAx.AcInsertUnits, /) -> None:
        pass
    def units(self, /) -> AcInsertUnits:
        pass
    def unload(self, /) -> None:
        pass
    def xrefDatabase(self, /) -> AcadDatabase:
        pass
class AcadBlockReference(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def attributes(self, /) -> list:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadBlockReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def constantAttributes(self, /) -> list:
        pass
    def convertToAnonymousBlock(self, /) -> None:
        pass
    def convertToStaticBlock(self, newBlockName:str, /) -> None:
        pass
    def dynamicBlockProperties(self, /) -> list:
        pass
    def effectiveName(self, /) -> str:
        pass
    def explode(self, /) -> list:
        pass
    def hasAttributes(self, /) -> bool:
        pass
    def insUnits(self, /) -> str:
        pass
    def insUnitsFactor(self, /) -> float:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def isDynamicBlock(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def resetBlock(self, /) -> None:
        pass
    def rotation(self, /) -> float:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setName(self, val:str, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setXEffectiveScaleFactor(self, val:float, /) -> None:
        pass
    def setXScaleFactor(self, val:float, /) -> None:
        pass
    def setYEffectiveScaleFactor(self, val:float, /) -> None:
        pass
    def setYScaleFactor(self, val:float, /) -> None:
        pass
    def setZEffectiveScaleFactor(self, val:float, /) -> None:
        pass
    def setZScaleFactor(self, val:float, /) -> None:
        pass
    def xEffectiveScaleFactor(self, /) -> float:
        pass
    def xScaleFactor(self, /) -> float:
        pass
    def yEffectiveScaleFactor(self, /) -> float:
        pass
    def yScaleFactor(self, /) -> float:
        pass
    def zEffectiveScaleFactor(self, /) -> float:
        pass
    def zScaleFactor(self, /) -> float:
        pass
class AcadBlocks(PyAx.AcadObject):
    def __getitem__(self, index: int, /) -> AcadBlock:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __iter__(self, /) -> object:
        pass
    def __reduce__(self, /):
        pass
    def add(self, insertionPoint:PyGe.Point3d, name:str, /) -> AcadBlock:
        pass
    def blocks(self, /) -> list:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadBlocks:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(index: int, /) -> AcadBlock:
        pass
class AcadCircle(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def area(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadCircle:
        pass
    def center(self, /) -> PyGe.Point3d:
        pass
    def circumference(self, /) -> float:
        pass
    @staticmethod
    def className() -> str:
        pass
    def diameter(self, /) -> float:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, /) -> list:
        pass
    def radius(self, /) -> float:
        pass
    def setArea(self, val:float, /) -> None:
        pass
    def setCenter(self, val:PyGe.GePoint3d, /) -> None:
        pass
    def setCircumference(self, val:float, /) -> None:
        pass
    def setDiameter(self, val:float, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRadius(self, val:float, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
class AcadDatabase:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def blocks(self, /) -> AcadBlocks:
        pass
    @staticmethod
    def className() -> str:
        pass
    def copyObjects(self, objs:list[PyAx.AcadObject], owner:PyAx.AcadObject, /) -> list:
        pass
    def dictionaries(self, /) -> AcadDictionaries:
        pass
    def dimStyles(self, /) -> AcadDimStyles:
        pass
    def elevationModelSpace(self, /) -> float:
        pass
    def elevationPaperSpace(self, /) -> float:
        pass
    def groups(self, /) -> AcadGroups:
        pass
    def handleToObject(self, val:str, /) -> AcadObject:
        pass
    def layers(self, /) -> AcadLayers:
        pass
    def layouts(self, /) -> AcadLayouts:
        pass
    def limits(self, /) -> tuple:
        pass
    def lineTypes(self, /) -> AcadLineTypes:
        pass
    def materials(self, /) -> AcadMaterials:
        pass
    def modelSpace(self, /) -> ModelSpace:
        pass
    def objectIdToObject(self, val:PyDb.ObjectId, /) -> AcadObject:
        pass
    def paperSpace(self, /) -> PaperSpace:
        pass
    def plotConfigurations(self, /) -> AcadPlotConfigurations:
        pass
    def preferences(self, /) -> AcadDatabasePreferences:
        pass
    def registeredApplications(self, /) -> AcadRegisteredApplications:
        pass
    def sectionManager(self, /) -> AcadSectionManager:
        pass
    def setElevationModelSpace(self, elev:float, /) -> None:
        pass
    def setElevationPaperSpace(self, elev:float, /) -> None:
        pass
    def setLimits(self, minmax:tuple[PyGe.Point2d,PyGe.Point2d], /) -> None:
        pass
    def summaryInfo(self, /) -> AcadSummaryInfo:
        pass
    def textStyles(self, /) -> AcadTextStyles:
        pass
    def userCoordinateSystems(self, /) -> AcadUCSs:
        pass
    def viewports(self, /) -> AcadViewports:
        pass
    def views(self, /) -> AcadViews:
        pass
class AcadDatabasePreferences:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def allowLongSymbolNames(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def contourLinesPerSurface(self, /) -> int:
        pass
    def displaySilhouette(self, /) -> bool:
        pass
    def lineWeightDisplay(self, /) -> bool:
        pass
    def lineweight(self, /) -> AcLineWeight:
        pass
    def maxActiveViewports(self, /) -> int:
        pass
    def objectSortByPSOutput(self, /) -> bool:
        pass
    def objectSortByPlotting(self, /) -> bool:
        pass
    def objectSortByRedraws(self, /) -> bool:
        pass
    def objectSortByRegens(self, /) -> bool:
        pass
    def objectSortBySelection(self, /) -> bool:
        pass
    def objectSortBySnap(self, /) -> bool:
        pass
    def oleLaunch(self, /) -> bool:
        pass
    def renderSmoothness(self, /) -> float:
        pass
    def segmentPerPolyline(self, /) -> int:
        pass
    def setAllowLongSymbolNames(self, val:bool, /) -> None:
        pass
    def setContourLinesPerSurface(self, val:int, /) -> None:
        pass
    def setDisplaySilhouette(self, val:bool, /) -> None:
        pass
    def setLineWeightDisplay(self, val:bool, /) -> None:
        pass
    def setLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setMaxActiveViewports(self, val:int, /) -> None:
        pass
    def setOLELaunch(self, val:bool, /) -> None:
        pass
    def setObjectSortByPSOutput(self, val:bool, /) -> None:
        pass
    def setObjectSortByPlotting(self, val:bool, /) -> None:
        pass
    def setObjectSortByRedraws(self, val:bool, /) -> None:
        pass
    def setObjectSortByRegens(self, val:bool, /) -> None:
        pass
    def setObjectSortBySelection(self, val:bool, /) -> None:
        pass
    def setObjectSortBySnap(self, val:bool, /) -> None:
        pass
    def setRenderSmoothness(self, val:float, /) -> None:
        pass
    def setSegmentPerPolyline(self, val:int, /) -> None:
        pass
    def setSolidFill(self, val:bool, /) -> None:
        pass
    def setTextFrameDisplay(self, val:bool, /) -> None:
        pass
    def setXRefEdit(self, val:bool, /) -> None:
        pass
    def setXRefLayerVisibility(self, val:bool, /) -> None:
        pass
    def solidFill(self, /) -> bool:
        pass
    def textFrameDisplay(self, /) -> bool:
        pass
    def xrefEdit(self, /) -> bool:
        pass
    def xrefLayerVisibility(self, /) -> bool:
        pass
class AcadDictionaries(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDictionaries:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDictionary(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDictionary:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDim3PointAngular(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDim3PointAngular:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimAligned(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimAligned:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimAngular(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimAngular:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimArcLength(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimArcLength:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimDiametric(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimDiametric:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimOrdinate(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimOrdinate:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimRadial(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimRadial:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimRadialLarge(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimRadialLarge:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimRotated(PyAx.AcadDimension):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimRotated:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimStyle(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimStyles(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimStyles:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDimension(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadDimension:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDocument(PyAx.AcadDatabase):
    def HWND(self, /) -> int:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def activate(self, /) -> None:
        pass
    def activeDimStyle(self, /) -> AcadDimStyle:
        pass
    def activeLayer(self, /) -> AcadLayer:
        pass
    def activeLayout(self, /) -> AcadLayout:
        pass
    def activeLinetype(self, /) -> AcadLineType:
        pass
    def activeMaterial(self, /) -> AcadMaterial:
        pass
    def activePViewport(self, /) -> AcadPViewport:
        pass
    def activeSelectionSet(self, /) -> AcadSelectionSet:
        pass
    def activeSpace(self, /) -> AcActiveSpace:
        pass
    def activeTextStyle(self, /) -> AcadTextStyle:
        pass
    def activeUCS(self, /) -> AcadUCS:
        pass
    def activeViewport(self, /) -> AcadViewport:
        pass
    def auditInfo(self, val:bool, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    def close(self, saveChanges:bool=False, fileName:str=None, /) -> None:
        pass
    def database(self, /) -> AcadDatabase:
        pass
    def endUndoMark(self, /) -> None:
        pass
    def fullName(self, /) -> str:
        pass
    def getVariable(self, varName:str, /) -> object:
        pass
    def height(self, /) -> int:
        pass
    def importFile(self, fullPath:str, insertionPoint:PyGe.Point3d, scaleFactor:float, /) -> AcadBlockReference:
        pass
    def isActive(self, /) -> bool:
        pass
    def isReadOnly(self, /) -> bool:
        pass
    def isSaved(self, /) -> bool:
        pass
    def loadShapeFile(self, name:str, /) -> None:
        pass
    def mSpace(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def objectSnapMode(self, /) -> bool:
        pass
    def open(self, fullPath:str, /) -> AcadDocument:
        pass
    def path(self, /) -> str:
        pass
    def pickfirstSelectionSet(self, /) -> AcadSelectionSet:
        pass
    def plot(self, /) -> AcadPlot:
        pass
    def postCommand(self, cmd:str, /) -> None:
        pass
    def purgeAll(self, /) -> None:
        pass
    def regen(self, rt:PyAx.AcRegenType, /) -> None:
        pass
    def selectionSets(self, /) -> AcadSelectionSets:
        pass
    def sendCommand(self, cmd:str, /) -> None:
        pass
    def setActiveDimStyle(self, val:PyAx.AcadDimStyle, /) -> None:
        pass
    def setActiveLayer(self, val:PyAx.AcadLayer, /) -> None:
        pass
    def setActiveLayout(self, val:PyAx.AcadLayout, /) -> None:
        pass
    def setActiveLinetype(self, val:PyAx.AcadLineType, /) -> None:
        pass
    def setActiveMaterial(self, val:PyAx.AcadMaterial, /) -> None:
        pass
    def setActivePViewport(self, val:PyAx.AcadPViewport, /) -> None:
        pass
    def setActiveSpace(self, val:PyAx.AcActiveSpace, /) -> None:
        pass
    def setActiveTextStyle(self, val:PyAx.AcadTextStyle, /) -> None:
        pass
    def setActiveUCS(self, val:PyAx.AcadUCS, /) -> None:
        pass
    def setActiveViewport(self, val:PyAx.AcadViewport, /) -> None:
        pass
    def setHeight(self, val:int, /) -> None:
        pass
    def setMSpace(self, val:bool, /) -> None:
        pass
    def setObjectSnapMode(self, val:bool, /) -> None:
        pass
    def setVariable(self, varName:str, obj:Any, /) -> None:
        pass
    def setWidth(self, val:int, /) -> None:
        pass
    def setWindowState(self, val:PyAx.AcWindowState, /) -> None:
        pass
    def startUndoMark(self, /) -> None:
        pass
    def utility(self, /) -> AcadUtility:
        pass
    def width(self, /) -> int:
        pass
    def windowState(self, /) -> AcWindowState:
        pass
    def windowTitle(self, /) -> str:
        pass
class AcadDocuments:
    def __getitem__(self, index: int, /) -> AcadDocument:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, template: str = None, /) -> AcadDocument:
        pass
    @staticmethod
    def className() -> str:
        pass
    def close(self, /) -> None:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index: int, /) -> AcadDocument:
        pass
    def open(self, path: str, readOnly: bool, /) -> AcadDocument:
        pass
class AcadDynamicBlockReferenceProperty:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def allowedValues(self, /) -> list:
        pass
    @staticmethod
    def className() -> str:
        pass
    def description(self, /) -> str:
        pass
    def isReadOnly(self, /) -> bool:
        pass
    def isShown(self, /) -> bool:
        pass
    def propertyName(self, /) -> str:
        pass
    def setValue(self, val:PyDb.EvalVariant, /) -> None:
        pass
    def unitsType(self, /) -> AcDynamicBlockReferencePropertyUnitsType:
        pass
    def value(self, /) -> PyDb.EvalVariant:
        pass
class AcadEllipse(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def area(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadEllipse:
        pass
    def center(self, /) -> PyGe.Point3d:
        pass
    @staticmethod
    def className() -> str:
        pass
    def endAngle(self, /) -> float:
        pass
    def endParameter(self, /) -> float:
        pass
    def endPoint(self, /) -> PyGe.Point3d:
        pass
    def majorAxis(self, /) -> PyGe.Vector3d:
        pass
    def majorRadius(self, /) -> float:
        pass
    def minorAxis(self, /) -> PyGe.Vector3d:
        pass
    def minorRadius(self, /) -> float:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def radiusRatio(self, /) -> float:
        pass
    def setCenter(self, val:PyGe.Point3d, /) -> None:
        pass
    def setEndAngle(self, val:float, /) -> None:
        pass
    def setEndParameter(self, val:float, /) -> None:
        pass
    def setMajorAxis(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setMajorRadius(self, val:float, /) -> None:
        pass
    def setMinorRadius(self, val:float, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRadiusRatio(self, val:float, /) -> None:
        pass
    def setStartAngle(self, val:float, /) -> None:
        pass
    def setStartParameter(self, val:float, /) -> None:
        pass
    def startAngle(self, /) -> float:
        pass
    def startParameter(self, /) -> float:
        pass
    def startPoint(self, /) -> PyGe.Point3d:
        pass
class AcadEntity(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def arrayPolar(self, numberOfObjects:int, angleToFill:float, centerPoint:PyGe.Point3d, /) -> list:
        pass
    def arrayRectangular(self, nRows:int, nColumns:int, nLevels:int, rowDist:float, colDist:float, levelDist:float, /) -> list:
        pass
    def boundingBox(self, /) -> tuple:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadEntity:
        pass
    @staticmethod
    def className() -> str:
        pass
    def color(self, /) -> AcColor:
        pass
    def copy(self, /) -> AcadEntity:
        pass
    def entityName(self, /) -> str:
        pass
    def entityTransparency(self, /) -> str:
        pass
    def entityType(self, /) -> int:
        pass
    def highlight(self, bHighlight:bool, /) -> None:
        pass
    def hyperlinks(self, /) -> AcadHyperlinks:
        pass
    def intersectWith(self, intersectObject:PyAx.AcadEntity, option:PyAx.AcExtendOption, /) -> list:
        pass
    def isVisible(self, /) -> bool:
        pass
    def layer(self, /) -> str:
        pass
    def linetype(self, /) -> str:
        pass
    def linetypeScale(self, /) -> float:
        pass
    def lineweight(self, /) -> AcLineWeight:
        pass
    def material(self, /) -> str:
        pass
    def mirror(self, point1:PyGe.Point3d, point2:PyGe.Point3d, /) -> AcadEntity:
        pass
    def mirror3D(self, point1:PyGe.Point3d, point2:PyGe.Point3d, point3:PyGe.Point3d, /) -> AcadEntity:
        pass
    def move(self, fromPoint:PyGe.Point3d, toPoint:PyGe.Point3d, /) -> None:
        pass
    def plotStyleName(self, /) -> str:
        pass
    def rotate(self, basePoint:PyGe.Point3d, rotationAngle:float, /) -> None:
        pass
    def rotate3D(self, point1:PyGe.Point3d, point2:PyGe.Point3d, rotationAngle:float, /) -> None:
        pass
    def scaleEntity(self, basePoint:PyGe.Point3d, scaleFactor:float, /) -> None:
        pass
    def setColor(self, color:PyAx.AcColor, /) -> None:
        pass
    def setEntityTransparency(self, entityTransparency:str, /) -> None:
        pass
    def setLayer(self, layer:str, /) -> None:
        pass
    def setLinetype(self, linetype:str, /) -> None:
        pass
    def setLinetypeScale(self, linetypeScale:float, /) -> None:
        pass
    def setLineweight(self, lineweight:PyAx.AcLineWeight, /) -> None:
        pass
    def setMaterial(self, material:str, /) -> None:
        pass
    def setPlotStyleName(self, plotStyleName:str, /) -> None:
        pass
    def setTrueColor(self, trueColor: PyAx.AcadAcCmColor, /) -> None:
        pass
    def setVisible(self, bVisible:bool, /) -> None:
        pass
    def transformBy(self, xform: PyGe.Matrix3d, /) -> None:
        pass
    def trueColor(self, /) -> AcadAcCmColor:
        pass
    def update(self, /) -> None:
        pass
class AcadExternalReference(PyAx.AcadBlockReference):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadExternalReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def layerPropertyOverrides(self, val:str, /) -> bool:
        pass
    def path(self, /) -> str:
        pass
    def setPath(self, val:str, /) -> None:
        pass
class AcadGroup(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadGroup:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadGroups(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadGroups:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadHatch(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def appendInnerLoop(self, objects:Iterable[PyAx.AcadEntity], /) -> None:
        pass
    def appendOuterLoop(self, objects:Iterable[PyAx.AcadEntity], /) -> None:
        pass
    def area(self, /) -> float:
        pass
    def associativeHatch(self, /) -> bool:
        pass
    def backgroundColor(self, /) -> AcadAcCmColor:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadHatch:
        pass
    @staticmethod
    def className() -> str:
        pass
    def elevation(self, /) -> float:
        pass
    def evaluate(self, /) -> None:
        pass
    def gradientAngle(self, /) -> float:
        pass
    def gradientCentered(self, /) -> bool:
        pass
    def gradientColor1(self, /) -> AcadAcCmColor:
        pass
    def gradientColor2(self, /) -> AcadAcCmColor:
        pass
    def gradientName(self, /) -> str:
        pass
    def hatchObjectType(self, /) -> AcHatchObjectType:
        pass
    def hatchStyle(self, /) -> AcHatchStyle:
        pass
    def insertLoopAt(self, index:int, loopType:PyAx.AcLoopType, objects:Iterable[PyAx.AcadEntity], /) -> None:
        pass
    def isoPenWidth(self, /) -> AcISOPenWidth:
        pass
    def loopAt(self, index:int, /) -> list:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def numberOfLoops(self, /) -> int:
        pass
    def origin(self, /) -> PyGe.Point3d:
        pass
    def patternAngle(self, /) -> float:
        pass
    def patternDouble(self, /) -> bool:
        pass
    def patternName(self, /) -> str:
        pass
    def patternScale(self, /) -> float:
        pass
    def patternSpace(self, /) -> float:
        pass
    def patternType(self, /) -> AcPatternType:
        pass
    def setAssociativeHatch(self, val:bool, /) -> None:
        pass
    def setBackgroundColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setElevation(self, val:float, /) -> None:
        pass
    def setGradientAngle(self, val:float, /) -> None:
        pass
    def setGradientCentered(self, val:float, /) -> None:
        pass
    def setGradientColor1(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setGradientColor2(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setGradientName(self, val:str, /) -> None:
        pass
    def setHatchObjectType(self, val:PyAx.AcHatchObjectType, /) -> None:
        pass
    def setHatchStyle(self, val:PyAx.AcHatchStyle, /) -> None:
        pass
    def setISOPenWidth(self, val:PyAx.AcISOPenWidth, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setOrigin(self, val:PyGe.Point3d, /) -> None:
        pass
    def setPattern(self, patternType:int, name:str, /) -> None:
        pass
    def setPatternAngle(self, val:float, /) -> None:
        pass
    def setPatternDouble(self, val:bool, /) -> None:
        pass
    def setPatternScale(self, val:float, /) -> None:
        pass
    def setPatternSpace(self, val:float, /) -> None:
        pass
class AcadHyperlink:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def setURL(self, val:str, /) -> None:
        pass
    def setURLDescription(self, val:str, /) -> None:
        pass
    def setURLNamedLocation(self, val:str, /) -> None:
        pass
    def url(self, /) -> str:
        pass
    def urlDescription(self, /) -> str:
        pass
    def urlNamedLocation(self, /) -> str:
        pass
class AcadHyperlinks:
    def __getitem__(self, name: str, description: str, namedLocation: str, /) -> AcadHyperlink:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, index: int, /) -> AcadHyperlink:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index: int, /) -> AcadHyperlink:
        pass
class AcadIdPair:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def isCloned(self, /) -> bool:
        pass
    def isOwnerXlated(self, /) -> bool:
        pass
    def isPrimary(self, /) -> bool:
        pass
    def key(self, /) -> PyDb.ObjectId:
        pass
    def value(self, /) -> PyDb.ObjectId:
        pass
class AcadLWPolyline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addVertex(self, index:int, val:PyGe.Point2d, /) -> None:
        pass
    def area(self, /) -> float:
        pass
    def bulge(self, index:int, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLWPolyline:
        pass
    @staticmethod
    def className() -> str:
        pass
    def constantWidth(self, /) -> float:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point2d:
        pass
    def coordinates(self, /) -> list:
        pass
    def elevation(self, /) -> float:
        pass
    def explode(self, /) -> list:
        pass
    def isClosed(self, /) -> bool:
        pass
    def length(self, /) -> float:
        pass
    def linetypeGeneration(self, /) -> bool:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def setBulge(self, index:int, val:float, /) -> None:
        pass
    def setClosed(self, val:bool, /) -> None:
        pass
    def setConstantWidth(self, val:float, /) -> None:
        pass
    def setCoordinate(self, index:int, val:PyGe.Point2d, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point2d], /) -> None:
        pass
    def setElevation(self, val:float, /) -> None:
        pass
    def setLinetypeGeneration(self, val:bool, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def setWidth(self, index:int, startWidth:float, endWidth:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
    def width(self, index:int, /) -> tuple:
        pass
class AcadLayer(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLayer:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadLayers(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLayers:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadLayout(PyAx.AcadPlotConfiguration):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def block(self, /) -> AcadBlock:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLayout:
        pass
    @staticmethod
    def className() -> str:
        pass
    def setTabOrder(self, val:int, /) -> None:
        pass
    def tabOrder(self, /) -> int:
        pass
class AcadLayouts(PyAx.AcadObject):
    def __getitem__(self, index: int, /) -> AcadLayout:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, name: str, /) -> AcadLayout:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLayouts:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index: int, /) -> AcadLayout:
        pass
class AcadLeader(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def annotation(self, /) -> AcadEntity:
        pass
    def arrowheadBlock(self, /) -> str:
        pass
    def arrowheadSize(self, /) -> float:
        pass
    def arrowheadType(self, /) -> AcDimArrowheadType:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLeader:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def dimensionLineColor(self, /) -> AcColor:
        pass
    def dimensionLineWeight(self, /) -> AcLineWeight:
        pass
    def evaluate(self, /) -> None:
        pass
    def leaderType(self, /) -> AcLeaderType:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setAnnotation(self, val:PyAx.AcadEntity, /) -> None:
        pass
    def setArrowheadBlock(self, val:str, /) -> None:
        pass
    def setArrowheadSize(self, val:float, /) -> None:
        pass
    def setArrowheadType(self, val:PyAx.AcDimArrowheadType, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setDimensionLineColor(self, val:PyAx.AcColor, /) -> None:
        pass
    def setDimensionLineWeight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setLeaderType(self, val:PyAx.AcLeaderType, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTextGap(self, val:float, /) -> None:
        pass
    def setVerticalTextPosition(self, val:PyAx.AcDimVerticalJustification, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def textGap(self, /) -> float:
        pass
    def verticalTextPosition(self, /) -> AcDimVerticalJustification:
        pass
class AcadLine(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def angle(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLine:
        pass
    @staticmethod
    def className() -> str:
        pass
    def delta(self, /) -> PyGe.Vector3d:
        pass
    def endPoint(self, /) -> PyGe.Point3d:
        pass
    def length(self, /) -> float:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def setEndPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setStartPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def startPoint(self, /) -> PyGe.Point3d:
        pass
    def thickness(self, /) -> float:
        pass
class AcadLineType(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLineType:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadLineTypes(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLineTypes:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadMInsertBlock(PyAx.AcadBlockReference):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMInsertBlock:
        pass
    @staticmethod
    def className() -> str:
        pass
    def columnSpacing(self, /) -> float:
        pass
    def columns(self, /) -> int:
        pass
    def rowSpacing(self, /) -> float:
        pass
    def rows(self, /) -> int:
        pass
    def setColumnSpacing(self, val:float, /) -> None:
        pass
    def setColumns(self, val:int, /) -> None:
        pass
    def setRowSpacing(self, val:float, /) -> None:
        pass
    def setRows(self, val:int, /) -> None:
        pass
class AcadMLeader(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addLeader(self, /) -> int:
        pass
    def addLeaderLine(self, val:int, coords:Iterable[PyGe.Point3d], /) -> int:
        pass
    def addLeaderLineEx(self, coords:Iterable[PyGe.Point3d], /) -> int:
        pass
    def arrowheadBlock(self, /) -> str:
        pass
    def arrowheadSize(self, /) -> float:
        pass
    def arrowheadType(self, /) -> AcDimArrowheadType:
        pass
    def blockAttributeValue(self, val:PyDb.ObjectId, /) -> str:
        pass
    def blockConnectionType(self, /) -> AcBlockConnectionType:
        pass
    def blockScale(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMLeader:
        pass
    @staticmethod
    def className() -> str:
        pass
    def contentBlockName(self, /) -> str:
        pass
    def contentBlockType(self, /) -> AcPredefBlockType:
        pass
    def contentType(self, /) -> AcMLeaderContentType:
        pass
    def dogLegged(self, /) -> bool:
        pass
    def doglegDirection(self, val:int, /) -> PyGe.Vector3d:
        pass
    def doglegLength(self, /) -> float:
        pass
    def landingGap(self, /) -> float:
        pass
    def leaderCount(self, /) -> int:
        pass
    def leaderIndex(self, val:int, /) -> int:
        pass
    def leaderLineColor(self, /) -> AcadAcCmColor:
        pass
    def leaderLineIndexes(self, val:int, /) -> list:
        pass
    def leaderLineVertices(self, val:int, /) -> list:
        pass
    def leaderLineWeight(self, /) -> AcLineWeight:
        pass
    def leaderLinetype(self, /) -> str:
        pass
    def leaderType(self, /) -> AcMLeaderType:
        pass
    def removeLeader(self, val:int, /) -> None:
        pass
    def removeLeaderLine(self, val:int, /) -> None:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setArrowheadBlock(self, val:str, /) -> None:
        pass
    def setArrowheadSize(self, val:float, /) -> None:
        pass
    def setArrowheadType(self, val:PyAx.AcDimArrowheadType, /) -> None:
        pass
    def setBlockAttributeValue(self, id:PyDb.ObjectId, val:str, /) -> None:
        pass
    def setBlockConnectionType(self, val:PyAx.AcBlockConnectionType, /) -> None:
        pass
    def setBlockScale(self, val:float, /) -> None:
        pass
    def setContentBlockName(self, val:str, /) -> None:
        pass
    def setContentBlockType(self, val:PyAx.AcPredefBlockType, /) -> None:
        pass
    def setContentType(self, val:PyAx.AcMLeaderContentType, /) -> None:
        pass
    def setDogLegged(self, val:bool, /) -> None:
        pass
    def setDoglegDirection(self, idx:int, val:PyGe.Vector3d, /) -> None:
        pass
    def setDoglegLength(self, val:float, /) -> None:
        pass
    def setLandingGap(self, val:float, /) -> None:
        pass
    def setLeaderLineColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setLeaderLineVertices(self, val:int, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setLeaderLineWeight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setLeaderLinetype(self, val:str, /) -> None:
        pass
    def setLeaderType(self, val:PyAx.AcMLeaderType, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTextAttachmentDirection(self, val:PyAx.AcTextAttachmentDirection, /) -> None:
        pass
    def setTextBackgroundFill(self, val:bool, /) -> None:
        pass
    def setTextBottomAttachmentType(self, val:PyAx.AcVerticalTextAttachmentType, /) -> None:
        pass
    def setTextDirection(self, val:PyAx.AcDrawingDirection, /) -> None:
        pass
    def setTextFrameDisplay(self, val:bool, /) -> None:
        pass
    def setTextHeight(self, val:float, /) -> None:
        pass
    def setTextJustify(self, val:PyAx.AcAttachmentPoint, /) -> None:
        pass
    def setTextLeftAttachmentType(self, val:PyAx.AcTextAttachmentType, /) -> None:
        pass
    def setTextLineSpacingDistance(self, val:float, /) -> None:
        pass
    def setTextLineSpacingFactor(self, val:float, /) -> None:
        pass
    def setTextLineSpacingStyle(self, val:PyAx.AcLineSpacingStyle, /) -> None:
        pass
    def setTextRightAttachmentType(self, val:PyAx.AcTextAttachmentType, /) -> None:
        pass
    def setTextRotation(self, val:float, /) -> None:
        pass
    def setTextString(self, val:str, /) -> None:
        pass
    def setTextStyleName(self, val:str, /) -> None:
        pass
    def setTextTopAttachmentType(self, val:PyAx.AcVerticalTextAttachmentType, /) -> None:
        pass
    def setTextWidth(self, val:float, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def textAttachmentDirection(self, /) -> AcTextAttachmentDirection:
        pass
    def textBackgroundFill(self, /) -> bool:
        pass
    def textBottomAttachmentType(self, /) -> AcVerticalTextAttachmentType:
        pass
    def textDirection(self, /) -> AcDrawingDirection:
        pass
    def textFrameDisplay(self, /) -> bool:
        pass
    def textHeight(self, /) -> float:
        pass
    def textJustify(self, /) -> AcAttachmentPoint:
        pass
    def textLeftAttachmentType(self, /) -> AcTextAttachmentType:
        pass
    def textLineSpacingDistance(self, /) -> float:
        pass
    def textLineSpacingFactor(self, /) -> float:
        pass
    def textLineSpacingStyle(self, /) -> AcLineSpacingStyle:
        pass
    def textRightAttachmentType(self, /) -> AcTextAttachmentType:
        pass
    def textRotation(self, /) -> float:
        pass
    def textString(self, /) -> str:
        pass
    def textStyleName(self, /) -> str:
        pass
    def textTopAttachmentType(self, /) -> AcVerticalTextAttachmentType:
        pass
    def textWidth(self, /) -> float:
        pass
    def vertexCount(self, val:int, /) -> int:
        pass
class AcadMLeaderStyle(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMLeaderStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadMLine(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMLine:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinates(self, /) -> list:
        pass
    def justification(self, /) -> AcMLineJustification:
        pass
    def mlineScale(self, /) -> float:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setJustification(self, val:PyAx.AcMLineJustification, /) -> None:
        pass
    def setMLineScale(self, val:float, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
class AcadMText(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def attachmentPoint(self, /) -> AcAttachmentPoint:
        pass
    def backgroundFill(self, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMText:
        pass
    @staticmethod
    def className() -> str:
        pass
    def drawingDirection(self, /) -> AcDrawingDirection:
        pass
    def fieldCode(self, /) -> str:
        pass
    def height(self, /) -> float:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def lineSpacingDistance(self, /) -> float:
        pass
    def lineSpacingFactor(self, /) -> float:
        pass
    def lineSpacingStyle(self, /) -> AcLineSpacingStyle:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def rotation(self, /) -> float:
        pass
    def setAttachmentPoint(self, val:PyAx.AcAttachmentPoint, /) -> None:
        pass
    def setBackgroundFill(self, val:bool, /) -> None:
        pass
    def setDrawingDirection(self, val:PyAx.AcDrawingDirection, /) -> None:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setLineSpacingDistance(self, val:float, /) -> None:
        pass
    def setLineSpacingFactor(self, val:float, /) -> None:
        pass
    def setLineSpacingStyle(self, val:str, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTextString(self, val:str, /) -> None:
        pass
    def setWidth(self, val:float, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def text(self, /) -> str:
        pass
    def textString(self, /) -> str:
        pass
    def width(self, /) -> float:
        pass
class AcadMaterial(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMaterial:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadMaterials(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMaterials:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadMenuBar:
    def __getitem__(self, index: int, /) -> AcadPopupMenu:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index, /) -> AcadPopupMenu:
        pass
class AcadMenuGroup:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def fileName(self, /) -> str:
        pass
    def menuType(self, /) -> AcMenuGroupType:
        pass
    def menus(self, /) -> AcadPopupMenus:
        pass
    def name(self, /) -> str:
        pass
    def parent(self, /) -> AcadMenuGroups:
        pass
    def save(self, menuType: PyAx.AcadMenuGroup, /) -> None:
        pass
    def saveAs(self, menuFileName: str, menuType: PyAx.AcadMenuGroup, /) -> None:
        pass
    def toolbars(self, /) -> AcadToolbars:
        pass
    def unload(self, /) -> None:
        pass
class AcadMenuGroups:
    def __getitem__(self, index: int, /) -> AcadMenuGroup:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, idx : int, /) -> AcadMenuGroup:
        pass
    def load(self, menuFileName : str, baseMenu : PyAx.AcadMenuGroup = None, /) -> AcadMenuGroup:
        pass
class AcadObject:
    def __hash__(self, /) -> int:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __ne__(self, rhs: PyAx.AcadObject, /) -> bool:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadObject:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def database(self, /) -> AcadDatabase:
        pass
    def erase(self, /) -> None:
        pass
    def extensionDictionary(self, /) -> AcadDictionary:
        pass
    def handle(self, /) -> PyDb.Handle:
        pass
    def hasExtensionDictionary(self, /) -> bool:
        pass
    def isEqualTo(self, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def objectId(self, /) -> PyDb.ObjectId:
        pass
    def objectName(self, /) -> str:
        pass
    def ownerId(self, /) -> PyDb.ObjectId:
        pass
    def setXdata(self, xdata:Iterable[tuple[int,Any]], /) -> None:
        pass
    def xdata(self, appName: str, /) -> list:
        pass
class AcadPViewport(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def arcSmoothness(self, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPViewport:
        pass
    def center(self, /) -> PyGe.Point3d:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clipped(self, /) -> bool:
        pass
    def customScale(self, /) -> float:
        pass
    def direction(self, /) -> PyGe.Vector3d:
        pass
    def display(self, /) -> None:
        pass
    def displayLocked(self, /) -> bool:
        pass
    def gridOn(self, /) -> bool:
        pass
    def gridSpacing(self, /) -> tuple:
        pass
    def hasSheetView(self, /) -> bool:
        pass
    def height(self, /) -> float:
        pass
    def labelBlockId(self, /) -> PyDb.ObjectId:
        pass
    def layerPropertyOverrides(self, /) -> bool:
        pass
    def lensLength(self, /) -> float:
        pass
    def modelView(self, /) -> AcadView:
        pass
    def removeHiddenLines(self, /) -> bool:
        pass
    def setArcSmoothness(self, val:int, /) -> None:
        pass
    def setCenter(self, val:PyGe.Point3d, /) -> None:
        pass
    def setCustomScale(self, val:float, /) -> None:
        pass
    def setDirection(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setDisplayLocked(self, val:bool, /) -> None:
        pass
    def setGridOn(self, val:bool, /) -> None:
        pass
    def setGridSpacing(self, XSpacing:float, YSpacing:float, /) -> None:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setLabelBlockId(self, val:PyDb.ObjectId, /) -> None:
        pass
    def setLensLength(self, val:float, /) -> None:
        pass
    def setModelView(self, val:PyAx.AcadView, /) -> None:
        pass
    def setRemoveHiddenLines(self, val:bool, /) -> None:
        pass
    def setShadePlot(self, val:int, /) -> None:
        pass
    def setSheetView(self, val:PyAx.AcadView, /) -> None:
        pass
    def setSnapBasePoint(self, val:PyGe.Point2d, /) -> None:
        pass
    def setSnapOn(self, val:bool, /) -> None:
        pass
    def setSnapRotationAngle(self, val:float, /) -> None:
        pass
    def setSnapSpacing(self, XSpacing:float, YSpacing:float, /) -> None:
        pass
    def setStandardScale(self, val:PyAx.AcViewportScale, /) -> None:
        pass
    def setStandardScale2(self, val:int, /) -> None:
        pass
    def setStyleSheet(self, val:str, /) -> None:
        pass
    def setTarget(self, val:PyGe.Point3d, /) -> None:
        pass
    def setTwistAngle(self, val:bool, /) -> None:
        pass
    def setUCSIconAtOrigin(self, val:bool, /) -> None:
        pass
    def setUCSIconOn(self, val:bool, /) -> None:
        pass
    def setUCSPerViewport(self, val:bool, /) -> None:
        pass
    def setViewportOn(self, val:bool, /) -> None:
        pass
    def setVisualStyle(self, val:int, /) -> None:
        pass
    def setWidth(self, val:float, /) -> None:
        pass
    def shadePlot(self, /) -> int:
        pass
    def sheetView(self, /) -> AcadView:
        pass
    def snapBasePoint(self, /) -> PyGe.Point2d:
        pass
    def snapOn(self, /) -> bool:
        pass
    def snapRotationAngle(self, /) -> float:
        pass
    def snapSpacing(self, /) -> tuple:
        pass
    def standardScale(self, /) -> AcViewportScale:
        pass
    def standardScale2(self, /) -> int:
        pass
    def styleSheet(self, /) -> str:
        pass
    def syncModelView(self, /) -> None:
        pass
    def target(self, /) -> PyGe.Point3d:
        pass
    def twistAngle(self, /) -> float:
        pass
    def ucsIconAtOrigin(self, /) -> bool:
        pass
    def ucsIconOn(self, /) -> bool:
        pass
    def ucsPerViewport(self, /) -> bool:
        pass
    def viewportOn(self, /) -> bool:
        pass
    def visualStyle(self, /) -> int:
        pass
    def width(self, /) -> float:
        pass
class AcadPlot:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def batchPlotProgress(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def numberOfCopies(self, /) -> int:
        pass
    def quietErrorMode(self, /) -> bool:
        pass
    def setBatchPlotProgress(self, val:bool, /) -> None:
        pass
    def setDisplayPlotPreview(self, val:PyAx.AcPreviewMode, /) -> None:
        pass
    def setLayoutsToPlot(self, layouts:list[str], /) -> None:
        pass
    def setNumberOfCopies(self, val:int, /) -> None:
        pass
    def setQuietErrorMode(self, val:bool, /) -> None:
        pass
    def startBatchMode(self, val:bool, /) -> None:
        pass
class AcadPlotConfiguration(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def canonicalMediaName(self, /) -> str:
        pass
    def canonicalMediaNames(self, /) -> list:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPlotConfiguration:
        pass
    def centerPlot(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def configName(self, /) -> str:
        pass
    def copyFrom(self, val:PyAx.AcadPlotConfiguration, /) -> None:
        pass
    def customScale(self, /) -> tuple:
        pass
    def localeMediaName(self, val:str, /) -> str:
        pass
    def modelType(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def paperMargins(self, /) -> tuple:
        pass
    def paperSize(self, /) -> tuple:
        pass
    def paperUnits(self, /) -> AcPlotPaperUnits:
        pass
    def plotDeviceNames(self, /) -> list:
        pass
    def plotHidden(self, /) -> bool:
        pass
    def plotOrigin(self, /) -> PyGe.Point2d:
        pass
    def plotRotation(self, /) -> AcPlotRotation:
        pass
    def plotStyleTableNames(self, /) -> list:
        pass
    def plotType(self, /) -> AcPlotType:
        pass
    def plotViewportBorders(self, /) -> bool:
        pass
    def plotViewportsFirst(self, /) -> bool:
        pass
    def plotWithLineweights(self, /) -> bool:
        pass
    def plotWithPlotStyles(self, /) -> bool:
        pass
    def refreshPlotDeviceInfo(self, /) -> None:
        pass
    def scaleLineweights(self, /) -> bool:
        pass
    def setCanonicalMediaName(self, val:str, /) -> None:
        pass
    def setCenterPlot(self, val:bool, /) -> None:
        pass
    def setConfigName(self, val:str, /) -> None:
        pass
    def setCustomScale(self, numerator:float, denominator:float, /) -> None:
        pass
    def setName(self, val:str, /) -> None:
        pass
    def setPaperUnits(self, val:PyAx.AcPlotPaperUnits, /) -> None:
        pass
    def setPlotHidden(self, val:bool, /) -> None:
        pass
    def setPlotOrigin(self, orgin:PyGe.Point2d, /) -> None:
        pass
    def setPlotRotation(self, val:PyAx.AcPlotRotation, /) -> None:
        pass
    def setPlotType(self, val:PyAx.AcPlotType, /) -> None:
        pass
    def setPlotViewportBorders(self, val:bool, /) -> None:
        pass
    def setPlotViewportsFirst(self, val:bool, /) -> None:
        pass
    def setPlotWithLineweights(self, val:bool, /) -> None:
        pass
    def setPlotWithPlotStyles(self, val:bool, /) -> None:
        pass
    def setScaleLineweights(self, val:bool, /) -> None:
        pass
    def setShowPlotStyles(self, val:bool, /) -> None:
        pass
    def setStandardScale(self, val:PyAx.AcPlotScale, /) -> None:
        pass
    def setStyleSheet(self, val:str, /) -> None:
        pass
    def setUseStandardScale(self, val:bool, /) -> None:
        pass
    def setViewToPlot(self, val:str, /) -> None:
        pass
    def setWindowToPlot(self, lowerLeft:PyGe.Point2d, upperRight:PyGe.Point2d, /) -> None:
        pass
    def showPlotStyles(self, /) -> bool:
        pass
    def standardScale(self, /) -> AcPlotScale:
        pass
    def styleSheet(self, /) -> str:
        pass
    def useStandardScale(self, /) -> bool:
        pass
    def viewToPlot(self, /) -> str:
        pass
    def windowToPlot(self, /) -> tuple:
        pass
class AcadPlotConfigurations(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPlotConfigurations:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadPoint(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPoint:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinates(self, /) -> PyGe.Point3d:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def setCoordinates(self, val:PyGe.Point3d, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
class AcadPolyfaceMesh(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPolyfaceMesh:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def numberOfFaces(self, /) -> int:
        pass
    def numberOfVertices(self, /) -> int:
        pass
    def setCoordinate(self, index:int, point:PyGe.Point3d, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setFaces(self, faces:Iterable[int], /) -> None:
        pass
class AcadPolygonMesh(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def appendVertex(self, vertex:PyGe.Point3d, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPolygonMesh:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def explode(self, /) -> list:
        pass
    def getType(self, /) -> AcPolymeshType:
        pass
    def mClose(self, /) -> bool:
        pass
    def mDensity(self, /) -> int:
        pass
    def mVertexCount(self, /) -> int:
        pass
    def nClose(self, /) -> bool:
        pass
    def nDensity(self, /) -> int:
        pass
    def nVertexCount(self, /) -> int:
        pass
    def setCoordinate(self, index:int, point:PyGe.Point3d, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setMClose(self, val:bool, /) -> None:
        pass
    def setMDensity(self, val:int, /) -> None:
        pass
    def setNClose(self, val:bool, /) -> None:
        pass
    def setNDensity(self, val:int, /) -> None:
        pass
    def setType(self, val:PyAx.AcPolymeshType, /) -> None:
        pass
class AcadPolyline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def area(self, /) -> float:
        pass
    def bulge(self, index:int, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPolyline:
        pass
    @staticmethod
    def className() -> str:
        pass
    def constantWidth(self, /) -> float:
        pass
    def coordinate(self, index:int, /) -> PyGe.Point3d:
        pass
    def coordinates(self, /) -> list:
        pass
    def elevation(self, /) -> float:
        pass
    def explode(self, /) -> list:
        pass
    def isClosed(self, /) -> bool:
        pass
    def length(self, /) -> float:
        pass
    def linetypeGeneration(self, /) -> bool:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def setBulge(self, index:int, val:float, /) -> None:
        pass
    def setClosed(self, val:bool, /) -> None:
        pass
    def setConstantWidth(self, val:float, /) -> None:
        pass
    def setCoordinate(self, index:int, val:PyGe.Point3d, /) -> None:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setElevation(self, val:float, /) -> None:
        pass
    def setLinetypeGeneration(self, val:bool, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def setWidth(self, index:int, startWidth:float, endWidth:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
    def width(self, index:int, /) -> tuple:
        pass
class AcadPopupMenu:
    def __getitem__(self, index: int, /) -> AcadPopupMenuItem:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addMenuItem(self, idx : int, label : str, macro : str, /) -> AcadPopupMenuItem:
        pass
    def addSeparator(self, idx : int, /) -> AcadPopupMenuItem:
        pass
    def addSubMenu(self, idx : int, label : str, /) -> AcadPopupMenuItem:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def insertInMenuBar(self, idx : int, /) -> None:
        pass
    def isOnMenuBar(self, /) -> bool:
        pass
    def isShortcutMenu(self, /) -> bool:
        pass
    def item(self, idx : int, /) -> AcadPopupMenuItem:
        pass
    def name(self, /) -> str:
        pass
    def nameNoMnemonic(self, /) -> str:
        pass
    def parent(self, /) -> AcadPopupMenus:
        pass
    def removeFromMenuBar(self, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
    def tagString(self, /) -> str:
        pass
class AcadPopupMenuItem:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def caption(self, /) -> str:
        pass
    def check(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def enable(self, /) -> bool:
        pass
    def endSubMenuLevel(self, /) -> int:
        pass
    def getType(self, /) -> AcMenuItemType:
        pass
    def helpString(self, /) -> str:
        pass
    def index(self, /) -> int:
        pass
    def label(self, /) -> str:
        pass
    def macro(self, /) -> str:
        pass
    def parent(self, /) -> AcadPopupMenu:
        pass
    def setCheck(self, enable: bool, /) -> None:
        pass
    def setEnable(self, enable: bool, /) -> None:
        pass
    def setEndSubMenuLevel(self, val: int, /) -> None:
        pass
    def setHelpString(self, helpString: str, /) -> None:
        pass
    def setLabel(self, label: str, /) -> None:
        pass
    def setMacro(self, macro: str, /) -> None:
        pass
    def setTagString(self, tag: str, /) -> None:
        pass
    def subMenu(self, /) -> AcadPopupMenu:
        pass
    def tagString(self, /) -> str:
        pass
class AcadPopupMenus:
    def __getitem__(self, index: int, /) -> AcadPopupMenu:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, toolbarName: str, /) -> AcadPopupMenu:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def insertMenuInMenuBar(self, insertMenuInMenuBar: str, idx : int, /) -> None:
        pass
    def item(self, idx : int, /) -> AcadPopupMenu:
        pass
    def parent(self, /) -> AcadMenuGroup:
        pass
    def removeMenuFromMenuBar(self, idx : int, /) -> None:
        pass
class AcadPreferences:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def display(self, /) -> AcadPreferencesDisplay:
        pass
    def drafting(self, /) -> AcadPreferencesDrafting:
        pass
    def files(self, /) -> AcadPreferencesFiles:
        pass
    def openSave(self, /) -> AcadPreferencesOpenSave:
        pass
    def output(self, /) -> AcadPreferencesOutput:
        pass
    def profiles(self, /) -> AcadPreferencesProfiles:
        pass
    def selection(self, /) -> AcadPreferencesSelection:
        pass
    def system(self, /) -> AcadPreferencesSystem:
        pass
    def user(self, /) -> AcadPreferencesUser:
        pass
class AcadPreferencesDisplay:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def autoTrackingVecColor(self, /) -> tuple:
        pass
    @staticmethod
    def className() -> str:
        pass
    def cursorSize(self, /) -> int:
        pass
    def displayLayoutTabs(self, /) -> bool:
        pass
    def displayScreenMenu(self, /) -> bool:
        pass
    def displayScrollBars(self, /) -> bool:
        pass
    def dockedVisibleLines(self, /) -> int:
        pass
    def graphicsWinLayoutBackgrndColor(self, /) -> tuple:
        pass
    def graphicsWinModelBackgrndColor(self, /) -> tuple:
        pass
    def historyLines(self, /) -> int:
        pass
    def imageFrameHighlight(self, /) -> bool:
        pass
    def layoutCreateViewport(self, /) -> bool:
        pass
    def layoutCrosshairColor(self, /) -> tuple:
        pass
    def layoutDisplayMargins(self, /) -> bool:
        pass
    def layoutDisplayPaper(self, /) -> bool:
        pass
    def layoutDisplayPaperShadow(self, /) -> bool:
        pass
    def layoutShowPlotSetup(self, /) -> bool:
        pass
    def maxAutoCADWindow(self, /) -> bool:
        pass
    def modelCrosshairColor(self, /) -> tuple:
        pass
    def setAutoTrackingVecColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setCursorSize(self, val:int, /) -> None:
        pass
    def setDisplayLayoutTabs(self, val:bool, /) -> None:
        pass
    def setDisplayScreenMenu(self, val:bool, /) -> None:
        pass
    def setDisplayScrollBars(self, val:bool, /) -> None:
        pass
    def setDockedVisibleLines(self, val:int, /) -> None:
        pass
    def setGraphicsWinLayoutBackgrndColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setGraphicsWinModelBackgrndColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setHistoryLines(self, val:int, /) -> None:
        pass
    def setImageFrameHighlight(self, val:bool, /) -> None:
        pass
    def setLayoutCreateViewport(self, val:bool, /) -> None:
        pass
    def setLayoutCrosshairColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setLayoutDisplayMargins(self, val:bool, /) -> None:
        pass
    def setLayoutDisplayPaper(self, val:bool, /) -> None:
        pass
    def setLayoutDisplayPaperShadow(self, val:bool, /) -> None:
        pass
    def setLayoutShowPlotSetup(self, val:bool, /) -> None:
        pass
    def setMaxAutoCADWindow(self, val:bool, /) -> None:
        pass
    def setModelCrosshairColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setShowRasterImage(self, val:bool, /) -> None:
        pass
    def setTextFont(self, val:str, /) -> None:
        pass
    def setTextFontSize(self, val:int, /) -> None:
        pass
    def setTextFontStyle(self, val:PyAx.AcTextFontStyle, /) -> None:
        pass
    def setTextWinBackgrndColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setTextWinTextColor(self, rgb:tuple[int,int,int], /) -> None:
        pass
    def setTrueColorImages(self, val:bool, /) -> None:
        pass
    def setXRefFadeIntensity(self, val:bool, /) -> None:
        pass
    def showRasterImage(self, /) -> bool:
        pass
    def textFont(self, /) -> str:
        pass
    def textFontSize(self, /) -> int:
        pass
    def textFontStyle(self, /) -> AcTextFontStyle:
        pass
    def textWinBackgrndColor(self, /) -> tuple:
        pass
    def textWinTextColor(self, /) -> tuple:
        pass
    def trueColorImages(self, /) -> bool:
        pass
    def xrefFadeIntensity(self, /) -> int:
        pass
class AcadPreferencesDrafting:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def alignmentPointAcquisition(self, /) -> AcAlignmentPointAcquisition:
        pass
    def autoSnapAperture(self, /) -> bool:
        pass
    def autoSnapApertureSize(self, /) -> int:
        pass
    def autoSnapMagnet(self, /) -> bool:
        pass
    def autoSnapMarker(self, /) -> bool:
        pass
    def autoSnapMarkerColor(self, /) -> AcColor:
        pass
    def autoSnapMarkerSize(self, /) -> int:
        pass
    def autoSnapTooltip(self, /) -> bool:
        pass
    def autoTrackTooltip(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def fullScreenTrackingVector(self, /) -> bool:
        pass
    def polarTrackingVector(self, /) -> bool:
        pass
    def setAlignmentPointAcquisition(self, flag:PyAx.AcAlignmentPointAcquisition, /) -> None:
        pass
    def setAutoSnapAperture(self, flag:bool, /) -> None:
        pass
    def setAutoSnapApertureSize(self, flag:int, /) -> None:
        pass
    def setAutoSnapMagnet(self, flag:bool, /) -> None:
        pass
    def setAutoSnapMarker(self, flag:bool, /) -> None:
        pass
    def setAutoSnapMarkerColor(self, flag:PyAx.AcColor, /) -> None:
        pass
    def setAutoSnapMarkerSize(self, flag:int, /) -> None:
        pass
    def setAutoSnapTooltip(self, flag:bool, /) -> None:
        pass
    def setAutoTrackTooltip(self, flag:bool, /) -> None:
        pass
    def setFullScreenTrackingVector(self, flag:bool, /) -> None:
        pass
    def setPolarTrackingVector(self, flag:bool, /) -> None:
        pass
class AcadPreferencesFiles:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def activeInvProject(self, /) -> str:
        pass
    def altFontFile(self, /) -> str:
        pass
    def altTabletMenuFile(self, /) -> str:
        pass
    def autoSavePath(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def colorBookPath(self, /) -> str:
        pass
    def configFile(self, /) -> str:
        pass
    def customDictionary(self, /) -> str:
        pass
    def customIconPath(self, /) -> str:
        pass
    def defaultInternetURL(self, /) -> str:
        pass
    def driversPath(self, /) -> str:
        pass
    def enterpriseMenuFile(self, /) -> str:
        pass
    def fontFileMap(self, /) -> str:
        pass
    def helpFilePath(self, /) -> str:
        pass
    def licenseServer(self, /) -> str:
        pass
    def logFilePath(self, /) -> str:
        pass
    def mainDictionary(self, /) -> str:
        pass
    def menuFile(self, /) -> str:
        pass
    def objectARXPath(self, /) -> str:
        pass
    def pageSetupOverridesTemplateFile(self, /) -> str:
        pass
    def plotLogFilePath(self, /) -> str:
        pass
    def postScriptPrologFile(self, /) -> str:
        pass
    def printFile(self, /) -> str:
        pass
    def printSpoolExecutable(self, /) -> str:
        pass
    def printSpoolerPath(self, /) -> str:
        pass
    def printerConfigPath(self, /) -> str:
        pass
    def printerDescPath(self, /) -> str:
        pass
    def printerStyleSheetPath(self, /) -> str:
        pass
    def projectFilePath(self, projectName:str, /) -> str:
        pass
    def qnewTemplateFile(self, /) -> str:
        pass
    def setActiveInvProject(self, val:str, /) -> None:
        pass
    def setAltFontFile(self, val:str, /) -> None:
        pass
    def setAltTabletMenuFile(self, val:str, /) -> None:
        pass
    def setAutoSavePath(self, val:str, /) -> None:
        pass
    def setColorBookPath(self, val:str, /) -> None:
        pass
    def setCustomDictionary(self, val:str, /) -> None:
        pass
    def setCustomIconPath(self, val:str, /) -> None:
        pass
    def setDefaultInternetURL(self, val:str, /) -> None:
        pass
    def setDriversPath(self, val:str, /) -> None:
        pass
    def setEnterpriseMenuFile(self, val:str, /) -> None:
        pass
    def setFontFileMap(self, val:str, /) -> None:
        pass
    def setHelpFilePath(self, val:str, /) -> None:
        pass
    def setLogFilePath(self, val:str, /) -> None:
        pass
    def setMainDictionary(self, val:str, /) -> None:
        pass
    def setMenuFile(self, val:str, /) -> None:
        pass
    def setObjectARXPath(self, val:str, /) -> None:
        pass
    def setPageSetupOverridesTemplateFile(self, val:str, /) -> None:
        pass
    def setPlotLogFilePath(self, val:str, /) -> None:
        pass
    def setPostScriptPrologFile(self, val:str, /) -> None:
        pass
    def setPrintFile(self, val:str, /) -> None:
        pass
    def setPrintSpoolExecutable(self, val:str, /) -> None:
        pass
    def setPrintSpoolerPath(self, val:str, /) -> None:
        pass
    def setPrinterConfigPath(self, val:str, /) -> None:
        pass
    def setPrinterDescPath(self, val:str, /) -> None:
        pass
    def setPrinterStyleSheetPath(self, val:str, /) -> None:
        pass
    def setProjectFilePath(self, projectName:str, projectFilePath:str, /) -> None:
        pass
    def setQNewTemplateFile(self, val:str, /) -> None:
        pass
    def setSupportPath(self, val:str, /) -> None:
        pass
    def setTempFilePath(self, val:str, /) -> None:
        pass
    def setTempXrefPath(self, val:str, /) -> None:
        pass
    def setTemplateDwgPath(self, val:str, /) -> None:
        pass
    def setTextEditor(self, val:str, /) -> None:
        pass
    def setTextureMapPath(self, val:str, /) -> None:
        pass
    def setToolPalettePath(self, val:str, /) -> None:
        pass
    def setWorkspacePath(self, val:str, /) -> None:
        pass
    def supportPath(self, /) -> str:
        pass
    def tempFilePath(self, /) -> str:
        pass
    def tempXrefPath(self, /) -> str:
        pass
    def templateDwgPath(self, /) -> str:
        pass
    def textEditor(self, /) -> str:
        pass
    def textureMapPath(self, /) -> str:
        pass
    def toolPalettePath(self, /) -> str:
        pass
    def workspacePath(self, /) -> str:
        pass
class AcadPreferencesOpenSave:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def autoAudit(self, /) -> bool:
        pass
    def autoSaveInterval(self, /) -> int:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createBackup(self, /) -> bool:
        pass
    def demandLoadARXApp(self, /) -> object:
        pass
    def fullCRCValidation(self, /) -> bool:
        pass
    def incrementalSavePercent(self, /) -> int:
        pass
    def logFileOn(self, /) -> bool:
        pass
    def mruNumber(self, /) -> int:
        pass
    def proxyImage(self, /) -> AcProxyImage:
        pass
    def saveAsType(self, /) -> AcSaveAsType:
        pass
    def savePreviewThumbnail(self, /) -> bool:
        pass
    def setAutoAudit(self, val:bool, /) -> None:
        pass
    def setAutoSaveInterval(self, val:int, /) -> None:
        pass
    def setCreateBackup(self, val:bool, /) -> None:
        pass
    def setDemandLoadARXApp(self, val:PyAx.AcARXDemandLoad, /) -> None:
        pass
    def setFullCRCValidation(self, val:bool, /) -> None:
        pass
    def setIncrementalSavePercent(self, val:int, /) -> None:
        pass
    def setLogFileOn(self, val:bool, /) -> None:
        pass
    def setProxyImage(self, val:PyAx.AcProxyImage, /) -> None:
        pass
    def setSaveAsType(self, val:PyAx.AcSaveAsType, /) -> None:
        pass
    def setSavePreviewThumbnail(self, val:bool, /) -> None:
        pass
    def setShowProxyDialogBox(self, val:bool, /) -> None:
        pass
    def setTempFileExtension(self, val:str, /) -> None:
        pass
    def setXrefDemandLoad(self, val:PyAx.AcXRefDemandLoad, /) -> None:
        pass
    def showProxyDialogBox(self, /) -> bool:
        pass
    def tempFileExtension(self, /) -> str:
        pass
    def xrefDemandLoad(self, /) -> AcXRefDemandLoad:
        pass
class AcadPreferencesOutput:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def automaticPlotLog(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def continuousPlotLog(self, /) -> bool:
        pass
    def defaultOutputDevice(self, /) -> str:
        pass
    def defaultPlotStyleForLayer(self, /) -> str:
        pass
    def defaultPlotStyleForObjects(self, /) -> str:
        pass
    def defaultPlotStyleTable(self, /) -> str:
        pass
    def defaultPlotToFilePath(self, /) -> str:
        pass
    def oleQuality(self, /) -> AcOleQuality:
        pass
    def plotLegacy(self, /) -> bool:
        pass
    def plotPolicy(self, /) -> object:
        pass
    def printerPaperSizeAlert(self, /) -> bool:
        pass
    def printerSpoolAlert(self, /) -> AcPrinterSpoolAlert:
        pass
    def setAutomaticPlotLog(self, val:bool, /) -> None:
        pass
    def setContinuousPlotLog(self, val:bool, /) -> None:
        pass
    def setDefaultOutputDevice(self, val:str, /) -> None:
        pass
    def setDefaultPlotStyleForLayer(self, val:str, /) -> None:
        pass
    def setDefaultPlotStyleForObjects(self, val:str, /) -> None:
        pass
    def setDefaultPlotStyleTable(self, val:str, /) -> None:
        pass
    def setDefaultPlotToFilePath(self, val:str, /) -> None:
        pass
    def setOLEQuality(self, val:PyAx.AcOleQuality, /) -> None:
        pass
    def setPlotLegacy(self, val:bool, /) -> None:
        pass
    def setPlotPolicy(self, val:PyAx.AcPlotPolicy, /) -> None:
        pass
    def setPrinterPaperSizeAlert(self, val:bool, /) -> None:
        pass
    def setPrinterSpoolAlert(self, val:PyAx.AcPrinterSpoolAlert, /) -> None:
        pass
    def setUseLastPlotSettings(self, val:bool, /) -> None:
        pass
    def useLastPlotSettings(self, /) -> bool:
        pass
class AcadPreferencesProfiles:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def activeProfile(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def copyProfile(self, oldProfileName:str, newProfileName:str, /) -> None:
        pass
    def deleteProfile(self, profileName:str, /) -> None:
        pass
    def exportProfile(self, profileName:str, regFile:str, /) -> None:
        pass
    def getAllProfileNames(self, /) -> list:
        pass
    def importProfile(self, profileName:str, regFile:str, IncludePathInfo:bool, /) -> None:
        pass
    def renameProfile(self, origProfileName:str, newProfileName:str, /) -> None:
        pass
    def resetProfile(self, profile:str, /) -> None:
        pass
    def setActiveProfile(self, activeProfile:str, /) -> None:
        pass
class AcadPreferencesSelection:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def displayGrips(self, /) -> bool:
        pass
    def displayGripsWithinBlocks(self, /) -> bool:
        pass
    def gripColorSelected(self, /) -> AcColor:
        pass
    def gripColorUnselected(self, /) -> AcColor:
        pass
    def gripSize(self, /) -> int:
        pass
    def pickAdd(self, /) -> bool:
        pass
    def pickAuto(self, /) -> bool:
        pass
    def pickBoxSize(self, /) -> int:
        pass
    def pickDrag(self, /) -> bool:
        pass
    def pickFirst(self, /) -> bool:
        pass
    def pickGroup(self, /) -> bool:
        pass
    def setDisplayGrips(self, flag:bool, /) -> None:
        pass
    def setDisplayGripsWithinBlocks(self, flag:bool, /) -> None:
        pass
    def setGripColorSelected(self, clr:PyAx.AcColor, /) -> None:
        pass
    def setGripColorUnselected(self, clr:PyAx.AcColor, /) -> None:
        pass
    def setGripSize(self, flag:int, /) -> None:
        pass
    def setPickAdd(self, flag:bool, /) -> None:
        pass
    def setPickAuto(self, flag:bool, /) -> None:
        pass
    def setPickBoxSize(self, flag:int, /) -> None:
        pass
    def setPickDrag(self, flag:bool, /) -> None:
        pass
    def setPickFirst(self, flag:bool, /) -> None:
        pass
    def setPickGroup(self, flag:bool, /) -> None:
        pass
class AcadPreferencesSystem:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def beepOnError(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def displayOLEScale(self, /) -> bool:
        pass
    def enableStartupDialog(self, /) -> bool:
        pass
    def loadAcadLspInAllDocuments(self, /) -> bool:
        pass
    def setBeepOnError(self, val:bool, /) -> None:
        pass
    def setDisplayOLEScale(self, val:bool, /) -> None:
        pass
    def setEnableStartupDialog(self, val:bool, /) -> None:
        pass
    def setLoadAcadLspInAllDocuments(self, val:bool, /) -> None:
        pass
    def setShowWarningMessages(self, val:bool, /) -> None:
        pass
    def setSingleDocumentMode(self, val:bool, /) -> None:
        pass
    def setStoreSQLIndex(self, val:bool, /) -> None:
        pass
    def setTablesReadOnly(self, val:bool, /) -> None:
        pass
    def showWarningMessages(self, /) -> bool:
        pass
    def singleDocumentMode(self, /) -> bool:
        pass
    def storeSQLIndex(self, /) -> bool:
        pass
    def tablesReadOnly(self, /) -> bool:
        pass
class AcadPreferencesUser:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def acmEditMode(self, /) -> AcDrawingAreaSCMEdit:
        pass
    def adcInsertUnitsDefaultSource(self, /) -> AcInsertUnits:
        pass
    def adcInsertUnitsDefaultTarget(self, /) -> AcInsertUnits:
        pass
    @staticmethod
    def className() -> str:
        pass
    def hyperlinkDisplayCursor(self, /) -> bool:
        pass
    def keyboardAccelerator(self, /) -> AcKeyboardAccelerator:
        pass
    def keyboardPriority(self, /) -> AcKeyboardPriority:
        pass
    def scmCommandMode(self, /) -> AcDrawingAreaSCMCommand:
        pass
    def scmDefaultMode(self, /) -> AcDrawingAreaSCMDefault:
        pass
    def scmTimeMode(self, /) -> bool:
        pass
    def scmTimeValue(self, /) -> int:
        pass
    def setADCInsertUnitsDefaultSource(self, val:PyAx.AcInsertUnits, /) -> None:
        pass
    def setADCInsertUnitsDefaultTarget(self, val:PyAx.AcInsertUnits, /) -> None:
        pass
    def setHyperlinkDisplayCursor(self, val:bool, /) -> None:
        pass
    def setKeyboardAccelerator(self, val:PyAx.AcKeyboardAccelerator, /) -> None:
        pass
    def setKeyboardPriority(self, val:PyAx.AcKeyboardPriority, /) -> None:
        pass
    def setSCMCommandMode(self, val:PyAx.AcDrawingAreaSCMCommand, /) -> None:
        pass
    def setSCMDefaultMode(self, val:PyAx.AcDrawingAreaSCMDefault, /) -> None:
        pass
    def setSCMEditMode(self, val:PyAx.AcDrawingAreaSCMEdit, /) -> None:
        pass
    def setSCMTimeMode(self, val:bool, /) -> None:
        pass
    def setSCMTimeValue(self, val:int, /) -> None:
        pass
    def setShortCutMenuDisplay(self, val:bool, /) -> None:
        pass
    def shortCutMenuDisplay(self, /) -> bool:
        pass
class AcadRasterImage(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def brightness(self, /) -> int:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRasterImage:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clipBoundary(self, val:Iterable[PyGe.Point2d], /) -> None:
        pass
    def clippingEnabled(self, /) -> bool:
        pass
    def contrast(self, /) -> int:
        pass
    def fade(self, /) -> int:
        pass
    def height(self, /) -> float:
        pass
    def imageFile(self, /) -> str:
        pass
    def imageHeight(self, /) -> float:
        pass
    def imageVisibility(self, /) -> bool:
        pass
    def imageWidth(self, /) -> float:
        pass
    def name(self, /) -> str:
        pass
    def origin(self, /) -> PyGe.Point3d:
        pass
    def rotation(self, /) -> float:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setBrightness(self, val:int, /) -> None:
        pass
    def setClippingEnabled(self, val:bool, /) -> None:
        pass
    def setContrast(self, val:int, /) -> None:
        pass
    def setFade(self, val:int, /) -> None:
        pass
    def setImageFile(self, val:str, /) -> None:
        pass
    def setImageHeight(self, val:float, /) -> None:
        pass
    def setImageVisibility(self, val:bool, /) -> None:
        pass
    def setImageWidth(self, val:float, /) -> None:
        pass
    def setName(self, val:str, /) -> None:
        pass
    def setOrigin(self, val:PyGe.Point3d, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setShowRotation(self, val:bool, /) -> None:
        pass
    def setTransparency(self, val:bool, /) -> None:
        pass
    def showRotation(self, /) -> bool:
        pass
    def transparency(self, /) -> bool:
        pass
    def width(self, /) -> float:
        pass
class AcadRay(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def basePoint(self, /) -> PyGe.Point3d:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRay:
        pass
    @staticmethod
    def className() -> str:
        pass
    def directionVector(self, /) -> PyGe.Vector3d:
        pass
    def secondPoint(self, /) -> PyGe.Point3d:
        pass
    def setBasePoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setDirectionVector(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setSecondPoint(self, val:PyGe.Point3d, /) -> None:
        pass
class AcadRegion(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def area(self, /) -> float:
        pass
    def boolean(self, booleanType:PyAx.AcBooleanType, region:PyAx.AcadRegion, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRegion:
        pass
    def centroid(self, /) -> PyGe.Point2d:
        pass
    @staticmethod
    def className() -> str:
        pass
    def explode(self, /) -> list:
        pass
    def momentOfInertia(self, /) -> PyGe.Point3d:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def perimeter(self, /) -> float:
        pass
    def principalDirections(self, /) -> list:
        pass
    def principalMoments(self, /) -> PyGe.Point3d:
        pass
    def radiiOfGyration(self, /) -> PyGe.Point3d:
        pass
class AcadRegisteredApplication(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRegisteredApplication:
        pass
    @staticmethod
    def className() -> str:
        pass
    def name(self, /) -> str:
        pass
    def setName(self, name:str, /) -> None:
        pass
class AcadRegisteredApplications(PyAx.AcadObject):
    def __getitem__(self, index: int, /) -> AcadRegisteredApplication:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, name: str, /) -> AcadRegisteredApplication:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRegisteredApplications:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index: int, /) -> AcadRegisteredApplication:
        pass
class AcadSection(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSection:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadSectionManager(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSectionManager:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadSectionSettings(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSectionSettings:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadSectionTypeSettings:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def backgroundLinesColor(self, /) -> AcadAcCmColor:
        pass
    def backgroundLinesHiddenLine(self, /) -> bool:
        pass
    def backgroundLinesLayer(self, /) -> str:
        pass
    def backgroundLinesLinetype(self, /) -> str:
        pass
    def backgroundLinesLinetypeScale(self, /) -> float:
        pass
    def backgroundLinesLineweight(self, /) -> AcLineWeight:
        pass
    def backgroundLinesPlotStyleName(self, /) -> str:
        pass
    def backgroundLinesVisible(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    def curveTangencyLinesColor(self, /) -> AcadAcCmColor:
        pass
    def curveTangencyLinesLayer(self, /) -> str:
        pass
    def curveTangencyLinesLinetype(self, /) -> str:
        pass
    def curveTangencyLinesLinetypeScale(self, /) -> float:
        pass
    def curveTangencyLinesLineweight(self, /) -> AcLineWeight:
        pass
    def curveTangencyLinesPlotStyleName(self, /) -> str:
        pass
    def curveTangencyLinesVisible(self, /) -> bool:
        pass
    def destinationFile(self, /) -> str:
        pass
    def foregroundLinesColor(self, /) -> AcadAcCmColor:
        pass
    def foregroundLinesEdgeTransparency(self, /) -> int:
        pass
    def foregroundLinesFaceTransparency(self, /) -> int:
        pass
    def foregroundLinesHiddenLine(self, /) -> bool:
        pass
    def foregroundLinesLayer(self, /) -> str:
        pass
    def foregroundLinesLinetype(self, /) -> str:
        pass
    def foregroundLinesLinetypeScale(self, /) -> float:
        pass
    def foregroundLinesLineweight(self, /) -> AcLineWeight:
        pass
    def foregroundLinesPlotStyleName(self, /) -> str:
        pass
    def foregroundLinesVisible(self, /) -> bool:
        pass
    def generationOptions(self, /) -> AcSectionGeneration:
        pass
    def intersectionBoundaryColor(self, /) -> AcadAcCmColor:
        pass
    def intersectionBoundaryDivisionLines(self, /) -> bool:
        pass
    def intersectionBoundaryLayer(self, /) -> str:
        pass
    def intersectionBoundaryLinetype(self, /) -> str:
        pass
    def intersectionBoundaryLinetypeScale(self, /) -> float:
        pass
    def intersectionBoundaryLineweight(self, /) -> AcLineWeight:
        pass
    def intersectionBoundaryPlotStyleName(self, /) -> str:
        pass
    def intersectionFillColor(self, /) -> AcadAcCmColor:
        pass
    def intersectionFillFaceTransparency(self, /) -> int:
        pass
    def intersectionFillHatchAngle(self, /) -> float:
        pass
    def intersectionFillHatchPatternName(self, /) -> str:
        pass
    def intersectionFillHatchPatternType(self, /) -> AcPatternType:
        pass
    def intersectionFillHatchScale(self, /) -> float:
        pass
    def intersectionFillHatchSpacing(self, /) -> float:
        pass
    def intersectionFillLayer(self, /) -> str:
        pass
    def intersectionFillLinetype(self, /) -> str:
        pass
    def intersectionFillLinetypeScale(self, /) -> float:
        pass
    def intersectionFillLineweight(self, /) -> AcLineWeight:
        pass
    def intersectionFillPlotStyleName(self, /) -> str:
        pass
    def intersectionFillVisible(self, /) -> bool:
        pass
    def setBackgroundLinesColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setBackgroundLinesHiddenLine(self, val:bool, /) -> None:
        pass
    def setBackgroundLinesLayer(self, val:str, /) -> None:
        pass
    def setBackgroundLinesLinetype(self, val:str, /) -> None:
        pass
    def setBackgroundLinesLinetypeScale(self, val:float, /) -> None:
        pass
    def setBackgroundLinesLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setBackgroundLinesPlotStyleName(self, val:str, /) -> None:
        pass
    def setBackgroundLinesVisible(self, val:bool, /) -> None:
        pass
    def setCurveTangencyLinesColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setCurveTangencyLinesLayer(self, val:str, /) -> None:
        pass
    def setCurveTangencyLinesLinetype(self, val:str, /) -> None:
        pass
    def setCurveTangencyLinesLinetypeScale(self, val:float, /) -> None:
        pass
    def setCurveTangencyLinesLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setCurveTangencyLinesPlotStyleName(self, val:str, /) -> None:
        pass
    def setCurveTangencyLinesVisible(self, val:bool, /) -> None:
        pass
    def setDestinationFile(self, val:str, /) -> None:
        pass
    def setForegroundLinesColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setForegroundLinesEdgeTransparency(self, val:int, /) -> None:
        pass
    def setForegroundLinesFaceTransparency(self, val:int, /) -> None:
        pass
    def setForegroundLinesHiddenLine(self, val:bool, /) -> None:
        pass
    def setForegroundLinesLayer(self, val:str, /) -> None:
        pass
    def setForegroundLinesLinetype(self, val:str, /) -> None:
        pass
    def setForegroundLinesLinetypeScale(self, val:float, /) -> None:
        pass
    def setForegroundLinesLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setForegroundLinesPlotStyleName(self, val:str, /) -> None:
        pass
    def setForegroundLinesVisible(self, val:bool, /) -> None:
        pass
    def setGenerationOptions(self, val:PyAx.AcSectionGeneration, /) -> None:
        pass
    def setIntersectionBoundaryColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setIntersectionBoundaryDivisionLines(self, val:bool, /) -> None:
        pass
    def setIntersectionBoundaryLayer(self, val:str, /) -> None:
        pass
    def setIntersectionBoundaryLinetype(self, val:str, /) -> None:
        pass
    def setIntersectionBoundaryLinetypeScale(self, val:float, /) -> None:
        pass
    def setIntersectionBoundaryLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setIntersectionBoundaryPlotStyleName(self, val:str, /) -> None:
        pass
    def setIntersectionFillColor(self, val:PyAx.AcadAcCmColor, /) -> None:
        pass
    def setIntersectionFillFaceTransparency(self, val:int, /) -> None:
        pass
    def setIntersectionFillHatchAngle(self, val:float, /) -> None:
        pass
    def setIntersectionFillHatchPatternName(self, val:str, /) -> None:
        pass
    def setIntersectionFillHatchPatternType(self, val:PyAx.AcPatternType, /) -> None:
        pass
    def setIntersectionFillHatchScale(self, val:float, /) -> None:
        pass
    def setIntersectionFillHatchSpacing(self, val:float, /) -> None:
        pass
    def setIntersectionFillLayer(self, val:str, /) -> None:
        pass
    def setIntersectionFillLinetype(self, val:str, /) -> None:
        pass
    def setIntersectionFillLinetypeScale(self, val:float, /) -> None:
        pass
    def setIntersectionFillLineweight(self, val:PyAx.AcLineWeight, /) -> None:
        pass
    def setIntersectionFillPlotStyleName(self, val:str, /) -> None:
        pass
    def setIntersectionFillVisible(self, val:bool, /) -> None:
        pass
    def setSourceObjects(self, ids:list[PyDb.ObjectId], /) -> None:
        pass
    def sourceObjects(self, /) -> list:
        pass
class AcadSecurityParams:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadSelectionSet:
    def __getitem__(self, index: int, /) -> AcadEntity:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __iter__(self, /) -> object:
        pass
    def __reduce__(self, /):
        pass
    def addItems(self, entities:list[PyAx.AcadEntity], /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def count(self, /) -> int:
        pass
    def delete(self, /) -> None:
        pass
    def entities(self, /) -> list:
        pass
    def highlight(self, bHighlight:bool, /) -> None:
        pass
    def item(self, index:int, /) -> AcadEntity:
        pass
    def name(self, /) -> str:
        pass
    def removeItems(self, entities:list[PyAx.AcadEntity], /) -> None:
        pass
    def selectAll(self, filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectAtPoint(self, pt1:PyGe.Point3d, filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectCrossing(self, pt1:PyGe.Point3d, pt2:PyGe.Point3d, filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectCrossingPolygon(self, pts:list[PyGe.Point3d]|tuple[PyGe.Point3d,...], filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectFence(self, pts:list[PyGe.Point3d]|tuple[PyGe.Point3d,...], filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectLast(self, /) -> None:
        pass
    def selectOnScreen(self, filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectWindow(self, pt1:PyGe.Point3d, pt2:PyGe.Point3d, filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def selectWindowPolygon(self, pts:list[PyGe.Point3d]|tuple[PyGe.Point3d,...], filter:list[tuple[int,Any]]=None, /) -> None:
        pass
    def update(self, /) -> None:
        pass
class AcadSelectionSets:
    def __getitem__(self, index: int, /) -> AcadSelectionSet:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, name: str, /) -> AcadSelectionSet:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, index: int, /) -> AcadSelectionSet:
        pass
class AcadShape(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadShape:
        pass
    @staticmethod
    def className() -> str:
        pass
    def height(self, /) -> float:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def name(self, /) -> str:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def obliqueAngle(self, /) -> float:
        pass
    def rotation(self, /) -> float:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setName(self, val:str, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setObliqueAngle(self, val:float, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
class AcadSolid(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSolid:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinates(self, /) -> list:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
class AcadSortentsTable(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSortentsTable:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadSpline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addFitPoint(self, val:int, point:PyGe.Point3d, /) -> None:
        pass
    def area(self, /) -> float:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSpline:
        pass
    @staticmethod
    def className() -> str:
        pass
    def closed(self, /) -> bool:
        pass
    def closed2(self, /) -> bool:
        pass
    def controlPoint(self, val:int, /) -> PyGe.Point3d:
        pass
    def controlPoints(self, /) -> list:
        pass
    def degree(self, /) -> int:
        pass
    def degree2(self, /) -> int:
        pass
    def deleteFitPoint(self, val:int, /) -> None:
        pass
    def elevateOrder(self, val:int, /) -> None:
        pass
    def endTangent(self, /) -> PyGe.Vector3d:
        pass
    def fitPoint(self, val:int, /) -> PyGe.Point3d:
        pass
    def fitPoints(self, /) -> list:
        pass
    def fitTolerance(self, /) -> float:
        pass
    def isPeriodic(self, /) -> bool:
        pass
    def isPlanar(self, /) -> tuple[bool,PyGe.Plane]:
        pass
    def isRational(self, /) -> bool:
        pass
    def knotParameterization(self, /) -> AcSplineKnotParameterizationType:
        pass
    def knots(self, /) -> list:
        pass
    def numberOfControlPoints(self, /) -> int:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def purgeFitData(self, /) -> None:
        pass
    def reverse(self, /) -> None:
        pass
    def setClosed2(self, val:bool, /) -> None:
        pass
    def setControlPoint(self, val:int, point:PyGe.Point3d, /) -> None:
        pass
    def setControlPoints(self, items:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setDegree2(self, val:int, /) -> None:
        pass
    def setEndTangent(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setFitPoint(self, val:int, point:PyGe.Point3d, /) -> None:
        pass
    def setFitPoints(self, items:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setFitTolerance(self, val:float, /) -> None:
        pass
    def setKnotParameterization(self, val:PyAx.AcSplineKnotParameterizationType, /) -> None:
        pass
    def setKnots(self, items:Iterable[PyGe.Vector3d], /) -> None:
        pass
    def setSplineFrame(self, val:PyAx.AcSplineFrameType, /) -> None:
        pass
    def setSplineMethod(self, val:PyAx.AcSplineMethodType, /) -> None:
        pass
    def setStartTangent(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setWeight(self, val:int, weight:float, /) -> None:
        pass
    def setWeights(self, items:Iterable[float], /) -> None:
        pass
    def splineFrame(self, /) -> AcSplineFrameType:
        pass
    def splineMethod(self, /) -> AcSplineMethodType:
        pass
    def startTangent(self, /) -> PyGe.Vector3d:
        pass
    def weight(self, val:int, /) -> float:
        pass
    def weights(self, /) -> list:
        pass
class AcadState:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def isQuiescent(self, /) -> bool:
        pass
class AcadSummaryInfo:
    def __getitem__(self, index: int, /) -> tuple:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addCustomInfo(self, key:str, val:str, /) -> None:
        pass
    def author(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def comments(self, /) -> str:
        pass
    def customByIndex(self, index:int, /) -> tuple:
        pass
    def customByKey(self, key:str, /) -> str:
        pass
    def hyperlinkBase(self, /) -> str:
        pass
    def keywords(self, /) -> str:
        pass
    def lastSavedBy(self, /) -> str:
        pass
    def numCustomInfo(self, /) -> int:
        pass
    def removeCustomByIndex(self, index:int, /) -> None:
        pass
    def removeCustomByKey(self, key:str, /) -> None:
        pass
    def revisionNumber(self, /) -> str:
        pass
    def setAuthor(self, val:str, /) -> None:
        pass
    def setComments(self, val:str, /) -> None:
        pass
    def setCustomByIndex(self, index:int, key:str, val:str, /) -> None:
        pass
    def setCustomByKey(self, key:str, val:str, /) -> None:
        pass
    def setHyperlinkBase(self, val:str, /) -> None:
        pass
    def setKeywords(self, val:str, /) -> None:
        pass
    def setLastSavedBy(self, val:str, /) -> None:
        pass
    def setRevisionNumber(self, val:str, /) -> None:
        pass
    def setSubject(self, val:str, /) -> None:
        pass
    def setTitle(self, val:str, /) -> None:
        pass
    def subject(self, /) -> str:
        pass
    def title(self, /) -> str:
        pass
class AcadTable(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTable:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadTableStyle(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTableStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadText(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def alignment(self, /) -> AcAlignment:
        pass
    def backward(self, /) -> bool:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadText:
        pass
    @staticmethod
    def className() -> str:
        pass
    def fieldCode(self, /) -> str:
        pass
    def height(self, /) -> float:
        pass
    def horizontalAlignment(self, /) -> AcHorizontalAlignment:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def obliqueAngle(self, /) -> float:
        pass
    def rotation(self, /) -> float:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setAlignment(self, val: PyAx.AcAlignment, /) -> None:
        pass
    def setBackward(self, val:bool, /) -> None:
        pass
    def setHeight(self, val:float, /) -> None:
        pass
    def setHorizontalAlignment(self, val: PyAx.AcHorizontalAlignment, /) -> None:
        pass
    def setInsertionPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setObliqueAngle(self, val:float, /) -> None:
        pass
    def setRotation(self, val:float, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val: str, /) -> None:
        pass
    def setTextAlignmentPoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setTextGenerationFlag(self, val:long, /) -> None:
        pass
    def setTextString(self, val: str, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def setUpsideDown(self, val:bool, /) -> None:
        pass
    def setVerticalAlignment(self, val: PyAx.AcVerticalAlignment, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def textAlignmentPoint(self, /) -> PyGe.Point3d:
        pass
    def textGenerationFlag(self, /) -> int:
        pass
    def textString(self, /) -> str:
        pass
    def thickness(self, /) -> float:
        pass
    def upsideDown(self, /) -> bool:
        pass
    def verticalAlignment(self, /) -> AcVerticalAlignment:
        pass
class AcadTextStyle(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTextStyle:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadTextStyles(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTextStyles:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadTolerance(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTolerance:
        pass
    @staticmethod
    def className() -> str:
        pass
    def dimensionLineColor(self, /) -> AcColor:
        pass
    def directionVector(self, /) -> PyGe.Vector3d:
        pass
    def insertionPoint(self, /) -> PyGe.Point3d:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def scaleFactor(self, /) -> float:
        pass
    def setDimensionLineColor(self, val:float, /) -> None:
        pass
    def setDirectionVector(self, val: PyGe.Vector3d, /) -> None:
        pass
    def setInsertionPoint(self, val: PyGe.Point3d, /) -> None:
        pass
    def setNormal(self, val: PyGe.Vector3d, /) -> None:
        pass
    def setScaleFactor(self, val:float, /) -> None:
        pass
    def setStyleName(self, val:str, /) -> None:
        pass
    def setTextColor(self, val:PyAx.AcColor, /) -> None:
        pass
    def setTextHeight(self, val:float, /) -> None:
        pass
    def setTextString(self, val:str, /) -> None:
        pass
    def setTextStyle(self, val:str, /) -> None:
        pass
    def styleName(self, /) -> str:
        pass
    def textColor(self, /) -> AcColor:
        pass
    def textHeight(self, /) -> float:
        pass
    def textString(self, /) -> str:
        pass
    def textStyle(self, /) -> str:
        pass
class AcadToolbar:
    def __getitem__(self, index: int, /) -> AcadToolbarItem:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addToolbarButton(self, index: int, name: str, helpstr: str, macro: str, flyoutButton:bool, /) -> AcadToolbarItem:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def count(self, /) -> int:
        pass
    def dock(self, val: PyAx.AcToolbarDockStatus, /) -> None:
        pass
    def dockStatus(self, /) -> AcToolbarDockStatus:
        pass
    def floatingRows(self, /) -> int:
        pass
    def height(self, /) -> int:
        pass
    def helpString(self, /) -> str:
        pass
    def isVisible(self, /) -> bool:
        pass
    def item(self, idx : int, /) -> AcadToolbarItem:
        pass
    def largeButtons(self, /) -> bool:
        pass
    def left(self, /) -> int:
        pass
    def name(self, /) -> str:
        pass
    def parent(self, /) -> AcadToolbars:
        pass
    def setFloat(self, top:int, left:int, numberFloatRows:int, /) -> None:
        pass
    def setFloatingRows(self, nRows:int, /) -> None:
        pass
    def setHelpString(self, helpString: str, /) -> None:
        pass
    def setLeft(self, left:int, /) -> None:
        pass
    def setName(self, name:str, /) -> None:
        pass
    def setTop(self, top:int, /) -> None:
        pass
    def setVisible(self, visible:bool, /) -> None:
        pass
    def tagString(self, /) -> str:
        pass
    def top(self, /) -> int:
        pass
    def width(self, /) -> int:
        pass
class AcadToolbarItem:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def attachToolbarToFlyout(self, menuGroupName: str, toolbarGroupName: str, /) -> None:
        pass
    def bitmaps(self, /) -> tuple:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def commandDisplayName(self, /) -> str:
        pass
    def getType(self, /) -> AcToolbarItemType:
        pass
    def helpString(self, /) -> str:
        pass
    def index(self, /) -> int:
        pass
    def macro(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def parent(self, /) -> AcadToolbar:
        pass
    def setBitmaps(self, smallIconName: str, largeIconName: str, /) -> None:
        pass
    def setCommandDisplayName(self, commandDisplayName: str, /) -> None:
        pass
    def setHelpString(self, helpString: str, /) -> None:
        pass
    def setMacro(self, macro: str, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
    def setTagString(self, tag: str, /) -> None:
        pass
    def tagString(self, /) -> str:
        pass
class AcadToolbars:
    def __getitem__(self, index: int, /) -> AcadToolbar:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, toolbarName:str, /) -> AcadToolbar:
        pass
    @staticmethod
    def className() -> str:
        pass
    def count(self, /) -> int:
        pass
    def item(self, idx : int, /) -> AcadToolbar:
        pass
    def largeButtons(self, /) -> bool:
        pass
    def parent(self, /) -> AcadMenuGroup:
        pass
    def setLargeButtons(self, largeButtons:bool, /) -> None:
        pass
class AcadTrace(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadTrace:
        pass
    @staticmethod
    def className() -> str:
        pass
    def coordinates(self, /) -> list:
        pass
    def normal(self, /) -> PyGe.Vector3d:
        pass
    def setCoordinates(self, coords:Iterable[PyGe.Point3d], /) -> None:
        pass
    def setNormal(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setThickness(self, val:float, /) -> None:
        pass
    def thickness(self, /) -> float:
        pass
class AcadUCS(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadUCS:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadUCSs(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadUCSs:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadUtility:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def angleFromXAxis(self, startPoint:PyGe.Point3d, endPoint:PyGe.Point3d, /) -> float:
        pass
    def angleToReal(self, angle:str, unit:PyAx.AcAngleUnits, /) -> float:
        pass
    def angleToString(self, angle:float, unit:PyAx.AcAngleUnits, precision:int, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def distanceToReal(self, dist:str, unit:PyAx.AcAngleUnits, /) -> float:
        pass
    @overload
    def getAngle(self, prompt: str, /) -> float: ...
    @overload
    def getAngle(self, basePoint:PyGe.Point3d, prompt: str, /) -> float: ...
    def getAngle(self, *args) -> float:
        pass
    def getCorner(self, point:PyGe.Point3d, prompt:str, /) -> PyGe.Point3d:
        pass
    def getDistance(self, point:PyGe.Point3d, prompt:str, /) -> float:
        pass
    def getEntity(self, prompt:str, /) -> tuple:
        pass
    def getInput(self, /) -> str:
        pass
    def getInteger(self, prompt:str, /) -> int:
        pass
    def getKeyword(self, prompt:str, /) -> str:
        pass
    def getObjectIdString(self, obj:PyAx.AcadEntity, bHex:bool, /) -> str:
        pass
    def getOrientation(self, point:PyGe.Point3d, prompt:str, /) -> float:
        pass
    @overload
    def getPoint(self, prompt: str, /) -> PyGe.Point3d: ...
    @overload
    def getPoint(self, basePoint:PyGe.Point3d, prompt: str, /) -> PyGe.Point3d: ...
    def getPoint(self, *args) -> PyGe.Point3d:
        pass
    def getReal(self, prompt:str, /) -> float:
        pass
    def getRemoteFile(self, URL:str, ignoreCache:bool, /) -> str:
        pass
    def getString(self, hasSpaces:int, prompt:str, /) -> str:
        pass
    def getSubEntity(self, prompt:str, /) -> tuple:
        pass
    def initializeUserInput(self, bits:int, keyWordList:str, /) -> None:
        pass
    def isRemoteFile(self, localFile:str, /) -> None:
        pass
    def isURL(self, URL:str, /) -> bool:
        pass
    def launchBrowserDialog(self, title:str, caption:str, URL:str, regkey:str, bnEnabled:bool, /) -> tuple:
        pass
    def polarPoint(self, point:PyGe.Point3d, angle:float, distance:float, /) -> PyGe.Point3d:
        pass
    def prompt(self, prompt:str, /) -> None:
        pass
    def putRemoteFile(self, URL:str, localFile:str, /) -> None:
        pass
    def realToString(self, real:str, unit:PyAx.AcAngleUnits, /) -> str:
        pass
    def sendModelessOperationEnded(self, context:str, /) -> None:
        pass
    def sendModelessOperationStart(self, context:str, /) -> None:
        pass
    def translateCoordinates(self, /) -> PyGe.Point3d:
        pass
class AcadView(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadView:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadViewport(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadViewport:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadViewports(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadViewports:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadViews(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadViews:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadXRecord(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadXRecord:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadXline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def basePoint(self, /) -> PyGe.Point3d:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadXline:
        pass
    @staticmethod
    def className() -> str:
        pass
    def directionVector(self, /) -> PyGe.Vector3d:
        pass
    def offset(self, val:float, /) -> list:
        pass
    def secondPoint(self, /) -> PyGe.Point3d:
        pass
    def setBasePoint(self, val:PyGe.Point3d, /) -> None:
        pass
    def setDirectionVector(self, val:PyGe.Vector3d, /) -> None:
        pass
    def setSecondPoint(self, val:PyGe.Point3d, /) -> None:
        pass
class ModelSpace(PyAx.AcadBlock):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> ModelSpace:
        pass
    @staticmethod
    def className() -> str:
        pass
class PaperSpace(PyAx.AcadBlock):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addPViewport(self, /) -> AcadPViewport:
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> PaperSpace:
        pass
    @staticmethod
    def className() -> str:
        pass
