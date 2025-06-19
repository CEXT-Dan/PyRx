#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeLinearEnt3d.h"
#include "PyGeCurve2d.h"
#include "PyGeCurve3d.h"
#include "PyDbMText.h"
#include "PyDbEval.h"
using namespace boost::python;

#if defined(_BRXTARGET)
#include "AcConstraints3d.h"
#endif

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makePyDbBlockReferenceWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, blockTableRec: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.BlockReference");
    class_<PyDbBlockReference, bases<PyDbEntity>>("BlockReference")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const PyDbObjectId&>(DS.CTOR(ctords, 2501)))
        .def("blockTableRecord", &PyDbBlockReference::blockTableRecord, DS.ARGS(2514))
        .def("setBlockTableRecord", &PyDbBlockReference::setBlockTableRecord, DS.ARGS({ "val : ObjectId" }, 2528))
        .def("position", &PyDbBlockReference::position, DS.ARGS(2525))
        .def("setPosition", &PyDbBlockReference::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 2531))
        .def("scaleFactors", &PyDbBlockReference::scaleFactors, DS.ARGS(2527))
        .def("nonAnnotationScaleFactors", &PyDbBlockReference::nonAnnotationScaleFactors, DS.ARGS(2521))
        .def("setScaleFactors", &PyDbBlockReference::setScaleFactors, DS.ARGS({ "val : PyGe.Scale3d" }, 2533))
        .def("rotation", &PyDbBlockReference::rotation, DS.ARGS(2526))
        .def("setRotation", &PyDbBlockReference::setRotation, DS.ARGS({ "val : float" }, 2532))
        .def("normal", &PyDbBlockReference::normal, DS.ARGS(2522))
        .def("setNormal", &PyDbBlockReference::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 2530))
        .def("blockTransform", &PyDbBlockReference::blockTransform, DS.ARGS(2515))
        .def("nonAnnotationBlockTransform", &PyDbBlockReference::nonAnnotationBlockTransform, DS.ARGS(2520))
        .def("setBlockTransform", &PyDbBlockReference::setBlockTransform, DS.ARGS({ "val : PyGe.Matrix3d" }, 2529))
        .def("appendAttribute", &PyDbBlockReference::appendAttribute, DS.ARGS({ "val : PyDb.AttributeReference" }, 2512))
        .def("attributeIds", &PyDbBlockReference::attributeIds, DS.ARGS())
        .def("treatAsAcDbBlockRefForExplode", &PyDbBlockReference::treatAsAcDbBlockRefForExplode, DS.ARGS(2535))
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit1)
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit2, DS.ARGS({ "val : PyGe.Matrix3d=PyGe.Matrix3d.kIdentity" }, 2517))
        .def("explodeToOwnerSpace", &PyDbBlockReference::explodeToOwnerSpace, DS.ARGS(2516))
        .def("getBlockName", &PyDbBlockReference::getBlockName, DS.ARGS())
        .def("className", &PyDbBlockReference::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockReference::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockReference::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockReference::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbBlockReference::PyDbBlockReference()
    : PyDbBlockReference(new AcDbBlockReference(), true)
{
}

PyDbBlockReference::PyDbBlockReference(const AcGePoint3d& position, const PyDbObjectId& blockTableRec)
    : PyDbBlockReference(new AcDbBlockReference(position, blockTableRec.m_id), true)
{
}

PyDbBlockReference::PyDbBlockReference(AcDbBlockReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id)
    : PyDbBlockReference(id, AcDb::OpenMode::kForRead)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbBlockReference>(id, mode), false)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbBlockReference>(id, mode, erased), false)
{
}

PyDbObjectId PyDbBlockReference::blockTableRecord() const
{
    return PyDbObjectId(impObj()->blockTableRecord());
}

void PyDbBlockReference::setBlockTableRecord(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setBlockTableRecord(val.m_id));
}

AcGePoint3d PyDbBlockReference::position() const
{
    return impObj()->position();
}

void PyDbBlockReference::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

AcGeScale3d PyDbBlockReference::scaleFactors() const
{
    return impObj()->scaleFactors();
}

AcGeScale3d PyDbBlockReference::nonAnnotationScaleFactors() const
{
    return impObj()->nonAnnotationScaleFactors();
}

void PyDbBlockReference::setScaleFactors(const AcGeScale3d& scale) const
{
    return PyThrowBadEs(impObj()->setScaleFactors(scale));
}

double PyDbBlockReference::rotation() const
{
    return impObj()->rotation();
}

void PyDbBlockReference::setRotation(double newVal) const
{
    return PyThrowBadEs(impObj()->setRotation(newVal));
}

AcGeVector3d PyDbBlockReference::normal() const
{
    return impObj()->normal();
}

void PyDbBlockReference::setNormal(const AcGeVector3d& newVal) const
{
    return PyThrowBadEs(impObj()->setNormal(newVal));
}

AcGeMatrix3d PyDbBlockReference::blockTransform() const
{
    return impObj()->blockTransform();
}

AcGeMatrix3d PyDbBlockReference::nonAnnotationBlockTransform() const
{
    return impObj()->nonAnnotationBlockTransform();
}

void PyDbBlockReference::setBlockTransform(const AcGeMatrix3d& val) const
{
    return PyThrowBadEs(impObj()->setBlockTransform(val));
}

PyDbObjectId PyDbBlockReference::appendAttribute(PyDbAttribute& att) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->appendAttribute(id, att.impObj()));
    return PyDbObjectId(id);
}

boost::python::list PyDbBlockReference::attributeIds() const
{
    PyAutoLockGIL lock;
    AcDbObjectId id;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->attributeIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

Adesk::Boolean PyDbBlockReference::treatAsAcDbBlockRefForExplode() const
{
    return impObj()->treatAsAcDbBlockRefForExplode();
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit1() const
{
    return geomExtentsBestFit2(AcGeMatrix3d::kIdentity);
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit2(const AcGeMatrix3d& parentXform) const
{
    AcDbExtents ex;
    PyThrowBadEs(impObj()->geomExtentsBestFit(ex, parentXform));
    return ex;
}

void PyDbBlockReference::explodeToOwnerSpace() const
{
    return PyThrowBadEs(impObj()->explodeToOwnerSpace());
}

std::string PyDbBlockReference::getBlockName() const
{
    AcString name;
    AcDbDynBlockReference dynBlk(impObj()->objectId());
    if (dynBlk.isDynamicBlock())
    {
        AcDbBlockTableRecordPointer bBlock(dynBlk.dynamicBlockTableRecord());
        PyThrowBadEs(bBlock.openStatus());
        PyThrowBadEs(bBlock->getName(name));
    }
    else
    {
        AcDbBlockTableRecordPointer bBlock(impObj()->blockTableRecord());
        PyThrowBadEs(bBlock.openStatus());
#if defined (_BRXTARGET) //related to (SR196681) parametric block
        if (bBlock->isAnonymous())
        {
            if (AcString efname = acdbEffectiveBlockRefName(impObj()->objectId()); !efname.isEmpty())
                return wstr_to_utf8(efname);
        }
#endif
        PyThrowBadEs(bBlock->getName(name));
    }
    return wstr_to_utf8(name);
}

std::string PyDbBlockReference::className()
{
    return "AcDbBlockReference";
}

PyRxClass PyDbBlockReference::desc()
{
    return PyRxClass(AcDbBlockReference::desc(), false);
}

PyDbBlockReference PyDbBlockReference::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbBlockReference, AcDbBlockReference>(src);
}

PyDbBlockReference PyDbBlockReference::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBlockReference>(src);
}

AcDbBlockReference* PyDbBlockReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbBlockReference*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbDynBlockReference
void makePyDbDynBlockReferenceWrapper() //TODO: Make test
{
    PyDocString DS("PyDb.DynBlockReference");
    class_<PyDbDynBlockReference>("DynBlockReference", no_init)
        .def(init<const PyDbObjectId&>(DS.ARGS({ "val :  PyDb.ObjectId" }, 4192)))
        .def("isDynamicBlock", &PyDbDynBlockReference::isDynamicBlock1, DS.ARGS(4216))
        .def("blockId", &PyDbDynBlockReference::blockId, DS.ARGS(4212))
        .def("resetBlock", &PyDbDynBlockReference::resetBlock, DS.ARGS(4217))
        .def("convertToStaticBlock", &PyDbDynBlockReference::convertToStaticBlock1)
        .def("convertToStaticBlock", &PyDbDynBlockReference::convertToStaticBlock2, DS.ARGS({ "val : str = ..." }, 4213))
        .def("dynamicBlockTableRecord", &PyDbDynBlockReference::dynamicBlockTableRecord, DS.ARGS(4214))
        .def("anonymousBlockTableRecord", &PyDbDynBlockReference::anonymousBlockTableRecord, DS.ARGS(4211))
        .def("getBlockProperties", &PyDbDynBlockReference::getBlockProperties, DS.ARGS(4215))
        .def("getIsDynamicBlock", &PyDbDynBlockReference::isDynamicBlock2, DS.SARGS({ "otherObject:  PyDb.ObjectId" })).staticmethod("getIsDynamicBlock")
        .def("className", &PyDbDynBlockReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDynBlockReference::PyDbDynBlockReference(const PyDbObjectId& id)
    : m_imp(new AcDbDynBlockReference(id.m_id))
{
}

bool PyDbDynBlockReference::isDynamicBlock1() const
{
    return impObj()->isDynamicBlock();
}

PyDbObjectId PyDbDynBlockReference::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

void PyDbDynBlockReference::resetBlock() const
{
    return PyThrowBadEs(impObj()->resetBlock());
}

void PyDbDynBlockReference::convertToStaticBlock1() const
{
    return PyThrowBadEs(impObj()->convertToStaticBlock());
}

void PyDbDynBlockReference::convertToStaticBlock2(const std::string& newBlockName) const
{
    return PyThrowBadEs(impObj()->convertToStaticBlock(utf8_to_wstr(newBlockName).c_str()));
}

PyDbObjectId PyDbDynBlockReference::dynamicBlockTableRecord() const
{
    return PyDbObjectId(impObj()->dynamicBlockTableRecord());
}

PyDbObjectId PyDbDynBlockReference::anonymousBlockTableRecord() const
{
    return PyDbObjectId(impObj()->anonymousBlockTableRecord());
}

boost::python::list PyDbDynBlockReference::getBlockProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbDynBlockReferencePropertyArray properties;
    impObj()->getBlockProperties(properties);
    for (const auto& item : properties)
        pyList.append(PyDbDynBlockReferenceProperty(item));
    return pyList;
}

bool PyDbDynBlockReference::isDynamicBlock2(const PyDbObjectId& blockTableRecordId)
{
    return AcDbDynBlockReference::isDynamicBlock(blockTableRecordId.m_id);
}

std::string PyDbDynBlockReference::className()
{
    return "AcDbDynBlockReference";
}

AcDbDynBlockReference* PyDbDynBlockReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDynBlockReference*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//DbMInsertBlock
void makePyDbMInsertBlockeWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, blockTableRec: PyDb.ObjectId, columns: int, rows: int, colSpacing: float, rowSpacing: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.MInsertBlock");
    class_<PyDbMInsertBlock, bases<PyDbBlockReference>>("MInsertBlock")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&, Adesk::UInt16, Adesk::UInt16, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 6409)))
        .def("columns", &PyDbMInsertBlock::columns, DS.ARGS(6411))
        .def("setColumns", &PyDbMInsertBlock::setColumns, DS.ARGS({ "val : int" }, 6415))
        .def("rows", &PyDbMInsertBlock::rows, DS.ARGS(6413))
        .def("setRows", &PyDbMInsertBlock::setRows, DS.ARGS({ "val : int" }, 6417))
        .def("columnSpacing", &PyDbMInsertBlock::columnSpacing, DS.ARGS(6412))
        .def("setColumnSpacing", &PyDbMInsertBlock::setColumnSpacing, DS.ARGS({ "val : float" }, 6416))
        .def("rowSpacing", &PyDbMInsertBlock::rowSpacing, DS.ARGS(6414))
        .def("setRowSpacing", &PyDbMInsertBlock::setRowSpacing, DS.ARGS({ "val : float" }, 6418))
        .def("className", &PyDbMInsertBlock::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMInsertBlock::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMInsertBlock::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMInsertBlock::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbMInsertBlock::PyDbMInsertBlock()
    : PyDbMInsertBlock(new AcDbMInsertBlock(), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const AcGePoint3d& position, const PyDbObjectId& blockTableRec, Adesk::UInt16 columns, Adesk::UInt16 rows, double colSpacing, double rowSpacing)
    : PyDbMInsertBlock(new AcDbMInsertBlock(position, blockTableRec.m_id, columns, rows, colSpacing, rowSpacing), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id)
    : PyDbMInsertBlock(id, AcDb::OpenMode::kForRead)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbBlockReference(openAcDbObject<AcDbMInsertBlock>(id, mode), false)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbBlockReference(openAcDbObject<AcDbMInsertBlock>(id, mode, erased), false)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(AcDbMInsertBlock* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

Adesk::UInt16 PyDbMInsertBlock::columns() const
{
    return impObj()->columns();
}

void PyDbMInsertBlock::setColumns(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setColumns(val));
}

Adesk::UInt16 PyDbMInsertBlock::rows() const
{
    return impObj()->rows();
}

void PyDbMInsertBlock::setRows(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setRows(val));
}

