#include "stdafx.h"
#include "PyBrx.h"
#include "PyBrxDbProperties.h"
#include "PyBrxCore.h"
#include "PyBrxPanel.h"
#include "PyBrxComponentCustomProperties.h"
#include "PyBrxConstraints3d.h"


#ifdef BRXAPP

using namespace boost::python;

static BOOST_PYTHON_MODULE(PyBrx)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBrxCoreWrapper();
#ifndef _BRXTARGET240
    makePyBrxDbPropertiesWrapper();
#endif
    makePyBrxPanelWrapper();
    makePyBrxMechanicalPropertySet();
    makePyBrxMechanicalPropertyDefinition();

    enum_<BricsCAD::LicensedFeature>("LicensedFeature")
        .value("eCore", BricsCAD::LicensedFeature::eCore)
        .value("eCommunicator", BricsCAD::LicensedFeature::eCommunicator)
        .value("eBim", BricsCAD::LicensedFeature::eBim)
        .value("eMechanical", BricsCAD::LicensedFeature::eMechanical)
        .export_values()
        ;

    enum_<BrxMechanicalPropertyType>("MechanicalPropertyType")
        .value("eUndefined", BrxMechanicalPropertyType::eUndefined)
        .value("eInteger", BrxMechanicalPropertyType::eInteger)
        .value("eReal", BrxMechanicalPropertyType::eReal)
        .value("eBoolean", BrxMechanicalPropertyType::eBoolean)
        .value("eString", BrxMechanicalPropertyType::eString)
        .export_values()
        ;

    enum_<AcConstraint::ConstraintType>("ConstraintType")
        .value("eAcUnknown", AcConstraint::ConstraintType::eAcUnknown)
        .value("eAc3DAngle", AcConstraint::ConstraintType::eAc3DAngle)
        .value("eAc3DCoincident", AcConstraint::ConstraintType::eAc3DCoincident)
        .value("eAc3DConcentric", AcConstraint::ConstraintType::eAc3DConcentric)
        .value("eAc3DDistance", AcConstraint::ConstraintType::eAc3DDistance)
        .value("eAc3DFix", AcConstraint::ConstraintType::eAc3DFix)
        .value("eAc3DMajorRadius", AcConstraint::ConstraintType::eAc3DMajorRadius)
        .value("eAc3DMinorRadius", AcConstraint::ConstraintType::eAc3DMinorRadius)
        .value("eAc3DParallel", AcConstraint::ConstraintType::eAc3DParallel)
        .value("eAc3DPerpendicular", AcConstraint::ConstraintType::eAc3DPerpendicular)
        .value("eAc3DPlanarAngle", AcConstraint::ConstraintType::eAc3DPlanarAngle)
        .value("eAc3DRadius", AcConstraint::ConstraintType::eAc3DRadius)
        .value("eAc3DRigidSet", AcConstraint::ConstraintType::eAc3DRigidSet)
        .value("eAc3DTangent", AcConstraint::ConstraintType::eAc3DTangent)
        .value("eAcCircularArray", AcConstraint::ConstraintType::eAcCircularArray)
        .value("eAcObjectAngle", AcConstraint::ConstraintType::eAcObjectAngle)
        .value("eAcPath", AcConstraint::ConstraintType::eAcPath)
        .export_values()
        ;

    enum_<AcConstraint::Directions>("ConstraintDirections")
        .value("eDirectionsAny", AcConstraint::Directions::eDirectionsAny)
        .value("eDirectionsSame", AcConstraint::Directions::eDirectionsSame)
        .value("eDirectionsOpposite", AcConstraint::Directions::eDirectionsOpposite)
        .value("eDirectionsKeep", AcConstraint::Directions::eDirectionsKeep)
        .export_values()
        ;

    enum_<AcConstraint::MeasurementMode>("ConstraintMeasurementMode")
        .value("eMeasurementModeCenter", AcConstraint::MeasurementMode::eMeasurementModeCenter)
        .value("eMeasurementModeBoundary", AcConstraint::MeasurementMode::eMeasurementModeBoundary)
        .value("eMeasurementModeCentralPoint", AcConstraint::MeasurementMode::eMeasurementModeCentralPoint)
        .export_values()
        ;

    enum_<AcConstraint::Placement>("ConstraintPlacement")
        .value("ePlacementAny", AcConstraint::Placement::ePlacementAny)
        .value("ePlacementOutside", AcConstraint::Placement::ePlacementOutside)
        .value("ePlacementInside", AcConstraint::Placement::ePlacementInside)
        .value("ePlacementKeep", AcConstraint::Placement::ePlacementKeep)
        .export_values()
        ;
}


void initPyBrxModule()
{
    PyImport_AppendInittab(PyBrxNamespace, &PyInit_PyBrx);
}
#endif
