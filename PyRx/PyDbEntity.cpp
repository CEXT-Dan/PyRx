#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyCmColorBase.h"
#include "PyGeEntity3d.h"
using namespace boost::python;

//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcDbEntityWrapper()
{
    static auto wrapper = class_<PyDbEntity, bases<PyDbObject>>("DbEntity", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockId", &PyDbEntity::blockId)

        .def("color", &PyDbEntity::color)
        .def("setColor", &PyDbEntity::setColor)

        .def("colorIndex", &PyDbEntity::colorIndex)
        .def("setColorIndex", &PyDbEntity::setColorIndex)

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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbEntity::blockId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockId());
}

AcCmColor PyDbEntity::color() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->color();
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLayer(newVal.m_id, doSubents, allowHiddenLayer);
}

std::string PyDbEntity::plotStyleName() const
{
    AcString str;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
#ifdef BRXAPP
    return  wstr_to_utf8(impObj()->plotStyleName());
#else
    impObj()->plotStyleName(str);
    return wstr_to_utf8(str);
#endif // BRXAPP
}

PyDbObjectId PyDbEntity::getPlotStyleNameId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbObjectId id;
    imp->getPlotStyleNameId(id);
    return PyDbObjectId(id);
}

Acad::ErrorStatus PyDbEntity::setColor(const AcCmColor& color, bool doSubents, PyDbDatabase& db)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setColor(color, doSubents, db.impObj());
}

Adesk::UInt16 PyDbEntity::colorIndex() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->colorIndex();
}

