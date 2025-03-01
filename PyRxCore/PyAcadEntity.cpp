#include "stdafx.h"
#include "PyAcadEntity.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObject.h"
#include "PyAcadObjectImpl.h"
using namespace boost::python;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper()
{
    PyDocString DS("AcadEntity");
    class_<PyAcadEntity, bases<PyAcadObject>>("AcadEntity", boost::python::no_init)
        .def("trueColor", &PyAcadEntity::trueColor, DS.ARGS())
        .def("setTrueColor", &PyAcadEntity::setTrueColor, DS.ARGS({ "trueColor: PyAx.AcadAcCmColor" }))
        .def("layer", &PyAcadEntity::layer, DS.ARGS())
        .def("setLayer", &PyAcadEntity::setLayer, DS.ARGS({ "layer:str" }))
        .def("linetype", &PyAcadEntity::linetype, DS.ARGS())
        .def("setLinetype", &PyAcadEntity::setLinetype, DS.ARGS({ "linetype:str" }))
        .def("linetypeScale", &PyAcadEntity::linetypeScale, DS.ARGS())
        .def("setLinetypeScale", &PyAcadEntity::setLinetypeScale, DS.ARGS({ "linetypeScale:float" }))
        .def("isVisible", &PyAcadEntity::isVisible, DS.ARGS())
        .def("setVisible", &PyAcadEntity::setVisible, DS.ARGS({ "bVisible:bool" }))
        .def("arrayPolar", &PyAcadEntity::arrayPolar, DS.ARGS({ "numberOfObjects:int","angleToFill:float","centerPoint:PyGe.Point3d" }))
        .def("arrayRectangular", &PyAcadEntity::arrayPolar, DS.ARGS({ "nRows:int","nColumns:int","nLevels:int","rowDist:float","colDist:float","levelDist:float" }))
        .def("highlight", &PyAcadEntity::highlight, DS.ARGS({ "bHighlight:bool" }))
        .def("copy", &PyAcadEntity::copy, DS.ARGS())
        .def("move", &PyAcadEntity::move, DS.ARGS({ "fromPoint:PyGe.Point3d","toPoint:PyGe.Point3d" }))
        .def("rotate", &PyAcadEntity::rotate, DS.ARGS({ "basePoint:PyGe.Point3d","rotationAngle:float" }))
        .def("rotate3D", &PyAcadEntity::rotate3D, DS.ARGS({ "point1:PyGe.Point3d","point2:PyGe.Point3d","rotationAngle:float" }))
        .def("mirror", &PyAcadEntity::mirror, DS.ARGS({ "point1:PyGe.Point3d","point2:PyGe.Point3d" }))
        .def("mirror3D", &PyAcadEntity::mirror3D, DS.ARGS({ "point1:PyGe.Point3d","point2:PyGe.Point3d","point3:PyGe.Point3d" }))
        .def("scaleEntity", &PyAcadEntity::scaleEntity, DS.ARGS({ "basePoint:PyGe.Point3d","scaleFactor:float" }))
        .def("transformBy", &PyAcadEntity::transformBy, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("update", &PyAcadEntity::update, DS.ARGS())
        .def("boundingBox", &PyAcadEntity::boundingBox, DS.ARGS())
        .def("intersectWith", &PyAcadEntity::intersectWith, DS.ARGS({ "intersectObject:PyAx.AcadEntity","option:PyAx.AcExtendOption" }))
        .def("plotStyleName", &PyAcadEntity::plotStyleName, DS.ARGS())
        .def("setPlotStyleName", &PyAcadEntity::setPlotStyleName, DS.ARGS({ "plotStyleName:str" }))
        .def("lineweight", &PyAcadEntity::lineweight, DS.ARGS())
        .def("setLineweight", &PyAcadEntity::setLineweight, DS.ARGS({ "lineweight:PyAx.AcLineWeight" }))
        .def("entityTransparency", &PyAcadEntity::entityTransparency, DS.ARGS())
        .def("setEntityTransparency", &PyAcadEntity::setEntityTransparency, DS.ARGS({ "entityTransparency:str" }))
        .def("hyperlinks", &PyAcadEntity::hyperlinks, DS.ARGS())
        .def("material", &PyAcadEntity::material, DS.ARGS())
        .def("setMaterial", &PyAcadEntity::setMaterial, DS.ARGS({ "material:str" }))
        .def("entityName", &PyAcadEntity::entityName, DS.ARGS())
        .def("entityType", &PyAcadEntity::entityType, DS.ARGS())
        .def("color", &PyAcadEntity::color, DS.ARGS())
        .def("setColor", &PyAcadEntity::setColor, DS.ARGS({ "color:PyAx.AcColor" }))
        .def("className", &PyAcadEntity::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyAcadEntity::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        ;
}

PyAcadEntity::PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr)
    :PyAcadObject(ptr)
{
}

PyAcadAcCmColor PyAcadEntity::trueColor() const
{
    return PyAcadAcCmColor{ impObj()->GetTrueColor() };
}

void PyAcadEntity::setTrueColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetTrueColor(*val.impObj());
}

std::string PyAcadEntity::layer() const
{
    return wstr_to_utf8(impObj()->GetLayer());
}

void PyAcadEntity::setLayer(const std::string& val)
{
    impObj()->SetLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadEntity::linetype() const
{
    return wstr_to_utf8(impObj()->GetLinetype());
}

void PyAcadEntity::setLinetype(const std::string& val)
{
    impObj()->SetLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadEntity::linetypeScale() const
{
    return impObj()->GetLinetypeScale();
}

void PyAcadEntity::setLinetypeScale(double val)
{
    impObj()->SetLinetypeScale(val);
}

bool PyAcadEntity::isVisible() const
{
    return impObj()->GetVisible();
}

void PyAcadEntity::setVisible(bool bVisible)
{
    impObj()->SetVisible(bVisible);
}

boost::python::list PyAcadEntity::arrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->ArrayPolar(numberOfObjects, angleToFill, centerPoint))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

boost::python::list PyAcadEntity::arrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->ArrayRectangular(nRows, nColumns, nLevels, rowDist, colDist, levelDist))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

void PyAcadEntity::highlight(bool highlight)
{
    impObj()->Highlight(highlight);
}

PyAcadEntity PyAcadEntity::copy()
{
    return PyAcadEntity{ impObj()->Copy() };
}

void PyAcadEntity::move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint)
{
    impObj()->Move(fromPoint, toPoint);
}

void PyAcadEntity::rotate(const AcGePoint3d& basePoint, double rotationAngle)
{
    impObj()->Rotate(basePoint, rotationAngle);
}

void PyAcadEntity::rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle)
{
    impObj()->Rotate3D(point1, point2, rotationAngle);
}

PyAcadEntity PyAcadEntity::mirror(const AcGePoint3d& point1, const AcGePoint3d& point2)
{
    return PyAcadEntity{ impObj()->Mirror(point1, point2) };
}

PyAcadEntity PyAcadEntity::mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3)
{
    return PyAcadEntity{ impObj()->Mirror3D(point1, point2, point3) };
}

void PyAcadEntity::scaleEntity(const AcGePoint3d& basePoint, double scaleFactor)
{
    impObj()->ScaleEntity(basePoint, scaleFactor);
}

void PyAcadEntity::transformBy(const AcGeMatrix3d& xform)
{
    impObj()->TransformBy(xform);
}

void PyAcadEntity::update()
{
    impObj()->Update();
}

boost::python::tuple PyAcadEntity::boundingBox()
{
    AcGePoint3d minp;
    AcGePoint3d maxp;
    impObj()->GetBoundingBox(minp, maxp);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(minp, maxp);
}

boost::python::list PyAcadEntity::intersectWith(const PyAcadEntity& intersectObject, PyAcExtendOption option)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->IntersectWith(*intersectObject.impObj(), option))
        pylist.append(item);
    return pylist;
}

std::string PyAcadEntity::plotStyleName() const
{
    return wstr_to_utf8(impObj()->GetPlotStyleName());
}

void PyAcadEntity::setPlotStyleName(const std::string& val)
{
    impObj()->SetPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadEntity::lineweight() const
{
    return impObj()->GetLineweight();
}

void PyAcadEntity::setLineweight(PyAcLineWeight lw)
{
    impObj()->SetLineweight(lw);
}

std::string PyAcadEntity::entityTransparency() const
{
    return wstr_to_utf8(impObj()->GetEntityTransparency());
}

void PyAcadEntity::setEntityTransparency(const std::string& val)
{
    impObj()->SetEntityTransparency(utf8_to_wstr(val).c_str());
}

PyAcadHyperlinks PyAcadEntity::hyperlinks() const
{
    return PyAcadHyperlinks{ impObj()->GetHyperlinks() };
}

std::string PyAcadEntity::material() const
{
    return wstr_to_utf8(impObj()->GetMaterial());
}

void PyAcadEntity::setMaterial(const std::string& val)
{
    impObj()->SetMaterial(utf8_to_wstr(val).c_str());
}

std::string PyAcadEntity::entityName() const
{
    return wstr_to_utf8(impObj()->GetEntityName());
}

long PyAcadEntity::entityType() const
{
    return impObj()->GetEntityType();
}

PyAcColor PyAcadEntity::color() const
{
    return impObj()->GetColor();
}

void PyAcadEntity::setColor(PyAcColor color)
{
    impObj()->SetColor(color);
}

PyAcadEntity PyAcadEntity::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadEntity>(src);
}

std::string PyAcadEntity::className()
{
    return "AcDbEntity";
}

