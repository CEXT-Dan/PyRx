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
        .def("cloneFrom", &PyDbLeader::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLeader::cast).staticmethod("cast")
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
    : PyDbCurve(openAcDbObject<AcDbLeader>(id, mode), false)
{
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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

void PyDbLeader::setDimstyleData(const PyDbObjectId& newDataId)
{
    return PyThrowBadEs(impObj()->setDimstyleData(newDataId.m_id));
}

void PyDbLeader::attachAnnotation(const PyDbObjectId& annoId)
{
    return PyThrowBadEs(impObj()->attachAnnotation(annoId.m_id));
}

void PyDbLeader::detachAnnotation()
{
    return PyThrowBadEs(impObj()->detachAnnotation());
}

PyDbObjectId PyDbLeader::annotationObjId() const
{
    return PyDbObjectId(impObj()->annotationObjId());
}

void PyDbLeader::setAnnotationObjId(const PyDbObjectId& annoId)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAnnotationObjId(annoId.m_id));
#endif
}

void PyDbLeader::evaluateLeader()
{
    return PyThrowBadEs(impObj()->evaluateLeader());
}

AcGeVector3d PyDbLeader::annotationOffset() const
{
    return impObj()->annotationOffset();
}

void PyDbLeader::setAnnotationOffset(const AcGeVector3d& offset)
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

void PyDbLeader::setDimasz(double val)
{
    return PyThrowBadEs(impObj()->setDimasz(val));
}

void PyDbLeader::setDimclrd(AcCmColor& val)
{
    return PyThrowBadEs(impObj()->setDimclrd(val));
}

void PyDbLeader::setDimgap(double val)
{
    return PyThrowBadEs(impObj()->setDimgap(val));
}

void PyDbLeader::setDimldrblk1(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setDimldrblk(val.m_id));
}

void PyDbLeader::setDimldrblk2(const std::string& val)
{
    return PyThrowBadEs(impObj()->setDimldrblk(utf8_to_wstr(val).c_str()));
}

void PyDbLeader::setDimlwd(AcDb::LineWeight val)
{
    return PyThrowBadEs(impObj()->setDimlwd(val));
}

void PyDbLeader::setDimsah(bool val)
{
    return PyThrowBadEs(impObj()->setDimsah(val));
}

void PyDbLeader::setDimscale(double val)
{
    return PyThrowBadEs(impObj()->setDimscale(val));
}

void PyDbLeader::setDimtad(int val)
{
    return PyThrowBadEs(impObj()->setDimtad(val));
}

void PyDbLeader::setDimtxsty(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setDimtxsty(val.m_id));
}

void PyDbLeader::setDimtxt(double val)
{
    return PyThrowBadEs(impObj()->setDimtxt(val));
}

void PyDbLeader::modified(const PyDbObject& obj)
{
    return impObj()->modified(obj.impObj());
}

void PyDbLeader::erased1(const PyDbObject& obj)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->erased(obj.impObj());
#endif
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

void PyDbLeader::setColorIndex1(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setColorIndex(val));
}

void PyDbLeader::setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents)
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
    if (!src.impObj()->isKindOf(AcDbLeader::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLeader(static_cast<AcDbLeader*>(src.impObj()->clone()), true);
}

PyDbLeader PyDbLeader::cast(const PyRxObject& src)
{
    PyDbLeader dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def("getOverridedMLeaderStyle", &PyDbMLeader::getOverridedMLeaderStyle)
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
        .def("cloneFrom", &PyDbMLeader::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbMLeader::cast).staticmethod("cast")
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
    : PyDbEntity(openAcDbObject<AcDbMLeader>(id, mode), false)
{
}

void PyDbMLeader::objectClosed(const PyDbObjectId& dbObjId)
{
    impObj()->objectClosed(dbObjId.m_id);
}

void PyDbMLeader::modified(const PyDbObject& dbObj)
{
    impObj()->modified(dbObj.impObj());
}

void PyDbMLeader::setOverride1(AcDbMLeader::PropertyOverrideType propertyType)
{
    return PyThrowBadEs(impObj()->setOverride(propertyType));
}

void PyDbMLeader::setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride)
{
    return PyThrowBadEs(impObj()->setOverride(propertyType, isOverride));
}

bool PyDbMLeader::isOverride(AcDbMLeader::PropertyOverrideType propertyType) const
{
    return impObj()->isOverride(propertyType);
}

void PyDbMLeader::setScale(double scale)
{
    return PyThrowBadEs(impObj()->setScale(scale));
}

double PyDbMLeader::scale() const
{
    return impObj()->scale();
}

PyDbAttribute PyDbMLeader::getBlockAttributeValue1(const PyDbObjectId& attdefId) const
{
    AcDbAttribute* patt = nullptr;
    PyThrowBadEs(impObj()->getBlockAttributeValue(attdefId.m_id, patt));
    return PyDbAttribute(patt, true);
}

void PyDbMLeader::setBlockAttributeValue1(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt)
{
    return PyThrowBadEs(impObj()->setBlockAttributeValue(attdefId.m_id, pAtt.impObj()));
}

std::string PyDbMLeader::getBlockAttributeValue2(const PyDbObjectId& attdefId) const
{
    RxAutoOutStr patt;
    PyThrowBadEs(impObj()->getBlockAttributeValue(attdefId.m_id, patt.buf));
    return patt.str();
}

void PyDbMLeader::setBlockAttributeValue2(const PyDbObjectId& attdefId, const std::string& pAtt)
{
    return PyThrowBadEs(impObj()->setBlockAttributeValue(attdefId.m_id, utf8_to_wstr(pAtt).c_str()));
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

void PyDbMLeader::moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType)
{
    return PyThrowBadEs(impObj()->moveMLeader(vector, moveType));
}

void PyDbMLeader::moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg)
{
    return PyThrowBadEs(impObj()->moveMLeader(vector, moveType, bAutoSwitchDogleg));
}

