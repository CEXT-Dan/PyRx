#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadDimension.h"
#include "PyAcadDimensionImpl.h"
#include "PyAcadTable.h"
#include "PyAcadTableImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadGroup
void makePyAcadGroupWrapper()
{
    PyDocString DS("AcadGroup");
    class_<PyAcadGroup, bases<PyAcadObject>>("AcadGroup", boost::python::no_init)
        .def("item", &PyAcadGroup::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadGroup::items, DS.ARGS())
        .def("count", &PyAcadGroup::count, DS.ARGS())
        .def("setTrueColor", &PyAcadGroup::setTrueColor, DS.ARGS({ "color: PyAx.AcadAcCmColor" }))
        .def("setLayer", &PyAcadGroup::setLayer, DS.ARGS({ "layer_name: str" }))
        .def("setLinetype", &PyAcadGroup::setLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("setLinetypeScale", &PyAcadGroup::setLinetypeScale, DS.ARGS({ "scale_factor: float" }))
        .def("setVisible", &PyAcadGroup::setVisible, DS.ARGS({ "is_visible: bool" }))
        .def("highlight", &PyAcadGroup::highlight, DS.ARGS({ "should_highlight: bool" }))
        .def("setPlotStyleName", &PyAcadGroup::setPlotStyleName, DS.ARGS({ "plot_style_name: str" }))
        .def("setLineWeight", &PyAcadGroup::setLineWeight, DS.ARGS({ "line_weight: int" }))
        .def("name", &PyAcadGroup::name, DS.ARGS())
        .def("setName", &PyAcadGroup::setName, DS.ARGS({ "group_name: str" }))
        .def("appendItems", &PyAcadGroup::appendItems, DS.ARGS({ "entities: Collection[PyAx.AcadEntity]" }))
        .def("removeItems", &PyAcadGroup::removeItems, DS.ARGS({ "entities: Collection[PyAx.AcadEntity]" }))
        .def("update", &PyAcadGroup::update, DS.ARGS())
        .def("setMaterial", &PyAcadGroup::setMaterial, DS.ARGS())
        .def("setColor", &PyAcadGroup::setColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("cast", &PyAcadGroup::cast, DS.SARGS({ "other_object: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadGroup::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadGroup::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadGroup::begin, &PyAcadGroup::end))
        ;
}

PyAcadGroup::PyAcadGroup(std::shared_ptr<PyIAcadGroupImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadEntity PyAcadGroup::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadEntity{ impObj()->GetItem(index) };
}

boost::python::list PyAcadGroup::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

long PyAcadGroup::count() const
{
    return impObj()->GetCount();
}

void PyAcadGroup::setTrueColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetTrueColor(*val.impObj());
}

void PyAcadGroup::setLayer(const std::string& val) const
{
    impObj()->SetLayer(utf8_to_wstr(val).c_str());
}

void PyAcadGroup::setLinetype(const std::string& val) const
{
    impObj()->SetLinetype(utf8_to_wstr(val).c_str());
}

void PyAcadGroup::setLinetypeScale(double val) const
{
    impObj()->SetLinetypeScale(val);
}

void PyAcadGroup::setVisible(bool val) const
{
    impObj()->SetVisible(val);
}

void PyAcadGroup::highlight(bool val) const
{
    impObj()->Highlight(val);
}

void PyAcadGroup::setPlotStyleName(const std::string& val) const
{
    impObj()->SetPlotStyleName(utf8_to_wstr(val).c_str());
}

void PyAcadGroup::setLineWeight(PyAcLineWeight val) const
{
    impObj()->SetLineWeight(val);
}

std::string PyAcadGroup::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadGroup::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

void PyAcadGroup::appendItems(const boost::python::object& objects) const
{
    std::vector<PyIAcadEntityImpl> objectimpls;
    for (const auto& pycurve : py_list_to_std_vector<PyAcadEntity>(objects))
        objectimpls.push_back(*pycurve.impObj());
    impObj()->AppendItems(objectimpls);
}

void PyAcadGroup::removeItems(const boost::python::object& objects) const
{
    std::vector<PyIAcadEntityImpl> objectimpls;
    for (const auto& pycurve : py_list_to_std_vector<PyAcadEntity>(objects))
        objectimpls.push_back(*pycurve.impObj());
    impObj()->RemoveItems(objectimpls);
}

void PyAcadGroup::update() const
{
    impObj()->Update();
}

void PyAcadGroup::setMaterial(const std::string& val) const
{
    impObj()->SetMaterial(utf8_to_wstr(val).c_str());
}

void PyAcadGroup::setColor(PyAcColor val) const
{
    impObj()->SetColor(val);
}

PyAcadGroup PyAcadGroup::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadGroup>(src);
}

std::string PyAcadGroup::className()
{
    return "AcadGroup";
}

PyIAcadGroupImpl* PyAcadGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadGroupImpl*>(m_pyImp.get());
}

void PyAcadGroup::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadEntity{ item });
}

std::vector<PyAcadEntity>::iterator PyAcadGroup::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadEntity>::iterator PyAcadGroup::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyAcadGroups
void makePyAcadGroupsWrapper()
{
    PyDocString DS("AcadGroups");
    class_<PyAcadGroups, bases<PyAcadObject>>("AcadGroups", boost::python::no_init)
        .def("count", &PyAcadGroups::count, DS.ARGS())
        .def("add", &PyAcadGroups::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadGroups::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadGroups::items, DS.ARGS())
        .def("cast", &PyAcadGroups::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadGroups::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadGroups::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadGroups::begin, &PyAcadGroups::end))
        ;
}

PyAcadGroups::PyAcadGroups(std::shared_ptr<PyIAcadGroupsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadGroups::count() const
{
    return impObj()->GetCount();
}

PyAcadGroup PyAcadGroups::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadGroup{ impObj()->GetItem(index) };
}

PyAcadGroup PyAcadGroups::add(const std::string& name) const
{
    return PyAcadGroup{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadGroups::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadGroup{ item });
    return _pylist;
}

PyAcadGroups PyAcadGroups::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadGroups>(src);
}

std::string PyAcadGroups::className()
{
    return "AcadGroups";
}

PyIAcadGroupsImpl* PyAcadGroups::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadGroupsImpl*>(m_pyImp.get());
}

void PyAcadGroups::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadGroup{ item });
}

