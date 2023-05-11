#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyCmColorBase.h"
#include "PyGePlane.h"
using namespace boost::python;
//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcDbEntityWrapper()
{
    class_<PyDbEntity, bases<PyDbObject>>("Entity", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockId", &PyDbEntity::blockId)
        .def("color", &PyDbEntity::color)
        .def("setColor", &PyDbEntity::setColor)
        .def("colorIndex", &PyDbEntity::colorIndex)
        .def("setColorIndex", &PyDbEntity::setColorIndex1)
        .def("setColorIndex", &PyDbEntity::setColorIndex2)
        .def("entityColor", &PyDbEntity::entityColor)
        .def("layer", &PyDbEntity::layer)
        .def("layerId", &PyDbEntity::layerId)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, bool, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, bool, bool)>("setLayer", &PyDbEntity::setLayer)
        .def("plotStyleName", &PyDbEntity::plotStyleName)
        .def("getPlotStyleNameId", &PyDbEntity::getPlotStyleNameId)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, Adesk::Boolean)>("setPlotStyleName", &PyDbEntity::setPlotStyleName)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::PlotStyleNameType, Adesk::Boolean)>("setPlotStyleName", &PyDbEntity::setPlotStyleName)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::PlotStyleNameType, const PyDbObjectId&, Adesk::Boolean)>("setPlotStyleName", &PyDbEntity::setPlotStyleName)
        .def("linetype", &PyDbEntity::linetype)
        .def("linetypeId", &PyDbEntity::linetypeId)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&)>("setLinetype", &PyDbEntity::setLinetype)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, Adesk::Boolean)>("setLinetype", &PyDbEntity::setLinetype)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&)>("setLinetype", &PyDbEntity::setLinetype)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, Adesk::Boolean)>("setLinetype", &PyDbEntity::setLinetype)
        .def("material", &PyDbEntity::material)
        .def("materialId", &PyDbEntity::materialId)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&)>("setMaterial", &PyDbEntity::setMaterial)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, Adesk::Boolean)>("setMaterial", &PyDbEntity::setMaterial)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&)>("setMaterial", &PyDbEntity::setMaterial)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, Adesk::Boolean)>("setMaterial", &PyDbEntity::setMaterial)
        .def("linetypeScale", &PyDbEntity::linetypeScale)
        .def<Acad::ErrorStatus(PyDbEntity::*)(double)>("setLinetypeScale", &PyDbEntity::setLinetypeScale)
        .def<Acad::ErrorStatus(PyDbEntity::*)(double, Adesk::Boolean)>("setLinetypeScale", &PyDbEntity::setLinetypeScale)
        .def("visibility", &PyDbEntity::visibility)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::Visibility)>("setVisibility", &PyDbEntity::setVisibility)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::Visibility, Adesk::Boolean)>("setVisibility", &PyDbEntity::setVisibility)
        .def("lineWeight", &PyDbEntity::lineWeight)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::LineWeight)>("setLineWeight", &PyDbEntity::setLineWeight)
        .def<Acad::ErrorStatus(PyDbEntity::*)(AcDb::LineWeight, Adesk::Boolean)>("setLineWeight", &PyDbEntity::setLineWeight)
        .def("collisionType", &PyDbEntity::collisionType)
        .def("castShadows", &PyDbEntity::castShadows)
        .def("setCastShadows", &PyDbEntity::setCastShadows)
        .def("receiveShadows", &PyDbEntity::receiveShadows)
        .def("setReceiveShadows", &PyDbEntity::setReceiveShadows)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbEntity&)>("setPropertiesFrom", &PyDbEntity::setPropertiesFrom)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbEntity&, Adesk::Boolean)>("setPropertiesFrom", &PyDbEntity::setPropertiesFrom)
        .def("isPlanar", &PyDbEntity::isPlanar)
        .def("getPlane", &PyDbEntity::getPlane)
        .def("getEcs", &PyDbEntity::getEcs)
        .def("list", &PyDbEntity::list)
        .def("transformBy", &PyDbEntity::transformBy)
        .def("recordGraphicsModified", &PyDbEntity::recordGraphicsModified)
        .def("recordGraphicsModified", &PyDbEntity::recordGraphicsModified)
        .def<void(PyDbEntity::*)(void)>("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults)
        .def<void(PyDbEntity::*)(const PyDbDatabase&)>("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults)
        .def("getCompoundObjectTransform", &PyDbEntity::getCompoundObjectTransform)//TODO: add test for out param
        .def("getGeomExtents", &PyDbEntity::getGeomExtents)//TODO: add test for out param
        .def("draw", &PyDbEntity::draw)
        .def("className", &PyDbEntity::className).staticmethod("className")
        .def("desc", &PyDbEntity::desc).staticmethod("desc")
        ;
}

//----------------------------------------------------------------------------------------------------
//PyDbEntity
PyDbEntity::PyDbEntity(AcDbEntity* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbEntity::PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbEntity* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbEntity>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbEntity::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

AcCmColor PyDbEntity::color() const
{
    return impObj()->color();
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal, bool doSubents)
{
    return this->setLayer(newVal, doSubents, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal, bool doSubents, bool allowHiddenLayer)
{
    return impObj()->setLayer(utf8_to_wstr(newVal).c_str(), doSubents, allowHiddenLayer);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal, bool doSubents)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer)
{
    return impObj()->setLayer(newVal.m_id, doSubents, allowHiddenLayer);
}

std::string PyDbEntity::plotStyleName() const
{
    AcString str;
#ifdef BRXAPP
    return  wstr_to_utf8(impObj()->plotStyleName());
#else
    impObj()->plotStyleName(str);
    return wstr_to_utf8(str);
#endif // BRXAPP
}

PyDbObjectId PyDbEntity::getPlotStyleNameId() const
{
    AcDbObjectId id;
    impObj()->getPlotStyleNameId(id);
    return PyDbObjectId(id);
}

Acad::ErrorStatus PyDbEntity::setColor(const AcCmColor& color, bool doSubents, PyDbDatabase& db)
{
    return impObj()->setColor(color, doSubents, db.impObj());
}

Adesk::UInt16 PyDbEntity::colorIndex() const
{
    return impObj()->colorIndex();
}

Acad::ErrorStatus PyDbEntity::setColorIndex1(Adesk::UInt16 color)
{
    return impObj()->setColorIndex(color);
}

Acad::ErrorStatus PyDbEntity::setColorIndex2(Adesk::UInt16 color, Adesk::Boolean doSubents)
{
    return impObj()->setColorIndex(color, doSubents);
}

AcCmEntityColor PyDbEntity::entityColor() const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbEntity::transparency() const
{
    return impObj()->transparency();
}

Acad::ErrorStatus PyDbEntity::setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents /*= true*/)
{
    return impObj()->setTransparency(trans, doSubents);
}

std::string PyDbEntity::layer() const
{
    return  wstr_to_utf8(impObj()->layer());
}

PyDbObjectId PyDbEntity::layerId() const
{
    return  PyDbObjectId(impObj()->layerId());
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(const std::string& str, Adesk::Boolean doSubents)
{
    return impObj()->setPlotStyleName(utf8_to_wstr(str).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(AcDb::PlotStyleNameType tp, Adesk::Boolean doSubents)
{
    return impObj()->setPlotStyleName(tp, AcDbObjectId::kNull, doSubents);
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(AcDb::PlotStyleNameType tp, const PyDbObjectId& newId, Adesk::Boolean doSubents)
{
    return impObj()->setPlotStyleName(tp, newId.m_id, doSubents);
}

std::string PyDbEntity::linetype() const
{
    return  wstr_to_utf8(impObj()->linetype());
}

PyDbObjectId PyDbEntity::linetypeId() const
{
    return  PyDbObjectId(impObj()->linetypeId());
}

Acad::ErrorStatus PyDbEntity::setLinetype(const std::string& newVal)
{
    return impObj()->setLinetype(utf8_to_wstr(newVal).c_str());
}

Acad::ErrorStatus PyDbEntity::setLinetype(const std::string& newVal, Adesk::Boolean doSubents)
{
    return impObj()->setLinetype(utf8_to_wstr(newVal).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setLinetype(const PyDbObjectId& newVal)
{
    return impObj()->setLinetype(newVal.m_id);
}

Acad::ErrorStatus PyDbEntity::setLinetype(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
{
    return impObj()->setLinetype(newVal.m_id, doSubents);
}

std::string PyDbEntity::material() const
{
    return  wstr_to_utf8(impObj()->material());
}

PyDbObjectId PyDbEntity::materialId() const
{
    return  PyDbObjectId(impObj()->materialId());
}

Acad::ErrorStatus PyDbEntity::setMaterial(const std::string& newVal)
{
    return impObj()->setMaterial(utf8_to_wstr(newVal).c_str());
}

Acad::ErrorStatus PyDbEntity::setMaterial(const std::string& newVal, Adesk::Boolean doSubents)
{
    return impObj()->setMaterial(utf8_to_wstr(newVal).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setMaterial(const PyDbObjectId& newVal)
{
    return impObj()->setLinetype(newVal.m_id);
}

Acad::ErrorStatus PyDbEntity::setMaterial(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
{
    return impObj()->setLinetype(newVal.m_id, doSubents);
}

double PyDbEntity::linetypeScale() const
{
    return  impObj()->linetypeScale();
}

Acad::ErrorStatus PyDbEntity::setLinetypeScale(double newval)
{
    return  impObj()->setLinetypeScale(newval);
}

Acad::ErrorStatus PyDbEntity::setLinetypeScale(double newval, Adesk::Boolean doSubents)
{
    return  impObj()->setLinetypeScale(newval, doSubents);
}

AcDb::Visibility PyDbEntity::visibility() const
{
    return  impObj()->visibility();
}

Acad::ErrorStatus PyDbEntity::setVisibility(AcDb::Visibility newVal)
{
    return  impObj()->setVisibility(newVal);
}

Acad::ErrorStatus PyDbEntity::setVisibility(AcDb::Visibility newVal, Adesk::Boolean doSubents /*= true*/)
{
    return  impObj()->setVisibility(newVal, doSubents);
}

AcDb::LineWeight PyDbEntity::lineWeight() const
{
    return impObj()->lineWeight();
}

Acad::ErrorStatus PyDbEntity::setLineWeight(AcDb::LineWeight newVal)
{
    return  impObj()->setLineWeight(newVal);
}

Acad::ErrorStatus PyDbEntity::setLineWeight(AcDb::LineWeight newVal, Adesk::Boolean doSubents)
{
    return impObj()->setLineWeight(newVal, doSubents);
}

AcDb::CollisionType PyDbEntity::collisionType() const
{
    return impObj()->collisionType();
}

bool PyDbEntity::castShadows() const
{
    return impObj()->castShadows();
}

void PyDbEntity::setCastShadows(bool newVal)
{
    impObj()->setCastShadows(newVal);
}

bool PyDbEntity::receiveShadows() const
{
    return impObj()->receiveShadows();
}

void PyDbEntity::setReceiveShadows(bool newVal)
{
    impObj()->setReceiveShadows(newVal);
}

Acad::ErrorStatus PyDbEntity::setPropertiesFrom(const PyDbEntity& pEntity)
{
    return impObj()->setPropertiesFrom(pEntity.impObj());
}

Acad::ErrorStatus PyDbEntity::setPropertiesFrom(const PyDbEntity& pEntity, Adesk::Boolean doSubents)
{
    return impObj()->setPropertiesFrom(pEntity.impObj(), doSubents);
}

Adesk::Boolean PyDbEntity::isPlanar() const
{
    return impObj()->isPlanar();
}

PyGePlane PyDbEntity::getPlane() const
{
    AcGePlane plane;
    AcDb::Planarity val;
    if (auto es = impObj()->getPlane(plane, val); es != eOk)
        throw PyAcadErrorStatus(es);
    if (val == AcDb::kNonPlanar)
        throw PyAcadErrorStatus(Acad::eNotApplicable);
    return PyGePlane(plane);
}

void PyDbEntity::getEcs(AcGeMatrix3d& retVal) const
{
    impObj()->getEcs(retVal);
}

void PyDbEntity::list() const
{
    impObj()->list();
}

Acad::ErrorStatus PyDbEntity::transformBy(const AcGeMatrix3d& xform)
{
    return impObj()->transformBy(xform);
}

void PyDbEntity::recordGraphicsModified()
{
    impObj()->recordGraphicsModified();
}

Acad::ErrorStatus PyDbEntity::draw()
{
    return impObj()->draw();
}

void PyDbEntity::setDatabaseDefaults()
{
    impObj()->setDatabaseDefaults();
}

void PyDbEntity::setDatabaseDefaults(const PyDbDatabase& db)
{
    impObj()->setDatabaseDefaults(db.impObj());
}

Acad::ErrorStatus PyDbEntity::getCompoundObjectTransform(AcGeMatrix3d& xMat) const
{
    return impObj()->getCompoundObjectTransform(xMat);
}

Acad::ErrorStatus PyDbEntity::getGeomExtents(AcDbExtents& extents) const
{
    return impObj()->getGeomExtents(extents);
}

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

PyRxClass PyDbEntity::desc()
{
    return PyRxClass(AcDbEntity::desc(), false);
}

AcDbEntity* PyDbEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbEntity*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
void makeAcDbBlockBeginWrapper()
{
    class_<PyDbBlockBegin, bases<PyDbEntity>>("BlockBegin", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockBegin::className).staticmethod("className")
        .def("desc", &PyDbBlockBegin::desc).staticmethod("desc")
        ;
}

PyDbBlockBegin::PyDbBlockBegin(AcDbBlockBegin* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockBegin::PyDbBlockBegin(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBlockBegin* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockBegin>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbBlockBegin::className()
{
    return "AcDbBlockBegin";
}

PyRxClass PyDbBlockBegin::desc()
{
    return PyRxClass(AcDbBlockBegin::desc(), false);
}

AcDbBlockBegin* PyDbBlockBegin::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBlockBegin*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makeAcDbBlockEndWrapper()
{
    class_<PyDbBlockEnd, bases<PyDbEntity>>("BlockEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockEnd::className).staticmethod("className")
        .def("desc", &PyDbBlockEnd::desc).staticmethod("desc")
        ;
}

PyDbBlockEnd::PyDbBlockEnd(AcDbBlockEnd* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockEnd::PyDbBlockEnd(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBlockEnd* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockEnd>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbBlockEnd::className()
{
    return "AcDbBlockEnd";
}

PyRxClass PyDbBlockEnd::desc()
{
    return PyRxClass(AcDbBlockEnd::desc(), false);
}

AcDbBlockEnd* PyDbBlockEnd::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBlockEnd*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makeAcDbSequenceEndWrapper()
{
    class_<PyDbSequenceEnd, bases<PyDbEntity>>("SequenceEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSequenceEnd::className).staticmethod("className")
        .def("desc", &PyDbSequenceEnd::desc).staticmethod("desc")
        ;
}

PyDbSequenceEnd::PyDbSequenceEnd(AcDbSequenceEnd* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbSequenceEnd::PyDbSequenceEnd(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbSequenceEnd* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSequenceEnd>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbSequenceEnd::className()
{
    return "AcDbSequenceEnd";
}

PyRxClass PyDbSequenceEnd::desc()
{
    return PyRxClass(AcDbSequenceEnd::desc(), false);
}

AcDbSequenceEnd* PyDbSequenceEnd::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSequenceEnd*>(m_pImp.get());
}