double PyDbMInsertBlock::columnSpacing() const
{
    return impObj()->columnSpacing();
}

void PyDbMInsertBlock::setColumnSpacing(double val) const
{
    return PyThrowBadEs(impObj()->setColumnSpacing(val));
}

double PyDbMInsertBlock::rowSpacing() const
{
    return impObj()->rowSpacing();
}

void PyDbMInsertBlock::setRowSpacing(double val) const
{
    return PyThrowBadEs(impObj()->setRowSpacing(val));
}

std::string PyDbMInsertBlock::className()
{
    return "AcDbMInsertBlock";
}

PyRxClass PyDbMInsertBlock::desc()
{
    return PyRxClass(AcDbMInsertBlock::desc(), false);
}

PyDbMInsertBlock PyDbMInsertBlock::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbMInsertBlock, AcDbMInsertBlock>(src);
}

PyDbMInsertBlock PyDbMInsertBlock::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMInsertBlock>(src);
}

AcDbMInsertBlock* PyDbMInsertBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMInsertBlock*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makePyDbVertexWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Vertex");
    class_<PyDbVertex, bases<PyDbEntity>>("Vertex")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9921)))
        .def("className", &PyDbVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbVertex::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbVertex::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbVertex::PyDbVertex()
    : PyDbEntity(new AcDbVertex(), true)
{
}

PyDbVertex::PyDbVertex(AcDbVertex* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbVertex>(id, mode), false)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id)
    : PyDbVertex(id, AcDb::OpenMode::kForRead)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbVertex>(id, mode, erased), false)
{
}

std::string PyDbVertex::className()
{
    return "AcDbVertex";
}

PyRxClass PyDbVertex::desc()
{
    return PyRxClass(AcDbVertex::desc(), false);
}

PyDbVertex PyDbVertex::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbVertex, AcDbVertex>(src);
}

PyDbVertex PyDbVertex::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbVertex>(src);
}

AcDbVertex* PyDbVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pos : PyGe.Point3d, bulge: float, startWidth: float, endWidth: float, tangent:float, vertexId: int\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Vertex2d");
    class_<PyDb2dVertex, bases<PyDbVertex>>("Vertex2d")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
#if !defined(_BRXTARGET250)
        .def(init<const AcGePoint3d&, double, double, double, double, Adesk::Int32>())
#endif
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 1196)))
        .def("vertexType", &PyDb2dVertex::vertexType, DS.ARGS(1212))
        .def("position", &PyDb2dVertex::position, DS.ARGS(1202))
        .def("setPosition", &PyDb2dVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 1205))
        .def("startWidth", &PyDb2dVertex::startWidth, DS.ARGS(1209))
        .def("setStartWidth", &PyDb2dVertex::setStartWidth, DS.ARGS({ "val : float" }, 1206))
        .def("endWidth", &PyDb2dVertex::endWidth, DS.ARGS(1199))
        .def("setEndWidth", &PyDb2dVertex::setEndWidth, DS.ARGS({ "val : float" }, 1204))
        .def("bulge", &PyDb2dVertex::bulge, DS.ARGS(1198))
        .def("setBulge", &PyDb2dVertex::setBulge, DS.ARGS({ "val : float" }, 1203))
        .def("isTangentUsed", &PyDb2dVertex::isTangentUsed, DS.ARGS(1201))
        .def("useTangent", &PyDb2dVertex::useTangent, DS.ARGS(1211))
        .def("ignoreTangent", &PyDb2dVertex::ignoreTangent, DS.ARGS(1200))
        .def("setTangentUsed", &PyDb2dVertex::setTangentUsed, DS.ARGS({ "val : bool" }, 1208))
        .def("tangent", &PyDb2dVertex::tangent, DS.ARGS(1210))
        .def("setTangent", &PyDb2dVertex::setTangent, DS.ARGS({ "val : float" }, 1207))
        .def("setVertexIdentifier", &PyDb2dVertex::setVertexIdentifier, DS.ARGS({ "val : int" }))
        .def("vertexIdentifier", &PyDb2dVertex::vertexIdentifier, DS.ARGS())
        .def("className", &PyDb2dVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb2dVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb2dVertex::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb2dVertex::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDb2dVertex::PyDb2dVertex()
    : PyDb2dVertex(new AcDb2dVertex(), true)
{
}

PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos)
    : PyDb2dVertex(new AcDb2dVertex(pos), true)
{
}

#if !defined(_BRXTARGET250)
PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier)
    : PyDb2dVertex(new AcDb2dVertex(pos, bulge, startWidth, endWidth, tangent, vertexIdentifier), true)
{
}
#endif

PyDb2dVertex::PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDb2dVertex>(id, mode), false)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id)
    : PyDb2dVertex(id, AcDb::OpenMode::kForRead)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbVertex(openAcDbObject<AcDb2dVertex>(id, mode, erased), false)
{
}

AcDb::Vertex2dType PyDb2dVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDb2dVertex::position() const
{
    return impObj()->position();
}

void PyDb2dVertex::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

double PyDb2dVertex::startWidth() const
{
    return impObj()->startWidth();
}

void PyDb2dVertex::setStartWidth(double newVal) const
{
    return PyThrowBadEs(impObj()->setStartWidth(newVal));
}

double PyDb2dVertex::endWidth() const
{
    return impObj()->endWidth();
}

void PyDb2dVertex::setEndWidth(double newVal) const
{
    return PyThrowBadEs(impObj()->setEndWidth(newVal));
}

double PyDb2dVertex::bulge() const
{
    return impObj()->bulge();
}

void PyDb2dVertex::setBulge(double newVal) const
{
    return PyThrowBadEs(impObj()->setBulge(newVal));
}

Adesk::Boolean PyDb2dVertex::isTangentUsed() const
{
    return impObj()->isTangentUsed();
}

void PyDb2dVertex::useTangent() const
{
    return PyThrowBadEs(impObj()->useTangent());
}

void PyDb2dVertex::ignoreTangent() const
{
    return PyThrowBadEs(impObj()->ignoreTangent());
}

void PyDb2dVertex::setTangentUsed(Adesk::Boolean val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTangentUsed(val));
#endif
}

double PyDb2dVertex::tangent() const
{
    return impObj()->tangent();
}

void PyDb2dVertex::setTangent(double newVal) const
{
    return PyThrowBadEs(impObj()->setTangent(newVal));
}

void PyDb2dVertex::setVertexIdentifier(Adesk::Int32 suggestedValue) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setVertexIdentifier(suggestedValue));
#endif
}

int PyDb2dVertex::vertexIdentifier() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->vertexIdentifier();
#endif
}

std::string PyDb2dVertex::className()
{
    return "AcDb2dVertex";
}

PyRxClass PyDb2dVertex::desc()
{
    return PyRxClass(AcDb2dVertex::desc(), false);
}

PyDb2dVertex PyDb2dVertex::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDb2dVertex, AcDb2dVertex>(src);
}

PyDb2dVertex PyDb2dVertex::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb2dVertex>(src);
}

AcDb2dVertex* PyDb2dVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb2dVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyDb3dPolylineVertexWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pos: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Polyline3dVertex");
    class_<PyDb3dPolylineVertex, bases<PyDbVertex>>("Polyline3dVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 1231)))
        .def("vertexType", &PyDb3dPolylineVertex::vertexType, DS.ARGS(1235))
        .def("position", &PyDb3dPolylineVertex::position, DS.ARGS(1233))
        .def("setPosition", &PyDb3dPolylineVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 1234))
        .def("className", &PyDb3dPolylineVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3dPolylineVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb3dPolylineVertex::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3dPolylineVertex::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex()
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const AcGePoint3d& pos)
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(pos), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(AcDb3dPolylineVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDb3dPolylineVertex>(id, mode), false)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id)
    : PyDb3dPolylineVertex(id, AcDb::OpenMode::kForRead)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbVertex(openAcDbObject<AcDb3dPolylineVertex>(id, mode, erased), false)
{
}

AcDb::Vertex3dType PyDb3dPolylineVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDb3dPolylineVertex::position() const
{
    return impObj()->position();
}

void PyDb3dPolylineVertex::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDb3dPolylineVertex::className()
{
    return "AcDb3dPolylineVertex";
}

PyRxClass PyDb3dPolylineVertex::desc()
{
    return PyRxClass(AcDb3dPolylineVertex::desc(), false);
}

PyDb3dPolylineVertex PyDb3dPolylineVertex::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDb3dPolylineVertex, AcDb3dPolylineVertex>(src);
}

PyDb3dPolylineVertex PyDb3dPolylineVertex::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb3dPolylineVertex>(src);
}

AcDb3dPolylineVertex* PyDb3dPolylineVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dPolylineVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolygonMeshVertexWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pos: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.PolygonMeshVertex");
    class_<PyDbPolygonMeshVertex, bases<PyDbVertex>>("PolygonMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7791)))
        .def("vertexType", &PyDbPolygonMeshVertex::vertexType, DS.ARGS(7795))
        .def("position", &PyDbPolygonMeshVertex::position, DS.ARGS(7793))
        .def("setPosition", &PyDbPolygonMeshVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 7794))
        .def("className", &PyDbPolygonMeshVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolygonMeshVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPolygonMeshVertex::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolygonMeshVertex::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex()
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const AcGePoint3d& pos)
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(pos), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(AcDbPolygonMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbPolygonMeshVertex>(id, mode), false)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id)
    : PyDbPolygonMeshVertex(id, AcDb::OpenMode::kForRead)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbVertex(openAcDbObject<AcDbPolygonMeshVertex>(id, mode, erased), false)
{
}

AcDb::Vertex3dType PyDbPolygonMeshVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDbPolygonMeshVertex::position() const
{
    return impObj()->position();
}

void PyDbPolygonMeshVertex::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDbPolygonMeshVertex::className()
{
    return "AcDbPolygonMeshVertex";
}

PyRxClass PyDbPolygonMeshVertex::desc()
{
    return PyRxClass(AcDbPolygonMeshVertex::desc(), false);
}

PyDbPolygonMeshVertex PyDbPolygonMeshVertex::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPolygonMeshVertex, AcDbPolygonMeshVertex>(src);
}

PyDbPolygonMeshVertex PyDbPolygonMeshVertex::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPolygonMeshVertex>(src);
}

AcDbPolygonMeshVertex* PyDbPolygonMeshVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolygonMeshVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolyFaceMeshVertexWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pos: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.PolyFaceMeshVertex");
    class_<PyDbPolyFaceMeshVertex, bases<PyDbVertex>>("PolyFaceMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7775)))
        .def("position", &PyDbPolyFaceMeshVertex::position, DS.ARGS(7777))
        .def("setPosition", &PyDbPolyFaceMeshVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 7778))
        .def("className", &PyDbPolyFaceMeshVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolyFaceMeshVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPolyFaceMeshVertex::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolyFaceMeshVertex::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex()
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const AcGePoint3d& pos)
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(pos), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(AcDbPolyFaceMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbPolyFaceMeshVertex>(id, mode), false)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id)
    : PyDbPolyFaceMeshVertex(id, AcDb::OpenMode::kForRead)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbVertex(openAcDbObject<AcDbPolyFaceMeshVertex>(id, mode, erased), false)
{
}

AcGePoint3d PyDbPolyFaceMeshVertex::position() const
{
    return impObj()->position();
}

