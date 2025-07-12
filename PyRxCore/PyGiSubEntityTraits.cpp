#include "stdafx.h"
#include "PyGiSubEntityTraits.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper()
{
    PyDocString DS("SubEntityTraits");
    class_<PyGiSubEntityTraits, bases<PyRxObject>>("SubEntityTraits", boost::python::no_init)
        .def("setColor", &PyGiSubEntityTraits::setColor, DS.ARGS({ "val: int" }))
        .def("setTrueColor", &PyGiSubEntityTraits::setTrueColor, DS.ARGS({ "clr: PyDb.EntityColor" }))
        .def("setLayer", &PyGiSubEntityTraits::setLayer, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setLineType", &PyGiSubEntityTraits::setLineType, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setSelectionMarker", &PyGiSubEntityTraits::setSelectionMarker, DS.ARGS({ "val: int" }))
        .def("setFillType", &PyGiSubEntityTraits::setFillType, DS.ARGS({ "val: PyGi.FillType" }))
        .def("setLineWeight", &PyGiSubEntityTraits::setLineWeight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("setLineTypeScale", &PyGiSubEntityTraits::setLineTypeScale1)
        .def("setLineTypeScale", &PyGiSubEntityTraits::setLineTypeScale2, DS.ARGS({ "val: float=1.0" }))
        .def("setThickness", &PyGiSubEntityTraits::setThickness, DS.ARGS({ "val: float" }))
        .def("setVisualStyle", &PyGiSubEntityTraits::setVisualStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setPlotStyleName", &PyGiSubEntityTraits::setPlotStyleName1)
        .def("setPlotStyleName", &PyGiSubEntityTraits::setPlotStyleName2, DS.ARGS({ "val: PyDb.PlotStyleNameType","id: PyDb.ObjectId = ..." }))
        .def("setMaterial", &PyGiSubEntityTraits::setMaterial, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setSectionable", &PyGiSubEntityTraits::setSectionable, DS.ARGS({ "val: bool" }))
        .def("setDrawFlags", &PyGiSubEntityTraits::setDrawFlags, DS.ARGS({ "flags: int" }))
        .def("setShadowFlags", &PyGiSubEntityTraits::setShadowFlags, DS.ARGS({ "val: PyGi.ShadowFlags" }))
        .def("setSelectionGeom", &PyGiSubEntityTraits::setSelectionGeom, DS.ARGS({ "val: bool" }))
        .def("setTransparency", &PyGiSubEntityTraits::setTransparency, DS.ARGS({ "val: PyDb.Transparency" }))
        .def("color", &PyGiSubEntityTraits::color, DS.ARGS())
        .def("trueColor", &PyGiSubEntityTraits::trueColor, DS.ARGS())
        .def("layerId", &PyGiSubEntityTraits::layerId, DS.ARGS())
        .def("lineTypeId", &PyGiSubEntityTraits::lineTypeId, DS.ARGS())
        .def("fillType", &PyGiSubEntityTraits::fillType, DS.ARGS())
        .def("lineWeight", &PyGiSubEntityTraits::lineWeight, DS.ARGS())
        .def("lineTypeScale", &PyGiSubEntityTraits::lineTypeScale, DS.ARGS())
        .def("thickness", &PyGiSubEntityTraits::thickness, DS.ARGS())
        .def("visualStyle", &PyGiSubEntityTraits::visualStyle, DS.ARGS())
        .def("getPlotStyleNameId", &PyGiSubEntityTraits::getPlotStyleNameId, DS.ARGS())
        .def("materialId", &PyGiSubEntityTraits::materialId, DS.ARGS())
        .def("sectionable", &PyGiSubEntityTraits::sectionable, DS.ARGS())
        .def("drawFlags", &PyGiSubEntityTraits::drawFlags, DS.ARGS())
        .def("shadowFlags", &PyGiSubEntityTraits::shadowFlags, DS.ARGS())
        .def("selectionGeom", &PyGiSubEntityTraits::selectionGeom, DS.ARGS())
        .def("transparency", &PyGiSubEntityTraits::transparency, DS.ARGS())
        .def("className", &PyGiSubEntityTraits::className).staticmethod("className")
        .def("desc", &PyGiSubEntityTraits::desc, DS.SARGS(15560)).staticmethod("desc")
        ;

    enum_<AcGiSubEntityTraits::DrawFlags>("DrawFlags")
        .value("kNoDrawFlags", AcGiSubEntityTraits::DrawFlags::kNoDrawFlags)
        .value("kDrawHatchGroup", AcGiSubEntityTraits::DrawFlags::kDrawHatchGroup)
        .value("kDrawFrontfacesOnly", AcGiSubEntityTraits::DrawFlags::kDrawFrontfacesOnly)
        .value("kDrawGradientFill", AcGiSubEntityTraits::DrawFlags::kDrawGradientFill)
        .value("kDrawSolidFill", AcGiSubEntityTraits::DrawFlags::kDrawSolidFill)
        .value("kDrawNoLineWeight", AcGiSubEntityTraits::DrawFlags::kDrawNoLineWeight)
        .value("kDrawNoOptimization", AcGiSubEntityTraits::DrawFlags::kDrawNoOptimization)
        .value("kDrawUseAcGiEntityForDgnLineType", AcGiSubEntityTraits::DrawFlags::kDrawUseAcGiEntityForDgnLineType)
        .value("kDrawFillTextBoundaryStart", AcGiSubEntityTraits::DrawFlags::kDrawFillTextBoundaryStart)
        .value("kDrawFillTextBoundaryEnd", AcGiSubEntityTraits::DrawFlags::kDrawFillTextBoundaryEnd)
        .value("kDrawFillSelectionWindow", AcGiSubEntityTraits::DrawFlags::kDrawFillSelectionWindow)
        .value("kDrawNoForceByLayer", AcGiSubEntityTraits::DrawFlags::kDrawNoForceByLayer)

        //DOH! the K lol!
#if defined(_ARXTARGET) && (_ARXTARGET == 242)
        .value("kDrawIsInWCS", AcGiSubEntityTraits::DrawFlags::KDrawIsInWCS)
#endif
#if defined(_ARXTARGET) && (_ARXTARGET >= 243)
        .value("kDrawIsInWCS", AcGiSubEntityTraits::DrawFlags::kDrawIsInWCS)
        .value("kDrawNoImageFrame", AcGiSubEntityTraits::DrawFlags::kDrawNoImageFrame)
#endif
        .export_values()
        ;

    enum_<AcGiSubEntityTraits::ShadowFlags>("ShadowFlags")
        .value("kNoDrawFlags", AcGiSubEntityTraits::ShadowFlags::kShadowsCastAndReceive)
        .value("kShadowsDoesNotCast", AcGiSubEntityTraits::ShadowFlags::kShadowsDoesNotCast)
        .value("kShadowsDoesNotReceive", AcGiSubEntityTraits::ShadowFlags::kShadowsDoesNotReceive)
        .value("kShadowsIgnore", AcGiSubEntityTraits::ShadowFlags::kShadowsIgnore)
        .export_values()
        ;

#if !defined(_BRXTARGET260)
    enum_<AcGiSubEntityTraits::SelectionFlags>("SelectionFlags")
        .value("kNoSelectionFlags", AcGiSubEntityTraits::SelectionFlags::kNoSelectionFlags)
        .value("kSelectionIgnore", AcGiSubEntityTraits::SelectionFlags::kSelectionIgnore)
        .export_values()
        ;
#endif
}

PyGiSubEntityTraits::PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

void PyGiSubEntityTraits::setColor(const Adesk::UInt16 color) const
{
    impObj()->setColor(color);
}

void PyGiSubEntityTraits::setTrueColor(const AcCmEntityColor& color) const
{
    impObj()->setTrueColor(color);
}

void PyGiSubEntityTraits::setLayer(const PyDbObjectId& layerId) const
{
    impObj()->setLayer(layerId.m_id);
}

void PyGiSubEntityTraits::setLineType(const PyDbObjectId& linetypeId) const
{
    impObj()->setLineType(linetypeId.m_id);
}

void PyGiSubEntityTraits::setSelectionMarker(const Adesk::LongPtr markerId) const
{
    impObj()->setSelectionMarker(markerId);
}

void PyGiSubEntityTraits::setFillType(const AcGiFillType val) const
{
    impObj()->setFillType(val);
}

void PyGiSubEntityTraits::setLineWeight(const AcDb::LineWeight lw) const
{
    impObj()->setLineWeight(lw);
}

void PyGiSubEntityTraits::setLineTypeScale1() const
{
    impObj()->setLineTypeScale();
}

void PyGiSubEntityTraits::setLineTypeScale2(double dScale) const
{
    impObj()->setLineTypeScale(dScale);
}

void PyGiSubEntityTraits::setThickness(double dThickness) const
{
    impObj()->setThickness(dThickness);
}

void PyGiSubEntityTraits::setVisualStyle(const PyDbObjectId& visualStyleId) const
{
    impObj()->setVisualStyle(visualStyleId.m_id);
}

void PyGiSubEntityTraits::setPlotStyleName1(AcDb::PlotStyleNameType val) const
{
    impObj()->setPlotStyleName(val);
}

void PyGiSubEntityTraits::setPlotStyleName2(AcDb::PlotStyleNameType val, const PyDbObjectId& id) const
{
    impObj()->setPlotStyleName(val, id.m_id);
}

void PyGiSubEntityTraits::setMaterial(const PyDbObjectId& materialId) const
{
    impObj()->setMaterial(materialId.m_id);
}

void PyGiSubEntityTraits::setSectionable(bool bSectionable) const
{
    impObj()->setSectionable(bSectionable);
}

void PyGiSubEntityTraits::setDrawFlags(Adesk::UInt32 flags) const
{
    return PyThrowBadEs(impObj()->setDrawFlags(flags));
}

void PyGiSubEntityTraits::setShadowFlags(AcGiSubEntityTraits::ShadowFlags flags) const
{
    return PyThrowBadEs(impObj()->setShadowFlags(flags));
}

void PyGiSubEntityTraits::setSelectionGeom(bool bSelectionflag) const
{
    impObj()->setSelectionGeom(bSelectionflag);
}

void PyGiSubEntityTraits::setTransparency(const AcCmTransparency& transparency) const
{
    impObj()->setTransparency(transparency);
}

Adesk::UInt16 PyGiSubEntityTraits::color(void) const
{
    return  impObj()->color();
}

AcCmEntityColor PyGiSubEntityTraits::trueColor(void) const
{
    return  impObj()->trueColor();
}

PyDbObjectId PyGiSubEntityTraits::layerId(void) const
{
    return PyDbObjectId(impObj()->layerId());
}

PyDbObjectId PyGiSubEntityTraits::lineTypeId(void) const
{
    return PyDbObjectId(impObj()->lineTypeId());
}

AcGiFillType PyGiSubEntityTraits::fillType(void) const
{
    return  impObj()->fillType();
}

AcDb::LineWeight PyGiSubEntityTraits::lineWeight(void) const
{
    return  impObj()->lineWeight();
}

double PyGiSubEntityTraits::lineTypeScale(void) const
{
    return  impObj()->lineTypeScale();
}

double PyGiSubEntityTraits::thickness(void) const
{
    return  impObj()->thickness();
}

PyDbObjectId PyGiSubEntityTraits::visualStyle(void) const
{
    return PyDbObjectId(impObj()->visualStyle());
}

PyDbObjectId PyGiSubEntityTraits::getPlotStyleNameId() const
{
    AcDbObjectId id;
    impObj()->getPlotStyleNameId(id);
    return PyDbObjectId(id);
}

PyDbObjectId PyGiSubEntityTraits::materialId(void) const
{
    return PyDbObjectId(impObj()->materialId());
}

bool PyGiSubEntityTraits::sectionable(void) const
{
    return  impObj()->sectionable();
}

Adesk::UInt32 PyGiSubEntityTraits::drawFlags(void) const
{
    return  impObj()->drawFlags();
}

AcGiSubEntityTraits::ShadowFlags PyGiSubEntityTraits::shadowFlags(void) const
{
    return  impObj()->shadowFlags();
}

bool PyGiSubEntityTraits::selectionGeom(void) const
{
    return  impObj()->selectionGeom();
}

AcCmTransparency PyGiSubEntityTraits::transparency(void) const
{
    return  impObj()->transparency();
}

std::string PyGiSubEntityTraits::className()
{
    return "AcGiSubEntityTraits";
}

PyRxClass PyGiSubEntityTraits::desc()
{
    return PyRxClass(AcGiSubEntityTraits::desc(), false);
}

AcGiSubEntityTraits* PyGiSubEntityTraits::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiSubEntityTraits*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiDrawableTraits
void makePyGiDrawableTraitsWrapper()
{
    PyDocString DS("DrawableTraits");
    class_<PyGiDrawableTraits, bases<PyGiSubEntityTraits>>("DrawableTraits", boost::python::no_init)
        .def("setupForEntity", &PyGiDrawableTraits::setupForEntity, DS.ARGS({ "entity: PyDb.Entity" }, 13052))
        .def("className", &PyGiDrawableTraits::className).staticmethod("className")
        .def("desc", &PyGiDrawableTraits::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyGiDrawableTraits::PyGiDrawableTraits(AcGiDrawableTraits* ptr, bool autoDelete)
    : PyGiSubEntityTraits(ptr, autoDelete)
{
}

void PyGiDrawableTraits::setupForEntity(PyDbEntity& pEntity) const
{
    impObj()->setupForEntity(pEntity.impObj());
}

std::string PyGiDrawableTraits::className()
{
    return "AcGiDrawableTraits";
}

PyRxClass PyGiDrawableTraits::desc()
{
    return PyRxClass(AcGiDrawableTraits::desc(), false);
}

AcGiDrawableTraits* PyGiDrawableTraits::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiDrawableTraits*>(m_pyImp.get());
}
