#include "stdafx.h"
#include "PyAcAx.h"
#include "PyAcadObject.h"
#include "PyAcadDbObject.h"
#include "PyAcadEntity.h"
#include "PyAcadApplication.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(PyAx)
{
    makePyAcadAcCmColorWrapper();
    makePyAcadHyperlinkWrapper();
    makePyAcadHyperlinksWrapper();
    makePyAcadSectionTypeSettingsWrapper();
    makePyAcadDatabasePreferencesWrapper();
    makePyAcadPreferencesFilesWrapper();
    makePyAcadPreferencesDisplayWrapper();
    makePyAcadPreferencesOpenSaveWrapper();
    makePyAcadPreferencesOutputWrapper();
    makePyAcadPreferencesSystemWrapper();
    makePyAcadPreferencesUserWrapper();
    makePyAcadPreferencesDraftingWrapper();
    makePyAcadPreferencesSelectionWrapper();
    makePyAcadPreferencesProfilesWrapper();
    makePyAcadPreferencesWrapper();
    makePyAcadSummaryInfoWrapper();
    makePyAcadDynamicBlockReferencePropertyWrapper();
    makePyAcadIdPairWrapper();
    makePyAcadPlotWrapper();
    makePyAcadMenuBarWrapper();
    makePyAcadMenuGroupWrapper();
    makePyAcadMenuGroupsWrapper();
    makePyAcadPopupMenuItemWrapper();
    makePyAcadPopupMenuWrapper();
    makePyAcadPopupMenusWrapper();
    makePyAcadToolbarsWrapper();
    makePyAcadToolbarItemWrapper();
    makePyAcadToolbarWrapper();


    makePyAcadStateWrapper();
    makePyAcadObjectWrapper();
    makePyAcadBlocksWrapper();
    makePyAcadEntityWrapper();
    makePyAcadDatabaseWrapper();
    makePyAcadDocumentWrapper();
    makePyAcadDocumentsWrapper();
    makePyAcadApplicationWrapper();

    makePyAcadBlockWrapper();
    makePyModelSpaceWrapper();
    makePyPaperSpaceWrapper();

    makePyAcad3DFaceWrapper();
    makePyAcadPolygonMeshWrapper();
    makePyAcad3DPolylineWrapper();
    makePyAcadArcWrapper();
    makePyAcadAttributeWrapper();
    makePyAcadRegionWrapper();
    makePyAcad3DSolidWrapper();
    makePyAcadCircleWrapper();
    makePyAcadDimensionWrapper();
    makePyAcadDimAlignedWrapper();
    makePyAcadDimAngularWrapper();
    makePyAcadDimDiametricWrapper();
    makePyAcadDimRotatedWrapper();
    makePyAcadDimOrdinateWrapper();
    makePyAcadDimRadialWrapper();
    makePyAcadDimArcLengthWrapper();
    makePyAcadDimRadialLargeWrapper();
    makePyAcadDim3PointAngularWrapper();
    makePyAcadEllipseWrapper();
    makePyAcadLeaderWrapper();
    makePyAcadMTextWrapper();
    makePyAcadPointWrapper();
    makePyAcadLWPolylineWrapper();
    makePyAcadPolylineWrapper();
    makePyAcadRayWrapper();
    makePyAcadShapeWrapper();
    makePyAcadSolidWrapper();
    makePyAcadSplineWrapper();
    makePyAcadTextWrapper();
    makePyAcadToleranceWrapper();
    makePyAcadTraceWrapper();
    makePyAcadXlineWrapper();
    makePyAcadBlockReferenceWrapper();
    makePyAcadMInsertBlockWrapper();
    makePyAcadExternalReferenceWrapper();
    makePyAcadHatchWrapper();
    makePyAcadRasterImageWrapper();
    makePyAcadLineWrapper();
    makePyAcadPolyfaceMeshWrapper();
    makePyAcadMLineWrapper();
    makePyAcadTableWrapper();
    makePyAcadSectionWrapper();
    makePyAcadMLeaderWrapper();

    enum_<PyAcSectionGeneration>("AcSectionGeneration")
        .value("acSectionGenerationSourceAllObjects", PyAcSectionGeneration::pyacSectionGenerationSourceAllObjects)
        .value("acSectionGenerationSourceSelectedObjects", PyAcSectionGeneration::pyacSectionGenerationSourceSelectedObjects)
        .value("acSectionGenerationDestinationNewBlock", PyAcSectionGeneration::pyacSectionGenerationDestinationNewBlock)
        .value("acSectionGenerationDestinationReplaceBlock", PyAcSectionGeneration::pyacSectionGenerationDestinationReplaceBlock)
        .value("acSectionGenerationDestinationFile", PyAcSectionGeneration::pyacSectionGenerationDestinationFile)
        .export_values()
        ;

    enum_<PyAcWindowState>("AcWindowState")
        .value("acNorm", PyAcWindowState::pyacNorm)
        .value("acMin", PyAcWindowState::pyacMin)
        .value("acMax", PyAcWindowState::pyacMax)
        .export_values()
        ;

    enum_<PyAcColorMethod>("AcColorMethod")
        .value("acColorMethodByLayer", PyAcColorMethod::pyacColorMethodByLayer)
        .value("acColorMethodByBlock", PyAcColorMethod::pyacColorMethodByBlock)
        .value("acColorMethodByRGB", PyAcColorMethod::pyacColorMethodByRGB)
        .value("acColorMethodByACI", PyAcColorMethod::pyacColorMethodByACI)
        .value("acColorMethodForeground", PyAcColorMethod::pyacColorMethodForeground)
        .export_values()
        ;

    enum_<PyAcColor>("AcColor")
        .value("acByBlock", PyAcColor::pyacByBlock)
        .value("acRed", PyAcColor::pyacRed)
        .value("acYellow", PyAcColor::pyacYellow)
        .value("acGreen", PyAcColor::pyacGreen)
        .value("acCyan", PyAcColor::pyacCyan)
        .value("acBlue", PyAcColor::pyacBlue)
        .value("acMagenta", PyAcColor::pyacMagenta)
        .value("acWhite", PyAcColor::pyacWhite)
        .value("acByLayer", PyAcColor::pyacByLayer)
        .export_values()
        ;

    enum_<PyAcZoomScaleType>("AcZoomScaleType")
        .value("acZoomScaledAbsolute", PyAcZoomScaleType::pyacZoomScaledAbsolute)
        .value("acZoomScaledRelative", PyAcZoomScaleType::pyacZoomScaledRelative)
        .value("acZoomScaledRelativePSpace", PyAcZoomScaleType::pyacZoomScaledRelativePSpace)
        .export_values()
        ;

    enum_<PyAcActiveSpace>("AcActiveSpace")
        .value("acPaperSpace", PyAcActiveSpace::pyacPaperSpace)
        .value("acModelSpace", PyAcActiveSpace::pyacModelSpace)
        .export_values()
        ;

    enum_<PyAcMenuGroupType>("AcMenuGroupType")
        .value("acBaseMenuGroup", PyAcMenuGroupType::pyacBaseMenuGroup)
        .value("acPartialMenuGroup", PyAcMenuGroupType::pyacPartialMenuGroup)
        .export_values()
        ;

    enum_<PyAcMenuFileType>("AcMenuFileType")
        .value("acMenuFileCompiled", PyAcMenuFileType::pyacMenuFileCompiled)
        .value("acMenuFileSource", PyAcMenuFileType::pyacMenuFileSource)
        .export_values()
        ;

    enum_<PyAcToolbarDockStatus>("AcToolbarDockStatus")
        .value("acToolbarDockTop", PyAcToolbarDockStatus::pyacToolbarDockTop)
        .value("acToolbarDockBottom", PyAcToolbarDockStatus::pyacToolbarDockBottom)
        .value("acToolbarDockLeft", PyAcToolbarDockStatus::pyacToolbarDockLeft)
        .value("acToolbarDockRight", PyAcToolbarDockStatus::pyacToolbarDockRight)
        .value("acToolbarFloating", PyAcToolbarDockStatus::pyacToolbarFloating)
        .export_values()
        ;

    enum_<PyAcToolbarItemType>("AcToolbarItemType")
        .value("acToolbarButton", PyAcToolbarItemType::pyacToolbarButton)
        .value("acToolbarSeparator", PyAcToolbarItemType::pyacToolbarSeparator)
        .value("acToolbarControl", PyAcToolbarItemType::pyacToolbarControl)
        .value("acToolbarFlyout", PyAcToolbarItemType::pyacToolbarFlyout)
        .export_values()
        ;

    enum_<PyAcMenuItemType>("AcMenuItemType")
        .value("acMenuItem", PyAcMenuItemType::pyacMenuItem)
        .value("acMenuSeparator", PyAcMenuItemType::pyacMenuSeparator)
        .value("acMenuSubMenu", PyAcMenuItemType::pyacMenuSubMenu)
        .export_values()
        ;

    enum_<PyAcPreviewMode>("AcPreviewMode")
        .value("acPartialPreview", PyAcPreviewMode::pyacPartialPreview)
        .value("acFullPreview", PyAcPreviewMode::pyacFullPreview)
        .export_values()
        ;

    enum_<PyAcAlignmentPointAcquisition>("AcAlignmentPointAcquisition")
        .value("acAlignPntAcquisitionAutomatic", PyAcAlignmentPointAcquisition::pyacAlignPntAcquisitionAutomatic)
        .value("acAlignPntAcquisitionShiftToAcquire", PyAcAlignmentPointAcquisition::pyacAlignPntAcquisitionShiftToAcquire)
        .export_values()
        ;

    enum_<PyAcKeyboardAccelerator>("AcKeyboardAccelerator")
        .value("acPreferenceClassic", PyAcKeyboardAccelerator::pyacPreferenceClassic)
        .value("acPreferenceClassic", PyAcKeyboardAccelerator::pyacPreferenceCustom)
        .export_values()
        ;

    enum_<PyAcKeyboardPriority>("AcKeyboardPriority")
        .value("acKeyboardRunningObjSnap", PyAcKeyboardPriority::pyacKeyboardRunningObjSnap)
        .value("acKeyboardEntry", PyAcKeyboardPriority::pyacKeyboardEntry)
        .value("acKeyboardEntryExceptScripts", PyAcKeyboardPriority::pyacKeyboardEntryExceptScripts)
        .export_values()
        ;

    enum_<PyAcInsertUnits>("AcInsertUnits")
        .value("acInsertUnitsUnitless", PyAcInsertUnits::pyacInsertUnitsUnitless)
        .value("acInsertUnitsInches", PyAcInsertUnits::pyacInsertUnitsInches)
        .value("acInsertUnitsFeet", PyAcInsertUnits::pyacInsertUnitsFeet)
        .value("acInsertUnitsMiles", PyAcInsertUnits::pyacInsertUnitsMiles)
        .value("acInsertUnitsMillimeters", PyAcInsertUnits::pyacInsertUnitsMillimeters)
        .value("acInsertUnitsCentimeters", PyAcInsertUnits::pyacInsertUnitsCentimeters)
        .value("acInsertUnitsMeters", PyAcInsertUnits::pyacInsertUnitsMeters)
        .value("acInsertUnitsKilometers", PyAcInsertUnits::pyacInsertUnitsKilometers)
        .value("acInsertUnitsMicroinches", PyAcInsertUnits::pyacInsertUnitsMicroinches)
        .value("acInsertUnitsMils", PyAcInsertUnits::pyacInsertUnitsMils)
        .value("acInsertUnitsYards", PyAcInsertUnits::pyacInsertUnitsYards)
        .value("acInsertUnitsAngstroms", PyAcInsertUnits::pyacInsertUnitsAngstroms)
        .value("acInsertUnitsNanometers", PyAcInsertUnits::pyacInsertUnitsNanometers)
        .value("acInsertUnitsMicrons", PyAcInsertUnits::pyacInsertUnitsMicrons)
        .value("acInsertUnitsDecimeters", PyAcInsertUnits::pyacInsertUnitsDecimeters)
        .value("acInsertUnitsDecameters", PyAcInsertUnits::pyacInsertUnitsDecameters)
        .value("acInsertUnitsHectometers", PyAcInsertUnits::pyacInsertUnitsHectometers)
        .value("acInsertUnitsGigameters", PyAcInsertUnits::pyacInsertUnitsGigameters)
        .value("acInsertUnitsAstronomicalUnits", PyAcInsertUnits::pyacInsertUnitsAstronomicalUnits)
        .value("acInsertUnitsLightYears", PyAcInsertUnits::pyacInsertUnitsLightYears)
        .value("acInsertUnitsParsecs", PyAcInsertUnits::pyacInsertUnitsParsecs)
        .value("acInsertUnitsUSSurveyFeet", PyAcInsertUnits::pyacInsertUnitsUSSurveyFeet)
        .value("acInsertUnitsUSSurveyInch", PyAcInsertUnits::pyacInsertUnitsUSSurveyInch)
        .value("acInsertUnitsUSSurveyYard", PyAcInsertUnits::pyacInsertUnitsUSSurveyYard)
        .value("acInsertUnitsUSSurveyMile", PyAcInsertUnits::pyacInsertUnitsUSSurveyMile)
        .export_values()
        ;

    enum_<PyAcDrawingAreaSCMDefault>("AcDrawingAreaSCMDefault")
        .value("acRepeatLastCommand", PyAcDrawingAreaSCMDefault::pyacRepeatLastCommand)
        .value("acSCM", PyAcDrawingAreaSCMDefault::pyacSCM)
        .export_values()
        ;

    enum_<PyAcDrawingAreaSCMEdit>("AcDrawingAreaSCMEdit")
        .value("acEdRepeatLastCommand", PyAcDrawingAreaSCMEdit::pyacEdRepeatLastCommand)
        .value("acEdSCM", PyAcDrawingAreaSCMEdit::pyacEdSCM)
        .export_values()
        ;

    enum_<PyAcDrawingAreaSCMCommand>("AcDrawingAreaSCMCommand")
        .value("acEnter", PyAcDrawingAreaSCMCommand::pyacEnter)
        .value("acEnableSCMOptions", PyAcDrawingAreaSCMCommand::pyacEnableSCMOptions)
        .value("acEnableSCM", PyAcDrawingAreaSCMCommand::pyacEnableSCM)
        .export_values()
        ;

    enum_<PyAcPrinterSpoolAlert>("AcPrinterSpoolAlert")
        .value("acPrinterAlwaysAlert", PyAcPrinterSpoolAlert::pyacPrinterAlwaysAlert)
        .value("acPrinterAlertOnce", PyAcPrinterSpoolAlert::pyacPrinterAlertOnce)
        .value("acPrinterNeverAlertLogOnce", PyAcPrinterSpoolAlert::pyacPrinterNeverAlertLogOnce)
        .value("acPrinterNeverAlert", PyAcPrinterSpoolAlert::pyacPrinterNeverAlert)
        .export_values()
        ;

    enum_<PyAcOleQuality>("AcOleQuality")
        .value("acOQLineArt", PyAcOleQuality::pyacOQLineArt)
        .value("acOQText", PyAcOleQuality::pyacOQText)
        .value("acOQGraphics", PyAcOleQuality::pyacOQGraphics)
        .value("acOQPhoto", PyAcOleQuality::pyacOQPhoto)
        .value("acOQHighPhoto", PyAcOleQuality::pyacOQHighPhoto)
        .export_values()
        ;

    enum_<PyAcXRefDemandLoad>("AcXRefDemandLoad")
        .value("acDemandLoadDisabled", PyAcXRefDemandLoad::pyacDemandLoadDisabled)
        .value("acDemandLoadEnabled", PyAcXRefDemandLoad::pyacDemandLoadEnabled)
        .value("acDemandLoadEnabledWithCopy", PyAcXRefDemandLoad::pyacDemandLoadEnabledWithCopy)
        .export_values()
        ;

    enum_<PyAcProxyImage>("AcProxyImage")
        .value("acProxyNotShow", PyAcProxyImage::pyacProxyNotShow)
        .value("acProxyShow", PyAcProxyImage::pyacProxyShow)
        .value("acProxyBoundingBox", PyAcProxyImage::pyacProxyBoundingBox)
        .export_values()
        ;

    enum_<PyAcSaveAsType>("AcSaveAsType")
        .value("acUnknown", PyAcSaveAsType::pyacUnknown)
        .value("acR12_dxf", PyAcSaveAsType::pyacR12_dxf)
        .value("acR13_dwg", PyAcSaveAsType::pyacR13_dwg)
        .value("acR13_dxf", PyAcSaveAsType::pyacR13_dxf)
        .value("acR14_dwg", PyAcSaveAsType::pyacR14_dwg)
        .value("acR14_dxf", PyAcSaveAsType::pyacR14_dxf)
        .value("ac2000_dwg", PyAcSaveAsType::pyac2000_dwg)
        .value("ac2000_dxf", PyAcSaveAsType::pyac2000_dxf)
        .value("ac2000_Template", PyAcSaveAsType::pyac2000_Template)
        .value("ac2004_dwg", PyAcSaveAsType::pyac2004_dwg)
        .value("ac2004_dxf", PyAcSaveAsType::pyac2004_dxf)
        .value("ac2004_Template", PyAcSaveAsType::pyac2004_Template)
        .value("ac2007_dwg", PyAcSaveAsType::pyac2007_dwg)
        .value("ac2007_dxf", PyAcSaveAsType::pyac2007_dxf)
        .value("ac2007_Template", PyAcSaveAsType::pyac2007_Template)
        .value("ac2010_dwg", PyAcSaveAsType::pyac2010_dwg)
        .value("ac2010_dxf", PyAcSaveAsType::pyac2010_dxf)
        .value("ac2010_Template", PyAcSaveAsType::pyac2010_Template)
        .value("ac2013_dwg", PyAcSaveAsType::pyac2013_dwg)
        .value("ac2013_dxf", PyAcSaveAsType::pyac2013_dxf)
        .value("ac2013_Template", PyAcSaveAsType::pyac2013_Template)
        .value("ac2018_dwg", PyAcSaveAsType::pyac2018_dwg)
        .value("ac2018_dxf", PyAcSaveAsType::pyac2018_dxf)
        .value("ac2018_Template", PyAcSaveAsType::pyac2018_Template)
        .value("acNative", PyAcSaveAsType::pyacNative)
        .value("acR15_dwg", PyAcSaveAsType::pyacR15_dwg)
        .value("acR15_dxf", PyAcSaveAsType::pyacR15_dxf)
        .value("acR15_Template", PyAcSaveAsType::pyacR15_Template)
        .value("acR18_dwg", PyAcSaveAsType::pyacR18_dwg)
        .value("acR18_dxf", PyAcSaveAsType::pyacR18_dxf)
        .value("acR18_Template", PyAcSaveAsType::pyacR18_Template)
        .export_values()
        ;

    enum_<PyAcTextFontStyle>("AcTextFontStyle")
        .value("acFontRegular", PyAcTextFontStyle::pyacFontRegular)
        .value("acFontItalic", PyAcTextFontStyle::pyacFontItalic)
        .value("acFontBold", PyAcTextFontStyle::pyacFontBold)
        .value("acFontBoldItalic", PyAcTextFontStyle::pyacFontBoldItalic)
        .export_values()
        ;

    enum_<PyAcLineWeight>("AcLineWeight")
        .value("acLnWt000", PyAcLineWeight::pyacLnWt000)
        .value("acLnWt005", PyAcLineWeight::pyacLnWt005)
        .value("acLnWt009", PyAcLineWeight::pyacLnWt009)
        .value("acLnWt013", PyAcLineWeight::pyacLnWt013)
        .value("acLnWt015", PyAcLineWeight::pyacLnWt015)
        .value("acLnWt018", PyAcLineWeight::pyacLnWt018)
        .value("acLnWt020", PyAcLineWeight::pyacLnWt020)
        .value("acLnWt025", PyAcLineWeight::pyacLnWt025)
        .value("acLnWt030", PyAcLineWeight::pyacLnWt030)
        .value("acLnWt035", PyAcLineWeight::pyacLnWt035)
        .value("acLnWt040", PyAcLineWeight::pyacLnWt040)
        .value("acLnWt050", PyAcLineWeight::pyacLnWt050)
        .value("acLnWt053", PyAcLineWeight::pyacLnWt053)
        .value("acLnWt060", PyAcLineWeight::pyacLnWt060)
        .value("acLnWt070", PyAcLineWeight::pyacLnWt070)
        .value("acLnWt080", PyAcLineWeight::pyacLnWt080)
        .value("acLnWt090", PyAcLineWeight::pyacLnWt090)
        .value("acLnWt100", PyAcLineWeight::pyacLnWt100)
        .value("acLnWt106", PyAcLineWeight::pyacLnWt106)
        .value("acLnWt120", PyAcLineWeight::pyacLnWt120)
        .value("acLnWt140", PyAcLineWeight::pyacLnWt140)
        .value("acLnWt158", PyAcLineWeight::pyacLnWt158)
        .value("acLnWt200", PyAcLineWeight::pyacLnWt200)
        .value("acLnWt211", PyAcLineWeight::pyacLnWt211)
        .value("acLnWtByLayer", PyAcLineWeight::pyacLnWtByLayer)
        .value("acLnWtByBlock", PyAcLineWeight::pyacLnWtByBlock)
        .value("acLnWtByLwDefault", PyAcLineWeight::pyacLnWtByLwDefault)
        .export_values()
        ;

    enum_<PyAcPatternType>("AcPatternType")
        .value("acHatchPatternTypeUserDefined", PyAcPatternType::pyacHatchPatternTypeUserDefined)
        .value("acHatchPatternTypePreDefined", PyAcPatternType::pyacHatchPatternTypePreDefined)
        .value("acHatchPatternTypeCustomDefined", PyAcPatternType::pyacHatchPatternTypeCustomDefined)
        .export_values()
        ;

    enum_<PyAcDynamicBlockReferencePropertyUnitsType>("AcDynamicBlockReferencePropertyUnitsType")
        .value("acNoUnits", PyAcDynamicBlockReferencePropertyUnitsType::pyacNoUnits)
        .value("acAngular", PyAcDynamicBlockReferencePropertyUnitsType::pyacAngular)
        .value("acDistance", PyAcDynamicBlockReferencePropertyUnitsType::pyacDistance)
        .value("acArea", PyAcDynamicBlockReferencePropertyUnitsType::pyacArea)
        .export_values()
        ;

    enum_<PyAcAttributeMode>("AcAttributeMode")
        .value("acAttributeModeNormal", PyAcAttributeMode::pyacAttributeModeNormal)
        .value("acAttributeModeInvisible", PyAcAttributeMode::pyacAttributeModeInvisible)
        .value("acAttributeModeConstant", PyAcAttributeMode::pyacAttributeModeConstant)
        .value("acAttributeModeVerify", PyAcAttributeMode::pyacAttributeModeVerify)
        .value("acAttributeModePreset", PyAcAttributeMode::pyacAttributeModePreset)
        .value("acAttributeModeLockPosition", PyAcAttributeMode::pyacAttributeModeLockPosition)
        .value("acAttributeModeMultipleLine", PyAcAttributeMode::pyacAttributeModeMultipleLine)
        .export_values()
        ;

    enum_<PyAcLeaderType>("AcLeaderType")
        .value("acLineNoArrow", PyAcLeaderType::pyacLineNoArrow)
        .value("acSplineNoArrow", PyAcLeaderType::pyacSplineNoArrow)
        .value("acLineWithArrow", PyAcLeaderType::pyacLineWithArrow)
        .value("acSplineWithArrow", PyAcLeaderType::pyacSplineWithArrow)
        .export_values()
        ;

    enum_<PyAcBlockScaling>("AcBlockScaling")
        .value("acAny", PyAcBlockScaling::pyacAny)
        .value("acUniform", PyAcBlockScaling::pyacUniform)
        .export_values()
        ;

    enum_<PyAcExtendOption>("AcExtendOption")
        .value("acExtendNone", PyAcExtendOption::pyacExtendNone)
        .value("acExtendThisEntity", PyAcExtendOption::pyacExtendThisEntity)
        .value("acExtendOtherEntity", PyAcExtendOption::pyacExtendOtherEntity)
        .value("acExtendBoth", PyAcExtendOption::pyacExtendBoth)
        .export_values()
        ;


}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}