void PyDbPolyFaceMeshVertex::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDbPolyFaceMeshVertex::className()
{
    return "AcDbPolyFaceMeshVertex";
}

PyRxClass PyDbPolyFaceMeshVertex::desc()
{
    return PyRxClass(AcDbPolyFaceMeshVertex::desc(), false);
}

PyDbPolyFaceMeshVertex PyDbPolyFaceMeshVertex::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPolyFaceMeshVertex, AcDbPolyFaceMeshVertex>(src);
}

PyDbPolyFaceMeshVertex PyDbPolyFaceMeshVertex::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPolyFaceMeshVertex>(src);
}

AcDbPolyFaceMeshVertex* PyDbPolyFaceMeshVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolyFaceMeshVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord
void makePyDbFaceRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- vtx0: int, vtx1: int, vtx2: int, vtx3: int\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.FaceRecord");
    class_<PyDbFaceRecord, bases<PyDbVertex>>("FaceRecord")
        .def(init<>())
        .def(init<Adesk::Int16, Adesk::Int16, Adesk::Int16, Adesk::Int16>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 4556)))
        .def("getVertexAt", &PyDbFaceRecord::getVertexAt, DS.ARGS({ "val : int" }, 4558))
        .def("setVertexAt", &PyDbFaceRecord::setVertexAt, DS.ARGS({ "val : int",  "idx : int" }, 4562))
        .def("isEdgeVisibleAt", &PyDbFaceRecord::isEdgeVisibleAt, DS.ARGS({ "val : int" }, 4559))
        .def("makeEdgeVisibleAt", &PyDbFaceRecord::makeEdgeVisibleAt, DS.ARGS({ "val : int" }, 4561))
        .def("makeEdgeInvisibleAt", &PyDbFaceRecord::makeEdgeInvisibleAt, DS.ARGS({ "val : int" }, 4560))
        .def("className", &PyDbFaceRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFaceRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbFaceRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFaceRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbFaceRecord::PyDbFaceRecord()
    :PyDbFaceRecord(new AcDbFaceRecord(), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(Adesk::Int16 vtx0, Adesk::Int16 vtx1, Adesk::Int16 vtx2, Adesk::Int16 vtx3)
    : PyDbFaceRecord(new AcDbFaceRecord(vtx0, vtx1, vtx2, vtx3), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(AcDbFaceRecord* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbFaceRecord>(id, mode), false)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id)
    : PyDbFaceRecord(id, AcDb::OpenMode::kForRead)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbVertex(openAcDbObject<AcDbFaceRecord>(id, mode, erased), false)
{
}

Adesk::Int16 PyDbFaceRecord::getVertexAt(Adesk::UInt16 faceIdx) const
{
    Adesk::Int16 vtxIdx = 0;
    PyThrowBadEs(impObj()->getVertexAt(faceIdx, vtxIdx));
    return vtxIdx;
}

void PyDbFaceRecord::setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx) const
{
    return PyThrowBadEs(impObj()->setVertexAt(faceIdx, vtxIdx));
}

Adesk::Boolean PyDbFaceRecord::isEdgeVisibleAt(Adesk::UInt16 faceIndex) const
{
    Adesk::Boolean flag = false;
    PyThrowBadEs(impObj()->isEdgeVisibleAt(faceIndex, flag));
    return flag;
}

void PyDbFaceRecord::makeEdgeVisibleAt(Adesk::UInt16 faceIndex) const
{
    return PyThrowBadEs(impObj()->makeEdgeVisibleAt(faceIndex));
}

void PyDbFaceRecord::makeEdgeInvisibleAt(Adesk::UInt16 faceIndex) const
{
    return PyThrowBadEs(impObj()->makeEdgeInvisibleAt(faceIndex));
}

std::string PyDbFaceRecord::className()
{
    return "AcDbFaceRecord";
}

PyRxClass PyDbFaceRecord::desc()
{
    return PyRxClass(AcDbFaceRecord::desc(), false);
}

PyDbFaceRecord PyDbFaceRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbFaceRecord, AcDbFaceRecord>(src);
}

PyDbFaceRecord PyDbFaceRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbFaceRecord>(src);
}

AcDbFaceRecord* PyDbFaceRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFaceRecord*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pos : PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Point");
    class_<PyDbPoint, bases<PyDbEntity>>("Point")
        .def(init<>())
        .def(init<AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7493)))
        .def("position", &PyDbPoint::position, DS.ARGS(7766))
        .def("setPosition", &PyDbPoint::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 7769))
        .def("thickness", &PyDbPoint::thickness, DS.ARGS(7772))
        .def("setThickness", &PyDbPoint::setThickness, DS.ARGS({ "val : float" }, 7770))
        .def("normal", &PyDbPoint::normal, DS.ARGS(7765))
        .def("setNormal", &PyDbPoint::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 7768))
        .def("ecsRotation", &PyDbPoint::ecsRotation, DS.ARGS(7762))
        .def("setEcsRotation", &PyDbPoint::setEcsRotation, DS.ARGS({ "val : float" }, 7767))
        .def("className", &PyDbPoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPoint::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPoint::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPoint::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbPoint::PyDbPoint()
    : PyDbPoint::PyDbPoint(new AcDbPoint(), true)
{
}

PyDbPoint::PyDbPoint(const AcGePoint3d& point)
    : PyDbPoint::PyDbPoint(new AcDbPoint(point), true)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPoint::PyDbPoint(openAcDbObject<AcDbPoint>(id, mode), false)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id)
    : PyDbPoint(id, AcDb::OpenMode::kForRead)
{
}

PyDbPoint::PyDbPoint(AcDbPoint* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPoint::PyDbPoint(openAcDbObject<AcDbPoint>(id, mode, erased), false)
{
}

AcGePoint3d PyDbPoint::position() const
{
    return impObj()->position();
}

void PyDbPoint::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

double PyDbPoint::thickness() const
{
    return impObj()->thickness();
}

void PyDbPoint::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbPoint::normal() const
{
    return impObj()->normal();
}

void PyDbPoint::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbPoint::ecsRotation() const
{
    return impObj()->ecsRotation();
}

void PyDbPoint::setEcsRotation(double val) const
{
    return PyThrowBadEs(impObj()->setEcsRotation(val));
}

std::string PyDbPoint::className()
{
    return "AcDbPoint";
}

PyRxClass PyDbPoint::desc()
{
    return PyRxClass(AcDbPoint::desc(), false);
}

PyDbPoint PyDbPoint::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPoint, AcDbPoint>(src);
}

PyDbPoint PyDbPoint::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPoint>(src);
}

AcDbPoint* PyDbPoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPoint*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2dPolyline
static AcGePoint3dArray& listToAcGePoint3dArrayRef(const boost::python::list& list)
{
    PyAutoLockGIL lock;
    //TODO: maybe this can be done better
    auto vec = py_list_to_std_vector<AcGePoint3d>(list);
    static AcGePoint3dArray arr;
    arr.removeAll();
    for (const AcGePoint3d& pnt : vec)
        arr.append(pnt);
    return arr;
}

void makePyDb2dPolylineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- ptype: PyDb.Poly2dType, points: list[PyGe.Point3d], closed: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view splineFitverOverload = "Overloads:\n"
        "- None: Any\n"
        "- splineType: PyDb.Poly2dType, splineSegs: int\n";

    constexpr const std::string_view appendVertexOverload = "Overloads:\n"
        "- vertex: PyDb.Vertex2d\n"
        "- outVertexId: PyDb.ObjectId,vertex: PyDb.Vertex2d\n";

    constexpr const std::string_view insertVertexAtOverload = "Overloads:\n"
        "- indexVt: PyDb.Vertex2d, newVertex: PyDb.Vertex2d\n"
        "- outVertexId: PyDb.ObjectId, indexVtId: PyDb.ObjectId, newVertex: PyDb.Vertex2d\n";

    PyDocString DS("Polyline2d");
    class_<PyDb2dPolyline, bases<PyDbCurve>>("Polyline2d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<AcDb::Poly2dType, const boost::python::list&, Adesk::Boolean>(DS.CTOR(ctords, 1160)))
        .def("polyType", &PyDb2dPolyline::polyType, DS.ARGS(1178))
        .def("setPolyType", &PyDb2dPolyline::setPolyType, DS.ARGS({ "val: PyDb.Poly2dType" }, 1187))
        .def("convertToPolyType", &PyDb2dPolyline::convertToPolyType, DS.ARGS({ "val: PyDb.Poly2dType" }, 1164))
        .def("makeClosed", &PyDb2dPolyline::makeClosed, DS.ARGS(1172))
        .def("makeOpen", &PyDb2dPolyline::makeOpen, DS.ARGS(1174))
        .def("setClosed", &PyDb2dPolyline::setClosed, DS.ARGS({ "val : bool" }, 1179))
        .def("constantWidth", &PyDb2dPolyline::constantWidth, DS.ARGS(1163))
        .def("setConstantWidth", &PyDb2dPolyline::setConstantWidth, DS.ARGS({ "val : float" }, 1180))
        .def("length", &PyDb2dPolyline::length, DS.ARGS(1171))
        .def("defaultStartWidth", &PyDb2dPolyline::defaultStartWidth, DS.ARGS(1167))
        .def("setDefaultStartWidth", &PyDb2dPolyline::setDefaultStartWidth, DS.ARGS({ "val : float" }, 1182))
        .def("defaultEndWidth", &PyDb2dPolyline::defaultEndWidth, DS.ARGS(1166))
        .def("setDefaultEndWidth", &PyDb2dPolyline::setDefaultEndWidth, DS.ARGS({ "val : float" }, 1181))
        .def("thickness", &PyDb2dPolyline::thickness, DS.ARGS(1192))
        .def("setThickness", &PyDb2dPolyline::setThickness, DS.ARGS({ "val : float" }, 1188))
        .def("normal", &PyDb2dPolyline::normal, DS.ARGS(1175))
        .def("setNormal", &PyDb2dPolyline::setNormal, DS.ARGS({ "normal : PyGe.Vector3d" }, 1186))
        .def("elevation", &PyDb2dPolyline::elevation, DS.ARGS(1168))
        .def("setElevation", &PyDb2dPolyline::setElevation, DS.ARGS({ "val : float" }, 1183))
        .def("isLinetypeGenerationOn", &PyDb2dPolyline::isLinetypeGenerationOn, DS.ARGS(1170))
        .def("setLinetypeGenerationOn", &PyDb2dPolyline::setLinetypeGenerationOn, DS.ARGS(1185))
        .def("setLinetypeGenerationOff", &PyDb2dPolyline::setLinetypeGenerationOff, DS.ARGS(1184))
        .def("straighten", &PyDb2dPolyline::straighten, DS.ARGS(1190))
        .def("splineFit", &PyDb2dPolyline::splineFit1)
        .def("splineFit", &PyDb2dPolyline::splineFit2, DS.OVRL(splineFitverOverload, 1189))
        .def("appendVertex", &PyDb2dPolyline::appendVertex1)
        .def("appendVertex", &PyDb2dPolyline::appendVertex2, DS.OVRL(appendVertexOverload, 1162))
        .def("insertVertexAt", &PyDb2dPolyline::insertVertexAt1)
        .def("insertVertexAt", &PyDb2dPolyline::insertVertexAt2, DS.OVRL(insertVertexAtOverload, 1169))
        .def("openVertex", &PyDb2dPolyline::openVertex, DS.ARGS({ "id : PyDb.ObjectId","mode: PyDb.OpenMode" }, 1177))
        .def("openSequenceEnd", &PyDb2dPolyline::openSequenceEnd, DS.ARGS({ "mode: PyDb.OpenMode" }, 1176))
        .def("vertexIds", &PyDb2dPolyline::vertexIds, DS.ARGS())
        .def("vertexPosition", &PyDb2dPolyline::vertexPosition, DS.ARGS({ "vt : PyDb.Vertex2d" }, 1194))
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide, DS.ARGS({ "val : float" }, 1173))
        .def("className", &PyDb2dPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb2dPolyline::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb2dPolyline::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb2dPolyline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDb2dPolyline::PyDb2dPolyline()
    : PyDbCurve(new AcDb2dPolyline(), true)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id)
    : PyDb2dPolyline(id, AcDb::OpenMode::kForRead)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDb2dPolyline>(id, mode), false)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDb2dPolyline>(id, mode, erased), false)
{
}

PyDb2dPolyline::PyDb2dPolyline(AcDb::Poly2dType type, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb2dPolyline(type, listToAcGePoint3dArrayRef(vertices), 0.0, closed), true)
{
}

