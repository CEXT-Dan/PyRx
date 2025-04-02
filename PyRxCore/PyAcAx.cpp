#include "stdafx.h"
#include "PyAcAx.h"
#include "PyAcadObject.h"
#include "PyAcadDbObject.h"
#include "PyAcadEntity.h"
#include "PyAcadDimension.h"
#include "PyAcadTable.h"
#include "PyAcadApplication.h"
using namespace boost::python;

static BOOST_PYTHON_MODULE(PyAx)
{
    makePyAcadUtilityWrapper();
    makePyAcadSecurityParamsWrapper();
    makePyAcadSelectionSetWrapper();
    makePyAcadSelectionSetsWrapper();
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
    makePyAcadPlotConfigurationWrapper();
    makePyAcadLayoutWrapper();
    makePyAcadSectionSettingsWrapper();
    makePyAcadViewWrapper();
    makePyAcadViewsWrapper();
    makePyAcadGroupWrapper();
    makePyAcadGroupsWrapper();
    makePyAcadDimStyleWrapper();
    makePyAcadDimStylesWrapper();
    makePyAcadLayerWrapper();
    makePyAcadLayersWrapper();
    makePyAcadLineTypeWrapper();
    makePyAcadLineTypesWrapper();
    makePyAcadXRecordWrapper();
    makePyAcadDictionaryWrapper();
    makePyAcadDictionariesWrapper();
    makePyAcadRegisteredApplicationWrapper();
    makePyAcadRegisteredApplicationsWrapper();
    makePyAcadTextStyleWrapper();
    makePyAcadTextStylesWrapper();
    makePyAcadUCSWrapper();
    makePyAcadUCSsWrapper();
    makePyAcadViewportWrapper();
    makePyAcadViewportsWrapper();
    makePyAcadPlotConfigurationsWrapper();
    makePyAcadSectionManagerWrapper();
    makePyAcadMaterialWrapper();
    makePyAcadMaterialsWrapper();
    makePyAcadTableStyleWrapper();
    makePyAcadMLeaderStyleWrapper();
    makePyAcadLayoutsWrapper();
    makePyAcadSortentsTableWrapper();
    makePyAcadBlockWrapper();
    makePyAcadBlocksWrapper();
    makePyAcadEntityWrapper();
    makePyAcadDatabaseWrapper();
    makePyAcadDocumentWrapper();
    makePyAcadDocumentsWrapper();
    makePyAcadApplicationWrapper();
    makePyModelSpaceWrapper();
    makePyPaperSpaceWrapper();
    makePyAcadPViewportWrapper();
    makePyAcad3DFaceWrapper();
    makePyAcadPolygonMeshWrapper();
    makePyAcad3DPolylineWrapper();
    makePyAcadArcWrapper();
    makePyAcadAttributeWrapper();
    makePyAcadAttributeReferenceWrapper();
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

    enum_<PyAcRegenType>("AcRegenType")
        .value("acActiveViewport", PyAcRegenType::pyacActiveViewport)
        .value("acAllViewports", PyAcRegenType::pyacAllViewports)
        .export_values()
        ;

    enum_<PyAcSelect>("AcSelect")
        .value("acSelectionSetWindow", PyAcSelect::pyacSelectionSetWindow)
        .value("acSelectionSetCrossing", PyAcSelect::pyacSelectionSetCrossing)
        .value("acSelectionSetFence", PyAcSelect::pyacSelectionSetFence)
        .value("acSelectionSetLast", PyAcSelect::pyacSelectionSetLast)
        .value("acSelectionSetAll", PyAcSelect::pyacSelectionSetAll)
        .value("acSelectionSetWindowPolygon", PyAcSelect::pyacSelectionSetWindowPolygon)
        .value("acSelectionSetCrossingPolygon", PyAcSelect::pyacSelectionSetCrossingPolygon)
        .export_values()
        ;

    enum_<PyAcAngleUnits>("AcAngleUnits")
        .value("acDegrees", PyAcAngleUnits::pyacDegrees)
        .value("acDegreeMinuteSeconds", PyAcAngleUnits::pyacDegreeMinuteSeconds)
        .value("acGrads", PyAcAngleUnits::pyacGrads)
        .value("acRadians", PyAcAngleUnits::pyacRadians)
        .export_values()
        ;
    enum_<PyAcUnits>("AcUnits")
        .value("acDefaultUnits", PyAcUnits::pyacDefaultUnits)
        .value("acScientific", PyAcUnits::pyacScientific)
        .value("acDecimal", PyAcUnits::pyacDecimal)
        .value("acEngineering", PyAcUnits::pyacEngineering)
        .value("acArchitectural", PyAcUnits::pyacArchitectural)
        .value("acFractional", PyAcUnits::pyacFractional)
        .export_values()
        ;

    enum_<PyAcCoordinateSystem>("AcCoordinateSystem")
        .value("acWorld", PyAcCoordinateSystem::pyacWorld)
        .value("acUCS", PyAcCoordinateSystem::pyacUCS)
        .value("acDisplayDCS", PyAcCoordinateSystem::pyacDisplayDCS)
        .value("acPaperSpaceDCS", PyAcCoordinateSystem::pyacPaperSpaceDCS)
        .value("acOCS", PyAcCoordinateSystem::pyacOCS)
        .export_values()
        ;

    enum_<PyAcViewportScale>("AcViewportScale")
        .value("acVpScaleToFit", PyAcViewportScale::pyacVpScaleToFit)
        .value("acVpCustomScale", PyAcViewportScale::pyacVpCustomScale)
        .value("acVp1_1", PyAcViewportScale::pyacVp1_1)
        .value("acVp1_2", PyAcViewportScale::pyacVp1_2)
        .value("acVp1_4", PyAcViewportScale::pyacVp1_4)
        .value("acVp1_5", PyAcViewportScale::pyacVp1_5)
        .value("acVp1_8", PyAcViewportScale::pyacVp1_8)
        .value("acVp1_10", PyAcViewportScale::pyacVp1_10)
        .value("acVp1_16", PyAcViewportScale::pyacVp1_16)
        .value("acVp1_20", PyAcViewportScale::pyacVp1_20)
        .value("acVp1_30", PyAcViewportScale::pyacVp1_30)
        .value("acVp1_40", PyAcViewportScale::pyacVp1_40)
        .value("acVp1_50", PyAcViewportScale::pyacVp1_50)
        .value("acVp1_100", PyAcViewportScale::pyacVp1_100)
        .value("acVp2_1", PyAcViewportScale::pyacVp2_1)
        .value("acVp4_1", PyAcViewportScale::pyacVp4_1)
        .value("acVp8_1", PyAcViewportScale::pyacVp8_1)
        .value("acVp10_1", PyAcViewportScale::pyacVp10_1)
        .value("acVp100_1", PyAcViewportScale::pyacVp100_1)
        .value("acVp1_128in_1ft", PyAcViewportScale::pyacVp1_128in_1ft)
        .value("acVp1_64in_1ft", PyAcViewportScale::pyacVp1_64in_1ft)
        .value("acVp1_32in_1ft", PyAcViewportScale::pyacVp1_32in_1ft)
        .value("acVp1_16in_1ft", PyAcViewportScale::pyacVp1_16in_1ft)
        .value("acVp3_32in_1ft", PyAcViewportScale::pyacVp3_32in_1ft)
        .value("acVp1_8in_1ft", PyAcViewportScale::pyacVp1_8in_1ft)
        .value("acVp3_16in_1ft", PyAcViewportScale::pyacVp3_16in_1ft)
        .value("acVp1_4in_1ft", PyAcViewportScale::pyacVp1_4in_1ft)
        .value("acVp3_8in_1ft", PyAcViewportScale::pyacVp3_8in_1ft)
        .value("acVp1_2in_1ft", PyAcViewportScale::pyacVp1_2in_1ft)
        .value("acVp3_4in_1ft", PyAcViewportScale::pyacVp3_4in_1ft)
        .value("acVp1in_1ft", PyAcViewportScale::pyacVp1in_1ft)
        .value("acVp1and1_2in_1ft", PyAcViewportScale::pyacVp1and1_2in_1ft)
        .value("acVp3in_1ft", PyAcViewportScale::pyacVp3in_1ft)
        .value("acVp6in_1ft", PyAcViewportScale::pyacVp6in_1ft)
        .value("acVp1ft_1ft", PyAcViewportScale::pyacVp1ft_1ft)
        .export_values()
        ;

    enum_<PyAcPolymeshType>("AcPolymeshType")
        .value("acSimpleMesh", PyAcPolymeshType::pyacSimpleMesh)
        .value("acQuadSurfaceMesh", PyAcPolymeshType::pyacQuadSurfaceMesh)
        .value("acCubicSurfaceMesh", PyAcPolymeshType::pyacCubicSurfaceMesh)
        .value("acBezierSurfaceMesh", PyAcPolymeshType::pyacBezierSurfaceMesh)
        .export_values()
        ;

    enum_<PyAc3DPolylineType>("Ac3DPolylineType")
        .value("acSimple3DPoly", PyAc3DPolylineType::pyacSimple3DPoly)
        .value("acQuadSpline3DPoly", PyAc3DPolylineType::pyacQuadSpline3DPoly)
        .value("acCubicSpline3DPoly", PyAc3DPolylineType::pyacCubicSpline3DPoly)
        .export_values()
        ;

    enum_<PyAcAlignment>("AcAlignment")
        .value("acAlignmentLeft", PyAcAlignment::pyacAlignmentLeft)
        .value("acAlignmentCenter", PyAcAlignment::pyacAlignmentCenter)
        .value("acAlignmentRight", PyAcAlignment::pyacAlignmentRight)
        .value("acAlignmentAligned", PyAcAlignment::pyacAlignmentAligned)
        .value("acAlignmentMiddle", PyAcAlignment::pyacAlignmentMiddle)
        .value("acAlignmentFit", PyAcAlignment::pyacAlignmentFit)
        .value("acAlignmentTopLeft", PyAcAlignment::pyacAlignmentTopLeft)
        .value("acAlignmentTopCenter", PyAcAlignment::pyacAlignmentTopCenter)
        .value("acAlignmentTopRight", PyAcAlignment::pyacAlignmentTopRight)
        .value("acAlignmentMiddleLeft", PyAcAlignment::pyacAlignmentMiddleLeft)
        .value("acAlignmentMiddleCenter", PyAcAlignment::pyacAlignmentMiddleCenter)
        .value("acAlignmentMiddleRight", PyAcAlignment::pyacAlignmentMiddleRight)
        .value("acAlignmentBottomLeft", PyAcAlignment::pyacAlignmentBottomLeft)
        .value("acAlignmentBottomCenter", PyAcAlignment::pyacAlignmentBottomCenter)
        .value("acAlignmentBottomRight", PyAcAlignment::pyacAlignmentBottomRight)
        .export_values()
        ;

    enum_<PyAcHorizontalAlignment>("AcHorizontalAlignment")
        .value("acHorizontalAlignmentLeft", PyAcHorizontalAlignment::pyacHorizontalAlignmentLeft)
        .value("acHorizontalAlignmentCenter", PyAcHorizontalAlignment::pyacHorizontalAlignmentCenter)
        .value("acHorizontalAlignmentRight", PyAcHorizontalAlignment::pyacHorizontalAlignmentRight)
        .value("acHorizontalAlignmentAligned", PyAcHorizontalAlignment::pyacHorizontalAlignmentAligned)
        .value("acHorizontalAlignmentMiddle", PyAcHorizontalAlignment::pyacHorizontalAlignmentMiddle)
        .value("acHorizontalAlignmentFit", PyAcHorizontalAlignment::pyacHorizontalAlignmentFit)
        .export_values()
        ;

    enum_<PyAcVerticalAlignment>("AcVerticalAlignment")
        .value("acVerticalAlignmentBaseline", PyAcVerticalAlignment::pyacVerticalAlignmentBaseline)
        .value("acVerticalAlignmentBottom", PyAcVerticalAlignment::pyacVerticalAlignmentBottom)
        .value("acVerticalAlignmentMiddle", PyAcVerticalAlignment::pyacVerticalAlignmentMiddle)
        .value("acVerticalAlignmentTop", PyAcVerticalAlignment::pyacVerticalAlignmentTop)
        .export_values()
        ;

    enum_<PyAcDrawingDirection>("AcDrawingDirection")
        .value("acLeftToRight", PyAcDrawingDirection::pyacLeftToRight)
        .value("acRightToLeft", PyAcDrawingDirection::pyacRightToLeft)
        .value("acTopToBottom", PyAcDrawingDirection::pyacTopToBottom)
        .value("acBottomToTop", PyAcDrawingDirection::pyacBottomToTop)
        .value("acByStyle", PyAcDrawingDirection::pyacByStyle)
        .export_values()
        ;

    enum_<PyAcBooleanType>("AcBooleanType")
        .value("acUnion", PyAcBooleanType::pyacUnion)
        .value("acIntersection", PyAcBooleanType::pyacIntersection)
        .value("acSubtraction", PyAcBooleanType::pyacSubtraction)
        .export_values()
        ;

    enum_<PyAcAttachmentPoint>("AcAttachmentPoint")
        .value("acAttachmentPointTopLeft", PyAcAttachmentPoint::pyacAttachmentPointTopLeft)
        .value("acAttachmentPointTopCenter", PyAcAttachmentPoint::pyacAttachmentPointTopCenter)
        .value("acAttachmentPointTopRight", PyAcAttachmentPoint::pyacAttachmentPointTopRight)
        .value("acAttachmentPointMiddleLeft", PyAcAttachmentPoint::pyacAttachmentPointMiddleLeft)
        .value("acAttachmentPointMiddleCenter", PyAcAttachmentPoint::pyacAttachmentPointMiddleCenter)
        .value("acAttachmentPointMiddleRight", PyAcAttachmentPoint::pyacAttachmentPointMiddleRight)
        .value("acAttachmentPointBottomLeft", PyAcAttachmentPoint::pyacAttachmentPointBottomLeft)
        .value("acAttachmentPointBottomCenter", PyAcAttachmentPoint::pyacAttachmentPointBottomCenter)
        .value("acAttachmentPointBottomRight", PyAcAttachmentPoint::pyacAttachmentPointBottomRight)
        .export_values()
        ;

    enum_<PyAcLineSpacingStyle>("AcLineSpacingStyle")
        .value("acLineSpacingStyleAtLeast", PyAcLineSpacingStyle::pyacLineSpacingStyleAtLeast)
        .value("acLineSpacingStyleExactly", PyAcLineSpacingStyle::pyacLineSpacingStyleExactly)
        .export_values()
        ;

    enum_<PyAcDimArrowheadType>("AcDimArrowheadType")
        .value("acArrowDefault", PyAcDimArrowheadType::pyacArrowDefault)
        .value("acArrowClosedBlank", PyAcDimArrowheadType::pyacArrowClosedBlank)
        .value("acArrowClosed", PyAcDimArrowheadType::pyacArrowClosed)
        .value("acArrowDot", PyAcDimArrowheadType::pyacArrowDot)
        .value("acArrowArchTick", PyAcDimArrowheadType::pyacArrowArchTick)
        .value("acArrowOblique", PyAcDimArrowheadType::pyacArrowOblique)
        .value("acArrowOpen", PyAcDimArrowheadType::pyacArrowOpen)
        .value("acArrowOrigin", PyAcDimArrowheadType::pyacArrowOrigin)
        .value("acArrowOrigin2", PyAcDimArrowheadType::pyacArrowOrigin2)
        .value("acArrowOpen90", PyAcDimArrowheadType::pyacArrowOpen90)
        .value("acArrowOpen30", PyAcDimArrowheadType::pyacArrowOpen30)
        .value("acArrowDotSmall", PyAcDimArrowheadType::pyacArrowDotSmall)
        .value("acArrowDotBlank", PyAcDimArrowheadType::pyacArrowDotBlank)
        .value("acArrowSmall", PyAcDimArrowheadType::pyacArrowSmall)
        .value("acArrowBoxBlank", PyAcDimArrowheadType::pyacArrowBoxBlank)
        .value("acArrowBoxFilled", PyAcDimArrowheadType::pyacArrowBoxFilled)
        .value("acArrowDatumBlank", PyAcDimArrowheadType::pyacArrowDatumBlank)
        .value("acArrowDatumFilled", PyAcDimArrowheadType::pyacArrowDatumFilled)
        .value("acArrowIntegral", PyAcDimArrowheadType::pyacArrowIntegral)
        .value("acArrowNone", PyAcDimArrowheadType::pyacArrowNone)
        .value("acArrowUserDefined", PyAcDimArrowheadType::pyacArrowUserDefined)
        .export_values()
        ;

    enum_<PyAcDimVerticalJustification>("AcDimVerticalJustification")
        .value("acVertCentered", PyAcDimVerticalJustification::pyacVertCentered)
        .value("acAbove", PyAcDimVerticalJustification::pyacAbove)
        .value("acOutside", PyAcDimVerticalJustification::pyacOutside)
        .value("acJIS", PyAcDimVerticalJustification::pyacJIS)
        .value("acUnder", PyAcDimVerticalJustification::pyacUnder)
        .export_values()
        ;

    enum_<PyAcPolylineType>("AcPolylineType")
        .value("acSimplePoly", PyAcPolylineType::pyacSimplePoly)
        .value("acFitCurvePoly", PyAcPolylineType::pyacFitCurvePoly)
        .value("acQuadSplinePoly", PyAcPolylineType::pyacQuadSplinePoly)
        .value("acCubicSplinePoly", PyAcPolylineType::pyacCubicSplinePoly)
        .export_values()
        ;

    enum_<PyAcSplineKnotParameterizationType>("AcSplineKnotParameterizationType")
        .value("acChord", PyAcSplineKnotParameterizationType::pyacChord)
        .value("acSqrtChord", PyAcSplineKnotParameterizationType::pyacSqrtChord)
        .value("acUniformParam", PyAcSplineKnotParameterizationType::pyacUniformParam)
        .value("acCustomParameterization", PyAcSplineKnotParameterizationType::pyacCustomParameterization)
        .export_values()
        ;

    enum_<PyAcSplineFrameType>("AcSplineFrameType")
        .value("acShow", PyAcSplineFrameType::pyacShow)
        .value("acHide", PyAcSplineFrameType::pyacHide)
        .export_values()
        ;

    enum_<PyAcSplineMethodType>("AcSplineMethodType")
        .value("acFit", PyAcSplineMethodType::pyacFit)
        .value("acControlVertices", PyAcSplineMethodType::pyacControlVertices)
        .export_values()
        ;

    enum_<PyAcISOPenWidth>("AcISOPenWidth")
        .value("acPenWidth013", PyAcISOPenWidth::pyacPenWidth013)
        .value("acPenWidth018", PyAcISOPenWidth::pyacPenWidth018)
        .value("acPenWidth025", PyAcISOPenWidth::pyacPenWidth025)
        .value("acPenWidth035", PyAcISOPenWidth::pyacPenWidth035)
        .value("acPenWidth050", PyAcISOPenWidth::pyacPenWidth050)
        .value("acPenWidth070", PyAcISOPenWidth::pyacPenWidth070)
        .value("acPenWidth100", PyAcISOPenWidth::pyacPenWidth100)
        .value("acPenWidth140", PyAcISOPenWidth::pyacPenWidth140)
        .value("acPenWidth200", PyAcISOPenWidth::pyacPenWidth200)
        .value("acPenWidthUnk", PyAcISOPenWidth::pyacPenWidthUnk)
        .export_values()
        ;

    enum_<PyAcHatchStyle>("AcHatchStyle")
        .value("acHatchStyleNormal", PyAcHatchStyle::pyacHatchStyleNormal)
        .value("acHatchStyleOuter", PyAcHatchStyle::pyacHatchStyleOuter)
        .value("acHatchStyleIgnore", PyAcHatchStyle::pyacHatchStyleIgnore)
        .export_values()
        ;

    enum_<PyAcLoopType>("AcLoopType")
        .value("acHatchLoopTypeDefault", PyAcLoopType::pyacHatchLoopTypeDefault)
        .value("acHatchLoopTypeExternal", PyAcLoopType::pyacHatchLoopTypeExternal)
        .value("acHatchLoopTypePolyline", PyAcLoopType::pyacHatchLoopTypePolyline)
        .value("acHatchLoopTypeDerived", PyAcLoopType::pyacHatchLoopTypeDerived)
        .value("acHatchLoopTypeTextbox", PyAcLoopType::pyacHatchLoopTypeTextbox)
        .export_values()
        ;

    enum_<PyAcHatchObjectType>("AcHatchObjectType")
        .value("acHatchObject", PyAcHatchObjectType::pyacHatchObject)
        .value("acGradientObject", PyAcHatchObjectType::pyacGradientObject)
        .export_values()
        ;

    enum_<PyAcMLineJustification>("AcMLineJustification")
        .value("acTop", PyAcMLineJustification::pyacTop)
        .value("acZero", PyAcMLineJustification::pyacZero)
        .value("acBottom", PyAcMLineJustification::pyacBottom)
        .export_values()
        ;

    enum_<PyAcMLeaderType>("AcMLeaderType")
        .value("acStraightLeader", PyAcMLeaderType::pyacStraightLeader)
        .value("acSplineLeader", PyAcMLeaderType::pyacSplineLeader)
        .value("acInVisibleLeader", PyAcMLeaderType::pyacInVisibleLeader)
        .export_values()
        ;

    enum_<PyAcBlockConnectionType>("AcBlockConnectionType")
        .value("acConnectExtents", PyAcBlockConnectionType::pyacConnectExtents)
        .value("acConnectBase", PyAcBlockConnectionType::pyacConnectBase)
        .export_values()
        ;

    enum_<PyAcTextAttachmentDirection>("AcTextAttachmentDirection")
        .value("acAttachmentHorizontal", PyAcTextAttachmentDirection::pyacAttachmentHorizontal)
        .value("acAttachmentVertical", PyAcTextAttachmentDirection::pyacAttachmentVertical)
        .export_values()
        ;

    enum_<PyAcTextAttachmentType>("AcTextAttachmentType")
        .value("acAttachmentTopOfTop", PyAcTextAttachmentType::pyacAttachmentTopOfTop)
        .value("acAttachmentMiddleOfTop", PyAcTextAttachmentType::pyacAttachmentMiddleOfTop)
        .value("acAttachmentBottomOfTop", PyAcTextAttachmentType::pyacAttachmentBottomOfTop)
        .value("acAttachmentBottomOfTopLine", PyAcTextAttachmentType::pyacAttachmentBottomOfTopLine)
        .value("acAttachmentMiddle", PyAcTextAttachmentType::pyacAttachmentMiddle)
        .value("acAttachmentMiddleOfBottom", PyAcTextAttachmentType::pyacAttachmentMiddleOfBottom)
        .value("acAttachmentBottomOfBottom", PyAcTextAttachmentType::pyacAttachmentBottomOfBottom)
        .value("acAttachmentBottomLine", PyAcTextAttachmentType::pyacAttachmentBottomLine)
        .value("acAttachmentAllLine", PyAcTextAttachmentType::pyacAttachmentAllLine)
        .export_values()
        ;

    enum_<PyAcPredefBlockType>("AcPredefBlockType")
        .value("acBlockImperial", PyAcPredefBlockType::pyacBlockImperial)
        .value("acBlockSlot", PyAcPredefBlockType::pyacBlockSlot)
        .value("acBlockCircle", PyAcPredefBlockType::pyacBlockCircle)
        .value("acBlockBox", PyAcPredefBlockType::pyacBlockBox)
        .value("acBlockHexagon", PyAcPredefBlockType::pyacBlockHexagon)
        .value("acBlockTriangle", PyAcPredefBlockType::pyacBlockTriangle)
        .value("acBlockUserDefined", PyAcPredefBlockType::pyacBlockUserDefined)
        .export_values()
        ;

    enum_<PyAcMLeaderContentType>("AcMLeaderContentType")
        .value("acNoneContent", PyAcMLeaderContentType::pyacNoneContent)
        .value("acBlockContent", PyAcMLeaderContentType::pyacBlockContent)
        .value("acMTextContent", PyAcMLeaderContentType::pyacMTextContent)
        .export_values()
        ;

    enum_<PyAcVerticalTextAttachmentType>("AcVerticalTextAttachmentType")
        .value("acAttachmentCenter", PyAcVerticalTextAttachmentType::pyacAttachmentCenter)
        .value("acAttachmentLinedCenter", PyAcVerticalTextAttachmentType::pyacAttachmentLinedCenter)
        .export_values()
        ;

    enum_<PyAcPlotPaperUnits>("AcPlotPaperUnits")
        .value("acInches", PyAcPlotPaperUnits::pyacInches)
        .value("acMillimeters", PyAcPlotPaperUnits::pyacMillimeters)
        .value("acPixels", PyAcPlotPaperUnits::pyacPixels)
        .export_values()
        ;

    enum_<PyAcPlotRotation>("AcPlotRotation")
        .value("ac0degrees", PyAcPlotRotation::pyac0degrees)
        .value("ac90degrees", PyAcPlotRotation::pyac90degrees)
        .value("ac180degrees", PyAcPlotRotation::pyac180degrees)
        .value("ac270degrees", PyAcPlotRotation::pyac270degrees)
        .export_values()
        ;

    enum_<PyAcPlotType>("AcPlotType")
        .value("acDisplay", PyAcPlotType::pyacDisplay)
        .value("acExtents", PyAcPlotType::pyacExtents)
        .value("acLimits", PyAcPlotType::pyacLimits)
        .value("acView", PyAcPlotType::pyacView)
        .value("acWindow", PyAcPlotType::pyacWindow)
        .value("acLayout", PyAcPlotType::pyacLayout)
        .export_values()
        ;

    enum_<PyAcPlotScale>("AcPlotScale")
        .value("acScaleToFit", PyAcPlotScale::pyacScaleToFit)
        .value("ac1_128in_1f", PyAcPlotScale::pyac1_128in_1ft)
        .value("ac1_64in_1ft", PyAcPlotScale::pyac1_64in_1ft)
        .value("ac1_32in_1ft", PyAcPlotScale::pyac1_32in_1ft)
        .value("ac1_16in_1ft", PyAcPlotScale::pyac1_16in_1ft)
        .value("ac3_32in_1ft", PyAcPlotScale::pyac3_32in_1ft)
        .value("ac1_8in_1ft", PyAcPlotScale::pyac1_8in_1ft)
        .value("ac3_16in_1ft", PyAcPlotScale::pyac3_16in_1ft)
        .value("ac1_4in_1ft", PyAcPlotScale::pyac1_4in_1ft)
        .value("ac3_8in_1ft", PyAcPlotScale::pyac3_8in_1ft)
        .value("ac1_2in_1ft", PyAcPlotScale::pyac1_2in_1ft)
        .value("ac3_4in_1ft", PyAcPlotScale::pyac3_4in_1ft)
        .value("ac1in_1ft", PyAcPlotScale::pyac1in_1ft)
        .value("ac3in_1ft", PyAcPlotScale::pyac3in_1ft)
        .value("ac6in_1ft", PyAcPlotScale::pyac6in_1ft)
        .value("ac1ft_1ft", PyAcPlotScale::pyac1ft_1ft)
        .value("ac1_1", PyAcPlotScale::pyac1_1)
        .value("ac1_2", PyAcPlotScale::pyac1_2)
        .value("ac1_4", PyAcPlotScale::pyac1_4)
        .value("ac1_5", PyAcPlotScale::pyac1_5)
        .value("ac1_8", PyAcPlotScale::pyac1_8)
        .value("ac1_10", PyAcPlotScale::pyac1_10)
        .value("ac1_16", PyAcPlotScale::pyac1_16)
        .value("ac1_20", PyAcPlotScale::pyac1_20)
        .value("ac1_30", PyAcPlotScale::pyac1_30)
        .value("ac1_40", PyAcPlotScale::pyac1_40)
        .value("ac1_50", PyAcPlotScale::pyac1_50)
        .value("ac1_100", PyAcPlotScale::pyac1_100)
        .value("ac2_1", PyAcPlotScale::pyac2_1)
        .value("ac4_1", PyAcPlotScale::pyac4_1)
        .value("ac8_1", PyAcPlotScale::pyac8_1)
        .value("ac10_1", PyAcPlotScale::pyac10_1)
        .value("ac100_1", PyAcPlotScale::pyac100_1)
        .export_values()
        ;

    enum_<PyAcSectionType>("AcSectionType")
        .value("acSectionTypeLiveSection", PyAcSectionType::pyacSectionTypeLiveSection)
        .value("acSectionType2dSection", PyAcSectionType::pyacSectionType2dSection)
        .value("acSectionType3dSection", PyAcSectionType::pyacSectionType3dSection)
        .export_values()
        ;

    enum_<PyAcViewportSplitType>("AcViewportSplitType")
        .value("acViewport2Horizontal", PyAcViewportSplitType::pyacViewport2Horizontal)
        .value("acViewport2Vertical", PyAcViewportSplitType::pyacViewport2Vertical)
        .value("acViewport3Left", PyAcViewportSplitType::pyacViewport3Left)
        .value("acViewport3Right", PyAcViewportSplitType::pyacViewport3Right)
        .value("acViewport3Horizontal", PyAcViewportSplitType::pyacViewport3Horizontal)
        .value("acViewport3Vertical", PyAcViewportSplitType::pyacViewport3Vertical)
        .value("acViewport3Above", PyAcViewportSplitType::pyacViewport3Above)
        .value("acViewport3Below", PyAcViewportSplitType::pyacViewport3Below)
        .value("acViewport4", PyAcViewportSplitType::pyacViewport4)
        .export_values()
        ;

    enum_<PyAcTableDirection>("AcTableDirection")
        .value("acTableTopToBottom", PyAcTableDirection::pyacTableTopToBottom)
        .value("acTableBottomToTop", PyAcTableDirection::pyacTableBottomToTop)
        .export_values()
        ;

    enum_<PyAcRowType>("AcRowType")
        .value("acUnknownRow", PyAcRowType::pyacUnknownRow)
        .value("acDataRow", PyAcRowType::pyacDataRow)
        .value("acTitleRow", PyAcRowType::pyacTitleRow)
        .value("acHeaderRow", PyAcRowType::pyacHeaderRow)
        .export_values()
        ;

    enum_<PyAcCellAlignment>("AcCellAlignment")
        .value("acTopLeft", PyAcCellAlignment::pyacTopLeft)
        .value("acTopCenter", PyAcCellAlignment::pyacTopCenter)
        .value("acTopRight", PyAcCellAlignment::pyacTopRight)
        .value("acMiddleLeft", PyAcCellAlignment::pyacMiddleLeft)
        .value("acMiddleCenter", PyAcCellAlignment::pyacMiddleCenter)
        .value("acMiddleRight", PyAcCellAlignment::pyacMiddleRight)
        .value("acBottomLeft", PyAcCellAlignment::pyacBottomLeft)
        .value("acBottomCenter", PyAcCellAlignment::pyacBottomCenter)
        .value("acBottomRight", PyAcCellAlignment::pyacBottomRight)
        .export_values()
        ;

    enum_<PyAcCellType>("AcCellType")
        .value("acUnknownCell", PyAcCellType::pyacUnknownCell)
        .value("acTextCell", PyAcCellType::pyacTextCell)
        .value("acBlockCell", PyAcCellType::pyacBlockCell)
        .export_values()
        ;

    enum_<PyAcRotationAngle>("AcRotationAngle")
        .value("acDegreesUnknown", PyAcRotationAngle::pyacDegreesUnknown)
        .value("acDegrees000", PyAcRotationAngle::pyacDegrees000)
        .value("acDegrees180", PyAcRotationAngle::pyacDegrees180)
        .value("acDegrees270", PyAcRotationAngle::pyacDegrees270)
        .export_values()
        ;

    enum_<PyAcCellEdgeMask>("AcCellEdgeMask")
        .value("acTopMask", PyAcCellEdgeMask::pyacTopMask)
        .value("acRightMask", PyAcCellEdgeMask::pyacRightMask)
        .value("acBottomMask", PyAcCellEdgeMask::pyacBottomMask)
        .value("acLeftMask", PyAcCellEdgeMask::pyacLeftMask)
        .export_values()
        ;
    enum_<PyAcSelectType>("AcSelectType")
        .value("acTableSelectWindow", PyAcSelectType::pyacTableSelectWindow)
        .value("acTableSelectCrossing", PyAcSelectType::pyacTableSelectCrossing)
        .export_values()
        ;

    enum_<PyAcValueDataType>("AcValueDataType")
        .value("acUnknownDataType", PyAcValueDataType::pyacUnknownDataType)
        .value("acLong", PyAcValueDataType::pyacLong)
        .value("acDouble", PyAcValueDataType::pyacDouble)
        .value("acString", PyAcValueDataType::pyacString)
        .value("acDate", PyAcValueDataType::pyacDate)
        .value("acPoint2d", PyAcValueDataType::pyacPoint2d)
        .value("acPoint3d", PyAcValueDataType::pyacPoint3d)
        .value("acObjectId", PyAcValueDataType::pyacObjectId)
        .value("acBuffer", PyAcValueDataType::pyacBuffer)
        .value("acResbuf", PyAcValueDataType::pyacResbuf)
        .value("acGeneral", PyAcValueDataType::pyacGeneral)
        .export_values()
        ;

    enum_<PyAcValueUnitType>("AcValueUnitType")
        .value("acUnitless", PyAcValueUnitType::pyacUnitless)
        .value("acUnitDistance", PyAcValueUnitType::pyacUnitDistance)
        .value("acUnitAngle", PyAcValueUnitType::pyacUnitAngle)
        .value("acUnitArea", PyAcValueUnitType::pyacUnitArea)
        .value("acUnitVolume", PyAcValueUnitType::pyacUnitVolume)
        .export_values()
        ;

    enum_<PyAcParseOption>("AcParseOption")
        .value("acParseOptionNone", PyAcParseOption::pyacParseOptionNone)
        .value("acSetDefaultFormat", PyAcParseOption::pyacSetDefaultFormat)
        .value("acPreserveMtextFormat", PyAcParseOption::pyacPreserveMtextFormat)
        .export_values()
        ;

    enum_<PyAcFormatOption>("AcFormatOption")
        .value("kFormatOptionNone", PyAcFormatOption::pykFormatOptionNone)
        .value("acForEditing", PyAcFormatOption::pyacForEditing)
        .value("acForExpression", PyAcFormatOption::pyacForExpression)
        .value("acUseMaximumPrecision", PyAcFormatOption::pyacUseMaximumPrecision)
        .value("acIgnoreMtextFormat", PyAcFormatOption::pyacIgnoreMtextFormat)
        .export_values()
        ;

    enum_<PyAcGridLineType>("AcGridLineType")
        .value("acInvalidGridLine", PyAcGridLineType::pyacInvalidGridLine)
        .value("acHorzTop", PyAcGridLineType::pyacHorzTop)
        .value("acHorzInside", PyAcGridLineType::pyacHorzInside)
        .value("acHorzBottom", PyAcGridLineType::pyacHorzBottom)
        .value("acVertLeft", PyAcGridLineType::pyacVertLeft)
        .value("acVertInside", PyAcGridLineType::pyacVertInside)
        .value("acVertRight", PyAcGridLineType::pyacVertRight)
        .export_values()
        ;

    enum_<PyAcCellContentType>("AcCellContentType")
        .value("acCellContentTypeUnknown", PyAcCellContentType::pyacCellContentTypeUnknown)
        .value("acCellContentTypeValue", PyAcCellContentType::pyacCellContentTypeValue)
        .value("acCellContentTypeField", PyAcCellContentType::pyacCellContentTypeField)
        .value("acCellContentTypeBlock", PyAcCellContentType::pyacCellContentTypeBlock)
        .export_values()
        ;

    enum_<PyAcCellState>("AcCellState")
        .value("acCellStateNone", PyAcCellState::pyacCellStateNone)
        .value("acCellStateContentLocked", PyAcCellState::pyacCellStateContentLocked)
        .value("acCellStateContentReadOnly", PyAcCellState::pyacCellStateContentReadOnly)
        .value("acCellStateFormatLocked", PyAcCellState::pyacCellStateFormatLocked)
        .value("acCellStateFormatReadOnly", PyAcCellState::pyacCellStateFormatReadOnly)
        .value("acCellStateLinked", PyAcCellState::pyacCellStateLinked)
        .value("acCellStateContentModified", PyAcCellState::pyacCellStateContentModified)
        .value("acCellStateFormatModified", PyAcCellState::pyacCellStateFormatModified)
        .export_values()
        ;

    enum_<PyAcCellMargin>("AcCellMargin")
        .value("acCellMarginTop", PyAcCellMargin::pyacCellMarginTop)
        .value("acCellMarginLeft", PyAcCellMargin::pyacCellMarginLeft)
        .value("acCellMarginBottom", PyAcCellMargin::pyacCellMarginBottom)
        .value("acCellMarginRight", PyAcCellMargin::pyacCellMarginRight)
        .value("acCellMarginHorzSpacing", PyAcCellMargin::pyacCellMarginHorzSpacing)
        .value("acCellMarginVertSpacing", PyAcCellMargin::pyacCellMarginVertSpacing)
        .export_values()
        ;

    enum_<PyAcCellContentLayout>("AcCellContentLayout")
        .value("acCellContentLayoutFlow", PyAcCellContentLayout::pyacCellContentLayoutFlow)
        .value("acCellContentLayoutStackedHorizontal", PyAcCellContentLayout::pyacCellContentLayoutStackedHorizontal)
        .value("acCellContentLayoutStackedVertical", PyAcCellContentLayout::pyacCellContentLayoutStackedVertical)
        .export_values()
        ;

    enum_<PyAcCellProperty>("AcCellProperty")
        .value("acInvalidCellProperty", PyAcCellProperty::pyacInvalidCellProperty)
        .value("acLock", PyAcCellProperty::pyacLock)
        .value("acDataType", PyAcCellProperty::pyacDataType)
        .value("acDataFormat", PyAcCellProperty::pyacDataFormat)
        .value("acRotation", PyAcCellProperty::pyacRotation)
        .value("acScale", PyAcCellProperty::pyacScale)
        .value("acAlignmentProperty", PyAcCellProperty::pyacAlignmentProperty)
        .value("acContentColor", PyAcCellProperty::pyacContentColor)
        .value("acBackgroundColor", PyAcCellProperty::pyacBackgroundColor)
        .value("acTextStyle", PyAcCellProperty::pyacTextStyle)
        .value("acTextHeight", PyAcCellProperty::pyacTextHeight)
        .value("acMarginLeft", PyAcCellProperty::pyacMarginLeft)
        .value("acMarginTop", PyAcCellProperty::pyacMarginTop)
        .value("acMarginRight", PyAcCellProperty::pyacMarginRight)
        .value("acMarginBottom", PyAcCellProperty::pyacMarginBottom)
        .value("acEnableBackgroundColor", PyAcCellProperty::pyacEnableBackgroundColor)
        .value("acAutoScale", PyAcCellProperty::pyacAutoScale)
        .value("acMergeAll", PyAcCellProperty::pyacMergeAll)
        .value("acFlowDirBtoT", PyAcCellProperty::pyacFlowDirBtoT)
        .value("acContentLayout", PyAcCellProperty::pyacContentLayout)
        .value("acDataTypeAndFormat", PyAcCellProperty::pyacDataTypeAndFormat)
        .value("acContentProperties", PyAcCellProperty::pyacContentProperties)
        .value("acBitProperties", PyAcCellProperty::pyacBitProperties)
        .value("acAllCellProperties", PyAcCellProperty::pyacAllCellProperties)
        .export_values()
        ;

    enum_<PyAcGridLineStyle>("AcGridLineStyle")
        .value("acGridLineStyleSingle", PyAcGridLineStyle::pyacGridLineStyleSingle)
        .value("acGridLineStyleDouble", PyAcGridLineStyle::pyacGridLineStyleDouble)
        .export_values()
        ;

    enum_<PyAcDataLinkUpdateDirection>("AcDataLinkUpdateDirection")
        .value("acUpdateDataFromSource", PyAcDataLinkUpdateDirection::pyacUpdateDataFromSource)
        .value("acUpdateSourceFromData", PyAcDataLinkUpdateDirection::pyacUpdateSourceFromData)
        .export_values()
        ;

    enum_<PyAcDataLinkUpdateOption>("AcDataLinkUpdateOption")
        .value("acUpdateOptionNone", PyAcDataLinkUpdateOption::pyacUpdateOptionNone)
        .value("acUpdateOptionOverwriteContentModifiedAfterUpdate", PyAcDataLinkUpdateOption::pyacUpdateOptionOverwriteContentModifiedAfterUpdate)
        .value("acUpdateOptionOverwriteFormatModifiedAfterUpdate", PyAcDataLinkUpdateOption::pyacUpdateOptionOverwriteFormatModifiedAfterUpdate)
        .value("acUpdateOptionUpdateFullSourceRange", PyAcDataLinkUpdateOption::pyacUpdateOptionUpdateFullSourceRange)
        .value("acUpdateOptionIncludeXrefs", PyAcDataLinkUpdateOption::pyacUpdateOptionIncludeXrefs)
        .export_values()
        ;

    enum_<PyAcTableFlowDirection>("AcTableFlowDirection")
        .value("acTableFlowRight", PyAcTableFlowDirection::pyacTableFlowRight)
        .value("acTableFlowDownOrUp", PyAcTableFlowDirection::pyacTableFlowDownOrUp)
        .value("acTableFlowLeft", PyAcTableFlowDirection::pyacTableFlowLeft)
        .export_values()
        ;

    enum_<PyAcDimPrecision>("AcDimPrecision")
        .value("acDimPrecisionZero", PyAcDimPrecision::pyacDimPrecisionZero)
        .value("acDimPrecisionOne", PyAcDimPrecision::pyacDimPrecisionOne)
        .value("acDimPrecisionTwo", PyAcDimPrecision::pyacDimPrecisionTwo)
        .value("acDimPrecisionThree", PyAcDimPrecision::pyacDimPrecisionThree)
        .value("acDimPrecisionFour", PyAcDimPrecision::pyacDimPrecisionFour)
        .value("acDimPrecisionFive", PyAcDimPrecision::pyacDimPrecisionFive)
        .value("acDimPrecisionSix", PyAcDimPrecision::pyacDimPrecisionSix)
        .value("acDimPrecisionSeven", PyAcDimPrecision::pyacDimPrecisionSeven)
        .value("acDimPrecisionEight", PyAcDimPrecision::pyacDimPrecisionEight)
        .export_values()
        ;

    enum_<PyAcDimUnits>("AcDimUnits")
        .value("acDimScientific", PyAcDimUnits::pyacDimScientific)
        .value("acDimDecimal", PyAcDimUnits::pyacDimDecimal)
        .value("acDimEngineering", PyAcDimUnits::pyacDimEngineering)
        .value("acDimArchitecturalStacked", PyAcDimUnits::pyacDimArchitecturalStacked)
        .value("acDimFractionalStacked", PyAcDimUnits::pyacDimFractionalStacked)
        .value("acDimArchitectural", PyAcDimUnits::pyacDimArchitectural)
        .value("acDimFractional", PyAcDimUnits::pyacDimFractional)
        .value("acDimWindowsDesktop", PyAcDimUnits::pyacDimWindowsDesktop)
        .export_values()
        ;

    enum_<PyAcDimLUnits>("AcDimLUnits")
        .value("acDimLScientific", PyAcDimLUnits::pyacDimLScientific)
        .value("acDimLDecimal", PyAcDimLUnits::pyacDimLDecimal)
        .value("acDimLEngineering", PyAcDimLUnits::pyacDimLEngineering)
        .value("acDimLArchitectural", PyAcDimLUnits::pyacDimLArchitectural)
        .value("acDimLFractional", PyAcDimLUnits::pyacDimLFractional)
        .value("acDimLWindowsDesktop", PyAcDimLUnits::pyacDimLWindowsDesktop)
        .export_values()
        ;

    enum_<PyAcDimTextMovement>("AcDimTextMovement")
        .value("acDimLineWithText", PyAcDimTextMovement::pyacDimLineWithText)
        .value("acMoveTextAddLeader", PyAcDimTextMovement::pyacMoveTextAddLeader)
        .value("acMoveTextNoLeader", PyAcDimTextMovement::pyacMoveTextNoLeader)
        .export_values()
        ;

    enum_<PyAcDimToleranceMethod>("AcDimToleranceMethod")
        .value("acTolNone", PyAcDimToleranceMethod::pyacTolNone)
        .value("acTolSymmetrical", PyAcDimToleranceMethod::pyacTolSymmetrical)
        .value("acTolDeviation", PyAcDimToleranceMethod::pyacTolDeviation)
        .value("acTolLimits", PyAcDimToleranceMethod::pyacTolLimits)
        .value("acTolBasic", PyAcDimToleranceMethod::pyacTolBasic)
        .export_values()
        ;

    enum_<PyAcDimToleranceJustify>("AcDimToleranceJustify")
        .value("acTolBottom", PyAcDimToleranceJustify::pyacTolBottom)
        .value("acTolMiddle", PyAcDimToleranceJustify::pyacTolMiddle)
        .value("acTolTop", PyAcDimToleranceJustify::pyacTolTop)
        .export_values()
        ;

    enum_<PyAcDimFit>("AcDimFit")
        .value("acTextAndArrows", PyAcDimFit::pyacTextAndArrows)
        .value("acArrowsOnly", PyAcDimFit::pyacArrowsOnly)
        .value("acTextOnly", PyAcDimFit::pyacTextOnly)
        .value("acBestFit", PyAcDimFit::pyacBestFit)
        .export_values()
        ;

    enum_<PyAcDimFractionType>("AcDimFractionType")
        .value("acHorizontal", PyAcDimFractionType::pyacHorizontal)
        .value("acDiagonal", PyAcDimFractionType::pyacDiagonal)
        .value("acNotStacked", PyAcDimFractionType::pyacNotStacked)
        .export_values()
        ;

    enum_<PyAcDimHorizontalJustification>("AcDimHorizontalJustification")
        .value("acHorzCentered", PyAcDimHorizontalJustification::pyacHorzCentered)
        .value("acFirstExtensionLine", PyAcDimHorizontalJustification::pyacFirstExtensionLine)
        .value("acSecondExtensionLine", PyAcDimHorizontalJustification::pyacSecondExtensionLine)
        .value("acOverFirstExtension", PyAcDimHorizontalJustification::pyacOverFirstExtension)
        .value("acOverSecondExtension", PyAcDimHorizontalJustification::pyacOverSecondExtension)
        .export_values()
        ;


}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}
