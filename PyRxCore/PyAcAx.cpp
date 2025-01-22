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
    makePyAcadEntityWrapper();
    makePyAcadDatabaseWrapper();
    makePyAcadDocumentWrapper();
    makePyAcadDocumentsWrapper();
    makePyAcadApplicationWrapper();

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

}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}
