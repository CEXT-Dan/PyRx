#include "stdafx.h"
#include "PyDbLeader.h"
#include "PyDbObjectId.h"
#include "PyGePlane.h"
#include "PyDbEnts.h"
#include "PyDbMText.h"

using namespace boost::python;

//----------------------------------------------------------------------------------
//PyDbLeader
void makePyDbLeaderWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("Leader");
    class_<PyDbLeader, bases<PyDbCurve>>("Leader")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 5888)))
        .def("setPlane", &PyDbLeader::setPlane, DS.ARGS({ "val: PyGe.Plane" }))
        .def("normal", &PyDbLeader::normal, DS.ARGS())
        .def("numVertices", &PyDbLeader::numVertices, DS.ARGS())
        .def("appendVertex", &PyDbLeader::appendVertex, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("removeLastVertex", &PyDbLeader::removeLastVertex, DS.ARGS())
        .def("firstVertex", &PyDbLeader::firstVertex, DS.ARGS())
        .def("lastVertex", &PyDbLeader::lastVertex, DS.ARGS())
        .def("vertexAt", &PyDbLeader::vertexAt, DS.ARGS({ "val: int" }))
        .def("setVertexAt", &PyDbLeader::setVertexAt, DS.ARGS({ "val: int","pt: PyGe.Point3d" }))
        .def("hasArrowHead", &PyDbLeader::hasArrowHead, DS.ARGS())
        .def("disableArrowHead", &PyDbLeader::disableArrowHead, DS.ARGS())
        .def("setHasArrowHead", &PyDbLeader::setHasArrowHead, DS.ARGS({ "val: bool" }))
        .def("hasHookLine", &PyDbLeader::hasHookLine, DS.ARGS())
        .def("setToSplineLeader", &PyDbLeader::setToSplineLeader, DS.ARGS())
        .def("setToStraightLeader", &PyDbLeader::setToStraightLeader, DS.ARGS())
        .def("isSplined", &PyDbLeader::isSplined, DS.ARGS())
        .def("setSplined", &PyDbLeader::setSplined, DS.ARGS({ "val: bool" }))
        .def("dimensionStyle", &PyDbLeader::dimensionStyle, DS.ARGS())
        .def("setDimensionStyle", &PyDbLeader::setDimensionStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setDimstyleData", &PyDbLeader::setDimstyleData, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("attachAnnotation", &PyDbLeader::attachAnnotation, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("detachAnnotation", &PyDbLeader::detachAnnotation, DS.ARGS())
        .def("annotationObjId", &PyDbLeader::annotationObjId, DS.ARGS())
        .def("setAnnotationObjId", &PyDbLeader::setAnnotationObjId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("evaluateLeader", &PyDbLeader::evaluateLeader, DS.ARGS())
        .def("annotationOffset", &PyDbLeader::annotationOffset, DS.ARGS())
        .def("setAnnotationOffset", &PyDbLeader::setAnnotationOffset, DS.ARGS({ "vec: PyGe.Vector3d" }))
        .def("annoType", &PyDbLeader::annoType, DS.ARGS())
        .def("annoHeight", &PyDbLeader::annoHeight, DS.ARGS())
        .def("annoWidth", &PyDbLeader::annoWidth, DS.ARGS())
        .def("dimasz", &PyDbLeader::dimasz, DS.ARGS())
        .def("dimclrd", &PyDbLeader::dimclrd, DS.ARGS())
        .def("dimgap", &PyDbLeader::dimgap, DS.ARGS())
        .def("dimlwd", &PyDbLeader::dimlwd, DS.ARGS())
        .def("dimsah", &PyDbLeader::dimsah, DS.ARGS())
        .def("dimscale", &PyDbLeader::dimscale, DS.ARGS())
        .def("dimtad", &PyDbLeader::dimtad, DS.ARGS())
        .def("dimtxsty", &PyDbLeader::dimtxsty, DS.ARGS())
        .def("dimtxt", &PyDbLeader::dimtxt, DS.ARGS())
        .def("setDimasz", &PyDbLeader::setDimasz, DS.ARGS({ "val: float" }))
        .def("setDimclrd", &PyDbLeader::setDimclrd, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("setDimgap", &PyDbLeader::setDimgap, DS.ARGS({ "val: float" }))
        .def("setDimldrblk", &PyDbLeader::setDimldrblk1)
        .def("setDimldrblk", &PyDbLeader::setDimldrblk2, DS.ARGS({ "id: str|PyDb.ObjectId" }))
        .def("setDimlwd", &PyDbLeader::setDimlwd, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("setDimsah", &PyDbLeader::setDimsah, DS.ARGS({ "val: bool" }))
        .def("setDimscale", &PyDbLeader::setDimscale, DS.ARGS({ "val: float" }))
        .def("setDimtad", &PyDbLeader::setDimtad, DS.ARGS({ "val: int" }))
        .def("setDimtxsty", &PyDbLeader::setDimtxsty, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setDimtxt", &PyDbLeader::setDimtxt, DS.ARGS({ "val: float" }))
        .def("modified", &PyDbLeader::modified, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("erased", &PyDbLeader::erased1)
        .def("erased", &PyDbLeader::erased2, DS.ARGS({ "obj: PyDb.DbObject","val: bool=True" }))
        .def("goodbye", &PyDbLeader::goodbye, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("copied", &PyDbLeader::copied, DS.ARGS({ "obja: PyDb.DbObject","objb: PyDb.DbObject" }))
        .def("setColorIndex", &PyDbLeader::setColorIndex1)
        .def("setColorIndex", &PyDbLeader::setColorIndex2, DS.ARGS({ "idx: int","dosubents: bool=True" }))
        .def("className", &PyDbLeader::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLeader::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLeader::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLeader::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbLeader::AnnoType>("AnnoType")
        .value("kMText", AcDbLeader::AnnoType::kMText)
        .value("kFcf", AcDbLeader::AnnoType::kFcf)
        .value("kBlockRef", AcDbLeader::AnnoType::kBlockRef)
        .value("kNoAnno", AcDbLeader::AnnoType::kNoAnno)
        .export_values()
        ;
}

PyDbLeader::PyDbLeader()
    : PyDbCurve(new AcDbLeader(), true)
{
}

PyDbLeader::PyDbLeader(AcDbLeader* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbLeader::PyDbLeader(const PyDbObjectId& id)
    : PyDbCurve(openAcDbObject<AcDbLeader>(id), false)
{
}

PyDbLeader::PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbLeader>(id, mode), false)
{
}

PyDbLeader::PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbLeader>(id, mode, erased), false)
{
}

void PyDbLeader::setPlane(const PyGePlane& plane) const
{
    impObj()->setPlane(*plane.impObj());
}

AcGeVector3d PyDbLeader::normal() const
{
    return impObj()->normal();
}

int PyDbLeader::numVertices() const
{
    return impObj()->numVertices();
}

Adesk::Boolean PyDbLeader::appendVertex(const AcGePoint3d& val) const
{
    return impObj()->appendVertex(val);
}

void PyDbLeader::removeLastVertex() const
{
    return impObj()->removeLastVertex();
}

AcGePoint3d PyDbLeader::firstVertex() const
{
    return impObj()->firstVertex();
}

AcGePoint3d PyDbLeader::lastVertex() const
{
    return impObj()->lastVertex();
}

AcGePoint3d PyDbLeader::vertexAt(int idx) const
{
    return impObj()->vertexAt(idx);
}

Adesk::Boolean PyDbLeader::setVertexAt(int idx, const AcGePoint3d& val) const
{
    return impObj()->setVertexAt(idx, val);
}

Adesk::Boolean PyDbLeader::hasArrowHead() const
{
    return impObj()->hasArrowHead();
}

void PyDbLeader::enableArrowHead() const
{
    return impObj()->enableArrowHead();
}

void PyDbLeader::disableArrowHead() const
{
    return impObj()->disableArrowHead();
}

void PyDbLeader::setHasArrowHead(Adesk::Boolean bEnable) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setHasArrowHead(bEnable);
#endif
}

Adesk::Boolean PyDbLeader::hasHookLine() const
{
    return impObj()->hasHookLine();
}

void PyDbLeader::setToSplineLeader() const
{
    return impObj()->setToSplineLeader();
}

void PyDbLeader::setToStraightLeader() const
{
    return impObj()->setToStraightLeader();
}

Adesk::Boolean PyDbLeader::isSplined() const
{
    return impObj()->isSplined();
}

void PyDbLeader::setSplined(Adesk::Boolean bSplined) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setSplined(bSplined);
#endif
}

PyDbHardPointerId PyDbLeader::dimensionStyle() const
{
    return PyDbHardPointerId(impObj()->dimensionStyle());
}

void PyDbLeader::setDimensionStyle(const PyDbHardPointerId& val) const
{
    return impObj()->setDimensionStyle(val.m_id);
}

void PyDbLeader::setDimstyleData(const PyDbObjectId& newDataId) const
{
    return PyThrowBadEs(impObj()->setDimstyleData(newDataId.m_id));
}

void PyDbLeader::attachAnnotation(const PyDbObjectId& annoId) const
{
    return PyThrowBadEs(impObj()->attachAnnotation(annoId.m_id));
}

void PyDbLeader::detachAnnotation() const
{
    return PyThrowBadEs(impObj()->detachAnnotation());
}

PyDbObjectId PyDbLeader::annotationObjId() const
{
    return PyDbObjectId(impObj()->annotationObjId());
}

void PyDbLeader::setAnnotationObjId(const PyDbObjectId& annoId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAnnotationObjId(annoId.m_id));
#endif
}

void PyDbLeader::evaluateLeader() const
{
    return PyThrowBadEs(impObj()->evaluateLeader());
}

AcGeVector3d PyDbLeader::annotationOffset() const
{
    return impObj()->annotationOffset();
}

void PyDbLeader::setAnnotationOffset(const AcGeVector3d& offset) const
{
    return PyThrowBadEs(impObj()->setAnnotationOffset(offset));
}

AcDbLeader::AnnoType PyDbLeader::annoType() const
{
    return impObj()->annoType();
}

double PyDbLeader::annoHeight() const
{
    return impObj()->annoHeight();
}

double PyDbLeader::annoWidth() const
{
    return impObj()->annoWidth();
}

double PyDbLeader::dimasz() const
{
    return impObj()->dimasz();
}

AcCmColor PyDbLeader::dimclrd() const
{
    return impObj()->dimclrd();
}

double PyDbLeader::dimgap() const
{
    return impObj()->dimgap();
}

AcDb::LineWeight PyDbLeader::dimlwd() const
{
    return impObj()->dimlwd();
}

PyDbObjectId PyDbLeader::dimldrblk() const
{
    return PyDbObjectId(impObj()->dimldrblk());
}

bool PyDbLeader::dimsah() const
{
    return impObj()->dimsah();
}

double PyDbLeader::dimscale() const
{
    return impObj()->dimscale();
}

int PyDbLeader::dimtad() const
{
    return impObj()->dimtad();
}

PyDbObjectId PyDbLeader::dimtxsty() const
{
    return PyDbObjectId(impObj()->dimtxsty());
}

double PyDbLeader::dimtxt() const
{
    return impObj()->dimtxt();
}

void PyDbLeader::setDimasz(double val) const
{
    return PyThrowBadEs(impObj()->setDimasz(val));
}

void PyDbLeader::setDimclrd(AcCmColor& val) const
{
    return PyThrowBadEs(impObj()->setDimclrd(val));
}

void PyDbLeader::setDimgap(double val) const
{
    return PyThrowBadEs(impObj()->setDimgap(val));
}

void PyDbLeader::setDimldrblk1(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setDimldrblk(val.m_id));
}

void PyDbLeader::setDimldrblk2(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setDimldrblk(utf8_to_wstr(val).c_str()));
}

void PyDbLeader::setDimlwd(AcDb::LineWeight val) const
{
    return PyThrowBadEs(impObj()->setDimlwd(val));
}

void PyDbLeader::setDimsah(bool val) const
{
    return PyThrowBadEs(impObj()->setDimsah(val));
}

void PyDbLeader::setDimscale(double val) const
{
    return PyThrowBadEs(impObj()->setDimscale(val));
}

void PyDbLeader::setDimtad(int val) const
{
    return PyThrowBadEs(impObj()->setDimtad(val));
}

void PyDbLeader::setDimtxsty(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setDimtxsty(val.m_id));
}

void PyDbLeader::setDimtxt(double val) const
{
    return PyThrowBadEs(impObj()->setDimtxt(val));
}

void PyDbLeader::modified(const PyDbObject& obj) const
{
    return impObj()->modified(obj.impObj());
}

void PyDbLeader::erased1(const PyDbObject& obj) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->erased(obj.impObj());
#endif
}

