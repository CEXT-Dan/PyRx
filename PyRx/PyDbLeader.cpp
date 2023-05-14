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
    class_<PyDbLeader, bases<PyDbCurve>>("Leader")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setPlane", &PyDbLeader::setPlane)
        .def("normal", &PyDbLeader::normal)
        .def("numVertices", &PyDbLeader::numVertices)
        .def("appendVertex", &PyDbLeader::appendVertex)
        .def("removeLastVertex", &PyDbLeader::removeLastVertex)
        .def("firstVertex", &PyDbLeader::firstVertex)
        .def("lastVertex", &PyDbLeader::lastVertex)
        .def("vertexAt", &PyDbLeader::vertexAt)
        .def("setVertexAt", &PyDbLeader::setVertexAt)
        .def("hasArrowHead", &PyDbLeader::hasArrowHead)
        .def("disableArrowHead", &PyDbLeader::disableArrowHead)
        .def("setHasArrowHead", &PyDbLeader::setHasArrowHead)
        .def("hasHookLine", &PyDbLeader::hasHookLine)
        .def("setToSplineLeader", &PyDbLeader::setToSplineLeader)
        .def("setToStraightLeader", &PyDbLeader::setToStraightLeader)
        .def("isSplined", &PyDbLeader::isSplined)
        .def("setSplined", &PyDbLeader::setSplined)
        .def("dimensionStyle", &PyDbLeader::dimensionStyle)
        .def("setDimensionStyle", &PyDbLeader::setDimensionStyle)
        .def("setDimstyleData", &PyDbLeader::setDimstyleData)
        .def("attachAnnotation", &PyDbLeader::attachAnnotation)
        .def("detachAnnotation", &PyDbLeader::detachAnnotation)
        .def("annotationObjId", &PyDbLeader::annotationObjId)
        .def("setAnnotationObjId", &PyDbLeader::setAnnotationObjId)
        .def("evaluateLeader", &PyDbLeader::evaluateLeader)
        .def("annotationOffset", &PyDbLeader::annotationOffset)
        .def("setAnnotationOffset", &PyDbLeader::setAnnotationOffset)
        .def("annoType", &PyDbLeader::annoType)
        .def("annoHeight", &PyDbLeader::annoHeight)
        .def("annoWidth", &PyDbLeader::annoWidth)
        .def("dimasz", &PyDbLeader::dimasz)
        .def("dimclrd", &PyDbLeader::dimclrd)
        .def("dimgap", &PyDbLeader::dimgap)
        .def("dimlwd", &PyDbLeader::dimlwd)
        .def("dimsah", &PyDbLeader::dimsah)
        .def("dimscale", &PyDbLeader::dimscale)
        .def("dimtad", &PyDbLeader::dimtad)
        .def("dimtxsty", &PyDbLeader::dimtxsty)
        .def("dimtxt", &PyDbLeader::dimtxt)
        .def("setDimasz", &PyDbLeader::setDimasz)
        .def("setDimclrd", &PyDbLeader::setDimclrd)
        .def("setDimgap", &PyDbLeader::setDimgap)
        .def("setDimldrblk", &PyDbLeader::setDimldrblk1)
        .def("setDimldrblk", &PyDbLeader::setDimldrblk2)
        .def("setDimlwd", &PyDbLeader::setDimlwd)
        .def("setDimsah", &PyDbLeader::setDimsah)
        .def("setDimscale", &PyDbLeader::setDimscale)
        .def("setDimtad", &PyDbLeader::setDimtad)
        .def("setDimtxsty", &PyDbLeader::setDimtxsty)
        .def("setDimtxt", &PyDbLeader::setDimtxt)
        .def("modified", &PyDbLeader::modified)
        .def("erased", &PyDbLeader::erased1)
        .def("erased", &PyDbLeader::erased2)
        .def("goodbye", &PyDbLeader::goodbye)
        .def("copied", &PyDbLeader::copied)
        .def("setColorIndex", &PyDbLeader::setColorIndex1)
        .def("setColorIndex", &PyDbLeader::setColorIndex2)
        .def("className", &PyDbLeader::className).staticmethod("className")
        .def("desc", &PyDbLeader::desc).staticmethod("desc")
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

PyDbLeader::PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbLeader* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLeader>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

void PyDbLeader::setPlane(const PyGePlane& plane)
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

Adesk::Boolean PyDbLeader::appendVertex(const AcGePoint3d& val)
{
    return impObj()->appendVertex(val);
}

void PyDbLeader::removeLastVertex()
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

Adesk::Boolean PyDbLeader::setVertexAt(int idx, const AcGePoint3d& val)
{
    return impObj()->setVertexAt(idx, val);
}

Adesk::Boolean PyDbLeader::hasArrowHead() const
{
    return impObj()->hasArrowHead();
}

void PyDbLeader::enableArrowHead()
{
    return impObj()->enableArrowHead();
}

void PyDbLeader::disableArrowHead()
{
    return impObj()->disableArrowHead();
}

