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