void PyDbLeader::erased2(const PyDbObject& obj, Adesk::Boolean val) const
{
    return impObj()->erased(obj.impObj(), val);
}

void PyDbLeader::goodbye(const PyDbObject& obj) const
{
    return impObj()->goodbye(obj.impObj());
}

void PyDbLeader::copied(const PyDbObject& objA, const PyDbObject& objB) const
{
    return impObj()->copied(objA.impObj(), objB.impObj());
}

void PyDbLeader::setColorIndex1(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setColorIndex(val));
}

void PyDbLeader::setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setColorIndex(val, doSubents));
}

std::string PyDbLeader::className()
{
    return "AcDbLeader";
}

PyRxClass PyDbLeader::desc()
{
    return PyRxClass(AcDbLeader::desc(), false);
}

PyDbLeader PyDbLeader::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLeader, AcDbLeader>(src);
}

PyDbLeader PyDbLeader::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLeader>(src);
}

AcDbLeader* PyDbLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLeader*>(m_pyImp.get());
}


//----------------------------------------------------------------------------------
//PyDbMLeader
void makePyDbMLeaderWrapper()
{
    constexpr const std::string_view setLeaderLineColorOverloads = "Overloads:\n"
        "- clr: PyDb.AcCmColor\n"
        "- leaderLineIndex: int, clr: PyDb.AcCmColor\n";

    constexpr const std::string_view setLeaderLineTypeIdOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId\n"
        "- leaderLineIndex: int, id: PyDb.ObjectId\n";

    constexpr const std::string_view setLeaderLineWeightOverloads = "Overloads:\n"
        "- lw: PyDb.LineWeight\n"
        "- leaderLineIndex: int, lw: PyDb.LineWeight\n";

    constexpr const std::string_view setDoglegLengthOverloads = "Overloads:\n"
        "- val: float\n"
        "- leaderIndex: int, val: float\n";

    constexpr const std::string_view setArrowSymbolIdOverloads = "Overloads:\n"
        "- arrowSymbolId: PyDb.ObjectId\n"
        "- leaderLineIndex: int, arrowSymbolId: PyDb.ObjectId\n";

    constexpr const std::string_view setArrowSizeOverloads = "Overloads:\n"
        "- val: float\n"
        "- leaderLineIndex: int, val: float\n";

    constexpr const std::string_view textAttachmentTypeOverloads = "Overloads:\n"
        "- None: Any\n"
        "- val: PyDb.MLeaderLeaderDirectionType\n";

    constexpr const std::string_view setTextAttachmentTypeOverloads = "Overloads:\n"
        "- textAttachmentType: PyDb.MLeaderTextAttachmentType\n"
        "- textAttachmentType: PyDb.MLeaderTextAttachmentType, val: PyDb.MLeaderLeaderDirectionType\n";

    constexpr const std::string_view connectionPointOverloads = "Overloads:\n"
        "- vec: PyGe.Vector3d\n"
        "- vec: PyGe.Vector3d, textAttachmentDirection: PyDb.MLeaderTextAttachmentDirection\n";

    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("MLeader");
    class_<PyDbMLeader, bases<PyDbEntity>>("MLeader")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("objectClosed", &PyDbMLeader::objectClosed, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("modified", &PyDbMLeader::modified, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setOverride", &PyDbMLeader::setOverride1)
        .def("setOverride", &PyDbMLeader::setOverride2, DS.ARGS({ "val: PyDb.MLeaderPropertyOverrideType", "isOverride: bool=True" }))
        .def("isOverride", &PyDbMLeader::isOverride, DS.ARGS({ "val: PyDb.MLeaderPropertyOverrideType" }))
        .def("setScale", &PyDbMLeader::setScale, DS.ARGS({ "val: float" }))
        .def("scale", &PyDbMLeader::scale, DS.ARGS())
        .def("getBlockAttribute", &PyDbMLeader::getBlockAttribute, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setBlockAttribute", &PyDbMLeader::setBlockAttribute, DS.ARGS({ "id: PyDb.ObjectId" ,"attribute: PyDb.Attribute" }))
        .def("getBlockAttributeValue", &PyDbMLeader::getBlockAttributeValue, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setBlockAttributeValue", &PyDbMLeader::setBlockAttributeValue, DS.ARGS({ "id: PyDb.ObjectId", "val: str" }))
        .def("plane", &PyDbMLeader::plane, DS.ARGS())
        .def("setPlane", &PyDbMLeader::setPlane, DS.ARGS({ "val: PyGe.Plane" }))
        .def("normal", &PyDbMLeader::normal, DS.ARGS())
        .def("moveMLeader", &PyDbMLeader::moveMLeader1)
        .def("moveMLeader", &PyDbMLeader::moveMLeader2, DS.ARGS({ "vec: PyGe.Vector3d","moveType: PyDb.MLeaderMoveType","bAutoSwitchDogleg: bool=True" }))
        .def("getContentGeomExtents", &PyDbMLeader::getContentGeomExtents, DS.ARGS())
        .def("numLeaders", &PyDbMLeader::numLeaders, DS.ARGS())
        .def("getLeaderIndexes", &PyDbMLeader::getLeaderIndexes, DS.ARGS())
        .def("removeLeader", &PyDbMLeader::removeLeader, DS.ARGS({ "leaderIndex: int" }))
        .def("numLeaderLines", &PyDbMLeader::numLeaderLines, DS.ARGS())
        .def("getLeaderLineIndexes", &PyDbMLeader::getLeaderLineIndexes1)
        .def("getLeaderLineIndexes", &PyDbMLeader::getLeaderLineIndexes2, DS.ARGS({ "leaderIndex: int = ..." }))
        .def("addLeader", &PyDbMLeader::addLeader, DS.ARGS())
        .def("addLeaderLine", &PyDbMLeader::addLeaderLine1)
        .def("addLeaderLine", &PyDbMLeader::addLeaderLine2, DS.ARGS({ "val: int|PyGe.Point3d" }))
        .def("removeLeaderLine", &PyDbMLeader::removeLeaderLine, DS.ARGS({ "leaderLineIndex: int" }))
        .def("addFirstVertex", &PyDbMLeader::addFirstVertex, DS.ARGS({ "leaderLineIndex: int","pt: PyGe.Point3d" }))
        .def("removeFirstVertex", &PyDbMLeader::removeFirstVertex, DS.ARGS({ "leaderLineIndex: int" }))
        .def("getFirstVertex", &PyDbMLeader::getFirstVertex, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setFirstVertex", &PyDbMLeader::setFirstVertex, DS.ARGS({ "leaderLineIndex: int","pt: PyGe.Point3d" }))
        .def("addLastVertex", &PyDbMLeader::addLastVertex, DS.ARGS({ "leaderLineIndex: int","pt: PyGe.Point3d" }))
        .def("removeLastVertex", &PyDbMLeader::removeLastVertex, DS.ARGS({ "leaderLineIndex: int" }))
        .def("getLastVertex", &PyDbMLeader::getLastVertex, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setLastVertex", &PyDbMLeader::setLastVertex, DS.ARGS({ "leaderLineIndex: int","pt: PyGe.Point3d" }))
        .def("numVertices", &PyDbMLeader::numVertices, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setVertex", &PyDbMLeader::setVertex, DS.ARGS({ "leaderLineIndex: int","idx: int","pt: PyGe.Point3d" }))
        .def("getVertex", &PyDbMLeader::getVertex, DS.ARGS({ "leaderLineIndex: int","idx: int" }))
        .def("getLeaderIndex", &PyDbMLeader::getLeaderIndex, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setDoglegDirection", &PyDbMLeader::setDoglegDirection, DS.ARGS({ "leaderIndex: int","vec: PyGe.Vector3d" }))
        .def("getDoglegDirection", &PyDbMLeader::getDoglegDirection, DS.ARGS({ "leaderIndex: int" }))
        .def("setLeaderLineType", &PyDbMLeader::setLeaderLineType1, DS.ARGS({ "leaderLineType: PyDb.MLeaderLeaderType" }))
        .def("setLeaderLineType", &PyDbMLeader::setLeaderLineType2, DS.ARGS({ "leaderIndex: int", "leaderLineType: PyDb.MLeaderLeaderType" }))
        .def("leaderLineType", &PyDbMLeader::leaderLineType, DS.ARGS())
        .def("getLeaderLineType", &PyDbMLeader::getLeaderLineType, DS.ARGS({ "leaderLineIndex: int" }))
        .def("leaderLineColor", &PyDbMLeader::leaderLineColor, DS.ARGS())
        .def("setLeaderLineColor", &PyDbMLeader::setLeaderLineColor1)
        .def("setLeaderLineColor", &PyDbMLeader::setLeaderLineColor2, DS.OVRL(setLeaderLineColorOverloads))
        .def("getLeaderLineColor", &PyDbMLeader::getLeaderLineColor, DS.ARGS({ "leaderLineIndex: int" }))
        .def("leaderLineTypeId", &PyDbMLeader::leaderLineTypeId, DS.ARGS())
        .def("setLeaderLineTypeId", &PyDbMLeader::setLeaderLineTypeId1)
        .def("setLeaderLineTypeId", &PyDbMLeader::setLeaderLineTypeId2, DS.OVRL(setLeaderLineTypeIdOverloads))
        .def("getLeaderLineTypeId", &PyDbMLeader::getLeaderLineTypeId, DS.ARGS({ "leaderLineIndex: int" }))
        .def("leaderLineWeight", &PyDbMLeader::leaderLineWeight, DS.ARGS())
        .def("setLeaderLineWeight", &PyDbMLeader::setLeaderLineWeight1)
        .def("setLeaderLineWeight", &PyDbMLeader::setLeaderLineWeight2, DS.OVRL(setLeaderLineWeightOverloads))
        .def("getLeaderLineWeight", &PyDbMLeader::getLeaderLineWeight, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setLandingGap", &PyDbMLeader::setLandingGap, DS.ARGS({ "val: float" }))
        .def("landingGap", &PyDbMLeader::landingGap, DS.ARGS())
        .def("setEnableLanding", &PyDbMLeader::setEnableLanding, DS.ARGS({ "val: bool" }))
        .def("enableLanding", &PyDbMLeader::enableLanding, DS.ARGS())
        .def("setEnableDogleg", &PyDbMLeader::setEnableDogleg, DS.ARGS({ "val: bool" }))
        .def("enableDogleg", &PyDbMLeader::enableDogleg, DS.ARGS())
        .def("doglegLength", &PyDbMLeader::doglegLength, DS.ARGS())
        .def("setDoglegLength", &PyDbMLeader::setDoglegLength1)
        .def("setDoglegLength", &PyDbMLeader::setDoglegLength2, DS.OVRL(setDoglegLengthOverloads))
        .def("getDoglegLength", &PyDbMLeader::getDoglegLength, DS.ARGS({ "leaderIndex: int" }))
        .def("arrowSymbolId", &PyDbMLeader::arrowSymbolId, DS.ARGS())
        .def("setArrowSymbolId", &PyDbMLeader::setArrowSymbolId1)
        .def("setArrowSymbolId", &PyDbMLeader::setArrowSymbolId2, DS.OVRL(setArrowSymbolIdOverloads))
        .def("getArrowSymbolId", &PyDbMLeader::getArrowSymbolId, DS.ARGS({ "leaderLineIndex: int" }))
        .def("arrowSize", &PyDbMLeader::arrowSize, DS.ARGS())
        .def("setArrowSize", &PyDbMLeader::setArrowSize1)
        .def("setArrowSize", &PyDbMLeader::setArrowSize2, DS.OVRL(setArrowSizeOverloads))
        .def("getArrowSize", &PyDbMLeader::getArrowSize, DS.ARGS({ "leaderLineIndex: int" }))
        .def("contentType", &PyDbMLeader::contentType, DS.ARGS())
        .def("setContentType", &PyDbMLeader::setContentType, DS.ARGS({ "val: PyDb.MLeaderContentType" }))
        .def("textStyleId", &PyDbMLeader::textStyleId, DS.ARGS())
        .def("setTextStyleId", &PyDbMLeader::setTextStyleId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("textAttachmentType", &PyDbMLeader::textAttachmentType1)
        .def("textAttachmentType", &PyDbMLeader::textAttachmentType2, DS.OVRL(textAttachmentTypeOverloads))
        .def("setTextAttachmentType", &PyDbMLeader::setTextAttachmentType1)
        .def("setTextAttachmentType", &PyDbMLeader::setTextAttachmentType2, DS.OVRL(setTextAttachmentTypeOverloads))
        .def("textAngleType", &PyDbMLeader::textAngleType, DS.ARGS())
        .def("setTextAngleType", &PyDbMLeader::setTextAngleType, DS.ARGS({ "val: PyDb.MLeaderTextAngleType" }))
        .def("textAlignmentType", &PyDbMLeader::textAlignmentType, DS.ARGS())
        .def("setTextAlignmentType", &PyDbMLeader::setTextAlignmentType, DS.ARGS({ "val: PyDb.MLeaderTextAlignmentType" }))
        .def("setTextColor", &PyDbMLeader::setTextColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("textColor", &PyDbMLeader::textColor, DS.ARGS())
        .def("setTextHeight", &PyDbMLeader::setTextHeight, DS.ARGS({ "val: float" }))
        .def("textHeight", &PyDbMLeader::textHeight, DS.ARGS())
        .def("setEnableFrameText", &PyDbMLeader::setEnableFrameText, DS.ARGS({ "val: bool" }))
        .def("enableFrameText", &PyDbMLeader::enableFrameText, DS.ARGS())
        .def("setMText", &PyDbMLeader::setMText, DS.ARGS({ "val: PyDb.MText" }))
        .def("mtext", &PyDbMLeader::mtext, DS.ARGS())
        .def("setBlockContentId", &PyDbMLeader::setBlockContentId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("blockContentId", &PyDbMLeader::blockContentId, DS.ARGS())
        .def("setBlockColor", &PyDbMLeader::setBlockColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("blockColor", &PyDbMLeader::blockColor, DS.ARGS())
        .def("setBlockScale", &PyDbMLeader::setBlockScale, DS.ARGS({ "val: PyGe.Scale3d" }))
        .def("blockScale", &PyDbMLeader::blockScale, DS.ARGS())
        .def("setBlockRotation", &PyDbMLeader::setBlockRotation, DS.ARGS({ "val: float" }))
        .def("blockRotation", &PyDbMLeader::blockRotation, DS.ARGS())
        .def("setBlockConnectionType", &PyDbMLeader::setBlockConnectionType, DS.ARGS({ "val: PyDb.MLeaderBlockConnectionType" }))
        .def("blockConnectionType", &PyDbMLeader::blockConnectionType, DS.ARGS())
        .def("setEnableAnnotationScale", &PyDbMLeader::setEnableAnnotationScale, DS.ARGS({ "val: bool" }))
        .def("enableAnnotationScale", &PyDbMLeader::enableAnnotationScale, DS.ARGS())
        .def("getOverridedMLeaderStyle", &PyDbMLeader::getOverridedMLeaderStyle, DS.ARGS({ "outVal: PyDb.MLeaderStyle" }))
        .def("setMLeaderStyle", &PyDbMLeader::setMLeaderStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("MLeaderStyle", &PyDbMLeader::MLeaderStyle, DS.ARGS())
        .def("setBlockPosition", &PyDbMLeader::setBlockPosition, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getBlockPosition", &PyDbMLeader::getBlockPosition, DS.ARGS())
        .def("setTextLocation", &PyDbMLeader::setTextLocation, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getTextLocation", &PyDbMLeader::getTextLocation, DS.ARGS())
        .def("setToleranceLocation", &PyDbMLeader::setToleranceLocation, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getToleranceLocation", &PyDbMLeader::getToleranceLocation, DS.ARGS())
        .def("hasContent", &PyDbMLeader::hasContent, DS.ARGS())
        .def("connectionPoint", &PyDbMLeader::connectionPoint1)
        .def("connectionPoint", &PyDbMLeader::connectionPoint2, DS.OVRL(connectionPointOverloads))
        .def("recomputeBreakPoints", &PyDbMLeader::recomputeBreakPoints, DS.ARGS())
        .def("postMLeaderToDb", &PyDbMLeader::postMLeaderToDb, DS.ARGS({ "db: PyDb.Database" }))
        .def("updateLeaderLinePosition", &PyDbMLeader::updateLeaderLinePosition, DS.ARGS())
        .def("removeLeaderLineRefAssoc", &PyDbMLeader::removeLeaderLineRefAssoc, DS.ARGS({ "leaderLineIndex: int" }))
        .def("setTextAttachmentDirection", &PyDbMLeader::setTextAttachmentDirection, DS.ARGS({ "textAttachmentDirection: PyDb.MLeaderTextAttachmentDirection" }))
        .def("textAttachmentDirection", &PyDbMLeader::textAttachmentDirection, DS.ARGS())
        .def("setExtendLeaderToText", &PyDbMLeader::setExtendLeaderToText, DS.ARGS({ "val: bool" }))
        .def("extendLeaderToText", &PyDbMLeader::extendLeaderToText, DS.ARGS())
        .def("className", &PyDbMLeader::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMLeader::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMLeader::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMLeader::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbMLeader::MoveType>("MLeaderMoveType")
        .value("kMoveAllPoints", AcDbMLeader::MoveType::kMoveAllPoints)
        .value("kMoveAllExceptArrowHeaderPoints", AcDbMLeader::MoveType::kMoveAllExceptArrowHeaderPoints)
        .value("kMoveContentAndDoglegPoints", AcDbMLeader::MoveType::kMoveContentAndDoglegPoints)
        .export_values()
        ;

    enum_<AcDbMLeader::gsMarkType>("MLeaderGsMarkType")
        .value("kNone", AcDbMLeader::gsMarkType::kNone)
        .value("kArrowMark", AcDbMLeader::gsMarkType::kArrowMark)
        .value("kLeaderLineMark", AcDbMLeader::gsMarkType::kLeaderLineMark)
        .value("kDoglegMark", AcDbMLeader::gsMarkType::kDoglegMark)
        .value("kMTextMark", AcDbMLeader::gsMarkType::kMTextMark)
        .value("kMTextUnderLineMark", AcDbMLeader::gsMarkType::kMTextUnderLineMark)
        .value("kToleranceMark", AcDbMLeader::gsMarkType::kToleranceMark)
        .value("kBlockMark", AcDbMLeader::gsMarkType::kBlockMark)
        .value("kBlockAttribute", AcDbMLeader::gsMarkType::kBlockAttribute)
        .export_values()
        ;

    enum_<AcDbMLeader::PropertyOverrideType>("MLeaderPropertyOverrideType")
        .value("kLeaderLineType", AcDbMLeader::PropertyOverrideType::kLeaderLineType)
        .value("kLeaderLineColor", AcDbMLeader::PropertyOverrideType::kLeaderLineColor)
        .value("kLeaderLineTypeId", AcDbMLeader::PropertyOverrideType::kLeaderLineTypeId)
        .value("kLeaderLineWeight", AcDbMLeader::PropertyOverrideType::kLeaderLineWeight)
        .value("kEnableLanding", AcDbMLeader::PropertyOverrideType::kEnableLanding)
        .value("kLandingGap", AcDbMLeader::PropertyOverrideType::kLandingGap)
        .value("kEnableDogleg", AcDbMLeader::PropertyOverrideType::kEnableDogleg)
        .value("kDoglegLength", AcDbMLeader::PropertyOverrideType::kDoglegLength)
        .value("kArrowSymbolId", AcDbMLeader::PropertyOverrideType::kArrowSymbolId)
        .value("kArrowSize", AcDbMLeader::PropertyOverrideType::kArrowSize)
        .value("kContentType", AcDbMLeader::PropertyOverrideType::kContentType)
        .value("kTextStyleId", AcDbMLeader::PropertyOverrideType::kTextStyleId)
        .value("kTextLeftAttachmentType", AcDbMLeader::PropertyOverrideType::kTextLeftAttachmentType)
        .value("kTextAngleType", AcDbMLeader::PropertyOverrideType::kTextAngleType)
        .value("kTextAlignmentType", AcDbMLeader::PropertyOverrideType::kTextAlignmentType)
        .value("kTextColor", AcDbMLeader::PropertyOverrideType::kTextColor)
        .value("kTextHeight", AcDbMLeader::PropertyOverrideType::kTextHeight)
        .value("kEnableFrameText", AcDbMLeader::PropertyOverrideType::kEnableFrameText)
        .value("kDefaultMText", AcDbMLeader::PropertyOverrideType::kDefaultMText)
        .value("kBlockId", AcDbMLeader::PropertyOverrideType::kBlockId)
        .value("kBlockColor", AcDbMLeader::PropertyOverrideType::kBlockColor)
        .value("kBlockScale", AcDbMLeader::PropertyOverrideType::kBlockScale)
        .value("kBlockRotation", AcDbMLeader::PropertyOverrideType::kBlockRotation)
        .value("kBlockConnectionType", AcDbMLeader::PropertyOverrideType::kBlockConnectionType)
        .value("kScale", AcDbMLeader::PropertyOverrideType::kScale)
        .value("kTextRightAttachmentType", AcDbMLeader::PropertyOverrideType::kTextRightAttachmentType)
        .value("kTextSwitchAlignmentType", AcDbMLeader::PropertyOverrideType::kTextSwitchAlignmentType)
        .value("kTextAttachmentDirection", AcDbMLeader::PropertyOverrideType::kTextAttachmentDirection)
        .value("kTextTopAttachmentType", AcDbMLeader::PropertyOverrideType::kTextTopAttachmentType)
        .value("kTextBottomAttachmentType", AcDbMLeader::PropertyOverrideType::kTextBottomAttachmentType)
        .value("kExtendLeaderToText", AcDbMLeader::PropertyOverrideType::kExtendLeaderToText)
        .value("kSize", AcDbMLeader::PropertyOverrideType::kSize)
        .export_values()
        ;
}

PyDbMLeader::PyDbMLeader()
    : PyDbEntity(new AcDbMLeader(), true)
{
}

PyDbMLeader::PyDbMLeader(AcDbMLeader* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMLeader::PyDbMLeader(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbMLeader>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMLeader::PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMLeader>(id, mode), false)
{
}

PyDbMLeader::PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMLeader>(id, mode, erased), false)
{
}

void PyDbMLeader::objectClosed(const PyDbObjectId& dbObjId) const
{
    impObj()->objectClosed(dbObjId.m_id);
}

void PyDbMLeader::modified(const PyDbObject& dbObj) const
{
    impObj()->modified(dbObj.impObj());
}

void PyDbMLeader::setOverride1(AcDbMLeader::PropertyOverrideType propertyType) const
{
    return PyThrowBadEs(impObj()->setOverride(propertyType));
}

void PyDbMLeader::setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride) const
{
    return PyThrowBadEs(impObj()->setOverride(propertyType, isOverride));
}

bool PyDbMLeader::isOverride(AcDbMLeader::PropertyOverrideType propertyType) const
{
    return impObj()->isOverride(propertyType);
}

void PyDbMLeader::setScale(double scale) const
{
    return PyThrowBadEs(impObj()->setScale(scale));
}

double PyDbMLeader::scale() const
{
    return impObj()->scale();
}

PyDbAttribute PyDbMLeader::getBlockAttribute(const PyDbObjectId& attdefId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbAttribute* patt = nullptr;
    PyThrowBadEs(impObj()->getBlockAttributeValue(attdefId.m_id, patt));
    return PyDbAttribute(patt, true);
#endif
}

void PyDbMLeader::setBlockAttribute(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt) const
{
    return PyThrowBadEs(impObj()->setBlockAttributeValue(attdefId.m_id, pAtt.impObj()));
}

std::string PyDbMLeader::getBlockAttributeValue(const PyDbObjectId& attdefId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    RxAutoOutStr patt;
    PyThrowBadEs(impObj()->getBlockAttributeValue(attdefId.m_id, patt.buf));
    return patt.str();
#endif
}

void PyDbMLeader::setBlockAttributeValue(const PyDbObjectId& attdefId, const std::string& pAtt) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockAttributeValue(attdefId.m_id, utf8_to_wstr(pAtt).c_str()));
#endif
}

PyGePlane PyDbMLeader::plane() const
{
    return PyGePlane(impObj()->plane());
}

void PyDbMLeader::setPlane(const PyGePlane& plane) const
{
    impObj()->setPlane(*plane.impObj());
}

AcGeVector3d PyDbMLeader::normal() const
{
    return impObj()->normal();
}

void PyDbMLeader::moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType) const
{
    return PyThrowBadEs(impObj()->moveMLeader(vector, moveType));
}

void PyDbMLeader::moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg) const
{
    return PyThrowBadEs(impObj()->moveMLeader(vector, moveType, bAutoSwitchDogleg));
}

AcDbExtents PyDbMLeader::getContentGeomExtents() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbExtents ext;
    PyThrowBadEs(impObj()->getContentGeomExtents(ext));
    return ext;
#endif
}

int PyDbMLeader::numLeaders() const
{
    return impObj()->numLeaders();
}

boost::python::list PyDbMLeader::getLeaderIndexes() const
{
    AcDbIntArray leaderIndexes;
    PyThrowBadEs(impObj()->getLeaderIndexes(leaderIndexes));
    return IntArrayToPyList(leaderIndexes);
}

int PyDbMLeader::addLeader() const
{
    int leaderIndex = 0;
    PyThrowBadEs(impObj()->addLeader(leaderIndex));
    return leaderIndex;
}

int PyDbMLeader::addLeaderLine1(int leaderIndex) const
{
    int leaderLineIndex = 0;
    PyThrowBadEs(impObj()->addLeaderLine(leaderIndex, leaderLineIndex));
    return leaderLineIndex;
}

int PyDbMLeader::addLeaderLine2(const AcGePoint3d& point) const
{
    int leaderLineIndex = 0;
    PyThrowBadEs(impObj()->addLeaderLine(point, leaderLineIndex));
    return leaderLineIndex;
}

void PyDbMLeader::removeLeaderLine(int leaderLineIndex) const
{
    return PyThrowBadEs(impObj()->removeLeaderLine(leaderLineIndex));
}

void PyDbMLeader::addFirstVertex(int leaderLineIndex, const AcGePoint3d& point) const
{
    return PyThrowBadEs(impObj()->addFirstVertex(leaderLineIndex, point));
}

void PyDbMLeader::removeFirstVertex(int leaderLineIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeFirstVertex(leaderLineIndex));
#endif
}

AcGePoint3d PyDbMLeader::getFirstVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getFirstVertex(leaderLineIndex, point));
    return point;
}

void PyDbMLeader::setFirstVertex(int leaderLineIndex, const AcGePoint3d& point) const
{
    return PyThrowBadEs(impObj()->setFirstVertex(leaderLineIndex, point));
}

void PyDbMLeader::addLastVertex(int leaderLineIndex, const AcGePoint3d& point) const
{
    return PyThrowBadEs(impObj()->addLastVertex(leaderLineIndex, point));
}

void PyDbMLeader::removeLastVertex(int leaderLineIndex) const
{
    return PyThrowBadEs(impObj()->removeLastVertex(leaderLineIndex));
}

void PyDbMLeader::removeLeader(int leaderIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeLeader(leaderIndex));
#endif
}

int PyDbMLeader::numLeaderLines() const
{
    return impObj()->numLeaderLines();
}

boost::python::list PyDbMLeader::getLeaderLineIndexes1() const
{
    AcDbIntArray leaderIndexes;
    PyThrowBadEs(impObj()->getLeaderLineIndexes(leaderIndexes));
    return IntArrayToPyList(leaderIndexes);
}

boost::python::list PyDbMLeader::getLeaderLineIndexes2(int leaderIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbIntArray leaderIndexes;
    PyThrowBadEs(impObj()->getLeaderLineIndexes(leaderIndex, leaderIndexes));
    return IntArrayToPyList(leaderIndexes);
#endif
}

AcGePoint3d PyDbMLeader::getLastVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getLastVertex(leaderLineIndex, point));
    return point;
}

void PyDbMLeader::setLastVertex(int leaderLineIndex, const AcGePoint3d& point) const
{
    return PyThrowBadEs(impObj()->setLastVertex(leaderLineIndex, point));
}

int PyDbMLeader::numVertices(int leaderLineIndex) const
{
    int cnt;
    PyThrowBadEs(impObj()->numVertices(leaderLineIndex, cnt));
    return cnt;
}

void PyDbMLeader::setVertex(int leaderLineIndex, int index, const AcGePoint3d& point) const
{
    return PyThrowBadEs(impObj()->setVertex(leaderLineIndex, index, point));
}

AcGePoint3d PyDbMLeader::getVertex(int leaderLineIndex, int index) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getVertex(leaderLineIndex, index, point));
    return point;
}

int PyDbMLeader::getLeaderIndex(int leaderLineIndex) const
{
    int cnt;
    PyThrowBadEs(impObj()->getLeaderIndex(leaderLineIndex, cnt));
    return cnt;
}

void PyDbMLeader::setDoglegDirection(int leaderIndex, const AcGeVector3d& vector) const
{
    return PyThrowBadEs(impObj()->setDoglegDirection(leaderIndex, vector));
}

AcGeVector3d PyDbMLeader::getDoglegDirection(int leaderIndex) const
{
    AcGeVector3d point;
    PyThrowBadEs(impObj()->getDoglegDirection(leaderIndex, point));
    return point;
}

void PyDbMLeader::setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType) const
{
    return PyThrowBadEs(impObj()->setLeaderLineType(leaderLineType));
}

void PyDbMLeader::setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType leaderLineType) const
{
    return PyThrowBadEs(impObj()->setLeaderLineType(leaderLineType, leaderLineType));
}

AcDbMLeaderStyle::LeaderType PyDbMLeader::getLeaderLineType(int leaderLineIndex) const
{
    AcDbMLeaderStyle::LeaderType leaderLineType = AcDbMLeaderStyle::kInVisibleLeader;
    PyThrowBadEs(impObj()->getLeaderLineType(leaderLineIndex, leaderLineType));
    return leaderLineType;
}

AcCmColor PyDbMLeader::leaderLineColor() const
{
    return impObj()->leaderLineColor();
}

void PyDbMLeader::setLeaderLineColor1(const AcCmColor& leaderLineColor) const
{
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineColor));
}

