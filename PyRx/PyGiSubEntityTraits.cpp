#include "stdafx.h"
#include "PyGiSubEntityTraits.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper()
{
    class_<PyGiSubEntityTraits, bases<PyRxObject>>("SubEntityTraits", boost::python::no_init)
        .def("setColor", &PyGiSubEntityTraits::setColor)
        .def("setTrueColor", &PyGiSubEntityTraits::setTrueColor)
        .def("setLayer", &PyGiSubEntityTraits::setLayer)
        .def("setLineType", &PyGiSubEntityTraits::setLineType)
        .def("setSelectionMarker", &PyGiSubEntityTraits::setSelectionMarker)
        .def("setFillType", &PyGiSubEntityTraits::setFillType)
        .def("setLineWeight", &PyGiSubEntityTraits::setLineWeight)
        .def("setLineTypeScale", &PyGiSubEntityTraits::setLineTypeScale1)
        .def("setLineTypeScale", &PyGiSubEntityTraits::setLineTypeScale2)
        .def("setThickness", &PyGiSubEntityTraits::setThickness)
        .def("setVisualStyle", &PyGiSubEntityTraits::setVisualStyle)
        .def("setPlotStyleName", &PyGiSubEntityTraits::setPlotStyleName1)
        .def("setPlotStyleName", &PyGiSubEntityTraits::setPlotStyleName2)
        .def("setMaterial", &PyGiSubEntityTraits::setMaterial)
        .def("setSectionable", &PyGiSubEntityTraits::setSectionable)
        .def("setDrawFlags", &PyGiSubEntityTraits::setDrawFlags)
        .def("setShadowFlags", &PyGiSubEntityTraits::setShadowFlags)
        .def("setSelectionGeom", &PyGiSubEntityTraits::setSelectionGeom)
        .def("setTransparency", &PyGiSubEntityTraits::setTransparency)
        .def("color", &PyGiSubEntityTraits::color)
        .def("trueColor", &PyGiSubEntityTraits::trueColor)
        .def("layerId", &PyGiSubEntityTraits::layerId)
        .def("lineTypeId", &PyGiSubEntityTraits::lineTypeId)
        .def("fillType", &PyGiSubEntityTraits::fillType)
        .def("lineWeight", &PyGiSubEntityTraits::lineWeight)
        .def("lineTypeScale", &PyGiSubEntityTraits::lineTypeScale)
        .def("thickness", &PyGiSubEntityTraits::thickness)
        .def("visualStyle", &PyGiSubEntityTraits::visualStyle)
        .def("getPlotStyleNameId", &PyGiSubEntityTraits::getPlotStyleNameId)
        .def("materialId", &PyGiSubEntityTraits::materialId)
        .def("sectionable", &PyGiSubEntityTraits::sectionable)
        .def("drawFlags", &PyGiSubEntityTraits::drawFlags)
        .def("shadowFlags", &PyGiSubEntityTraits::shadowFlags)
        .def("selectionGeom", &PyGiSubEntityTraits::selectionGeom)
        .def("transparency", &PyGiSubEntityTraits::transparency)
        .def("className", &PyGiSubEntityTraits::className).staticmethod("className")
        .def("desc", &PyGiSubEntityTraits::desc).staticmethod("desc")
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
#ifdef ARXAPP
        .value("KDrawIsInWCS", AcGiSubEntityTraits::DrawFlags::KDrawIsInWCS)
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
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    enum_<AcGiSubEntityTraits::SelectionFlags>("SelectionFlags")
        .value("kNoSelectionFlags", AcGiSubEntityTraits::SelectionFlags::kNoSelectionFlags)
        .value("kSelectionIgnore", AcGiSubEntityTraits::SelectionFlags::kSelectionIgnore)
        .export_values()
        ;
#endif // !BRXAPP
}

PyGiSubEntityTraits::PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

void PyGiSubEntityTraits::setColor(const Adesk::UInt16 color)
{
    impObj()->setColor(color);
}

void PyGiSubEntityTraits::setTrueColor(const AcCmEntityColor& color)
{
    impObj()->setTrueColor(color);
}

void PyGiSubEntityTraits::setLayer(const PyDbObjectId& layerId)
{
    impObj()->setLayer(layerId.m_id);
}

void PyGiSubEntityTraits::setLineType(const PyDbObjectId& linetypeId)
{
    impObj()->setLineType(linetypeId.m_id);
}

void PyGiSubEntityTraits::setSelectionMarker(const Adesk::LongPtr markerId)
{
    impObj()->setSelectionMarker(markerId);
}

void PyGiSubEntityTraits::setFillType(const AcGiFillType val)
{
    impObj()->setSelectionMarker(val);
}

void PyGiSubEntityTraits::setLineWeight(const AcDb::LineWeight lw)
{
    impObj()->setLineWeight(lw);
}

void PyGiSubEntityTraits::setLineTypeScale1()
{
    impObj()->setLineTypeScale();
}

void PyGiSubEntityTraits::setLineTypeScale2(double dScale)
{
    impObj()->setLineTypeScale(dScale);
}

void PyGiSubEntityTraits::setThickness(double dThickness)
{
    impObj()->setThickness(dThickness);
}

void PyGiSubEntityTraits::setVisualStyle(const PyDbObjectId& visualStyleId)
{
    impObj()->setVisualStyle(visualStyleId.m_id);
}

void PyGiSubEntityTraits::setPlotStyleName1(AcDb::PlotStyleNameType val)
{
    impObj()->setPlotStyleName(val);
}

void PyGiSubEntityTraits::setPlotStyleName2(AcDb::PlotStyleNameType val, const PyDbObjectId& id)
{
    impObj()->setPlotStyleName(val, id.m_id);
}

void PyGiSubEntityTraits::setMaterial(const PyDbObjectId& materialId)
{
    impObj()->setMaterial(materialId.m_id);
}

void PyGiSubEntityTraits::setSectionable(bool bSectionable)
{
    impObj()->setSectionable(bSectionable);
}

void PyGiSubEntityTraits::setDrawFlags(Adesk::UInt32 flags)
{
    return PyThrowBadEs(impObj()->setDrawFlags(flags));
}

void PyGiSubEntityTraits::setShadowFlags(AcGiSubEntityTraits::ShadowFlags flags)
{
    return PyThrowBadEs(impObj()->setShadowFlags(flags));
}

void PyGiSubEntityTraits::setSelectionGeom(bool bSelectionflag)
{
    impObj()->setSelectionGeom(bSelectionflag);
}

void PyGiSubEntityTraits::setTransparency(const AcCmTransparency& transparency)
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcGiSubEntityTraits*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiDrawableTraits
void makePyGiDrawableTraitsWrapper()
{
    class_<PyGiDrawableTraits, bases<PyGiSubEntityTraits>>("DrawableTraits", boost::python::no_init)
        .def("className", &PyGiDrawableTraits::className).staticmethod("className")
        .def("desc", &PyGiDrawableTraits::desc).staticmethod("desc")
        ;
}

PyGiDrawableTraits::PyGiDrawableTraits(AcGiDrawableTraits* ptr, bool autoDelete)
    : PyGiSubEntityTraits(ptr, autoDelete)
{
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcGiDrawableTraits*>(m_pyImp.get());
}
