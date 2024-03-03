#include "stdafx.h"
#include "PyAcGi.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"
#include "PyGiSubEntityTraits.h"
#include "PyGiTransientManager.h"
#include "PyGiGraphicsKernel.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGi)
{
    docstring_options local_docstring_options(true, true, true);

    makePyGiObjectWrapper();
    makePyGiCommonDrawWrapper();
    makePyGiWorldDrawWrapper();
    makePyGiViewportDrawWrapper();
    makePyGiDrawableOverruleWrapper();
    makePyGiSubEntityTraitsWrapper();
    makePyGiDrawableTraitsWrapper();
    makePyGiGeometryWrapper();
    makePyGiWorldGeometryWrapper();
    makePyGiViewportGeometryWrapper();
    makePyGiTransientManagerWrapper();

#ifdef PYRX_IN_PROGRESS_GS_GI
    makePyGiKernelDescriptorWrapper();
    makePyGiGraphicsKernelWrapper();
#endif

    enum_<AcGiTransientDrawingMode>("AcGiTransientDrawingMode")
        .value("kAcGiMain", AcGiTransientDrawingMode::kAcGiMain)
        .value("kAcGiSprite", AcGiTransientDrawingMode::kAcGiSprite)
        .value("kAcGiDirectShortTerm", AcGiTransientDrawingMode::kAcGiDirectShortTerm)
        .value("kAcGiHighlight", AcGiTransientDrawingMode::kAcGiHighlight)
        .value("kAcGiDirectTopmost", AcGiTransientDrawingMode::kAcGiDirectTopmost)
        .value("kAcGiContrast", AcGiTransientDrawingMode::kAcGiContrast)
        .value("kAcGiDrawingModeCount", AcGiTransientDrawingMode::kAcGiDrawingModeCount)
        .export_values()
        ;

    enum_<AcGiPositionTransformBehavior>("AcGiPositionTransformBehavior")
        .value("kAcGiWorldPosition", AcGiPositionTransformBehavior::kAcGiWorldPosition)
        .value("kAcGiViewportPosition", AcGiPositionTransformBehavior::kAcGiViewportPosition)
        .value("kAcGiScreenPosition", AcGiPositionTransformBehavior::kAcGiScreenPosition)
        .value("kAcGiScreenLocalOriginPosition", AcGiPositionTransformBehavior::kAcGiScreenLocalOriginPosition)
        .value("kAcGiWorldWithScreenOffsetPosition", AcGiPositionTransformBehavior::kAcGiWorldWithScreenOffsetPosition)
        .export_values()
        ;
    enum_<AcGiScaleTransformBehavior>("AcGiScaleTransformBehavior")
        .value("kAcGiWorldScale", AcGiScaleTransformBehavior::kAcGiWorldScale)
        .value("kAcGiViewportScale", AcGiScaleTransformBehavior::kAcGiViewportScale)
        .value("kAcGiScreenScale", AcGiScaleTransformBehavior::kAcGiScreenScale)
        .value("kAcGiViewportLocalOriginScale", AcGiScaleTransformBehavior::kAcGiViewportLocalOriginScale)
        .value("kAcGiScreenLocalOriginScale", AcGiScaleTransformBehavior::kAcGiScreenLocalOriginScale)
        .export_values()
        ;
    enum_<AcGiOrientationTransformBehavior>("AcGiOrientationTransformBehavior")
        .value("kAcGiWorldOrientation", AcGiOrientationTransformBehavior::kAcGiWorldOrientation)
        .value("kAcGiScreenOrientation", AcGiOrientationTransformBehavior::kAcGiScreenOrientation)
        .value("kAcGiZAxisOrientation", AcGiOrientationTransformBehavior::kAcGiZAxisOrientation)
        .export_values()
        ;
    enum_<AcGiGeometry::TransparencyMode>("TransparencyMode")//TODO: check for clash
        .value("kTransparencyOff", AcGiGeometry::TransparencyMode::kTransparencyOff)
        .value("kTransparency1Bit", AcGiGeometry::TransparencyMode::kTransparency1Bit)
        .value("kTransparency8Bit", AcGiGeometry::TransparencyMode::kTransparency8Bit)
        .export_values()
        ;
    enum_<AcGiArcType>("AcGiArcType")
        .value("kAcGiArcSimple", AcGiArcType::kAcGiArcSimple)
        .value("kAcGiArcSector", AcGiArcType::kAcGiArcSector)
        .value("kAcGiArcChord", AcGiArcType::kAcGiArcChord)
        .export_values()
        ;
    enum_<AcGiOrientationType>("AcGiOrientationType")
        .value("kAcGiCounterClockwise", AcGiOrientationType::kAcGiCounterClockwise)
        .value("kAcGiNoOrientation", AcGiOrientationType::kAcGiNoOrientation)
        .value("kAcGiClockwise", AcGiOrientationType::kAcGiClockwise)
        .export_values()
        ;
    enum_<AcGiFillType>("AcGiFillType")
        .value("kAcGiFillAlways", AcGiFillType::kAcGiFillAlways)
        .value("kAcGiFillNever", AcGiFillType::kAcGiFillNever)
        .export_values()
        ;
    enum_<AcGiVisibility>("AcGiVisibility")
        .value("kAcGiInvisible", AcGiVisibility::kAcGiInvisible)
        .value("kAcGiVisible", AcGiVisibility::kAcGiVisible)
        .value("kAcGiSilhouette", AcGiVisibility::kAcGiSilhouette)
        .export_values()
        ;
    enum_<AcGiRegenType>("AcGiRegenType")
        .value("eAcGiRegenTypeInvalid", AcGiRegenType::eAcGiRegenTypeInvalid)
        .value("kAcGiStandardDisplay", AcGiRegenType::kAcGiStandardDisplay)
        .value("kAcGiHideOrShadeCommand", AcGiRegenType::kAcGiHideOrShadeCommand)
        .value("kAcGiShadedDisplay", AcGiRegenType::kAcGiShadedDisplay)
        .value("kAcGiForExplode", AcGiRegenType::kAcGiForExplode)
        .value("kAcGiSaveWorldDrawForProxy", AcGiRegenType::kAcGiSaveWorldDrawForProxy)
        .export_values()
        ;
}

void initPyGiModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGi);
}