void PyDbMLeader::setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineIndex, leaderLineColor));
#endif
}

AcCmColor PyDbMLeader::getLeaderLineColor(int leaderLineIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcCmColor leaderLineColor;
    PyThrowBadEs(impObj()->getLeaderLineColor(leaderLineIndex, leaderLineColor));
    return leaderLineColor;
#endif
}

PyDbObjectId PyDbMLeader::leaderLineTypeId() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->leaderLineTypeId();
#endif
}

AcDbMLeaderStyle::LeaderType PyDbMLeader::leaderLineType() const
{
    return impObj()->leaderLineType();
}

void PyDbMLeader::setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineTypeId.m_id));
#endif
}

void PyDbMLeader::setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineIndex, leaderLineTypeId.m_id));
#endif
}

PyDbObjectId PyDbMLeader::getLeaderLineTypeId(int leaderLineIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getLeaderLineTypeId(leaderLineIndex, id));
    return PyDbObjectId(id);
#endif
}

AcDb::LineWeight PyDbMLeader::leaderLineWeight() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->leaderLineWeight();
#endif
}

void PyDbMLeader::setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineWeight));
#endif
}

void PyDbMLeader::setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight leaderLineWeight) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineIndex, leaderLineWeight));
#endif
}

AcDb::LineWeight PyDbMLeader::getLeaderLineWeight(int leaderLineIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDb::LineWeight wt;
    PyThrowBadEs(impObj()->getLeaderLineWeight(leaderLineIndex, wt));
    return wt;
#endif
}