PyDb2dPolyline::PyDb2dPolyline(AcDb2dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

AcDb::Poly2dType PyDb2dPolyline::polyType() const
{
    return impObj()->polyType();
}

void PyDb2dPolyline::setPolyType(AcDb::Poly2dType val) const
{
    return PyThrowBadEs(impObj()->setPolyType(val));
}

void PyDb2dPolyline::convertToPolyType(AcDb::Poly2dType val) const
{
    return PyThrowBadEs(impObj()->convertToPolyType(val));
}

void PyDb2dPolyline::makeClosed() const
{
    return PyThrowBadEs(impObj()->makeClosed());
}

void PyDb2dPolyline::makeOpen() const
{
    return PyThrowBadEs(impObj()->makeOpen());
}

void PyDb2dPolyline::setClosed(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setClosed(val));
}

double PyDb2dPolyline::constantWidth() const
{
    double val;
    PyThrowBadEs(impObj()->constantWidth(val));
    return val;
}

void PyDb2dPolyline::setConstantWidth(double val) const
{
    return PyThrowBadEs(impObj()->setConstantWidth(val));
}

double PyDb2dPolyline::length() const
{
    double val;
    PyThrowBadEs(impObj()->length(val));
    return val;
}

double PyDb2dPolyline::defaultStartWidth() const
{
    return impObj()->defaultStartWidth();
}

void PyDb2dPolyline::setDefaultStartWidth(double val) const
{
    return PyThrowBadEs(impObj()->setDefaultStartWidth(val));
}

double PyDb2dPolyline::defaultEndWidth() const
{
    return impObj()->defaultEndWidth();
}

void PyDb2dPolyline::setDefaultEndWidth(double val) const
{
    return PyThrowBadEs(impObj()->setDefaultEndWidth(val));
}

double PyDb2dPolyline::thickness() const
{
    return impObj()->thickness();
}

void PyDb2dPolyline::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDb2dPolyline::normal() const
{
    return impObj()->normal();
}

void PyDb2dPolyline::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDb2dPolyline::elevation() const
{
    return impObj()->elevation();
}

void PyDb2dPolyline::setElevation(double val) const
{
    return PyThrowBadEs(impObj()->setElevation(val));
}

Adesk::Boolean PyDb2dPolyline::isLinetypeGenerationOn() const
{
    return impObj()->isLinetypeGenerationOn();
}

void PyDb2dPolyline::setLinetypeGenerationOn() const
{
    return PyThrowBadEs(impObj()->setLinetypeGenerationOn());
}

void PyDb2dPolyline::setLinetypeGenerationOff() const
{
    return PyThrowBadEs(impObj()->setLinetypeGenerationOff());
}

void PyDb2dPolyline::straighten() const
{
    return PyThrowBadEs(impObj()->straighten());
}

void PyDb2dPolyline::splineFit1() const
{
    return PyThrowBadEs(impObj()->splineFit());
}

void PyDb2dPolyline::splineFit2(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs) const
{
    return PyThrowBadEs(impObj()->splineFit(splineType, splineSegs));
}

void PyDb2dPolyline::appendVertex1(const PyDb2dVertex& vt) const
{
    return PyThrowBadEs(impObj()->appendVertex(vt.impObj()));
}

void PyDb2dPolyline::appendVertex2(PyDbObjectId& id, const PyDb2dVertex& vt) const
{
    return PyThrowBadEs(impObj()->appendVertex(id.m_id, vt.impObj()));
}

void PyDb2dPolyline::insertVertexAt1(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex) const
{
    return PyThrowBadEs(impObj()->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj()));
}

void PyDb2dPolyline::insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex) const
{
    return PyThrowBadEs(impObj()->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj()));
}

PyDb2dVertex PyDb2dPolyline::openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    return PyDb2dVertex(vertId, mode);
}

PyDbSequenceEnd PyDb2dPolyline::openSequenceEnd(AcDb::OpenMode mode) const
{
    AcDbSequenceEnd* pEnd = nullptr;
    PyThrowBadEs(impObj()->openSequenceEnd(pEnd, mode));
    return PyDbSequenceEnd(pEnd, true);
}

boost::python::list PyDb2dPolyline::vertexIds() const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->vertexIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

AcGePoint3d PyDb2dPolyline::vertexPosition(const AcDb2dVertex& vert) const
{
    return impObj()->vertexPosition(vert);
}

void PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol) const
{
#if defined(_GRXTARGET260) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->makeClosedIfStartAndEndVertexCoincide(distTol));
#endif
}

std::string PyDb2dPolyline::className()
{
    return "AcDb2dPolyline";
}

PyRxClass PyDb2dPolyline::desc()
{
    return PyRxClass(AcDb2dPolyline::desc(), false);
}

PyDb2dPolyline PyDb2dPolyline::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDb2dPolyline, AcDb2dPolyline>(src);
}

PyDb2dPolyline PyDb2dPolyline::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb2dPolyline>(src);
}

AcDb2dPolyline* PyDb2dPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb2dPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb3dPolyline
void makePyDb3dPolylineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- ptype: PyDb.Poly3dType, points: list[PyGe.Point3d], closed: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view splineFitverOverload = "Overloads:\n"
        "- None: Any\n"
        "- splineType: PyDb.Poly3dType, splineSegs: int\n";

    constexpr const std::string_view appendVertexOverload = "Overloads:\n"
        "- vertex: PyDb.Polyline3dVertex\n"
        "- outVertexId: PyDb.ObjectId,vertex: PyDb.Polyline3dVertex\n";

    constexpr const std::string_view insertVertexAtOverload = "Overloads:\n"
        "- indexVt: PyDb.Polyline3dVertex, newVertex: PyDb.Polyline3dVertex\n"
        "- outVertexId: PyDb.ObjectId, indexVtId: PyDb.ObjectId, newVertex: PyDb.Polyline3dVertex\n";

    PyDocString DS("PyDb.Polyline3d");
    class_<PyDb3dPolyline, bases<PyDbCurve>>("Polyline3d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<AcDb::Poly3dType, const boost::python::list&, Adesk::Boolean>(DS.CTOR(ctords, 1230)))
        .def("length", &PyDb3dPolyline::length, DS.ARGS(1241))
        .def("setClosed", &PyDb3dPolyline::setClosed, DS.ARGS({ "val : bool" }, 1247))
        .def("makeClosed", &PyDb3dPolyline::makeClosed, DS.ARGS(1242))
        .def("makeOpen", &PyDb3dPolyline::makeOpen, DS.ARGS(1243))
        .def("polyType", &PyDb3dPolyline::polyType, DS.ARGS(1246))
        .def("setPolyType", &PyDb3dPolyline::setPolyType, DS.ARGS({ "val : PyDb.Poly3dType" }, 1248))
        .def("convertToPolyType", &PyDb3dPolyline::convertToPolyType, DS.ARGS({ "val : PyDb.Poly3dType" }, 1239))
        .def("straighten", &PyDb3dPolyline::straighten, DS.ARGS(1250))
        .def("splineFit", &PyDb3dPolyline::splineFit1)
        .def("splineFit", &PyDb3dPolyline::splineFit2, DS.OVRL(splineFitverOverload, 1249))
        .def("appendVertex", &PyDb3dPolyline::appendVertex1)
        .def("appendVertex", &PyDb3dPolyline::appendVertex2, DS.OVRL(appendVertexOverload, 1238))
        .def("insertVertexAt", &PyDb3dPolyline::insertVertexAt1)
        .def("insertVertexAt", &PyDb3dPolyline::insertVertexAt2, DS.OVRL(insertVertexAtOverload, 1240))
        .def("openVertex", &PyDb3dPolyline::openVertex, DS.ARGS({ "id : PyDb.ObjectId", "mode: PyDb.OpenMode" }, 1245))
        .def("openSequenceEnd", &PyDb3dPolyline::openSequenceEnd, DS.ARGS({ "mode: PyDb.OpenMode" }, 1244))
        .def("vertexIds", &PyDb3dPolyline::vertexIds, DS.ARGS())
        .def("getAcGeCurve", &PyDb3dPolyline::getAcGeCurve1)
        .def("getAcGeCurve", &PyDb3dPolyline::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }, 2775))
        .def("className", &PyDb3dPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3dPolyline::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb3dPolyline::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3dPolyline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDb3dPolyline::PyDb3dPolyline()
    : PyDbCurve(new AcDb3dPolyline(), true)
{
}

PyDb3dPolyline::PyDb3dPolyline(AcDb3dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDb3dPolyline>(id, mode), false)
{
}

PyDb3dPolyline::PyDb3dPolyline(AcDb::Poly3dType pt, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb3dPolyline(pt, listToAcGePoint3dArrayRef(vertices), closed), true)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id)
    : PyDb3dPolyline(id, AcDb::OpenMode::kForNotify)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErased)
    : PyDbCurve(openAcDbObject<AcDb3dPolyline>(id, mode, openErased), false)
{
}

double PyDb3dPolyline::length() const
{
    double val;
    PyThrowBadEs(impObj()->length(val));
    return val;
}

void PyDb3dPolyline::setClosed(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setClosed(val));
}

void PyDb3dPolyline::makeClosed() const
{
    return PyThrowBadEs(impObj()->makeClosed());
}

void PyDb3dPolyline::makeOpen() const
{
    return PyThrowBadEs(impObj()->makeOpen());
}

AcDb::Poly3dType PyDb3dPolyline::polyType() const
{
    return impObj()->polyType();
}

void PyDb3dPolyline::setPolyType(AcDb::Poly3dType val) const
{
    return PyThrowBadEs(impObj()->setPolyType(val));
}

void PyDb3dPolyline::convertToPolyType(AcDb::Poly3dType val) const
{
    return PyThrowBadEs(impObj()->convertToPolyType(val));
}

void PyDb3dPolyline::straighten() const
{
    return PyThrowBadEs(impObj()->straighten());
}

void PyDb3dPolyline::splineFit1() const
{
    return PyThrowBadEs(impObj()->splineFit());
}

void PyDb3dPolyline::splineFit2(AcDb::Poly3dType splineType, Adesk::Int16 splineSegs) const
{
    return PyThrowBadEs(impObj()->splineFit(splineType, splineSegs));
}

void PyDb3dPolyline::appendVertex1(const PyDb3dPolylineVertex& vt) const
{
    return PyThrowBadEs(impObj()->appendVertex(vt.impObj()));
}

void PyDb3dPolyline::appendVertex2(PyDbObjectId& id, const PyDb3dPolylineVertex& vt) const
{
    return PyThrowBadEs(impObj()->appendVertex(id.m_id, vt.impObj()));
}

void PyDb3dPolyline::insertVertexAt1(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex) const
{
    return PyThrowBadEs(impObj()->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj()));
}

void PyDb3dPolyline::insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex) const
{
    return PyThrowBadEs(impObj()->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj()));
}

PyDb3dPolylineVertex PyDb3dPolyline::openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    return PyDb3dPolylineVertex(vertId, mode);
}

PyDbSequenceEnd PyDb3dPolyline::openSequenceEnd(AcDb::OpenMode mode) const
{
    AcDbSequenceEnd* pEnd = nullptr;
    PyThrowBadEs(impObj()->openSequenceEnd(pEnd, mode));
    return PyDbSequenceEnd(pEnd, true);
}

PyGeCompositeCurve3d PyDb3dPolyline::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCompositeCurve3d(pGeCurve);
}

PyGeCompositeCurve3d PyDb3dPolyline::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCompositeCurve3d(pGeCurve);
}

boost::python::list PyDb3dPolyline::vertexIds() const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->vertexIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

std::string PyDb3dPolyline::className()
{
    return "AcDb3dPolyline";
}

PyRxClass PyDb3dPolyline::desc()
{
    return PyRxClass(AcDb3dPolyline::desc(), false);
}

PyDb3dPolyline PyDb3dPolyline::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDb3dPolyline, AcDb3dPolyline>(src);
}

PyDb3dPolyline PyDb3dPolyline::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb3dPolyline>(src);
}