PyIAcadEntityImpl* PyAcadEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadEntityImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPViewport
void makePyAcadPViewportWrapper()
{
    PyDocString DS("AcadPViewport");
    class_<PyAcadPViewport, bases<PyAcadEntity>>("AcadPViewport", boost::python::no_init)
        .def("center", &PyAcadPViewport::center, DS.ARGS())
        .def("setCenter", &PyAcadPViewport::setCenter, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("direction", &PyAcadPViewport::direction, DS.ARGS())
        .def("setDirection", &PyAcadPViewport::setDirection, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("gridOn", &PyAcadPViewport::gridOn, DS.ARGS())
        .def("setGridOn", &PyAcadPViewport::setGridOn, DS.ARGS({ "val:bool" }))
        .def("height", &PyAcadPViewport::height, DS.ARGS())
        .def("setHeight", &PyAcadPViewport::setHeight, DS.ARGS({ "val:float" }))
        .def("width", &PyAcadPViewport::width, DS.ARGS())
        .def("setWidth", &PyAcadPViewport::setWidth, DS.ARGS({ "val:float" }))
        .def("viewportOn", &PyAcadPViewport::viewportOn, DS.ARGS())
        .def("setViewportOn", &PyAcadPViewport::setViewportOn, DS.ARGS({ "val:bool" }))
        .def("clipped", &PyAcadPViewport::clipped, DS.ARGS())
        .def("displayLocked", &PyAcadPViewport::displayLocked, DS.ARGS())
        .def("setDisplayLocked", &PyAcadPViewport::setDisplayLocked, DS.ARGS({ "val:bool" }))
        .def("standardScale", &PyAcadPViewport::standardScale, DS.ARGS())
        .def("setStandardScale", &PyAcadPViewport::setStandardScale, DS.ARGS({ "val:PyAx.AcViewportScale" }))
        .def("customScale", &PyAcadPViewport::customScale, DS.ARGS())
        .def("setCustomScale", &PyAcadPViewport::setCustomScale, DS.ARGS({ "val:float" }))
        .def("styleSheet", &PyAcadPViewport::styleSheet, DS.ARGS())
        .def("setStyleSheet", &PyAcadPViewport::setStyleSheet, DS.ARGS({ "val:str" }))
        .def("ucsPerViewport", &PyAcadPViewport::ucsPerViewport, DS.ARGS())
        .def("setUCSPerViewport", &PyAcadPViewport::setUCSPerViewport, DS.ARGS({ "val:bool" }))
        .def("snapBasePoint", &PyAcadPViewport::snapBasePoint, DS.ARGS())
        .def("setSnapBasePoint", &PyAcadPViewport::setSnapBasePoint, DS.ARGS({ "val:PyGe.Point2d" }))
        .def("snapOn", &PyAcadPViewport::snapOn, DS.ARGS())
        .def("setSnapOn", &PyAcadPViewport::setSnapOn, DS.ARGS({ "val:bool" }))
        .def("snapRotationAngle", &PyAcadPViewport::snapRotationAngle, DS.ARGS())
        .def("setSnapRotationAngle", &PyAcadPViewport::setSnapRotationAngle, DS.ARGS({ "val:float" }))
        .def("ucsIconOn", &PyAcadPViewport::ucsIconOn, DS.ARGS())
        .def("setUCSIconOn", &PyAcadPViewport::setUCSIconOn, DS.ARGS({ "val:bool" }))
        .def("ucsIconAtOrigin", &PyAcadPViewport::ucsIconAtOrigin, DS.ARGS())
        .def("setUCSIconAtOrigin", &PyAcadPViewport::setUCSIconAtOrigin, DS.ARGS({ "val:bool" }))
        .def("gridSpacing", &PyAcadPViewport::gridSpacing, DS.ARGS())
        .def("setGridSpacing", &PyAcadPViewport::setGridSpacing, DS.ARGS({ "XSpacing:float", "YSpacing:float" }))
        .def("snapSpacing", &PyAcadPViewport::snapSpacing, DS.ARGS())
        .def("setSnapSpacing", &PyAcadPViewport::setSnapSpacing, DS.ARGS({ "XSpacing:float", "YSpacing:float" }))
        .def("display", &PyAcadPViewport::display, DS.ARGS())
        .def("twistAngle", &PyAcadPViewport::twistAngle, DS.ARGS())
        .def("setTwistAngle", &PyAcadPViewport::setTwistAngle, DS.ARGS({ "val:bool" }))
        .def("lensLength", &PyAcadPViewport::lensLength, DS.ARGS())
        .def("setLensLength", &PyAcadPViewport::setLensLength, DS.ARGS({ "val:float" }))
        .def("removeHiddenLines", &PyAcadPViewport::removeHiddenLines, DS.ARGS())
        .def("setRemoveHiddenLines", &PyAcadPViewport::setRemoveHiddenLines, DS.ARGS({ "val:bool" }))
        .def("target", &PyAcadPViewport::target, DS.ARGS())
        .def("setTarget", &PyAcadPViewport::setTarget, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("arcSmoothness", &PyAcadPViewport::arcSmoothness, DS.ARGS())
        .def("setArcSmoothness", &PyAcadPViewport::setArcSmoothness, DS.ARGS({ "val:int" }))
        .def("visualStyle", &PyAcadPViewport::visualStyle, DS.ARGS())
        .def("setVisualStyle", &PyAcadPViewport::setVisualStyle, DS.ARGS({ "val:int" }))
        .def("shadePlot", &PyAcadPViewport::shadePlot, DS.ARGS())
        .def("setShadePlot", &PyAcadPViewport::setShadePlot, DS.ARGS({ "val:int" }))
        .def("modelView", &PyAcadPViewport::modelView, DS.ARGS())
        .def("setModelView", &PyAcadPViewport::setModelView, DS.ARGS({ "val:PyAx.AcadView" }))
        .def("sheetView", &PyAcadPViewport::sheetView, DS.ARGS())
        .def("setSheetView", &PyAcadPViewport::setSheetView, DS.ARGS({ "val:PyAx.AcadView" }))
        .def("labelBlockId", &PyAcadPViewport::labelBlockId, DS.ARGS())
        .def("setLabelBlockId", &PyAcadPViewport::setLabelBlockId, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("hasSheetView", &PyAcadPViewport::hasSheetView, DS.ARGS())
        .def("syncModelView", &PyAcadPViewport::syncModelView, DS.ARGS())
        .def("standardScale2", &PyAcadPViewport::standardScale2, DS.ARGS())
        .def("setStandardScale2", &PyAcadPViewport::setStandardScale2, DS.ARGS({ "val:int" }))
        .def("layerPropertyOverrides", &PyAcadPViewport::layerPropertyOverrides, DS.ARGS())
        .def("cast", &PyAcadPViewport::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPViewport::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPViewport::PyAcadPViewport(std::shared_ptr<PyIAcadPViewportImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadPViewport::center() const
{
    return impObj()->GetCenter();
}

void PyAcadPViewport::setCenter(const AcGePoint3d& val)
{
    impObj()->SetCenter(val);
}

AcGeVector3d PyAcadPViewport::direction() const
{
    return impObj()->GetDirection();
}

void PyAcadPViewport::setDirection(const AcGeVector3d& val)
{
    impObj()->SetDirection(val);
}

bool PyAcadPViewport::gridOn() const
{
    return impObj()->GetGridOn();
}

void PyAcadPViewport::setGridOn(bool bVisible)
{
    impObj()->SetGridOn(bVisible);
}

double PyAcadPViewport::height() const
{
    return impObj()->GetHeight();
}

void PyAcadPViewport::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadPViewport::width() const
{
    return impObj()->GetWidth();
}

void PyAcadPViewport::setWidth(double val)
{
    impObj()->SetWidth(val);
}

bool PyAcadPViewport::viewportOn() const
{
    return impObj()->GetViewportOn();
}

void PyAcadPViewport::setViewportOn(bool bVisible)
{
    impObj()->SetViewportOn(bVisible);
}

bool PyAcadPViewport::clipped() const
{
    return impObj()->GetClipped();
}

bool PyAcadPViewport::displayLocked() const
{
    return impObj()->GetDisplayLocked();
}

void PyAcadPViewport::setDisplayLocked(bool bVisible)
{
    impObj()->SetDisplayLocked(bVisible);
}

PyAcViewportScale PyAcadPViewport::standardScale() const
{
    return impObj()->GetStandardScale();
}

void PyAcadPViewport::setStandardScale(PyAcViewportScale val)
{
    impObj()->SetStandardScale(val);
}

double PyAcadPViewport::customScale() const
{
    return impObj()->GetCustomScale();
}

void PyAcadPViewport::setCustomScale(double val)
{
    impObj()->SetCustomScale(val);
}

std::string PyAcadPViewport::styleSheet() const
{
    return wstr_to_utf8(impObj()->GetStyleSheet());
}

void PyAcadPViewport::setStyleSheet(const std::string& val)
{
    impObj()->SetStyleSheet(utf8_to_wstr(val).c_str());
}

bool PyAcadPViewport::ucsPerViewport() const
{
    return impObj()->GetUCSPerViewport();
}

void PyAcadPViewport::setUCSPerViewport(bool UCSSaved)
{
    impObj()->SetUCSPerViewport(UCSSaved);
}

AcGePoint2d PyAcadPViewport::snapBasePoint() const
{
    return impObj()->GetSnapBasePoint();
}

void PyAcadPViewport::setSnapBasePoint(const AcGePoint2d& val)
{
    impObj()->SetSnapBasePoint(val);
}

bool PyAcadPViewport::snapOn() const
{
    return impObj()->GetSnapOn();
}

void PyAcadPViewport::setSnapOn(bool UCSSaved)
{
    impObj()->SetSnapOn(UCSSaved);
}

double PyAcadPViewport::snapRotationAngle() const
{
    return impObj()->GetSnapRotationAngle();
}

void PyAcadPViewport::setSnapRotationAngle(double val)
{
    impObj()->SetSnapRotationAngle(val);
}

bool PyAcadPViewport::ucsIconOn() const
{
    return impObj()->GetUCSIconOn();
}

void PyAcadPViewport::setUCSIconOn(bool bIconOn)
{
    impObj()->SetUCSIconOn(bIconOn);
}

bool PyAcadPViewport::ucsIconAtOrigin() const
{
    return impObj()->GetUCSIconAtOrigin();
}

void PyAcadPViewport::setUCSIconAtOrigin(bool bIconAtOrigin)
{
    impObj()->SetUCSIconAtOrigin(bIconAtOrigin);
}

boost::python::tuple PyAcadPViewport::gridSpacing()
{
    PyAutoLockGIL lock;
    double XSpacing = 1.0;
    double YSpacing = 1.0;
    impObj()->GetGridSpacing(XSpacing, YSpacing);
    return boost::python::make_tuple(XSpacing, YSpacing);
}

void PyAcadPViewport::setGridSpacing(double XSpacing, double YSpacing)
{
    impObj()->SetGridSpacing(XSpacing, YSpacing);
}

boost::python::tuple PyAcadPViewport::snapSpacing()
{
    PyAutoLockGIL lock;
    double XSpacing = 1.0;
    double YSpacing = 1.0;
    impObj()->GetSnapSpacing(XSpacing, YSpacing);
    return boost::python::make_tuple(XSpacing, YSpacing);
}

void PyAcadPViewport::setSnapSpacing(double XSpacing, double YSpacing)
{
    impObj()->SetSnapSpacing(XSpacing, YSpacing);
}

void PyAcadPViewport::display(bool bStatus)
{
    impObj()->Display(bStatus);
}

double PyAcadPViewport::twistAngle() const
{
    return impObj()->GetTwistAngle();
}

void PyAcadPViewport::setTwistAngle(double val)
{
    impObj()->SetTwistAngle(val);
}

double PyAcadPViewport::lensLength() const
{
    return impObj()->GetLensLength();
}

void PyAcadPViewport::setLensLength(double val)
{
    impObj()->SetLensLength(val);
}

bool PyAcadPViewport::removeHiddenLines() const
{
    return impObj()->GetRemoveHiddenLines();
}

void PyAcadPViewport::setRemoveHiddenLines(bool bRemoval)
{
    impObj()->SetRemoveHiddenLines(bRemoval);
}

AcGePoint3d PyAcadPViewport::target() const
{
    return impObj()->GetTarget();
}

void PyAcadPViewport::setTarget(const AcGePoint3d& val)
{
    impObj()->SetTarget(val);
}

long PyAcadPViewport::arcSmoothness() const
{
    return impObj()->GetArcSmoothness();
}

void PyAcadPViewport::setArcSmoothness(long val)
{
    impObj()->SetArcSmoothness(val);
}

int PyAcadPViewport::visualStyle() const
{
    return impObj()->GetVisualStyle();
}

void PyAcadPViewport::setVisualStyle(int val)
{
    impObj()->SetVisualStyle(val);
}

int PyAcadPViewport::shadePlot() const
{
    return impObj()->GetShadePlot();
}

void PyAcadPViewport::setShadePlot(int val)
{
    impObj()->SetShadePlot(val);
}

PyAcadView PyAcadPViewport::modelView() const
{
    return PyAcadView{ impObj()->GetModelView() };
}

void PyAcadPViewport::setModelView(const PyAcadView& val) const
{
    impObj()->SetModelView(*val.impObj());
}

PyAcadView PyAcadPViewport::sheetView() const
{
    return PyAcadView{ impObj()->GetSheetView() };
}

void PyAcadPViewport::setSheetView(const PyAcadView& val) const
{
    impObj()->SetSheetView(*val.impObj());
}

PyDbObjectId PyAcadPViewport::labelBlockId() const
{
    return  PyDbObjectId{ impObj()->GetLabelBlockId() };
}

void PyAcadPViewport::setLabelBlockId(const PyDbObjectId& id)
{
    impObj()->SetLabelBlockId(id.m_id);
}

bool PyAcadPViewport::hasSheetView() const
{
    return impObj()->GetHasSheetView();
}

void PyAcadPViewport::syncModelView()
{
    impObj()->SyncModelView();
}

int PyAcadPViewport::standardScale2() const
{
    return impObj()->GetStandardScale2();
}

void PyAcadPViewport::setStandardScale2(int val)
{
    impObj()->SetStandardScale2(val);
}

bool PyAcadPViewport::layerPropertyOverrides() const
{
    return impObj()->GetLayerPropertyOverrides();
}

PyAcadPViewport PyAcadPViewport::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPViewport>(src);
}

std::string PyAcadPViewport::className()
{
    return "AcadPViewport";
}

PyIAcadPViewportImpl* PyAcadPViewport::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPViewportImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcad3DFace
void makePyAcad3DFaceWrapper()
{
    PyDocString DS("Acad3DFace");
    class_<PyAcad3DFace, bases<PyAcadEntity>>("Acad3DFace", boost::python::no_init)
        .def("coordinates", &PyAcad3DFace::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcad3DFace::setCoordinates, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("invisibleEdge", &PyAcad3DFace::invisibleEdge, DS.ARGS({ "index:int" }))
        .def("setInvisibleEdge", &PyAcad3DFace::setInvisibleEdge, DS.ARGS({ "index:int", "flag:bool" }))
        .def("coordinate", &PyAcad3DFace::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcad3DFace::setCoordinate, DS.ARGS({ "index:int", "point:PyGe.Point3d" }))
        .def("cast", &PyAcad3DFace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DFace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DFace::PyAcad3DFace(std::shared_ptr<PyIAcad3DFaceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcad3DFace::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcad3DFace::setCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    impObj()->SetCoordinates(p1, p2, p3, p4);
}

bool PyAcad3DFace::invisibleEdge(int index) const
{
    return impObj()->GetInvisibleEdge(index);
}

void PyAcad3DFace::setInvisibleEdge(int index, bool flag) const
{
    impObj()->SetInvisibleEdge(index, flag);
}

AcGePoint3d PyAcad3DFace::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcad3DFace::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAcad3DFace PyAcad3DFace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcad3DFace>(src);
}

std::string PyAcad3DFace::className()
{
    return "Acad3DFace";
}

PyIAcad3DFaceImpl* PyAcad3DFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcad3DFaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPolygonMesh
void makePyAcadPolygonMeshWrapper()
{
    PyDocString DS("AcadPolygonMesh");
    class_<PyAcadPolygonMesh, bases<PyAcadEntity>>("AcadPolygonMesh", boost::python::no_init)
        .def("coordinates", &PyAcadPolygonMesh::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadPolygonMesh::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point3d]" }))
        .def("mClose", &PyAcadPolygonMesh::mClose, DS.ARGS())
        .def("setMClose", &PyAcadPolygonMesh::setMClose, DS.ARGS({ "val:bool" }))
        .def("nClose", &PyAcadPolygonMesh::nClose, DS.ARGS())
        .def("setNClose", &PyAcadPolygonMesh::setNClose, DS.ARGS({ "val:bool" }))
        .def("mDensity", &PyAcadPolygonMesh::mDensity, DS.ARGS())
        .def("setMDensity", &PyAcadPolygonMesh::setMDensity, DS.ARGS({ "val:int" }))
        .def("nDensity", &PyAcadPolygonMesh::nDensity, DS.ARGS())
        .def("setNDensity", &PyAcadPolygonMesh::setNDensity, DS.ARGS({ "val:int" }))
        .def("mVertexCount", &PyAcadPolygonMesh::mVertexCount, DS.ARGS())
        .def("nVertexCount", &PyAcadPolygonMesh::nVertexCount, DS.ARGS())
        .def("getType", &PyAcadPolygonMesh::getType, DS.ARGS())
        .def("setType", &PyAcadPolygonMesh::setType, DS.ARGS({ "val:PyAx.AcPolymeshType" }))
        .def("appendVertex", &PyAcadPolygonMesh::appendVertex, DS.ARGS({ "vertex:PyGe.Point3d" }))
        .def("explode", &PyAcadPolygonMesh::explode, DS.ARGS())
        .def("coordinate", &PyAcadPolygonMesh::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcadPolygonMesh::setCoordinate, DS.ARGS({ "index:int", "point:PyGe.Point3d" }))
        .def("cast", &PyAcadPolygonMesh::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolygonMesh::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolygonMesh::PyAcadPolygonMesh(std::shared_ptr<PyIAcadPolygonMeshImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcadPolygonMesh::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcadPolygonMesh::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint3d>(coords));
}

bool PyAcadPolygonMesh::mClose() const
{
    return impObj()->GetMClose();
}

void PyAcadPolygonMesh::setMClose(bool val)
{
    impObj()->SetMClose(val);
}

bool PyAcadPolygonMesh::nClose() const
{
    return impObj()->GetNClose();
}

void PyAcadPolygonMesh::setNClose(bool val)
{
    impObj()->SetNClose(val);
}

long PyAcadPolygonMesh::mDensity() const
{
    return impObj()->GetMDensity();
}

void PyAcadPolygonMesh::setMDensity(long val)
{
    impObj()->SetMDensity(val);
}

long PyAcadPolygonMesh::nDensity() const
{
    return impObj()->GetNDensity();
}

void PyAcadPolygonMesh::setNDensity(long val)
{
    impObj()->SetNDensity(val);
}

long PyAcadPolygonMesh::mVertexCount() const
{
    return impObj()->GetMVertexCount();
}

long PyAcadPolygonMesh::nVertexCount() const
{
    return impObj()->GetNVertexCount();
}

PyAcPolymeshType PyAcadPolygonMesh::getType() const
{
    return impObj()->GetType();
}

void PyAcadPolygonMesh::setType(PyAcPolymeshType val)
{
    impObj()->SetType(val);
}

void PyAcadPolygonMesh::appendVertex(const AcGePoint3d& val)
{
    impObj()->AppendVertex(val);
}

boost::python::list PyAcadPolygonMesh::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

AcGePoint3d PyAcadPolygonMesh::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcadPolygonMesh::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAcadPolygonMesh PyAcadPolygonMesh::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPolygonMesh>(src);
}

std::string PyAcadPolygonMesh::className()
{
    return "AcadPolygonMesh";
}

PyIAcadPolygonMeshImpl* PyAcadPolygonMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPolygonMeshImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcad3DPolyline
void makePyAcad3DPolylineWrapper()
{
    PyDocString DS("Acad3DPolyline");
    class_<PyAcad3DPolyline, bases<PyAcadEntity>>("Acad3DPolyline", boost::python::no_init)
        .def("coordinates", &PyAcad3DPolyline::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcad3DPolyline::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point3d]" }))
        .def("getType", &PyAcad3DPolyline::getType, DS.ARGS())
        .def("setType", &PyAcad3DPolyline::setType, DS.ARGS({ "val:PyAx.Ac3DPolylineType" }))
        .def("appendVertex", &PyAcad3DPolyline::appendVertex, DS.ARGS({ "vertex:PyGe.Point3d" }))
        .def("explode", &PyAcad3DPolyline::explode, DS.ARGS())
        .def("coordinate", &PyAcad3DPolyline::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcad3DPolyline::setCoordinate, DS.ARGS({ "index:int", "point:PyGe.Point3d" }))
        .def("isClosed", &PyAcad3DPolyline::isClosed, DS.ARGS())
        .def("setClosed", &PyAcad3DPolyline::setClosed, DS.ARGS({ "val:bool" }))
        .def("length", &PyAcad3DPolyline::length, DS.ARGS())
        .def("cast", &PyAcad3DPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DPolyline::PyAcad3DPolyline(std::shared_ptr<PyIAcad3DPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcad3DPolyline::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcad3DPolyline::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint3d>(coords));
}

void PyAcad3DPolyline::appendVertex(const AcGePoint3d& val)
{
    impObj()->AppendVertex(val);
}

boost::python::list PyAcad3DPolyline::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

AcGePoint3d PyAcad3DPolyline::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcad3DPolyline::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAc3DPolylineType PyAcad3DPolyline::getType() const
{
    return impObj()->GetType();
}

void PyAcad3DPolyline::setType(PyAc3DPolylineType val)
{
    impObj()->SetType(val);
}

bool PyAcad3DPolyline::isClosed() const
{
    return impObj()->GetClosed();
}

void PyAcad3DPolyline::setClosed(bool val)
{
    impObj()->SetClosed(val);
}

double PyAcad3DPolyline::length() const
{
    return impObj()->GetLength();
}

PyAcad3DPolyline PyAcad3DPolyline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcad3DPolyline>(src);
}

std::string PyAcad3DPolyline::className()
{
    return "Acad3DPolyline";
}

PyIAcad3DPolylineImpl* PyAcad3DPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcad3DPolylineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadArc
void makePyAcadArcWrapper()
{
    PyDocString DS("AcadArc");
    class_<PyAcadArc, bases<PyAcadEntity>>("AcadArc", boost::python::no_init)
        .def("startPoint", &PyAcadArc::startPoint, DS.ARGS())
        .def("center", &PyAcadArc::center, DS.ARGS())
        .def("setCenter", &PyAcadArc::setCenter, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("endPoint", &PyAcadArc::endPoint, DS.ARGS())
        .def("radius", &PyAcadArc::radius, DS.ARGS())
        .def("setRadius", &PyAcadArc::setRadius, DS.ARGS({ "val:float" }))
        .def("startAngle", &PyAcadArc::startAngle, DS.ARGS())
        .def("setStartAngle", &PyAcadArc::setStartAngle, DS.ARGS({ "val:float" }))
        .def("endAngle", &PyAcadArc::endAngle, DS.ARGS())
        .def("endAngle", &PyAcadArc::endAngle, DS.ARGS({ "val:float" }))
        .def("totalAngle", &PyAcadArc::totalAngle, DS.ARGS())
        .def("arcLength", &PyAcadArc::arcLength, DS.ARGS())
        .def("thickness", &PyAcadArc::thickness, DS.ARGS())
        .def("setThickness", &PyAcadArc::setThickness, DS.ARGS({ "val:float" }))
        .def("offset", &PyAcadArc::offset, DS.ARGS({ "val:float" }))
        .def("area", &PyAcadArc::area, DS.ARGS())
        .def("normal", &PyAcadArc::normal, DS.ARGS())
        .def("setNormal", &PyAcadArc::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("cast", &PyAcadArc::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadArc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadArc::PyAcadArc(std::shared_ptr<PyIAcadArcImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadArc::startPoint() const
{
    return impObj()->GetStartPoint();
}

AcGePoint3d PyAcadArc::center() const
{
    return impObj()->GetCenter();
}

void PyAcadArc::setCenter(const AcGePoint3d& val)
{
    impObj()->SetCenter(val);
}

AcGePoint3d PyAcadArc::endPoint() const
{
    return impObj()->GetEndPoint();
}

double PyAcadArc::radius() const
{
    return impObj()->GetRadius();
}

void PyAcadArc::setRadius(double val)
{
    impObj()->SetRadius(val);
}

double PyAcadArc::startAngle() const
{
    return impObj()->GetStartAngle();
}

void PyAcadArc::setStartAngle(double val)
{
    impObj()->SetRadius(val);
}

double PyAcadArc::endAngle() const
{
    return impObj()->GetEndAngle();
}

void PyAcadArc::setEndAngle(double val)
{
    impObj()->SetEndAngle(val);
}

double PyAcadArc::totalAngle() const
{
    return impObj()->GetTotalAngle();
}

double PyAcadArc::arcLength() const
{
    return impObj()->GetArcLength();
}

double PyAcadArc::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadArc::setThickness(double val)
{
    impObj()->SetThickness(val);
}

boost::python::list PyAcadArc::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

double PyAcadArc::area() const
{
    return impObj()->GetArea();
}

AcGeVector3d PyAcadArc::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadArc::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

PyAcadArc PyAcadArc::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadArc>(src);
}

std::string PyAcadArc::className()
{
    return "AcadArc";
}

PyIAcadArcImpl* PyAcadArc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadArcImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadAttribute
void makePyAcadAttributeWrapper()
{
    PyDocString DS("AcadAttribute");
    class_<PyAcadAttribute, bases<PyAcadEntity>>("AcadAttribute", boost::python::no_init)
        .def("fieldLength", &PyAcadAttribute::fieldLength, DS.ARGS())
        .def("setFieldLength", &PyAcadAttribute::setFieldLength, DS.ARGS({ "val:int" }))
        .def("tagString", &PyAcadAttribute::tagString, DS.ARGS())
        .def("setTagString", &PyAcadAttribute::setTagString, DS.ARGS({ "val:str" }))
        .def("promptString", &PyAcadAttribute::promptString, DS.ARGS())
        .def("setPromptString", &PyAcadAttribute::setPromptString, DS.ARGS({ "val:str" }))
        .def("textString", &PyAcadAttribute::textString, DS.ARGS())
        .def("setTextString", &PyAcadAttribute::setTextString, DS.ARGS({ "val:str" }))
        .def("styleName", &PyAcadAttribute::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadAttribute::setStyleName, DS.ARGS({ "val:str" }))
        .def("alignment", &PyAcadAttribute::alignment, DS.ARGS())
        .def("setAlignment", &PyAcadAttribute::setAlignment, DS.ARGS({ "val:PyAx.AcAlignment" }))
        .def("horizontalAlignment", &PyAcadAttribute::horizontalAlignment, DS.ARGS())
        .def("setHorizontalAlignment", &PyAcadAttribute::setHorizontalAlignment, DS.ARGS({ "val:PyAx.AcHorizontalAlignment" }))
        .def("verticalAlignment", &PyAcadAttribute::verticalAlignment, DS.ARGS())
        .def("setVerticalAlignment", &PyAcadAttribute::setVerticalAlignment, DS.ARGS({ "val:PyAx.AcVerticalAlignment" }))
        .def("height", &PyAcadAttribute::height, DS.ARGS())
        .def("setHeight", &PyAcadAttribute::setHeight, DS.ARGS({ "val:float" }))
        .def("rotation", &PyAcadAttribute::rotation, DS.ARGS())
        .def("setRotation", &PyAcadAttribute::setRotation, DS.ARGS({ "val:float" }))
        .def("scaleFactor", &PyAcadAttribute::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadAttribute::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("obliqueAngle", &PyAcadAttribute::obliqueAngle, DS.ARGS())
        .def("textAlignmentPoint", &PyAcadAttribute::textAlignmentPoint, DS.ARGS({ "val:float" }))
        .def("textAlignmentPoint", &PyAcadAttribute::textAlignmentPoint, DS.ARGS())
        .def("setTextAlignmentPoint", &PyAcadAttribute::setTextAlignmentPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("insertionPoint", &PyAcadAttribute::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadAttribute::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("normal", &PyAcadAttribute::normal, DS.ARGS())
        .def("setNormal", &PyAcadAttribute::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("textGenerationFlag", &PyAcadAttribute::textGenerationFlag, DS.ARGS())
        .def("setTextGenerationFlag", &PyAcadAttribute::setTextGenerationFlag, DS.ARGS({ "val:int" }))
        .def("thickness", &PyAcadAttribute::thickness, DS.ARGS())
        .def("setThickness", &PyAcadAttribute::setThickness, DS.ARGS({ "val:float" }))
        .def("mode", &PyAcadAttribute::mode, DS.ARGS())
        .def("setMode", &PyAcadAttribute::setMode, DS.ARGS({ "val:int" }))
        .def("upsideDown", &PyAcadAttribute::upsideDown, DS.ARGS())
        .def("setUpsideDown", &PyAcadAttribute::setUpsideDown, DS.ARGS({ "val:bool" }))
        .def("backward", &PyAcadAttribute::backward, DS.ARGS())
        .def("setBackward", &PyAcadAttribute::setBackward, DS.ARGS({ "val:bool" }))
        .def("invisible", &PyAcadAttribute::invisible, DS.ARGS())
        .def("setInvisible", &PyAcadAttribute::setInvisible, DS.ARGS({ "val:bool" }))
        .def("constant", &PyAcadAttribute::constant, DS.ARGS())
        .def("setConstant", &PyAcadAttribute::setConstant, DS.ARGS({ "val:bool" }))
        .def("verify", &PyAcadAttribute::verify, DS.ARGS())
        .def("setVerify", &PyAcadAttribute::setVerify, DS.ARGS({ "val:bool" }))
        .def("preset", &PyAcadAttribute::preset, DS.ARGS())
        .def("setPreset", &PyAcadAttribute::setPreset, DS.ARGS({ "val:bool" }))
        .def("lockPosition", &PyAcadAttribute::lockPosition, DS.ARGS())
        .def("setLockPosition", &PyAcadAttribute::setLockPosition, DS.ARGS({ "val:bool" }))
        .def("isMTextAttribute", &PyAcadAttribute::isMTextAttribute, DS.ARGS())
        .def("setIsMTextAttribute", &PyAcadAttribute::setIsMTextAttribute, DS.ARGS({ "val:bool" }))
        .def("mtextAttributeContent", &PyAcadAttribute::mtextAttributeContent, DS.ARGS())
        .def("setMTextAttributeContent", &PyAcadAttribute::setMTextAttributeContent, DS.ARGS({ "val:str" }))
        .def("updateMTextAttribute", &PyAcadAttribute::updateMTextAttribute, DS.ARGS())
        .def("mtextBoundaryWidth", &PyAcadAttribute::mtextBoundaryWidth, DS.ARGS())
        .def("setMTextBoundaryWidth", &PyAcadAttribute::setMTextBoundaryWidth, DS.ARGS({ "val:float" }))
        .def("mtextDrawingDirection", &PyAcadAttribute::mtextDrawingDirection, DS.ARGS())
        .def("setMTextDrawingDirection", &PyAcadAttribute::setMTextDrawingDirection, DS.ARGS({ "val:PyAx.AcDrawingDirection" }))
        .def("cast", &PyAcadAttribute::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadAttribute::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadAttribute::PyAcadAttribute(std::shared_ptr<PyIAcadAttributeImpl> ptr)
    : PyAcadEntity(ptr)
{
}

long PyAcadAttribute::fieldLength() const
{
    return impObj()->GetFieldLength();
}

void PyAcadAttribute::setFieldLength(long val)
{
    impObj()->SetFieldLength(val);
}

std::string PyAcadAttribute::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadAttribute::setTagString(const std::string& val)
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

std::string PyAcadAttribute::promptString() const
{
    return wstr_to_utf8(impObj()->GetPromptString());
}

void PyAcadAttribute::setPromptString(const std::string& val)
{
    impObj()->SetPromptString(utf8_to_wstr(val).c_str());
}

std::string PyAcadAttribute::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadAttribute::setTextString(const std::string& val)
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

std::string PyAcadAttribute::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadAttribute::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcAlignment PyAcadAttribute::alignment() const
{
    return impObj()->GetAlignment();
}

void PyAcadAttribute::setAlignment(PyAcAlignment val)
{
    impObj()->SetAlignment(val);
}

PyAcHorizontalAlignment PyAcadAttribute::horizontalAlignment() const
{
    return impObj()->GetHorizontalAlignment();
}

void PyAcadAttribute::setHorizontalAlignment(PyAcHorizontalAlignment val)
{
    impObj()->SetHorizontalAlignment(val);
}

PyAcVerticalAlignment PyAcadAttribute::verticalAlignment() const
{
    return impObj()->GetVerticalAlignment();
}

void PyAcadAttribute::setVerticalAlignment(PyAcVerticalAlignment val)
{
    impObj()->SetVerticalAlignment(val);
}

double PyAcadAttribute::height() const
{
    return impObj()->GetHeight();
}

void PyAcadAttribute::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadAttribute::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadAttribute::setRotation(double val)
{
    impObj()->SetRotation(val);
}

double PyAcadAttribute::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadAttribute::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

double PyAcadAttribute::obliqueAngle() const
{
    return impObj()->GetObliqueAngle();
}

void PyAcadAttribute::setObliqueAngle(double val)
{
    impObj()->SetObliqueAngle(val);
}

AcGePoint3d PyAcadAttribute::textAlignmentPoint() const
{
    return impObj()->GetTextAlignmentPoint();
}

void PyAcadAttribute::setTextAlignmentPoint(const AcGePoint3d& val)
{
    impObj()->SetTextAlignmentPoint(val);
}

AcGePoint3d PyAcadAttribute::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadAttribute::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

AcGeVector3d PyAcadAttribute::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadAttribute::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

long PyAcadAttribute::textGenerationFlag() const
{
    return impObj()->GetTextGenerationFlag();
}

void PyAcadAttribute::setTextGenerationFlag(long val)
{
    impObj()->SetTextGenerationFlag(val);
}

double PyAcadAttribute::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadAttribute::setThickness(double val)
{
    impObj()->SetThickness(val);
}

long PyAcadAttribute::mode() const
{
    return impObj()->GetMode();
}

void PyAcadAttribute::setMode(long val)
{
    impObj()->SetMode(val);
}

bool PyAcadAttribute::upsideDown() const
{
    return impObj()->GetUpsideDown();
}

void PyAcadAttribute::setUpsideDown(bool val)
{
    impObj()->SetUpsideDown(val);
}

bool PyAcadAttribute::backward() const
{
    return impObj()->GetBackward();
}

void PyAcadAttribute::setBackward(bool val)
{
    impObj()->SetBackward(val);
}

bool PyAcadAttribute::invisible() const
{
    return impObj()->GetInvisible();
}

void PyAcadAttribute::setInvisible(bool val)
{
    impObj()->SetInvisible(val);
}

bool PyAcadAttribute::constant() const
{
    return impObj()->GetConstant();
}

void PyAcadAttribute::setConstant(bool val)
{
    impObj()->SetConstant(val);
}

bool PyAcadAttribute::verify() const
{
    return impObj()->GetVerify();
}

void PyAcadAttribute::setVerify(bool val)
{
    impObj()->SetVerify(val);
}

bool PyAcadAttribute::preset() const
{
    return impObj()->GetPreset();
}

void PyAcadAttribute::setPreset(bool val)
{
    impObj()->SetPreset(val);
}

bool PyAcadAttribute::lockPosition() const
{
    return impObj()->GetLockPosition();
}

void PyAcadAttribute::setLockPosition(bool val)
{
    impObj()->SetLockPosition(val);
}

bool PyAcadAttribute::isMTextAttribute() const
{
    return impObj()->GetMTextAttribute();
}

void PyAcadAttribute::setIsMTextAttribute(bool val)
{
    impObj()->SetMTextAttribute(val);
}

std::string PyAcadAttribute::mtextAttributeContent() const
{
    return wstr_to_utf8(impObj()->GetMTextAttributeContent());
}

void PyAcadAttribute::setMTextAttributeContent(const std::string& val)
{
    impObj()->SetMTextAttributeContent(utf8_to_wstr(val).c_str());
}

void PyAcadAttribute::updateMTextAttribute()
{
    impObj()->UpdateMTextAttribute();
}

double PyAcadAttribute::mtextBoundaryWidth() const
{
    return impObj()->GetMTextBoundaryWidth();
}

void PyAcadAttribute::setMTextBoundaryWidth(double val)
{
    impObj()->SetMTextBoundaryWidth(val);
}

PyAcDrawingDirection PyAcadAttribute::mtextDrawingDirection() const
{
    return impObj()->GetMTextDrawingDirection();
}

void PyAcadAttribute::setMTextDrawingDirection(PyAcDrawingDirection val)
{
    impObj()->SetMTextDrawingDirection(val);
}

PyAcadAttribute PyAcadAttribute::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadAttribute>(src);
}

std::string PyAcadAttribute::className()
{
    return "AcadAttribute";
}

PyIAcadAttributeImpl* PyAcadAttribute::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadAttributeImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadAttributeReference
void makePyAcadAttributeReferenceWrapper()
{
    PyDocString DS("AcadAttributeReference");
    class_<PyAcadAttributeReference, bases<PyAcadEntity>>("AcadAttributeReference", boost::python::no_init)
        .def("fieldLength", &PyAcadAttributeReference::fieldLength, DS.ARGS())
        .def("setFieldLength", &PyAcadAttributeReference::setFieldLength, DS.ARGS({ "val:int" }))
        .def("tagString", &PyAcadAttributeReference::tagString, DS.ARGS())
        .def("setTagString", &PyAcadAttributeReference::setTagString, DS.ARGS({ "val:str" }))
        .def("textString", &PyAcadAttributeReference::textString, DS.ARGS())
        .def("setTextString", &PyAcadAttributeReference::setTextString, DS.ARGS({ "val:str" }))
        .def("styleName", &PyAcadAttributeReference::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadAttributeReference::setStyleName, DS.ARGS({ "val:str" }))
        .def("alignment", &PyAcadAttributeReference::alignment, DS.ARGS())
        .def("setAlignment", &PyAcadAttributeReference::setAlignment, DS.ARGS({ "val:PyAx.AcAlignment" }))
        .def("horizontalAlignment", &PyAcadAttributeReference::horizontalAlignment, DS.ARGS())
        .def("setHorizontalAlignment", &PyAcadAttributeReference::setHorizontalAlignment, DS.ARGS({ "val:PyAx.AcHorizontalAlignment" }))
        .def("verticalAlignment", &PyAcadAttributeReference::verticalAlignment, DS.ARGS())
        .def("setVerticalAlignment", &PyAcadAttributeReference::setVerticalAlignment, DS.ARGS({ "val:PyAx.AcVerticalAlignment" }))
        .def("height", &PyAcadAttributeReference::height, DS.ARGS())
        .def("setHeight", &PyAcadAttributeReference::setHeight, DS.ARGS({ "val:float" }))
        .def("rotation", &PyAcadAttributeReference::rotation, DS.ARGS())
        .def("setRotation", &PyAcadAttributeReference::setRotation, DS.ARGS({ "val:float" }))
        .def("scaleFactor", &PyAcadAttributeReference::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadAttributeReference::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("obliqueAngle", &PyAcadAttributeReference::obliqueAngle, DS.ARGS())
        .def("textAlignmentPoint", &PyAcadAttributeReference::textAlignmentPoint, DS.ARGS({ "val:float" }))
        .def("textAlignmentPoint", &PyAcadAttributeReference::textAlignmentPoint, DS.ARGS())
        .def("setTextAlignmentPoint", &PyAcadAttributeReference::setTextAlignmentPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("insertionPoint", &PyAcadAttributeReference::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadAttributeReference::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("normal", &PyAcadAttributeReference::normal, DS.ARGS())
        .def("setNormal", &PyAcadAttributeReference::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("textGenerationFlag", &PyAcadAttributeReference::textGenerationFlag, DS.ARGS())
        .def("setTextGenerationFlag", &PyAcadAttributeReference::setTextGenerationFlag, DS.ARGS({ "val:int" }))
        .def("thickness", &PyAcadAttributeReference::thickness, DS.ARGS())
        .def("setThickness", &PyAcadAttributeReference::setThickness, DS.ARGS({ "val:float" }))
        .def("upsideDown", &PyAcadAttributeReference::upsideDown, DS.ARGS())
        .def("setUpsideDown", &PyAcadAttributeReference::setUpsideDown, DS.ARGS({ "val:bool" }))
        .def("backward", &PyAcadAttributeReference::backward, DS.ARGS())
        .def("setBackward", &PyAcadAttributeReference::setBackward, DS.ARGS({ "val:bool" }))
        .def("invisible", &PyAcadAttributeReference::invisible, DS.ARGS())
        .def("setInvisible", &PyAcadAttributeReference::setInvisible, DS.ARGS({ "val:bool" }))
        .def("constant", &PyAcadAttributeReference::constant, DS.ARGS())
        .def("lockPosition", &PyAcadAttributeReference::lockPosition, DS.ARGS())
        .def("isMTextAttribute", &PyAcadAttributeReference::isMTextAttribute, DS.ARGS())
        .def("setIsMTextAttribute", &PyAcadAttributeReference::setIsMTextAttribute, DS.ARGS({ "val:bool" }))
        .def("mtextAttributeContent", &PyAcadAttributeReference::mtextAttributeContent, DS.ARGS())
        .def("setMTextAttributeContent", &PyAcadAttributeReference::setMTextAttributeContent, DS.ARGS({ "val:str" }))
        .def("updateMTextAttribute", &PyAcadAttributeReference::updateMTextAttribute, DS.ARGS())
        .def("mtextBoundaryWidth", &PyAcadAttributeReference::mtextBoundaryWidth, DS.ARGS())
        .def("setMTextBoundaryWidth", &PyAcadAttributeReference::setMTextBoundaryWidth, DS.ARGS({ "val:float" }))
        .def("mtextDrawingDirection", &PyAcadAttributeReference::mtextDrawingDirection, DS.ARGS())
        .def("setMTextDrawingDirection", &PyAcadAttributeReference::setMTextDrawingDirection, DS.ARGS({ "val:PyAx.AcDrawingDirection" }))
        .def("cast", &PyAcadAttributeReference::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadAttributeReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadAttributeReference::PyAcadAttributeReference(std::shared_ptr<PyIAcadAttributeReferenceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

long PyAcadAttributeReference::fieldLength() const
{
    return impObj()->GetFieldLength();
}

void PyAcadAttributeReference::setFieldLength(long val)
{
    impObj()->SetFieldLength(val);
}

std::string PyAcadAttributeReference::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadAttributeReference::setTagString(const std::string& val)
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

std::string PyAcadAttributeReference::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadAttributeReference::setTextString(const std::string& val)
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

std::string PyAcadAttributeReference::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadAttributeReference::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcAlignment PyAcadAttributeReference::alignment() const
{
    return impObj()->GetAlignment();
}

void PyAcadAttributeReference::setAlignment(PyAcAlignment val)
{
    impObj()->SetAlignment(val);
}

PyAcHorizontalAlignment PyAcadAttributeReference::horizontalAlignment() const
{
    return impObj()->GetHorizontalAlignment();
}

void PyAcadAttributeReference::setHorizontalAlignment(PyAcHorizontalAlignment val)
{
    impObj()->SetHorizontalAlignment(val);
}

PyAcVerticalAlignment PyAcadAttributeReference::verticalAlignment() const
{
    return impObj()->GetVerticalAlignment();
}

void PyAcadAttributeReference::setVerticalAlignment(PyAcVerticalAlignment val)
{
    impObj()->SetVerticalAlignment(val);
}

double PyAcadAttributeReference::height() const
{
    return impObj()->GetHeight();
}

void PyAcadAttributeReference::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadAttributeReference::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadAttributeReference::setRotation(double val)
{
    impObj()->SetRotation(val);
}

double PyAcadAttributeReference::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadAttributeReference::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

double PyAcadAttributeReference::obliqueAngle() const
{
    return impObj()->GetObliqueAngle();
}

void PyAcadAttributeReference::setObliqueAngle(double val)
{
    impObj()->SetObliqueAngle(val);
}

AcGePoint3d PyAcadAttributeReference::textAlignmentPoint() const
{
    return impObj()->GetTextAlignmentPoint();
}

void PyAcadAttributeReference::setTextAlignmentPoint(const AcGePoint3d& val)
{
    impObj()->SetTextAlignmentPoint(val);
}

AcGePoint3d PyAcadAttributeReference::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadAttributeReference::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

AcGeVector3d PyAcadAttributeReference::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadAttributeReference::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

long PyAcadAttributeReference::textGenerationFlag() const
{
    return impObj()->GetTextGenerationFlag();
}

void PyAcadAttributeReference::setTextGenerationFlag(long val)
{
    impObj()->SetTextGenerationFlag(val);
}

double PyAcadAttributeReference::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadAttributeReference::setThickness(double val)
{
    impObj()->SetThickness(val);
}

bool PyAcadAttributeReference::upsideDown() const
{
    return impObj()->GetUpsideDown();
}

void PyAcadAttributeReference::setUpsideDown(bool val)
{
    impObj()->SetUpsideDown(val);
}

bool PyAcadAttributeReference::backward() const
{
    return impObj()->GetBackward();
}

void PyAcadAttributeReference::setBackward(bool val)
{
    impObj()->SetBackward(val);
}

bool PyAcadAttributeReference::invisible() const
{
    return impObj()->GetInvisible();
}

void PyAcadAttributeReference::setInvisible(bool val)
{
    impObj()->SetInvisible(val);
}

bool PyAcadAttributeReference::constant() const
{
    return impObj()->GetConstant();
}

bool PyAcadAttributeReference::lockPosition() const
{
    return impObj()->GetLockPosition();
}

bool PyAcadAttributeReference::isMTextAttribute() const
{
    return impObj()->GetMTextAttribute();
}

void PyAcadAttributeReference::setIsMTextAttribute(bool val)
{
    impObj()->SetMTextAttribute(val);
}

std::string PyAcadAttributeReference::mtextAttributeContent() const
{
    return wstr_to_utf8(impObj()->GetMTextAttributeContent());
}

void PyAcadAttributeReference::setMTextAttributeContent(const std::string& val)
{
    impObj()->SetMTextAttributeContent(utf8_to_wstr(val).c_str());
}

void PyAcadAttributeReference::updateMTextAttribute()
{
    impObj()->UpdateMTextAttribute();
}

double PyAcadAttributeReference::mtextBoundaryWidth() const
{
    return impObj()->GetMTextBoundaryWidth();
}

void PyAcadAttributeReference::setMTextBoundaryWidth(double val)
{
    impObj()->SetMTextBoundaryWidth(val);
}

PyAcDrawingDirection PyAcadAttributeReference::mtextDrawingDirection() const
{
    return impObj()->GetMTextDrawingDirection();
}

void PyAcadAttributeReference::setMTextDrawingDirection(PyAcDrawingDirection val)
{
    impObj()->SetMTextDrawingDirection(val);
}

PyAcadAttributeReference PyAcadAttributeReference::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadAttributeReference>(src);
}

std::string PyAcadAttributeReference::className()
{
    return "AcadAttributeReference";
}

PyIAcadAttributeReferenceImpl* PyAcadAttributeReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadAttributeReferenceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadRegion
void makePyAcadRegionWrapper()
{
    PyDocString DS("AcadRegion");
    class_<PyAcadRegion, bases<PyAcadEntity>>("AcadRegion", boost::python::no_init)
        .def("area", &PyAcadRegion::area, DS.ARGS())
        .def("centroid", &PyAcadRegion::centroid, DS.ARGS())
        .def("momentOfInertia", &PyAcadRegion::momentOfInertia, DS.ARGS())
        .def("normal", &PyAcadRegion::normal, DS.ARGS())
        .def("perimeter", &PyAcadRegion::perimeter, DS.ARGS())
        .def("principalDirections", &PyAcadRegion::principalDirections, DS.ARGS())
        .def("principalMoments", &PyAcadRegion::principalMoments, DS.ARGS())
        .def("radiiOfGyration", &PyAcadRegion::radiiOfGyration, DS.ARGS())
        .def("boolean", &PyAcadRegion::boolean, DS.ARGS({ "booleanType:PyAx.AcBooleanType","region:PyAx.AcadRegion" }))
        .def("explode", &PyAcadRegion::explode, DS.ARGS())
        .def("cast", &PyAcadRegion::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRegion::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRegion::PyAcadRegion(std::shared_ptr<PyIAcadRegionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

double PyAcadRegion::area() const
{
    return impObj()->GetArea();
}

AcGePoint2d PyAcadRegion::centroid() const
{
    return impObj()->GetCentroid();
}

AcGePoint3d PyAcadRegion::momentOfInertia() const
{
    return impObj()->GetMomentOfInertia();
}

AcGeVector3d PyAcadRegion::normal() const
{
    return impObj()->GetNormal();
}

double PyAcadRegion::perimeter() const
{
    return impObj()->GetPerimeter();
}

boost::python::list PyAcadRegion::principalDirections() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetPrincipalDirections())
        pylist.append(item);
    return pylist;
}

AcGePoint3d PyAcadRegion::principalMoments() const
{
    return impObj()->GetPrincipalMoments();
}

AcGePoint3d PyAcadRegion::radiiOfGyration() const
{
    return impObj()->GetRadiiOfGyration();
}

void PyAcadRegion::boolean(PyAcBooleanType val, const PyAcadRegion& region) const
{
    impObj()->Boolean(val, *region.impObj());
}

boost::python::list PyAcadRegion::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

PyAcadRegion PyAcadRegion::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadRegion>(src);
}

std::string PyAcadRegion::className()
{
    return "AcadRegion";
}

PyIAcadRegionImpl* PyAcadRegion::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadRegionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcad3DSolid
void makePyAcad3DSolidWrapper()
{
    PyDocString DS("Acad3DSolid");
    class_<PyAcad3DSolid, bases<PyAcadEntity>>("Acad3DSolid", boost::python::no_init)
        .def("centroid", &PyAcad3DSolid::centroid, DS.ARGS())
        .def("momentOfInertia", &PyAcad3DSolid::momentOfInertia, DS.ARGS())
        .def("principalDirections", &PyAcad3DSolid::principalDirections, DS.ARGS())
        .def("principalMoments", &PyAcad3DSolid::principalMoments, DS.ARGS())
        .def("productOfInertia", &PyAcad3DSolid::productOfInertia, DS.ARGS())
        .def("radiiOfGyration", &PyAcad3DSolid::radiiOfGyration, DS.ARGS())
        .def("volume", &PyAcad3DSolid::volume, DS.ARGS())
        .def("boolean", &PyAcad3DSolid::boolean, DS.ARGS({ "val:PyAx.AcBooleanType","solid:PyAx.Acad3DSolid" }))
        .def("checkInterference", &PyAcad3DSolid::checkInterference, DS.ARGS({ "solid:PyAx.Acad3DSolid", "createInterferenceSolid:bool" }))
        .def("sliceSolid", &PyAcad3DSolid::sliceSolid, DS.ARGS({ "p1:PyGe.GePoint3d","p2:PyGe.GePoint3d","p3:PyGe.GePoint3d","negative:bool" }))
        .def("sectionSolid", &PyAcad3DSolid::sectionSolid, DS.ARGS({ "p1:PyGe.GePoint3d","p2:PyGe.GePoint3d","p3:PyGe.GePoint3d" }))
        .def("solidType", &PyAcad3DSolid::solidType, DS.ARGS())
        .def("position", &PyAcad3DSolid::position, DS.ARGS())
        .def("setPosition", &PyAcad3DSolid::setPosition, DS.ARGS({ "val:PyGe.GePoint3d" }))
        .def("history", &PyAcad3DSolid::history, DS.ARGS())
        .def("setHistory", &PyAcad3DSolid::setHistory, DS.ARGS({ "val:bool" }))
        .def("showHistory", &PyAcad3DSolid::showHistory, DS.ARGS())
        .def("setShowHistory", &PyAcad3DSolid::setShowHistory, DS.ARGS({ "val:bool" }))
        .def("cast", &PyAcad3DSolid::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DSolid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DSolid::PyAcad3DSolid(std::shared_ptr<PyIAcad3DSolidImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcad3DSolid::centroid() const
{
    return impObj()->GetCentroid();
}

AcGePoint3d PyAcad3DSolid::momentOfInertia() const
{
    return impObj()->GetMomentOfInertia();
}

boost::python::tuple PyAcad3DSolid::principalDirections() const
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetPrincipalDirections();
    if (val.size() == 3)
        return boost::python::make_tuple(val[0], val[1], val[2]);
    return boost::python::tuple{};
}

AcGePoint3d PyAcad3DSolid::principalMoments() const
{
    return impObj()->GetPrincipalMoments();
}

AcGePoint3d PyAcad3DSolid::productOfInertia() const
{
    return impObj()->GetProductOfInertia();
}

AcGePoint3d PyAcad3DSolid::radiiOfGyration() const
{
    return impObj()->GetRadiiOfGyration();
}

double PyAcad3DSolid::volume() const
{
    return impObj()->GetVolume();
}

void PyAcad3DSolid::boolean(PyAcBooleanType val, const PyAcad3DSolid& solid) const
{
    impObj()->Boolean(val, *solid.impObj());
}

boost::python::tuple PyAcad3DSolid::checkInterference(const PyAcad3DSolid& solid, bool createInterferenceSolid)
{
    PyAutoLockGIL lock;
    bool outSolidsInterfere = false;
    PyAcad3DSolid retVal{ impObj()->CheckInterference(*solid.impObj(), createInterferenceSolid, outSolidsInterfere) };
    return boost::python::make_tuple(outSolidsInterfere, retVal);
}

PyAcad3DSolid PyAcad3DSolid::sliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative)
{
    return PyAcad3DSolid{ impObj()->SliceSolid(p1, p2, p3, negative) };
}

PyAcadRegion PyAcad3DSolid::sectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3)
{
    return PyAcadRegion{ impObj()->SectionSolid(p1, p2, p3) };
}

std::string PyAcad3DSolid::solidType() const
{
    return wstr_to_utf8(impObj()->GetSolidType());
}

AcGePoint3d PyAcad3DSolid::position() const
{
    return impObj()->GetPosition();
}

void PyAcad3DSolid::setPosition(const AcGePoint3d& val)
{
    impObj()->SetPosition(val);
}

bool PyAcad3DSolid::history() const
{
    return impObj()->GetHistory();
}

void PyAcad3DSolid::setHistory(bool val)
{
    return impObj()->SetHistory(val);
}

bool PyAcad3DSolid::showHistory() const
{
    return impObj()->GetShowHistory();
}

void PyAcad3DSolid::setShowHistory(bool val)
{
    return impObj()->SetShowHistory(val);
}

PyAcad3DSolid PyAcad3DSolid::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcad3DSolid>(src);
}

std::string PyAcad3DSolid::className()
{
    return "Acad3DSolid";
}

PyIAcad3DSolidImpl* PyAcad3DSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcad3DSolidImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadCircle
void makePyAcadCircleWrapper()
{
    PyDocString DS("AcadCircle");
    class_<PyAcadCircle, bases<PyAcadEntity>>("AcadCircle", boost::python::no_init)
        .def("center", &PyAcadCircle::center, DS.ARGS())
        .def("setCenter", &PyAcadCircle::setCenter, DS.ARGS({ "val:PyGe.GePoint3d" }))
        .def("radius", &PyAcadCircle::radius, DS.ARGS())
        .def("setRadius", &PyAcadCircle::setRadius, DS.ARGS({ "val:float" }))
        .def("diameter", &PyAcadCircle::diameter, DS.ARGS())
        .def("setDiameter", &PyAcadCircle::setDiameter, DS.ARGS({ "val:float" }))
        .def("circumference", &PyAcadCircle::circumference, DS.ARGS())
        .def("setCircumference", &PyAcadCircle::setCircumference, DS.ARGS({ "val:float" }))
        .def("area", &PyAcadCircle::area, DS.ARGS())
        .def("setArea", &PyAcadCircle::setArea, DS.ARGS({ "val:float" }))
        .def("normal", &PyAcadCircle::normal, DS.ARGS())
        .def("setNormal", &PyAcadCircle::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadCircle::thickness, DS.ARGS())
        .def("setThickness", &PyAcadCircle::setThickness, DS.ARGS({ "val:float" }))
        .def("offset", &PyAcadCircle::offset, DS.ARGS())
        .def("cast", &PyAcadCircle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadCircle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadCircle::PyAcadCircle(std::shared_ptr<PyIAcadCircleImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadCircle::center() const
{
    return impObj()->GetCenter();
}

void PyAcadCircle::setCenter(const AcGePoint3d& val)
{
    impObj()->SetCenter(val);
}

double PyAcadCircle::radius() const
{
    return impObj()->GetRadius();
}

void PyAcadCircle::setRadius(double val)
{
    impObj()->SetRadius(val);
}

double PyAcadCircle::diameter() const
{
    return impObj()->GetDiameter();
}

void PyAcadCircle::setDiameter(double val)
{
    impObj()->SetDiameter(val);
}

double PyAcadCircle::circumference() const
{
    return impObj()->GetCircumference();
}

void PyAcadCircle::setCircumference(double val)
{
    impObj()->SetCircumference(val);
}

double PyAcadCircle::area() const
{
    return impObj()->GetArea();
}

void PyAcadCircle::setArea(double val)
{
    impObj()->SetArea(val);
}

AcGeVector3d PyAcadCircle::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadCircle::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadCircle::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadCircle::setThickness(double val)
{
    impObj()->SetThickness(val);
}

boost::python::list PyAcadCircle::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

PyAcadCircle PyAcadCircle::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadCircle>(src);
}

std::string PyAcadCircle::className()
{
    return "AcadCircle";
}

PyIAcadCircleImpl* PyAcadCircle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadCircleImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadEllipse
void makePyAcadEllipseWrapper()
{
    PyDocString DS("AcadEllipse");
    class_<PyAcadEllipse, bases<PyAcadEntity>>("AcadEllipse", boost::python::no_init)
        .def("startPoint", &PyAcadEllipse::startPoint, DS.ARGS())
        .def("endPoint", &PyAcadEllipse::endPoint, DS.ARGS())
        .def("center", &PyAcadEllipse::center, DS.ARGS())
        .def("setCenter", &PyAcadEllipse::setCenter, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("majorRadius", &PyAcadEllipse::majorRadius, DS.ARGS())
        .def("setMajorRadius", &PyAcadEllipse::setMajorRadius, DS.ARGS({ "val:float" }))
        .def("minorRadius", &PyAcadEllipse::minorRadius, DS.ARGS())
        .def("setMinorRadius", &PyAcadEllipse::setMinorRadius, DS.ARGS({ "val:float" }))
        .def("radiusRatio", &PyAcadEllipse::radiusRatio, DS.ARGS())
        .def("setRadiusRatio", &PyAcadEllipse::setRadiusRatio, DS.ARGS({ "val:float" }))
        .def("startAngle", &PyAcadEllipse::startAngle, DS.ARGS())
        .def("setStartAngle", &PyAcadEllipse::setStartAngle, DS.ARGS({ "val:float" }))
        .def("endAngle", &PyAcadEllipse::endAngle, DS.ARGS())
        .def("setEndAngle", &PyAcadEllipse::setEndAngle, DS.ARGS({ "val:float" }))
        .def("startParameter", &PyAcadEllipse::startParameter, DS.ARGS())
        .def("setStartParameter", &PyAcadEllipse::setStartParameter, DS.ARGS({ "val:float" }))
        .def("endParameter", &PyAcadEllipse::endParameter, DS.ARGS())
        .def("setEndParameter", &PyAcadEllipse::setEndParameter, DS.ARGS({ "val:float" }))
        .def("majorAxis", &PyAcadEllipse::majorAxis, DS.ARGS())
        .def("setMajorAxis", &PyAcadEllipse::setMajorAxis, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("minorAxis", &PyAcadEllipse::minorAxis, DS.ARGS())
        .def("normal", &PyAcadEllipse::normal, DS.ARGS())
        .def("setNormal", &PyAcadEllipse::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("area", &PyAcadEllipse::area, DS.ARGS())
        .def("offset", &PyAcadEllipse::offset, DS.ARGS({ "val:float" }))
        .def("cast", &PyAcadEllipse::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadEllipse::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadEllipse::PyAcadEllipse(std::shared_ptr<PyIAcadEllipseImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadEllipse::startPoint() const
{
    return impObj()->GetStartPoint();
}

AcGePoint3d PyAcadEllipse::endPoint() const
{
    return impObj()->GetEndPoint();
}

AcGePoint3d PyAcadEllipse::center() const
{
    return impObj()->GetCenter();
}

void PyAcadEllipse::setCenter(const AcGePoint3d& val)
{
    impObj()->SetCenter(val);
}

double PyAcadEllipse::majorRadius() const
{
    return impObj()->GetMajorRadius();
}

void PyAcadEllipse::setMajorRadius(double val)
{
    impObj()->SetMajorRadius(val);
}

double PyAcadEllipse::minorRadius() const
{
    return impObj()->GetMinorRadius();
}

void PyAcadEllipse::setMinorRadius(double val)
{
    impObj()->SetMinorRadius(val);
}

double PyAcadEllipse::radiusRatio() const
{
    return impObj()->GetRadiusRatio();
}

void PyAcadEllipse::setRadiusRatio(double val)
{
    impObj()->SetRadiusRatio(val);
}

double PyAcadEllipse::startAngle() const
{
    return impObj()->GetStartAngle();
}

void PyAcadEllipse::setStartAngle(double val)
{
    impObj()->SetStartAngle(val);
}

double PyAcadEllipse::endAngle() const
{
    return impObj()->GetEndAngle();
}

void PyAcadEllipse::setEndAngle(double val)
{
    impObj()->SetEndAngle(val);
}

double PyAcadEllipse::startParameter() const
{
    return impObj()->GetStartParameter();
}

void PyAcadEllipse::setStartParameter(double val)
{
    impObj()->SetStartParameter(val);
}

double PyAcadEllipse::endParameter() const
{
    return impObj()->GetEndParameter();
}

void PyAcadEllipse::setEndParameter(double val)
{
    impObj()->SetEndParameter(val);
}

AcGeVector3d PyAcadEllipse::majorAxis() const
{
    return impObj()->GetMajorAxis();
}

void PyAcadEllipse::setMajorAxis(AcGeVector3d val)
{
    impObj()->SetMajorAxis(val);
}

AcGeVector3d PyAcadEllipse::minorAxis() const
{
    return impObj()->GetMinorAxis();
}

AcGeVector3d PyAcadEllipse::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadEllipse::setNormal(AcGeVector3d val)
{
    impObj()->SetNormal(val);
}

double PyAcadEllipse::area() const
{
    return impObj()->GetArea();
}

boost::python::list PyAcadEllipse::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

PyAcadEllipse PyAcadEllipse::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadEllipse>(src);
}

std::string PyAcadEllipse::className()
{
    return "AcadEllipse";
}

PyIAcadEllipseImpl* PyAcadEllipse::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadEllipseImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLeader
void makePyAcadLeaderWrapper()
{
    PyDocString DS("AcadLeader");
    class_<PyAcadLeader, bases<PyAcadEntity>>("AcadLeader", boost::python::no_init)
        .def("coordinates", &PyAcadLeader::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadLeader::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point3d]" }))
        .def("normal", &PyAcadLeader::normal, DS.ARGS())
        .def("styleName", &PyAcadLeader::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadLeader::setStyleName, DS.ARGS({ "val:str" }))
        .def("leaderType", &PyAcadLeader::leaderType, DS.ARGS())
        .def("setLeaderType", &PyAcadLeader::setLeaderType, DS.ARGS({ "val:PyAx.AcLeaderType" }))
        .def("evaluate", &PyAcadLeader::evaluate, DS.ARGS())
        .def("coordinate", &PyAcadLeader::coordinate, DS.ARGS({ "index:int" }))
        .def("setLeaderType", &PyAcadLeader::setLeaderType, DS.ARGS({ "index:int","val:PyGe.Point3d" }))
        .def("annotation", &PyAcadLeader::annotation, DS.ARGS())
        .def("setAnnotation", &PyAcadLeader::setAnnotation, DS.ARGS({ "val:PyAx.AcadEntity" }))
        .def("arrowheadSize", &PyAcadLeader::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadLeader::setArrowheadSize, DS.ARGS({ "val:float" }))
        .def("arrowheadType", &PyAcadLeader::arrowheadType, DS.ARGS())
        .def("setArrowheadType", &PyAcadLeader::setArrowheadType, DS.ARGS({ "val:PyAx.AcDimArrowheadType" }))
        .def("dimensionLineColor", &PyAcadLeader::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadLeader::setDimensionLineColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("dimensionLineWeight", &PyAcadLeader::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadLeader::setDimensionLineWeight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("scaleFactor", &PyAcadLeader::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadLeader::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("verticalTextPosition", &PyAcadLeader::verticalTextPosition, DS.ARGS())
        .def("setVerticalTextPosition", &PyAcadLeader::setVerticalTextPosition, DS.ARGS({ "val:PyAx.AcDimVerticalJustification" }))
        .def("textGap", &PyAcadLeader::textGap, DS.ARGS())
        .def("setTextGap", &PyAcadLeader::setTextGap, DS.ARGS({ "val:float" }))
        .def("arrowheadBlock", &PyAcadLeader::arrowheadBlock, DS.ARGS())
        .def("setArrowheadBlock", &PyAcadLeader::setArrowheadBlock, DS.ARGS({ "val:str" }))
        .def("cast", &PyAcadLeader::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLeader::PyAcadLeader(std::shared_ptr<PyIAcadLeaderImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcadLeader::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcadLeader::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint3d>(coords));
}

AcGeVector3d PyAcadLeader::normal() const
{
    return impObj()->GetNormal();
}

std::string PyAcadLeader::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadLeader::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcLeaderType PyAcadLeader::leaderType() const
{
    return impObj()->GetType();
}

void PyAcadLeader::setLeaderType(PyAcLeaderType val) const
{
    impObj()->SetType(val);
}

void PyAcadLeader::evaluate()
{
    impObj()->Evaluate();
}

AcGePoint3d PyAcadLeader::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcadLeader::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAcadEntity PyAcadLeader::annotation() const
{
    return PyAcadEntity{ impObj()->GetAnnotation() };
}

void PyAcadLeader::setAnnotation(const PyAcadEntity& val)
{
    impObj()->SetAnnotation(*val.impObj());
}

double PyAcadLeader::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadLeader::setArrowheadSize(double val)
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadLeader::arrowheadType() const
{
    return impObj()->GetArrowheadType();
}

void PyAcadLeader::setArrowheadType(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowheadType(val);
}

PyAcColor PyAcadLeader::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadLeader::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcLineWeight PyAcadLeader::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadLeader::setDimensionLineWeight(PyAcLineWeight val)
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadLeader::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadLeader::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

PyAcDimVerticalJustification PyAcadLeader::verticalTextPosition() const
{
    return impObj()->GetVerticalTextPosition();
}

void PyAcadLeader::setVerticalTextPosition(PyAcDimVerticalJustification val) const
{
    impObj()->SetVerticalTextPosition(val);
}

double PyAcadLeader::textGap() const
{
    return impObj()->GetTextGap();
}

void PyAcadLeader::setTextGap(double val)
{
    impObj()->SetTextGap(val)
        ;
}

std::string PyAcadLeader::arrowheadBlock() const
{
    return wstr_to_utf8(impObj()->GetArrowheadBlock());
}

void PyAcadLeader::setArrowheadBlock(const std::string& val)
{
    impObj()->SetArrowheadBlock(utf8_to_wstr(val).c_str());
}

PyAcadLeader PyAcadLeader::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLeader>(src);
}

std::string PyAcadLeader::className()
{
    return "AcadLeader";
}

PyIAcadLeaderImpl* PyAcadLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLeaderImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMText
void makePyAcadMTextWrapper()
{
    PyDocString DS("AcadMText");
    class_<PyAcadMText, bases<PyAcadEntity>>("AcadMText", boost::python::no_init)
        .def("text", &PyAcadMText::text, DS.ARGS())
        .def("textString", &PyAcadMText::textString, DS.ARGS())
        .def("setTextString", &PyAcadMText::setTextString, DS.ARGS({ "val:str" }))
        .def("styleName", &PyAcadMText::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadMText::setStyleName, DS.ARGS({ "val:str" }))
        .def("attachmentPoint", &PyAcadMText::attachmentPoint, DS.ARGS())
        .def("setAttachmentPoint", &PyAcadMText::setAttachmentPoint, DS.ARGS({ "val:PyAx.AcAttachmentPoint" }))
        .def("drawingDirection", &PyAcadMText::drawingDirection, DS.ARGS())
        .def("setDrawingDirection", &PyAcadMText::setDrawingDirection, DS.ARGS({ "val:PyAx.AcDrawingDirection" }))
        .def("width", &PyAcadMText::width, DS.ARGS())
        .def("setWidth", &PyAcadMText::setWidth, DS.ARGS({ "val:float" }))
        .def("height", &PyAcadMText::height, DS.ARGS())
        .def("setHeight", &PyAcadMText::setHeight, DS.ARGS({ "val:float" }))
        .def("rotation", &PyAcadMText::rotation, DS.ARGS())
        .def("setRotation", &PyAcadMText::setRotation, DS.ARGS({ "val:float" }))
        .def("insertionPoint", &PyAcadMText::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadMText::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("normal", &PyAcadMText::normal, DS.ARGS())
        .def("setNormal", &PyAcadMText::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("lineSpacingFactor", &PyAcadMText::lineSpacingFactor, DS.ARGS())
        .def("setLineSpacingFactor", &PyAcadMText::setLineSpacingFactor, DS.ARGS({ "val:float" }))
        .def("lineSpacingStyle", &PyAcadMText::lineSpacingStyle, DS.ARGS())
        .def("setLineSpacingStyle", &PyAcadMText::setLineSpacingStyle, DS.ARGS({ "val:str" }))
        .def("lineSpacingDistance", &PyAcadMText::lineSpacingDistance, DS.ARGS())
        .def("setLineSpacingDistance", &PyAcadMText::setLineSpacingDistance, DS.ARGS({ "val:float" }))
        .def("backgroundFill", &PyAcadMText::backgroundFill, DS.ARGS())
        .def("setBackgroundFill", &PyAcadMText::setBackgroundFill, DS.ARGS({ "val:bool" }))
        .def("fieldCode", &PyAcadMText::fieldCode, DS.ARGS())
        .def("cast", &PyAcadMText::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMText::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMText::PyAcadMText(std::shared_ptr<PyIAcadMTextImpl> ptr)
    : PyAcadEntity(ptr)
{
}

std::string PyAcadMText::text() const
{
    return wstr_to_utf8(impObj()->GetText());
}

std::string PyAcadMText::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadMText::setTextString(const std::string& val)
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

std::string PyAcadMText::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadMText::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcAttachmentPoint PyAcadMText::attachmentPoint() const
{
    return impObj()->GetAttachmentPoint();
}

void PyAcadMText::setAttachmentPoint(PyAcAttachmentPoint val)
{
    impObj()->SetAttachmentPoint(val);
}

PyAcDrawingDirection PyAcadMText::drawingDirection() const
{
    return impObj()->GetDrawingDirection();
}

void PyAcadMText::setDrawingDirection(PyAcDrawingDirection val)
{
    impObj()->SetDrawingDirection(val);
}

double PyAcadMText::width() const
{
    return impObj()->GetWidth();
}

void PyAcadMText::setWidth(double val)
{
    impObj()->SetWidth(val);
}

double PyAcadMText::height() const
{
    return impObj()->GetHeight();
}

void PyAcadMText::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadMText::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadMText::setRotation(double val)
{
    impObj()->SetRotation(val);
}

AcGePoint3d PyAcadMText::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadMText::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

AcGeVector3d PyAcadMText::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadMText::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadMText::lineSpacingFactor() const
{
    return impObj()->GetLineSpacingFactor();
}

void PyAcadMText::setLineSpacingFactor(double val)
{
    impObj()->SetLineSpacingFactor(val);
}

PyAcLineSpacingStyle PyAcadMText::lineSpacingStyle() const
{
    return impObj()->GetLineSpacingStyle();
}

void PyAcadMText::setLineSpacingStyle(PyAcLineSpacingStyle val)
{
    impObj()->SetLineSpacingStyle(val);
}

double PyAcadMText::lineSpacingDistance() const
{
    return impObj()->GetLineSpacingDistance();
}

void PyAcadMText::setLineSpacingDistance(double val)
{
    impObj()->SetLineSpacingDistance(val);
}

bool PyAcadMText::backgroundFill() const
{
    return impObj()->GetBackgroundFill();
}

void PyAcadMText::setBackgroundFill(bool val)
{
    impObj()->SetBackgroundFill(val);
}

std::string PyAcadMText::fieldCode() const
{
    return wstr_to_utf8(impObj()->GetFieldCode());
}

PyAcadMText PyAcadMText::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMText>(src);
}

std::string PyAcadMText::className()
{
    return "AcadMText";
}

PyIAcadMTextImpl* PyAcadMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMTextImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPoint
void makePyAcadPointWrapper()
{
    PyDocString DS("AcadPoint");
    class_<PyAcadPoint, bases<PyAcadEntity>>("AcadPoint", boost::python::no_init)
        .def("coordinates", &PyAcadPoint::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadPoint::setCoordinates, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("normal", &PyAcadPoint::normal, DS.ARGS())
        .def("setNormal", &PyAcadPoint::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadPoint::thickness, DS.ARGS())
        .def("setThickness", &PyAcadPoint::setThickness, DS.ARGS({ "val:float" }))
        .def("cast", &PyAcadPoint::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPoint::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPoint::PyAcadPoint(std::shared_ptr<PyIAcadPointImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadPoint::coordinates() const
{
    return impObj()->GetCoordinates();
}

void PyAcadPoint::setCoordinates(const AcGePoint3d& val)
{
    impObj()->SetCoordinates(val);
}

AcGeVector3d PyAcadPoint::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadPoint::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadPoint::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadPoint::setThickness(double val)
{
    impObj()->SetThickness(val);
}

PyAcadPoint PyAcadPoint::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPoint>(src);
}

std::string PyAcadPoint::className()
{
    return "AcadPoint";
}

PyIAcadPointImpl* PyAcadPoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPointImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLWPolyline
void makePyAcadLWPolylineWrapper()
{
    PyDocString DS("AcadLWPolyline");
    class_<PyAcadLWPolyline, bases<PyAcadEntity>>("AcadLWPolyline", boost::python::no_init)
        .def("coordinates", &PyAcadLWPolyline::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadLWPolyline::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point2d]" }))
        .def("normal", &PyAcadLWPolyline::normal, DS.ARGS())
        .def("setNormal", &PyAcadLWPolyline::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadLWPolyline::thickness, DS.ARGS())
        .def("setThickness", &PyAcadLWPolyline::setThickness, DS.ARGS({ "val:float" }))
        .def("addVertex", &PyAcadLWPolyline::addVertex, DS.ARGS({ "index:int", "val:PyGe.Point2d" }))
        .def("explode", &PyAcadLWPolyline::explode, DS.ARGS())
        .def("bulge", &PyAcadLWPolyline::bulge, DS.ARGS({ "index:int" }))
        .def("setBulge", &PyAcadLWPolyline::setBulge, DS.ARGS({ "index:int","val:float" }))
        .def("width", &PyAcadLWPolyline::width, DS.ARGS({ "index:int" }))
        .def("setWidth", &PyAcadLWPolyline::setWidth, DS.ARGS({ "index:int","startWidth:float","endWidth:float" }))
        .def("constantWidth", &PyAcadLWPolyline::constantWidth, DS.ARGS())
        .def("setConstantWidth", &PyAcadLWPolyline::setConstantWidth, DS.ARGS({ "val:float" }))
        .def("offset", &PyAcadLWPolyline::offset, DS.ARGS({ "val:float" }))
        .def("elevation", &PyAcadLWPolyline::elevation, DS.ARGS())
        .def("setElevation", &PyAcadLWPolyline::setElevation, DS.ARGS({ "val:float" }))
        .def("area", &PyAcadLWPolyline::area, DS.ARGS())
        .def("coordinate", &PyAcadLWPolyline::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcadLWPolyline::setCoordinate, DS.ARGS({ "index:int","val:PyGe.Point2d" }))
        .def("isClosed", &PyAcadLWPolyline::isClosed, DS.ARGS())
        .def("setClosed", &PyAcadLWPolyline::setClosed, DS.ARGS({ "val:bool" }))
        .def("linetypeGeneration", &PyAcadLWPolyline::linetypeGeneration, DS.ARGS())
        .def("setLinetypeGeneration", &PyAcadLWPolyline::setLinetypeGeneration, DS.ARGS({ "val:bool" }))
        .def("length", &PyAcadLWPolyline::length, DS.ARGS())
        .def("cast", &PyAcadLWPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLWPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLWPolyline::PyAcadLWPolyline(std::shared_ptr<PyIAcadLWPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcadLWPolyline::coordinates() const
{
    return Point2dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcadLWPolyline::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint2d>(coords));
}

AcGeVector3d PyAcadLWPolyline::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadLWPolyline::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadLWPolyline::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadLWPolyline::setThickness(double val)
{
    impObj()->SetThickness(val);
}

void PyAcadLWPolyline::addVertex(int index, const AcGePoint2d& val)
{
    impObj()->AddVertex(index, val);
}

boost::python::list PyAcadLWPolyline::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

double PyAcadLWPolyline::bulge(int index) const
{
    return impObj()->GetBulge(index);
}

void PyAcadLWPolyline::setBulge(int index, double val)
{
    return impObj()->SetBulge(index, val);
}

boost::python::tuple PyAcadLWPolyline::width(int index) const
{
    PyAutoLockGIL lock;
    double startWidth = 0.0;
    double endWidth = 0.0;
    impObj()->GetWidth(index, startWidth, endWidth);
    return boost::python::make_tuple(startWidth, endWidth);
}

void PyAcadLWPolyline::setWidth(int index, double startWidth, double endWidth)
{
    impObj()->SetWidth(index, startWidth, endWidth);
}

double PyAcadLWPolyline::constantWidth() const
{
    return impObj()->GetConstantWidth();
}

void PyAcadLWPolyline::setConstantWidth(double val)
{
    impObj()->SetConstantWidth(val);
}

boost::python::list PyAcadLWPolyline::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

double PyAcadLWPolyline::elevation() const
{
    return impObj()->GetElevation();
}

void PyAcadLWPolyline::setElevation(double val)
{
    impObj()->SetElevation(val);
}

double PyAcadLWPolyline::area() const
{
    return impObj()->GetArea();
}

AcGePoint2d PyAcadLWPolyline::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcadLWPolyline::setCoordinate(int index, const AcGePoint2d& val)
{
    impObj()->SetCoordinate(index, val);
}

bool PyAcadLWPolyline::isClosed() const
{
    return impObj()->GetClosed();
}

void PyAcadLWPolyline::setClosed(bool val)
{
    impObj()->SetClosed(val);
}

bool PyAcadLWPolyline::linetypeGeneration() const
{
    return impObj()->GetLinetypeGeneration();
}

void PyAcadLWPolyline::setLinetypeGeneration(bool val)
{
    impObj()->SetLinetypeGeneration(val);
}

double PyAcadLWPolyline::length() const
{
    return impObj()->GetLength();
}

PyAcadLWPolyline PyAcadLWPolyline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLWPolyline>(src);
}

std::string PyAcadLWPolyline::className()
{
    return "AcadLWPolyline";
}

PyIAcadLWPolylineImpl* PyAcadLWPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLWPolylineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPolyline
void makePyAcadPolylineWrapper()
{
    PyDocString DS("AcadPolyline");
    class_<PyAcadPolyline, bases<PyAcadEntity>>("AcadPolyline", boost::python::no_init)
        .def("coordinates", &PyAcadPolyline::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadPolyline::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point3d]" }))
        .def("normal", &PyAcadPolyline::normal, DS.ARGS())
        .def("setNormal", &PyAcadPolyline::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadPolyline::thickness, DS.ARGS())
        .def("setThickness", &PyAcadPolyline::setThickness, DS.ARGS({ "val:float" }))
        .def("explode", &PyAcadPolyline::explode, DS.ARGS())
        .def("bulge", &PyAcadPolyline::bulge, DS.ARGS({ "index:int" }))
        .def("setBulge", &PyAcadPolyline::setBulge, DS.ARGS({ "index:int","val:float" }))
        .def("width", &PyAcadPolyline::width, DS.ARGS({ "index:int" }))
        .def("setWidth", &PyAcadPolyline::setWidth, DS.ARGS({ "index:int","startWidth:float","endWidth:float" }))
        .def("constantWidth", &PyAcadPolyline::constantWidth, DS.ARGS())
        .def("setConstantWidth", &PyAcadPolyline::setConstantWidth, DS.ARGS({ "val:float" }))
        .def("offset", &PyAcadPolyline::offset, DS.ARGS({ "val:float" }))
        .def("elevation", &PyAcadPolyline::elevation, DS.ARGS())
        .def("setElevation", &PyAcadPolyline::setElevation, DS.ARGS({ "val:float" }))
        .def("area", &PyAcadPolyline::area, DS.ARGS())
        .def("coordinate", &PyAcadPolyline::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcadPolyline::setCoordinate, DS.ARGS({ "index:int","val:PyGe.Point3d" }))
        .def("isClosed", &PyAcadPolyline::isClosed, DS.ARGS())
        .def("setClosed", &PyAcadPolyline::setClosed, DS.ARGS({ "val:bool" }))
        .def("linetypeGeneration", &PyAcadPolyline::linetypeGeneration, DS.ARGS())
        .def("setLinetypeGeneration", &PyAcadPolyline::setLinetypeGeneration, DS.ARGS({ "val:bool" }))
        .def("length", &PyAcadPolyline::length, DS.ARGS())
        .def("cast", &PyAcadPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolyline::PyAcadPolyline(std::shared_ptr<PyIAcadPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcadPolyline::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcadPolyline::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint3d>(coords));
}

AcGeVector3d PyAcadPolyline::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadPolyline::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadPolyline::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadPolyline::setThickness(double val)
{
    impObj()->SetThickness(val);
}

boost::python::list PyAcadPolyline::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

double PyAcadPolyline::bulge(int index) const
{
    return impObj()->GetBulge(index);
}

void PyAcadPolyline::setBulge(int index, double val)
{
    return impObj()->SetBulge(index, val);
}

boost::python::tuple PyAcadPolyline::width(int index) const
{
    PyAutoLockGIL lock;
    double startWidth = 0.0;
    double endWidth = 0.0;
    impObj()->GetWidth(index, startWidth, endWidth);
    return boost::python::make_tuple(startWidth, endWidth);
}

void PyAcadPolyline::setWidth(int index, double startWidth, double endWidth)
{
    impObj()->SetWidth(index, startWidth, endWidth);
}

double PyAcadPolyline::constantWidth() const
{
    return impObj()->GetConstantWidth();
}

void PyAcadPolyline::setConstantWidth(double val)
{
    impObj()->SetConstantWidth(val);
}

boost::python::list PyAcadPolyline::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

double PyAcadPolyline::elevation() const
{
    return impObj()->GetElevation();
}

void PyAcadPolyline::setElevation(double val)
{
    impObj()->SetElevation(val);
}

double PyAcadPolyline::area() const
{
    return impObj()->GetArea();
}

AcGePoint3d PyAcadPolyline::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcadPolyline::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

bool PyAcadPolyline::isClosed() const
{
    return impObj()->GetClosed();
}

void PyAcadPolyline::setClosed(bool val)
{
    impObj()->SetClosed(val);
}

bool PyAcadPolyline::linetypeGeneration() const
{
    return impObj()->GetLinetypeGeneration();
}

void PyAcadPolyline::setLinetypeGeneration(bool val)
{
    impObj()->SetLinetypeGeneration(val);
}

double PyAcadPolyline::length() const
{
    return impObj()->GetLength();
}

PyAcadPolyline PyAcadPolyline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPolyline>(src);
}

std::string PyAcadPolyline::className()
{
    return "AcadPolyline";
}

PyIAcadPolylineImpl* PyAcadPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPolylineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadRay
void makePyAcadRayWrapper()
{
    PyDocString DS("AcadRay");
    class_<PyAcadRay, bases<PyAcadEntity>>("AcadRay", boost::python::no_init)
        .def("basePoint", &PyAcadRay::basePoint, DS.ARGS())
        .def("setBasePoint", &PyAcadRay::setBasePoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("secondPoint", &PyAcadRay::secondPoint, DS.ARGS())
        .def("setSecondPoint", &PyAcadRay::setSecondPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("directionVector", &PyAcadRay::directionVector, DS.ARGS())
        .def("setDirectionVector", &PyAcadRay::setDirectionVector, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("cast", &PyAcadRay::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRay::PyAcadRay(std::shared_ptr<PyIAcadRayImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadRay::basePoint() const
{
    return impObj()->GetBasePoint();
}

void PyAcadRay::setBasePoint(const AcGePoint3d& val)
{
    impObj()->SetBasePoint(val);
}

AcGePoint3d PyAcadRay::secondPoint() const
{
    return impObj()->GetSecondPoint();
}

void PyAcadRay::setSecondPoint(const AcGePoint3d& val)
{
    impObj()->SetSecondPoint(val);
}

AcGeVector3d PyAcadRay::directionVector() const
{
    return impObj()->GetDirectionVector();
}

void PyAcadRay::setDirectionVector(const AcGeVector3d& val)
{
    impObj()->SetDirectionVector(val);
}

PyAcadRay PyAcadRay::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadRay>(src);
}

std::string PyAcadRay::className()
{
    return "AcadRay";
}

PyIAcadRayImpl* PyAcadRay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadRayImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadShape
void makePyAcadShapeWrapper()
{
    PyDocString DS("AcadShape");
    class_<PyAcadShape, bases<PyAcadEntity>>("AcadShape", boost::python::no_init)
        .def("insertionPoint", &PyAcadShape::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadShape::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("name", &PyAcadShape::name, DS.ARGS())
        .def("setName", &PyAcadShape::setName, DS.ARGS({ "val:str" }))
        .def("height", &PyAcadShape::height, DS.ARGS())
        .def("setHeight", &PyAcadShape::setHeight, DS.ARGS({ "val:float" }))
        .def("rotation", &PyAcadShape::rotation, DS.ARGS())
        .def("setRotation", &PyAcadShape::setRotation, DS.ARGS({ "val:float" }))
        .def("scaleFactor", &PyAcadShape::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadShape::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("obliqueAngle", &PyAcadShape::obliqueAngle, DS.ARGS())
        .def("setObliqueAngle", &PyAcadShape::setObliqueAngle, DS.ARGS({ "val:float" }))
        .def("normal", &PyAcadShape::normal, DS.ARGS())
        .def("setNormal", &PyAcadShape::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadShape::thickness, DS.ARGS())
        .def("setThickness", &PyAcadShape::setThickness, DS.ARGS({ "val:float" }))
        .def("cast", &PyAcadShape::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadShape::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadShape::PyAcadShape(std::shared_ptr<PyIAcadShapeImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadShape::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadShape::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

std::string PyAcadShape::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadShape::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

double PyAcadShape::height() const
{
    return impObj()->GetHeight();
}

void PyAcadShape::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadShape::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadShape::setRotation(double val)
{
    impObj()->SetRotation(val);
}

double PyAcadShape::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadShape::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

double PyAcadShape::obliqueAngle() const
{
    return impObj()->GetObliqueAngle();
}

void PyAcadShape::setObliqueAngle(double val)
{
    impObj()->SetObliqueAngle(val);
}

AcGeVector3d PyAcadShape::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadShape::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadShape::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadShape::setThickness(double val)
{
    impObj()->SetThickness(val);
}

PyAcadShape PyAcadShape::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadShape>(src);
}

std::string PyAcadShape::className()
{
    return "AcadShape";
}

PyIAcadShapeImpl* PyAcadShape::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadShapeImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSolid
void makePyAcadSolidWrapper()
{
    PyDocString DS("AcadSolid");
    class_<PyAcadSolid, bases<PyAcadEntity>>("AcadSolid", boost::python::no_init)
        .def("coordinates", &PyAcadSolid::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcadSolid::setCoordinates, DS.ARGS({ "coords:Iterable[PyGe.Point3d]" }))
        .def("normal", &PyAcadSolid::normal, DS.ARGS())
        .def("setNormal", &PyAcadSolid::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("thickness", &PyAcadSolid::thickness, DS.ARGS())
        .def("setThickness", &PyAcadSolid::setThickness, DS.ARGS({ "val:float" }))
        .def("cast", &PyAcadSolid::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSolid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSolid::PyAcadSolid(std::shared_ptr<PyIAcadSolidImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcadSolid::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcadSolid::setCoordinates(const boost::python::object& coords)
{
    impObj()->SetCoordinates(py_list_to_std_vector<AcGePoint3d>(coords));
}

AcGeVector3d PyAcadSolid::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadSolid::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadSolid::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadSolid::setThickness(double val)
{
    impObj()->SetThickness(val);
}

AcGePoint3d PyAcadSolid::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcadSolid::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAcadSolid PyAcadSolid::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSolid>(src);
}

std::string PyAcadSolid::className()
{
    return "AcadSolid";
}

PyIAcadSolidImpl* PyAcadSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSolidImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSpline
void makePyAcadSplineWrapper()
{
    PyDocString DS("AcadSpline");
    class_<PyAcadSpline, bases<PyAcadEntity>>("AcadSpline", boost::python::no_init)
        .def("numberOfControlPoints", &PyAcadSpline::numberOfControlPoints, DS.ARGS())
        .def("controlPoints", &PyAcadSpline::controlPoints, DS.ARGS())
        .def("setControlPoints", &PyAcadSpline::setControlPoints, DS.ARGS({ "items:Iterable[PyGe.Point3d]" }))
        .def("fitPoints", &PyAcadSpline::fitPoints, DS.ARGS())
        .def("setFitPoints", &PyAcadSpline::setFitPoints, DS.ARGS({ "items:Iterable[PyGe.Point3d]" }))
        .def("degree", &PyAcadSpline::degree, DS.ARGS())
        .def("closed", &PyAcadSpline::closed, DS.ARGS())
        .def("isPlanar", &PyAcadSpline::isPlanar, DS.ARGS())
        .def("isRational", &PyAcadSpline::isRational, DS.ARGS())
        .def("isPeriodic", &PyAcadSpline::isPeriodic, DS.ARGS())
        .def("startTangent", &PyAcadSpline::startTangent, DS.ARGS())
        .def("setStartTangent", &PyAcadSpline::setStartTangent, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("endTangent", &PyAcadSpline::endTangent, DS.ARGS())
        .def("setEndTangent", &PyAcadSpline::setEndTangent, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("fitTolerance", &PyAcadSpline::fitTolerance, DS.ARGS())
        .def("setFitTolerance", &PyAcadSpline::setFitTolerance, DS.ARGS({ "val:float" }))
        .def("area", &PyAcadSpline::area, DS.ARGS())
        .def("controlPoint", &PyAcadSpline::controlPoint, DS.ARGS({ "val:int" }))
        .def("setControlPoint", &PyAcadSpline::setControlPoint, DS.ARGS({ "val:int","point:PyGe.Point3d" }))
        .def("fitPoint", &PyAcadSpline::fitPoint, DS.ARGS({ "val:int" }))
        .def("setFitPoint", &PyAcadSpline::setFitPoint, DS.ARGS({ "val:int","point:PyGe.Point3d" }))
        .def("weight", &PyAcadSpline::weight, DS.ARGS({ "val:int" }))
        .def("setWeight", &PyAcadSpline::setWeight, DS.ARGS({ "val:int","weight:float" }))
        .def("addFitPoint", &PyAcadSpline::addFitPoint, DS.ARGS({ "val:int","point:PyGe.Point3d" }))
        .def("deleteFitPoint", &PyAcadSpline::deleteFitPoint, DS.ARGS({ "val:int" }))
        .def("elevateOrder", &PyAcadSpline::elevateOrder, DS.ARGS({ "val:int" }))
        .def("offset", &PyAcadSpline::offset, DS.ARGS({ "val:float" }))
        .def("purgeFitData", &PyAcadSpline::purgeFitData, DS.ARGS())
        .def("reverse", &PyAcadSpline::reverse, DS.ARGS())
        .def("knots", &PyAcadSpline::knots, DS.ARGS())
        .def("setKnots", &PyAcadSpline::setKnots, DS.ARGS({ "items:Iterable[PyGe.Vector3d]" }))
        .def("weights", &PyAcadSpline::weights, DS.ARGS())
        .def("setWeights", &PyAcadSpline::setWeights, DS.ARGS({ "items:Iterable[float]" }))
        .def("knotParameterization", &PyAcadSpline::knotParameterization, DS.ARGS())
        .def("setKnotParameterization", &PyAcadSpline::setKnotParameterization, DS.ARGS({ "val:PyAx.AcSplineKnotParameterizationType" }))
        .def("splineFrame", &PyAcadSpline::splineFrame, DS.ARGS())
        .def("setSplineFrame", &PyAcadSpline::setSplineFrame, DS.ARGS({ "val:PyAx.AcSplineFrameType" }))
        .def("splineMethod", &PyAcadSpline::splineMethod, DS.ARGS())
        .def("setSplineMethod", &PyAcadSpline::setSplineMethod, DS.ARGS({ "val:PyAx.AcSplineMethodType" }))
        .def("degree2", &PyAcadSpline::degree2, DS.ARGS())
        .def("setDegree2", &PyAcadSpline::setDegree2, DS.ARGS({ "val:int" }))
        .def("closed2", &PyAcadSpline::closed2, DS.ARGS())
        .def("setClosed2", &PyAcadSpline::setClosed2, DS.ARGS({ "val:bool" }))
        .def("cast", &PyAcadSpline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSpline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSpline::PyAcadSpline(std::shared_ptr<PyIAcadSplineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

long PyAcadSpline::numberOfControlPoints() const
{
    return impObj()->GetNumberOfControlPoints();
}

boost::python::list PyAcadSpline::controlPoints() const
{
    return Point3dArrayToPyList(impObj()->GetControlPoints());
}

void PyAcadSpline::setControlPoints(const boost::python::object& coords)
{
    impObj()->SetControlPoints(py_list_to_std_vector<AcGePoint3d>(coords));
}

boost::python::list PyAcadSpline::fitPoints() const
{
    return Point3dArrayToPyList(impObj()->GetFitPoints());
}

void PyAcadSpline::setFitPoints(const boost::python::object& coords)
{
    impObj()->SetFitPoints(py_list_to_std_vector<AcGePoint3d>(coords));
}

long PyAcadSpline::degree() const
{
    return impObj()->GetDegree();
}

bool PyAcadSpline::closed() const
{
    return impObj()->GetClosed();
}

bool PyAcadSpline::isPlanar() const
{
    return impObj()->GetIsPlanar();
}

bool PyAcadSpline::isRational() const
{
    return impObj()->GetIsRational();
}

bool PyAcadSpline::isPeriodic() const
{
    return impObj()->GetIsPeriodic();
}

AcGeVector3d PyAcadSpline::startTangent() const
{
    return impObj()->GetStartTangent();
}

void PyAcadSpline::setStartTangent(const AcGeVector3d& val)
{
    impObj()->SetStartTangent(val);
}

AcGeVector3d PyAcadSpline::endTangent() const
{
    return impObj()->GetEndTangent();
}

void PyAcadSpline::setEndTangent(const AcGeVector3d& val)
{
    impObj()->SetEndTangent(val);
}

double PyAcadSpline::fitTolerance() const
{
    return impObj()->GetFitTolerance();
}

void PyAcadSpline::setFitTolerance(double val)
{
    impObj()->SetFitTolerance(val);
}

double PyAcadSpline::area() const
{
    return impObj()->GetArea();
}

AcGePoint3d PyAcadSpline::controlPoint(int index) const
{
    return impObj()->GetControlPoint(index);
}

void PyAcadSpline::setControlPoint(int index, const AcGePoint3d& val)
{
    impObj()->SetControlPoint(index, val);
}

AcGePoint3d PyAcadSpline::fitPoint(int index) const
{
    return impObj()->GetFitPoint(index);
}

void PyAcadSpline::setFitPoint(int index, const AcGePoint3d& val)
{
    impObj()->SetFitPoint(index, val);
}

double PyAcadSpline::weight(int index) const
{
    return impObj()->GetWeight(index);
}

void PyAcadSpline::setWeight(int index, double val)
{
    impObj()->SetWeight(index, val);
}

void PyAcadSpline::addFitPoint(int index, const AcGePoint3d& val)
{
    impObj()->AddFitPoint(index, val);
}

void PyAcadSpline::deleteFitPoint(int index)
{
    return impObj()->DeleteFitPoint(index);
}

void PyAcadSpline::elevateOrder(int index)
{
    return impObj()->ElevateOrder(index);
}

boost::python::list PyAcadSpline::offset(double val) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Offset(val))
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

void PyAcadSpline::purgeFitData()
{
    return impObj()->PurgeFitData();
}

void PyAcadSpline::reverse()
{
    return impObj()->Reverse();
}

boost::python::list PyAcadSpline::knots() const
{
    return Vector3dArrayToPyList(impObj()->GetKnots());
}

void PyAcadSpline::setKnots(const boost::python::object& val)
{
    impObj()->SetKnots(py_list_to_std_vector<AcGeVector3d>(val));
}

boost::python::list PyAcadSpline::weights() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetWeights())
        pylist.append(item);
    return pylist;
}

void PyAcadSpline::setWeights(const boost::python::object& val)
{
    impObj()->SetWeights(py_list_to_std_vector<double>(val));
}

PyAcSplineKnotParameterizationType PyAcadSpline::knotParameterization() const
{
    return impObj()->GetKnotParameterization();
}

void PyAcadSpline::setKnotParameterization(PyAcSplineKnotParameterizationType val)
{
    impObj()->SetKnotParameterization(val);
}

PyAcSplineFrameType PyAcadSpline::splineFrame() const
{
    return impObj()->GetSplineFrame();
}

void PyAcadSpline::setSplineFrame(PyAcSplineFrameType val)
{
    impObj()->SetSplineFrame(val);
}

PyAcSplineMethodType PyAcadSpline::splineMethod() const
{
    return impObj()->GetSplineMethod();
}

void PyAcadSpline::setSplineMethod(PyAcSplineMethodType val)
{
    impObj()->SetSplineMethod(val);
}

long PyAcadSpline::degree2() const
{
    return impObj()->GetDegree2();
}

void PyAcadSpline::setDegree2(long val)
{
    impObj()->SetDegree2(val);
}

bool PyAcadSpline::closed2() const
{
    return impObj()->GetClosed2();
}

void PyAcadSpline::setClosed2(bool val)
{
    impObj()->SetClosed2(val);
}

PyAcadSpline PyAcadSpline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSpline>(src);
}

std::string PyAcadSpline::className()
{
    return "AcadSpline";
}

PyIAcadSplineImpl* PyAcadSpline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSplineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadText
void makePyAcadTextWrapper()
{
    PyDocString DS("AcadText");
    class_<PyAcadText, bases<PyAcadEntity>>("AcadText", boost::python::no_init)
        .def("textString", &PyAcadText::textString, DS.ARGS())
        .def("setTextString", &PyAcadText::setTextString, DS.ARGS({ "val: str" }))
        .def("styleName", &PyAcadText::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadText::setStyleName, DS.ARGS({ "val: str" }))
        .def("alignment", &PyAcadText::alignment, DS.ARGS())
        .def("setAlignment", &PyAcadText::setAlignment, DS.ARGS({ "val: PyAx.AcAlignment" }))
        .def("horizontalAlignment", &PyAcadText::horizontalAlignment, DS.ARGS())
        .def("setHorizontalAlignment", &PyAcadText::setHorizontalAlignment, DS.ARGS({ "val: PyAx.AcHorizontalAlignment" }))
        .def("verticalAlignment", &PyAcadText::verticalAlignment, DS.ARGS())
        .def("setVerticalAlignment", &PyAcadText::setVerticalAlignment, DS.ARGS({ "val: PyAx.AcVerticalAlignment" }))
        .def("height", &PyAcadText::height, DS.ARGS())
        .def("setHeight", &PyAcadText::setHeight, DS.ARGS({ "val:float" }))
        .def("rotation", &PyAcadText::rotation, DS.ARGS())
        .def("setRotation", &PyAcadText::setRotation, DS.ARGS({ "val:float" }))
        .def("scaleFactor", &PyAcadText::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadText::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("obliqueAngle", &PyAcadText::obliqueAngle, DS.ARGS())
        .def("setObliqueAngle", &PyAcadText::setObliqueAngle, DS.ARGS({ "val:float" }))
        .def("textAlignmentPoint", &PyAcadText::textAlignmentPoint, DS.ARGS())
        .def("setTextAlignmentPoint", &PyAcadText::setTextAlignmentPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("insertionPoint", &PyAcadText::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadText::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("normal", &PyAcadText::normal, DS.ARGS())
        .def("setNormal", &PyAcadText::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("textGenerationFlag", &PyAcadText::textGenerationFlag, DS.ARGS())
        .def("setTextGenerationFlag", &PyAcadText::setTextGenerationFlag, DS.ARGS({ "val:long" }))
        .def("thickness", &PyAcadText::thickness, DS.ARGS())
        .def("setThickness", &PyAcadText::setThickness, DS.ARGS({ "val:float" }))
        .def("upsideDown", &PyAcadText::upsideDown, DS.ARGS())
        .def("setUpsideDown", &PyAcadText::setUpsideDown, DS.ARGS({ "val:bool" }))
        .def("backward", &PyAcadText::backward, DS.ARGS())
        .def("setBackward", &PyAcadText::setBackward, DS.ARGS({ "val:bool" }))
        .def("fieldCode", &PyAcadText::fieldCode, DS.ARGS())
        .def("cast", &PyAcadText::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadText::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadText::PyAcadText(std::shared_ptr<PyIAcadTextImpl> ptr)
    : PyAcadEntity(ptr)
{
}

std::string PyAcadText::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadText::setTextString(const std::string& val)
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

std::string PyAcadText::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadText::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcAlignment PyAcadText::alignment() const
{
    return impObj()->GetAlignment();
}

void PyAcadText::setAlignment(PyAcAlignment val)
{
    impObj()->GetAlignment();
}

PyAcHorizontalAlignment PyAcadText::horizontalAlignment() const
{
    return impObj()->GetHorizontalAlignment();
}

void PyAcadText::setHorizontalAlignment(PyAcHorizontalAlignment val)
{
    impObj()->SetHorizontalAlignment(val);
}

PyAcVerticalAlignment PyAcadText::verticalAlignment() const
{
    return impObj()->GetVerticalAlignment();
}

void PyAcadText::setVerticalAlignment(PyAcVerticalAlignment val)
{
    impObj()->SetVerticalAlignment(val);
}

double PyAcadText::height() const
{
    return impObj()->GetHeight();
}

void PyAcadText::setHeight(double val)
{
    impObj()->SetHeight(val);
}

double PyAcadText::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadText::setRotation(double val)
{
    impObj()->SetRotation(val);
}

double PyAcadText::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadText::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

double PyAcadText::obliqueAngle() const
{
    return impObj()->GetObliqueAngle();
}

void PyAcadText::setObliqueAngle(double val)
{
    impObj()->SetObliqueAngle(val);
}

AcGePoint3d PyAcadText::textAlignmentPoint() const
{
    return impObj()->GetTextAlignmentPoint();
}

void PyAcadText::setTextAlignmentPoint(const AcGePoint3d& val)
{
    impObj()->SetTextAlignmentPoint(val);
}

AcGePoint3d PyAcadText::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadText::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

AcGeVector3d PyAcadText::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadText::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

long PyAcadText::textGenerationFlag() const
{
    return impObj()->GetTextGenerationFlag();
}

void PyAcadText::setTextGenerationFlag(long val)
{
    impObj()->SetTextGenerationFlag(val);
}

double PyAcadText::thickness() const
{
    return impObj()->GetThickness();
}

void PyAcadText::setThickness(double val)
{
    impObj()->SetThickness(val);
}

bool PyAcadText::upsideDown() const
{
    return impObj()->GetUpsideDown();
}

void PyAcadText::setUpsideDown(bool val)
{
    impObj()->SetUpsideDown(val);
}

bool PyAcadText::backward() const
{
    return impObj()->GetBackward();
}

void PyAcadText::setBackward(bool val)
{
    impObj()->SetBackward(val);
}

std::string PyAcadText::fieldCode() const
{
    return wstr_to_utf8(impObj()->GetFieldCode());
}

PyAcadText PyAcadText::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadText>(src);
}

std::string PyAcadText::className()
{
    return "AcadText";
}

PyIAcadTextImpl* PyAcadText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTextImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadTolerance
void makePyAcadToleranceWrapper()
{
    PyDocString DS("AcadTolerance");
    class_<PyAcadTolerance, bases<PyAcadEntity>>("AcadTolerance", boost::python::no_init)
        .def("directionVector", &PyAcadTolerance::directionVector, DS.ARGS())
        .def("setDirectionVector", &PyAcadTolerance::setDirectionVector, DS.ARGS({ "val: PyGe.Vector3d" }))
        .def("insertionPoint", &PyAcadTolerance::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadTolerance::setInsertionPoint, DS.ARGS({ "val: PyGe.Point3d" }))
        .def("normal", &PyAcadTolerance::normal, DS.ARGS())
        .def("setNormal", &PyAcadTolerance::setNormal, DS.ARGS({ "val: PyGe.Vector3d" }))
        .def("styleName", &PyAcadTolerance::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadTolerance::setStyleName, DS.ARGS({ "val:str" }))
        .def("textColor", &PyAcadTolerance::textColor, DS.ARGS())
        .def("setTextColor", &PyAcadTolerance::setTextColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("textString", &PyAcadTolerance::textString, DS.ARGS())
        .def("setTextString", &PyAcadTolerance::setTextString, DS.ARGS({ "val:str" }))
        .def("textStyle", &PyAcadTolerance::textStyle, DS.ARGS())
        .def("setTextStyle", &PyAcadTolerance::setTextStyle, DS.ARGS({ "val:str" }))
        .def("textHeight", &PyAcadTolerance::textHeight, DS.ARGS())
        .def("setTextHeight", &PyAcadTolerance::setTextHeight, DS.ARGS({ "val:float" }))
        .def("scaleFactor", &PyAcadTolerance::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadTolerance::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("dimensionLineColor", &PyAcadTolerance::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadTolerance::setDimensionLineColor, DS.ARGS({ "val:float" }))
        .def("cast", &PyAcadTolerance::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTolerance::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTolerance::PyAcadTolerance(std::shared_ptr<PyIAcadToleranceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGeVector3d PyAcadTolerance::directionVector() const
{
    return impObj()->GetDirectionVector();
}

void PyAcadTolerance::setDirectionVector(const AcGeVector3d& val)
{
    impObj()->SetDirectionVector(val);
}

AcGePoint3d PyAcadTolerance::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadTolerance::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

AcGeVector3d PyAcadTolerance::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadTolerance::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

std::string PyAcadTolerance::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadTolerance::setStyleName(const std::string& val)
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadTolerance::textColor() const
{
    return impObj()->GetTextColor();
}

void PyAcadTolerance::setTextColor(PyAcColor val)
{
    impObj()->SetTextColor(val);
}

std::string PyAcadTolerance::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadTolerance::setTextString(const std::string& val)
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

std::string PyAcadTolerance::textStyle() const
{
    return wstr_to_utf8(impObj()->GetTextStyle());
}

void PyAcadTolerance::setTextStyle(const std::string& val)
{
    impObj()->SetTextStyle(utf8_to_wstr(val).c_str());
}

double PyAcadTolerance::textHeight() const
{
    return impObj()->GetTextHeight();
}

void PyAcadTolerance::setTextHeight(double val)
{
    impObj()->SetTextHeight(val);
}

double PyAcadTolerance::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadTolerance::setScaleFactor(double val)
{
    impObj()->SetScaleFactor(val);
}

PyAcColor PyAcadTolerance::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadTolerance::setDimensionLineColor(PyAcColor val)
{
    impObj()->SetDimensionLineColor(val);
}

PyAcadTolerance PyAcadTolerance::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTolerance>(src);
}

std::string PyAcadTolerance::className()
{
    return "AcadTolerance";
}

PyIAcadToleranceImpl* PyAcadTolerance::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadToleranceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadTrace
void makePyAcadTraceWrapper()
{
    PyDocString DS("AcadTrace");
    class_<PyAcadTrace, bases<PyAcadEntity>>("AcadTrace", boost::python::no_init)
        .def("cast", &PyAcadTrace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTrace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTrace::PyAcadTrace(std::shared_ptr<PyIAcadTraceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadTrace PyAcadTrace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTrace>(src);
}

std::string PyAcadTrace::className()
{
    return "AcadTrace";
}

PyIAcadTraceImpl* PyAcadTrace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTraceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadXline
void makePyAcadXlineWrapper()
{
    PyDocString DS("AcadXline");
    class_<PyAcadXline, bases<PyAcadEntity>>("AcadXline", boost::python::no_init)
        .def("cast", &PyAcadXline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadXline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadXline::PyAcadXline(std::shared_ptr<PyIAcadXlineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadXline PyAcadXline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadXline>(src);
}

std::string PyAcadXline::className()
{
    return "AcadXline";
}

PyIAcadXlineImpl* PyAcadXline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadXlineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadBlockReference
void makePyAcadBlockReferenceWrapper()
{
    PyDocString DS("AcadBlockReference");
    class_<PyAcadBlockReference, bases<PyAcadEntity>>("AcadBlockReference", boost::python::no_init)
        .def("insertionPoint", &PyAcadBlockReference::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadBlockReference::setInsertionPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("name", &PyAcadBlockReference::name, DS.ARGS())
        .def("setName", &PyAcadBlockReference::setName, DS.ARGS({ "val:str" }))
        .def("normal", &PyAcadBlockReference::normal, DS.ARGS())
        .def("setNormal", &PyAcadBlockReference::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("rotation", &PyAcadBlockReference::rotation, DS.ARGS())
        .def("setRotation", &PyAcadBlockReference::setRotation, DS.ARGS({ "val:float" }))
        .def("xScaleFactor", &PyAcadBlockReference::xScaleFactor, DS.ARGS())
        .def("setXScaleFactor", &PyAcadBlockReference::setXScaleFactor, DS.ARGS({ "val:float" }))
        .def("yScaleFactor", &PyAcadBlockReference::yScaleFactor, DS.ARGS())
        .def("setYScaleFactor", &PyAcadBlockReference::setYScaleFactor, DS.ARGS({ "val:float" }))
        .def("zScaleFactor", &PyAcadBlockReference::zScaleFactor, DS.ARGS())
        .def("setZScaleFactor", &PyAcadBlockReference::setZScaleFactor, DS.ARGS({ "val:float" }))
        .def("explode", &PyAcadBlockReference::explode, DS.ARGS())
        .def("attributes", &PyAcadBlockReference::attributes, DS.ARGS())
        .def("constantAttributes", &PyAcadBlockReference::constantAttributes, DS.ARGS())
        .def("dynamicBlockProperties", &PyAcadBlockReference::dynamicBlockProperties, DS.ARGS())
        .def("hasAttributes", &PyAcadBlockReference::hasAttributes, DS.ARGS())
        .def("effectiveName", &PyAcadBlockReference::effectiveName, DS.ARGS())
        .def("isDynamicBlock", &PyAcadBlockReference::isDynamicBlock, DS.ARGS())
        .def("resetBlock", &PyAcadBlockReference::resetBlock, DS.ARGS())
        .def("convertToAnonymousBlock", &PyAcadBlockReference::convertToAnonymousBlock, DS.ARGS())
        .def("convertToStaticBlock", &PyAcadBlockReference::convertToStaticBlock, DS.ARGS({ "newBlockName:str" }))
        .def("xEffectiveScaleFactor", &PyAcadBlockReference::xEffectiveScaleFactor, DS.ARGS())
        .def("setXEffectiveScaleFactor", &PyAcadBlockReference::setXEffectiveScaleFactor, DS.ARGS({ "val:float" }))
        .def("yEffectiveScaleFactor", &PyAcadBlockReference::yEffectiveScaleFactor, DS.ARGS())
        .def("setYEffectiveScaleFactor", &PyAcadBlockReference::setYEffectiveScaleFactor, DS.ARGS({ "val:float" }))
        .def("zEffectiveScaleFactor", &PyAcadBlockReference::zEffectiveScaleFactor, DS.ARGS())
        .def("setZEffectiveScaleFactor", &PyAcadBlockReference::setZEffectiveScaleFactor, DS.ARGS({ "val:float" }))
        .def("insUnits", &PyAcadBlockReference::insUnits, DS.ARGS())
        .def("insUnitsFactor", &PyAcadBlockReference::insUnitsFactor, DS.ARGS())
        .def("cast", &PyAcadBlockReference::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlockReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlockReference::PyAcadBlockReference(std::shared_ptr<PyIAcadBlockReferenceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGePoint3d PyAcadBlockReference::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadBlockReference::setInsertionPoint(const AcGePoint3d& val)
{
    impObj()->SetInsertionPoint(val);
}

std::string PyAcadBlockReference::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadBlockReference::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

AcGeVector3d PyAcadBlockReference::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadBlockReference::setNormal(const AcGeVector3d& val)
{
    impObj()->SetNormal(val);
}

double PyAcadBlockReference::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadBlockReference::setRotation(double val)
{
    impObj()->SetRotation(val);
}

double PyAcadBlockReference::xScaleFactor() const
{
    return impObj()->GetXScaleFactor();
}

void PyAcadBlockReference::setXScaleFactor(double val)
{
    impObj()->SetXScaleFactor(val);
}

double PyAcadBlockReference::yScaleFactor() const
{
    return impObj()->GetYScaleFactor();
}

void PyAcadBlockReference::setYScaleFactor(double val)
{
    impObj()->SetYScaleFactor(val);
}

double PyAcadBlockReference::zScaleFactor() const
{
    return impObj()->GetZScaleFactor();
}

void PyAcadBlockReference::setZScaleFactor(double val)
{
    impObj()->SetZScaleFactor(val);
}

boost::python::list PyAcadBlockReference::explode() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->Explode())
        pylist.append(PyAcadEntity{ item });
    return pylist;
}

boost::python::list PyAcadBlockReference::attributes() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetAttributes())
        pylist.append(PyAcadAttributeReference{ item });
    return pylist;
}

boost::python::list PyAcadBlockReference::constantAttributes() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetConstantAttributes())
        pylist.append(PyAcadAttributeReference{ item });
    return pylist;
}

boost::python::list PyAcadBlockReference::dynamicBlockProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetDynamicBlockProperties())
        pylist.append(PyAcadDynamicBlockReferenceProperty{ item });
    return pylist;
}

bool PyAcadBlockReference::hasAttributes() const
{
    return impObj()->GetHasAttributes();
}

std::string PyAcadBlockReference::effectiveName() const
{
    return wstr_to_utf8(impObj()->GetEffectiveName());
}

bool PyAcadBlockReference::isDynamicBlock() const
{
    return impObj()->GetIsDynamicBlock();
}

void PyAcadBlockReference::resetBlock() const
{
    impObj()->ResetBlock();
}

void PyAcadBlockReference::convertToAnonymousBlock() const
{
    impObj()->ConvertToAnonymousBlock();
}

void PyAcadBlockReference::convertToStaticBlock(const std::string& newBlockName) const
{
    impObj()->ConvertToStaticBlock(utf8_to_wstr(newBlockName).c_str());
}

double PyAcadBlockReference::xEffectiveScaleFactor() const
{
    return impObj()->GetXEffectiveScaleFactor();
}

void PyAcadBlockReference::setXEffectiveScaleFactor(double val)
{
    impObj()->SetXEffectiveScaleFactor(val);
}

double PyAcadBlockReference::yEffectiveScaleFactor() const
{
    return impObj()->GetYEffectiveScaleFactor();
}

void PyAcadBlockReference::setYEffectiveScaleFactor(double val)
{
    impObj()->SetYEffectiveScaleFactor(val);
}

double PyAcadBlockReference::zEffectiveScaleFactor() const
{
    return impObj()->GetZEffectiveScaleFactor();
}

void PyAcadBlockReference::setZEffectiveScaleFactor(double val)
{
    impObj()->SetZEffectiveScaleFactor(val);
}

std::string PyAcadBlockReference::insUnits() const
{
    return wstr_to_utf8(impObj()->GetInsUnits());
}

double PyAcadBlockReference::insUnitsFactor() const
{
    return impObj()->GetInsUnitsFactor();
}

PyAcadBlockReference PyAcadBlockReference::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadBlockReference>(src);
}

std::string PyAcadBlockReference::className()
{
    return "AcadBlockReference";
}

PyIAcadBlockReferenceImpl* PyAcadBlockReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadBlockReferenceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadHatch
void makePyAcadHatchWrapper()
{
    PyDocString DS("AcadHatch");
    class_<PyAcadHatch, bases<PyAcadEntity>>("AcadHatch", boost::python::no_init)
        .def("cast", &PyAcadHatch::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadHatch::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadHatch::PyAcadHatch(std::shared_ptr<PyIAcadHatchImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadHatch PyAcadHatch::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadHatch>(src);
}

std::string PyAcadHatch::className()
{
    return "AcadHatch";
}

PyIAcadHatchImpl* PyAcadHatch::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadHatchImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadRasterImage
void makePyAcadRasterImageWrapper()
{
    PyDocString DS("AcadRasterImage");
    class_<PyAcadRasterImage, bases<PyAcadEntity>>("AcadRasterImage", boost::python::no_init)
        .def("cast", &PyAcadRasterImage::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRasterImage::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRasterImage::PyAcadRasterImage(std::shared_ptr<PyIAcadRasterImageImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadRasterImage PyAcadRasterImage::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadRasterImage>(src);
}

std::string PyAcadRasterImage::className()
{
    return "AcadRasterImage";
}

PyIAcadRasterImageImpl* PyAcadRasterImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadRasterImageImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLine
void makePyAcadLineWrapper()
{
    PyDocString DS("AcadLine");
    class_<PyAcadLine, bases<PyAcadEntity>>("AcadLine", boost::python::no_init)
        .def("cast", &PyAcadLine::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLine::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLine::PyAcadLine(std::shared_ptr<PyIAcadLineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadLine PyAcadLine::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLine>(src);
}

std::string PyAcadLine::className()
{
    return "AcadLine";
}

PyIAcadLineImpl* PyAcadLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMInsertBlock
void makePyAcadMInsertBlockWrapper()
{
    PyDocString DS("AcadMInsertBlock");
    class_<PyAcadMInsertBlock, bases<PyAcadBlockReference>>("AcadMInsertBlock", boost::python::no_init)
        .def("setColumns", &PyAcadMInsertBlock::setColumns, DS.ARGS({ "val:int" }))
        .def("columns", &PyAcadMInsertBlock::columns, DS.ARGS())
        .def("setRows", &PyAcadMInsertBlock::setRows, DS.ARGS({ "val:int" }))
        .def("rows", &PyAcadMInsertBlock::rows, DS.ARGS())
        .def("setColumnSpacing", &PyAcadMInsertBlock::setColumnSpacing, DS.ARGS({ "val:float" }))
        .def("columnSpacing", &PyAcadMInsertBlock::columnSpacing, DS.ARGS())
        .def("setRowSpacing", &PyAcadMInsertBlock::setRowSpacing, DS.ARGS({ "val:float" }))
        .def("rowSpacing", &PyAcadMInsertBlock::rowSpacing, DS.ARGS())
        .def("cast", &PyAcadMInsertBlock::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMInsertBlock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMInsertBlock::PyAcadMInsertBlock(std::shared_ptr<PyIAcadMInsertBlockImpl> ptr)
    : PyAcadBlockReference(ptr)
{
}

void PyAcadMInsertBlock::setColumns(long val)
{
    impObj()->SetColumns(val);
}

long PyAcadMInsertBlock::columns() const
{
    return impObj()->GetColumns();
}

void PyAcadMInsertBlock::setRows(long val)
{
    impObj()->SetRows(val);
}

long PyAcadMInsertBlock::rows() const
{
    return impObj()->GetRows();
}

void PyAcadMInsertBlock::setColumnSpacing(double val)
{
    impObj()->SetColumnSpacing(val);
}

double PyAcadMInsertBlock::columnSpacing() const
{
    return impObj()->GetColumnSpacing();
}

void PyAcadMInsertBlock::setRowSpacing(double val)
{
    impObj()->SetRowSpacing(val);
}

double PyAcadMInsertBlock::rowSpacing() const
{
    return impObj()->GetRowSpacing();
}

PyAcadMInsertBlock PyAcadMInsertBlock::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMInsertBlock>(src);
}

std::string PyAcadMInsertBlock::className()
{
    return "AcadMInsertBlock";
}

PyIAcadMInsertBlockImpl* PyAcadMInsertBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMInsertBlockImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadExternalReference
void makePyAcadExternalReferenceWrapper()
{
    PyDocString DS("AcadExternalReference");
    class_<PyAcadExternalReference, bases<PyAcadBlockReference>>("AcadExternalReference", boost::python::no_init)
        .def("path", &PyAcadExternalReference::path, DS.ARGS())
        .def("setPath", &PyAcadExternalReference::setPath, DS.ARGS({ "val:str" }))
        .def("layerPropertyOverrides", &PyAcadExternalReference::layerPropertyOverrides, DS.ARGS({ "val:str" }))
        .def("cast", &PyAcadExternalReference::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadExternalReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadExternalReference::PyAcadExternalReference(std::shared_ptr<PyIAcadExternalReferenceImpl> ptr)
    : PyAcadBlockReference(ptr)
{
}

std::string PyAcadExternalReference::path() const
{
    return wstr_to_utf8(impObj()->GetPath());
}

void PyAcadExternalReference::setPath(const std::string& val)
{
    impObj()->SetPath(utf8_to_wstr(val).c_str());
}

bool PyAcadExternalReference::layerPropertyOverrides() const
{
    return impObj()->GetLayerPropertyOverrides();
}

PyAcadExternalReference PyAcadExternalReference::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadExternalReference>(src);
}

std::string PyAcadExternalReference::className()
{
    return "AcadExternalReference";
}

PyIAcadExternalReferenceImpl* PyAcadExternalReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadExternalReferenceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPolyfaceMesh
void makePyAcadPolyfaceMeshWrapper()
{
    PyDocString DS("AcadPolyfaceMesh");
    class_<PyAcadPolyfaceMesh, bases<PyAcadEntity>>("AcadPolyfaceMesh", boost::python::no_init)
        .def("cast", &PyAcadPolyfaceMesh::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolyfaceMesh::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolyfaceMesh::PyAcadPolyfaceMesh(std::shared_ptr<PyIAcadPolyfaceMeshImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadPolyfaceMesh PyAcadPolyfaceMesh::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPolyfaceMesh>(src);
}

std::string PyAcadPolyfaceMesh::className()
{
    return "AcadPolyfaceMesh";
}

PyIAcadPolyfaceMeshImpl* PyAcadPolyfaceMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPolyfaceMeshImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMLine
void makePyAcadMLineWrapper()
{
    PyDocString DS("AcadMLine");
    class_<PyAcadMLine, bases<PyAcadEntity>>("AcadMLine", boost::python::no_init)
        .def("cast", &PyAcadMLine::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMLine::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMLine::PyAcadMLine(std::shared_ptr<PyIAcadMLineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadMLine PyAcadMLine::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMLine>(src);
}

std::string PyAcadMLine::className()
{
    return "AcadMLine";
}

PyIAcadMLineImpl* PyAcadMLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMLineImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSection
void makePyAcadSectionWrapper()
{
    PyDocString DS("AcadSection");
    class_<PyAcadSection, bases<PyAcadEntity>>("AcadSection", boost::python::no_init)
        .def("cast", &PyAcadSection::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSection::PyAcadSection(std::shared_ptr<PyIAcadSectionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadSection PyAcadSection::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSection>(src);
}

std::string PyAcadSection::className()
{
    return "AcadSection";
}

PyIAcadSectionImpl* PyAcadSection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSectionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMLeader
void makePyAcadMLeaderWrapper()
{
    PyDocString DS("AcadMLeader");
    class_<PyAcadMLeader, bases<PyAcadEntity>>("AcadMLeader", boost::python::no_init)
        .def("cast", &PyAcadMLeader::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMLeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMLeader::PyAcadMLeader(std::shared_ptr<PyIAcadMLeaderImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadMLeader PyAcadMLeader::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMLeader>(src);
}

std::string PyAcadMLeader::className()
{
    return "AcadMLeader";
}

PyIAcadMLeaderImpl* PyAcadMLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMLeaderImpl*>(m_pyImp.get());
}