void PyDbMLeader::setLandingGap(double landingGap) const
{
    return PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

double PyDbMLeader::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbMLeader::setEnableLanding(bool enableLanding) const
{
    return PyThrowBadEs(impObj()->setEnableLanding(enableLanding));
}

bool PyDbMLeader::enableLanding() const
{
    return impObj()->enableLanding();
}

void PyDbMLeader::setEnableDogleg(bool enableDogleg) const
{
    return PyThrowBadEs(impObj()->setEnableDogleg(enableDogleg));
}

bool PyDbMLeader::enableDogleg() const
{
    return impObj()->enableDogleg();
}

double PyDbMLeader::doglegLength() const
{
    return impObj()->doglegLength();
}

void PyDbMLeader::setDoglegLength1(double doglegLength) const
{
    return PyThrowBadEs(impObj()->setDoglegLength(doglegLength));
}

void PyDbMLeader::setDoglegLength2(int leaderIndex, double doglegLength) const
{
    return PyThrowBadEs(impObj()->setDoglegLength(leaderIndex, doglegLength));
}

double PyDbMLeader::getDoglegLength(int leaderIndex) const
{
    double val;
    PyThrowBadEs(impObj()->doglegLength(leaderIndex, val));
    return val;
}

PyDbObjectId PyDbMLeader::arrowSymbolId() const
{
    return PyDbObjectId(impObj()->arrowSymbolId());
}

void PyDbMLeader::setArrowSymbolId1(const PyDbObjectId& arrowSymbolId) const
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(arrowSymbolId.m_id));
}

