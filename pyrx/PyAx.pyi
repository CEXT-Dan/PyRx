from __future__ import annotations
from typing import overload, Any, ClassVar, Self, TypeVar
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
acAlignPntAcquisitionAutomatic: AcAlignmentPointAcquisition  # 0
acAlignPntAcquisitionShiftToAcquire: AcAlignmentPointAcquisition  # 1
acAngular: AcDynamicBlockReferencePropertyUnitsType  # 1
acAny: AcBlockScaling  # 0
acArea: AcDynamicBlockReferencePropertyUnitsType  # 3
acAttributeModeConstant: AcAttributeMode  # 2
acAttributeModeInvisible: AcAttributeMode  # 1
acAttributeModeLockPosition: AcAttributeMode  # 16
acAttributeModeMultipleLine: AcAttributeMode  # 32
acAttributeModeNormal: AcAttributeMode  # 0
acAttributeModePreset: AcAttributeMode  # 8
acAttributeModeVerify: AcAttributeMode  # 4
acBaseMenuGroup: AcMenuGroupType  # 0
acBlue: AcColor  # 5
acByBlock: AcColor  # 0
acByLayer: AcColor  # 256
acColorMethodByACI: AcColorMethod  # 195
acColorMethodByBlock: AcColorMethod  # 193
acColorMethodByLayer: AcColorMethod  # 192
acColorMethodByRGB: AcColorMethod  # 194
acColorMethodForeground: AcColorMethod  # 197
acCyan: AcColor  # 4
acDemandLoadDisabled: AcXRefDemandLoad  # 0
acDemandLoadEnabled: AcXRefDemandLoad  # 1
acDemandLoadEnabledWithCopy: AcXRefDemandLoad  # 2
acDistance: AcDynamicBlockReferencePropertyUnitsType  # 2
acEdRepeatLastCommand: AcDrawingAreaSCMEdit  # 0
acEdSCM: AcDrawingAreaSCMEdit  # 1
acEnableSCM: AcDrawingAreaSCMCommand  # 2
acEnableSCMOptions: AcDrawingAreaSCMCommand  # 1
acEnter: AcDrawingAreaSCMCommand  # 0
acFontBold: AcTextFontStyle  # 2
acFontBoldItalic: AcTextFontStyle  # 3
acFontItalic: AcTextFontStyle  # 1
acFontRegular: AcTextFontStyle  # 0
acFullPreview: AcPreviewMode  # 1
acGreen: AcColor  # 3
acHatchPatternTypeCustomDefined: AcPatternType  # 2
acHatchPatternTypePreDefined: AcPatternType  # 1
acHatchPatternTypeUserDefined: AcPatternType  # 0
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
acKeyboardEntry: AcKeyboardPriority  # 1
acKeyboardEntryExceptScripts: AcKeyboardPriority  # 2
acKeyboardRunningObjSnap: AcKeyboardPriority  # 0
acLineNoArrow: AcLeaderType  # 0
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
acMagenta: AcColor  # 6
acMax: AcWindowState  # 3
acMenuFileCompiled: AcMenuFileType  # 0
acMenuFileSource: AcMenuFileType  # 1
acMenuItem: AcMenuItemType  # 0
acMenuSeparator: AcMenuItemType  # 1
acMenuSubMenu: AcMenuItemType  # 2
acMin: AcWindowState  # 2
acModelSpace: AcActiveSpace  # 1
acNative: AcSaveAsType  # 64
acNoUnits: AcDynamicBlockReferencePropertyUnitsType  # 0
acNorm: AcWindowState  # 1
acOQGraphics: AcOleQuality  # 2
acOQHighPhoto: AcOleQuality  # 4
acOQLineArt: AcOleQuality  # 0
acOQPhoto: AcOleQuality  # 3
acOQText: AcOleQuality  # 1
acPaperSpace: AcActiveSpace  # 0
acPartialMenuGroup: AcMenuGroupType  # 1
acPartialPreview: AcPreviewMode  # 0
acPreferenceClassic: AcKeyboardAccelerator  # 1
acPrinterAlertOnce: AcPrinterSpoolAlert  # 1
acPrinterAlwaysAlert: AcPrinterSpoolAlert  # 0
acPrinterNeverAlert: AcPrinterSpoolAlert  # 3
acPrinterNeverAlertLogOnce: AcPrinterSpoolAlert  # 2
acProxyBoundingBox: AcProxyImage  # 2
acProxyNotShow: AcProxyImage  # 0
acProxyShow: AcProxyImage  # 1
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
acRed: AcColor  # 1
acRepeatLastCommand: AcDrawingAreaSCMDefault  # 0
acSCM: AcDrawingAreaSCMDefault  # 1
acSectionGenerationDestinationFile: AcSectionGeneration  # 64
acSectionGenerationDestinationNewBlock: AcSectionGeneration  # 16
acSectionGenerationDestinationReplaceBlock: AcSectionGeneration  # 32
acSectionGenerationSourceAllObjects: AcSectionGeneration  # 1
acSectionGenerationSourceSelectedObjects: AcSectionGeneration  # 2
acSplineNoArrow: AcLeaderType  # 1
acSplineWithArrow: AcLeaderType  # 3
acToolbarButton: AcToolbarItemType  # 0
acToolbarControl: AcToolbarItemType  # 2
acToolbarDockBottom: AcToolbarDockStatus  # 1
acToolbarDockLeft: AcToolbarDockStatus  # 2
acToolbarDockRight: AcToolbarDockStatus  # 3
acToolbarDockTop: AcToolbarDockStatus  # 0
acToolbarFloating: AcToolbarDockStatus  # 4
acToolbarFlyout: AcToolbarItemType  # 3
acToolbarSeparator: AcToolbarItemType  # 1
acUniform: AcBlockScaling  # 1
acUnknown: AcSaveAsType  # -1
acWhite: AcColor  # 7
acYellow: AcColor  # 2
acZoomScaledAbsolute: AcZoomScaleType  # 0
acZoomScaledRelative: AcZoomScaleType  # 1
acZoomScaledRelativePSpace: AcZoomScaleType  # 2
class AcActiveSpace(_BoostPythonEnum):
    acPaperSpace: ClassVar[Self]  # 0
    acModelSpace: ClassVar[Self]  # 1