Acad::ErrorStatus PyDbEntity::setColorIndex(Adesk::UInt16 color, Adesk::Boolean doSubents /*= true*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setColorIndex(color, doSubents);
}

AcCmEntityColor PyDbEntity::entityColor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->entityColor();
}

AcCmTransparency PyDbEntity::transparency() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->transparency();
}

Acad::ErrorStatus PyDbEntity::setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents /*= true*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setTransparency(trans, doSubents);
}

std::string PyDbEntity::layer() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  wstr_to_utf8(impObj()->layer());
}

PyDbObjectId PyDbEntity::layerId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  PyDbObjectId(impObj()->layerId());
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(const std::string& str, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setPlotStyleName(utf8_to_wstr(str).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(AcDb::PlotStyleNameType tp, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setPlotStyleName(tp, AcDbObjectId::kNull, doSubents);
}

Acad::ErrorStatus PyDbEntity::setPlotStyleName(AcDb::PlotStyleNameType tp, const PyDbObjectId& newId, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setPlotStyleName(tp, newId.m_id, doSubents);
}

std::string PyDbEntity::linetype() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  wstr_to_utf8(imp->linetype());
}

PyDbObjectId PyDbEntity::linetypeId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  PyDbObjectId(impObj()->linetypeId());
}

Acad::ErrorStatus PyDbEntity::setLinetype(const std::string& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(utf8_to_wstr(newVal).c_str());
}

Acad::ErrorStatus PyDbEntity::setLinetype(const std::string& newVal, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(utf8_to_wstr(newVal).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setLinetype(const PyDbObjectId& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(newVal.m_id);
}

Acad::ErrorStatus PyDbEntity::setLinetype(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(newVal.m_id, doSubents);
}

std::string PyDbEntity::material() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  wstr_to_utf8(imp->material());
}

PyDbObjectId PyDbEntity::materialId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  PyDbObjectId(impObj()->materialId());
}

Acad::ErrorStatus PyDbEntity::setMaterial(const std::string& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setMaterial(utf8_to_wstr(newVal).c_str());
}

Acad::ErrorStatus PyDbEntity::setMaterial(const std::string& newVal, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setMaterial(utf8_to_wstr(newVal).c_str(), doSubents);
}

Acad::ErrorStatus PyDbEntity::setMaterial(const PyDbObjectId& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(newVal.m_id);
}

Acad::ErrorStatus PyDbEntity::setMaterial(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLinetype(newVal.m_id, doSubents);
}

double PyDbEntity::linetypeScale() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->linetypeScale();
}

Acad::ErrorStatus PyDbEntity::setLinetypeScale(double newval)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->setLinetypeScale(newval);
}

Acad::ErrorStatus PyDbEntity::setLinetypeScale(double newval, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->setLinetypeScale(newval, doSubents);
}

AcDb::Visibility PyDbEntity::visibility() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->visibility();
}

Acad::ErrorStatus PyDbEntity::setVisibility(AcDb::Visibility newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->setVisibility(newVal);
}

Acad::ErrorStatus PyDbEntity::setVisibility(AcDb::Visibility newVal, Adesk::Boolean doSubents /*= true*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->setVisibility(newVal, doSubents);
}

AcDb::LineWeight PyDbEntity::lineWeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lineWeight();
}

Acad::ErrorStatus PyDbEntity::setLineWeight(AcDb::LineWeight newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  imp->setLineWeight(newVal);
}

Acad::ErrorStatus PyDbEntity::setLineWeight(AcDb::LineWeight newVal, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLineWeight(newVal, doSubents);
}

AcDb::CollisionType PyDbEntity::collisionType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->collisionType();
}

bool PyDbEntity::castShadows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->castShadows();
}

void PyDbEntity::setCastShadows(bool newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setCastShadows(newVal);
}

bool PyDbEntity::receiveShadows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->receiveShadows();
}

void PyDbEntity::setReceiveShadows(bool newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setReceiveShadows(newVal);
}

Acad::ErrorStatus PyDbEntity::setPropertiesFrom(const PyDbEntity& pEntity)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPropertiesFrom(pEntity.impObj());
}

Acad::ErrorStatus PyDbEntity::setPropertiesFrom(const PyDbEntity& pEntity, Adesk::Boolean doSubents)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPropertiesFrom(pEntity.impObj(), doSubents);
}

Adesk::Boolean PyDbEntity::isPlanar() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPlanar();
}

PyGePlane PyDbEntity::getPlane() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePlane plane;
    AcDb::Planarity val;
    if (auto es = imp->getPlane(plane, val); es != eOk)
        throw PyAcadErrorStatus(es);
    if(val == AcDb::kNonPlanar)
        throw PyAcadErrorStatus(Acad::eNotApplicable);
    return PyGePlane(plane);
}

void PyDbEntity::getEcs(AcGeMatrix3d& retVal) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->getEcs(retVal);
}

void PyDbEntity::list() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->list();
}

Acad::ErrorStatus PyDbEntity::transformBy(const AcGeMatrix3d& xform)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->transformBy(xform);
}

void PyDbEntity::recordGraphicsModified()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->recordGraphicsModified();
}

Acad::ErrorStatus PyDbEntity::draw()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->draw();
}

void PyDbEntity::setDatabaseDefaults()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setDatabaseDefaults();
}

void PyDbEntity::setDatabaseDefaults(const PyDbDatabase& db)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setDatabaseDefaults(db.impObj());
}

Acad::ErrorStatus PyDbEntity::getCompoundObjectTransform(AcGeMatrix3d& xMat) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getCompoundObjectTransform(xMat);
}

Acad::ErrorStatus PyDbEntity::getGeomExtents(AcDbExtents& extents) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getGeomExtents(extents);
}

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

AcDbEntity* PyDbEntity::impObj() const
{
    return static_cast<AcDbEntity*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
void makeAcDbBlockBeginWrapper()
{
    static auto wrapper = class_<PyDbBlockBegin, bases<PyDbEntity>>("DbBlockBegin", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockBegin::className).staticmethod("className")
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbBlockBegin::className()
{
    return "AcDbBlockBegin";
}

AcDbBlockBegin* PyDbBlockBegin::impObj() const
{
    return static_cast<AcDbBlockBegin*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makeAcDbBlockEndWrapper()
{
    static auto wrapper = class_<PyDbBlockEnd, bases<PyDbEntity>>("DbBlockEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockBegin::className).staticmethod("className")
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbBlockEnd::className()
{
    return "AcDbBlockEnd";
}

AcDbBlockEnd* PyDbBlockEnd::impObj() const
{
    return static_cast<AcDbBlockEnd*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makeAcDbSequenceEndWrapper()
{
    static auto wrapper = class_<PyDbSequenceEnd, bases<PyDbEntity>>("DbSequenceEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSequenceEnd::className).staticmethod("className")
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbSequenceEnd::className()
{
    return "AcDbSequenceEnd";
}

AcDbSequenceEnd* PyDbSequenceEnd::impObj() const
{
    return static_cast<AcDbSequenceEnd*>(m_pImp.get());
}