void PyDbLeader::setHasArrowHead(Adesk::Boolean bEnable)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHasArrowHead(bEnable);
#endif
}

Adesk::Boolean PyDbLeader::hasHookLine() const
{
    return impObj()->hasHookLine();
}

void PyDbLeader::setToSplineLeader()
{
    return impObj()->setToSplineLeader();
}

void PyDbLeader::setToStraightLeader()
{
    return impObj()->setToStraightLeader();
}

Adesk::Boolean PyDbLeader::isSplined() const
{
    return impObj()->isSplined();
}

void PyDbLeader::setSplined(Adesk::Boolean bSplined)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSplined(bSplined);
#endif
}

PyDbHardPointerId PyDbLeader::dimensionStyle() const
{
    return PyDbHardPointerId(impObj()->dimensionStyle());
}

void PyDbLeader::setDimensionStyle(const PyDbHardPointerId& val)
{
    return impObj()->setDimensionStyle(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimstyleData(const PyDbObjectId& newDataId)
{
    return impObj()->setDimstyleData(newDataId.m_id);
}

Acad::ErrorStatus PyDbLeader::attachAnnotation(const PyDbObjectId& annoId)
{
    return impObj()->attachAnnotation(annoId.m_id);
}

Acad::ErrorStatus PyDbLeader::detachAnnotation()
{
    return impObj()->detachAnnotation();
}

PyDbObjectId PyDbLeader::annotationObjId() const
{
    return PyDbObjectId(impObj()->annotationObjId());
}

Acad::ErrorStatus PyDbLeader::setAnnotationObjId(const PyDbObjectId& annoId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAnnotationObjId(annoId.m_id);
#endif
}

Acad::ErrorStatus PyDbLeader::evaluateLeader()
{
    return impObj()->evaluateLeader();
}

AcGeVector3d PyDbLeader::annotationOffset() const
{
    return impObj()->annotationOffset();
}

Acad::ErrorStatus PyDbLeader::setAnnotationOffset(const AcGeVector3d& offset)
{
    return impObj()->setAnnotationOffset(offset);
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

Acad::ErrorStatus PyDbLeader::setDimasz(double val)
{
    return impObj()->setDimasz(val);
}

Acad::ErrorStatus PyDbLeader::setDimclrd(AcCmColor& val)
{
    return impObj()->setDimclrd(val);
}

Acad::ErrorStatus PyDbLeader::setDimgap(double val)
{
    return impObj()->setDimgap(val);
}

Acad::ErrorStatus PyDbLeader::setDimldrblk1(const PyDbObjectId& val)
{
    return impObj()->setDimldrblk(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimldrblk2(const std::string& val)
{
    return impObj()->setDimldrblk(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbLeader::setDimlwd(AcDb::LineWeight val)
{
    return impObj()->setDimlwd(val);
}

Acad::ErrorStatus PyDbLeader::setDimsah(bool val)
{
    return impObj()->setDimsah(val);
}

Acad::ErrorStatus PyDbLeader::setDimscale(double val)
{
    return impObj()->setDimscale(val);
}

Acad::ErrorStatus PyDbLeader::setDimtad(int val)
{
    return impObj()->setDimtad(val);
}

Acad::ErrorStatus PyDbLeader::setDimtxsty(const PyDbObjectId& val)
{
    return impObj()->setDimtxsty(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimtxt(double val)
{
    return impObj()->setDimtxt(val);
}

void PyDbLeader::modified(const PyDbObject& obj)
{
    return impObj()->modified(obj.impObj());
}

void PyDbLeader::erased1(const PyDbObject& obj)
{
    return impObj()->erased(obj.impObj());
}

void PyDbLeader::erased2(const PyDbObject& obj, Adesk::Boolean val)
{
    return impObj()->erased(obj.impObj(), val);
}

void PyDbLeader::goodbye(const PyDbObject& obj)
{
    return impObj()->goodbye(obj.impObj());
}

void PyDbLeader::copied(const PyDbObject& objA, const PyDbObject& objB)
{
    return impObj()->copied(objA.impObj(), objB.impObj());
}

Acad::ErrorStatus PyDbLeader::setColorIndex1(Adesk::UInt16 val)
{
    return impObj()->setColorIndex(val);
}

Acad::ErrorStatus PyDbLeader::setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents)
{
    return impObj()->setColorIndex(val, doSubents);
}

std::string PyDbLeader::className()
{
    return "AcDbLeader";
}

PyRxClass PyDbLeader::desc()
{
    return PyRxClass(AcDbLeader::desc(), false);
}

AcDbLeader* PyDbLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLeader*>(m_pImp.get());
}


//----------------------------------------------------------------------------------
//PyDbMLeader
void makePyDbMLeaderWrapper()
{
    class_<PyDbMLeader, bases<PyDbEntity>>("MLeader")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("objectClosed", &PyDbMLeader::objectClosed)
        .def("modified", &PyDbMLeader::modified)
        .def("setOverride", &PyDbMLeader::setOverride1)
        .def("setOverride", &PyDbMLeader::setOverride2)
        .def("isOverride", &PyDbMLeader::isOverride)
        .def("setScale", &PyDbMLeader::setScale)
        .def("scale", &PyDbMLeader::scale)
        .def("getBlockAttributeValue", &PyDbMLeader::getBlockAttributeValue1)
        .def("setBlockAttributeValue", &PyDbMLeader::setBlockAttributeValue1)
        .def("getBlockAttributeValue", &PyDbMLeader::getBlockAttributeValue2)
        .def("setBlockAttributeValue", &PyDbMLeader::setBlockAttributeValue2)
        .def("plane", &PyDbMLeader::plane)
        .def("setPlane", &PyDbMLeader::setPlane)
        .def("normal", &PyDbMLeader::normal)
        .def("moveMLeader", &PyDbMLeader::moveMLeader1)
        .def("moveMLeader", &PyDbMLeader::moveMLeader2)
        .def("getContentGeomExtents", &PyDbMLeader::getContentGeomExtents)
        .def("numLeaders", &PyDbMLeader::numLeaders)
        .def("getLeaderIndexes", &PyDbMLeader::getLeaderIndexes)
        .def("removeLeader", &PyDbMLeader::removeLeader)
        .def("numLeaderLines", &PyDbMLeader::numLeaderLines)
        .def("getLeaderLineIndexes", &PyDbMLeader::getLeaderLineIndexes1)
        .def("getLeaderLineIndexes", &PyDbMLeader::getLeaderLineIndexes2)
        .def("addLeader", &PyDbMLeader::addLeader)
        .def("addLeaderLine", &PyDbMLeader::addLeaderLine1)
        .def("addLeaderLine", &PyDbMLeader::addLeaderLine2)
        .def("removeLeaderLine", &PyDbMLeader::removeLeaderLine)
        .def("addFirstVertex", &PyDbMLeader::addFirstVertex)
        .def("removeFirstVertex", &PyDbMLeader::removeFirstVertex)
        .def("getFirstVertex", &PyDbMLeader::getFirstVertex)
        .def("setFirstVertex", &PyDbMLeader::setFirstVertex)
        .def("addLastVertex", &PyDbMLeader::addLastVertex)
        .def("removeLastVertex", &PyDbMLeader::removeLastVertex)
        .def("getLastVertex", &PyDbMLeader::getLastVertex)
        .def("setLastVertex", &PyDbMLeader::setLastVertex)
        .def("numVertices", &PyDbMLeader::numVertices)
        .def("setVertex", &PyDbMLeader::setVertex)
        .def("getVertex", &PyDbMLeader::getVertex)
        .def("getLeaderIndex", &PyDbMLeader::getLeaderIndex)
        .def("setDoglegDirection", &PyDbMLeader::setDoglegDirection)
        .def("getDoglegDirection", &PyDbMLeader::getDoglegDirection)
        .def("setLeaderLineType", &PyDbMLeader::setLeaderLineType1)
        .def("setLeaderLineType", &PyDbMLeader::setLeaderLineType2)
        .def("leaderLineType", &PyDbMLeader::leaderLineType)
        .def("getLeaderLineType", &PyDbMLeader::getLeaderLineType)
        .def("leaderLineColor", &PyDbMLeader::leaderLineColor)
        .def("setLeaderLineColor1", &PyDbMLeader::setLeaderLineColor1)
        .def("setLeaderLineColor1", &PyDbMLeader::setLeaderLineColor2)
        .def("getLeaderLineColor", &PyDbMLeader::getLeaderLineColor)
        .def("leaderLineTypeId", &PyDbMLeader::leaderLineTypeId)
        .def("setLeaderLineTypeId", &PyDbMLeader::setLeaderLineTypeId1)
        .def("setLeaderLineTypeId", &PyDbMLeader::setLeaderLineTypeId2)
        .def("getLeaderLineTypeId", &PyDbMLeader::getLeaderLineTypeId)
        .def("leaderLineWeight", &PyDbMLeader::leaderLineWeight)
        .def("setLeaderLineWeight1", &PyDbMLeader::setLeaderLineWeight1)
        .def("setLeaderLineWeight1", &PyDbMLeader::setLeaderLineWeight2)
        .def("getLeaderLineWeight", &PyDbMLeader::getLeaderLineWeight)
        .def("setLandingGap", &PyDbMLeader::setLandingGap)
        .def("landingGap", &PyDbMLeader::landingGap)
        .def("setEnableLanding", &PyDbMLeader::setEnableLanding)
        .def("enableLanding", &PyDbMLeader::enableLanding)
        .def("setEnableDogleg", &PyDbMLeader::setEnableDogleg)
        .def("enableDogleg", &PyDbMLeader::enableDogleg)
        .def("doglegLength", &PyDbMLeader::doglegLength)
        .def("setDoglegLength", &PyDbMLeader::setDoglegLength1)
        .def("setDoglegLength", &PyDbMLeader::setDoglegLength2)
        .def("getDoglegLength", &PyDbMLeader::getDoglegLength)
        .def("arrowSymbolId", &PyDbMLeader::arrowSymbolId)
        .def("setArrowSymbolId", &PyDbMLeader::setArrowSymbolId1)
        .def("setArrowSymbolId", &PyDbMLeader::setArrowSymbolId2)
        .def("getArrowSymbolId", &PyDbMLeader::getArrowSymbolId)
        .def("arrowSize", &PyDbMLeader::arrowSize)
        .def("setArrowSize", &PyDbMLeader::setArrowSize1)
        .def("setArrowSize", &PyDbMLeader::setArrowSize2)
        .def("getArrowSize", &PyDbMLeader::getArrowSize)
        .def("contentType", &PyDbMLeader::contentType)
        .def("setContentType", &PyDbMLeader::setContentType)
        .def("textStyleId", &PyDbMLeader::textStyleId)
        .def("setTextStyleId", &PyDbMLeader::setTextStyleId)
        .def("textAttachmentType", &PyDbMLeader::textAttachmentType1)
        .def("textAttachmentType", &PyDbMLeader::textAttachmentType2)
        .def("setTextAttachmentType", &PyDbMLeader::setTextAttachmentType1)
        .def("setTextAttachmentType", &PyDbMLeader::setTextAttachmentType2)
        .def("textAngleType", &PyDbMLeader::textAngleType)
        .def("setTextAngleType", &PyDbMLeader::setTextAngleType)
        .def("textAlignmentType", &PyDbMLeader::textAlignmentType)
        .def("setTextAlignmentType", &PyDbMLeader::setTextAlignmentType)
        .def("setTextColor", &PyDbMLeader::setTextColor)
        .def("textColor", &PyDbMLeader::textColor)
        .def("setTextHeight", &PyDbMLeader::setTextHeight)
        .def("textHeight", &PyDbMLeader::textHeight)
        .def("setEnableFrameText", &PyDbMLeader::setEnableFrameText)
        .def("enableFrameText", &PyDbMLeader::enableFrameText)
        .def("setMText", &PyDbMLeader::setMText)
        .def("mtext", &PyDbMLeader::mtext)
        .def("setBlockContentId", &PyDbMLeader::setBlockContentId)
        .def("blockContentId", &PyDbMLeader::blockContentId)
        .def("setBlockColor", &PyDbMLeader::setBlockColor)
        .def("blockColor", &PyDbMLeader::blockColor)
        .def("setBlockScale", &PyDbMLeader::setBlockScale)
        .def("blockScale", &PyDbMLeader::blockScale)
        .def("setBlockRotation", &PyDbMLeader::setBlockRotation)
        .def("blockRotation", &PyDbMLeader::blockRotation)
        .def("setBlockConnectionType", &PyDbMLeader::setBlockConnectionType)
        .def("blockConnectionType", &PyDbMLeader::blockConnectionType)
        .def("setEnableAnnotationScale", &PyDbMLeader::setEnableAnnotationScale)
        .def("enableAnnotationScale", &PyDbMLeader::enableAnnotationScale)
        .def("setMLeaderStyle", &PyDbMLeader::setMLeaderStyle)
        .def("MLeaderStyle", &PyDbMLeader::MLeaderStyle)
        .def("setBlockPosition", &PyDbMLeader::setBlockPosition)
        .def("getBlockPosition", &PyDbMLeader::getBlockPosition)
        .def("setTextLocation", &PyDbMLeader::setTextLocation)
        .def("getTextLocation", &PyDbMLeader::getTextLocation)
        .def("setToleranceLocation", &PyDbMLeader::setToleranceLocation)
        .def("getToleranceLocation", &PyDbMLeader::getToleranceLocation)
        .def("hasContent", &PyDbMLeader::hasContent)
        .def("connectionPoint", &PyDbMLeader::connectionPoint1)
        .def("connectionPoint", &PyDbMLeader::connectionPoint2)
        .def("recomputeBreakPoints", &PyDbMLeader::recomputeBreakPoints)
        .def("postMLeaderToDb", &PyDbMLeader::postMLeaderToDb)
        .def("updateLeaderLinePosition", &PyDbMLeader::updateLeaderLinePosition)
        .def("removeLeaderLineRefAssoc", &PyDbMLeader::removeLeaderLineRefAssoc)
        .def("setTextAttachmentDirection", &PyDbMLeader::setTextAttachmentDirection)
        .def("textAttachmentDirection", &PyDbMLeader::textAttachmentDirection)
        .def("setExtendLeaderToText", &PyDbMLeader::setExtendLeaderToText)
        .def("extendLeaderToText", &PyDbMLeader::extendLeaderToText)
        .def("className", &PyDbMLeader::className).staticmethod("className")
        .def("desc", &PyDbMLeader::desc).staticmethod("desc")
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

PyDbMLeader::PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbMLeader* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbMLeader>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

void PyDbMLeader::objectClosed(const PyDbObjectId& dbObjId)
{
    impObj()->objectClosed(dbObjId.m_id);
}

void PyDbMLeader::modified(const PyDbObject& dbObj)
{
    impObj()->modified(dbObj.impObj());
}

Acad::ErrorStatus PyDbMLeader::setOverride1(AcDbMLeader::PropertyOverrideType propertyType)
{
    return impObj()->setOverride(propertyType);
}

Acad::ErrorStatus PyDbMLeader::setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride)
{
    return impObj()->setOverride(propertyType, isOverride);
}

bool PyDbMLeader::isOverride(AcDbMLeader::PropertyOverrideType propertyType) const
{
    return impObj()->isOverride(propertyType);
}

Acad::ErrorStatus PyDbMLeader::setScale(double scale)
{
    return impObj()->setScale(scale);
}

double PyDbMLeader::scale() const
{
    return impObj()->scale();
}

PyDbAttribute PyDbMLeader::getBlockAttributeValue1(const PyDbObjectId& attdefId) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDbAttribute* patt = nullptr;
    if (auto es = impObj()->getBlockAttributeValue(attdefId.m_id, patt); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbAttribute(patt, true);
#endif
}

Acad::ErrorStatus PyDbMLeader::setBlockAttributeValue1(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt)
{
    return impObj()->setBlockAttributeValue(attdefId.m_id, pAtt.impObj());
}

std::string PyDbMLeader::getBlockAttributeValue2(const PyDbObjectId& attdefId) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    ACHAR* patt = nullptr;
    if (auto es = impObj()->getBlockAttributeValue(attdefId.m_id, patt); es != eOk)
        throw PyAcadErrorStatus(es);
    auto str = wstr_to_utf8(patt);
    acutDelString(patt);
    return str;
#endif
}

Acad::ErrorStatus PyDbMLeader::setBlockAttributeValue2(const PyDbObjectId& attdefId, const std::string& pAtt)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setBlockAttributeValue(attdefId.m_id, utf8_to_wstr(pAtt).c_str());
#endif
}

PyGePlane PyDbMLeader::plane() const
{
    return PyGePlane(impObj()->plane());
}

void PyDbMLeader::setPlane(const PyGePlane& plane)
{
    impObj()->setPlane(*plane.impObj());
}

AcGeVector3d PyDbMLeader::normal() const
{
    return impObj()->normal();
}

Acad::ErrorStatus PyDbMLeader::moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType)
{
    return impObj()->moveMLeader(vector, moveType);
}

Acad::ErrorStatus PyDbMLeader::moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg)
{
    return impObj()->moveMLeader(vector, moveType, bAutoSwitchDogleg);
}

AcDbExtents PyDbMLeader::getContentGeomExtents() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDbExtents ext;
    if (auto es = impObj()->getContentGeomExtents(ext); es != eOk)
        throw PyAcadErrorStatus(es);
    return ext;
#endif
}

int PyDbMLeader::numLeaders() const
{
    return impObj()->numLeaders();
}

boost::python::list PyDbMLeader::getLeaderIndexes() const
{
    boost::python::list _list;
    AcArray<int> leaderIndexes;
    if (auto es = impObj()->getLeaderIndexes(leaderIndexes); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : leaderIndexes)
        _list.append(item);
    return _list;
}

int PyDbMLeader::addLeader()
{
    int leaderIndex = 0;
    if (auto es = impObj()->addLeader(leaderIndex); es != eOk)
        throw PyAcadErrorStatus(es);
    return leaderIndex;
}

int PyDbMLeader::addLeaderLine1(int leaderIndex)
{
    int leaderLineIndex = 0;
    if (auto es = impObj()->addLeaderLine(leaderIndex, leaderLineIndex); es != eOk)
        throw PyAcadErrorStatus(es);
    return leaderLineIndex;
}

int PyDbMLeader::addLeaderLine2(const AcGePoint3d& point)
{
    int leaderLineIndex = 0;
    if (auto es = impObj()->addLeaderLine(point, leaderLineIndex); es != eOk)
        throw PyAcadErrorStatus(es);
    return leaderLineIndex;
}

Acad::ErrorStatus PyDbMLeader::removeLeaderLine(int leaderLineIndex)
{
    return impObj()->removeLeaderLine(leaderLineIndex);
}

Acad::ErrorStatus PyDbMLeader::addFirstVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return impObj()->addFirstVertex(leaderLineIndex, point);
}

Acad::ErrorStatus PyDbMLeader::removeFirstVertex(int leaderLineIndex)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeFirstVertex(leaderLineIndex);
#endif
}

