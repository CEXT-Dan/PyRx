#include "stdafx.h"
#include "PyBrxCv.h"
#include "PyBrxCvBase.h"

#ifdef BRXAPP

using namespace boost::python;

BOOST_PYTHON_MODULE(PyBrxCv)
{
    docstring_options local_docstring_options(true, true, true);

    makePyBrxCvDbSubObjectWrapper();
    makePyBrxCvDbObjectWrapper();
    makePyBrxCvDbEntityWrapper();
    makePyBrxCvDbCurveWrapper();
    makePyBrxCvCivil3dEntityInfoWrapper();
    makePyBrxCvCivil3dConverterWrapper();
    makePyBrxCvDbViewWrapper();
    makePyBrxCvDbVAlignmentViewWrapper();
    makePyBrxCvStationEquationWrapper();
    makePyBrxCvStationEquationsWrapper();
    makePyBrxCvDbHAlignmentWrapper();

    enum_<BrxCvCivil3dConverter::Civil3dLabels>("Civil3dLabels")
        .value("eNoLabels", BrxCvCivil3dConverter::Civil3dLabels::eNoLabels)
        .value("eSurfaceLabels", BrxCvCivil3dConverter::Civil3dLabels::eSurfaceLabels)
        .value("eAlignmentsLabels", BrxCvCivil3dConverter::Civil3dLabels::eAlignmentsLabels)
        .value("eUnattachedLabels", BrxCvCivil3dConverter::Civil3dLabels::eUnattachedLabels)
        .value("eDefaultLabels", BrxCvCivil3dConverter::Civil3dLabels::eDefaultLabels)
        .value("eAllLabels", BrxCvCivil3dConverter::Civil3dLabels::eAllLabels)
        .export_values()
        ;

    enum_<BrxCvCivil3dEntityInfo::Civil3dEntityType>("Civil3dEntityType")
        .value("eNoEntity", BrxCvCivil3dEntityInfo::Civil3dEntityType::eNoEntity)
        .value("eAlignment", BrxCvCivil3dEntityInfo::Civil3dEntityType::eAlignment)
        .value("eProfile", BrxCvCivil3dEntityInfo::Civil3dEntityType::eProfile)
        .value("eTinSurface", BrxCvCivil3dEntityInfo::Civil3dEntityType::eTinSurface)
        .value("eProfileView", BrxCvCivil3dEntityInfo::Civil3dEntityType::eProfileView)
        .export_values()
        ;

    enum_<BrxCvCivil3dEntityInfo::Civil3dAlignmentType>("Civil3dAlignmentType")
        .value("eNotAlignment", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eNotAlignment)
        .value("eCenterline", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eCenterline)
        .value("eOffset", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eOffset)
        .value("eCurbReturn", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eCurbReturn)
        .value("eRail", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eRail)
        .value("eMiscellaneous", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eMiscellaneous)
        .export_values()
        ;

    enum_<BrxCvCivil3dEntityInfo::Civil3dProfileType>("Civil3dProfileType")
        .value("eNotProfile", BrxCvCivil3dEntityInfo::Civil3dProfileType::eNotProfile)
        .value("eLayout", BrxCvCivil3dEntityInfo::Civil3dProfileType::eLayout)
        .value("eStaticSurface", BrxCvCivil3dEntityInfo::Civil3dProfileType::eStaticSurface)
        .value("eDynamicSurface", BrxCvCivil3dEntityInfo::Civil3dProfileType::eDynamicSurface)
        .value("eQuick", BrxCvCivil3dEntityInfo::Civil3dProfileType::eQuick)
        .export_values()
        ;
    enum_<BrxCvStationEquation::EStationEquationType>("EStationEquationType")
        .value("Increasing", BrxCvStationEquation::EStationEquationType::Increasing)
        .value("Decreasing", BrxCvStationEquation::EStationEquationType::Decreasing)
        .export_values()
        ;

    enum_<BrxCvDbHAlignment::EHAlignmentVisualStyle>("EHAlignmentVisualStyle")
        .value("eUndefined", BrxCvDbHAlignment::EHAlignmentVisualStyle::eUndefined)
        .value("eElements", BrxCvDbHAlignment::EHAlignmentVisualStyle::eElements)
        .value("eTangentExtensions", BrxCvDbHAlignment::EHAlignmentVisualStyle::eTangentExtensions)
        .value("eElementExtensions", BrxCvDbHAlignment::EHAlignmentVisualStyle::eElementExtensions)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::EArcType>("EArcType")
        .value("eCompound", BrxCvDbHAlignment::EArcType::eCompound)
        .value("eReverse", BrxCvDbHAlignment::EArcType::eReverse)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::EArcParameterType>("EArcParameterType")
        .value("eRadius", BrxCvDbHAlignment::EArcParameterType::eRadius)
        .value("eDegreeOfCurve", BrxCvDbHAlignment::EArcParameterType::eDegreeOfCurve)
        .value("eTangentLength", BrxCvDbHAlignment::EArcParameterType::eTangentLength)
        .value("eChordLength", BrxCvDbHAlignment::EArcParameterType::eChordLength)
        .value("eCurveLength", BrxCvDbHAlignment::EArcParameterType::eCurveLength)
        .value("eExternalDist", BrxCvDbHAlignment::EArcParameterType::eExternalDist)
        .value("eMiddleOrdinate", BrxCvDbHAlignment::EArcParameterType::eMiddleOrdinate)
        .value("eCurveAngle", BrxCvDbHAlignment::EArcParameterType::eCurveAngle)
        .value("eCurveThroughPoint", BrxCvDbHAlignment::EArcParameterType::eCurveThroughPoint)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::ESpiralDefinitionType>("ESpiralDefinitionType")
        .value("eClothoid", BrxCvDbHAlignment::ESpiralDefinitionType::eClothoid)
        .value("eCubicParabola", BrxCvDbHAlignment::ESpiralDefinitionType::eCubicParabola)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::ESpiralParameterType>("ESpiralParameterType")
        .value("eParamA", BrxCvDbHAlignment::ESpiralParameterType::eParamA)
        .value("eParamLength", BrxCvDbHAlignment::ESpiralParameterType::eParamLength)
        .export_values()
        ;
};

void initPyBrxCvModule()
{
    PyImport_AppendInittab(PyBrxCvNamespace, &PyInit_PyBrxCv);
}

#endif