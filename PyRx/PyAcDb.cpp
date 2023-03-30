#include "stdafx.h"
#include "PyAcDb.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbSymbolTableRecord.h"

using namespace boost::python;

static PyDbObject openDbObject(const PyDbObjectId& id, bool forWrite)
{
    AcDbObject* pObj = nullptr;
    if (acdbOpenAcDbObject(pObj, id.m_id, forWrite ? AcDb::kForWrite : AcDb::kForRead) == eOk)
        return PyDbObject(pObj, true);
    throw PyNullObject();
}

static PyDbObject openDbEntity(const PyDbObjectId& id, bool forWrite)
{
    if (id.m_id.objectClass()->isDerivedFrom(AcDbEntity::desc()))
    {
        AcDbEntity* pObj = nullptr;
        if (acdbOpenAcDbEntity(pObj, id.m_id, forWrite ? AcDb::kForWrite : AcDb::kForRead) == eOk)
            return PyDbObject(pObj, true);
    }
    throw PyNullObject();
}

BOOST_PYTHON_MODULE(PyDb)
{
    def("openDbObject", openDbObject);
    def("openDbEntity", openDbEntity);

    //create in class order!
    makeAcDbObjectIdWrapper();
    makeAcDbObjectWrapper();
    makeAcDbSymbolTableRecordWrapper();
    makeAcDbBlockTableRecordWrapper();
    makeAcDbDatabaseWrapper();
    makeAcDbHostApplicationServicesWrapper();



    enum_<AcDb::LineWeight>("LineWeight")
        .value("LnWt000", AcDb::LineWeight::kLnWt000)
        .value("LnWt005", AcDb::LineWeight::kLnWt005)
        .value("LnWt009", AcDb::LineWeight::kLnWt009)
        .value("LnWt013", AcDb::LineWeight::kLnWt013)
        .value("LnWt015", AcDb::LineWeight::kLnWt015)
        .value("LnWt018", AcDb::LineWeight::kLnWt018)
        .value("LnWt020", AcDb::LineWeight::kLnWt020)
        .value("LnWt025", AcDb::LineWeight::kLnWt025)
        .value("LnWt030", AcDb::LineWeight::kLnWt030)
        .value("LnWt035", AcDb::LineWeight::kLnWt035)
        .value("LnWt040", AcDb::LineWeight::kLnWt040)
        .value("LnWt050", AcDb::LineWeight::kLnWt050)
        .value("LnWt053", AcDb::LineWeight::kLnWt053)
        .value("LnWt060", AcDb::LineWeight::kLnWt060)
        .value("LnWt070", AcDb::LineWeight::kLnWt070)
        .value("LnWt080", AcDb::LineWeight::kLnWt080)
        .value("LnWt090", AcDb::LineWeight::kLnWt090)
        .value("LnWt100", AcDb::LineWeight::kLnWt100)
        .value("LnWt106", AcDb::LineWeight::kLnWt106)
        .value("LnWt120", AcDb::LineWeight::kLnWt120)
        .value("LnWt140", AcDb::LineWeight::kLnWt140)
        .value("LnWt158", AcDb::LineWeight::kLnWt158)
        .value("LnWt200", AcDb::LineWeight::kLnWt200)
        .value("LnWt211", AcDb::LineWeight::kLnWt211)
        .value("LnWtByLayer", AcDb::LineWeight::kLnWtByLayer)
        .value("LnWtByBlock", AcDb::LineWeight::kLnWtByBlock)
        .value("LnWtByLwDefault", AcDb::LineWeight::kLnWtByLwDefault)
        ;
    enum_<AcDb::PlotStyleNameType>("PlotStyleNameType")
        .value("PlotStyleNameByLayer", AcDb::PlotStyleNameType::kPlotStyleNameByLayer)
        .value("PlotStyleNameByBlock", AcDb::PlotStyleNameType::kPlotStyleNameByBlock)
        .value("PlotStyleNameIsDictDefault", AcDb::PlotStyleNameType::kPlotStyleNameIsDictDefault)
        .value("PlotStyleNameById", AcDb::PlotStyleNameType::kPlotStyleNameById)
        ;
    enum_<AcDb::EndCaps>("EndCaps")
        .value("EndCapNone", AcDb::EndCaps::kEndCapNone)
        .value("EndCapRound", AcDb::EndCaps::kEndCapRound)
        .value("EndCapAngle", AcDb::EndCaps::kEndCapAngle)
        .value("EndCapSquare", AcDb::EndCaps::kEndCapSquare)
        ;
    enum_<AcDb::UnitsValue>("UnitsValue")
        .value("UnitsUndefined", AcDb::UnitsValue::kUnitsUndefined)
        .value("UnitsInches", AcDb::UnitsValue::kUnitsInches)
        .value("UnitsFeet", AcDb::UnitsValue::kUnitsFeet)
        .value("UnitsMiles", AcDb::UnitsValue::kUnitsMiles)
        .value("UnitsMillimeters", AcDb::UnitsValue::kUnitsMillimeters)
        .value("UnitsCentimeters", AcDb::UnitsValue::kUnitsCentimeters)
        .value("UnitsMeters", AcDb::UnitsValue::kUnitsMeters)
        .value("UnitsKilometers", AcDb::UnitsValue::kUnitsKilometers)
        .value("UnitsMicroinches", AcDb::UnitsValue::kUnitsMicroinches)
        .value("UnitsMils", AcDb::UnitsValue::kUnitsMils)
        .value("UnitsYards", AcDb::UnitsValue::kUnitsYards)
        .value("UnitsAngstroms", AcDb::UnitsValue::kUnitsAngstroms)
        .value("UnitsNanometers", AcDb::UnitsValue::kUnitsNanometers)
        .value("UnitsMicrons", AcDb::UnitsValue::kUnitsMicrons)
        .value("UnitsDecimeters", AcDb::UnitsValue::kUnitsDecimeters)
        .value("UnitsDekameters", AcDb::UnitsValue::kUnitsDekameters)
        .value("UnitsHectometers", AcDb::UnitsValue::kUnitsHectometers)
        .value("UnitsGigameters", AcDb::UnitsValue::kUnitsGigameters)
        .value("UnitsAstronomical", AcDb::UnitsValue::kUnitsAstronomical)
        .value("UnitsLightYears", AcDb::UnitsValue::kUnitsLightYears)
        .value("UnitsParsecs", AcDb::UnitsValue::kUnitsParsecs)
        .value("UnitsUSSurveyFeet", AcDb::UnitsValue::kUnitsUSSurveyFeet)
        .value("UnitsUSSurveyInch", AcDb::UnitsValue::kUnitsUSSurveyInch)
        .value("UnitsUSSurveyYard", AcDb::UnitsValue::kUnitsUSSurveyYard)
        .value("UnitsUSSurveyMile", AcDb::UnitsValue::kUnitsUSSurveyMile)
        .value("UnitsMax", AcDb::UnitsValue::kUnitsMax)
        ;
    enum_<AcDb::JoinStyle>("JoinStyle")
        .value("JnStylNone", AcDb::JoinStyle::kJnStylNone)
        .value("JnStylRound", AcDb::JoinStyle::kJnStylRound)
        .value("JnStylAngle", AcDb::JoinStyle::kJnStylAngle)
        .value("JnStylFlat", AcDb::JoinStyle::kJnStylFlat)
        ;
    enum_<AcDb::MeasurementValue>("MeasurementValue")
        .value("English", AcDb::MeasurementValue::kEnglish)
        .value("Metric", AcDb::MeasurementValue::kMetric)
        ;
    enum_<AcDb::UpdateOption>("UpdateOption")
        .value("UpdateOptionNone", AcDb::UpdateOption::kUpdateOptionNone)
        .value("UpdateOptionSkipFormat", AcDb::UpdateOption::kUpdateOptionSkipFormat)
        .value("UpdateOptionUpdateRowHeight", AcDb::UpdateOption::kUpdateOptionUpdateRowHeight)
        .value("UpdateOptionUpdateColumnWidth", AcDb::UpdateOption::kUpdateOptionUpdateColumnWidth)
        .value("UpdateOptionAllowSourceUpdate", AcDb::UpdateOption::kUpdateOptionAllowSourceUpdate)
        .value("UpdateOptionForceFullSourceUpdate", AcDb::UpdateOption::kUpdateOptionForceFullSourceUpdate)
        .value("UpdateOptionOverwriteContentModifiedAfterUpdate", AcDb::UpdateOption::kUpdateOptionOverwriteContentModifiedAfterUpdate)
        .value("UpdateOptionOverwriteFormatModifiedAfterUpdate", AcDb::UpdateOption::kUpdateOptionOverwriteFormatModifiedAfterUpdate)
        .value("UpdateOptionForPreview", AcDb::UpdateOption::kUpdateOptionForPreview)
        .value("UpdateOptionIncludeXrefs", AcDb::UpdateOption::kUpdateOptionIncludeXrefs)
        .value("SkipFormatAfterFirstUpdate", AcDb::UpdateOption::kSkipFormatAfterFirstUpdate)
        ;
    enum_<AcDb::UpdateDirection>("UpdateDirection")
        .value("UpdateDirSourceToData", AcDb::UpdateDirection::kUpdateDirSourceToData)
        .value("UpdateDirDataToSource", AcDb::UpdateDirection::kUpdateDirDataToSource)
        ;
    enum_<AcDb::DuplicateRecordCloning>("DuplicateRecordCloning")
        .value("DrcNotApplicable", AcDb::DuplicateRecordCloning::kDrcNotApplicable)
        .value("DrcIgnore", AcDb::DuplicateRecordCloning::kDrcIgnore)
        .value("DrcReplace", AcDb::DuplicateRecordCloning::kDrcReplace)
        .value("DrcXrefMangleName", AcDb::DuplicateRecordCloning::kDrcXrefMangleName)
        .value("DrcMangleName", AcDb::DuplicateRecordCloning::kDrcMangleName)
        .value("DrcUnmangleName", AcDb::DuplicateRecordCloning::kDrcUnmangleName)
        ;
    enum_<AcDb::OrthographicView>("OrthographicView")
        .value("NonOrthoView", AcDb::OrthographicView::kNonOrthoView)
        .value("TopView", AcDb::OrthographicView::kTopView)
        .value("BottomView", AcDb::OrthographicView::kBottomView)
        .value("FrontView", AcDb::OrthographicView::kFrontView)
        .value("BackView", AcDb::OrthographicView::kBackView)
        .value("LeftView", AcDb::OrthographicView::kLeftView)
        .value("RightView", AcDb::OrthographicView::kRightView)
        ;
    //TODO
    enum_<Acad::ErrorStatus>("ErrorStatus")
        .value("eOk", Acad::ErrorStatus::eOk)
        .value("eNullPtr", Acad::ErrorStatus::eNullPtr)
        ;
};

void initPyDbModule()
{
    PyImport_AppendInittab(PyDbNamespace, &PyInit_PyDb);
}