AcDb3dPolyline* PyDb3dPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbArc
void makePyDbArcWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- center: PyGe.Point3d, radius: float, startAngle: float, endAngle: float\n"
        "- center: PyGe.Point3d,normal: PyGe.Vector2d, radius: float, startAngle: float, endAngle: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Arc");
    class_<PyDbArc, bases<PyDbCurve>>("Arc")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, double, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double, double, double>(DS.CTOR(ctords, 1491)))
        .def("center", &PyDbArc::center, DS.ARGS(1519))
        .def("setCenter", &PyDbArc::setCenter, DS.ARGS({ "val:PyGe.Point3d" }, 1524))
        .def("radius", &PyDbArc::radius, DS.ARGS(1523))
        .def("setRadius", &PyDbArc::setRadius, DS.ARGS({ "val:float" }, 1527))
        .def("startAngle", &PyDbArc::startAngle, DS.ARGS(1530))
        .def("setStartAngle", &PyDbArc::setStartAngle, DS.ARGS({ "val:float" }, 1528))
        .def("endAngle", &PyDbArc::endAngle, DS.ARGS(1520))
        .def("setEndAngle", &PyDbArc::setEndAngle, DS.ARGS({ "val:float" }, 1525))
        .def("totalAngle", &PyDbArc::totalAngle, DS.ARGS(1533))
        .def("length", &PyDbArc::length, DS.ARGS(1521))
        .def("thickness", &PyDbArc::thickness, DS.ARGS(1532))
        .def("setThickness", &PyDbArc::setThickness, DS.ARGS({ "val:float" }, 1529))
        .def("normal", &PyDbArc::normal, DS.ARGS(1522))
        .def("setNormal", &PyDbArc::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }, 1526))
        .def("getAcGeCurve", &PyDbArc::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbArc::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }, 2775))
        .def("className", &PyDbArc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbArc::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbArc::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbArc::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbArc::PyDbArc()
    : PyDbCurve(new AcDbArc(), true)
{
}

PyDbArc::PyDbArc(AcDbArc* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbArc>(id, mode), false)
{
}

PyDbArc::PyDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, radius, startAngle, endAngle), true)
{
}

PyDbArc::PyDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, normal, radius, startAngle, endAngle), true)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id)
    : PyDbArc(id, AcDb::OpenMode::kForRead)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbArc>(id, mode, erased), false)
{
}

AcGePoint3d PyDbArc::center() const
{
    return impObj()->center();
}

void PyDbArc::setCenter(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setCenter(val));
}

double PyDbArc::radius() const
{
    return impObj()->radius();
}

void PyDbArc::setRadius(double val) const
{
    return PyThrowBadEs(impObj()->setRadius(val));
}

double PyDbArc::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbArc::setStartAngle(double val) const
{
    return PyThrowBadEs(impObj()->setStartAngle(val));
}

double PyDbArc::endAngle() const
{
    return impObj()->endAngle();
}

void PyDbArc::setEndAngle(double val) const
{
    return PyThrowBadEs(impObj()->setEndAngle(val));
}

double PyDbArc::totalAngle() const
{
    return impObj()->totalAngle();
}

double PyDbArc::length() const
{
    return impObj()->length();
}

double PyDbArc::thickness() const
{
    return impObj()->thickness();
}

void PyDbArc::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbArc::normal() const
{
    return impObj()->normal();
}

void PyDbArc::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

PyGeCircArc3d PyDbArc::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCircArc3d(pGeCurve);
}

PyGeCircArc3d PyDbArc::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCircArc3d(pGeCurve);
}

std::string PyDbArc::className()
{
    return "AcDbArc";
}

PyRxClass PyDbArc::desc()
{
    return PyRxClass(AcDbArc::desc(), false);
}

PyDbArc PyDbArc::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbArc, AcDbArc>(src);
}

PyDbArc PyDbArc::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbArc>(src);
}

AcDbArc* PyDbArc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbArc*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbCircle
void makePyDbCircleWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- center: PyGe.Point3d, normal: PyGe.Vector3d, radius: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Circle");
    class_<PyDbCircle, bases<PyDbCurve>>("Circle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double>(DS.CTOR(ctords, 2683)))
        .def("center", &PyDbCircle::center, DS.ARGS(2685))
        .def("setCenter", &PyDbCircle::setCenter, DS.ARGS({ "val:PyGe.Point3d" }, 2690))
        .def("radius", &PyDbCircle::radius, DS.ARGS(2689))
        .def("setRadius", &PyDbCircle::setRadius, DS.ARGS({ "val:float" }, 2694))
        .def("thickness", &PyDbCircle::thickness, DS.ARGS(2697))
        .def("setThickness", &PyDbCircle::setThickness, DS.ARGS({ "val:float" }, 2695))
        .def("normal", &PyDbCircle::normal, DS.ARGS(2688))
        .def("setNormal", &PyDbCircle::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }, 2693))
        .def("circumference", &PyDbCircle::circumference, DS.ARGS(2686))
        .def("setCircumference", &PyDbCircle::setCircumference, DS.ARGS({ "val:float" }, 2691))
        .def("diameter", &PyDbCircle::diameter, DS.ARGS(2687))
        .def("setDiameter", &PyDbCircle::setDiameter, DS.ARGS({ "val:float" }, 2692))
        .def("getAcGeCurve", &PyDbCircle::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbCircle::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }, 2775))
        .def("className", &PyDbCircle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbCircle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbCircle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbCircle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbCircle::PyDbCircle()
    : PyDbCurve(new AcDbCircle(), true)
{
}

PyDbCircle::PyDbCircle(AcDbCircle* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbCircle>(id, mode), false)
{
}

PyDbCircle::PyDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius)
    : PyDbCurve(new AcDbCircle(cntr, nrm, radius), true)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id)
    : PyDbCircle(id, AcDb::OpenMode::kForRead)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbCircle>(id, mode, erased), false)
{
}

AcGePoint3d PyDbCircle::center() const
{
    return impObj()->center();
}

void PyDbCircle::setCenter(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setCenter(val));
}

double PyDbCircle::radius() const
{
    return impObj()->radius();
}

void PyDbCircle::setRadius(double val) const
{
    return PyThrowBadEs(impObj()->setRadius(val));
}

double PyDbCircle::thickness() const
{
    return impObj()->thickness();
}

void PyDbCircle::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbCircle::normal() const
{
    return impObj()->normal();
}

void PyDbCircle::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbCircle::circumference() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->circumference();
#endif
}

void PyDbCircle::setCircumference(double val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCircumference(val));
#endif
}

double PyDbCircle::diameter() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->diameter();
#endif
}

void PyDbCircle::setDiameter(double val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDiameter(val));
#endif
}

PyGeCircArc3d PyDbCircle::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCircArc3d(pGeCurve);
}

PyGeCircArc3d PyDbCircle::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCircArc3d(pGeCurve);
}

std::string PyDbCircle::className()
{
    return "AcDbCircle";
}

PyRxClass PyDbCircle::desc()
{
    return PyRxClass(AcDbCircle::desc(), false);
}

PyDbCircle PyDbCircle::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbCircle, AcDbCircle>(src);
}

PyDbCircle PyDbCircle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbCircle>(src);
}

AcDbCircle* PyDbCircle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbCircle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbLine
void makePyDbLineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- start: PyGe.Point3d,end: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Line");
    class_<PyDbLine, bases<PyDbCurve>>("Line")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctords, 6027)))
        .def("startPoint", &PyDbLine::startPoint, DS.ARGS(6081))
        .def("setStartPoint", &PyDbLine::setStartPoint, DS.ARGS({ "val:PyGe.Point3d" }, 6079))
        .def("endPoint", &PyDbLine::endPoint, DS.ARGS(6074))
        .def("setEndPoint", &PyDbLine::setEndPoint, DS.ARGS({ "val:PyGe.Point3d" }, 6077))
        .def("thickness", &PyDbLine::thickness, DS.ARGS(6083))
        .def("setThickness", &PyDbLine::setThickness, DS.ARGS({ "val:float" }, 6080))
        .def("normal", &PyDbLine::normal, DS.ARGS(6076))
        .def("setNormal", &PyDbLine::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }, 6078))
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbLine::getOffsetCurvesGivenPlaneNormal, DS.ARGS({ "val:PyGe.Vector3d","offset:float" }, 6075))
        .def("getAcGeCurve", &PyDbLine::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbLine::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }, 2775))
        .def("midPoint", &PyDbLine::midPoint, DS.ARGS())
        .def("direction", &PyDbLine::direction, DS.ARGS())
        .def("className", &PyDbLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLine::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLine::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLine::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbLine::PyDbLine()
    : PyDbCurve(new AcDbLine(), true)
{
}

PyDbLine::PyDbLine(AcDbLine* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbLine>(id, mode), false)
{
}

PyDbLine::PyDbLine(const AcGePoint3d& start, const AcGePoint3d& end)
    : PyDbCurve(new AcDbLine(start, end), true)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id)
    : PyDbLine(id, AcDb::OpenMode::kForRead)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbLine>(id, mode, erased), false)
{
}

AcGePoint3d PyDbLine::startPoint() const
{
    return impObj()->startPoint();
}

void PyDbLine::setStartPoint(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setStartPoint(val));
}

AcGePoint3d PyDbLine::endPoint() const
{
    return impObj()->endPoint();
}

AcGePoint3d PyDbLine::midPoint() const
{
    AcGeLineSeg3d seg(impObj()->startPoint(), impObj()->endPoint());
    return seg.midPoint();
}

void PyDbLine::setEndPoint(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setEndPoint(val));
}

double PyDbLine::thickness() const
{
    return impObj()->thickness();
}

void PyDbLine::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbLine::normal() const
{
    return impObj()->normal();
}

void PyDbLine::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

PyGeLineSeg3d PyDbLine::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeLineSeg3d(pGeCurve);
}

PyGeLineSeg3d PyDbLine::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeLineSeg3d(pGeCurve);
}

AcGeVector3d PyDbLine::direction() const
{
    return impObj()->endPoint() - impObj()->startPoint();
}

std::string PyDbLine::className()
{
    return "AcDbLine";
}

PyRxClass PyDbLine::desc()
{
    return PyRxClass(AcDbLine::desc(), false);
}

PyDbLine PyDbLine::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLine, AcDbLine>(src);
}

PyDbLine PyDbLine::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLine>(src);
}