class AcAlignmentPointAcquisition(_BoostPythonEnum):
    acAlignPntAcquisitionAutomatic: ClassVar[Self]  # 0
    acAlignPntAcquisitionShiftToAcquire: ClassVar[Self]  # 1
class AcAttributeMode(_BoostPythonEnum):
    acAttributeModeNormal: ClassVar[Self]  # 0
    acAttributeModeInvisible: ClassVar[Self]  # 1
    acAttributeModeConstant: ClassVar[Self]  # 2
    acAttributeModeVerify: ClassVar[Self]  # 4
    acAttributeModePreset: ClassVar[Self]  # 8
    acAttributeModeLockPosition: ClassVar[Self]  # 16
    acAttributeModeMultipleLine: ClassVar[Self]  # 32
class AcBlockScaling(_BoostPythonEnum):
    acAny: ClassVar[Self]  # 0
    acUniform: ClassVar[Self]  # 1
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
class AcDynamicBlockReferencePropertyUnitsType(_BoostPythonEnum):
    acNoUnits: ClassVar[Self]  # 0
    acAngular: ClassVar[Self]  # 1
    acDistance: ClassVar[Self]  # 2
    acArea: ClassVar[Self]  # 3
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> Acad3DPolyline:
        pass
    @staticmethod
    def className() -> str:
        pass