AcDbExtents PyDbMLeader::getContentGeomExtents() const
{
    AcDbExtents ext;
    PyThrowBadEs(impObj()->getContentGeomExtents(ext));
    return ext;
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

int PyDbMLeader::addLeader()
{
    int leaderIndex = 0;
    PyThrowBadEs(impObj()->addLeader(leaderIndex));
    return leaderIndex;
}

int PyDbMLeader::addLeaderLine1(int leaderIndex)
{
    int leaderLineIndex = 0;
    PyThrowBadEs(impObj()->addLeaderLine(leaderIndex, leaderLineIndex));
    return leaderLineIndex;
}

int PyDbMLeader::addLeaderLine2(const AcGePoint3d& point)
{
    int leaderLineIndex = 0;
    PyThrowBadEs(impObj()->addLeaderLine(point, leaderLineIndex));
    return leaderLineIndex;
}

void PyDbMLeader::removeLeaderLine(int leaderLineIndex)
{
    return PyThrowBadEs(impObj()->removeLeaderLine(leaderLineIndex));
}

void PyDbMLeader::addFirstVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return PyThrowBadEs(impObj()->addFirstVertex(leaderLineIndex, point));
}

void PyDbMLeader::removeFirstVertex(int leaderLineIndex)
{
    return PyThrowBadEs(impObj()->removeFirstVertex(leaderLineIndex));
}

AcGePoint3d PyDbMLeader::getFirstVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getFirstVertex(leaderLineIndex, point));
    return point;
}

void PyDbMLeader::setFirstVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return PyThrowBadEs(impObj()->setFirstVertex(leaderLineIndex, point));
}

void PyDbMLeader::addLastVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return PyThrowBadEs(impObj()->addLastVertex(leaderLineIndex, point));
}

void PyDbMLeader::removeLastVertex(int leaderLineIndex)
{
    return PyThrowBadEs(impObj()->removeLastVertex(leaderLineIndex));
}

void PyDbMLeader::removeLeader(int leaderIndex)
{
    return PyThrowBadEs(impObj()->removeLeader(leaderIndex));
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
    AcDbIntArray leaderIndexes;
    PyThrowBadEs(impObj()->getLeaderLineIndexes(leaderIndexes));
    return IntArrayToPyList(leaderIndexes);
}

AcGePoint3d PyDbMLeader::getLastVertex(int leaderLineIndex) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getLastVertex(leaderLineIndex, point));
    return point;
}

void PyDbMLeader::setLastVertex(int leaderLineIndex, const AcGePoint3d& point)
{
    return PyThrowBadEs(impObj()->setLastVertex(leaderLineIndex, point));
}

int PyDbMLeader::numVertices(int leaderLineIndex) const
{
    int cnt;
    PyThrowBadEs(impObj()->numVertices(leaderLineIndex, cnt));
    return cnt;
}

void PyDbMLeader::setVertex(int leaderLineIndex, int index, const AcGePoint3d& point)
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

void PyDbMLeader::setDoglegDirection(int leaderIndex, const AcGeVector3d& vector)
{
    return PyThrowBadEs(impObj()->setDoglegDirection(leaderIndex, vector));
}

AcGeVector3d PyDbMLeader::getDoglegDirection(int leaderIndex) const
{
    AcGeVector3d point;
    PyThrowBadEs(impObj()->getDoglegDirection(leaderIndex, point));
    return point;
}

void PyDbMLeader::setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType)
{
    return PyThrowBadEs(impObj()->setLeaderLineType(leaderLineType));
}

void PyDbMLeader::setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType leaderLineType)
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

void PyDbMLeader::setLeaderLineColor1(const AcCmColor& leaderLineColor)
{
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineColor));
}

void PyDbMLeader::setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor)
{
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineIndex, leaderLineColor));
}

AcCmColor PyDbMLeader::getLeaderLineColor(int leaderLineIndex) const
{
    AcCmColor leaderLineColor;
    PyThrowBadEs(impObj()->getLeaderLineColor(leaderLineIndex, leaderLineColor));
    return leaderLineColor;
}