std::vector<PyAcadGroup>::iterator PyAcadGroups::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadGroup>::iterator PyAcadGroups::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper()
{
    PyDocString DS("AcadBlock");
    class_<PyAcadBlock, bases<PyAcadObject>>("AcadBlock", boost::python::no_init)
        .def("count", &PyAcadBlock::count, DS.ARGS())
        .def("item", &PyAcadBlock::item, DS.SARGS({ "index: int" }))
        .def("entities", &PyAcadBlock::entities, DS.ARGS())
        .def("items", &PyAcadBlock::entities, DS.ARGS())
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
        .def("layout", &PyAcadBlock::layout, DS.ARGS())
        .def("isXRef", &PyAcadBlock::isXRef, DS.ARGS())
        .def("addCustomObject", &PyAcadBlock::addCustomObject, DS.ARGS({ "name:str" }))
        .def("add3DFace", &PyAcadBlock::add3DFace, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("add3DMesh", &PyAcadBlock::add3DMesh, DS.ARGS({ "M:int","N:int","points:Collection[PyGe.Point3d]" }))
        .def("add3DPoly", &PyAcadBlock::add3DPoly, DS.ARGS({ "points:Collection[PyGe.Point3d]" }))
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
        .def("addLeader", &PyAcadBlock::addLeader, DS.ARGS({ "points:Collection[PyGe.Point3d]","annotation:PyAx.AcadEntity","leaderType:PyAx.AcLeaderType" }))
        .def("addMText", &PyAcadBlock::addMText, DS.ARGS({ "insertionPoint:PyGe.Point3d","width:float","textVal:str" }))
        .def("addPoint", &PyAcadBlock::addPoint, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("addLightWeightPolyline", &PyAcadBlock::addLightWeightPolyline, DS.ARGS({ "points:Collection[PyGe.Point2d]" }))
        .def("addPolyline", &PyAcadBlock::addPolyline, DS.ARGS({ "points:Collection[PyGe.Point3d]" }))
        .def("addRay", &PyAcadBlock::addRay, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d" }))
        .def("addRegion", &PyAcadBlock::addRegion, DS.ARGS({ "curves:PyAx.AcadEntity" }))
        .def("addRevolvedSolid", &PyAcadBlock::addRevolvedSolid, DS.ARGS({ "region:PyAx.AcadRegion","axisPoint:PyGe.Point3d","axisDir:PyGe.Vector3d","angle:float" }))
        .def("addShape", &PyAcadBlock::addShape, DS.ARGS({ "name:str","insertionPoint:PyGe.Point3d", "scaleFactor:float","rotationAngle:float" }))
        .def("addSolid", &PyAcadBlock::addSolid, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("addSphere", &PyAcadBlock::addSphere, DS.ARGS({ "center:PyGe.Point3d","radius:float" }))
        .def("addSpline", &PyAcadBlock::addSpline, DS.ARGS({ "points:Collection[PyGe.Point3d]", "startTangent:PyGe.Vector3d","endTangent:PyGe.Vector3d" }))
        .def("addText", &PyAcadBlock::addText, DS.ARGS({ "textValue:str","insertionPoint:PyGe.Point3d", "height:float" }))
        .def("addTolerance", &PyAcadBlock::addTolerance, DS.ARGS({ "textValue:str","insertionPoint:PyGe.Point3d", "direction:PyGe.Vector3d" }))
        .def("addTorus", &PyAcadBlock::addTorus, DS.ARGS({ "center:PyGe.Point3d","torusRadius:float","tubeRadius:float" }))
        .def("addWedge", &PyAcadBlock::addWedge, DS.ARGS({ "center:PyGe.Point3d","length:float","width:float","height:float" }))
        .def("addXline", &PyAcadBlock::addXline, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d" }))
        .def("insertBlock", &PyAcadBlock::insertBlock, DS.ARGS({ "insertionPoint:PyGe.Point3d","name:str","scale:PyGe.Scale3d","rotation:float" }))
        .def("addHatch", &PyAcadBlock::addHatch, DS.ARGS({ "patternType:int","patternName:str","associativity:bool", "ht:PyAx.AcHatchObjectType" }))
        .def("addRaster", &PyAcadBlock::addRaster, DS.ARGS({ "imageFileName:str","insertionPoint:PyGe.Point3d","scaleFactor:float","rotationAngle:float" }))
        .def("addLine", &PyAcadBlock::addLine, DS.ARGS({ "startPoint:PyGe.Point3d","endPoint:PyGe.Point3d" }))
        .def("addMInsertBlock", &PyAcadBlock::addMInsertBlock, DS.ARGS({ "point:PyGe.Point3d","name:str","rotation:float","numRows:int","numCols:int" ,"rowSpacing:int" ,"rolumnSpacing:int" }))
        .def("addPolyfaceMesh", &PyAcadBlock::addPolyfaceMesh, DS.ARGS({ "points:Collection[PyGe.Point3d]", "faces:Collection[int]" }))
        .def("addMLine", &PyAcadBlock::addMLine, DS.ARGS({ "points:Collection[PyGe.Point3d]" }))
        .def("attachExternalReference", &PyAcadBlock::attachExternalReference, DS.ARGS({ "path:str","name:str","insertionPoint:PyGe.Point3d","scale:PyGe.Scale3d","rotation:float","bOverlay:bool" }))
        .def("addTable", &PyAcadBlock::addTable, DS.ARGS({ "insertionPoint:PyGe.Point3d","numRows:int","numColumns:int","rowHeight:float","colWidth:float" }))
        .def("addSection", &PyAcadBlock::addSection, DS.ARGS({ "fromPoint:PyGe.Point3d","toPoint:PyGe.Point3d","planeVector:PyGe.Vector3d" }))
        .def("addMLeader", &PyAcadBlock::addMLeader, DS.ARGS({ "points:Collection[PyGe.Point3d]" }))

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

void PyAcadBlock::setName(const std::string& val) const
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

void PyAcadBlock::setExplodable(bool val) const
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

PyAcadLayout PyAcadBlock::layout() const
{
    return PyAcadLayout{ impObj()->GetLayout() };
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

boost::python::list PyAcadBlock::addRegion(const boost::python::object& curves) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> curveimpls;
    for (const auto& pycurve : py_list_to_std_vector<PyAcadEntity>(curves))
        curveimpls.push_back(*pycurve.impObj());
    boost::python::list _pylist;
    for (auto& region : impObj()->AddRegion(curveimpls))
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

PyAcadHatch PyAcadBlock::addHatch(int patternType, const std::string& patternName, bool associativity, PyAcHatchObjectType ht)
{
    return PyAcadHatch{ impObj()->AddHatch(patternType, utf8_to_wstr(patternName).c_str(), associativity,ht) };
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
        .def("addPViewport", &PyAcadPaperSpace::addPViewport, DS.ARGS())
        .def("cast", &PyAcadPaperSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPaperSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPaperSpace::PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadPViewport PyAcadPaperSpace::addPViewport(const AcGePoint3d& center, double width, double height)
{
    return PyAcadPViewport{ impObj()->AddPViewport(center,width,height) };
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
        .def("has", &PyAcadBlocks::has, DS.ARGS({ "blockName:str" }))
        .def("count", &PyAcadBlocks::count, DS.ARGS())
        .def("item", &PyAcadBlocks::item, DS.SARGS({ "index: int" }))
        .def("add", &PyAcadBlocks::add, DS.ARGS({ "insertionPoint:PyGe.Point3d","name:str" }))
        .def("blocks", &PyAcadBlocks::blocks, DS.ARGS())
        .def("items", &PyAcadBlocks::blocks, DS.ARGS())
        .def("cast", &PyAcadBlocks::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlocks::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadBlocks::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadBlocks::begin, &PyAcadBlocks::end))
        ;
}

PyAcadBlocks::PyAcadBlocks(std::shared_ptr<PyIAcadBlocksImpl> ptr)
    : PyAcadObject(ptr)
{
}

bool PyAcadBlocks::has(const std::string& name) const
{
    return impObj()->GetHas(utf8_to_wstr(name).c_str());
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
        .def("setCaption", &PyAcadApplication::setCaption, DS.ARGS({ "caption:str" }))
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

PyAcadState PyAcadApplication::acadState() const
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

void PyAcadApplication::loadArx(const std::string& sval) const
{
    impObj()->LoadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::loadDVB(const std::string& sval) const
{
    impObj()->LoadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::quit() const
{
    impObj()->Quit();
}

void PyAcadApplication::runMacro(const std::string& sval) const
{
    impObj()->RunMacro(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadArx(const std::string& sval) const
{
    impObj()->UnloadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadDVB(const std::string& sval) const
{
    impObj()->UnloadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::update() const
{
    impObj()->Update();
}

void PyAcadApplication::zoomAll() const
{
    impObj()->ZoomAll();
}

void PyAcadApplication::zoomCenter(const AcGePoint3d& pnt, double magnify) const
{
    impObj()->ZoomCenter(pnt, magnify);
}

void PyAcadApplication::zoomExtents() const
{
    impObj()->ZoomExtents();
}

void PyAcadApplication::zoomPickWindow() const
{
    impObj()->ZoomPickWindow();
}

void PyAcadApplication::zoomPrevious() const
{
    impObj()->ZoomPrevious();
}

void PyAcadApplication::zoomScaled(double magnify, PyAcZoomScaleType scaletype) const
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

void PyAcadApplication::setCaption(const std::string& val) const
{
    impObj()->SetCaption(utf8_to_wstr(val).c_str());
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

void PyAcadApplication::setHeight(int val) const
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

void PyAcadApplication::setVisible(bool val) const
{
    impObj()->SetVisible(val);
}

int PyAcadApplication::getWidth() const
{
    return impObj()->GetWidth();
}

void PyAcadApplication::setWidth(int val) const
{
    impObj()->SetWidth(val);
}

int PyAcadApplication::getWindowLeft() const
{
    return impObj()->GetWindowLeft();
}

void PyAcadApplication::setWindowLeft(int val) const
{
    impObj()->SetWindowLeft(val);
}

PyAcWindowState PyAcadApplication::getWindowState() const
{
    return impObj()->GetWindowState();
}

void PyAcadApplication::setWindowState(PyAcWindowState val) const
{
    impObj()->SetWindowState(val);
}

int PyAcadApplication::getWindowTop() const
{
    return impObj()->GetWindowTop();
}

void PyAcadApplication::setWindowTop(int val) const
{
    impObj()->SetWindowTop(val);
}

std::string PyAcadApplication::className()
{
    return "AcadApplication";
}

bool PyAcadApplication::runTest()
{
    return PyAcadApplicationImpl::runTest();
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
        .def("add", &PyAcadDocuments::add2, DS.ARGS({ "template: str = ..." }))
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

PyAcadDocument PyAcadDocuments::add1() const
{
    return PyAcadDocument{ impObj()->Add() };
}

PyAcadDocument PyAcadDocuments::add2(const std::string& _template) const
{
    return PyAcadDocument{ impObj()->Add(utf8_to_wstr(_template).c_str()) };
}

void PyAcadDocuments::close() const
{
    return impObj()->Close();
}

PyAcadDocument PyAcadDocuments::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadDocument{ impObj()->GetItem(index) };
}

PyAcadDocument PyAcadDocuments::open(const std::string& path, bool readOnly) const
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
        .def("blocks", &PyAcadDatabase::blocks, DS.ARGS())
        .def("copyObjects", &PyAcadDatabase::copyObjects, DS.ARGS({ "objs:list[PyAx.AcadObject]","owner:PyAx.AcadObject" }))
        .def("groups", &PyAcadDatabase::groups, DS.ARGS())
        .def("dimStyles", &PyAcadDatabase::dimStyles, DS.ARGS())
        .def("layers", &PyAcadDatabase::layers, DS.ARGS())
        .def("lineTypes", &PyAcadDatabase::lineTypes, DS.ARGS())
        .def("dictionaries", &PyAcadDatabase::dictionaries, DS.ARGS())
        .def("registeredApplications", &PyAcadDatabase::registeredApplications, DS.ARGS())
        .def("textStyles", &PyAcadDatabase::textStyles, DS.ARGS())
        .def("userCoordinateSystems", &PyAcadDatabase::userCoordinateSystems, DS.ARGS())
        .def("views", &PyAcadDatabase::views, DS.ARGS())
        .def("viewports", &PyAcadDatabase::viewports, DS.ARGS())
        .def("elevationModelSpace", &PyAcadDatabase::elevationModelSpace, DS.ARGS())
        .def("setElevationModelSpace", &PyAcadDatabase::setElevationModelSpace, DS.ARGS({ "elev:float" }))
        .def("elevationPaperSpace", &PyAcadDatabase::elevationPaperSpace, DS.ARGS())
        .def("setElevationPaperSpace", &PyAcadDatabase::setElevationPaperSpace, DS.ARGS({ "elev:float" }))
        .def("limits", &PyAcadDatabase::limits, DS.ARGS())
        .def("setLimits", &PyAcadDatabase::setLimits, DS.ARGS({ "minmax:tuple[PyGe.Point2d,PyGe.Point2d]" }))
        .def("handleToObject", &PyAcadDatabase::handleToObject, DS.ARGS({ "val:str" }))
        .def("objectIdToObject", &PyAcadDatabase::objectIdToObject, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("layouts", &PyAcadDatabase::layouts, DS.ARGS())
        .def("plotConfigurations", &PyAcadDatabase::plotConfigurations, DS.ARGS())
        .def("preferences", &PyAcadDatabase::preferences, DS.ARGS())
        .def("summaryInfo", &PyAcadDatabase::summaryInfo, DS.ARGS())
        .def("sectionManager", &PyAcadDatabase::sectionManager, DS.ARGS())
        .def("materials", &PyAcadDatabase::materials, DS.ARGS())
        .def("className", &PyAcadDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabase::PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept
    : m_pyImp(ptr)
{
}

PyAcadDatabase::PyAcadDatabase(AcDbDatabase* ptr) noexcept
    : m_pyImp(std::make_shared<PyIAcadDatabaseImpl>(GetIAcadDatabaseFromAcDbDatabse(ptr)))
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

PyAcadSectionManager PyAcadDatabase::sectionManager() const
{
    return PyAcadSectionManager{ impObj()->GetSectionManager() };
}

PyAcadMaterials PyAcadDatabase::materials() const
{
    return PyAcadMaterials{ impObj()->GetMaterials() };
}

PyAcadBlocks PyAcadDatabase::blocks() const
{
    return PyAcadBlocks{ impObj()->GetBlocks() };
}

boost::python::list PyAcadDatabase::copyObjects(const boost::python::object& pyobjs, const PyAcadObject& owner) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadObjectImpl> objs;
    for (const auto& item : py_list_to_std_vector<PyAcadObject>(pyobjs))
        objs.push_back(*item.impObj());
    boost::python::list pycopies;
    for (const auto& item : impObj()->CopyObjects(objs, *owner.impObj()))
        pycopies.append(PyAcadObject{ item });
    return pycopies;
}

PyAcadGroups PyAcadDatabase::groups() const
{
    return PyAcadGroups{ impObj()->GetGroups() };
}

PyAcadDimStyles PyAcadDatabase::dimStyles() const
{
    return PyAcadDimStyles{ impObj()->GetDimStyles() };
}

PyAcadLayers PyAcadDatabase::layers() const
{
    return PyAcadLayers{ impObj()->GetLayers() };
}

PyAcadLineTypes PyAcadDatabase::lineTypes() const
{
    return PyAcadLineTypes{ impObj()->GetLineTypes() };
}

PyAcadDictionaries PyAcadDatabase::dictionaries() const
{
    return PyAcadDictionaries{ impObj()->GetDictionaries() };
}

PyAcadRegisteredApplications PyAcadDatabase::registeredApplications() const
{
    return PyAcadRegisteredApplications{ impObj()->GetRegisteredApplications() };
}

PyAcadTextStyles PyAcadDatabase::textStyles() const
{
    return PyAcadTextStyles{ impObj()->GetTextStyles() };
}

PyAcadUCSs PyAcadDatabase::userCoordinateSystems() const
{
    return PyAcadUCSs{ impObj()->GetUserCoordinateSystems() };
}

PyAcadViews PyAcadDatabase::views() const
{
    return PyAcadViews{ impObj()->GetViews() };
}

PyAcadViewports PyAcadDatabase::viewports() const
{
    return PyAcadViewports{ impObj()->GetViewports() };
}

double PyAcadDatabase::elevationModelSpace() const
{
    return impObj()->GetElevationModelSpace();
}

void PyAcadDatabase::setElevationModelSpace(double val) const
{
    impObj()->SetElevationModelSpace(val);
}

double PyAcadDatabase::elevationPaperSpace() const
{
    return impObj()->GetElevationPaperSpace();
}

void PyAcadDatabase::setElevationPaperSpace(double val) const
{
    impObj()->SetElevationPaperSpace(val);
}

boost::python::tuple PyAcadDatabase::limits() const
{
    PyAutoLockGIL lock;
    AcGePoint2d min;
    AcGePoint2d max;
    impObj()->GetLimits(min, max);
    return boost::python::make_tuple(min, max);
}

void PyAcadDatabase::setLimits(boost::python::tuple minmax) const
{
    const auto& vec = py_list_to_std_vector<AcGePoint2d>(minmax);
    if (vec.size() != 2)
        PyThrowBadEs(eInvalidInput);
    AcGePoint2d min = vec[0];
    AcGePoint2d max = vec[1];
    impObj()->SetLimits(min, max);
}

PyAcadObject PyAcadDatabase::handleToObject(const std::string& val) const
{
    return PyAcadObject{ impObj()->HandleToObject(utf8_to_wstr(val).c_str()) };
}

PyAcadObject PyAcadDatabase::objectIdToObject(const PyDbObjectId& val) const
{
    return PyAcadObject{ impObj()->ObjectIdToObject(val.m_id) };
}

PyAcadLayouts PyAcadDatabase::layouts() const
{
    return PyAcadLayouts{ impObj()->GetLayouts() };
}

PyAcadPlotConfigurations PyAcadDatabase::plotConfigurations() const
{
    return PyAcadPlotConfigurations{ impObj()->GetPlotConfigurations() };
}

PyAcadDatabasePreferences PyAcadDatabase::preferences() const
{
    return PyAcadDatabasePreferences{ impObj()->GetPreferences() };
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
    constexpr const std::string_view saveAsOverloads = "Overloads:\n"
        "- fileName: str\n"
        "- fileName: str, saType: PyAx.AcSaveAsType\n"
        "- fileName: str, saType: PyAx.AcSaveAsType, pr: PyAx.AcadSecurityParams\n";

    PyDocString DS("AcadDocument");
    class_<PyAcadDocument, bases<PyAcadDatabase>>("AcadDocument", no_init)
        .def("plot", &PyAcadDocument::plot, DS.ARGS())
        .def("activeLayer", &PyAcadDocument::activeLayer, DS.ARGS())
        .def("setActiveLayer", &PyAcadDocument::setActiveLayer, DS.ARGS({ "layer:PyAx.AcadLayer" }))
        .def("activeLinetype", &PyAcadDocument::activeLinetype, DS.ARGS())
        .def("setActiveLinetype", &PyAcadDocument::setActiveLinetype, DS.ARGS({ "linetype:PyAx.AcadLineType" }))
        .def("activeDimStyle", &PyAcadDocument::activeDimStyle, DS.ARGS())
        .def("setActiveDimStyle", &PyAcadDocument::setActiveDimStyle, DS.ARGS({ "dimstyle:PyAx.AcadDimStyle" }))
        .def("activeTextStyle", &PyAcadDocument::activeTextStyle, DS.ARGS())
        .def("setActiveTextStyle", &PyAcadDocument::setActiveTextStyle, DS.ARGS({ "textstyle:PyAx.AcadTextStyle" }))
        .def("activeUCS", &PyAcadDocument::activeUCS, DS.ARGS())
        .def("setActiveUCS", &PyAcadDocument::setActiveUCS, DS.ARGS({ "UCS:PyAx.AcadUCS" }))
        .def("activeViewport", &PyAcadDocument::activeViewport, DS.ARGS())
        .def("setActiveViewport", &PyAcadDocument::setActiveViewport, DS.ARGS({ "viewport:PyAx.AcadViewport" }))
        .def("activePViewport", &PyAcadDocument::activePViewport, DS.ARGS())
        .def("setActivePViewport", &PyAcadDocument::setActivePViewport, DS.ARGS({ "p_viewport:PyAx.AcadPViewport" }))
        .def("activeSpace", &PyAcadDocument::activeSpace, DS.ARGS())
        .def("setActiveSpace", &PyAcadDocument::setActiveSpace, DS.ARGS({ "space:PyAx.AcActiveSpace" }))
        .def("selectionSets", &PyAcadDocument::selectionSets, DS.ARGS())
        .def("activeSelectionSet", &PyAcadDocument::activeSelectionSet, DS.ARGS())
        .def("name", &PyAcadDocument::name, DS.ARGS())
        .def("fullName", &PyAcadDocument::fullName, DS.ARGS())
        .def("path", &PyAcadDocument::path, DS.ARGS())
        .def("objectSnapMode", &PyAcadDocument::objectSnapMode, DS.ARGS())
        .def("setObjectSnapMode", &PyAcadDocument::setObjectSnapMode, DS.ARGS({ "enable:bool" }))
        .def("isReadOnly", &PyAcadDocument::isReadOnly, DS.ARGS())
        .def("isSaved", &PyAcadDocument::isSaved, DS.ARGS())
        .def("mSpace", &PyAcadDocument::mSpace, DS.ARGS())
        .def("setMSpace", &PyAcadDocument::setMSpace, DS.ARGS({ "enable:bool" }))
        .def("utility", &PyAcadDocument::utility, DS.ARGS())
        .def("open", &PyAcadDocument::open, DS.ARGS({ "full_path:str" }))
        .def("auditInfo", &PyAcadDocument::auditInfo, DS.ARGS({ "enable:bool" }))
        .def("importFile", &PyAcadDocument::importFile, DS.ARGS({ "file_path:str","insertion_point:PyGe.Point3d","scale_factor:float" }))
        .def("exportToFile", &PyAcadDocument::exportToFile, DS.ARGS({ "file_name:str","extension:str","selection_set:PyAx.AcadSelectionSet" }))
        .def("saveAs", &PyAcadDocument::saveAs1)
        .def("saveAs", &PyAcadDocument::saveAs2)
        .def("saveAs", &PyAcadDocument::saveAs3, DS.OVRL(saveAsOverloads))
        .def("save", &PyAcadDocument::save, DS.ARGS())
        .def("wblock", &PyAcadDocument::wblock, DS.ARGS({ "file_name: str", "selection_set: PyAx.AcadSelectionSet" }))
        .def("purgeAll", &PyAcadDocument::purgeAll, DS.ARGS())
        .def("getVariable", &PyAcadDocument::getVariable, DS.ARGS({ "variable_name:str" }))
        .def("setVariable", &PyAcadDocument::setVariable, DS.ARGS({ "variable_name:str","value:Any" }))
        .def("loadShapeFile", &PyAcadDocument::loadShapeFile, DS.ARGS({ "file_name:str" }))
        .def("regen", &PyAcadDocument::regen, DS.ARGS({ "regen_type:PyAx.AcRegenType" }))
        .def("pickfirstSelectionSet", &PyAcadDocument::pickfirstSelectionSet, DS.ARGS())
        .def("isActive", &PyAcadDocument::isActive, DS.ARGS())
        .def("activate", &PyAcadDocument::activate, DS.ARGS())
        .def("close", &PyAcadDocument::close1)
        .def("close", &PyAcadDocument::close2)
        .def("close", &PyAcadDocument::close3, DS.ARGS({ "save_changes:bool=False", "file_name:str = ..." }))
        .def("windowState", &PyAcadDocument::windowState, DS.ARGS())
        .def("setWindowState", &PyAcadDocument::setWindowState, DS.ARGS({ "state:PyAx.AcWindowState" }))
        .def("width", &PyAcadDocument::width, DS.ARGS())
        .def("setWidth", &PyAcadDocument::setWidth, DS.ARGS({ "width:int" }))
        .def("height", &PyAcadDocument::height, DS.ARGS())
        .def("setHeight", &PyAcadDocument::setHeight, DS.ARGS({ "height:int" }))
        .def("activeLayout", &PyAcadDocument::activeLayout, DS.ARGS())
        .def("setActiveLayout", &PyAcadDocument::setActiveLayout, DS.ARGS({ "layout:PyAx.AcadLayout" }))
        .def("sendCommand", &PyAcadDocument::sendCommand, DS.ARGS({ "command:str" }))
        .def("postCommand", &PyAcadDocument::postCommand, DS.ARGS({ "command:str" }))
        .def("HWND", &PyAcadDocument::HWND, DS.ARGS())
        .def("windowTitle", &PyAcadDocument::windowTitle, DS.ARGS())
        .def("startUndoMark", &PyAcadDocument::startUndoMark, DS.ARGS())
        .def("endUndoMark", &PyAcadDocument::endUndoMark, DS.ARGS())
        .def("endUndoMark", &PyAcadDocument::endUndoMark, DS.ARGS())
        .def("database", &PyAcadDocument::database, DS.ARGS())
        .def("activeMaterial", &PyAcadDocument::activeMaterial, DS.ARGS())
        .def("setActiveMaterial", &PyAcadDocument::setActiveMaterial, DS.ARGS({ "material:PyAx.AcadMaterial" }))
        .def("className", &PyAcadDocument::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocument::PyAcadDocument(std::shared_ptr<PyIAcadDocumentImpl> ptr)
    : PyAcadDatabase(ptr)
{
}

PyAcadPlot PyAcadDocument::plot() const
{
    return PyAcadPlot{ impObj()->GetPlot() };
}

PyAcadLayer PyAcadDocument::activeLayer() const
{
    return PyAcadLayer{ impObj()->GetActiveLayer() };
}

void PyAcadDocument::setActiveLayer(const PyAcadLayer& obj) const
{
    impObj()->SetActiveLayer(*obj.impObj());
}

PyAcadLineType PyAcadDocument::activeLinetype() const
{
    return PyAcadLineType{ impObj()->GetActiveLinetype() };
}

void PyAcadDocument::setActiveLinetype(const PyAcadLineType& obj) const
{
    impObj()->SetActiveLinetype(*obj.impObj());
}

PyAcadDimStyle PyAcadDocument::activeDimStyle() const
{
    return PyAcadDimStyle{ impObj()->GetActiveDimStyle() };
}

void PyAcadDocument::setActiveDimStyle(const PyAcadDimStyle& obj) const
{
    impObj()->SetActiveDimStyle(*obj.impObj());
}

PyAcadTextStyle PyAcadDocument::activeTextStyle() const
{
    return PyAcadTextStyle{ impObj()->GetActiveTextStyle() };
}

void PyAcadDocument::setActiveTextStyle(const PyAcadTextStyle& obj) const
{
    impObj()->SetActiveTextStyle(*obj.impObj());
}

PyAcadUCS PyAcadDocument::activeUCS() const
{
    return PyAcadUCS{ impObj()->GetActiveUCS() };
}

void PyAcadDocument::setActiveUCS(const PyAcadUCS& obj) const
{
    impObj()->SetActiveUCS(*obj.impObj());
}

PyAcadViewport PyAcadDocument::activeViewport() const
{
    return PyAcadViewport{ impObj()->GetActiveViewport() };
}

void PyAcadDocument::setActiveViewport(const PyAcadViewport& obj) const
{
    impObj()->SetActiveViewport(*obj.impObj());
}

PyAcadPViewport PyAcadDocument::activePViewport() const
{
    return PyAcadPViewport{ impObj()->GetActivePViewport() };
}

void PyAcadDocument::setActivePViewport(const PyAcadPViewport& obj) const
{
    impObj()->SetActivePViewport(*obj.impObj());
}

PyAcActiveSpace PyAcadDocument::activeSpace() const
{
    return impObj()->GetActiveSpace();
}

void PyAcadDocument::setActiveSpace(PyAcActiveSpace sp) const
{
    impObj()->SetActiveSpace(sp);
}

PyAcadSelectionSets PyAcadDocument::selectionSets() const
{
    return PyAcadSelectionSets{ impObj()->GetSelectionSets() };
}

PyAcadSelectionSet PyAcadDocument::activeSelectionSet() const
{
    return PyAcadSelectionSet{ impObj()->GetActiveSelectionSet() };
}

std::string PyAcadDocument::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

std::string PyAcadDocument::fullName() const
{
    return wstr_to_utf8(impObj()->GetFullName());
}

std::string PyAcadDocument::path() const
{
    return wstr_to_utf8(impObj()->GetPath());
}

bool PyAcadDocument::objectSnapMode() const
{
    return impObj()->GetObjectSnapMode();
}

void PyAcadDocument::setObjectSnapMode(bool flag) const
{
    impObj()->SetObjectSnapMode(flag);
}

bool PyAcadDocument::isReadOnly() const
{
    return impObj()->GetReadOnly();
}

bool PyAcadDocument::isSaved() const
{
    return impObj()->GetSaved();
}

bool PyAcadDocument::mSpace() const
{
    return impObj()->GetMSpace();
}

void PyAcadDocument::setMSpace(bool flag) const
{
    impObj()->SetMSpace(flag);
}

PyAcadUtility PyAcadDocument::utility() const
{
    return PyAcadUtility{ impObj()->GetUtility() };
}

PyAcadDocument PyAcadDocument::open(const std::string& path) const
{
    return PyAcadDocument{ impObj()->Open(utf8_to_wstr(path).c_str()) };
}

void PyAcadDocument::auditInfo(bool flag) const
{
    impObj()->AuditInfo(flag);
}

PyAcadBlockReference PyAcadDocument::importFile(const std::string& path, const AcGePoint3d& InsertionPoint, double scaleFactor) const
{
    return PyAcadBlockReference{ impObj()->Import(utf8_to_wstr(path).c_str(),InsertionPoint,scaleFactor) };
}

void PyAcadDocument::exportToFile(const std::string& fileName, const std::string& extension, const PyAcadSelectionSet& sset) const
{
    impObj()->Export(utf8_to_wstr(fileName).c_str(), utf8_to_wstr(extension).c_str(), *sset.impObj());
}

PyAcadDocument PyAcadDocument::newDoc(const std::string& path) const
{
    return PyAcadDocument{ impObj()->New(utf8_to_wstr(path).c_str()) };
}

void PyAcadDocument::save() const
{
    impObj()->Save();
}

void PyAcadDocument::saveAs1(const std::string& fileName) const
{
    impObj()->SaveAs(utf8_to_wstr(fileName).c_str());
}

void PyAcadDocument::saveAs2(const std::string& fileName, PyAcSaveAsType saType) const
{
    impObj()->SaveAs(utf8_to_wstr(fileName).c_str(), saType);
}

void PyAcadDocument::saveAs3(const std::string& fileName, PyAcSaveAsType saType, const PyAcadSecurityParams& pr) const
{
    impObj()->SaveAs(utf8_to_wstr(fileName).c_str(), saType, *pr.impObj());
}

void PyAcadDocument::wblock(const std::string& fileName, const PyAcadSelectionSet& sset) const
{
    impObj()->Wblock(utf8_to_wstr(fileName).c_str(), *sset.impObj());
}

void PyAcadDocument::purgeAll() const
{
    impObj()->PurgeAll();
}

boost::python::object PyAcadDocument::getVariable(const std::string& name) const
{
    const auto& tv = impObj()->GetVariable(utf8_to_wstr(name).c_str());
    switch (tv.code)
    {
        case TypedVariant::kInt16:
        {
            return boost::python::object(std::get<TypedVariant::kInt16>(tv.variant));
        }
        case TypedVariant::kInt32:
        {
            return boost::python::object(std::get<TypedVariant::kInt32>(tv.variant));
        }
        case TypedVariant::kFloat:
        {
            return boost::python::object(std::get<TypedVariant::kFloat>(tv.variant));
        }
        case TypedVariant::kString:
        {
            return boost::python::object(wstr_to_utf8(std::get<TypedVariant::kString>(tv.variant)));
        }
        case TypedVariant::kPoint3d:
        {
            return boost::python::object(std::get<TypedVariant::kPoint3d>(tv.variant));
        }
        default:
        {
            acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
            break;
        }
    }
    return boost::python::object{};
}

void PyAcadDocument::setVariable(const std::string& name, const boost::python::object& src) const
{
    PyAutoLockGIL lock;
    TypedVariant buf;
    const CString asSym = utf8_to_wstr(name).c_str();
    if (PyLong_Check(src.ptr()))
    {
        const int val = extract<int32_t>(src);
        if (val <= SHRT_MAX)
        {
            buf.code = TypedVariant::kInt16;
            buf.variant = int16_t(val);
        }
        else
        {
            buf.code = TypedVariant::kInt32;
            buf.variant = int32_t(val);
        }
    }
    else if (PyFloat_Check(src.ptr()))
    {
        const double val = extract<double>(src);
        buf.code = TypedVariant::kFloat;
        buf.variant = val;
    }
    else if (extract<AcGePoint2d>(src).check())
    {
        const AcGePoint2d val = extract<AcGePoint2d>(src);
        buf.code = TypedVariant::kPoint3d;
        buf.variant = AcGePoint3d{ val.x, val.y, 0 };
    }
    else if (extract<AcGePoint3d>(src).check())
    {
        const AcGePoint3d val = extract<AcGePoint3d>(src);
        buf.code = TypedVariant::kPoint3d;
        buf.variant = val;
    }
    else if (extract<char*>(src).check())
    {
        buf.code = TypedVariant::kString;
        buf.variant = utf8_to_wstr(extract<char*>(src));
    }
    else
    {
        PyThrowBadEs(Acad::eInvalidInput);
    }
    impObj()->SetVariable(asSym, buf);
}

void PyAcadDocument::loadShapeFile(const std::string& name) const
{
    impObj()->LoadShapeFile(utf8_to_wstr(name).c_str());
}

void PyAcadDocument::regen(PyAcRegenType rt) const
{
    impObj()->Regen(rt);
}

PyAcadSelectionSet PyAcadDocument::pickfirstSelectionSet() const
{
    return PyAcadSelectionSet{ impObj()->GetPickfirstSelectionSet() };
}

bool PyAcadDocument::isActive() const
{
    return impObj()->IsActive();
}

void PyAcadDocument::activate() const
{
    impObj()->Activate();
}

PyAcadDatabase PyAcadDocument::database() const
{
    return PyAcadDatabase{ impObj()->GetDatabase() };
}

PyAcadMaterial PyAcadDocument::activeMaterial() const
{
    return PyAcadMaterial{ impObj()->GetActiveMaterial() };
}

void PyAcadDocument::setActiveMaterial(const PyAcadMaterial& val) const
{
    impObj()->SetActiveMaterial(*val.impObj());
}

void PyAcadDocument::close1() const
{
    impObj()->Close();
}

void PyAcadDocument::close2(bool saveChanges) const
{
    impObj()->Close(saveChanges);
}

void PyAcadDocument::close3(bool saveChanges, const std::string& fileName) const
{
    impObj()->Close(saveChanges, utf8_to_wstr(fileName).c_str());
}

PyAcWindowState PyAcadDocument::windowState() const
{
    return impObj()->GetWindowState();
}

void PyAcadDocument::setWindowState(PyAcWindowState val) const
{
    impObj()->SetWindowState(val);
}

int PyAcadDocument::width() const
{
    return impObj()->GetWidth();
}

void PyAcadDocument::setWidth(int val) const
{
    impObj()->SetWidth(val);
}

int PyAcadDocument::height() const
{
    return impObj()->GetHeight();
}

void PyAcadDocument::setHeight(int val) const
{
    impObj()->SetHeight(val);
}

PyAcadLayout PyAcadDocument::activeLayout() const
{
    return PyAcadLayout{ impObj()->GetActiveLayout() };
}

void PyAcadDocument::setActiveLayout(const PyAcadLayout& val) const
{
    impObj()->SetActiveLayout(*val.impObj());
}

void PyAcadDocument::sendCommand(const std::string& cmd) const
{
    impObj()->SendCommand(utf8_to_wstr(cmd).c_str());
}

void PyAcadDocument::postCommand(const std::string& cmd) const
{
    impObj()->PostCommand(utf8_to_wstr(cmd).c_str());
}

LONG_PTR PyAcadDocument::HWND() const
{
    return impObj()->GetHWND();
}

std::string PyAcadDocument::windowTitle() const
{
    return wstr_to_utf8(impObj()->GetWindowTitle());
}

void PyAcadDocument::startUndoMark() const
{
    impObj()->StartUndoMark();
}

void PyAcadDocument::endUndoMark() const
{
    impObj()->EndUndoMark();
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

//----------------------------------------------------------------------------------------
//PyAcadUtility
void makePyAcadUtilityWrapper()
{
    constexpr const std::string_view getAngleOverloads = "Overloads:\n"
        "- prompt: str\n"
        "- basePoint:PyGe.Point3d, prompt: str\n";

    constexpr const std::string_view getPointOverloads = "Overloads:\n"
        "- prompt: str\n"
        "- basePoint:PyGe.Point3d, prompt: str\n";

    PyDocString DS("AcadUtility");
    class_<PyAcadUtility>("AcadUtility", boost::python::no_init)
        .def("angleToReal", &PyAcadUtility::angleToReal, DS.ARGS({ "angle:str","unit:PyAx.AcAngleUnits" }))
        .def("angleToString", &PyAcadUtility::angleToString, DS.ARGS({ "angle:float","unit:PyAx.AcAngleUnits","precision:int" }))
        .def("distanceToReal", &PyAcadUtility::distanceToReal, DS.ARGS({ "dist:str","unit:PyAx.AcAngleUnits" }))
        .def("realToString", &PyAcadUtility::realToString, DS.ARGS({ "real:str","unit:PyAx.AcAngleUnits" }))
        .def("translateCoordinates", &PyAcadUtility::translateCoordinates1)
        .def("translateCoordinates", &PyAcadUtility::translateCoordinates2)
        .def("initializeUserInput", &PyAcadUtility::initializeUserInput, DS.ARGS({ "bits:int","keyWordList:str" }))
        .def("getInteger", &PyAcadUtility::getInteger, DS.ARGS({ "prompt:str" }))
        .def("getReal", &PyAcadUtility::getReal, DS.ARGS({ "prompt:str" }))
        .def("getInput", &PyAcadUtility::getInput, DS.ARGS())
        .def("getKeyword", &PyAcadUtility::getKeyword, DS.ARGS({ "prompt:str" }))
        .def("getString", &PyAcadUtility::getString, DS.ARGS({ "hasSpaces:int", "prompt:str" }))
        .def("getAngle", &PyAcadUtility::getAngle1)
        .def("getAngle", &PyAcadUtility::getAngle2, DS.OVRL(getAngleOverloads))
        .def("angleFromXAxis", &PyAcadUtility::angleFromXAxis, DS.ARGS({ "startPoint:PyGe.Point3d","endPoint:PyGe.Point3d" }))
        .def("getCorner", &PyAcadUtility::getCorner, DS.ARGS({ "point:PyGe.Point3d","prompt:str" }))
        .def("getDistance", &PyAcadUtility::getDistance, DS.ARGS({ "point:PyGe.Point3d","prompt:str" }))
        .def("getOrientation", &PyAcadUtility::getOrientation, DS.ARGS({ "point:PyGe.Point3d","prompt:str" }))
        .def("getPoint", &PyAcadUtility::getPoint1)
        .def("getPoint", &PyAcadUtility::getPoint2, DS.OVRL(getPointOverloads))
        .def("polarPoint", &PyAcadUtility::polarPoint, DS.ARGS({ "point:PyGe.Point3d","angle:float","distance:float" }))
        .def("getEntity", &PyAcadUtility::getEntity, DS.ARGS({ "prompt:str" }))
        .def("prompt", &PyAcadUtility::prompt, DS.ARGS({ "prompt:str" }))
        .def("getSubEntity", &PyAcadUtility::getSubEntity, DS.ARGS({ "prompt:str" }))
        .def("isURL", &PyAcadUtility::isURL, DS.ARGS({ "URL:str" }))
        .def("getRemoteFile", &PyAcadUtility::getRemoteFile, DS.ARGS({ "URL:str","ignoreCache:bool" }))
        .def("isRemoteFile", &PyAcadUtility::putRemoteFile, DS.ARGS({ "localFile:str" }))
        .def("launchBrowserDialog", &PyAcadUtility::launchBrowserDialog, DS.ARGS({ "title:str","caption:str","URL:str","regkey:str","bnEnabled:bool" }))
        .def("putRemoteFile", &PyAcadUtility::putRemoteFile, DS.ARGS({ "URL:str","localFile:str" }))
        .def("sendModelessOperationStart", &PyAcadUtility::sendModelessOperationStart, DS.ARGS({ "context:str" }))
        .def("sendModelessOperationEnded", &PyAcadUtility::sendModelessOperationEnded, DS.ARGS({ "context:str" }))
        .def("getObjectIdString", &PyAcadUtility::getObjectIdString, DS.ARGS({ "obj:PyAx.AcadEntity","bHex:bool" }))
        .def("className", &PyAcadUtility::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadUtility::PyAcadUtility(std::shared_ptr<PyIAcadUtilityImpl> ptr)
    : m_pyImp(ptr)
{
}

double PyAcadUtility::angleToReal(const std::string& angle, PyAcAngleUnits unit) const
{
    return impObj()->AngleToReal(utf8_to_wstr(angle).c_str(), unit);
}

std::string PyAcadUtility::angleToString(double angle, PyAcAngleUnits unit, int precision) const
{
    return wstr_to_utf8(impObj()->AngleToString(angle, unit, precision));
}

double PyAcadUtility::distanceToReal(const std::string& dist, PyAcUnits unit) const
{
    return impObj()->DistanceToReal(utf8_to_wstr(dist).c_str(), unit);
}

std::string PyAcadUtility::realToString(double angle, PyAcUnits unit, int precision) const
{
    return wstr_to_utf8(impObj()->RealToString(angle, unit, precision));
}

AcGePoint3d PyAcadUtility::translateCoordinates1(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement) const
{
    return impObj()->TranslateCoordinates(point, fromCoordSystem, toCoordSystem, displacement);
}

AcGePoint3d PyAcadUtility::translateCoordinates2(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement, const AcGeVector3d& normal) const
{
    return impObj()->TranslateCoordinates(point, fromCoordSystem, toCoordSystem, displacement, normal);
}

void PyAcadUtility::initializeUserInput(int bits, const std::string& keyWordList) const
{
    impObj()->InitializeUserInput(bits, utf8_to_wstr(keyWordList).c_str());
}

int PyAcadUtility::getInteger(const std::string& prompt) const
{
    return impObj()->GetInteger(utf8_to_wstr(prompt).c_str());
}

double PyAcadUtility::getReal(const std::string& prompt) const
{
    return impObj()->GetReal(utf8_to_wstr(prompt).c_str());
}

std::string PyAcadUtility::getInput() const
{
    return wstr_to_utf8(impObj()->GetInput());
}

std::string PyAcadUtility::getKeyword(const std::string& prompt) const
{
    return wstr_to_utf8(impObj()->GetKeyword(utf8_to_wstr(prompt).c_str()));
}

std::string PyAcadUtility::getString(int hasSpaces, const std::string& prompt) const
{
    return wstr_to_utf8(impObj()->GetString(hasSpaces, utf8_to_wstr(prompt).c_str()));
}

double PyAcadUtility::getAngle1(const std::string& prompt) const
{
    return impObj()->GetAngle(utf8_to_wstr(prompt).c_str());
}

double PyAcadUtility::getAngle2(const AcGePoint3d& point, const std::string& prompt) const
{
    return impObj()->GetAngle(point, utf8_to_wstr(prompt).c_str());
}

double PyAcadUtility::angleFromXAxis(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint) const
{
    return impObj()->AngleFromXAxis(startPoint, endPoint);
}

AcGePoint3d PyAcadUtility::getCorner(const AcGePoint3d& point, const std::string& prompt) const
{
    return impObj()->GetCorner(point, utf8_to_wstr(prompt).c_str());
}

double PyAcadUtility::getDistance(const AcGePoint3d& point, const std::string& prompt) const
{
    return impObj()->GetDistance(point, utf8_to_wstr(prompt).c_str());
}

double PyAcadUtility::getOrientation(const AcGePoint3d& point, const std::string& prompt) const
{
    return impObj()->GetOrientation(point, utf8_to_wstr(prompt).c_str());
}

AcGePoint3d PyAcadUtility::getPoint1(const std::string& prompt) const
{
    return impObj()->GetPoint(utf8_to_wstr(prompt).c_str());
}

AcGePoint3d PyAcadUtility::getPoint2(const AcGePoint3d& point, const std::string& prompt) const
{
    return impObj()->GetPoint(point, utf8_to_wstr(prompt).c_str());
}

AcGePoint3d PyAcadUtility::polarPoint(const AcGePoint3d& point, double angle, double distance) const
{
    return impObj()->PolarPoint(point, angle, distance);
}

boost::python::tuple PyAcadUtility::getEntity(const std::string& prompt) const
{
    PyAutoLockGIL lock;
    AcGePoint3d hitpoint;
    PyAcadEntity ent{ impObj()->GetEntity(utf8_to_wstr(prompt).c_str(),hitpoint) };
    return boost::python::make_tuple(ent, hitpoint);
}

void PyAcadUtility::prompt(const std::string& prompt) const
{
    return impObj()->Prompt(utf8_to_wstr(prompt).c_str());
}

boost::python::tuple PyAcadUtility::getSubEntity(const std::string& prompt) const
{
    PyAutoLockGIL lock;
    AcGePoint3d hp;
    AcGeMatrix3d xf;
    std::vector<AcDbObjectId> ids;
    PyAcadEntity ent{ impObj()->GetSubEntity(utf8_to_wstr(prompt).c_str(), hp, xf, ids) };
    boost::python::list idlist;
    for (const auto& id : ids)
        idlist.append(PyDbObjectId{ id });
    return boost::python::make_tuple(ent, hp, xf, idlist);
}

bool PyAcadUtility::isURL(const std::string& URL) const
{
    return impObj()->IsURL(utf8_to_wstr(URL).c_str());
}

std::string PyAcadUtility::getRemoteFile(const std::string& URL, bool ignoreCache) const
{
    return wstr_to_utf8(impObj()->GetRemoteFile(utf8_to_wstr(URL).c_str(), ignoreCache));
}

void PyAcadUtility::putRemoteFile(const std::string& URL, const std::string& localFile) const
{
    return impObj()->PutRemoteFile(utf8_to_wstr(URL).c_str(), utf8_to_wstr(localFile).c_str());
}

boost::python::tuple PyAcadUtility::isRemoteFile(const std::string& localFile) const
{
    CString URL;
    bool flag = impObj()->IsRemoteFile(utf8_to_wstr(localFile).c_str(), URL);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(flag, wstr_to_utf8(URL));
}

boost::python::tuple PyAcadUtility::launchBrowserDialog(const std::string& title, const std::string& caption, const std::string& URL, const std::string& regkey, bool bnEnabled) const
{
    CString selectedURL;
    bool flag = impObj()->LaunchBrowserDialog(utf8_to_wstr(title).c_str(), utf8_to_wstr(caption).c_str(), utf8_to_wstr(URL).c_str(), utf8_to_wstr(regkey).c_str(), bnEnabled, selectedURL);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(flag, wstr_to_utf8(selectedURL));
}

void PyAcadUtility::sendModelessOperationStart(const std::string& context) const
{
    impObj()->SendModelessOperationStart(utf8_to_wstr(context).c_str());
}

void PyAcadUtility::sendModelessOperationEnded(const std::string& context) const
{
    impObj()->SendModelessOperationEnded(utf8_to_wstr(context).c_str());
}

std::string PyAcadUtility::getObjectIdString(const PyAcadEntity& obj, bool bHex) const
{
    return wstr_to_utf8(impObj()->GetObjectIdString(*obj.impObj(), bHex));
}

std::string PyAcadUtility::className()
{
    return "AcadUtility";
}

PyIAcadUtilityImpl* PyAcadUtility::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadUtilityImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSecurityParams
void makePyAcadSecurityParamsWrapper()
{
    PyDocString DS("AcadSecurityParams");
    class_<PyAcadSecurityParams>("AcadSecurityParams", boost::python::no_init)
        .def("className", &PyAcadSecurityParams::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSecurityParams::PyAcadSecurityParams(std::shared_ptr<PyIAcadSecurityParamsImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadSecurityParams::className()
{
    return "AcadSecurityParams";
}

PyIAcadSecurityParamsImpl* PyAcadSecurityParams::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSecurityParamsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSelectionSet
void makePyAcadSelectionSetWrapper()
{
    PyDocString DS("AcadSelectionSet");
    class_<PyAcadSelectionSet>("AcadSelectionSet", boost::python::no_init)
        .def("count", &PyAcadSelectionSet::count, DS.ARGS())
        .def("delete", &PyAcadSelectionSet::_delete, DS.ARGS())
        .def("item", &PyAcadSelectionSet::item, DS.ARGS({ "index:int" }))
        .def("name", &PyAcadSelectionSet::name, DS.ARGS())
        .def("highlight", &PyAcadSelectionSet::highlight, DS.ARGS({ "bHighlight:bool" }))
        .def("update", &PyAcadSelectionSet::update, DS.ARGS())
        .def("addItems", &PyAcadSelectionSet::addItems, DS.ARGS({ "entities:Collection[PyAx.AcadEntity]" }))
        .def("removeItems", &PyAcadSelectionSet::removeItems, DS.ARGS({ "entities:Collection[PyAx.AcadEntity]" }))
        .def("clear", &PyAcadSelectionSet::clear, DS.ARGS())
        .def("entities", &PyAcadSelectionSet::entities, DS.ARGS())
        .def("selectAll", &PyAcadSelectionSet::selectAll1)
        .def("selectAll", &PyAcadSelectionSet::selectAll2, DS.ARGS({ "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectOnScreen", &PyAcadSelectionSet::selectOnScreen1)
        .def("selectOnScreen", &PyAcadSelectionSet::selectOnScreen2, DS.ARGS({ "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectWindow", &PyAcadSelectionSet::selectWindow1)
        .def("selectWindow", &PyAcadSelectionSet::selectWindow2, DS.ARGS({ "pt1:PyGe.Point3d", "pt2:PyGe.Point3d", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectCrossing", &PyAcadSelectionSet::selectCrossing1)
        .def("selectCrossing", &PyAcadSelectionSet::selectCrossing2, DS.ARGS({ "pt1:PyGe.Point3d", "pt2:PyGe.Point3d", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectFence", &PyAcadSelectionSet::selectFence1)
        .def("selectFence", &PyAcadSelectionSet::selectFence2, DS.ARGS({ "pts:Collection[PyGe.Point3d]", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectWindowPolygon", &PyAcadSelectionSet::selectWindowPolygon1)
        .def("selectWindowPolygon", &PyAcadSelectionSet::selectWindowPolygon2, DS.ARGS({ "pts:Collection[PyGe.Point3d]", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectCrossingPolygon", &PyAcadSelectionSet::selectCrossingPolygon1)
        .def("selectCrossingPolygon", &PyAcadSelectionSet::selectCrossingPolygon2, DS.ARGS({ "pts:Collection[PyGe.Point3d]", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("selectLast", &PyAcadSelectionSet::selectLast, DS.ARGS())
        .def("selectAtPoint", &PyAcadSelectionSet::selectAtPoint1)
        .def("selectAtPoint", &PyAcadSelectionSet::selectAtPoint2, DS.ARGS({ "pt1:PyGe.Point3d", "filter:Collection[tuple[int,Any]] = ..." }))
        .def("__getitem__", &PyAcadSelectionSet::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadSelectionSet::begin, &PyAcadSelectionSet::end))
        .def("className", &PyAcadSelectionSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSelectionSet::PyAcadSelectionSet(std::shared_ptr<PyIAcadSelectionSetImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadSelectionSet::count() const
{
    return impObj()->GetCount();
}

PyAcadEntity PyAcadSelectionSet::item(long ind) const
{
    return PyAcadEntity{ impObj()->GetItem(ind) };
}

void PyAcadSelectionSet::_delete() const
{
    impObj()->Delete();
}

std::string PyAcadSelectionSet::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadSelectionSet::highlight(bool flag) const
{
    impObj()->Highlight(flag);
}

void PyAcadSelectionSet::erase() const
{
    impObj()->Erase();
}

void PyAcadSelectionSet::update() const
{
    impObj()->Update();
}

void PyAcadSelectionSet::addItems(const boost::python::object& pyents) const
{
    std::vector<PyIAcadEntityImpl> ients;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ients.emplace_back(*item.impObj());
    impObj()->AddItems(ients);
}

void PyAcadSelectionSet::removeItems(const boost::python::object& pyents) const
{
    std::vector<PyIAcadEntityImpl> ients;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ients.emplace_back(*item.impObj());
    impObj()->RemoveItems(ients);
}

void PyAcadSelectionSet::clear() const
{
    impObj()->Clear();
}

boost::python::list PyAcadSelectionSet::entities() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

static void buildFilter(TypedVariants& tvs, const boost::python::object& filter)
{
    size_t listSize = boost::python::len(filter);
    for (size_t idx = 0; idx < listSize; idx++)
    {
        tuple tpl = extract<tuple>(filter[idx]);
        if (boost::python::len(tpl) != 2)
            throw PyErrorStatusException(Acad::eInvalidInput);

        int16_t code = static_cast<int16_t>(extract<int>(tpl[0]));
        switch (acdbGroupCodeToType(code))
        {
            case AcDb::kDwgText:
            {
                tvs.emplace_back(TypedVariant{ code, utf8_to_wstr(extract<char*>(tpl[1])) });
                break;
            }
            case AcDb::kDwgInt16:
            {
                tvs.emplace_back(TypedVariant{ code,  static_cast<int16_t>(extract<int>(tpl[1])) });
                break;
            }
            case AcDb::kDwgInt32:
            {
                tvs.emplace_back(TypedVariant{ code,  static_cast<int32_t>(extract<int>(tpl[1])) });
                break;
            }
            case AcDb::kDwgReal:
            {
                tvs.emplace_back(TypedVariant{ code, extract<double>(tpl[1]) });
                break;
            }
            case AcDb::kDwg3Real:
            {
                tvs.emplace_back(TypedVariant{ code, extract<AcGePoint3d>(tpl[1]) });
                break;
            }
            default:
            {
                PyThrowBadEs(eInvalidInput);
                break;
            }
        }
    }
}

void PyAcadSelectionSet::selectAll1() const
{
    TypedVariants tvs;
    impObj()->SelectAll(tvs);
}

void PyAcadSelectionSet::selectAll2(const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectAll(tvs);
}

void PyAcadSelectionSet::selectOnScreen1() const
{
    TypedVariants tvs;
    impObj()->SelectOnScreen(tvs);
}

void PyAcadSelectionSet::selectOnScreen2(const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectOnScreen(tvs);
}

void PyAcadSelectionSet::selectLast() const
{
    impObj()->SelectLast();
}

void PyAcadSelectionSet::selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2) const
{
    TypedVariants tvs;
    impObj()->SelectWindow(pt1, pt2, tvs);
}

void PyAcadSelectionSet::selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectWindow(pt1, pt2, tvs);
}

void PyAcadSelectionSet::selectCrossing1(const AcGePoint3d& pt1, const AcGePoint3d& pt2) const
{
    TypedVariants tvs;
    impObj()->SelectCrossing(pt1, pt2, tvs);
}

void PyAcadSelectionSet::selectCrossing2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectCrossing(pt1, pt2, tvs);
}

void PyAcadSelectionSet::selectFence1(const boost::python::object& points) const
{
    TypedVariants tvs;
    impObj()->SelectFence(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectFence2(const boost::python::object& points, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectFence(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectWindowPolygon1(const boost::python::object& points) const
{
    TypedVariants tvs;
    impObj()->SelectWindowPolygon(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectWindowPolygon2(const boost::python::object& points, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectWindowPolygon(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectCrossingPolygon1(const boost::python::object& points) const
{
    TypedVariants tvs;
    impObj()->SelectCrossingPolygon(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectCrossingPolygon2(const boost::python::object& points, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectCrossingPolygon(py_list_to_std_vector<AcGePoint3d>(points), tvs);
}

void PyAcadSelectionSet::selectAtPoint1(const AcGePoint3d& pt1) const
{
    TypedVariants tvs;
    impObj()->SelectAtPoint(pt1, tvs);
}

void PyAcadSelectionSet::selectAtPoint2(const AcGePoint3d& pt1, const boost::python::object& filter) const
{
    TypedVariants tvs;
    buildFilter(tvs, filter);
    impObj()->SelectAtPoint(pt1, tvs);
}

std::string PyAcadSelectionSet::className()
{
    return "AcadSelectionSet";
}

PyIAcadSelectionSetImpl* PyAcadSelectionSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSelectionSetImpl*>(m_pyImp.get());
}


void PyAcadSelectionSet::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadEntity{ item });
}

std::vector<PyAcadEntity>::iterator PyAcadSelectionSet::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadEntity>::iterator PyAcadSelectionSet::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyAcadSelectionSets
void makePyAcadSelectionSetsWrapper()
{
    PyDocString DS("AcadSelectionSets");
    class_<PyAcadSelectionSets>("AcadSelectionSets", boost::python::no_init)

        .def("count", &PyAcadSelectionSets::count, DS.ARGS())
        .def("add", &PyAcadSelectionSets::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadSelectionSets::item, DS.ARGS({ "index: int" }))
        .def("__getitem__", &PyAcadSelectionSets::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadSelectionSets::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSelectionSets::PyAcadSelectionSets(std::shared_ptr<PyIAcadSelectionSetsImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadSelectionSets::count() const
{
    return impObj()->GetCount();
}

PyAcadSelectionSet PyAcadSelectionSets::add(const std::string& name) const
{
    return PyAcadSelectionSet{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

PyAcadSelectionSet PyAcadSelectionSets::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadSelectionSet{ impObj()->GetItem(index) };
}

std::string PyAcadSelectionSets::className()
{
    return "AcadSelectionSets";
}

PyIAcadSelectionSetsImpl* PyAcadSelectionSets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSelectionSetsImpl*>(m_pyImp.get());
}