void PyDbMLeader::setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId) const
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(leaderLineIndex, arrowSymbolId.m_id));
}

PyDbObjectId PyDbMLeader::getArrowSymbolId(int leaderLineIndex) const
{
    AcDbObjectId val;
    PyThrowBadEs(impObj()->getArrowSymbolId(leaderLineIndex, val));
    return PyDbObjectId(val);
}

double PyDbMLeader::arrowSize() const
{
    return impObj()->arrowSize();
}

void PyDbMLeader::setArrowSize1(double arrowSize) const
{
    return PyThrowBadEs(impObj()->setArrowSize(arrowSize));
}

void PyDbMLeader::setArrowSize2(int leaderLineIndex, double arrowSize) const
{
    return PyThrowBadEs(impObj()->setArrowSize(leaderLineIndex, arrowSize));
}

double PyDbMLeader::getArrowSize(int leaderLineIndex) const
{
    double val;
    PyThrowBadEs(impObj()->getArrowSize(leaderLineIndex, val));
    return val;
}

AcDbMLeaderStyle::ContentType PyDbMLeader::contentType() const
{
    return impObj()->contentType();
}

void PyDbMLeader::setContentType(AcDbMLeaderStyle::ContentType contentType) const
{
    return PyThrowBadEs(impObj()->setContentType(contentType));
}

PyDbObjectId PyDbMLeader::textStyleId() const
{
    return PyDbObjectId(impObj()->textStyleId());
}

void PyDbMLeader::setTextStyleId(const PyDbObjectId& textStyleId) const
{
    return PyThrowBadEs(impObj()->setTextStyleId(textStyleId.m_id));
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeader::textAttachmentType1() const
{
    return impObj()->textAttachmentType();
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeader::textAttachmentType2(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return impObj()->textAttachmentType(leaderDirection);
}

void PyDbMLeader::setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType) const
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType));
}

void PyDbMLeader::setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType, leaderDirection));
}

AcDbMLeaderStyle::TextAngleType PyDbMLeader::textAngleType() const
{
    return impObj()->textAngleType();
}

void PyDbMLeader::setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType) const
{
    return PyThrowBadEs(impObj()->setTextAngleType(textAngleType));
}

AcDbMLeaderStyle::TextAlignmentType PyDbMLeader::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

void PyDbMLeader::setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType) const
{
    return PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
}

void PyDbMLeader::setTextColor(const AcCmColor& textColor) const
{
    return PyThrowBadEs(impObj()->setTextColor(textColor));
}

AcCmColor PyDbMLeader::textColor() const
{
    return impObj()->textColor();
}

void PyDbMLeader::setTextHeight(double textHeight) const
{
    return PyThrowBadEs(impObj()->setTextHeight(textHeight));
}

double PyDbMLeader::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMLeader::setEnableFrameText(bool enableFrameText) const
{
    return PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

bool PyDbMLeader::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbMLeader::setMText(const PyDbMText& pMText) const
{
    return PyThrowBadEs(impObj()->setMText(pMText.impObj()));
}

PyDbMText PyDbMLeader::mtext() const
{
    return PyDbMText(impObj()->mtext(), true);
}

void PyDbMLeader::setBlockContentId(const PyDbObjectId& blockId) const
{
    return PyThrowBadEs(impObj()->setBlockContentId(blockId.m_id));
}

PyDbObjectId PyDbMLeader::blockContentId() const
{
    return PyDbObjectId(impObj()->blockContentId());
}

void PyDbMLeader::setBlockColor(const AcCmColor& blockColor) const
{
    return PyThrowBadEs(impObj()->setBlockColor(blockColor));
}

AcCmColor PyDbMLeader::blockColor() const
{
    return impObj()->blockColor();
}

void PyDbMLeader::setBlockScale(const AcGeScale3d& scale) const
{
    return PyThrowBadEs(impObj()->setBlockScale(scale));
}

AcGeScale3d PyDbMLeader::blockScale() const
{
    return impObj()->blockScale();
}

void PyDbMLeader::setBlockRotation(double rotation) const
{
    return PyThrowBadEs(impObj()->setBlockRotation(rotation));
}

double PyDbMLeader::blockRotation() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->blockRotation();
#endif
}

void PyDbMLeader::setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType) const
{
    return PyThrowBadEs(impObj()->setBlockConnectionType(blockConnectionType));
}

AcDbMLeaderStyle::BlockConnectionType PyDbMLeader::blockConnectionType() const
{
    return impObj()->blockConnectionType();
}

void PyDbMLeader::setEnableAnnotationScale(bool enableAnnotationScale) const
{
    return PyThrowBadEs(impObj()->setEnableAnnotationScale(enableAnnotationScale));
}

bool PyDbMLeader::enableAnnotationScale() const
{
    return impObj()->enableAnnotationScale();
}

void PyDbMLeader::setMLeaderStyle(const PyDbObjectId& blockId) const
{
    return PyThrowBadEs(impObj()->setMLeaderStyle(blockId.m_id));
}

PyDbObjectId PyDbMLeader::MLeaderStyle() const
{
    return PyDbObjectId(impObj()->MLeaderStyle());
}

void PyDbMLeader::getOverridedMLeaderStyle(PyDbMLeaderStyle& mleaderStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return  PyThrowBadEs(impObj()->getOverridedMLeaderStyle(*mleaderStyle.impObj()));
#endif
}

void PyDbMLeader::setBlockPosition(const AcGePoint3d& position) const
{
    return PyThrowBadEs(impObj()->setBlockPosition(position));
}

AcGePoint3d PyDbMLeader::getBlockPosition() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getBlockPosition(val));
    return val;
}

void PyDbMLeader::setTextLocation(const AcGePoint3d& location) const
{
    return PyThrowBadEs(impObj()->setTextLocation(location));
}

AcGePoint3d PyDbMLeader::getTextLocation() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getTextLocation(val));
    return val;
}

void PyDbMLeader::setToleranceLocation(const AcGePoint3d& location) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setToleranceLocation(location));
#endif
}

AcGePoint3d PyDbMLeader::getToleranceLocation() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getToleranceLocation(val));
    return val;
#endif
}

bool PyDbMLeader::hasContent() const
{
    return impObj()->hasContent();
}