PyDbObjectId PyDbMLeader::leaderLineTypeId() const
{
    return impObj()->leaderLineTypeId();
}

AcDbMLeaderStyle::LeaderType PyDbMLeader::leaderLineType() const
{
    return impObj()->leaderLineType();
}

void PyDbMLeader::setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId)
{
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineTypeId.m_id));
}

void PyDbMLeader::setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId)
{
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineIndex, leaderLineTypeId.m_id));
}

PyDbObjectId PyDbMLeader::getLeaderLineTypeId(int leaderLineIndex) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getLeaderLineTypeId(leaderLineIndex, id));
    return PyDbObjectId(id);
}

AcDb::LineWeight PyDbMLeader::leaderLineWeight() const
{
    return impObj()->leaderLineWeight();
}

void PyDbMLeader::setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight)
{
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineWeight));
}

void PyDbMLeader::setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight leaderLineWeight)
{
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineIndex, leaderLineWeight));
}

AcDb::LineWeight PyDbMLeader::getLeaderLineWeight(int leaderLineIndex) const
{
    AcDb::LineWeight wt;
    PyThrowBadEs(impObj()->getLeaderLineWeight(leaderLineIndex, wt));
    return wt;
}

void PyDbMLeader::setLandingGap(double landingGap)
{
    return PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

double PyDbMLeader::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbMLeader::setEnableLanding(bool enableLanding)
{
    return PyThrowBadEs(impObj()->setEnableLanding(enableLanding));
}

bool PyDbMLeader::enableLanding() const
{
    return impObj()->enableLanding();
}

void PyDbMLeader::setEnableDogleg(bool enableDogleg)
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

void PyDbMLeader::setDoglegLength1(double doglegLength)
{
    return PyThrowBadEs(impObj()->setDoglegLength(doglegLength));
}

void PyDbMLeader::setDoglegLength2(int leaderIndex, double doglegLength)
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

void PyDbMLeader::setArrowSymbolId1(const PyDbObjectId& arrowSymbolId)
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(arrowSymbolId.m_id));
}

void PyDbMLeader::setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId)
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

void PyDbMLeader::setArrowSize1(double arrowSize)
{
    return PyThrowBadEs(impObj()->setArrowSize(arrowSize));
}

void PyDbMLeader::setArrowSize2(int leaderLineIndex, double arrowSize)
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

void PyDbMLeader::setContentType(AcDbMLeaderStyle::ContentType contentType)
{
    return PyThrowBadEs(impObj()->setContentType(contentType));
}

PyDbObjectId PyDbMLeader::textStyleId() const
{
    return PyDbObjectId(impObj()->textStyleId());
}

void PyDbMLeader::setTextStyleId(const PyDbObjectId& textStyleId)
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

void PyDbMLeader::setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType)
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType));
}

void PyDbMLeader::setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection)
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType, leaderDirection));
}

AcDbMLeaderStyle::TextAngleType PyDbMLeader::textAngleType() const
{
    return impObj()->textAngleType();
}

void PyDbMLeader::setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType)
{
    return PyThrowBadEs(impObj()->setTextAngleType(textAngleType));
}

AcDbMLeaderStyle::TextAlignmentType PyDbMLeader::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

void PyDbMLeader::setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType)
{
    return PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
}

void PyDbMLeader::setTextColor(const AcCmColor& textColor)
{
    return PyThrowBadEs(impObj()->setTextColor(textColor));
}

AcCmColor PyDbMLeader::textColor() const
{
    return impObj()->textColor();
}

void PyDbMLeader::setTextHeight(double textHeight)
{
    return PyThrowBadEs(impObj()->setTextHeight(textHeight));
}

double PyDbMLeader::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMLeader::setEnableFrameText(bool enableFrameText)
{
    return PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

bool PyDbMLeader::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbMLeader::setMText(const PyDbMText& pMText)
{
    return PyThrowBadEs(impObj()->setMText(pMText.impObj()));
}

PyDbMText PyDbMLeader::mtext() const
{
    return PyDbMText(impObj()->mtext(), true);
}

void PyDbMLeader::setBlockContentId(const PyDbObjectId& blockId)
{
    return PyThrowBadEs(impObj()->setBlockContentId(blockId.m_id));
}

PyDbObjectId PyDbMLeader::blockContentId() const
{
    return PyDbObjectId(impObj()->blockContentId());
}

void PyDbMLeader::setBlockColor(const AcCmColor& blockColor)
{
    return PyThrowBadEs(impObj()->setBlockColor(blockColor));
}

AcCmColor PyDbMLeader::blockColor() const
{
    return impObj()->blockColor();
}

void PyDbMLeader::setBlockScale(const AcGeScale3d& scale)
{
    return PyThrowBadEs(impObj()->setBlockScale(scale));
}

AcGeScale3d PyDbMLeader::blockScale() const
{
    return impObj()->blockScale();
}

void PyDbMLeader::setBlockRotation(double rotation)
{
    return PyThrowBadEs(impObj()->setBlockRotation(rotation));
}

double PyDbMLeader::blockRotation() const
{
    return impObj()->blockRotation();
}

void PyDbMLeader::setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType)
{
    return PyThrowBadEs(impObj()->setBlockConnectionType(blockConnectionType));
}