AcDbLine* PyDbLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPolyline
void makePyDbPolylineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- num_verts: int\n"
        "- pnts: list[PyGe.Point3d]\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Polyline");
    class_<PyDbPolyline, bases<PyDbCurve>>("Polyline")
        .def(init<>())
        .def(init<unsigned int>())
        .def(init<const boost::python::list&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7823)))
        .def("getPoint3dAt", &PyDbPolyline::getPoint3dAt, DS.ARGS({ "idx:int" }, 7839))
        .def("getPoint2dAt", &PyDbPolyline::getPoint2dAt, DS.ARGS({ "idx:int" }, 7839))
        .def("segType", &PyDbPolyline::segType, DS.ARGS({ "idx:int" }, 7854))
        .def("onSegAt", &PyDbPolyline::onSegAt, DS.ARGS({ "idx:int","pt2d:PyGe.Point2d","param:float" }, 7850))
        .def("getLineSeg2dAt", &PyDbPolyline::getLineSeg2dAt, DS.ARGS({ "idx:int" }, 7838))
        .def("getLineSeg3dAt", &PyDbPolyline::getLineSeg3dAt, DS.ARGS({ "idx:int" }, 7838))
        .def("getArcSeg2dAt", &PyDbPolyline::getArcSeg2dAt, DS.ARGS({ "idx:int" }, 7834))
        .def("getArcSeg3dAt", &PyDbPolyline::getArcSeg3dAt, DS.ARGS({ "idx:int" }, 7834))
        .def("setClosed", &PyDbPolyline::setClosed, DS.ARGS({ "val:bool" }, 7856))
        .def("setPlinegen", &PyDbPolyline::setPlinegen, DS.ARGS({ "val:bool" }, 7860))
        .def("setElevation", &PyDbPolyline::setElevation, DS.ARGS({ "elev:float" }, 7858))
        .def("setThickness", &PyDbPolyline::setThickness, DS.ARGS({ "val:float" }, 7862))
        .def("setConstantWidth", &PyDbPolyline::setConstantWidth, DS.ARGS({ "width:float" }, 7857))
        .def("setNormal", &PyDbPolyline::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }, 7859))
        .def("isOnlyLines", &PyDbPolyline::isOnlyLines, DS.ARGS(7844))
        .def("hasPlinegen", &PyDbPolyline::hasPlinegen, DS.ARGS(7842))
        .def("elevation", &PyDbPolyline::elevation, DS.ARGS(7833))
        .def("thickness", &PyDbPolyline::thickness, DS.ARGS(7865))
        .def("getConstantWidth", &PyDbPolyline::getConstantWidth, DS.ARGS(7836))
        .def("normal", &PyDbPolyline::normal, DS.ARGS(7848))
        .def("addVertexAt", &PyDbPolyline::addVertexAt1)
        .def("addVertexAt", &PyDbPolyline::addVertexAt2, DS.ARGS({ "idx:int","pt2d:PyGe.Point2d","bulge:float=0.0","startWidth:float=-1.0","endWidth:float=-1.0" }, 7825))
        .def("removeVertexAt", &PyDbPolyline::removeVertexAt, DS.ARGS({ "idx:int" }, 7851))
        .def("numVerts", &PyDbPolyline::numVerts, DS.ARGS(7849))
        .def("getBulgeAt", &PyDbPolyline::getBulgeAt, DS.ARGS({ "idx:int" }, 7835))
        .def("getStartWidthAt", &PyDbPolyline::getStartWidthAt, DS.ARGS({ "idx:int" }, 7840))
        .def("getEndWidthAt", &PyDbPolyline::getEndWidthAt, DS.ARGS({ "idx:int" }, 7840))
        .def("setPointAt", &PyDbPolyline::setPointAt, DS.ARGS({ "idx:int" ,"pt2d:PyGe.Point2d" }, 7861))
        .def("setBulgeAt", &PyDbPolyline::setBulgeAt, DS.ARGS({ "idx:int" ,"bulge:float" }, 7855))
        .def("setWidthsAt", &PyDbPolyline::setWidthsAt, DS.ARGS({ "idx:int" ,"startWidth:float","endWidth:float" }, 7863))
        .def("minimizeMemory", &PyDbPolyline::minimizeMemory, DS.ARGS(7847))
        .def("maximizeMemory", &PyDbPolyline::maximizeMemory, DS.ARGS(7846))
        .def("reset", &PyDbPolyline::reset, DS.ARGS({ "reuse:bool" ,"numVerts:int" }, 7852))
        .def("hasBulges", &PyDbPolyline::hasBulges, DS.ARGS(7841))
        .def("hasVertexIdentifiers", &PyDbPolyline::hasVertexIdentifiers, DS.ARGS())
        .def("hasWidth", &PyDbPolyline::hasWidth, DS.ARGS(7843))
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDbPolyline::makeClosedIfStartAndEndVertexCoincide, DS.ARGS({ "distTol:float" }, 7845))
        .def("getEcs", &PyDbPolyline::getEcs, DS.ARGS(7837))
        .def("getAcGeCurve", &PyDbPolyline::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbPolyline::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }, 2775))
        .def("getAcGeCurve2d", &PyDbPolyline::getAcGeCurve2d, DS.ARGS())
        .def("toPoint2dList", &PyDbPolyline::toPoint2dList, DS.ARGS())
        .def("toPoint3dList", &PyDbPolyline::toPoint3dList, DS.ARGS())
        .def("toList", &PyDbPolyline::toList, DS.ARGS())
        .def("className", &PyDbPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolyline::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPolyline::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolyline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbPolyline::SegType>("SegType")
        .value("kLine", AcDbPolyline::SegType::kLine)
        .value("kArc", AcDbPolyline::SegType::kArc)
        .value("kCoincident", AcDbPolyline::SegType::kCoincident)
        .value("kPoint", AcDbPolyline::SegType::kPoint)
        .value("kEmpty", AcDbPolyline::SegType::kEmpty)
        ;
}

PyDbPolyline::PyDbPolyline()
    : PyDbCurve(new AcDbPolyline(), true)
{
}

PyDbPolyline::PyDbPolyline(unsigned int num_verts)
    : PyDbCurve(new AcDbPolyline(num_verts), true)
{
}

PyDbPolyline::PyDbPolyline(AcDbPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbPolyline>(id, mode), false)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id)
    : PyDbPolyline(id, AcDb::OpenMode::kForRead)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbPolyline>(id, mode, erased), false)
{
}

PyDbPolyline::PyDbPolyline(const boost::python::list& pnts)
    : PyDbCurve(new AcDbPolyline(boost::python::len(pnts)), true)
{
    if (boost::python::len(pnts) == 0)
        return;

    const extract<AcGePoint2d> extractor2d(pnts[0]);
    if (extractor2d.check())
    {
        auto vec = py_list_to_std_vector<AcGePoint2d>(pnts);
        for (int i = 0; i < vec.size(); i++)
            impObj()->addVertexAt(i, vec[i]);
        return;
    }
    const extract<AcGePoint3d> extractor3d(pnts[0]);
    if (extractor3d.check())
    {
        auto vec = py_list_to_std_vector<AcGePoint3d>(pnts);
        for (int i = 0; i < vec.size(); i++)
            impObj()->addVertexAt(i, AcGePoint2d(vec[i].x, vec[i].y));
        return;
    }
    const extract<boost::python::tuple> extractorTpl(pnts[0]);
    if (extractorTpl.check())
    {
        auto vec = std::vector<boost::python::tuple>(boost::python::stl_input_iterator<boost::python::tuple>(pnts),
            boost::python::stl_input_iterator<boost::python::tuple>());

        for (int i = 0; i < vec.size(); i++)
        {
            auto nlen = boost::python::len(vec[i]);
            if (nlen > 1)
                impObj()->addVertexAt(i, PyListToAcGePoint2d(vec[i]));
        }
        return;
    }
    const extract<boost::python::list> extractorList(pnts[0]);
    if (extractorList.check())
    {
        auto vec = std::vector<boost::python::list>(boost::python::stl_input_iterator<boost::python::list>(pnts),
            boost::python::stl_input_iterator<boost::python::list>());

        for (int i = 0; i < vec.size(); i++)
        {
            auto nlen = boost::python::len(vec[i]);
            if (nlen > 1)
                impObj()->addVertexAt(i, PyListToAcGePoint2d(vec[i]));
        }
        return;
    }
}

AcGePoint3d PyDbPolyline::getPoint3dAt(unsigned int idx) const
{
    AcGePoint3d pnt;
    if (auto es = impObj()->getPointAt(idx, pnt); es != eOk)
        throw PyErrorStatusException(es);
    return pnt;
}

AcGePoint2d PyDbPolyline::getPoint2dAt(unsigned int idx) const
{
    AcGePoint2d pnt;
    if (auto es = impObj()->getPointAt(idx, pnt); es != eOk)
        throw PyErrorStatusException(es);
    return pnt;
}

AcDbPolyline::SegType PyDbPolyline::segType(unsigned int index) const
{
    return impObj()->segType(index);
}

Adesk::Boolean PyDbPolyline::onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const
{
    double _param = param;
    return impObj()->onSegAt(index, pt2d, _param);
}

PyGeLineSeg2d PyDbPolyline::getLineSeg2dAt(unsigned int index) const
{
    AcGeLineSeg2d seg;
    if (auto es = impObj()->getLineSegAt(index, seg); es != eOk)
        throw PyErrorStatusException(es);
    return PyGeLineSeg2d(seg.copy());
}

PyGeLineSeg3d PyDbPolyline::getLineSeg3dAt(unsigned int index) const
{
    AcGeLineSeg3d seg;
    if (auto es = impObj()->getLineSegAt(index, seg); es != eOk)
        throw PyErrorStatusException(es);
    return PyGeLineSeg3d(seg.copy());
}

PyGeCircArc2d PyDbPolyline::getArcSeg2dAt(unsigned int index) const
{
    AcGeCircArc2d seg;
    if (auto es = impObj()->getArcSegAt(index, seg); es != eOk)
        throw PyErrorStatusException(es);
    return PyGeCircArc2d(seg.copy());
}

PyGeCircArc3d PyDbPolyline::getArcSeg3dAt(unsigned int index) const
{
    AcGeCircArc3d seg;
    if (auto es = impObj()->getArcSegAt(index, seg); es != eOk)
        throw PyErrorStatusException(es);
    return PyGeCircArc3d(seg.copy());
}

void PyDbPolyline::setClosed(Adesk::Boolean val) const
{
    impObj()->setClosed(val);
}

void PyDbPolyline::setPlinegen(Adesk::Boolean val) const
{
    impObj()->setPlinegen(val);
}

void PyDbPolyline::setElevation(double val) const
{
    impObj()->setElevation(val);
}

void PyDbPolyline::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

void PyDbPolyline::setConstantWidth(double val) const
{
    return PyThrowBadEs(impObj()->setConstantWidth(val));
}

void PyDbPolyline::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

Adesk::Boolean PyDbPolyline::isOnlyLines() const
{
    return impObj()->isOnlyLines();
}

Adesk::Boolean PyDbPolyline::hasPlinegen() const
{
    return impObj()->hasPlinegen();
}

double PyDbPolyline::elevation() const
{
    return impObj()->elevation();
}

double PyDbPolyline::thickness() const
{
    return impObj()->thickness();
}

double PyDbPolyline::getConstantWidth() const
{
    double w = 0.0;
    if (auto es = impObj()->getConstantWidth(w); es != eOk)
        throw PyErrorStatusException(es);
    return w;
}

AcGeVector3d PyDbPolyline::normal() const
{
    return impObj()->normal();
}

void PyDbPolyline::addVertexAt1(unsigned int index, const AcGePoint2d& pnt) const
{
    return PyThrowBadEs(impObj()->addVertexAt(index, pnt));
}

void PyDbPolyline::addVertexAt2(unsigned int index, const AcGePoint2d& pnt, double bulge, double startWidth, double endWidth) const
{
    return PyThrowBadEs(impObj()->addVertexAt(index, pnt, bulge, startWidth, endWidth));
}

void PyDbPolyline::removeVertexAt(unsigned int index) const
{
    return PyThrowBadEs(impObj()->removeVertexAt(index));
}

unsigned int PyDbPolyline::numVerts() const
{
    return impObj()->numVerts();
}

double PyDbPolyline::getBulgeAt(unsigned int index) const
{
    double w = 0.0;
    PyThrowBadEs(impObj()->getBulgeAt(index, w));
    return w;
}

double PyDbPolyline::getStartWidthAt(unsigned int index) const
{
    double s = 0.0;
    double e = 0.0;
    PyThrowBadEs(impObj()->getWidthsAt(index, s, e));
    return s;
}

double PyDbPolyline::getEndWidthAt(unsigned int index) const
{
    double s = 0.0;
    double e = 0.0;
    PyThrowBadEs(impObj()->getWidthsAt(index, s, e));
    return e;
}

void PyDbPolyline::setPointAt(unsigned int index, const AcGePoint2d& pt) const
{
    return PyThrowBadEs(impObj()->setPointAt(index, pt));
}

void PyDbPolyline::setBulgeAt(unsigned int index, double bulge) const
{
    return PyThrowBadEs(impObj()->setBulgeAt(index, bulge));
}

void PyDbPolyline::setWidthsAt(unsigned int index, double startWidth, double endWidth) const
{
    return PyThrowBadEs(impObj()->setWidthsAt(index, startWidth, endWidth));
}

void PyDbPolyline::minimizeMemory() const
{
    return PyThrowBadEs(impObj()->minimizeMemory());
}

void PyDbPolyline::maximizeMemory() const
{
    return PyThrowBadEs(impObj()->maximizeMemory());
}

void PyDbPolyline::reset(Adesk::Boolean reuse, unsigned int numVerts) const
{
    impObj()->reset(reuse, numVerts);
}

Adesk::Boolean PyDbPolyline::hasBulges() const
{
    return impObj()->hasBulges();
}

Adesk::Boolean PyDbPolyline::hasVertexIdentifiers() const
{
    return impObj()->hasVertexIdentifiers();
}

Adesk::Boolean PyDbPolyline::hasWidth() const
{
    return impObj()->hasWidth();
}

void PyDbPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol) const
{
#if defined(_GRXTARGET260) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->makeClosedIfStartAndEndVertexCoincide(distTol));
#endif
}

PyGeCompositeCurve3d PyDbPolyline::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCompositeCurve3d(pGeCurve);
}

PyGeCompositeCurve3d PyDbPolyline::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCompositeCurve3d(pGeCurve);
}

