#include "stdafx.h"
#include "PyAcBr.h"
#include "PyBrEntity.h"
#include "PyBrTraverser.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//makeAcBrMassProps
static double getMassPropVolume(const AcBrMassProps& prop)
{
    return prop.mVolume;
}

static double getMassPropMass(const AcBrMassProps& prop)
{
    return prop.mMass;
}

static AcGePoint3d getMassPropCentroid(const AcBrMassProps& prop)
{
    return prop.mCentroid;
}

static boost::python::tuple getMassRadiiGyration(const AcBrMassProps& prop)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(prop.mRadiiGyration[0], prop.mRadiiGyration[1], prop.mRadiiGyration[2]);
}

static boost::python::tuple getMassMomInertia(const AcBrMassProps& prop)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(prop.mMomInertia[0], prop.mMomInertia[1], prop.mMomInertia[2]);
}

static boost::python::tuple getMassProdInertia(const AcBrMassProps& prop)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(prop.mProdInertia[0], prop.mProdInertia[1], prop.mProdInertia[2]);
}

static boost::python::tuple getMassPrinMoments(const AcBrMassProps& prop)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(prop.mPrinMoments[0], prop.mPrinMoments[1], prop.mPrinMoments[2]);
}

static boost::python::tuple getMassPrinAxes(const AcBrMassProps& prop)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(prop.mPrinAxes[0], prop.mPrinAxes[1], prop.mPrinAxes[2]);
}

void makeAcBrMassProps()
{
    PyDocString DS("MassProps ");
    class_<AcBrMassProps >("MassProps")
        .def("volume", &getMassPropVolume, DS.ARGS())
        .def("mass", &getMassPropMass, DS.ARGS())
        .def("centroid", &getMassPropCentroid, DS.ARGS())
        .def("radiiGyration", &getMassRadiiGyration, DS.ARGS())
        .def("momInertia", &getMassMomInertia, DS.ARGS())
        .def("prodInertia", &getMassProdInertia, DS.ARGS())
        .def("prinMoments", &getMassPrinMoments, DS.ARGS())
        .def("prinAxes", &getMassPrinAxes, DS.ARGS())
        ;
}

BOOST_PYTHON_MODULE(PyBr)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    PyBrErrorStatusException::makePyBrErrorStatusExceptionWrapper();
    makeAcBrMassProps();
    makePyBrHitWrapper();
    makePyBrEntityWrapper();
    makePyBrBrepWrapper();
    makePyBrComplexWrapper();
    makePyBrEdgeWrapper();
    makePyBrFaceWrapper();
    makePyBrLoopWrapper();
    makePyBrShellWrapper();
    makePyBrVertexWrapper();
    makePyBrMeshEntityWrapper();
    makePyBrElementWrapper();
    makePyBrElement2dWrapper();
    makePyBrMeshWrapper();
    makePyBrMesh2dWrapper();
    makePyBrNodeWrapper();

    makePyBrTraverserWrapper();
    makePyBrepComplexTraverserWrapper();
    makePyBrepEdgeTraverserWrapper();
    makePyBrepFaceTraverserWrapper();
    makePyBrepShellTraverserWrapper();
    makePyBrepVertexTraverserWrapper();
    makePyBrComplexShellTraverserWrapper();
    makePyBrEdgeLoopTraverserWrapper();
    makePyBrElement2dNodeTraverserWrapper();
    makePyBrFaceLoopTraverserWrapper();
    makePyBrLoopEdgeTraverserWrapper();
    makePyBrLoopVertexTraverserWrapper();
    makePyBrMesh2dElement2dTraverserWrapper();
    makePyBrShellFaceTraverserWrapper();
    makePyBrVertexEdgeTraverserWrapper();
    makePyBrVertexLoopTraverserWrapper();

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
    enum_<AcBr::ValidationLevel>("ValidationLevel")
        .value("kFullValidation", AcBr::ValidationLevel::kFullValidation)
        .value("kNoValidation", AcBr::ValidationLevel::kNoValidation)
        .export_values()
        ;
}


void initPyBrModule()
{
    PyImport_AppendInittab(PyBrNamespace, &PyInit_PyBr);
}