AcDbMLeaderStyle::BlockConnectionType PyDbMLeader::blockConnectionType() const
{
    return impObj()->blockConnectionType();
}

void PyDbMLeader::setEnableAnnotationScale(bool enableAnnotationScale)
{
    return PyThrowBadEs(impObj()->setEnableAnnotationScale(enableAnnotationScale));
}

bool PyDbMLeader::enableAnnotationScale() const
{
    return impObj()->enableAnnotationScale();
}

void PyDbMLeader::setMLeaderStyle(const PyDbObjectId& blockId)
{
    return PyThrowBadEs(impObj()->setMLeaderStyle(blockId.m_id));
}

PyDbObjectId PyDbMLeader::MLeaderStyle()
{
    return PyDbObjectId(impObj()->MLeaderStyle());
}

void PyDbMLeader::getOverridedMLeaderStyle(PyDbMLeaderStyle& mleaderStyle)
{
    return  PyThrowBadEs(impObj()->getOverridedMLeaderStyle(*mleaderStyle.impObj()));
}

void PyDbMLeader::setBlockPosition(const AcGePoint3d& position)
{
    return PyThrowBadEs(impObj()->setBlockPosition(position));
}

AcGePoint3d PyDbMLeader::getBlockPosition() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getBlockPosition(val));
    return val;
}

void PyDbMLeader::setTextLocation(const AcGePoint3d& location)
{
    return PyThrowBadEs(impObj()->setTextLocation(location));
}

AcGePoint3d PyDbMLeader::getTextLocation() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getTextLocation(val));
    return val;
}

void PyDbMLeader::setToleranceLocation(const AcGePoint3d& location)
{
    return PyThrowBadEs(impObj()->setToleranceLocation(location));
}

AcGePoint3d PyDbMLeader::getToleranceLocation() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getToleranceLocation(val));
    return val;
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
    AcGePoint3d val;
    PyThrowBadEs(impObj()->connectionPoint(vect, val, textAttachmentDirection));
    return val;
}

void PyDbMLeader::recomputeBreakPoints()
{
    return PyThrowBadEs(impObj()->recomputeBreakPoints());
}

void PyDbMLeader::postMLeaderToDb(PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->postMLeaderToDb(pDb.impObj()));
}

void PyDbMLeader::updateLeaderLinePosition()
{
    return PyThrowBadEs(impObj()->updateLeaderLinePosition());
}

void PyDbMLeader::removeLeaderLineRefAssoc(int leaderLineIndex) const
{
    return PyThrowBadEs(impObj()->removeLeaderLineRefAssoc(leaderLineIndex));
}

void PyDbMLeader::setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection)
{
    return PyThrowBadEs(impObj()->setTextAttachmentDirection(textAttachmentDirection));
}

AcDbMLeaderStyle::TextAttachmentDirection PyDbMLeader::textAttachmentDirection() const
{
    return impObj()->textAttachmentDirection();
}

void PyDbMLeader::setExtendLeaderToText(bool value)
{
    return PyThrowBadEs(impObj()->setExtendLeaderToText(value));
}

bool PyDbMLeader::extendLeaderToText() const
{
    return impObj()->extendLeaderToText();
}

std::string PyDbMLeader::className()
{
    return "AcDbMLeader";
}

PyRxClass PyDbMLeader::desc()
{
    return PyRxClass(AcDbLeader::desc(), false);
}

PyDbMLeader PyDbMLeader::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbMLeader::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMLeader(static_cast<AcDbMLeader*>(src.impObj()->clone()), true);
}