AcGePoint3d PyDbMLeader::getFirstVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    if (auto es = impObj()->getFirstVertex(leaderLineIndex, point); es != eOk)
        throw PyAcadErrorStatus(es);
    return point;
}

Acad::ErrorStatus PyDbMLeader::setFirstVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return impObj()->setFirstVertex(leaderLineIndex, point);
}

Acad::ErrorStatus PyDbMLeader::addLastVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return impObj()->addLastVertex(leaderLineIndex, point);
}

Acad::ErrorStatus PyDbMLeader::removeLastVertex(int leaderLineIndex)
{
    return impObj()->removeLastVertex(leaderLineIndex);
}

Acad::ErrorStatus PyDbMLeader::removeLeader(int leaderIndex)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeLeader(leaderIndex);
#endif
}

int PyDbMLeader::numLeaderLines() const
{
    return impObj()->numLeaderLines();
}

boost::python::list PyDbMLeader::getLeaderLineIndexes1() const
{
    boost::python::list _list;
    AcArray<int> leaderIndexes;
    if (auto es = impObj()->getLeaderLineIndexes(leaderIndexes); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : leaderIndexes)
        _list.append(item);
    return _list;
}

boost::python::list PyDbMLeader::getLeaderLineIndexes2(int leaderIndex) const
{
    boost::python::list _list;
    AcArray<int> leaderIndexes;
    if (auto es = impObj()->getLeaderLineIndexes(leaderIndexes); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : leaderIndexes)
        _list.append(item);
    return _list;
}