AcGePoint3d PyDbMLeader::connectionPoint1(const AcGeVector3d& vect) const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->connectionPoint(vect, val));
    return val;
}

AcGePoint3d PyDbMLeader::connectionPoint2(const AcGeVector3d& vect, AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d val;
    PyThrowBadEs(impObj()->connectionPoint(vect, val, textAttachmentDirection));
    return val;
#endif
}

void PyDbMLeader::recomputeBreakPoints() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->recomputeBreakPoints());
#endif
}

void PyDbMLeader::postMLeaderToDb(const PyDbDatabase& pDb) const
{
    return PyThrowBadEs(impObj()->postMLeaderToDb(pDb.impObj()));
}

void PyDbMLeader::updateLeaderLinePosition() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->updateLeaderLinePosition());
#endif
}

void PyDbMLeader::removeLeaderLineRefAssoc(int leaderLineIndex) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeLeaderLineRefAssoc(leaderLineIndex));
#endif
}

void PyDbMLeader::setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const
{
    return PyThrowBadEs(impObj()->setTextAttachmentDirection(textAttachmentDirection));
}

AcDbMLeaderStyle::TextAttachmentDirection PyDbMLeader::textAttachmentDirection() const
{
    return impObj()->textAttachmentDirection();
}

void PyDbMLeader::setExtendLeaderToText(bool value) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtendLeaderToText(value));
#endif
}

bool PyDbMLeader::extendLeaderToText() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->extendLeaderToText();
#endif
}

std::string PyDbMLeader::className()
{
    return "AcDbMLeader";
}

PyRxClass PyDbMLeader::desc()
{
    return PyRxClass(AcDbMLeader::desc(), false);
}

PyDbMLeader PyDbMLeader::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbMLeader, AcDbMLeader>(src);
}

PyDbMLeader PyDbMLeader::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMLeader>(src);
}