PyGeCompositeCurve2d PyDbPolyline::getAcGeCurve2d() const
{
    AcGeIntArray own;
    AcGeVoidPointerArray arr;
    for (size_t idx = 0; idx < impObj()->numVerts(); idx++)
    {
        if (impObj()->segType(idx) == AcDbPolyline::kLine)
        {
            AcGeLineSeg2d* seg = new AcGeLineSeg2d();
            PyThrowBadEs(impObj()->getLineSegAt(idx, *seg));
            own.append(1);
            arr.append(seg);
        }
        else if (impObj()->segType(idx) == AcDbPolyline::kArc)
        {
            AcGeCircArc2d* seg = new AcGeCircArc2d();
            PyThrowBadEs(impObj()->getArcSegAt(idx, *seg));
            own.append(1);
            arr.append(seg);
        }
    }
    return PyGeCompositeCurve2d{ new AcGeCompositeCurve2d(arr, own) };
}

boost::python::list PyDbPolyline::toPoint2dList() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint2d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(pnt);
    }
    return pyList;
}

boost::python::list PyDbPolyline::toPoint3dList() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint3d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(pnt);
    }
    return pyList;
}

boost::python::list PyDbPolyline::toList() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint2d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(boost::python::make_tuple(pnt.x, pnt.y));
    }
    return pyList;
}

std::string PyDbPolyline::className()
{
    return "AcDbPolyline";
}

PyRxClass PyDbPolyline::desc()
{
    return PyRxClass(AcDbPolyline::desc(), false);
}

PyDbPolyline PyDbPolyline::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPolyline, AcDbPolyline>(src);
}

PyDbPolyline PyDbPolyline::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPolyline>(src);
}

AcDbPolyline* PyDbPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbDace
void makePyDbFaceWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pt0 : PyGe.Point3d, pt1 : PyGe.Point3d, pt2 : PyGe.Point3d\n"
        "- pt0 : PyGe.Point3d, pt1 : PyGe.Point3d, pt2 : PyGe.Point3d,pt3 : PyGe.Point3d\n"
        "- pt0 : PyGe.Point3d, pt1 : PyGe.Point3d, pt2 : PyGe.Point3d, e0vis: bool, e1vis: bool, e2vis: bool, e3vis: bool, e4vis: bool\n"
        "- pt0 : PyGe.Point3d, pt1 : PyGe.Point3d, pt2 : PyGe.Point3d,pt3 : PyGe.Point3d, e0vis: bool, e1vis: bool, e2vis: bool, e3vis: bool, e4vis: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Face");
    class_<PyDbFace, bases<PyDbEntity>>("Face")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>(DS.CTOR(ctords, 4555)))
        .def("getVertexAt", &PyDbFace::getVertexAt, DS.ARGS({ "vIndex:int" }, 4576))
        .def("setVertexAt", &PyDbFace::setVertexAt, DS.ARGS({ "vIndex:int","pnt:PyGe.Point3d" }, 4581))
        .def("isEdgeVisibleAt", &PyDbFace::isEdgeVisibleAt, DS.ARGS({ "vIndex:int" }, 4577))
        .def("makeEdgeVisibleAt", &PyDbFace::makeEdgeVisibleAt, DS.ARGS({ "vIndex:int" }, 4580))
        .def("makeEdgeInvisibleAt", &PyDbFace::makeEdgeInvisibleAt, DS.ARGS({ "vIndex:int" }, 4579))
        .def("className", &PyDbFace::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFace::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbFace::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFace::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbFace::PyDbFace()
    : PyDbEntity(new AcDbFace(), true)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id)
    : PyDbFace(id, AcDb::OpenMode::kForRead)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbFace>(id, mode), false)
{
}

PyDbFace::PyDbFace(AcDbFace* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, pt3, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, e0vis, e1vis, e2vis, e3vis), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, pt3, e0vis, e1vis, e2vis, e3vis), true)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbFace>(id, mode, erased), false)
{
}

AcGePoint3d PyDbFace::getVertexAt(Adesk::UInt16 val) const
{
    AcGePoint3d rPoint;
    PyThrowBadEs(impObj()->getVertexAt(val, rPoint));
    return rPoint;
}

void PyDbFace::setVertexAt(Adesk::UInt16 val, const AcGePoint3d& pnt) const
{
    return PyThrowBadEs(impObj()->setVertexAt(val, pnt));
}

Adesk::Boolean PyDbFace::isEdgeVisibleAt(Adesk::UInt16 val) const
{
    Adesk::Boolean rval;
    PyThrowBadEs(impObj()->isEdgeVisibleAt(val, rval));
    return rval;
}

void PyDbFace::makeEdgeVisibleAt(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->makeEdgeVisibleAt(val));
}

void PyDbFace::makeEdgeInvisibleAt(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->makeEdgeInvisibleAt(val));
}

std::string PyDbFace::className()
{
    return "AcDbFace";
}

PyRxClass PyDbFace::desc()
{
    return PyRxClass(AcDbFace::desc(), false);
}

PyDbFace PyDbFace::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbFace, AcDbFace>(src);
}

PyDbFace PyDbFace::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbFace>(src);
}

AcDbFace* PyDbFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFace*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbFcf
void makePyDbFcfWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- val: str, pnt: PyGe.Point3d, normal: PyGe.Vector3d, direction: PyGe.Vector3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setDimstyleDataOverloads = "Overloads:\n"
        "- val: PyDb.DimStyleTableRecord\n"
        "- val: PyDb.ObjectId\n";

    PyDocString DS("Fcf");
    class_<PyDbFcf, bases<PyDbEntity>>("Fcf")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const std::string&, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&>(DS.CTOR(ctords, 4585)))
        .def("setText", &PyDbFcf::setText, DS.ARGS({ "val:str" }, 4611))
        .def("text", &PyDbFcf::text, DS.ARGS(4613))
        .def("textAll", &PyDbFcf::textAll, DS.ARGS(4613))
        .def("setLocation", &PyDbFcf::setLocation, DS.ARGS({ "val:PyGe.Point3d" }, 4609))
        .def("location", &PyDbFcf::location, DS.ARGS(4598))
        .def("setOrientation", &PyDbFcf::setOrientation, DS.ARGS({ "normal:PyGe.Vector3d","direction:PyGe.Vector3d" }, 4610))
        .def("normal", &PyDbFcf::normal, DS.ARGS(4599))
        .def("direction", &PyDbFcf::direction, DS.ARGS(4594))
        .def("getBoundingPoints", &PyDbFcf::getBoundingPoints, DS.ARGS(4596))
        .def("getBoundingPline", &PyDbFcf::getBoundingPline, DS.ARGS(4595))
        .def("setDimensionStyle", &PyDbFcf::setDimensionStyle, DS.ARGS({ "val:PyDb.ObjectId" }, 4602))
        .def("dimensionStyle", &PyDbFcf::dimensionStyle, DS.ARGS(4589))
        .def("getDimstyleData", &PyDbFcf::getDimstyleData, DS.ARGS(4597))
        .def("setDimstyleData", &PyDbFcf::setDimstyleData2)
        .def("setDimstyleData", &PyDbFcf::setDimstyleData1, DS.OVRL(setDimstyleDataOverloads, 4605))
        .def("setDimVars", &PyDbFcf::setDimVars, DS.ARGS(4608))
        .def("dimclrd", &PyDbFcf::dimclrd, DS.ARGS(4587))
        .def("dimclrt", &PyDbFcf::dimclrt, DS.ARGS(4588))
        .def("dimgap", &PyDbFcf::dimgap, DS.ARGS(4590))
        .def("dimscale", &PyDbFcf::dimscale, DS.ARGS(4591))
        .def("dimtxsty", &PyDbFcf::dimtxsty, DS.ARGS(4592))
        .def("dimtxt", &PyDbFcf::dimtxt, DS.ARGS(4593))
        .def("setDimclrd", &PyDbFcf::setDimclrd, DS.ARGS({ "val:Color" }, 4600))
        .def("setDimclrt", &PyDbFcf::setDimclrt, DS.ARGS({ "val:Color" }, 4601))
        .def("setDimgap", &PyDbFcf::setDimgap, DS.ARGS({ "val:float" }, 4603))
        .def("setDimscale", &PyDbFcf::setDimscale, DS.ARGS({ "val:float" }, 4604))
        .def("setDimtxsty", &PyDbFcf::setDimtxsty, DS.ARGS({ "id: PyDb.ObjectId" }, 4606))
        .def("setDimtxt", &PyDbFcf::setDimtxt, DS.ARGS({ "val:float" }, 4607))
        .def("className", &PyDbFcf::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFcf::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbFcf::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFcf::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbFcf::PyDbFcf()
    : PyDbEntity(new AcDbFcf(), true)
{
}

PyDbFcf::PyDbFcf(AcDbFcf* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbFcf::PyDbFcf(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbFcf>(id, mode), false)
{
}

PyDbFcf::PyDbFcf(const std::string& str, const AcGePoint3d& pnt, const AcGeVector3d& normal, const AcGeVector3d& direction)
    : PyDbEntity(new AcDbFcf(utf8_to_wstr(str).c_str(), pnt, normal, direction), true)
{
}

PyDbFcf::PyDbFcf(const PyDbObjectId& id)
    : PyDbFcf(id, AcDb::OpenMode::kForRead)
{
}

PyDbFcf::PyDbFcf(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbFcf>(id, mode, erased), false)
{
}

void PyDbFcf::setText(const std::string& val) const
{
    impObj()->setText(utf8_to_wstr(val).c_str());
}

std::string PyDbFcf::text(int lineNo) const
{
    return wstr_to_utf8(impObj()->text(lineNo));
}

std::string PyDbFcf::textAll() const
{
    return wstr_to_utf8(impObj()->text());
}

void PyDbFcf::setLocation(const AcGePoint3d& val) const
{
    impObj()->setLocation(val);
}

AcGePoint3d PyDbFcf::location() const
{
    return impObj()->location();
}

void PyDbFcf::setOrientation(const AcGeVector3d& norm, const AcGeVector3d& dir) const
{
    impObj()->setOrientation(norm, dir);
}

AcGeVector3d PyDbFcf::normal() const
{
    return impObj()->normal();
}

AcGeVector3d PyDbFcf::direction() const
{
    return impObj()->direction();
}

boost::python::list PyDbFcf::getBoundingPoints() const
{
    PyAutoLockGIL loc;
    AcGePoint3dArray a;
    boost::python::list l;
    impObj()->getBoundingPoints(a);
    for (auto& p : a)
        l.append(p);
    return l;
}

boost::python::list PyDbFcf::getBoundingPline() const
{
    PyAutoLockGIL loc;
    AcGePoint3dArray a;
    boost::python::list l;
    impObj()->getBoundingPline(a);
    for (auto& p : a)
        l.append(p);
    return l;
}

void PyDbFcf::setDimensionStyle(const PyDbHardPointerId& id) const
{
    impObj()->setDimensionStyle(id.m_id);
}

PyDbHardPointerId PyDbFcf::dimensionStyle() const
{
    return PyDbHardPointerId(impObj()->dimensionStyle());
}

PyDbDimStyleTableRecord PyDbFcf::getDimstyleData() const
{
    AcDbDimStyleTableRecord* pSyle = nullptr;
    PyThrowBadEs(impObj()->getDimstyleData(pSyle));
    return PyDbDimStyleTableRecord(pSyle, true);
}

void PyDbFcf::setDimstyleData2(const PyDbDimStyleTableRecord& pNewData) const
{
    return PyThrowBadEs(impObj()->setDimstyleData(pNewData.impObj()));
}

void PyDbFcf::setDimstyleData1(const PyDbObjectId& newDataId) const
{
    return PyThrowBadEs(impObj()->setDimstyleData(newDataId.m_id));
}

void PyDbFcf::setDimVars() const
{
    impObj()->setDimVars();
}

AcCmColor PyDbFcf::dimclrd() const
{
    return impObj()->dimclrd();
}

AcCmColor PyDbFcf::dimclrt() const
{
    return impObj()->dimclrt();
}

double PyDbFcf::dimgap() const
{
    return impObj()->dimgap();
}

double PyDbFcf::dimscale() const
{
    return impObj()->dimscale();
}

PyDbObjectId PyDbFcf::dimtxsty() const
{
    return PyDbObjectId(impObj()->dimtxsty());
}

double PyDbFcf::dimtxt() const
{
    return impObj()->dimtxt();
}

void PyDbFcf::setDimclrd(AcCmColor& val) const
{
    return PyThrowBadEs(impObj()->setDimclrd(val));
}

void PyDbFcf::setDimclrt(AcCmColor& val) const
{
    return PyThrowBadEs(impObj()->setDimclrt(val));
}

void PyDbFcf::setDimgap(double val) const
{
    return PyThrowBadEs(impObj()->setDimgap(val));
}

void PyDbFcf::setDimscale(double val) const
{
    return PyThrowBadEs(impObj()->setDimscale(val));
}

void PyDbFcf::setDimtxsty(PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setDimtxsty(val.m_id));
}

void PyDbFcf::setDimtxt(double val) const
{
    return PyThrowBadEs(impObj()->setDimtxt(val));
}

std::string PyDbFcf::className()
{
    return "AcDbFcf";
}

PyRxClass PyDbFcf::desc()
{
    return PyRxClass(AcDbFcf::desc(), false);
}

PyDbFcf PyDbFcf::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbFcf, AcDbFcf>(src);
}