AcGePoint3d PyDbMLeader::getLastVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    if (auto es = impObj()->getLastVertex(leaderLineIndex, point); es != eOk)
        throw PyAcadErrorStatus(es);
    return point;
}

Acad::ErrorStatus PyDbMLeader::setLastVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return impObj()->setLastVertex(leaderLineIndex, point);
}

int PyDbMLeader::numVertices(int leaderLineIndex) const
{
    int cnt;
    if (auto es = impObj()->numVertices(leaderLineIndex, cnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return cnt;
}

Acad::ErrorStatus PyDbMLeader::setVertex(int leaderLineIndex, int index, const AcGePoint3d& point)
{
    return impObj()->setVertex(leaderLineIndex, index, point);
}

AcGePoint3d PyDbMLeader::getVertex(int leaderLineIndex, int index) const
{
    AcGePoint3d point;
    if (auto es = impObj()->getVertex(leaderLineIndex, index, point); es != eOk)
        throw PyAcadErrorStatus(es);
    return point;
}

int PyDbMLeader::getLeaderIndex(int leaderLineIndex) const
{
    int cnt;
    if (auto es = impObj()->getLeaderIndex(leaderLineIndex, cnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return cnt;
}

Acad::ErrorStatus PyDbMLeader::setDoglegDirection(int leaderIndex, const AcGeVector3d& vector)
{
    return impObj()->setDoglegDirection(leaderIndex, vector);
}

AcGeVector3d PyDbMLeader::getDoglegDirection(int leaderIndex) const
{
    AcGeVector3d point;
    if (auto es = impObj()->getDoglegDirection(leaderIndex, point); es != eOk)
        throw PyAcadErrorStatus(es);
    return point;
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType)
{
    return impObj()->setLeaderLineType(leaderLineType);
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType leaderLineType)
{
    return impObj()->setLeaderLineType(leaderLineType, leaderLineType);
}

AcDbMLeaderStyle::LeaderType PyDbMLeader::getLeaderLineType(int leaderLineIndex) const
{
    AcDbMLeaderStyle::LeaderType leaderLineType = AcDbMLeaderStyle::kInVisibleLeader;
    if (auto es = impObj()->getLeaderLineType(leaderLineIndex, leaderLineType); es != eOk)
        throw PyAcadErrorStatus(es);
    return leaderLineType;
}

AcCmColor PyDbMLeader::leaderLineColor() const
{
    return impObj()->leaderLineColor();
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineColor1(const AcCmColor& leaderLineColor)
{
    return impObj()->setLeaderLineColor(leaderLineColor);
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLeaderLineColor(leaderLineIndex, leaderLineColor);
#endif
}

AcCmColor PyDbMLeader::getLeaderLineColor(int leaderLineIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcCmColor leaderLineColor;
    if (auto es = impObj()->getLeaderLineColor(leaderLineIndex, leaderLineColor); es != eOk)
        throw PyAcadErrorStatus(es);
    return leaderLineColor;
#endif
}

PyDbObjectId PyDbMLeader::leaderLineTypeId() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->leaderLineTypeId();
#endif
}

AcDbMLeaderStyle::LeaderType PyDbMLeader::leaderLineType() const
{
    return impObj()->leaderLineType();
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLeaderLineTypeId(leaderLineTypeId.m_id);
#endif
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLeaderLineTypeId(leaderLineIndex, leaderLineTypeId.m_id);
#endif
}

PyDbObjectId PyDbMLeader::getLeaderLineTypeId(int leaderLineIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDbObjectId id;
    if (auto es = impObj()->getLeaderLineTypeId(leaderLineIndex, id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
#endif
}

AcDb::LineWeight PyDbMLeader::leaderLineWeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->leaderLineWeight();
#endif
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLeaderLineWeight(leaderLineWeight);
#endif
}

Acad::ErrorStatus PyDbMLeader::setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight leaderLineWeight)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLeaderLineWeight(leaderLineIndex, leaderLineWeight);
#endif
}

AcDb::LineWeight PyDbMLeader::getLeaderLineWeight(int leaderLineIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDb::LineWeight wt;
    if (auto es = impObj()->getLeaderLineWeight(leaderLineIndex, wt); es != eOk)
        throw PyAcadErrorStatus(es);
    return wt;
#endif
}

Acad::ErrorStatus PyDbMLeader::setLandingGap(double landingGap)
{
    return impObj()->setLandingGap(landingGap);
}

double PyDbMLeader::landingGap() const
{
    return impObj()->landingGap();
}

Acad::ErrorStatus PyDbMLeader::setEnableLanding(bool enableLanding)
{
    return impObj()->setEnableLanding(enableLanding);
}

bool PyDbMLeader::enableLanding() const
{
    return impObj()->enableLanding();
}

Acad::ErrorStatus PyDbMLeader::setEnableDogleg(bool enableDogleg)
{
    return impObj()->setEnableDogleg(enableDogleg);
}

bool PyDbMLeader::enableDogleg() const
{
    return impObj()->enableDogleg();
}

double PyDbMLeader::doglegLength() const
{
    return impObj()->doglegLength();
}

Acad::ErrorStatus PyDbMLeader::setDoglegLength1(double doglegLength)
{
    return impObj()->setDoglegLength(doglegLength);
}

Acad::ErrorStatus PyDbMLeader::setDoglegLength2(int leaderIndex, double doglegLength)
{
    return impObj()->setDoglegLength(leaderIndex, doglegLength);
}

double PyDbMLeader::getDoglegLength(int leaderIndex) const
{
    double val;
    if (auto es = impObj()->doglegLength(leaderIndex, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

PyDbObjectId PyDbMLeader::arrowSymbolId() const
{
    return PyDbObjectId(impObj()->arrowSymbolId());
}

Acad::ErrorStatus PyDbMLeader::setArrowSymbolId1(const PyDbObjectId& arrowSymbolId)
{
    return impObj()->setArrowSymbolId(arrowSymbolId.m_id);
}

Acad::ErrorStatus PyDbMLeader::setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId)
{
    return impObj()->setArrowSymbolId(leaderLineIndex, arrowSymbolId.m_id);
}

PyDbObjectId PyDbMLeader::getArrowSymbolId(int leaderLineIndex) const
{
    AcDbObjectId val;
    if (auto es = impObj()->getArrowSymbolId(leaderLineIndex, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(val);
}

double PyDbMLeader::arrowSize() const
{
    return impObj()->arrowSize();
}

Acad::ErrorStatus PyDbMLeader::setArrowSize1(double arrowSize)
{
    return impObj()->setArrowSize(arrowSize);
}

Acad::ErrorStatus PyDbMLeader::setArrowSize2(int leaderLineIndex, double arrowSize)
{
    return impObj()->setArrowSize(leaderLineIndex, arrowSize);
}

double PyDbMLeader::getArrowSize(int leaderLineIndex) const
{
    double val;
    if (auto es = impObj()->getArrowSize(leaderLineIndex, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

AcDbMLeaderStyle::ContentType PyDbMLeader::contentType() const
{
    return impObj()->contentType();
}

Acad::ErrorStatus PyDbMLeader::setContentType(AcDbMLeaderStyle::ContentType contentType)
{
    return impObj()->setContentType(contentType);
}

PyDbObjectId PyDbMLeader::textStyleId() const
{
    return PyDbObjectId(impObj()->textStyleId());
}

Acad::ErrorStatus PyDbMLeader::setTextStyleId(const PyDbObjectId& textStyleId)
{
    return impObj()->setTextStyleId(textStyleId.m_id);
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeader::textAttachmentType1() const
{
    return impObj()->textAttachmentType();
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeader::textAttachmentType2(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return impObj()->textAttachmentType(leaderDirection);
}

Acad::ErrorStatus PyDbMLeader::setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType)
{
    return impObj()->setTextAttachmentType(textAttachmentType);
}

Acad::ErrorStatus PyDbMLeader::setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection)
{
    return impObj()->setTextAttachmentType(textAttachmentType, leaderDirection);
}

AcDbMLeaderStyle::TextAngleType PyDbMLeader::textAngleType() const
{
    return impObj()->textAngleType();
}

Acad::ErrorStatus PyDbMLeader::setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType)
{
    return impObj()->setTextAngleType(textAngleType);
}

AcDbMLeaderStyle::TextAlignmentType PyDbMLeader::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

Acad::ErrorStatus PyDbMLeader::setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType)
{
    return impObj()->setTextAlignmentType(textAlignmentType);
}

Acad::ErrorStatus PyDbMLeader::setTextColor(const AcCmColor& textColor)
{
    return impObj()->setTextColor(textColor);
}

AcCmColor PyDbMLeader::textColor() const
{
    return impObj()->textColor();
}

Acad::ErrorStatus PyDbMLeader::setTextHeight(double textHeight)
{
    return impObj()->setTextHeight(textHeight);
}

double PyDbMLeader::textHeight() const
{
    return impObj()->textHeight();
}

Acad::ErrorStatus PyDbMLeader::setEnableFrameText(bool enableFrameText)
{
    return impObj()->setEnableFrameText(enableFrameText);
}

bool PyDbMLeader::enableFrameText() const
{
    return impObj()->enableFrameText();
}

Acad::ErrorStatus PyDbMLeader::setMText(const PyDbMText& pMText)
{
    return impObj()->setMText(pMText.impObj());
}

PyDbMText PyDbMLeader::mtext() const
{
    return PyDbMText(impObj()->mtext(), true);
}

Acad::ErrorStatus PyDbMLeader::setBlockContentId(const PyDbObjectId& blockId)
{
    return impObj()->setBlockContentId(blockId.m_id);
}

PyDbObjectId PyDbMLeader::blockContentId() const
{
    return PyDbObjectId(impObj()->blockContentId());
}

Acad::ErrorStatus PyDbMLeader::setBlockColor(const AcCmColor& blockColor)
{
    return impObj()->setBlockColor(blockColor);
}

AcCmColor PyDbMLeader::blockColor() const
{
    return impObj()->blockColor();
}

Acad::ErrorStatus PyDbMLeader::setBlockScale(const AcGeScale3d& scale)
{
    return impObj()->setBlockScale(scale);
}

AcGeScale3d PyDbMLeader::blockScale() const
{
    return impObj()->blockScale();
}

Acad::ErrorStatus PyDbMLeader::setBlockRotation(double rotation)
{
    return impObj()->setBlockRotation(rotation);
}

double PyDbMLeader::blockRotation() const
{
    return impObj()->blockRotation();
}

Acad::ErrorStatus PyDbMLeader::setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType)
{
    return impObj()->setBlockConnectionType(blockConnectionType);
}

AcDbMLeaderStyle::BlockConnectionType PyDbMLeader::blockConnectionType() const
{
    return impObj()->blockConnectionType();
}

Acad::ErrorStatus PyDbMLeader::setEnableAnnotationScale(bool enableAnnotationScale)
{
    return impObj()->setEnableAnnotationScale(enableAnnotationScale);
}

bool PyDbMLeader::enableAnnotationScale() const
{
    return impObj()->enableAnnotationScale();
}

Acad::ErrorStatus PyDbMLeader::setMLeaderStyle(const PyDbObjectId& blockId)
{
    return impObj()->setMLeaderStyle(blockId.m_id);
}

PyDbObjectId PyDbMLeader::MLeaderStyle()
{
    return PyDbObjectId(impObj()->MLeaderStyle());
}

Acad::ErrorStatus PyDbMLeader::setBlockPosition(const AcGePoint3d& position)
{
    return impObj()->setBlockPosition(position);
}

AcGePoint3d PyDbMLeader::getBlockPosition() const
{
    AcGePoint3d val;
    if (auto es = impObj()->getBlockPosition(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMLeader::setTextLocation(const AcGePoint3d& location)
{
    return impObj()->setTextLocation(location);
}

AcGePoint3d PyDbMLeader::getTextLocation() const
{
    AcGePoint3d val;
    if (auto es = impObj()->getTextLocation(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMLeader::setToleranceLocation(const AcGePoint3d& location)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setToleranceLocation(location);
#endif
}

AcGePoint3d PyDbMLeader::getToleranceLocation() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcGePoint3d val;
    if (auto es = impObj()->getToleranceLocation(val); es != eOk)
        throw PyAcadErrorStatus(es);
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
    if (auto es = impObj()->connectionPoint(vect, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

AcGePoint3d PyDbMLeader::connectionPoint2(const AcGeVector3d& vect, AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcGePoint3d val;
    if (auto es = impObj()->connectionPoint(vect, val, textAttachmentDirection); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
#endif
}

Acad::ErrorStatus PyDbMLeader::recomputeBreakPoints()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->recomputeBreakPoints();
#endif
}

Acad::ErrorStatus PyDbMLeader::postMLeaderToDb(PyDbDatabase& pDb)
{
    return impObj()->postMLeaderToDb(pDb.impObj());
}

Acad::ErrorStatus PyDbMLeader::updateLeaderLinePosition()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->updateLeaderLinePosition();
#endif
}

Acad::ErrorStatus PyDbMLeader::removeLeaderLineRefAssoc(int leaderLineIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeLeaderLineRefAssoc(leaderLineIndex);
#endif
}

Acad::ErrorStatus PyDbMLeader::setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection)
{
    return impObj()->setTextAttachmentDirection(textAttachmentDirection);
}

AcDbMLeaderStyle::TextAttachmentDirection PyDbMLeader::textAttachmentDirection() const
{
    return impObj()->textAttachmentDirection();
}

Acad::ErrorStatus PyDbMLeader::setExtendLeaderToText(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtendLeaderToText(value);
#endif
}

bool PyDbMLeader::extendLeaderToText() const
{
#ifdef BRXAPP
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
    return PyRxClass(AcDbLeader::desc(), false);
}

AcDbMLeader* PyDbMLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbMLeader*>(m_pImp.get());
}