class Acad3DSolid(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> Acad3DSolid:
        pass
    @staticmethod
    def className() -> str:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadArc:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadAttribute(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadAttribute:
        pass
    @staticmethod
    def className() -> str:
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
    def add3DMesh(self, M:int, N:int, points:list[PyGe.Point3d], /) -> AcadPolygonMesh:
        pass
    def add3DPoly(self, points:list[PyGe.Point3d], /) -> Acad3DPolyline:
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
    def addHatch(self, patternType:int, patternName:str, associativity:bool, /) -> AcadHatch:
        pass
    def addLeader(self, points:list[PyGe.Point3d], annotation:PyAx.AcadEntity, leaderType:PyAx.AcLeaderType, /) -> AcadLeader:
        pass
    def addLightWeightPolyline(self, points:list[PyGe.Point2d], /) -> AcadLWPolyline:
        pass
    def addLine(self, startPoint:PyGe.Point3d, endPoint:PyGe.Point3d, /) -> AcadLine:
        pass
    def addMInsertBlock(self, point:PyGe.Point3d, name:str, rotation:float, numRows:int, numCols:int, rowSpacing:int, rolumnSpacing:int, /) -> AcadMInsertBlock:
        pass
    def addMLeader(self, points:list[PyGe.Point3d], /) -> AcadMLeader:
        pass
    def addMLine(self, points:list[PyGe.Point3d], /) -> AcadMLine:
        pass
    def addMText(self, insertionPoint:PyGe.Point3d, width:float, textVal:str, /) -> AcadMText:
        pass
    def addPoint(self, point:PyGe.Point3d, /) -> AcadPoint:
        pass
    def addPolyfaceMesh(self, points:list[PyGe.Point3d], faces:list[int], /) -> AcadPolyfaceMesh:
        pass
    def addPolyline(self, points:list[PyGe.Point3d], /) -> AcadPolyline:
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
    def addSpline(self, points:list[PyGe.Point3d], startTangent:PyGe.Vector3d, endTangent:PyGe.Vector3d, /) -> AcadSpline:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadBlockReference:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadCircle(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadCircle:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadDatabase:
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
    def modelSpace(self, /) -> ModelSpace:
        pass
    def paperSpace(self, /) -> PaperSpace:
        pass
    def summaryInfo(self, /) -> AcadSummaryInfo:
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
    def close(self, saveChanges:bool=False, fileName:str=None, /) -> None:
        pass
    def database(self, /) -> AcadDatabase:
        pass
    def name(self, /) -> str:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadEllipse:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadEntity(PyAx.AcadObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadEntity:
        pass
    @staticmethod
    def className() -> str:
        pass
    def setTrueColor(self, trueColor: PyAx.AcadAcCmColor, /) -> None:
        pass
    def transformBy(self, xform: PyGe.Matrix3d, /) -> None:
        pass
    def trueColor(self, /) -> AcadAcCmColor:
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
class AcadHatch(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadHatch:
        pass
    @staticmethod
    def className() -> str:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLWPolyline:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadLeader(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLeader:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadLine(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadLine:
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
class AcadMLeader(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMLeader:
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
class AcadMText(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadMText:
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
    def database(self, /) -> AcadDatabase:
        pass
    def delete(self, /) -> None:
        pass
    def erase(self, /) -> None:
        pass
    def getXData(self, appName: str, /) -> list:
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
    def setXdata(self, /) -> None:
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
class AcadPolygonMesh(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPolygonMesh:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadPolyline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadPolyline:
        pass
    @staticmethod
    def className() -> str:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRasterImage:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadRay(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRay:
        pass
    @staticmethod
    def className() -> str:
        pass
class AcadRegion(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadRegion:
        pass
    @staticmethod
    def className() -> str:
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
class AcadSpline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadSpline:
        pass
    @staticmethod
    def className() -> str:
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
class AcadText(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadText:
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
class AcadXline(PyAx.AcadEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> AcadXline:
        pass
    @staticmethod
    def className() -> str:
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
    @staticmethod
    def cast(otherObject: PyAx.AcadObject, /) -> PaperSpace:
        pass
    @staticmethod
    def className() -> str:
        pass
