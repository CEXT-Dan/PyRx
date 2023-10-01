#include "stdafx.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------------------
//wrapper
std::string AcCmColorToString(const AcCmColor& s)
{
    return std::format("({},{},{})", s.red(), s.green(), s.blue());
}

std::string AcCmColorToStringRepr(const AcCmColor& s)
{
    return std::format("<{}.Color({},{},{})>", PyDbNamespace, s.red(), s.green(), s.blue());
}

static bool AcCmColorEqualsOperator(const AcCmColor& left, const AcCmColor& right)
{
    return left == right;
}
static bool AcCmColorNotEqualsOperator(const AcCmColor& left, const AcCmColor& right)
{
    return left != right;
}

void makePyCmColorWrapper()
{
    PyDocString DS("Color");
    class_<AcCmColor>("Color")
        .def("setNone", &AcCmColor::setNone, DS.ARGS())
        .def("setByBlock", &AcCmColor::setByBlock, DS.ARGS())
        .def("setForeground", &AcCmColor::setForeground, DS.ARGS())
        .def("setLayerOff", &AcCmColor::setLayerOff, DS.ARGS())
        .def("setByLayer", &AcCmColor::setByLayer, DS.ARGS())
        .def("isByColor", &AcCmColor::isByColor, DS.ARGS())
        .def("isByLayer", &AcCmColor::isByLayer, DS.ARGS())
        .def("isByBlock", &AcCmColor::isByBlock, DS.ARGS())
        .def("isByACI", &AcCmColor::isByACI, DS.ARGS())
        .def("isByPen", &AcCmColor::isByPen, DS.ARGS())
        .def("isForeground", &AcCmColor::isForeground, DS.ARGS())
        .def("isNone", &AcCmColor::isNone, DS.ARGS())
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmColor::setRGB, DS.ARGS({ "val : int" }))
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmColor::setRGB, DS.ARGS({ "red : int","green : int","blue : int" }))
        .def("red", &AcCmColor::red, DS.ARGS())
        .def("green", &AcCmColor::green, DS.ARGS())
        .def("blue", &AcCmColor::blue, DS.ARGS())
        .def("setCOLORREF", &AcCmColor::setCOLORREF, DS.ARGS({ "val : int" }))
        .def("getCOLORREF", &AcCmColor::getCOLORREF, DS.ARGS())
        .def("getRGB", &AcCmColor::getRGB, DS.ARGS())
        .def("setRGBM", &AcCmColor::setRGBM, DS.ARGS({ "val : int" }))
        .def("getRGBM", &AcCmColor::getRGBM, DS.ARGS())
        .def("colorIndex", &AcCmColor::colorIndex, DS.ARGS())
        .def("setColorIndex", &AcCmColor::setColorIndex, DS.ARGS({ "val : int" }))
        .def("penIndex", &AcCmColor::penIndex, DS.ARGS())
        .def("setPenIndex", &AcCmColor::setPenIndex, DS.ARGS({ "val : int" }))
        .def("entityColor", &AcCmColor::entityColor, DS.ARGS())
        //operators
        .def("__eq__", &AcCmColorEqualsOperator)
        .def("__ne__", &AcCmColorNotEqualsOperator)
        .def("__str__", &AcCmColorToString)
        .def("__repr__", &AcCmColorToStringRepr)
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmTransparency no conversion, so we don't need a py wrapper
void makePyCmTransparencyWrapper()
{
    class_<AcCmTransparency>("Transparency")
        .def(init<Adesk::UInt8>())
        .def(init<double>())
        .def("setAlpha", &AcCmTransparency::setAlpha)
        .def("setAlphaPercent", &AcCmTransparency::setAlphaPercent)
        .def("alpha", &AcCmTransparency::alpha)
        .def("alphaPercent", &AcCmTransparency::alphaPercent)
        .def("isByAlpha", &AcCmTransparency::isByAlpha)
        .def("isByBlock", &AcCmTransparency::isByBlock)
        .def("isByLayer", &AcCmTransparency::isByLayer)
        .def("isInvalid", &AcCmTransparency::isInvalid)
        .def("isClear", &AcCmTransparency::isClear)
        .def("isSolid", &AcCmTransparency::isSolid)
        //operators
        .def("__eq__", &AcCmTransparency::operator==)
        .def("__ne__", &AcCmTransparency::operator!=)
        ;

    enum_<AcCmTransparency::transparencyMethod>("TransparencyMethod")
        .value("kByLayer", AcCmTransparency::transparencyMethod::kByLayer)
        .value("kByBlock", AcCmTransparency::transparencyMethod::kByBlock)
        .value("kByAlpha", AcCmTransparency::transparencyMethod::kByAlpha)
        .value("kErrorValue", AcCmTransparency::transparencyMethod::kErrorValue)
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmEntityColor no conversion, so we don't need a py wrapper
void makePyCmEntityColorWrapper()
{
    class_<AcCmEntityColor>("EntityColor")
        .def(init<Adesk::UInt8, Adesk::UInt8, Adesk::UInt8>())
        .def("setNone", &AcCmEntityColor::setNone)
        .def("setByBlock", &AcCmEntityColor::setByBlock)
        .def("setForeground", &AcCmEntityColor::setForeground)
        .def("setByLayer", &AcCmEntityColor::setByLayer)
        .def("setLayerOff", &AcCmEntityColor::setLayerOff)
        .def("None", &AcCmEntityColor::None)
        .def("ByBlock", &AcCmEntityColor::ByBlock)
        .def("ByLayer", &AcCmEntityColor::ByLayer)
        .def("Foreground", &AcCmEntityColor::Foreground)
        .def("white", &AcCmEntityColor::white)
        .def("black", &AcCmEntityColor::black)
        .def("colorMethod", &AcCmEntityColor::colorMethod)
        .def("setColorIndex", &AcCmEntityColor::setColorIndex)
        .def("colorIndex", &AcCmEntityColor::colorIndex)
        .def("setLayerIndex", &AcCmEntityColor::setLayerIndex)
        .def("layerIndex", &AcCmEntityColor::layerIndex)
        .def("setPenIndex", &AcCmEntityColor::setPenIndex)
        .def("penIndex", &AcCmEntityColor::penIndex)
        .def("red", &AcCmEntityColor::red)
        .def("green", &AcCmEntityColor::green)
        .def("blue", &AcCmEntityColor::blue)
        .def("setCOLORREF", &AcCmEntityColor::setCOLORREF)
        .def("getCOLORREF", &AcCmEntityColor::getCOLORREF)
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmEntityColor::setRGB)
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmEntityColor::setRGB)
        .def("getRGB", &AcCmEntityColor::getRGB)
        .def("setRGBM", &AcCmEntityColor::setRGBM)
        .def("getRGBM", &AcCmEntityColor::getRGBM)
        .def("isByColor", &AcCmEntityColor::isByColor)
        .def("isByLayer", &AcCmEntityColor::isByLayer)
        .def("isByBlock", &AcCmEntityColor::isByBlock)
        .def("isByACI", &AcCmEntityColor::isByACI)
        .def("isByPen", &AcCmEntityColor::isByPen)
        .def("isForeground", &AcCmEntityColor::isForeground)
        .def("isLayerOff", &AcCmEntityColor::isLayerOff)
        .def("isLayerFrozen", &AcCmEntityColor::isLayerFrozen)
        .def("isNone", &AcCmEntityColor::isNone)
        .def("isLayerFrozenOrOff", &AcCmEntityColor::isLayerFrozenOrOff)
        .def("canResolveRGB", &AcCmEntityColor::canResolveRGB)
        .def("makeTrueColor", &AcCmEntityColor::makeTrueColor)
        .def("None", &AcCmEntityColor::None).staticmethod("None")
        .def("ByBlock", &AcCmEntityColor::ByBlock).staticmethod("ByBlock")
        .def("ByLayer", &AcCmEntityColor::ByLayer).staticmethod("ByLayer")
        .def("Foreground", &AcCmEntityColor::Foreground).staticmethod("Foreground")
        .def("white", &AcCmEntityColor::white).staticmethod("white")
        .def("black", &AcCmEntityColor::black).staticmethod("black")
        .def("__eq__", &AcCmEntityColor::operator==)
        .def("__ne__", &AcCmEntityColor::operator!=)
        ;
    enum_<AcCmEntityColor::ColorMethod>("ColorMethod")
        .value("kByLayer", AcCmEntityColor::ColorMethod::kByLayer)
        .value("kByBlock", AcCmEntityColor::ColorMethod::kByBlock)
        .value("kByColor", AcCmEntityColor::ColorMethod::kByColor)
        .value("kByACI", AcCmEntityColor::ColorMethod::kByACI)
        .value("kByPen", AcCmEntityColor::ColorMethod::kByPen)
        .value("kForeground", AcCmEntityColor::ColorMethod::kForeground)
        .value("kLayerOff", AcCmEntityColor::ColorMethod::kLayerOff)
        .value("kLayerFrozen", AcCmEntityColor::ColorMethod::kLayerFrozen)
        .value("kNone", AcCmEntityColor::ColorMethod::kNone)
        ;
    enum_<AcCmEntityColor::ACIcolorMethod>("ACIcolorMethod")
        .value("kACIbyBlock", AcCmEntityColor::ACIcolorMethod::kACIbyBlock)
        .value("kACIforeground", AcCmEntityColor::ACIcolorMethod::kACIforeground)
        .value("kACIbyLayer", AcCmEntityColor::ACIcolorMethod::kACIbyLayer)
        .value("kACIclear", AcCmEntityColor::ACIcolorMethod::kACIclear)
        .value("kACIstandard", AcCmEntityColor::ACIcolorMethod::kACIstandard)
        .value("kACImaximum", AcCmEntityColor::ACIcolorMethod::kACImaximum)
        .value("kACInone", AcCmEntityColor::ACIcolorMethod::kACInone)
        .value("kACIminimum", AcCmEntityColor::ACIcolorMethod::kACIminimum)
        .value("kACIfrozenLayer", AcCmEntityColor::ACIcolorMethod::kACIfrozenLayer)
        ;
}