PyDbMLeader PyDbMLeader::cast(const PyRxObject& src)
{
    PyDbMLeader dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbMLeaderStyle, bases<PyDbObject>>("MLeaderStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getName", &PyDbMLeaderStyle::getName)
        .def("setName", &PyDbMLeaderStyle::setName)
        .def("isRenamable", &PyDbMLeaderStyle::isRenamable)
        .def("description", &PyDbMLeaderStyle::description)
        .def("setDescription", &PyDbMLeaderStyle::setDescription)
        .def("bitFlags", &PyDbMLeaderStyle::bitFlags)
        .def("setBitFlags", &PyDbMLeaderStyle::setBitFlags)
        .def("contentType", &PyDbMLeaderStyle::contentType)
        .def("setContentType", &PyDbMLeaderStyle::setContentType)
        .def("setDrawMLeaderOrderType", &PyDbMLeaderStyle::setDrawMLeaderOrderType)
        .def("drawMLeaderOrderType", &PyDbMLeaderStyle::drawMLeaderOrderType)
        .def("setDrawLeaderOrderType", &PyDbMLeaderStyle::setDrawLeaderOrderType)
        .def("drawLeaderOrderType", &PyDbMLeaderStyle::drawLeaderOrderType)
        .def("setDrawLeaderOrderType", &PyDbMLeaderStyle::setDrawLeaderOrderType)
        .def("drawLeaderOrderType", &PyDbMLeaderStyle::drawLeaderOrderType)
        .def("setMaxLeaderSegmentsPoints", &PyDbMLeaderStyle::setMaxLeaderSegmentsPoints)
        .def("maxLeaderSegmentsPoints", &PyDbMLeaderStyle::maxLeaderSegmentsPoints)
        .def("setFirstSegmentAngleConstraint", &PyDbMLeaderStyle::setFirstSegmentAngleConstraint)
        .def("firstSegmentAngleConstraint", &PyDbMLeaderStyle::firstSegmentAngleConstraint)
        .def("setSecondSegmentAngleConstraint", &PyDbMLeaderStyle::setSecondSegmentAngleConstraint)
        .def("secondSegmentAngleConstraint", &PyDbMLeaderStyle::secondSegmentAngleConstraint)
        .def("setLeaderLineType", &PyDbMLeaderStyle::setLeaderLineType)
        .def("leaderLineType", &PyDbMLeaderStyle::leaderLineType)
        .def("setLeaderLineColor", &PyDbMLeaderStyle::setLeaderLineColor)
        .def("leaderLineColor", &PyDbMLeaderStyle::leaderLineColor)
        .def("setLeaderLineTypeId", &PyDbMLeaderStyle::setLeaderLineTypeId)
        .def("leaderLineTypeId", &PyDbMLeaderStyle::leaderLineTypeId)
        .def("setLeaderLineWeight", &PyDbMLeaderStyle::setLeaderLineWeight)
        .def("leaderLineWeight", &PyDbMLeaderStyle::leaderLineWeight)
        .def("setEnableLanding", &PyDbMLeaderStyle::setEnableLanding)
        .def("enableLanding", &PyDbMLeaderStyle::enableLanding)
        .def("setLandingGap", &PyDbMLeaderStyle::setLandingGap)
        .def("landingGap", &PyDbMLeaderStyle::landingGap)
        .def("setEnableDogleg", &PyDbMLeaderStyle::setEnableDogleg)
        .def("enableDogleg", &PyDbMLeaderStyle::enableDogleg)
        .def("setDoglegLength", &PyDbMLeaderStyle::setDoglegLength)
        .def("doglegLength", &PyDbMLeaderStyle::doglegLength)
        .def("setArrowSymbolId", &PyDbMLeaderStyle::setArrowSymbolId1)
        .def("setArrowSymbolId", &PyDbMLeaderStyle::setArrowSymbolId2)
        .def("arrowSymbolId", &PyDbMLeaderStyle::arrowSymbolId)
        .def("setArrowSize", &PyDbMLeaderStyle::setArrowSize)
        .def("arrowSize", &PyDbMLeaderStyle::arrowSize)
        .def("setDefaultMText", &PyDbMLeaderStyle::setDefaultMText)
        .def("defaultMText", &PyDbMLeaderStyle::defaultMText)
        .def("setTextStyleId", &PyDbMLeaderStyle::setTextStyleId)
        .def("textStyleId", &PyDbMLeaderStyle::textStyleId)
        .def("setTextAttachmentType", &PyDbMLeaderStyle::setTextAttachmentType1)
        .def("textAttachmentType", &PyDbMLeaderStyle::textAttachmentType1)
        .def("setTextAttachmentType", &PyDbMLeaderStyle::setTextAttachmentType2)
        .def("textAttachmentType", &PyDbMLeaderStyle::textAttachmentType2)
        .def("setTextAngleType", &PyDbMLeaderStyle::setTextAngleType)
        .def("textAngleType", &PyDbMLeaderStyle::textAngleType)
        .def("setTextAlignmentType", &PyDbMLeaderStyle::setTextAlignmentType)
        .def("textAlignmentType", &PyDbMLeaderStyle::textAlignmentType)
        .def("setTextAlignAlwaysLeft", &PyDbMLeaderStyle::setTextAlignAlwaysLeft)
        .def("textAlignAlwaysLeft", &PyDbMLeaderStyle::textAlignAlwaysLeft)
        .def("setTextColor", &PyDbMLeaderStyle::setTextColor)
        .def("textColor", &PyDbMLeaderStyle::textColor)
        .def("setTextHeight", &PyDbMLeaderStyle::setTextHeight)
        .def("textHeight", &PyDbMLeaderStyle::textHeight)
        .def("setEnableFrameText", &PyDbMLeaderStyle::setEnableFrameText)
        .def("enableFrameText", &PyDbMLeaderStyle::enableFrameText)
        .def("setAlignSpace", &PyDbMLeaderStyle::setAlignSpace)
        .def("alignSpace", &PyDbMLeaderStyle::alignSpace)
        .def("setBlockId", &PyDbMLeaderStyle::setBlockId1)
        .def("setBlockId", &PyDbMLeaderStyle::setBlockId2)
        .def("blockId", &PyDbMLeaderStyle::blockId)
        .def("setBlockColor", &PyDbMLeaderStyle::setBlockColor)
        .def("blockColor", &PyDbMLeaderStyle::blockColor)
        .def("setBlockScale", &PyDbMLeaderStyle::setBlockScale)
        .def("blockScale", &PyDbMLeaderStyle::blockScale)
        .def("setEnableBlockScale", &PyDbMLeaderStyle::setEnableBlockScale)
        .def("enableBlockScale", &PyDbMLeaderStyle::enableBlockScale)
        .def("setBlockRotation", &PyDbMLeaderStyle::setBlockRotation)
        .def("blockRotation", &PyDbMLeaderStyle::blockRotation)
        .def("setEnableBlockRotation", &PyDbMLeaderStyle::setEnableBlockRotation)
        .def("enableBlockRotation", &PyDbMLeaderStyle::enableBlockRotation)
        .def("setBlockConnectionType", &PyDbMLeaderStyle::setBlockConnectionType)
        .def("blockConnectionType", &PyDbMLeaderStyle::blockConnectionType)
        .def("setScale", &PyDbMLeaderStyle::setScale)
        .def("scale", &PyDbMLeaderStyle::scale)
        .def("overwritePropChanged", &PyDbMLeaderStyle::overwritePropChanged)
        .def("postMLeaderStyleToDb", &PyDbMLeaderStyle::postMLeaderStyleToDb)
        .def("setAnnotative", &PyDbMLeaderStyle::setAnnotative)
        .def("annotative", &PyDbMLeaderStyle::annotative)
        .def("setBreakSize", &PyDbMLeaderStyle::setBreakSize)
        .def("breakSize", &PyDbMLeaderStyle::breakSize)
        .def("setTextAttachmentDirection", &PyDbMLeaderStyle::setTextAttachmentDirection)
        .def("textAttachmentDirection", &PyDbMLeaderStyle::textAttachmentDirection)
        .def("setExtendLeaderToText", &PyDbMLeaderStyle::setExtendLeaderToText)
        .def("extendLeaderToText", &PyDbMLeaderStyle::extendLeaderToText)
        .def("className", &PyDbMLeaderStyle::className).staticmethod("className")
        .def("desc", &PyDbMLeaderStyle::desc).staticmethod("desc")
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

PyDbMLeaderStyle::PyDbMLeaderStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbMLeaderStyle>(id, mode), false)
{
}