PyDbFcf PyDbFcf::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbFcf>(src);
}

AcDbFcf* PyDbFcf::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFcf*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbSolid
void makePyDbSolidWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pnt0: PyGe.Point3d, pnt1: PyGe.Point3d, pnt2: PyGe.Point3d\n"
        "- pnt0: PyGe.Point3d, pnt1: PyGe.Point3d, pnt2: PyGe.Point3d, pnt3: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Solid");
    class_<PyDbSolid, bases<PyDbEntity>>("Solid")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctords, 8653)))
        .def("getPointAt", &PyDbSolid::getPointAt, DS.ARGS({ "idx: int" }, 8668))
        .def("setPointAt", &PyDbSolid::setPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point3d" }, 8672))
        .def("thickness", &PyDbSolid::thickness, DS.ARGS(8675))
        .def("setThickness", &PyDbSolid::setThickness, DS.ARGS({ "val: float" }, 8673))
        .def("normal", &PyDbSolid::normal, DS.ARGS(8669))
        .def("setNormal", &PyDbSolid::setNormal, DS.ARGS({ "vec: PyGe.Vector3d" }, 8671))
        .def("className", &PyDbSolid::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSolid::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSolid::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSolid::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSolid::PyDbSolid()
    : PyDbSolid(new AcDbSolid(), true)
{
}

PyDbSolid::PyDbSolid(const PyDbObjectId& id)
    : PyDbSolid(openAcDbObject<AcDbSolid>(id, AcDb::kForRead), false)
{
}

PyDbSolid::PyDbSolid(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSolid(openAcDbObject<AcDbSolid>(id, mode), false)
{
}

PyDbSolid::PyDbSolid(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSolid(openAcDbObject<AcDbSolid>(id, mode, erased), false)
{
}

PyDbSolid::PyDbSolid(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
    : PyDbSolid(new AcDbSolid(pnt0, pnt1, pnt2), true)
{
}

PyDbSolid::PyDbSolid(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2, const AcGePoint3d& pnt3)
    : PyDbSolid(new AcDbSolid(pnt0, pnt1, pnt2, pnt3), true)
{
}

PyDbSolid::PyDbSolid(AcDbSolid* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcGePoint3d PyDbSolid::getPointAt(Adesk::UInt16 idx) const
{
    AcGePoint3d pntRes;
    PyThrowBadEs(impObj()->getPointAt(idx, pntRes));
    return pntRes;
}

void PyDbSolid::setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val) const
{
    PyThrowBadEs(impObj()->setPointAt(idx, val));
}

double PyDbSolid::thickness() const
{
    return impObj()->thickness();
}

void PyDbSolid::setThickness(double val) const
{
    PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbSolid::normal() const
{
    return impObj()->normal();
}

void PyDbSolid::setNormal(const AcGeVector3d& val) const
{
    PyThrowBadEs(impObj()->setNormal(val));
}

std::string PyDbSolid::className()
{
    return "AcDbSolid";
}

PyRxClass PyDbSolid::desc()
{
    return PyRxClass(AcDbSolid::desc(), false);
}

PyDbSolid PyDbSolid::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSolid, AcDbSolid>(src);
}

PyDbSolid PyDbSolid::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSolid>(src);
}

AcDbSolid* PyDbSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSolid*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbTrace
void makePyDbTraceWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pnt0: PyGe.Point3d, pnt1: PyGe.Point3d, pnt2: PyGe.Point3d, pnt3: PyGe.Point3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Trace");
    class_<PyDbTrace, bases<PyDbEntity>>("Trace")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctords, 9769)))
        .def("getPointAt", &PyDbTrace::getPointAt, DS.ARGS({ "idx: int" }, 9773))
        .def("setPointAt", &PyDbTrace::setPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point3d" }, 9778))
        .def("thickness", &PyDbTrace::thickness, DS.ARGS(9781))
        .def("setThickness", &PyDbTrace::setThickness, DS.ARGS({ "val: float" }, 9779))
        .def("normal", &PyDbTrace::normal, DS.ARGS(9775))
        .def("setNormal", &PyDbTrace::setNormal, DS.ARGS({ "vec: PyGe.Vector3d" }, 9777))
        .def("className", &PyDbTrace::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTrace::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbTrace::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTrace::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbTrace::PyDbTrace()
    : PyDbTrace(new AcDbTrace(), true)
{
}

PyDbTrace::PyDbTrace(const PyDbObjectId& id)
    : PyDbTrace(openAcDbObject<AcDbTrace>(id, AcDb::kForRead), false)
{
}

PyDbTrace::PyDbTrace(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbTrace(openAcDbObject<AcDbTrace>(id, mode), false)
{
}

PyDbTrace::PyDbTrace(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbTrace(openAcDbObject<AcDbTrace>(id, mode, erased), false)
{
}

PyDbTrace::PyDbTrace(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2, const AcGePoint3d& pnt3)
    : PyDbTrace(new AcDbTrace(pnt0, pnt1, pnt2, pnt3), true)
{
}

PyDbTrace::PyDbTrace(AcDbTrace* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcGePoint3d PyDbTrace::getPointAt(Adesk::UInt16 idx) const
{
    AcGePoint3d pntRes;
    PyThrowBadEs(impObj()->getPointAt(idx, pntRes));
    return pntRes;
}

void PyDbTrace::setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val) const
{
    PyThrowBadEs(impObj()->setPointAt(idx, val));
}

double PyDbTrace::thickness() const
{
    return impObj()->thickness();
}

void PyDbTrace::setThickness(double val) const
{
    PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbTrace::normal() const
{
    return impObj()->normal();
}

void PyDbTrace::setNormal(const AcGeVector3d& val) const
{
    PyThrowBadEs(impObj()->setNormal(val));
}

std::string PyDbTrace::className()
{
    return "AcDbTrace";
}

PyRxClass PyDbTrace::desc()
{
    return PyRxClass(AcDbTrace::desc(), false);
}

PyDbTrace PyDbTrace::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbTrace, AcDbTrace>(src);
}

PyDbTrace PyDbTrace::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbTrace>(src);
}

AcDbTrace* PyDbTrace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbTrace*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbShape
void makePyDbShapeWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pnt: PyGe.Point3d, size: float, rotation: float, widthFactor: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Shape");
    class_<PyDbShape, bases<PyDbEntity>>("Shape")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, double, double, double>(DS.CTOR(ctords, 8585)))
        .def("position", &PyDbShape::position, DS.ARGS(8592))
        .def("setPosition", &PyDbShape::setPosition, DS.ARGS({ "pt: PyGe.Point3d" }, 8597))
        .def("size", &PyDbShape::size, DS.ARGS(8607))
        .def("setSize", &PyDbShape::setSize, DS.ARGS({ "val: float" }, 8601))
        .def("name", &PyDbShape::name, DS.ARGS(8589))
        .def("setName", &PyDbShape::setName, DS.ARGS({ "val: str" }, 8594))
        .def("rotation", &PyDbShape::rotation, DS.ARGS(8593))
        .def("setRotation", &PyDbShape::setRotation, DS.ARGS({ "val: float" }, 8598))
        .def("widthFactor", &PyDbShape::widthFactor, DS.ARGS(8611))
        .def("setWidthFactor", &PyDbShape::setWidthFactor, DS.ARGS({ "val: float" }, 8604))
        .def("oblique", &PyDbShape::oblique, DS.ARGS(8591))
        .def("setOblique", &PyDbShape::setOblique, DS.ARGS({ "val: float" }, 8596))
        .def("thickness", &PyDbShape::thickness, DS.ARGS(8610))
        .def("setThickness", &PyDbShape::setThickness, DS.ARGS({ "val: float" }, 8603))
        .def("normal", &PyDbShape::normal, DS.ARGS(8590))
        .def("setNormal", &PyDbShape::setNormal, DS.ARGS({ "vec: PyGe.Vector3d" }, 8595))
        .def("shapeNumber", &PyDbShape::shapeNumber, DS.ARGS(8606))
        .def("setShapeNumber", &PyDbShape::setShapeNumber, DS.ARGS({ "idx: int" }, 8600))
        .def("styleId", &PyDbShape::styleId, DS.ARGS(8608))
        .def("setStyleId", &PyDbShape::setStyleId, DS.ARGS({ "id: PyDb.ObjectId" }, 8602))
        .def("className", &PyDbShape::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbShape::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbShape::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbShape::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbShape::PyDbShape()
    : PyDbShape(new AcDbShape(), true)
{
}

PyDbShape::PyDbShape(const PyDbObjectId& id)
    : PyDbShape(openAcDbObject<AcDbShape>(id, AcDb::kForRead), false)
{
}

PyDbShape::PyDbShape(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbShape(openAcDbObject<AcDbShape>(id, mode), false)
{
}

PyDbShape::PyDbShape(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbShape(openAcDbObject<AcDbShape>(id, mode, erased), false)
{
}

PyDbShape::PyDbShape(const AcGePoint3d& position, double size, double rotation, double widthFactor)
    : PyDbShape(new AcDbShape(position, size, rotation, widthFactor), true)
{
}

PyDbShape::PyDbShape(AcDbShape* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcGePoint3d PyDbShape::position() const
{
    return impObj()->position();
}

void PyDbShape::setPosition(const AcGePoint3d& val) const
{
    PyThrowBadEs(impObj()->setPosition(val));
}

double PyDbShape::size() const
{
    return impObj()->size();
}

void PyDbShape::setSize(double val) const
{
    PyThrowBadEs(impObj()->setSize(val));
}

std::string PyDbShape::name() const
{
#if defined(_BRXTARGET250)
    return wstr_to_utf8(impObj()->name());
#else
    AcString val;
    PyThrowBadEs(impObj()->name(val));
    return wstr_to_utf8(val);
#endif
}

void PyDbShape::setName(const std::string& val) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(val).c_str()));
}

double PyDbShape::rotation() const
{
    return impObj()->rotation();
}

void PyDbShape::setRotation(double val) const
{
    PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbShape::widthFactor() const
{
    return impObj()->widthFactor();
}

void PyDbShape::setWidthFactor(double val) const
{
    PyThrowBadEs(impObj()->setWidthFactor(val));
}

double PyDbShape::oblique() const
{
    return impObj()->oblique();
}

void PyDbShape::setOblique(double val) const
{
    PyThrowBadEs(impObj()->setOblique(val));
}

double PyDbShape::thickness() const
{
    return impObj()->thickness();
}

void PyDbShape::setThickness(double val) const
{
    PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbShape::normal() const
{
    return impObj()->normal();
}

void PyDbShape::setNormal(const AcGeVector3d& val) const
{
    PyThrowBadEs(impObj()->setNormal(val));
}

Adesk::Int16 PyDbShape::shapeNumber() const
{
    return impObj()->shapeNumber();
}

void PyDbShape::setShapeNumber(Adesk::Int16 idx) const
{
    PyThrowBadEs(impObj()->setShapeNumber(idx));
}

PyDbObjectId PyDbShape::styleId() const
{
    return impObj()->styleId();
}

void PyDbShape::setStyleId(const PyDbObjectId& id) const
{
    PyThrowBadEs(impObj()->setStyleId(id.m_id));
}

std::string PyDbShape::className()
{
    return "AcDbShape";
}

PyRxClass PyDbShape::desc()
{
    return PyRxClass(AcDbShape::desc(), false);
}

PyDbShape PyDbShape::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbShape, AcDbShape>(src);
}

PyDbShape PyDbShape::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbShape>(src);
}

AcDbShape* PyDbShape::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbShape*>(m_pyImp.get());
}