AcDbMLeader* PyDbMLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMLeader*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------
//PyDbMLeaderStyle
void makePyDbMLeaderStyleWrapper()
{
    constexpr const std::string_view textAttachmentTypeOverloads = "Overloads:\n"
        "- None: Any\n"
        "- val: PyDb.MLeaderLeaderDirectionType\n";

    constexpr const std::string_view setTextAttachmentTypeOverloads = "Overloads:\n"
        "- textAttachmentType: PyDb.MLeaderTextAttachmentType\n"
        "- textAttachmentType: PyDb.MLeaderTextAttachmentType, val: PyDb.MLeaderLeaderDirectionType\n";

    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("MLeaderStyle");
    class_<PyDbMLeaderStyle, bases<PyDbObject>>("MLeaderStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("getName", &PyDbMLeaderStyle::getName, DS.ARGS())
        .def("setName", &PyDbMLeaderStyle::setName, DS.ARGS({ "val: str" }))
        .def("isRenamable", &PyDbMLeaderStyle::isRenamable, DS.ARGS())
        .def("description", &PyDbMLeaderStyle::description, DS.ARGS())
        .def("setDescription", &PyDbMLeaderStyle::setDescription, DS.ARGS({ "val: str" }))
        .def("bitFlags", &PyDbMLeaderStyle::bitFlags, DS.ARGS())
        .def("setBitFlags", &PyDbMLeaderStyle::setBitFlags, DS.ARGS({ "val: int" }))
        .def("contentType", &PyDbMLeaderStyle::contentType, DS.ARGS())
        .def("setContentType", &PyDbMLeaderStyle::setContentType, DS.ARGS({ "val: PyDb.MLeaderContentType" }))
        .def("drawMLeaderOrderType", &PyDbMLeaderStyle::drawMLeaderOrderType, DS.ARGS())
        .def("setDrawMLeaderOrderType", &PyDbMLeaderStyle::setDrawMLeaderOrderType, DS.ARGS({ "val: PyDb.DrawMLeaderOrderType" }))
        .def("drawLeaderOrderType", &PyDbMLeaderStyle::drawLeaderOrderType, DS.ARGS())
        .def("setDrawLeaderOrderType", &PyDbMLeaderStyle::setDrawLeaderOrderType, DS.ARGS({ "val: PyDb.DrawLeaderOrderType" }))
        .def("setMaxLeaderSegmentsPoints", &PyDbMLeaderStyle::setMaxLeaderSegmentsPoints, DS.ARGS({ "maxLeaderSegmentsPoints: int" }))
        .def("maxLeaderSegmentsPoints", &PyDbMLeaderStyle::maxLeaderSegmentsPoints, DS.ARGS())
        .def("setFirstSegmentAngleConstraint", &PyDbMLeaderStyle::setFirstSegmentAngleConstraint, DS.ARGS({ "val: PyDb.MLeaderSegmentAngleType" }))
        .def("firstSegmentAngleConstraint", &PyDbMLeaderStyle::firstSegmentAngleConstraint, DS.ARGS())
        .def("setSecondSegmentAngleConstraint", &PyDbMLeaderStyle::setSecondSegmentAngleConstraint, DS.ARGS({ "val: PyDb.MLeaderSegmentAngleType" }))
        .def("secondSegmentAngleConstraint", &PyDbMLeaderStyle::secondSegmentAngleConstraint, DS.ARGS())
        .def("setLeaderLineType", &PyDbMLeaderStyle::setLeaderLineType, DS.ARGS({ "val:  PyDb.MLeaderLeaderType" }))
        .def("leaderLineType", &PyDbMLeaderStyle::leaderLineType, DS.ARGS())
        .def("setLeaderLineColor", &PyDbMLeaderStyle::setLeaderLineColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("leaderLineColor", &PyDbMLeaderStyle::leaderLineColor, DS.ARGS())
        .def("setLeaderLineTypeId", &PyDbMLeaderStyle::setLeaderLineTypeId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("leaderLineTypeId", &PyDbMLeaderStyle::leaderLineTypeId, DS.ARGS())
        .def("setLeaderLineWeight", &PyDbMLeaderStyle::setLeaderLineWeight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("leaderLineWeight", &PyDbMLeaderStyle::leaderLineWeight, DS.ARGS())
        .def("setEnableLanding", &PyDbMLeaderStyle::setEnableLanding, DS.ARGS({ "val: bool" }))
        .def("enableLanding", &PyDbMLeaderStyle::enableLanding, DS.ARGS())
        .def("setLandingGap", &PyDbMLeaderStyle::setLandingGap, DS.ARGS({ "val: float" }))
        .def("landingGap", &PyDbMLeaderStyle::landingGap, DS.ARGS())
        .def("setEnableDogleg", &PyDbMLeaderStyle::setEnableDogleg, DS.ARGS({ "val: bool" }))
        .def("enableDogleg", &PyDbMLeaderStyle::enableDogleg, DS.ARGS())
        .def("setDoglegLength", &PyDbMLeaderStyle::setDoglegLength, DS.ARGS({ "val: float" }))
        .def("doglegLength", &PyDbMLeaderStyle::doglegLength, DS.ARGS())
        .def("setArrowSymbolId", &PyDbMLeaderStyle::setArrowSymbolId1)
        .def("setArrowSymbolId", &PyDbMLeaderStyle::setArrowSymbolId2, DS.ARGS({ "val: str|PyDb.ObjectId" }))
        .def("arrowSymbolId", &PyDbMLeaderStyle::arrowSymbolId, DS.ARGS())
        .def("setArrowSize", &PyDbMLeaderStyle::setArrowSize, DS.ARGS({ "val: float" }))
        .def("arrowSize", &PyDbMLeaderStyle::arrowSize, DS.ARGS())
        .def("setDefaultMText", &PyDbMLeaderStyle::setDefaultMText, DS.ARGS({ "mt: PyDb.MText" }))
        .def("defaultMText", &PyDbMLeaderStyle::defaultMText, DS.ARGS())
        .def("setTextStyleId", &PyDbMLeaderStyle::setTextStyleId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("textStyleId", &PyDbMLeaderStyle::textStyleId, DS.ARGS())
        .def("textAttachmentType", &PyDbMLeaderStyle::textAttachmentType1)
        .def("textAttachmentType", &PyDbMLeaderStyle::textAttachmentType2, DS.OVRL(textAttachmentTypeOverloads))
        .def("setTextAttachmentType", &PyDbMLeaderStyle::setTextAttachmentType1)
        .def("setTextAttachmentType", &PyDbMLeaderStyle::setTextAttachmentType2, DS.OVRL(setTextAttachmentTypeOverloads))
        .def("setTextAngleType", &PyDbMLeaderStyle::setTextAngleType, DS.ARGS({ "val: PyDb.MLeaderTextAngleType" }))
        .def("textAngleType", &PyDbMLeaderStyle::textAngleType, DS.ARGS())
        .def("setTextAlignmentType", &PyDbMLeaderStyle::setTextAlignmentType, DS.ARGS({ "val:  PyDb.MLeaderTextAlignmentType" }))
        .def("textAlignmentType", &PyDbMLeaderStyle::textAlignmentType, DS.ARGS())
        .def("setTextAlignAlwaysLeft", &PyDbMLeaderStyle::setTextAlignAlwaysLeft, DS.ARGS({ "val: bool" }))
        .def("textAlignAlwaysLeft", &PyDbMLeaderStyle::textAlignAlwaysLeft, DS.ARGS())
        .def("setTextColor", &PyDbMLeaderStyle::setTextColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("textColor", &PyDbMLeaderStyle::textColor, DS.ARGS())
        .def("setTextHeight", &PyDbMLeaderStyle::setTextHeight, DS.ARGS({ "val: float" }))
        .def("textHeight", &PyDbMLeaderStyle::textHeight, DS.ARGS())
        .def("setEnableFrameText", &PyDbMLeaderStyle::setEnableFrameText, DS.ARGS({ "val: bool" }))
        .def("enableFrameText", &PyDbMLeaderStyle::enableFrameText, DS.ARGS())
        .def("setAlignSpace", &PyDbMLeaderStyle::setAlignSpace, DS.ARGS({ "val: float" }))
        .def("alignSpace", &PyDbMLeaderStyle::alignSpace, DS.ARGS())
        .def("setBlockId", &PyDbMLeaderStyle::setBlockId1)
        .def("setBlockId", &PyDbMLeaderStyle::setBlockId2, DS.ARGS({ "id: str|PyDb.ObjectId" }))
        .def("blockId", &PyDbMLeaderStyle::blockId, DS.ARGS())
        .def("setBlockColor", &PyDbMLeaderStyle::setBlockColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("blockColor", &PyDbMLeaderStyle::blockColor, DS.ARGS())
        .def("setBlockScale", &PyDbMLeaderStyle::setBlockScale, DS.ARGS({ "pt: PyGe.Scale3d" }))
        .def("blockScale", &PyDbMLeaderStyle::blockScale, DS.ARGS())
        .def("setEnableBlockScale", &PyDbMLeaderStyle::setEnableBlockScale, DS.ARGS({ "val: bool" }))
        .def("enableBlockScale", &PyDbMLeaderStyle::enableBlockScale, DS.ARGS())
        .def("setBlockRotation", &PyDbMLeaderStyle::setBlockRotation, DS.ARGS({ "val: float" }))
        .def("blockRotation", &PyDbMLeaderStyle::blockRotation, DS.ARGS())
        .def("setEnableBlockRotation", &PyDbMLeaderStyle::setEnableBlockRotation, DS.ARGS({ "val: bool" }))
        .def("enableBlockRotation", &PyDbMLeaderStyle::enableBlockRotation, DS.ARGS())
        .def("setBlockConnectionType", &PyDbMLeaderStyle::setBlockConnectionType, DS.ARGS({ "val: PyDb.MLeaderBlockConnectionType" }))
        .def("blockConnectionType", &PyDbMLeaderStyle::blockConnectionType, DS.ARGS())
        .def("setScale", &PyDbMLeaderStyle::setScale, DS.ARGS({ "val: float" }))
        .def("scale", &PyDbMLeaderStyle::scale, DS.ARGS())
        .def("overwritePropChanged", &PyDbMLeaderStyle::overwritePropChanged, DS.ARGS())
        .def("postMLeaderStyleToDb", &PyDbMLeaderStyle::postMLeaderStyleToDb, DS.ARGS({ "db: PyDb.Database","name: str" }))
        .def("setAnnotative", &PyDbMLeaderStyle::setAnnotative, DS.ARGS({ "val: bool" }))
        .def("annotative", &PyDbMLeaderStyle::annotative, DS.ARGS())
        .def("setBreakSize", &PyDbMLeaderStyle::setBreakSize, DS.ARGS({ "val: float" }))
        .def("breakSize", &PyDbMLeaderStyle::breakSize, DS.ARGS())
        .def("setTextAttachmentDirection", &PyDbMLeaderStyle::setTextAttachmentDirection, DS.ARGS({ "val: PyDb.MLeaderTextAttachmentDirection" }))
        .def("textAttachmentDirection", &PyDbMLeaderStyle::textAttachmentDirection, DS.ARGS())
        .def("setExtendLeaderToText", &PyDbMLeaderStyle::setExtendLeaderToText, DS.ARGS({ "val: bool" }))
        .def("extendLeaderToText", &PyDbMLeaderStyle::extendLeaderToText, DS.ARGS())
        .def("className", &PyDbMLeaderStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMLeaderStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        ;

    enum_<AcDbMLeaderStyle::ContentType>("MLeaderContentType")
        .value("kNoneContent", AcDbMLeaderStyle::ContentType::kNoneContent)
        .value("kBlockContent", AcDbMLeaderStyle::ContentType::kBlockContent)
        .value("kMTextContent", AcDbMLeaderStyle::ContentType::kMTextContent)
        .value("kToleranceContent", AcDbMLeaderStyle::ContentType::kToleranceContent)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::DrawMLeaderOrderType>("DrawMLeaderOrderType")
        .value("kDrawContentFirst", AcDbMLeaderStyle::DrawMLeaderOrderType::kDrawContentFirst)
        .value("kDrawLeaderFirst", AcDbMLeaderStyle::DrawMLeaderOrderType::kDrawLeaderFirst)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::DrawLeaderOrderType>("DrawLeaderOrderType")
        .value("kDrawLeaderHeadFirst", AcDbMLeaderStyle::DrawLeaderOrderType::kDrawLeaderHeadFirst)
        .value("kDrawLeaderTailFirst", AcDbMLeaderStyle::DrawLeaderOrderType::kDrawLeaderTailFirst)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::LeaderType>("MLeaderLeaderType")
        .value("kInVisibleLeader", AcDbMLeaderStyle::LeaderType::kInVisibleLeader)
        .value("kStraightLeader", AcDbMLeaderStyle::LeaderType::kStraightLeader)
        .value("kSplineLeader", AcDbMLeaderStyle::LeaderType::kSplineLeader)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::TextAttachmentDirection>("MLeaderTextAttachmentDirection")
        .value("kAttachmentHorizontal", AcDbMLeaderStyle::TextAttachmentDirection::kAttachmentHorizontal)
        .value("kAttachmentVertical", AcDbMLeaderStyle::TextAttachmentDirection::kAttachmentVertical)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::TextAttachmentType>("MLeaderTextAttachmentType")
        .value("kAttachmentTopOfTop", AcDbMLeaderStyle::TextAttachmentType::kAttachmentTopOfTop)
        .value("kAttachmentMiddleOfTop", AcDbMLeaderStyle::TextAttachmentType::kAttachmentMiddleOfTop)
        .value("kAttachmentMiddle", AcDbMLeaderStyle::TextAttachmentType::kAttachmentMiddle)
        .value("kAttachmentMiddleOfBottom", AcDbMLeaderStyle::TextAttachmentType::kAttachmentMiddleOfBottom)
        .value("kAttachmentBottomOfBottom", AcDbMLeaderStyle::TextAttachmentType::kAttachmentBottomOfBottom)
        .value("kAttachmentBottomLine", AcDbMLeaderStyle::TextAttachmentType::kAttachmentBottomLine)
        .value("kAttachmentBottomOfTopLine", AcDbMLeaderStyle::TextAttachmentType::kAttachmentBottomOfTopLine)
        .value("kAttachmentBottomOfTop", AcDbMLeaderStyle::TextAttachmentType::kAttachmentBottomOfTop)
        .value("kAttachmentAllLine", AcDbMLeaderStyle::TextAttachmentType::kAttachmentAllLine)
        .value("kAttachmentCenter", AcDbMLeaderStyle::TextAttachmentType::kAttachmentCenter)
        .value("kAttachmentLinedCenter", AcDbMLeaderStyle::TextAttachmentType::kAttachmentLinedCenter)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::TextAngleType>("MLeaderTextAngleType")
        .value("kInsertAngle", AcDbMLeaderStyle::TextAngleType::kInsertAngle)
        .value("kHorizontalAngle", AcDbMLeaderStyle::TextAngleType::kHorizontalAngle)
        .value("kAlwaysRightReadingAngle", AcDbMLeaderStyle::TextAngleType::kAlwaysRightReadingAngle)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::TextAlignmentType>("MLeaderTextAlignmentType")
        .value("kLeftAlignment", AcDbMLeaderStyle::TextAlignmentType::kLeftAlignment)
        .value("kCenterAlignment", AcDbMLeaderStyle::TextAlignmentType::kCenterAlignment)
        .value("kRightAlignment", AcDbMLeaderStyle::TextAlignmentType::kRightAlignment)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::BlockConnectionType>("MLeaderBlockConnectionType")
        .value("kConnectExtents", AcDbMLeaderStyle::BlockConnectionType::kConnectExtents)
        .value("kConnectBase", AcDbMLeaderStyle::BlockConnectionType::kConnectBase)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::LeaderDirectionType>("MLeaderLeaderDirectionType")
        .value("kUnknownLeader", AcDbMLeaderStyle::LeaderDirectionType::kUnknownLeader)
        .value("kLeftLeader", AcDbMLeaderStyle::LeaderDirectionType::kLeftLeader)
        .value("kRightLeader", AcDbMLeaderStyle::LeaderDirectionType::kRightLeader)
        .value("kTopLeader", AcDbMLeaderStyle::LeaderDirectionType::kTopLeader)
        .value("kBottomLeader", AcDbMLeaderStyle::LeaderDirectionType::kBottomLeader)
        .export_values()
        ;
    enum_<AcDbMLeaderStyle::SegmentAngleType>("MLeaderSegmentAngleType")
        .value("kAny", AcDbMLeaderStyle::SegmentAngleType::kAny)
        .value("k15", AcDbMLeaderStyle::SegmentAngleType::k15)
        .value("k30", AcDbMLeaderStyle::SegmentAngleType::k30)
        .value("k45", AcDbMLeaderStyle::SegmentAngleType::k45)
        .value("k60", AcDbMLeaderStyle::SegmentAngleType::k60)
        .value("k90", AcDbMLeaderStyle::SegmentAngleType::k90)
        .value("kHorz", AcDbMLeaderStyle::SegmentAngleType::kHorz)
        .export_values()
        ;
}

PyDbMLeaderStyle::PyDbMLeaderStyle()
    : PyDbObject(new AcDbMLeaderStyle(), true)
{
}

PyDbMLeaderStyle::PyDbMLeaderStyle(AcDbMLeaderStyle* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbMLeaderStyle::PyDbMLeaderStyle(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbMLeaderStyle>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMLeaderStyle::PyDbMLeaderStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbMLeaderStyle>(id, mode), false)
{
}

PyDbMLeaderStyle::PyDbMLeaderStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool openEdased)
    : PyDbObject(openAcDbObject<AcDbMLeaderStyle>(id, mode, openEdased), false)
{
}

std::string PyDbMLeaderStyle::getName() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr name;
    PyThrowBadEs(impObj()->getName(name.buf));
    return name.str();
#else
    AcString name;
    PyThrowBadEs(impObj()->getName(name));
    return wstr_to_utf8(name);
#endif
}

void PyDbMLeaderStyle::setName(const std::string& pszName) const
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(pszName).c_str()));
}

bool PyDbMLeaderStyle::isRenamable() const
{
    throw PyNotimplementedByHost();
}

const std::string PyDbMLeaderStyle::description(void) const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbMLeaderStyle::setDescription(const std::string& pszDescription) const
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(pszDescription).c_str()));
}

Adesk::UInt32 PyDbMLeaderStyle::bitFlags() const
{
    return impObj()->bitFlags();
}

void PyDbMLeaderStyle::setBitFlags(Adesk::UInt32 flags) const
{
    return PyThrowBadEs(impObj()->setBitFlags(flags));
}

AcDbMLeaderStyle::ContentType PyDbMLeaderStyle::contentType() const
{
    return impObj()->contentType();
}

void PyDbMLeaderStyle::setContentType(AcDbMLeaderStyle::ContentType contentType) const
{
    return PyThrowBadEs(impObj()->setContentType(contentType));
}

void PyDbMLeaderStyle::setDrawMLeaderOrderType(AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDrawMLeaderOrderType(drawMLeaderOrderType));
#endif
}

