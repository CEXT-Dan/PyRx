#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntityImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper()
{
    PyDocString DS("AcadBlock");
    class_<PyAcadBlock, bases<PyAcadObject>>("AcadBlock", boost::python::no_init)
        .def("count", &PyAcadBlock::count, DS.ARGS())
        .def("item", &PyAcadBlock::item, DS.SARGS({ "index: int" }))
        .def("entities", &PyAcadBlock::entities, DS.ARGS())
        .def("name", &PyAcadBlock::name, DS.ARGS())
        .def("setName", &PyAcadBlock::setName, DS.ARGS({ "name:str" }))
        .def("origin", &PyAcadBlock::origin, DS.ARGS())
        .def("setOrigin", &PyAcadBlock::setOrigin, DS.ARGS({ "origin:PyGe.Point3d" }))
        .def("unload", &PyAcadBlock::unload, DS.ARGS())
        .def("reload", &PyAcadBlock::reload, DS.ARGS())
        .def("bind", &PyAcadBlock::bind, DS.ARGS({ "bPrefixName:bool" }))
        .def("detach", &PyAcadBlock::detach, DS.ARGS())
        .def("xrefDatabase", &PyAcadBlock::xrefDatabase, DS.ARGS())
        .def("path", &PyAcadBlock::path, DS.ARGS())
        .def("setPath", &PyAcadBlock::setPath, DS.ARGS({ "path:str" }))
        .def("comments", &PyAcadBlock::comments, DS.ARGS())
        .def("setComments", &PyAcadBlock::setComments, DS.ARGS({ "comments:str" }))
        .def("units", &PyAcadBlock::units, DS.ARGS())
        .def("setUnits", &PyAcadBlock::setUnits, DS.ARGS({ "units:PyAx.AcInsertUnits" }))
        .def("isExplodable", &PyAcadBlock::isExplodable, DS.ARGS())
        .def("setExplodable", &PyAcadBlock::setExplodable, DS.ARGS({ "explodable:bool" }))
        .def("blockScaling", &PyAcadBlock::blockScaling, DS.ARGS())
        .def("setBlockScaling", &PyAcadBlock::setBlockScaling, DS.ARGS({ "blockScaling:PyAx.AcBlockScaling" }))
        .def("isDynamicBlock", &PyAcadBlock::isDynamicBlock, DS.ARGS())
        .def("isLayout", &PyAcadBlock::isLayout, DS.ARGS())
        //.def("layout", &PyAcadBlock::layout, DS.ARGS())
        .def("isXRef", &PyAcadBlock::isXRef, DS.ARGS())
        .def("addCustomObject", &PyAcadBlock::addCustomObject, DS.ARGS({ "name:str" }))
        .def("add3DFace", &PyAcadBlock::add3DFace, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("add3DMesh", &PyAcadBlock::add3DMesh, DS.ARGS({ "M:int","N:int","points:list[PyGe.Point3d]" }))
        .def("add3DPoly", &PyAcadBlock::add3DPoly, DS.ARGS({ "points:list[PyGe.Point3d]" }))
        .def("addArc", &PyAcadBlock::addArc, DS.ARGS({ "canter:PyGe.Point3d","radius:float","startAngle:float","endAngle:float" }))
        .def("addAttribute", &PyAcadBlock::addAttribute, DS.ARGS({ "height:float","mode:PyAx.AcAttributeMode","prompt:str","insertionPoint:PyGe.Point3d","tag:str", "value:str" }))
        .def("addBox", &PyAcadBlock::addBox, DS.ARGS({ "origin:PyGe.Point3d","length:float","width:float","height:float" }))
        .def("addCircle", &PyAcadBlock::addCircle, DS.ARGS({ "canter:PyGe.Point3d","radius:float" }))
        .def("addCone", &PyAcadBlock::addCone, DS.ARGS({ "canter:PyGe.Point3d","baseRadius:float","height:float" }))
        .def("addCylinder", &PyAcadBlock::addCylinder, DS.ARGS({ "canter:PyGe.Point3d","radius:float","height:float" }))
        .def("addDimAligned", &PyAcadBlock::addDimAligned, DS.ARGS({ "extLine1Point:PyGe.Point3d","extLine2Point:PyGe.Point3d","textPosition:PyGe.Point3d" }))
        .def("addDimAngular", &PyAcadBlock::addDimAngular, DS.ARGS({ "angleVertex:PyGe.Point3d","firstEndPoint:PyGe.Point3d","secondEndPoint:PyGe.Point3d","textPosition:PyGe.Point3d" }))
        .def("addDimDiametric", &PyAcadBlock::addDimDiametric, DS.ARGS({ "chordPoint:PyGe.Point3d","farChordPoint:PyGe.Point3d","leaderLength:float" }))
        .def("addDimRotated", &PyAcadBlock::addDimRotated, DS.ARGS({ "extLine1Point:PyGe.Point3d","extLine2Point:PyGe.Point3d","dimLineLocation:PyGe.Point3d","rotationAngle:float" }))
        .def("addDimOrdinate", &PyAcadBlock::addDimOrdinate, DS.ARGS({ "definitionPoint:PyGe.Point3d","leaderEndPoint:PyGe.Point3d","UseXAxis:int" }))
        .def("addDimRadial", &PyAcadBlock::addDimRadial, DS.ARGS({ "center:PyGe.Point3d","chordPoint:PyGe.Point3d","leaderLength:float" }))
        .def("addDimRadialLarge", &PyAcadBlock::addDimRadialLarge, DS.ARGS({ "center:PyGe.Point3d","chordPoint:PyGe.Point3d","overrideCenter:PyGe.Point3d","jogPoint:PyGe.Point3d","jogAngle:float" }))
        .def("addDim3PointAngular", &PyAcadBlock::addDim3PointAngular, DS.ARGS({ "angleVertex:PyGe.Point3d","firstEndPoint:PyGe.Point3d","secondEndPoint:PyGe.Point3d","textPosition:PyGe.Point3d" }))
        .def("addDimArc", &PyAcadBlock::addDimArc, DS.ARGS({ "arcCenter:PyGe.Point3d","firstEndPoint:PyGe.Point3d","secondEndPoint:PyGe.Point3d","arcPoint:PyGe.Point3d" }))
        .def("addEllipse", &PyAcadBlock::addEllipse, DS.ARGS({ "center:PyGe.Point3d","majorAxis:PyGe.Vector3d","radiusRatio:float" }))
        .def("addEllipticalCone", &PyAcadBlock::addEllipticalCone, DS.ARGS({ "center:PyGe.Point3d","majorRadius:float","minorRadius:float","height:float" }))
        .def("addEllipticalCylinder", &PyAcadBlock::addEllipticalCylinder, DS.ARGS({ "center:PyGe.Point3d","majorRadius:float","minorRadius:float","height:float" }))
        .def("addExtrudedSolid", &PyAcadBlock::addExtrudedSolid, DS.ARGS({ "region:PyAx.AcadRegion","height:float","taperAngle:float" }))
        .def("addExtrudedSolidAlongPath", &PyAcadBlock::addExtrudedSolidAlongPath, DS.ARGS({ "region:PyAx.AcadRegion","path:PyAx.AcadEntity" }))
        .def("addLeader", &PyAcadBlock::addLeader, DS.ARGS({ "points:list[PyGe.Point3d]","annotation:PyAx.AcadEntity","leaderType:PyAx.AcLeaderType" }))
        .def("addMText", &PyAcadBlock::addMText, DS.ARGS({ "insertionPoint:PyGe.Point3d","width:float","textVal:str" }))
        .def("addPoint", &PyAcadBlock::addPoint, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("addLightWeightPolyline", &PyAcadBlock::addLightWeightPolyline, DS.ARGS({ "points:list[PyGe.Point2d]" }))
        .def("addPolyline", &PyAcadBlock::addPolyline, DS.ARGS({ "points:list[PyGe.Point3d]" }))
        .def("addRay", &PyAcadBlock::addRay, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d" }))
        .def("addRegion", &PyAcadBlock::addRegion, DS.ARGS({ "curves:PyAx.AcadEntity" }))
        .def("addRevolvedSolid", &PyAcadBlock::addRevolvedSolid, DS.ARGS({ "region:PyAx.AcadRegion","axisPoint:PyGe.Point3d","axisDir:PyGe.Vector3d","angle:float" }))
        .def("addShape", &PyAcadBlock::addShape, DS.ARGS({ "name:str","insertionPoint:PyGe.Point3d", "scaleFactor:float","rotationAngle:float" }))
        .def("addSolid", &PyAcadBlock::addSolid, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("addSphere", &PyAcadBlock::addSphere, DS.ARGS({ "center:PyGe.Point3d","radius:float" }))
        .def("addSpline", &PyAcadBlock::addSpline, DS.ARGS({ "points:list[PyGe.Point3d]", "startTangent:PyGe.Vector3d","endTangent:PyGe.Vector3d" }))
        .def("addText", &PyAcadBlock::addText, DS.ARGS({ "textValue:str","insertionPoint:PyGe.Point3d", "height:float" }))
        .def("addTolerance", &PyAcadBlock::addTolerance, DS.ARGS({ "textValue:str","insertionPoint:PyGe.Point3d", "direction:PyGe.Vector3d" }))
        .def("addTorus", &PyAcadBlock::addTorus, DS.ARGS({ "center:PyGe.Point3d","torusRadius:float","tubeRadius:float" }))
        .def("addWedge", &PyAcadBlock::addWedge, DS.ARGS({ "center:PyGe.Point3d","length:float","width:float","height:float" }))
        .def("addXline", &PyAcadBlock::addXline, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d" }))
        .def("insertBlock", &PyAcadBlock::insertBlock, DS.ARGS({ "insertionPoint:PyGe.Point3d","name:str","scale:PyGe.Scale3d","rotation:float" }))
        .def("addHatch", &PyAcadBlock::addHatch, DS.ARGS({ "patternType:int","patternName:str","associativity:bool" }))
        .def("addRaster", &PyAcadBlock::addRaster, DS.ARGS({ "imageFileName:str","insertionPoint:PyGe.Point3d","scaleFactor:float","rotationAngle:float" }))
        .def("addLine", &PyAcadBlock::addLine, DS.ARGS({ "startPoint:PyGe.Point3d","endPoint:PyGe.Point3d" }))
        .def("addMInsertBlock", &PyAcadBlock::addMInsertBlock, DS.ARGS({ "point:PyGe.Point3d","name:str","rotation:float","numRows:int","numCols:int" ,"rowSpacing:int" ,"rolumnSpacing:int" }))
        .def("addPolyfaceMesh", &PyAcadBlock::addPolyfaceMesh, DS.ARGS({ "points:list[PyGe.Point3d]", "faces:list[int]" }))
        .def("addMLine", &PyAcadBlock::addMLine, DS.ARGS({ "points:list[PyGe.Point3d]" }))
        .def("attachExternalReference", &PyAcadBlock::attachExternalReference, DS.ARGS({ "path:str","name:str","insertionPoint:PyGe.Point3d","scale:PyGe.Scale3d","rotation:float","bOverlay:bool" }))
        .def("addTable", &PyAcadBlock::addTable, DS.ARGS({ "insertionPoint:PyGe.Point3d","numRows:int","numColumns:int","rowHeight:float","colWidth:float" }))
        .def("addSection", &PyAcadBlock::addSection, DS.ARGS({ "fromPoint:PyGe.Point3d","toPoint:PyGe.Point3d","planeVector:PyGe.Vector3d" }))
        .def("addMLeader", &PyAcadBlock::addMLeader, DS.ARGS({ "points:list[PyGe.Point3d]" }))

        .def("__getitem__", &PyAcadBlock::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadBlock::begin, &PyAcadBlock::end))
        .def("cast", &PyAcadBlock::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlock::PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadBlock::count() const
{
    return impObj()->GetCount();
}

PyAcadEntity PyAcadBlock::item(long ind) const
{
    if (ind >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadEntity{ impObj()->GetItem(ind) };
}

boost::python::list PyAcadBlock::entities() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

std::string PyAcadBlock::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadBlock::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

AcGePoint3d PyAcadBlock::origin() const
{
    return impObj()->GetOrigin();
}

void PyAcadBlock::setOrigin(const AcGePoint3d& val) const
{
    impObj()->SetOrigin(val);
}

void PyAcadBlock::unload() const
{
    impObj()->Unload();
}

void PyAcadBlock::reload() const
{
    impObj()->Reload();
}

void PyAcadBlock::bind(bool bPrefixName) const
{
    impObj()->Bind(bPrefixName);
}

void PyAcadBlock::detach() const
{
    impObj()->Detach();
}

PyAcadDatabase PyAcadBlock::xrefDatabase() const
{
    return PyAcadDatabase{ impObj()->GetXRefDatabase() };
}

std::string PyAcadBlock::path() const
{
    return wstr_to_utf8(impObj()->GetPath());
}

void PyAcadBlock::setPath(const std::string& val) const
{
    impObj()->SetPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadBlock::comments() const
{
    return wstr_to_utf8(impObj()->GetComments());
}

void PyAcadBlock::setComments(const std::string& val) const
{
    impObj()->SetComments(utf8_to_wstr(val).c_str());
}

PyAcInsertUnits PyAcadBlock::units() const
{
    return impObj()->GetUnits();
}

void PyAcadBlock::setUnits(PyAcInsertUnits val) const
{
    impObj()->SetUnits(val);
}

bool PyAcadBlock::isExplodable() const
{
    return impObj()->GetExplodable();
}

void PyAcadBlock::setExplodable(bool val)
{
    impObj()->SetExplodable(val);
}

PyAcBlockScaling PyAcadBlock::blockScaling() const
{
    return impObj()->GetBlockScaling();
}

void PyAcadBlock::setBlockScaling(PyAcBlockScaling val) const
{
    impObj()->SetBlockScaling(val);
}

bool PyAcadBlock::isDynamicBlock() const
{
    return impObj()->GetIsDynamicBlock();
}

bool PyAcadBlock::isLayout() const
{
    return impObj()->GetIsLayout();
}

bool PyAcadBlock::isXRef() const
{
    return impObj()->GetIsXRef();
}

PyAcadObject PyAcadBlock::addCustomObject(const std::string& val)
{
    return PyAcadObject{ impObj()->AddCustomObject(utf8_to_wstr(val).c_str()) };
}

PyAcad3DFace PyAcadBlock::add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    return PyAcad3DFace{ impObj()->Add3DFace(p1,p2,p3,p4) };
}

PyAcadPolygonMesh PyAcadBlock::add3DMesh(int M, int N, const boost::python::object& iterable)
{
    return PyAcadPolygonMesh{ impObj()->Add3DMesh(M,N,py_list_to_std_vector<AcGePoint3d>(iterable)) };
}

PyAcad3DPolyline PyAcadBlock::add3DPoly(const boost::python::object& iterable)
{
    return PyAcad3DPolyline{ impObj()->Add3DPoly(py_list_to_std_vector<AcGePoint3d>(iterable)) };
}

PyAcadArc PyAcadBlock::addArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
{
    return PyAcadArc{ impObj()->AddArc(center, radius, startAngle, endAngle) };
}

PyAcadAttribute PyAcadBlock::addAttribute(double Height, PyAcAttributeMode mode, const std::string& prompt, const AcGePoint3d& insertionPoint, const std::string& tag, const std::string& value)
{
    return PyAcadAttribute{ impObj()->AddAttribute(Height, mode, utf8_to_wstr(prompt).c_str(), insertionPoint,utf8_to_wstr(tag).c_str(),utf8_to_wstr(value).c_str()) };
}

PyAcad3DSolid PyAcadBlock::addBox(const AcGePoint3d& origin, double length, double width, double height)
{
    return PyAcad3DSolid(impObj()->AddBox(origin, length, width, height));
}

PyAcadCircle PyAcadBlock::addCircle(const AcGePoint3d& center, double radius)
{
    return PyAcadCircle(impObj()->AddCircle(center, radius));
}

PyAcad3DSolid PyAcadBlock::addCone(const AcGePoint3d& center, double baseRadius, double height)
{
    return PyAcad3DSolid{ impObj()->AddCone(center,baseRadius,height) };
}

PyAcad3DSolid PyAcadBlock::addCylinder(const AcGePoint3d& center, double radius, double height)
{
    return PyAcad3DSolid{ impObj()->AddCylinder(center,radius,height) };
}

PyAcadDimAligned PyAcadBlock::addDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition)
{
    return PyAcadDimAligned{ impObj()->AddDimAligned(extLine1Point, extLine2Point, textPosition) };
}

PyAcadDimAngular PyAcadBlock::addDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition)
{
    return PyAcadDimAngular{ impObj()->AddDimAngular(angleVertex, firstEndPoint, secondEndPoint, textPosition) };
}

PyAcadDimDiametric PyAcadBlock::addDimDiametric(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength)
{
    return PyAcadDimDiametric{ impObj()->AddDimDiametric(chordPoint, farChordPoint, leaderLength) };
}

PyAcadDimRotated PyAcadBlock::addDimRotated(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& dimLineLocation, double rotationAngle)
{
    return PyAcadDimRotated{ impObj()->AddDimRotated(extLine1Point, extLine2Point, dimLineLocation, rotationAngle) };
}

PyAcadDimOrdinate PyAcadBlock::addDimOrdinate(const AcGePoint3d& definitionPoint, const AcGePoint3d& leaderEndPoint, int UseXAxis)
{
    return PyAcadDimOrdinate{ impObj()->AddDimOrdinate(definitionPoint, leaderEndPoint, UseXAxis) };
}

PyAcadDimRadial PyAcadBlock::addDimRadial(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength)
{
    return PyAcadDimRadial{ impObj()->AddDimRadial(center, chordPoint, leaderLength) };
}

PyAcadDimRadialLarge PyAcadBlock::addDimRadialLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle)
{
    return PyAcadDimRadialLarge{ impObj()->AddDimRadialLarge(center,chordPoint, overrideCenter, jogPoint, jogAngle) };
}

PyAcadDim3PointAngular PyAcadBlock::addDim3PointAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition)
{
    return PyAcadDim3PointAngular{ impObj()->AddDim3PointAngular(angleVertex, firstEndPoint, secondEndPoint, textPosition) };
}

PyAcadDimArcLength PyAcadBlock::addDimArc(const AcGePoint3d& arcCenter, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& arcPoint)
{
    return PyAcadDimArcLength{ impObj()->AddDimArc(arcCenter, firstEndPoint, secondEndPoint, arcPoint) };
}

PyAcadEllipse PyAcadBlock::addEllipse(const AcGePoint3d& center, const AcGeVector3d& majorAxis, double radiusRatio)
{
    return PyAcadEllipse{ impObj()->AddEllipse(center,majorAxis, radiusRatio) };
}

PyAcad3DSolid PyAcadBlock::addEllipticalCone(const AcGePoint3d& center, double majorRadius, double minorRadius, double height)
{
    return PyAcad3DSolid{ impObj()->AddEllipticalCone(center,majorRadius, minorRadius,height) };
}

PyAcad3DSolid PyAcadBlock::addEllipticalCylinder(const AcGePoint3d& center, double majorRadius, double minorRadius, double height)
{
    return PyAcad3DSolid{ impObj()->AddEllipticalCylinder(center,majorRadius, minorRadius,height) };
}

PyAcad3DSolid PyAcadBlock::addExtrudedSolid(const PyAcadRegion& impl, double height, double taperAngle)
{
    return PyAcad3DSolid{ impObj()->AddExtrudedSolid(*impl.impObj(),height,taperAngle) };
}

PyAcad3DSolid PyAcadBlock::addExtrudedSolidAlongPath(const PyAcadRegion& region, const PyAcadEntity& entity)
{
    return PyAcad3DSolid{ impObj()->AddExtrudedSolidAlongPath(*region.impObj(),*entity.impObj()) };
}

PyAcadLeader PyAcadBlock::addLeader(const boost::python::object& points, const PyAcadEntity& annotation, PyAcLeaderType lt)
{
    return PyAcadLeader{ impObj()->AddLeader(py_list_to_std_vector<AcGePoint3d>(points),*annotation.impObj(),lt) };
}

PyAcadMText PyAcadBlock::addMText(const AcGePoint3d& insertionPoint, double width, const std::string& text)
{
    return PyAcadMText{ impObj()->AddMText(insertionPoint,width,utf8_to_wstr(text).c_str()) };
}

PyAcadPoint PyAcadBlock::addPoint(const AcGePoint3d& point)
{
    return PyAcadPoint{ impObj()->AddPoint(point) };
}

PyAcadLWPolyline PyAcadBlock::addLightWeightPolyline(const boost::python::object& points)
{
    return PyAcadLWPolyline{ impObj()->AddLightWeightPolyline(py_list_to_std_vector<AcGePoint2d>(points)) };
}

PyAcadPolyline PyAcadBlock::addPolyline(const boost::python::object& points)
{
    return PyAcadPolyline{ impObj()->AddPolyline(py_list_to_std_vector<AcGePoint3d>(points)) };
}

PyAcadRay PyAcadBlock::addRay(const AcGePoint3d& p1, const AcGePoint3d& p2)
{
    return PyAcadRay{ impObj()->AddRay(p1,p2) };
}

boost::python::list PyAcadBlock::addRegion(const boost::python::object& curves)
{
    std::vector<PyIAcadEntityImpl> curveimpls;
    const auto& pycurves = py_list_to_std_vector<PyAcadEntity>(curves);
    for (const auto& pycurve : pycurves)
        curveimpls.push_back(*pycurve.impObj());
    const auto& regions = impObj()->AddRegion(curveimpls);
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto& region : regions)
        _pylist.append(PyAcadRegion{ region });
    return _pylist;
}

PyAcad3DSolid PyAcadBlock::addRevolvedSolid(const PyAcadRegion& region, const AcGePoint3d& axisPoint, const AcGeVector3d& axisDir, double angle)
{
    return PyAcad3DSolid{ impObj()->AddRevolvedSolid(*region.impObj(),axisPoint,axisDir,angle) };
}

PyAcadShape PyAcadBlock::addShape(const std::string& name, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle)
{
    return PyAcadShape{ impObj()->AddShape(utf8_to_wstr(name).c_str(),insertionPoint,scaleFactor, rotationAngle) };
}

PyAcadSolid PyAcadBlock::addSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    return PyAcadSolid{ impObj()->AddSolid(p1, p2, p3, p4) };
}

PyAcad3DSolid PyAcadBlock::addSphere(const AcGePoint3d& center, double radius)
{
    return PyAcad3DSolid{ impObj()->AddSphere(center, radius) };
}

PyAcadSpline PyAcadBlock::addSpline(const boost::python::object& points, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent)
{
    return PyAcadSpline{ impObj()->AddSpline(py_list_to_std_vector<AcGePoint3d>(points), startTangent, endTangent) };
}

PyAcadText PyAcadBlock::addText(const std::string& textValue, const AcGePoint3d& insertionPoint, double height)
{
    return PyAcadText{ impObj()->AddText(utf8_to_wstr(textValue).c_str(),insertionPoint,height) };
}

PyAcadTolerance PyAcadBlock::addTolerance(const std::string& textValue, const AcGePoint3d& insertionPoint, const AcGeVector3d& direction)
{
    return PyAcadTolerance{ impObj()->AddTolerance(utf8_to_wstr(textValue).c_str(),insertionPoint,direction) };
}

PyAcad3DSolid PyAcadBlock::addTorus(const AcGePoint3d& center, double torusRadius, double tubeRadius)
{
    return PyAcad3DSolid{ impObj()->AddTorus(center, torusRadius,tubeRadius) };
}

PyAcad3DSolid PyAcadBlock::addWedge(const AcGePoint3d& center, double length, double width, double height)
{
    return PyAcad3DSolid{ impObj()->AddWedge(center, length,width,height) };
}

PyAcadXline PyAcadBlock::addXline(const AcGePoint3d& p1, const AcGePoint3d& p2)
{
    return PyAcadXline{ impObj()->AddXline(p1, p2) };
}

PyAcadBlockReference PyAcadBlock::insertBlock(const AcGePoint3d& insertionPoint, const std::string& name, const AcGeScale3d& scale, double rotation)
{
    return PyAcadBlockReference{ impObj()->InsertBlock(insertionPoint, utf8_to_wstr(name).c_str(),scale, rotation) };
}

PyAcadHatch PyAcadBlock::addHatch(int patternType, const std::string& patternName, bool associativity)
{
    return PyAcadHatch{ impObj()->AddHatch(patternType, utf8_to_wstr(patternName).c_str(), associativity) };
}

PyAcadRasterImage PyAcadBlock::addRaster(const std::string& imageFileName, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle)
{
    return PyAcadRasterImage{ impObj()->AddRaster(utf8_to_wstr(imageFileName).c_str(), insertionPoint, scaleFactor, rotationAngle) };
}

PyAcadLine PyAcadBlock::addLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint)
{
    return PyAcadLine{ impObj()->AddLine(startPoint, endPoint) };
}

