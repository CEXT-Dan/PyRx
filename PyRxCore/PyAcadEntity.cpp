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
        .def("cast", &PyAcadPViewport::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPViewport::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPViewport::PyAcadPViewport(std::shared_ptr<PyIAcadPViewportImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadPolygonMesh::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolygonMesh::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolygonMesh::PyAcadPolygonMesh(std::shared_ptr<PyIAcadPolygonMeshImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcad3DPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DPolyline::PyAcad3DPolyline(std::shared_ptr<PyIAcad3DPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadArc::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadArc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadArc::PyAcadArc(std::shared_ptr<PyIAcadArcImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadAttribute::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadAttribute::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadAttribute::PyAcadAttribute(std::shared_ptr<PyIAcadAttributeImpl> ptr)
    : PyAcadEntity(ptr)
{
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
//PyAcadRegion
void makePyAcadRegionWrapper()
{
    PyDocString DS("AcadRegion");
    class_<PyAcadRegion, bases<PyAcadEntity>>("AcadRegion", boost::python::no_init)
        .def("cast", &PyAcadRegion::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRegion::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRegion::PyAcadRegion(std::shared_ptr<PyIAcadRegionImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcad3DSolid::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DSolid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DSolid::PyAcad3DSolid(std::shared_ptr<PyIAcad3DSolidImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadCircle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadCircle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadCircle::PyAcadCircle(std::shared_ptr<PyIAcadCircleImpl> ptr)
    : PyAcadEntity(ptr)
{
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
//PyAcadDimension
void makePyAcadDimensionWrapper()
{
    PyDocString DS("AcadDimension");
    class_<PyAcadDimension, bases<PyAcadEntity>>("AcadDimension", boost::python::no_init)
        .def("cast", &PyAcadDimension::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimension::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimension::PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadDimension PyAcadDimension::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimension>(src);
}

std::string PyAcadDimension::className()
{
    return "AcadDimension";
}

PyIAcadDimensionImpl* PyAcadDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimensionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper()
{
    PyDocString DS("AcadDimAligned");
    class_<PyAcadDimAligned, bases<PyAcadDimension>>("AcadDimAligned", boost::python::no_init)
        .def("cast", &PyAcadDimAligned::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAligned::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAligned::PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAligned PyAcadDimAligned::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAligned>(src);
}

std::string PyAcadDimAligned::className()
{
    return "AcadDimAligned";
}

PyIAcadDimAlignedImpl* PyAcadDimAligned::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAlignedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper()
{
    PyDocString DS("AcadDimAngular");
    class_<PyAcadDimAngular, bases<PyAcadDimension>>("AcadDimAngular", boost::python::no_init)
        .def("cast", &PyAcadDimAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAngular::PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAngular PyAcadDimAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAngular>(src);
}

std::string PyAcadDimAngular::className()
{
    return "AcadDimAngular";
}

PyIAcadDimAngularImpl* PyAcadDimAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper()
{
    PyDocString DS("AcadDimDiametric");
    class_<PyAcadDimDiametric, bases<PyAcadDimension>>("AcadDimDiametric", boost::python::no_init)
        .def("cast", &PyAcadDimDiametric::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimDiametric::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimDiametric::PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimDiametric PyAcadDimDiametric::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimDiametric>(src);
}

std::string PyAcadDimDiametric::className()
{
    return "AcadDimDiametric";
}

PyIAcadDimDiametricImpl* PyAcadDimDiametric::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimDiametricImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper()
{
    PyDocString DS("AcadDimRotated");
    class_<PyAcadDimRotated, bases<PyAcadDimension>>("AcadDimRotated", boost::python::no_init)
        .def("cast", &PyAcadDimRotated::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRotated::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRotated::PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRotated PyAcadDimRotated::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRotated>(src);
}

std::string PyAcadDimRotated::className()
{
    return "AcadDimRotated";
}

PyIAcadDimRotatedImpl* PyAcadDimRotated::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRotatedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper()
{
    PyDocString DS("AcadDimOrdinate");
    class_<PyAcadDimOrdinate, bases<PyAcadDimension>>("AcadDimOrdinate", boost::python::no_init)
        .def("cast", &PyAcadDimOrdinate::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimOrdinate::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimOrdinate::PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimOrdinate PyAcadDimOrdinate::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimOrdinate>(src);
}

std::string PyAcadDimOrdinate::className()
{
    return "AcadDimOrdinate";
}

PyIAcadDimOrdinateImpl* PyAcadDimOrdinate::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimOrdinateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper()
{
    PyDocString DS("AcadDimRadial");
    class_<PyAcadDimRadial, bases<PyAcadDimension>>("AcadDimRadial", boost::python::no_init)
        .def("cast", &PyAcadDimRadial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadial::PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadial PyAcadDimRadial::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadial>(src);
}

std::string PyAcadDimRadial::className()
{
    return "AcadDimRadial";
}

PyIAcadDimRadialImpl* PyAcadDimRadial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper()
{
    PyDocString DS("AcadDim3PointAngular");
    class_<PyAcadDim3PointAngular, bases<PyAcadDimension>>("AcadDim3PointAngular", boost::python::no_init)
        .def("cast", &PyAcadDim3PointAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDim3PointAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDim3PointAngular::PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDim3PointAngular PyAcadDim3PointAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDim3PointAngular>(src);
}

std::string PyAcadDim3PointAngular::className()
{
    return "AcadDim3PointAngular";
}

PyIAcadDim3PointAngularImpl* PyAcadDim3PointAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDim3PointAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper()
{
    PyDocString DS("AcadDimArcLength");
    class_<PyAcadDimArcLength, bases<PyAcadDimension>>("AcadDimArcLength", boost::python::no_init)
        .def("cast", &PyAcadDimArcLength::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimArcLength::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimArcLength::PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimArcLength PyAcadDimArcLength::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimArcLength>(src);
}

std::string PyAcadDimArcLength::className()
{
    return "AcadDimArcLength";
}

PyIAcadDimArcLengthImpl* PyAcadDimArcLength::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimArcLengthImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper()
{
    PyDocString DS("AcadDimRadialLarge");
    class_<PyAcadDimRadialLarge, bases<PyAcadDimension>>("AcadDimRadialLarge", boost::python::no_init)
        .def("cast", &PyAcadDimRadialLarge::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadialLarge::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadialLarge::PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadialLarge PyAcadDimRadialLarge::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadialLarge>(src);
}

std::string PyAcadDimRadialLarge::className()
{
    return "AcadDimRadialLarge";
}

PyIAcadDimRadialLargeImpl* PyAcadDimRadialLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialLargeImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadEllipse
void makePyAcadEllipseWrapper()
{
    PyDocString DS("AcadEllipse");
    class_<PyAcadEllipse, bases<PyAcadEntity>>("AcadEllipse", boost::python::no_init)
        .def("cast", &PyAcadEllipse::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadEllipse::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadEllipse::PyAcadEllipse(std::shared_ptr<PyIAcadEllipseImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadLeader::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLeader::PyAcadLeader(std::shared_ptr<PyIAcadLeaderImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadMText::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMText::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMText::PyAcadMText(std::shared_ptr<PyIAcadMTextImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadPoint::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPoint::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPoint::PyAcadPoint(std::shared_ptr<PyIAcadPointImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadLWPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLWPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLWPolyline::PyAcadLWPolyline(std::shared_ptr<PyIAcadLWPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolyline::PyAcadPolyline(std::shared_ptr<PyIAcadPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadRay::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRay::PyAcadRay(std::shared_ptr<PyIAcadRayImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadShape::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadShape::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadShape::PyAcadShape(std::shared_ptr<PyIAcadShapeImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadSolid::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSolid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSolid::PyAcadSolid(std::shared_ptr<PyIAcadSolidImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadSpline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSpline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSpline::PyAcadSpline(std::shared_ptr<PyIAcadSplineImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadText::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadText::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadText::PyAcadText(std::shared_ptr<PyIAcadTextImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadTolerance::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTolerance::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTolerance::PyAcadTolerance(std::shared_ptr<PyIAcadToleranceImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadBlockReference::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlockReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlockReference::PyAcadBlockReference(std::shared_ptr<PyIAcadBlockReferenceImpl> ptr)
    : PyAcadEntity(ptr)
{
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
        .def("cast", &PyAcadMInsertBlock::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMInsertBlock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMInsertBlock::PyAcadMInsertBlock(std::shared_ptr<PyIAcadMInsertBlockImpl> ptr)
    : PyAcadBlockReference(ptr)
{
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
        .def("cast", &PyAcadExternalReference::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadExternalReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadExternalReference::PyAcadExternalReference(std::shared_ptr<PyIAcadExternalReferenceImpl> ptr)
    : PyAcadBlockReference(ptr)
{
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
//PyAcadTable
void makePyAcadTableWrapper()
{
    PyDocString DS("AcadTable");
    class_<PyAcadTable, bases<PyAcadEntity>>("AcadTable", boost::python::no_init)
        .def("cast", &PyAcadTable::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTable::PyAcadTable(std::shared_ptr<PyIAcadTableImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadTable PyAcadTable::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTable>(src);
}

std::string PyAcadTable::className()
{
    return "AcadTable";
}

PyIAcadTableImpl* PyAcadTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTableImpl*>(m_pyImp.get());
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