AcDbMLeaderStyle::DrawMLeaderOrderType PyDbMLeaderStyle::drawMLeaderOrderType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->drawMLeaderOrderType();
#endif
}

void PyDbMLeaderStyle::setDrawLeaderOrderType(AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDrawLeaderOrderType(drawLeaderOrderType));
#endif
}

AcDbMLeaderStyle::DrawLeaderOrderType PyDbMLeaderStyle::drawLeaderOrderType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->drawLeaderOrderType();
#endif
}

void PyDbMLeaderStyle::setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints) const
{
    return PyThrowBadEs(impObj()->setMaxLeaderSegmentsPoints(maxLeaderSegmentsPoints));
}

int PyDbMLeaderStyle::maxLeaderSegmentsPoints() const
{
    return impObj()->maxLeaderSegmentsPoints();
}

void PyDbMLeaderStyle::setFirstSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle) const
{
    return PyThrowBadEs(impObj()->setFirstSegmentAngleConstraint(angle));
}

AcDbMLeaderStyle::SegmentAngleType PyDbMLeaderStyle::firstSegmentAngleConstraint() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->firstSegmentAngleConstraint();
#endif
}

void PyDbMLeaderStyle::setSecondSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle) const
{
    return PyThrowBadEs(impObj()->setSecondSegmentAngleConstraint(angle));
}

AcDbMLeaderStyle::SegmentAngleType PyDbMLeaderStyle::secondSegmentAngleConstraint() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->secondSegmentAngleConstraint();
#endif
}

void PyDbMLeaderStyle::setLeaderLineType(AcDbMLeaderStyle::LeaderType leaderLineType) const
{
    return PyThrowBadEs(impObj()->setLeaderLineType(leaderLineType));
}

AcDbMLeaderStyle::LeaderType PyDbMLeaderStyle::leaderLineType() const
{
    return impObj()->leaderLineType();
}

void PyDbMLeaderStyle::setLeaderLineColor(const AcCmColor& leaderLineColor) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineColor));
#endif
}

AcCmColor PyDbMLeaderStyle::leaderLineColor() const
{
    return impObj()->leaderLineColor();
}

void PyDbMLeaderStyle::setLeaderLineTypeId(const PyDbObjectId& leaderLineTypeId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineTypeId.m_id));
#endif
}

PyDbObjectId PyDbMLeaderStyle::leaderLineTypeId() const
{
    return impObj()->leaderLineTypeId();
}

void PyDbMLeaderStyle::setLeaderLineWeight(AcDb::LineWeight leaderLineWeight) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineWeight));
#endif
}

AcDb::LineWeight PyDbMLeaderStyle::leaderLineWeight() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->leaderLineWeight();
#endif
}

void PyDbMLeaderStyle::setEnableLanding(bool enableLanding) const
{
    return PyThrowBadEs(impObj()->setEnableLanding(enableLanding));
}

bool PyDbMLeaderStyle::enableLanding() const
{
    return impObj()->enableLanding();
}

void PyDbMLeaderStyle::setLandingGap(double landingGap) const
{
    return PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

double PyDbMLeaderStyle::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbMLeaderStyle::setEnableDogleg(bool enableDogleg) const
{
    return PyThrowBadEs(impObj()->setEnableDogleg(enableDogleg));
}

bool PyDbMLeaderStyle::enableDogleg() const
{
    return impObj()->enableDogleg();
}

void PyDbMLeaderStyle::setDoglegLength(double doglegLength) const
{
    return PyThrowBadEs(impObj()->setEnableDogleg(doglegLength));
}

double PyDbMLeaderStyle::doglegLength() const
{
    return impObj()->doglegLength();
}

void PyDbMLeaderStyle::setArrowSymbolId1(const std::string& name) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setArrowSymbolId(utf8_to_wstr(name).c_str()));
#endif
}

void PyDbMLeaderStyle::setArrowSymbolId2(const PyDbObjectId& arrowSymbolId) const
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(arrowSymbolId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::arrowSymbolId() const
{
    return PyDbObjectId(impObj()->arrowSymbolId());
}

void PyDbMLeaderStyle::setArrowSize(double arrowSize) const
{
    return PyThrowBadEs(impObj()->setArrowSize(arrowSize));
}

double PyDbMLeaderStyle::arrowSize() const
{
    return impObj()->arrowSize();
}

void PyDbMLeaderStyle::setDefaultMText(const PyDbMText& defaultMText) const
{
    return PyThrowBadEs(impObj()->setDefaultMText(defaultMText.impObj()));
}

PyDbMText PyDbMLeaderStyle::defaultMText() const
{
    return PyDbMText(impObj()->defaultMText(), true);
}

void PyDbMLeaderStyle::setTextStyleId(const PyDbObjectId& textStyleId) const
{
    return PyThrowBadEs(impObj()->setTextStyleId(textStyleId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::textStyleId() const
{
    return PyDbObjectId(impObj()->textStyleId());
}

void PyDbMLeaderStyle::setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType, leaderDirection));
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeaderStyle::textAttachmentType1(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return impObj()->textAttachmentType(leaderDirection);
}

void PyDbMLeaderStyle::setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType));
#endif
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeaderStyle::textAttachmentType2() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->textAttachmentType();
#endif
}

void PyDbMLeaderStyle::setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType) const
{
    return PyThrowBadEs(impObj()->setTextAngleType(textAngleType));
}

AcDbMLeaderStyle::TextAngleType PyDbMLeaderStyle::textAngleType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->textAngleType();
#endif
}

void PyDbMLeaderStyle::setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
#endif
}

AcDbMLeaderStyle::TextAlignmentType PyDbMLeaderStyle::textAlignmentType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->textAlignmentType();
#endif
}

void PyDbMLeaderStyle::setTextAlignAlwaysLeft(bool bAlwaysLeft) const
{
    return PyThrowBadEs(impObj()->setTextAlignAlwaysLeft(bAlwaysLeft));
}

bool PyDbMLeaderStyle::textAlignAlwaysLeft() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->textAlignAlwaysLeft();
#endif
}

void PyDbMLeaderStyle::setTextColor(const AcCmColor& textColor) const
{
    return PyThrowBadEs(impObj()->setTextColor(textColor));
}

AcCmColor PyDbMLeaderStyle::textColor() const
{
    return impObj()->textColor();
}

void PyDbMLeaderStyle::setTextHeight(double textHeight) const
{
    return PyThrowBadEs(impObj()->setTextHeight(textHeight));
}

double PyDbMLeaderStyle::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMLeaderStyle::setEnableFrameText(bool enableFrameText) const
{
    return PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

bool PyDbMLeaderStyle::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbMLeaderStyle::setAlignSpace(double alignSpace) const
{
    return PyThrowBadEs(impObj()->setAlignSpace(alignSpace));
}

double PyDbMLeaderStyle::alignSpace() const
{
    return impObj()->alignSpace();
}

void PyDbMLeaderStyle::setBlockId1(const std::string& name) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockId(utf8_to_wstr(name).c_str()));
#endif
}

void PyDbMLeaderStyle::setBlockId2(const PyDbObjectId& blockId) const
{
    return PyThrowBadEs(impObj()->setBlockId(blockId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

void PyDbMLeaderStyle::setBlockColor(const AcCmColor& blockColor) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockColor(blockColor));
#endif
}

AcCmColor PyDbMLeaderStyle::blockColor() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->blockColor();
#endif
}

void PyDbMLeaderStyle::setBlockScale(const AcGeScale3d& scale) const
{
    return PyThrowBadEs(impObj()->setBlockScale(scale));
}

AcGeScale3d PyDbMLeaderStyle::blockScale() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->blockScale();
#endif
}

void PyDbMLeaderStyle::setEnableBlockScale(bool enableBlockScale) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setEnableBlockScale(enableBlockScale));
#endif
}

bool PyDbMLeaderStyle::enableBlockScale() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->enableBlockScale();
#endif
}

void PyDbMLeaderStyle::setBlockRotation(double rotation) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockRotation(rotation));
#endif
}

double PyDbMLeaderStyle::blockRotation() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->blockRotation();
#endif
}

void PyDbMLeaderStyle::setEnableBlockRotation(bool enableBlockRotation) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setEnableBlockRotation(enableBlockRotation));
#endif
}

bool PyDbMLeaderStyle::enableBlockRotation() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->enableBlockRotation();
#endif
}

void PyDbMLeaderStyle::setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockConnectionType(blockConnectionType));
#endif
}

AcDbMLeaderStyle::BlockConnectionType PyDbMLeaderStyle::blockConnectionType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->blockConnectionType();
#endif
}

void PyDbMLeaderStyle::setScale(double scale) const
{
    return PyThrowBadEs(impObj()->setScale(scale));
}

double PyDbMLeaderStyle::scale() const
{
    return impObj()->scale();
}

bool PyDbMLeaderStyle::overwritePropChanged() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->overwritePropChanged();
#endif
}

PyDbObjectId PyDbMLeaderStyle::postMLeaderStyleToDb(PyDbDatabase& pDb, const std::string& styleName) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->postMLeaderStyleToDb(pDb.impObj(), utf8_to_wstr(styleName).c_str(), id));
    return PyDbObjectId(id);
}

void PyDbMLeaderStyle::setAnnotative(bool isAnnotative) const
{
    return PyThrowBadEs(impObj()->setAnnotative(isAnnotative));
}

bool PyDbMLeaderStyle::annotative() const
{
    return impObj()->annotative();
}

void PyDbMLeaderStyle::setBreakSize(double size) const
{
    return PyThrowBadEs(impObj()->setBreakSize(size));
}

double PyDbMLeaderStyle::breakSize() const
{
    return impObj()->breakSize();
}

void PyDbMLeaderStyle::setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTextAttachmentDirection(textAttachmentDirection));
#endif
}

AcDbMLeaderStyle::TextAttachmentDirection PyDbMLeaderStyle::textAttachmentDirection() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->textAttachmentDirection();
#endif
}

void PyDbMLeaderStyle::setExtendLeaderToText(bool value) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtendLeaderToText(value));
#endif
}

bool PyDbMLeaderStyle::extendLeaderToText() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->extendLeaderToText();
#endif
}

std::string PyDbMLeaderStyle::className()
{
    return "AcDbMLeaderStyle";
}

PyRxClass PyDbMLeaderStyle::desc()
{
    return PyRxClass(AcDbMLeaderStyle::desc(), false);
}

AcDbMLeaderStyle* PyDbMLeaderStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMLeaderStyle*>(m_pyImp.get());
}