PyAcadMInsertBlock PyAcadBlock::addMInsertBlock(const AcGePoint3d& point, const std::string& name, const AcGeScale3d& scale, double rotation, long numRows, long numCols, long rowSpacing, long columnSpacing)
{
    return PyAcadMInsertBlock{ impObj()->AddMInsertBlock(point, utf8_to_wstr(name).c_str(), scale, rotation, numRows, numCols, rowSpacing, columnSpacing) };
}

PyAcadPolyfaceMesh PyAcadBlock::addPolyfaceMesh(const boost::python::object& points, const boost::python::object& faces)
{
    return PyAcadPolyfaceMesh{ impObj()->AddPolyfaceMesh(py_list_to_std_vector<AcGePoint3d>(points), py_list_to_std_vector<Adesk::Int16>(faces)) };
}

PyAcadMLine PyAcadBlock::addMLine(const boost::python::object& points)
{
    return PyAcadMLine{ impObj()->AddMLine(py_list_to_std_vector<AcGePoint3d>(points)) };
}

PyAcadExternalReference PyAcadBlock::attachExternalReference(const std::string& path, const std::string& name, const AcGePoint3d& insertionPoint, const AcGeScale3d& scale, double rotation, bool bOverlay)
{
    return PyAcadExternalReference{ impObj()->AttachExternalReference(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str(),insertionPoint,scale,rotation, bOverlay) };
}

