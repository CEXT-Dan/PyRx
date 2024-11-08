#include "stdafx.h"
#include "PyAcBr.h"
#include "PyBrEntity.h"

using namespace boost::python;


BOOST_PYTHON_MODULE(PyBr)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBrEntityWrapper();

    enum_<AcBr::Element2dShape>("Element2dShape")
        .value("kDefault", AcBr::Element2dShape::kDefault)
        .value("kAllPolygons", AcBr::Element2dShape::kAllPolygons)
        .value("kAllQuadrilaterals", AcBr::Element2dShape::kAllQuadrilaterals)
        .value("kAllTriangles", AcBr::Element2dShape::kAllTriangles)
        .export_values()
        ;

    enum_<AcBr::ErrorStatus>("ErrorStatus")
        .value("eAmbiguousOutput", AcBr::ErrorStatus::eAmbiguousOutput)
        .value("eBrepChanged", AcBr::ErrorStatus::eBrepChanged)
        .value("eDegenerateTopology", AcBr::ErrorStatus::eDegenerateTopology)
        .value("eInvalidInput", AcBr::ErrorStatus::eInvalidInput)
        .value("eInvalidObject", AcBr::ErrorStatus::eInvalidObject)
        .value("eMissingGeometry", AcBr::ErrorStatus::eMissingGeometry)
        .value("eMissingSubentity", AcBr::ErrorStatus::eMissingSubentity)
        .value("eNotApplicable", AcBr::ErrorStatus::eNotApplicable)
        .value("eNotImplementedYet", AcBr::ErrorStatus::eNotImplementedYet)
        .value("eNullObjectId", AcBr::ErrorStatus::eNullObjectId)
        .value("eNullObjectPointer", AcBr::ErrorStatus::eNullObjectPointer)
        .value("eNullSubentityId", AcBr::ErrorStatus::eNullSubentityId)
        .value("eObjectIdMismatch", AcBr::ErrorStatus::eObjectIdMismatch)
        .value("eOk", AcBr::ErrorStatus::eOk)
        .value("eOutOfMemory", AcBr::ErrorStatus::eOutOfMemory)
        .value("eTopologyMismatch", AcBr::ErrorStatus::eTopologyMismatch)
        .value("eUninitialisedObject", AcBr::ErrorStatus::eUninitialisedObject)
        .value("eUnsuitableGeometry", AcBr::ErrorStatus::eUnsuitableGeometry)
        .value("eUnsuitableTopology", AcBr::ErrorStatus::eUnsuitableTopology)
        .value("eWrongObjectType", AcBr::ErrorStatus::eWrongObjectType)
        .value("eWrongSubentityType", AcBr::ErrorStatus::eWrongSubentityType)
        .export_values()
        ;

    enum_<AcBr::LoopType>("LoopType")
        .value("kUnclassified", AcBr::LoopType::kUnclassified)
        .value("kExterior", AcBr::LoopType::kExterior)
        .value("kInterior", AcBr::LoopType::kInterior)
        .value("kWinding", AcBr::LoopType::kWinding)
        .value("kLoopUnclassified", AcBr::LoopType::kLoopUnclassified)
        .value("kLoopExterior", AcBr::LoopType::kLoopExterior)
        .value("kLoopExterior", AcBr::LoopType::kLoopExterior)
        .value("kLoopExterior", AcBr::LoopType::kLoopExterior)
        .export_values()
        ;

    enum_<AcBr::Relation>("Relation")
        .value("kUnknown", AcBr::Relation::kUnknown)
        .value("kOutside", AcBr::Relation::kOutside)
        .value("kInside", AcBr::Relation::kInside)
        .value("kBoundary", AcBr::Relation::kBoundary)
        .value("kCoincident", AcBr::Relation::kCoincident)
        .value("kTangent", AcBr::Relation::kTangent)
        .value("kIntersect", AcBr::Relation::kIntersect)
        .export_values()
        ;

    enum_<AcBr::ShellType>("ShellType")
        .value("kShellUnclassified", AcBr::ShellType::kShellUnclassified)
        .value("kShellExterior", AcBr::ShellType::kShellExterior)
        .value("kShellInterior", AcBr::ShellType::kShellInterior)
        .export_values()
        ;
    enum_<AcBr::ValidationLevel>("ShellType")
        .value("kFullValidation", AcBr::ValidationLevel::kFullValidation)
        .value("kNoValidation", AcBr::ValidationLevel::kNoValidation)
        .export_values()
        ;

}


void initPyBrModule()
{
    PyImport_AppendInittab(PyBrNamespace, &PyInit_PyBr);
}