std::string PyDbMLeaderStyle::getName() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    RxAutoOutStr name;
    PyThrowBadEs(impObj()->getName(name.buf));
    return wstr_to_utf8(name.buf);
#else
    AcString name;
    PyThrowBadEs(impObj()->getName(name));
    return wstr_to_utf8(name);
#endif
}

void PyDbMLeaderStyle::setName(const std::string& pszName)
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

void PyDbMLeaderStyle::setDescription(const std::string& pszDescription)
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(pszDescription).c_str()));
}

Adesk::UInt32 PyDbMLeaderStyle::bitFlags() const
{
    return impObj()->bitFlags();
}

void PyDbMLeaderStyle::setBitFlags(Adesk::UInt32 flags)
{
    return PyThrowBadEs(impObj()->setBitFlags(flags));
}

AcDbMLeaderStyle::ContentType PyDbMLeaderStyle::contentType() const
{
    return impObj()->contentType();
}

void PyDbMLeaderStyle::setContentType(AcDbMLeaderStyle::ContentType contentType)
{
    return PyThrowBadEs(impObj()->setContentType(contentType));
}

void PyDbMLeaderStyle::setDrawMLeaderOrderType(AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType)
{
    return PyThrowBadEs(impObj()->setDrawMLeaderOrderType(drawMLeaderOrderType));
}

AcDbMLeaderStyle::DrawMLeaderOrderType PyDbMLeaderStyle::drawMLeaderOrderType() const
{
    return impObj()->drawMLeaderOrderType();
}

void PyDbMLeaderStyle::setDrawLeaderOrderType(AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType)
{
    return PyThrowBadEs(impObj()->setDrawLeaderOrderType(drawLeaderOrderType));
}

AcDbMLeaderStyle::DrawLeaderOrderType PyDbMLeaderStyle::drawLeaderOrderType() const
{
    return impObj()->drawLeaderOrderType();
}

void PyDbMLeaderStyle::setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints)
{
    return PyThrowBadEs(impObj()->setMaxLeaderSegmentsPoints(maxLeaderSegmentsPoints));
}

int PyDbMLeaderStyle::maxLeaderSegmentsPoints() const
{
    return impObj()->maxLeaderSegmentsPoints();
}

void PyDbMLeaderStyle::setFirstSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle)
{
    return PyThrowBadEs(impObj()->setFirstSegmentAngleConstraint(angle));
}

AcDbMLeaderStyle::SegmentAngleType PyDbMLeaderStyle::firstSegmentAngleConstraint() const
{
    return impObj()->firstSegmentAngleConstraint();
}