PyAcadTable PyAcadBlock::addTable(const AcGePoint3d& insertionPoint, int numRows, int numColumns, double rowHeight, double colWidth)
{
    return PyAcadTable{ impObj()->AddTable(insertionPoint, numRows, numColumns, rowHeight, colWidth) };
}

PyAcadSection PyAcadBlock::addSection(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint, const AcGeVector3d& planeVector)
{
    return PyAcadSection{ impObj()->AddSection(fromPoint, toPoint, planeVector) };
}

PyAcadMLeader PyAcadBlock::addMLeader(const boost::python::object& points)
{
    PyAutoLockGIL lock;
    return PyAcadMLeader{ impObj()->AddMLeader(py_list_to_std_vector<AcGePoint3d>(points)) };
}

PyAcadBlock PyAcadBlock::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadBlock>(src);
}

std::string PyAcadBlock::className()
{
    return "AcadBlock";
}

PyIAcadBlockImpl* PyAcadBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadBlockImpl*>(m_pyImp.get());
}

void PyAcadBlock::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadEntity{ item });
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyModelSpace
void makePyModelSpaceWrapper()
{
    PyDocString DS("ModelSpace");
    class_<PyAcadModelSpace, bases<PyAcadBlock>>("ModelSpace", boost::python::no_init)
        .def("cast", &PyAcadModelSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadModelSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadModelSpace::PyAcadModelSpace(std::shared_ptr<PyIAcadModelSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadModelSpace PyAcadModelSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadModelSpace>(src);
}

std::string PyAcadModelSpace::className()
{
    return "AcadModelSpace";
}

PyIAcadModelSpaceImpl* PyAcadModelSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadModelSpaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyPaperSpace
void makePyPaperSpaceWrapper()
{
    PyDocString DS("PaperSpace");
    class_<PyAcadPaperSpace, bases<PyAcadBlock>>("PaperSpace", boost::python::no_init)
        .def("cast", &PyAcadPaperSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPaperSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPaperSpace::PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadPaperSpace PyAcadPaperSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPaperSpace>(src);
}

std::string PyAcadPaperSpace::className()
{
    return "AcadPaperSpace";
}

PyIAcadPaperSpaceImpl* PyAcadPaperSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPaperSpaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadBlocks
void makePyAcadBlocksWrapper()
{
    PyDocString DS("AcadBlocks");
    class_<PyAcadBlocks, bases<PyAcadObject>>("AcadBlocks", boost::python::no_init)
        .def("count", &PyAcadBlocks::count, DS.ARGS())
        .def("item", &PyAcadBlocks::item, DS.SARGS({ "index: int" }))
        .def("add", &PyAcadBlocks::add, DS.ARGS({ "insertionPoint:PyGe.Point3d","name:str" }))
        .def("blocks", &PyAcadBlocks::blocks, DS.ARGS())
        .def("cast", &PyAcadBlocks::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("__getitem__", &PyAcadBlocks::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadBlocks::begin, &PyAcadBlocks::end))
        .def("className", &PyAcadBlocks::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlocks::PyAcadBlocks(std::shared_ptr<PyIAcadBlocksImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadBlock PyAcadBlocks::item(long ind) const
{
    if (ind >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadBlock{ impObj()->GetItem(ind) };
}

long PyAcadBlocks::count() const
{
    return impObj()->GetCount();
}

PyAcadBlock PyAcadBlocks::add(const AcGePoint3d& insertionPoint, const std::string& name) const
{
    return PyAcadBlock{ impObj()->Add(insertionPoint, utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadBlocks::blocks() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetIter())
        pylist.append(PyAcadBlock{ item });
    return pylist;
}

PyAcadBlocks PyAcadBlocks::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadBlocks>(src);
}

std::string PyAcadBlocks::className()
{
    return "AcadBlocks";
}

PyIAcadBlocksImpl* PyAcadBlocks::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadBlocksImpl*>(m_pyImp.get());
}

void PyAcadBlocks::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadBlock{ item });
}

std::vector<PyAcadBlock>::iterator PyAcadBlocks::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadBlock>::iterator PyAcadBlocks::end()
{
    filliterator();
    return m_iterable.end();
}

//------------------------------------------------------------------------------------
//PyAcadState
void makePyAcadStateWrapper()
{
    PyDocString DS("AcadState");
    class_<PyAcadState>("AcadState", no_init)
        .def("isQuiescent", &PyAcadState::isQuiescent, DS.ARGS())
        .def("className", &PyAcadState::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadState::PyAcadState(std::shared_ptr<PyIAcadStateImpl> ptr)
    : m_pyImp(ptr)
{
}

bool PyAcadState::isQuiescent() const
{
    return impObj()->getIsQuiescent();
}

std::string PyAcadState::className()
{
    return "AcadState";
}

PyIAcadStateImpl* PyAcadState::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadStateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadApplicationWrapper()
{
    PyDocString DS("AcadApplication");
    class_<PyAcadApplication>("AcadApplication")
        .def("eval", &PyAcadApplication::eval, DS.ARGS({ "sval: str" }))
        .def("listArx", &PyAcadApplication::listArx, DS.ARGS())
        .def("acadState", &PyAcadApplication::acadState, DS.ARGS())
        .def("loadArx", &PyAcadApplication::loadArx, DS.ARGS({ "arx: str" }))
        .def("loadDVB", &PyAcadApplication::loadDVB, DS.ARGS({ "dvb: str" }))
        .def("quit", &PyAcadApplication::quit, DS.ARGS())
        .def("runMacro", &PyAcadApplication::runMacro, DS.ARGS({ "macro: str" }))
        .def("unloadArx", &PyAcadApplication::unloadArx, DS.ARGS({ "arx: str" }))
        .def("unloadDVB", &PyAcadApplication::unloadDVB, DS.ARGS({ "dvb: str" }))
        .def("update", &PyAcadApplication::update, DS.ARGS())
        .def("zoomAll", &PyAcadApplication::zoomAll, DS.ARGS())
        .def("zoomCenter", &PyAcadApplication::zoomCenter, DS.ARGS({ "pt: PyGe.Point3d", "magnify: float" }))
        .def("zoomExtents", &PyAcadApplication::zoomExtents, DS.ARGS())
        .def("zoomPickWindow", &PyAcadApplication::zoomPickWindow, DS.ARGS())
        .def("zoomPrevious", &PyAcadApplication::zoomPrevious, DS.ARGS())
        .def("zoomScaled", &PyAcadApplication::zoomScaled, DS.ARGS({ "magnify: float","scaletype: PyAx.AcZoomScaleType" }))
        .def("activeDocument", &PyAcadApplication::activeDocument, DS.ARGS())
        .def("setActiveDocument", &PyAcadApplication::setActiveDocument, DS.ARGS({ "doc : PyAx.AcadDocument" }))
        .def("caption", &PyAcadApplication::caption, DS.ARGS())
        .def("documents", &PyAcadApplication::documents, DS.ARGS())
        .def("fullName", &PyAcadApplication::fullName, DS.ARGS())
        .def("getHeight", &PyAcadApplication::getHeight, DS.ARGS())
        .def("setHeight", &PyAcadApplication::setHeight, DS.ARGS({ "height: int" }))
        .def("getHWND", &PyAcadApplication::getHWND, DS.ARGS())
        .def("localeId", &PyAcadApplication::localeId, DS.ARGS())
        .def("getName", &PyAcadApplication::getName, DS.ARGS())
        .def("getPath", &PyAcadApplication::getPath, DS.ARGS())
        .def("version", &PyAcadApplication::version, DS.ARGS())
        .def("isVisible", &PyAcadApplication::isVisible, DS.ARGS())
        .def("setVisible", &PyAcadApplication::setVisible, DS.ARGS({ "visible: bool" }))
        .def("getWidth", &PyAcadApplication::getWidth, DS.ARGS())
        .def("setWidth", &PyAcadApplication::setWidth, DS.ARGS({ "width: int" }))
        .def("getWindowLeft", &PyAcadApplication::getWindowLeft, DS.ARGS())
        .def("setWindowLeft", &PyAcadApplication::setWindowLeft, DS.ARGS({ "left: int" }))
        .def("getWindowTop", &PyAcadApplication::getWindowTop, DS.ARGS())
        .def("setWindowTop", &PyAcadApplication::setWindowTop, DS.ARGS({ "top: int" }))
        .def("getWindowState", &PyAcadApplication::getWindowState, DS.ARGS())
        .def("setWindowState", &PyAcadApplication::setWindowState, DS.ARGS({ "state: PyAx.AcWindowState" }))
        .def("menuBar", &PyAcadApplication::menuBar, DS.ARGS())
        .def("menuGroups", &PyAcadApplication::menuGroups, DS.ARGS())
        .def("preferences", &PyAcadApplication::preferences, DS.ARGS())
        .def("className", &PyAcadApplication::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadApplication::PyAcadApplication()
    : m_pyImp(new PyAcadApplicationImpl())
{
}

void PyAcadApplication::eval(const std::string& sval) const
{
    impObj()->Eval(utf8_to_wstr(sval).c_str());
}

PyAcadState PyAcadApplication::acadState()
{
    return PyAcadState{ impObj()->GetAcadState() };
}

boost::python::list PyAcadApplication::listArx() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& arx : impObj()->ListArx())
        _pylist.append(wstr_to_utf8(arx));
    return _pylist;
}

void PyAcadApplication::loadArx(const std::string& sval)
{
    impObj()->LoadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::loadDVB(const std::string& sval)
{
    impObj()->LoadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::quit()
{
    impObj()->Quit();
}

void PyAcadApplication::runMacro(const std::string& sval)
{
    impObj()->RunMacro(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadArx(const std::string& sval)
{
    impObj()->UnloadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadDVB(const std::string& sval)
{
    impObj()->UnloadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::update()
{
    impObj()->Update();
}

void PyAcadApplication::zoomAll()
{
    impObj()->ZoomAll();
}

void PyAcadApplication::zoomCenter(const AcGePoint3d& pnt, double magnify)
{
    impObj()->ZoomCenter(pnt, magnify);
}

void PyAcadApplication::zoomExtents()
{
    impObj()->ZoomExtents();
}

void PyAcadApplication::zoomPickWindow()
{
    impObj()->ZoomPickWindow();
}

void PyAcadApplication::zoomPrevious()
{
    impObj()->ZoomPrevious();
}

void PyAcadApplication::zoomScaled(double magnify, PyAcZoomScaleType scaletype)
{
    impObj()->ZoomScaled(magnify, scaletype);
}

PyAcadDocument PyAcadApplication::activeDocument() const
{
    return PyAcadDocument{ impObj()->GetActiveDocument() };
}

void PyAcadApplication::setActiveDocument(const PyAcadDocument& val) const
{
    impObj()->SetActiveDocument(*val.impObj());
}

std::string PyAcadApplication::caption() const
{
    return wstr_to_utf8(impObj()->GetCaption());
}

PyAcadDocuments PyAcadApplication::documents() const
{
    return PyAcadDocuments(impObj()->GetDocuments());
}

std::string PyAcadApplication::fullName() const
{
    return wstr_to_utf8(impObj()->GetFullName());
}

int PyAcadApplication::getHeight() const
{
    return impObj()->GetHeight();
}

void PyAcadApplication::setHeight(int val)
{
    impObj()->SetHeight(val);
}

LONG_PTR PyAcadApplication::getHWND() const
{
    return impObj()->GetHWND();
}

long PyAcadApplication::localeId() const
{
    return impObj()->GetLocaleId();
}

PyAcadMenuBar PyAcadApplication::menuBar() const
{
    return PyAcadMenuBar(impObj()->GetMenuBar());
}

PyAcadMenuGroups PyAcadApplication::menuGroups() const
{
    return PyAcadMenuGroups(impObj()->GetMenuGroups());
}

std::string PyAcadApplication::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

std::string PyAcadApplication::getPath() const
{
    return wstr_to_utf8(impObj()->GetPath());
}

PyAcadPreferences PyAcadApplication::preferences()
{
    return PyAcadPreferences(impObj()->GetPreferences());
}

std::string PyAcadApplication::version() const
{
    return wstr_to_utf8(impObj()->GetVersion());
}

bool PyAcadApplication::isVisible() const
{
    return impObj()->GetVisible();
}

void PyAcadApplication::setVisible(bool val)
{
    impObj()->SetVisible(val);
}

int PyAcadApplication::getWidth() const
{
    return impObj()->GetWidth();
}

void PyAcadApplication::setWidth(int val)
{
    impObj()->SetWidth(val);
}

int PyAcadApplication::getWindowLeft() const
{
    return impObj()->GetWindowLeft();
}

void PyAcadApplication::setWindowLeft(int val)
{
    impObj()->SetWindowLeft(val);
}

PyAcWindowState PyAcadApplication::getWindowState() const
{
    return impObj()->GetWindowState();
}

void PyAcadApplication::setWindowState(PyAcWindowState val)
{
    impObj()->SetWindowState(val);
}

int PyAcadApplication::getWindowTop() const
{
    return impObj()->GetWindowTop();
}

void PyAcadApplication::setWindowTop(int val)
{
    impObj()->SetWindowTop(val);
}

std::string PyAcadApplication::className()
{
    return "AcadApplication";
}

bool PyAcadApplication::runTest(const AcDbObjectId& id)
{
    return PyAcadApplicationImpl::runTest(id);
}

PyAcadApplicationImpl* PyAcadApplication::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyAcadApplicationImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDocuments
void makePyAcadDocumentsWrapper()
{
    PyDocString DS("AcadDocuments");
    class_<PyAcadDocuments>("AcadDocuments", no_init)
        .def("count", &PyAcadDocuments::count, DS.ARGS())
        .def("add", &PyAcadDocuments::add1)
        .def("add", &PyAcadDocuments::add2, DS.ARGS({ "template: str = None" }))
        .def("close", &PyAcadDocuments::close, DS.ARGS())
        .def("item", &PyAcadDocuments::item, DS.ARGS({ "index: int" }))
        .def("open", &PyAcadDocuments::open, DS.ARGS({ "path: str","readOnly: bool" }))
        .def("__getitem__", &PyAcadDocuments::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadDocuments::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocuments::PyAcadDocuments(std::shared_ptr<PyIAcadDocumentsImpl> ptr) noexcept
    : m_pyImp(ptr)
{
}

long PyAcadDocuments::count() const
{
    return impObj()->GetCount();
}

PyAcadDocument PyAcadDocuments::add1()
{
    return PyAcadDocument{ impObj()->Add() };
}

PyAcadDocument PyAcadDocuments::add2(const std::string& _template)
{
    return PyAcadDocument{ impObj()->Add(utf8_to_wstr(_template).c_str()) };
}

void PyAcadDocuments::close()
{
    return impObj()->Close();
}

PyAcadDocument PyAcadDocuments::item(long index)
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadDocument{ impObj()->GetItem(index) };
}

PyAcadDocument PyAcadDocuments::open(const std::string& path, bool readOnly)
{
    return PyAcadDocument{ impObj()->Open(utf8_to_wstr(path).c_str(),readOnly) };
}

std::string PyAcadDocuments::className()
{
    return "AcadDocuments";
}

PyIAcadDocumentsImpl* PyAcadDocuments::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDatabase
void makePyAcadDatabaseWrapper()
{
    PyDocString DS("AcadDatabase");
    class_<PyAcadDatabase>("AcadDatabase", no_init)
        .def("modelSpace", &PyAcadDatabase::modelSpace, DS.ARGS())
        .def("paperSpace", &PyAcadDatabase::paperSpace, DS.ARGS())
        .def("summaryInfo", &PyAcadDatabase::summaryInfo, DS.ARGS())
        .def("blocks", &PyAcadDatabase::blocks, DS.ARGS())
        .def("className", &PyAcadDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabase::PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept
    : m_pyImp(ptr)
{
}

PyAcadModelSpace PyAcadDatabase::modelSpace() const
{
    return PyAcadModelSpace{ impObj()->GetModelSpace() };
}

PyAcadPaperSpace PyAcadDatabase::paperSpace() const
{
    return PyAcadPaperSpace{ impObj()->GetPaperSpace() };
}

PyAcadSummaryInfo PyAcadDatabase::summaryInfo() const
{
    return PyAcadSummaryInfo{ impObj()->GetSummaryInfo() };
}

PyAcadBlocks PyAcadDatabase::blocks() const
{
    return PyAcadBlocks{ impObj()->GetBlocks() };
}

std::string PyAcadDatabase::className()
{
    return "AcadDatabase";
}

PyIAcadDatabaseImpl* PyAcadDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDocument
void makePyAcadDocumentWrapper()
{
    PyDocString DS("AcadDocument");
    class_<PyAcadDocument, bases<PyAcadDatabase>>("AcadDocument", no_init)
        .def("close", &PyAcadDocument::close1)
        .def("close", &PyAcadDocument::close2)
        .def("close", &PyAcadDocument::close3, DS.ARGS({ "saveChanges:bool=False", "fileName:str=None" }))

        .def("name", &PyAcadDocument::name, DS.ARGS())
        .def("database", &PyAcadDocument::database, DS.ARGS())
        .def("className", &PyAcadDocument::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocument::PyAcadDocument(std::shared_ptr<PyIAcadDocumentImpl> ptr)
    : PyAcadDatabase(ptr)
{
}

std::string PyAcadDocument::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

PyAcadDatabase PyAcadDocument::database()
{
    return PyAcadDatabase{ impObj()->GetDatabase() };
}

void PyAcadDocument::close1()
{
    impObj()->Close();
}

void PyAcadDocument::close2(bool saveChanges)
{
    impObj()->Close(saveChanges);
}

void PyAcadDocument::close3(bool saveChanges, const std::string& fileName)
{
    impObj()->Close(saveChanges, utf8_to_wstr(fileName).c_str());
}

std::string PyAcadDocument::className()
{
    return "AcadDocument";
}

PyIAcadDocumentImpl* PyAcadDocument::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDocumentImpl*>(m_pyImp.get());
}