void PyDbMLeaderStyle::setSecondSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle)
{
    return PyThrowBadEs(impObj()->setSecondSegmentAngleConstraint(angle));
}

AcDbMLeaderStyle::SegmentAngleType PyDbMLeaderStyle::secondSegmentAngleConstraint() const
{
    return impObj()->secondSegmentAngleConstraint();
}

void PyDbMLeaderStyle::setLeaderLineType(AcDbMLeaderStyle::LeaderType leaderLineType)
{
    return PyThrowBadEs(impObj()->setLeaderLineType(leaderLineType));
}

AcDbMLeaderStyle::LeaderType PyDbMLeaderStyle::leaderLineType() const
{
    return impObj()->leaderLineType();
}

void PyDbMLeaderStyle::setLeaderLineColor(const AcCmColor& leaderLineColor)
{
    return PyThrowBadEs(impObj()->setLeaderLineColor(leaderLineColor));
}

AcCmColor PyDbMLeaderStyle::leaderLineColor() const
{
    return impObj()->leaderLineColor();
}

void PyDbMLeaderStyle::setLeaderLineTypeId(const PyDbObjectId& leaderLineTypeId)
{
    return PyThrowBadEs(impObj()->setLeaderLineTypeId(leaderLineTypeId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::leaderLineTypeId() const
{
    return impObj()->leaderLineTypeId();
}

void PyDbMLeaderStyle::setLeaderLineWeight(AcDb::LineWeight leaderLineWeight)
{
    return PyThrowBadEs(impObj()->setLeaderLineWeight(leaderLineWeight));
}

AcDb::LineWeight PyDbMLeaderStyle::leaderLineWeight() const
{
    return impObj()->leaderLineWeight();
}

void PyDbMLeaderStyle::setEnableLanding(bool enableLanding)
{
    return PyThrowBadEs(impObj()->setEnableLanding(enableLanding));
}

bool PyDbMLeaderStyle::enableLanding() const
{
    return impObj()->enableLanding();
}

void PyDbMLeaderStyle::setLandingGap(double landingGap)
{
    return PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

double PyDbMLeaderStyle::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbMLeaderStyle::setEnableDogleg(bool enableDogleg)
{
    return PyThrowBadEs(impObj()->setEnableDogleg(enableDogleg));
}

bool PyDbMLeaderStyle::enableDogleg() const
{
    return impObj()->enableDogleg();
}

void PyDbMLeaderStyle::setDoglegLength(double doglegLength)
{
    return PyThrowBadEs(impObj()->setEnableDogleg(doglegLength));
}

double PyDbMLeaderStyle::doglegLength() const
{
    return impObj()->doglegLength();
}

void PyDbMLeaderStyle::setArrowSymbolId1(const std::string& name)
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(utf8_to_wstr(name).c_str()));
}

void PyDbMLeaderStyle::setArrowSymbolId2(const PyDbObjectId& arrowSymbolId)
{
    return PyThrowBadEs(impObj()->setArrowSymbolId(arrowSymbolId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::arrowSymbolId() const
{
    return PyDbObjectId(impObj()->arrowSymbolId());
}

void PyDbMLeaderStyle::setArrowSize(double arrowSize)
{
    return PyThrowBadEs(impObj()->setArrowSize(arrowSize));
}

double PyDbMLeaderStyle::arrowSize() const
{
    return impObj()->arrowSize();
}

void PyDbMLeaderStyle::setDefaultMText(const PyDbMText& defaultMText)
{
    return PyThrowBadEs(impObj()->setDefaultMText(defaultMText.impObj()));
}

PyDbMText PyDbMLeaderStyle::defaultMText() const
{
    return PyDbMText(impObj()->defaultMText(), true);
}

void PyDbMLeaderStyle::setTextStyleId(const PyDbObjectId& textStyleId)
{
    return PyThrowBadEs(impObj()->setTextStyleId(textStyleId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::textStyleId() const
{
    return PyDbObjectId(impObj()->textStyleId());
}

void PyDbMLeaderStyle::setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection)
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType, leaderDirection));
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeaderStyle::textAttachmentType1(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const
{
    return impObj()->textAttachmentType(leaderDirection);
}

void PyDbMLeaderStyle::setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType)
{
    return PyThrowBadEs(impObj()->setTextAttachmentType(textAttachmentType));
}

AcDbMLeaderStyle::TextAttachmentType PyDbMLeaderStyle::textAttachmentType2() const
{
    return impObj()->textAttachmentType();
}

void PyDbMLeaderStyle::setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType)
{
    return PyThrowBadEs(impObj()->setTextAngleType(textAngleType));
}

AcDbMLeaderStyle::TextAngleType PyDbMLeaderStyle::textAngleType() const
{
    return impObj()->textAngleType();
}

void PyDbMLeaderStyle::setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType)
{
    return PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
}

AcDbMLeaderStyle::TextAlignmentType PyDbMLeaderStyle::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

void PyDbMLeaderStyle::setTextAlignAlwaysLeft(bool bAlwaysLeft)
{
    return PyThrowBadEs(impObj()->setTextAlignAlwaysLeft(bAlwaysLeft));
}

bool PyDbMLeaderStyle::textAlignAlwaysLeft() const
{
    return impObj()->textAlignAlwaysLeft();
}

void PyDbMLeaderStyle::setTextColor(const AcCmColor& textColor)
{
    return PyThrowBadEs(impObj()->setTextColor(textColor));
}

AcCmColor PyDbMLeaderStyle::textColor() const
{
    return impObj()->textColor();
}

void PyDbMLeaderStyle::setTextHeight(double textHeight)
{
    return PyThrowBadEs(impObj()->setTextHeight(textHeight));
}

double PyDbMLeaderStyle::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMLeaderStyle::setEnableFrameText(bool enableFrameText)
{
    return PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

bool PyDbMLeaderStyle::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbMLeaderStyle::setAlignSpace(double alignSpace)
{
    return PyThrowBadEs(impObj()->setAlignSpace(alignSpace));
}

double PyDbMLeaderStyle::alignSpace() const
{
    return impObj()->alignSpace();
}

void PyDbMLeaderStyle::setBlockId1(const std::string& name)
{
    return PyThrowBadEs(impObj()->setBlockId(utf8_to_wstr(name).c_str()));
}

void PyDbMLeaderStyle::setBlockId2(const PyDbObjectId& blockId)
{
    return PyThrowBadEs(impObj()->setBlockId(blockId.m_id));
}

PyDbObjectId PyDbMLeaderStyle::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

void PyDbMLeaderStyle::setBlockColor(const AcCmColor& blockColor)
{
    return PyThrowBadEs(impObj()->setBlockColor(blockColor));
}

AcCmColor PyDbMLeaderStyle::blockColor() const
{
    return impObj()->blockColor();
}

void PyDbMLeaderStyle::setBlockScale(const AcGeScale3d& scale)
{
    return PyThrowBadEs(impObj()->setBlockScale(scale));
}

AcGeScale3d PyDbMLeaderStyle::blockScale() const
{
    return impObj()->blockScale();
}

void PyDbMLeaderStyle::setEnableBlockScale(bool enableBlockScale)
{
    return PyThrowBadEs(impObj()->setEnableBlockScale(enableBlockScale));
}

bool PyDbMLeaderStyle::enableBlockScale() const
{
    return impObj()->enableBlockScale();
}

void PyDbMLeaderStyle::setBlockRotation(double rotation)
{
    return PyThrowBadEs(impObj()->setBlockRotation(rotation));
}

double PyDbMLeaderStyle::blockRotation() const
{
    return impObj()->blockRotation();
}

void PyDbMLeaderStyle::setEnableBlockRotation(bool enableBlockRotation)
{
    return PyThrowBadEs(impObj()->setEnableBlockRotation(enableBlockRotation));
}

bool PyDbMLeaderStyle::enableBlockRotation() const
{
    return impObj()->enableBlockRotation();
}

void PyDbMLeaderStyle::setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType)
{
    return PyThrowBadEs(impObj()->setBlockConnectionType(blockConnectionType));
}

AcDbMLeaderStyle::BlockConnectionType PyDbMLeaderStyle::blockConnectionType() const
{
    return impObj()->blockConnectionType();
}

void PyDbMLeaderStyle::setScale(double scale)
{
    return PyThrowBadEs(impObj()->setScale(scale));
}

double PyDbMLeaderStyle::scale() const
{
    return impObj()->scale();
}

bool PyDbMLeaderStyle::overwritePropChanged() const
{
    return impObj()->overwritePropChanged();
}

PyDbObjectId PyDbMLeaderStyle::postMLeaderStyleToDb(PyDbDatabase& pDb, const std::string& styleName)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->postMLeaderStyleToDb(pDb.impObj(), utf8_to_wstr(styleName).c_str(), id));
    return PyDbObjectId(id);
}

void PyDbMLeaderStyle::setAnnotative(bool isAnnotative)
{
    return PyThrowBadEs(impObj()->setAnnotative(isAnnotative));
}

bool PyDbMLeaderStyle::annotative() const
{
    return impObj()->annotative();
}

void PyDbMLeaderStyle::setBreakSize(double size)
{
    return PyThrowBadEs(impObj()->setBreakSize(size));
}

double PyDbMLeaderStyle::breakSize() const
{
    return impObj()->breakSize();
}

void PyDbMLeaderStyle::setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection)
{
    return PyThrowBadEs(impObj()->setTextAttachmentDirection(textAttachmentDirection));
}

AcDbMLeaderStyle::TextAttachmentDirection PyDbMLeaderStyle::textAttachmentDirection() const
{
    return impObj()->textAttachmentDirection();
}

void PyDbMLeaderStyle::setExtendLeaderToText(bool value)
{
    return PyThrowBadEs(impObj()->setExtendLeaderToText(value));
}

bool PyDbMLeaderStyle::extendLeaderToText() const
{
    return impObj()->extendLeaderToText();
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
