#include "stdafx.h"


#ifdef BRXAPP
#if !defined(_BRXTARGET240)

#include "PyBrxCvDbLabel.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStylePartDisplaySettings
void makeBrxCvDbStylePartDisplaySettingsWrapper()
{
    PyDocString DS("CvDbStylePartDisplaySettings");
    class_<PyBrxCvDbStylePartDisplaySettings, bases<PyBrxCvDbSubObject>>("CvDbStylePartDisplaySettings", boost::python::no_init)
        .def("displaySetting", &PyBrxCvDbStylePartDisplaySettings::isVisible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbStylePartDisplaySettings::setVisible, DS.ARGS({ "val: bool" }))
        .def("color", &PyBrxCvDbStylePartDisplaySettings::color, DS.ARGS())
        .def("setColor", &PyBrxCvDbStylePartDisplaySettings::setColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("layer", &PyBrxCvDbStylePartDisplaySettings::layer, DS.ARGS())
        .def("setLayer", &PyBrxCvDbStylePartDisplaySettings::setLayer, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineType", &PyBrxCvDbStylePartDisplaySettings::lineType, DS.ARGS())
        .def("setLineType", &PyBrxCvDbStylePartDisplaySettings::setLineType, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineTypeScale", &PyBrxCvDbStylePartDisplaySettings::lineTypeScale, DS.ARGS())
        .def("setLineTypeScale", &PyBrxCvDbStylePartDisplaySettings::setLineTypeScale, DS.ARGS({ "val: float" }))
        .def("lineWeight", &PyBrxCvDbStylePartDisplaySettings::lineWeight, DS.ARGS())
        .def("setLineWeight", &PyBrxCvDbStylePartDisplaySettings::setLineWeight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("plotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameType, DS.ARGS())
        .def("setPlotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType, DS.ARGS({ "val: PyDb.PlotStyleNameType" }))
        .def("plotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameId, DS.ARGS())
        .def("setPlotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId, DS.ARGS({ "id: PyDb.ObjectId" }))
        ;
}

PyBrxCvDbStylePartDisplaySettings::PyBrxCvDbStylePartDisplaySettings(BrxCvDbStylePartDisplaySettings* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
}

bool PyBrxCvDbStylePartDisplaySettings::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbStylePartDisplaySettings::setVisible(bool value)
{
    PyThrowBadEs(impObj()->setVisible(value));
}

AcCmColor PyBrxCvDbStylePartDisplaySettings::color() const
{
    return impObj()->color();
}

void PyBrxCvDbStylePartDisplaySettings::setColor(const AcCmColor& value)
{
    PyThrowBadEs(impObj()->setColor(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::layer() const
{
    return PyDbObjectId{ impObj()->layer() };
}

void PyBrxCvDbStylePartDisplaySettings::setLayer(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setLayer(value.m_id));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::lineType() const
{
    return PyDbObjectId{ impObj()->lineType() };
}

void PyBrxCvDbStylePartDisplaySettings::setLineType(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setLineType(value.m_id));
}

double PyBrxCvDbStylePartDisplaySettings::lineTypeScale() const
{
    return impObj()->lineTypeScale();
}

void PyBrxCvDbStylePartDisplaySettings::setLineTypeScale(double value)
{
    PyThrowBadEs(impObj()->setLineTypeScale(value));
}

AcDb::LineWeight PyBrxCvDbStylePartDisplaySettings::lineWeight() const
{
    return impObj()->lineWeight();
}

void PyBrxCvDbStylePartDisplaySettings::setLineWeight(AcDb::LineWeight value)
{
    PyThrowBadEs(impObj()->setLineWeight(value));
}

AcDb::PlotStyleNameType PyBrxCvDbStylePartDisplaySettings::plotStyleNameType() const
{
    return impObj()->plotStyleNameType();
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType(AcDb::PlotStyleNameType value)
{
    PyThrowBadEs(impObj()->setPlotStyleNameType(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::plotStyleNameId() const
{
    return PyDbObjectId{ impObj()->plotStyleNameId() };
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setPlotStyleNameId(value.m_id));
}

BrxCvDbStylePartDisplaySettings* PyBrxCvDbStylePartDisplaySettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStylePartDisplaySettings*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper()
{
    PyDocString DS("CvDbStyle");
    class_<PyBrxCvDbStyle, bases<PyBrxCvDbObject>>("CvDbStyle", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("displaySetting", &PyBrxCvDbStyle::displaySetting, DS.ARGS())
        .def("displaySettings", &PyBrxCvDbStyle::displaySettings, DS.ARGS())
        .def("createdDate", &PyBrxCvDbStyle::createdDate, DS.ARGS())
        .def("createdBy", &PyBrxCvDbStyle::createdBy, DS.ARGS())
        .def("lastEditedDate", &PyBrxCvDbStyle::lastEditedDate, DS.ARGS())
        .def("lastEditedBy", &PyBrxCvDbStyle::lastEditedBy, DS.ARGS())
        .def("setCreatedBy", &PyBrxCvDbStyle::setCreatedBy, DS.ARGS({ "filter : str" }))

        .def("className", &PyBrxCvDbStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbStyle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode, erased), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete)
    : PyBrxCvDbObject(ptr, autoDelete)
{
}

PyBrxCvDbStylePartDisplaySettings PyBrxCvDbStyle::displaySetting(DisplayOrientation orientation, const std::string& partName) const
{
    auto ptr = impObj()->displaySetting(orientation, utf8_to_wstr(partName).c_str());
    if (ptr.refCount() == 1)
        return PyBrxCvDbStylePartDisplaySettings(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

boost::python::list PyBrxCvDbStyle::displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->displaySettings(orientation))
    {
        if (item.refCount() == 1)
            _pylist.append(PyBrxCvDbStylePartDisplaySettings(item.detach(), true));
        else
            throw PyErrorStatusException(Acad::eInvalidOpenState);
    }
    return _pylist;
}

PyDbDate PyBrxCvDbStyle::createdDate() const
{
    return PyDbDate(impObj()->createdDate());
}

const std::string PyBrxCvDbStyle::createdBy() const
{
    return wstr_to_utf8(impObj()->createdBy());
}

PyDbDate PyBrxCvDbStyle::lastEditedDate() const
{
    return PyDbDate();
}

const std::string PyBrxCvDbStyle::lastEditedBy() const
{
    return wstr_to_utf8(impObj()->lastEditedBy());
}

void PyBrxCvDbStyle::setCreatedBy(const std::string& value)
{
    PyThrowBadEs(impObj()->setCreatedBy(utf8_to_wstr(value).c_str()));
}

BrxCvDbStyle* PyBrxCvDbStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleComponentWrapper
void makeBrxCvDbLabelStyleComponentWrapper()
{
    PyDocString DS("CvDbLabelStyleComponent");
    class_<PyBrxCvDbLabelStyleComponent, bases<PyBrxCvDbSubObject>>("CvDbLabelStyleComponent", boost::python::no_init)
        .def("displaySetting", &PyBrxCvDbLabelStyleComponent::isVisible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbLabelStyleComponent::setVisible, DS.ARGS({ "val: bool" }))
        .def("color", &PyBrxCvDbLabelStyleComponent::color, DS.ARGS())
        .def("setColor", &PyBrxCvDbLabelStyleComponent::setColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("anchorIndex", &PyBrxCvDbLabelStyleComponent::anchorIndex, DS.ARGS())
        .def("setAnchorIndex", &PyBrxCvDbLabelStyleComponent::setAnchorIndex, DS.ARGS({ "val : int" }))
        .def("anchorPoint", &PyBrxCvDbLabelStyleComponent::anchorPoint, DS.ARGS())
        .def("setAnchorPoint", &PyBrxCvDbLabelStyleComponent::setAnchorPoint, DS.ARGS({ "val : PyBrxCv.LabelAnchor" }))
        ;
}

PyBrxCvDbLabelStyleComponent::PyBrxCvDbLabelStyleComponent(BrxCvDbLabelStyleComponent* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
}

bool PyBrxCvDbLabelStyleComponent::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbLabelStyleComponent::setVisible(bool isVisible)
{
    PyThrowBadEs(impObj()->setVisible(isVisible));
}

AcCmColor PyBrxCvDbLabelStyleComponent::color() const
{
    return impObj()->color();
}

void PyBrxCvDbLabelStyleComponent::setColor(const AcCmColor& value)
{
    PyThrowBadEs(impObj()->setColor(value));
}

Adesk::UInt32 PyBrxCvDbLabelStyleComponent::anchorIndex() const
{
    return impObj()->anchorIndex();
}

void PyBrxCvDbLabelStyleComponent::setAnchorIndex(Adesk::UInt32 index)
{
    PyThrowBadEs(impObj()->setAnchorIndex(index));
}

BrxCvDbLabelStyleComponent::LabelAnchor PyBrxCvDbLabelStyleComponent::anchorPoint() const
{
    return impObj()->anchorPoint();
}

void PyBrxCvDbLabelStyleComponent::setAnchorPoint(LabelAnchor anchor)
{
    PyThrowBadEs(impObj()->setAnchorPoint(anchor));
}

BrxCvDbLabelStyleComponent* PyBrxCvDbLabelStyleComponent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleComponent*>(m_pyImp.get());
}

void makeBrxCvDbLabelStyleArrowWrapper()
{
    {
        PyDocString DS("CvDbLabelStyleArrow");
        class_<PyBrxCvDbLabelStyleArrow, bases<BrxCvDbLabelStyleArrow>>("CvDbLabelStyleArrow", boost::python::no_init)
            .def("arrowHeadStyle", &PyBrxCvDbLabelStyleArrow::arrowHeadStyle, DS.ARGS())
            .def("setArrowHeadStyle", &PyBrxCvDbLabelStyleArrow::setArrowHeadStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
            .def("arrowHeadSize", &PyBrxCvDbLabelStyleArrow::arrowHeadSize, DS.ARGS())
            .def("setArrowHeadSize", &PyBrxCvDbLabelStyleArrow::setArrowHeadSize, DS.ARGS({ "val: float" }))
            .def("setArrowHeadSizeExprIndex", &PyBrxCvDbLabelStyleArrow::setArrowHeadSizeExprIndex, DS.ARGS({ "val: int" }))
            .def("angle", &PyBrxCvDbLabelStyleArrow::angle, DS.ARGS())
            .def("setAngle", &PyBrxCvDbLabelStyleArrow::setAngle, DS.ARGS({ "val: float" }))
            .def("angleExprIndex", &PyBrxCvDbLabelStyleArrow::angleExprIndex, DS.ARGS())
            .def("setAngleExprIndex", &PyBrxCvDbLabelStyleArrow::setAngleExprIndex, DS.ARGS({ "val: int" }))
            .def("isFixedLength", &PyBrxCvDbLabelStyleArrow::isFixedLength, DS.ARGS())
            .def("setFixedLength", &PyBrxCvDbLabelStyleArrow::setFixedLength, DS.ARGS({ "val: bool" }))
            .def("length", &PyBrxCvDbLabelStyleArrow::length, DS.ARGS())
            .def("setLength", &PyBrxCvDbLabelStyleArrow::setLength, DS.ARGS({ "val: float" }))
            .def("lengthExprIndex", &PyBrxCvDbLabelStyleArrow::lengthExprIndex, DS.ARGS())
            .def("setLengthExprIndex", &PyBrxCvDbLabelStyleArrow::setLengthExprIndex, DS.ARGS({ "val: int" }))
            .def("offset", &PyBrxCvDbLabelStyleArrow::offset, DS.ARGS())
            .def("setOffset", &PyBrxCvDbLabelStyleArrow::setOffset, DS.ARGS({ "val: AcGeVector2d" }))
            .def("linetype", &PyBrxCvDbLabelStyleArrow::linetype, DS.ARGS())
            .def("setLinetype", &PyBrxCvDbLabelStyleArrow::setLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
            .def("lineweight", &PyBrxCvDbLabelStyleArrow::lineweight, DS.ARGS())
            .def("setLineweight", &PyBrxCvDbLabelStyleArrow::setLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))
            ;
    }
}

PyBrxCvDbLabelStyleArrow::PyBrxCvDbLabelStyleArrow(BrxCvDbLabelStyleArrow* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbLabelStyleArrow::arrowHeadStyle() const
{
    return PyDbObjectId{ impObj()->arrowHeadStyle() };
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadStyle(const PyDbObjectId& objId)
{
    PyThrowBadEs(impObj()->setArrowHeadStyle(objId.m_id));
}

double PyBrxCvDbLabelStyleArrow::arrowHeadSize() const
{
    return impObj()->arrowHeadSize();
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadSize(double size)
{
    //SSC
    PyThrowBadEs(impObj()->setArrowHeadSize(size));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::arrowHeadSizeExprIndex() const
{
    return impObj()->arrowHeadSizeExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadSizeExprIndex(Adesk::UInt32 index)
{
    PyThrowBadEs(impObj()->setArrowHeadSizeExprIndex(index));
}

double PyBrxCvDbLabelStyleArrow::angle() const
{
    return impObj()->angle();
}

void PyBrxCvDbLabelStyleArrow::setAngle(double radAngle)
{
    PyThrowBadEs(impObj()->setAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::angleExprIndex() const
{
    return impObj()->angleExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setAngleExprIndex(Adesk::UInt32 index)
{
    PyThrowBadEs(impObj()->setAngleExprIndex(index));
}

bool PyBrxCvDbLabelStyleArrow::isFixedLength() const
{
    return impObj()->isFixedLength();
}

void PyBrxCvDbLabelStyleArrow::setFixedLength(bool isFixedLength)
{
    PyThrowBadEs(impObj()->setFixedLength(isFixedLength));
}

double PyBrxCvDbLabelStyleArrow::length() const
{
    return impObj()->length();
}

void PyBrxCvDbLabelStyleArrow::setLength(double length)
{
    PyThrowBadEs(impObj()->setLength(length));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::lengthExprIndex() const
{
    return impObj()->lengthExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setLengthExprIndex(Adesk::UInt32 index)
{
    PyThrowBadEs(impObj()->setLengthExprIndex(index));
}

AcGeVector2d PyBrxCvDbLabelStyleArrow::offset() const
{
    return impObj()->offset();
}

void PyBrxCvDbLabelStyleArrow::setOffset(const AcGeVector2d& offset)
{
    PyThrowBadEs(impObj()->setOffset(offset));
}

PyDbObjectId PyBrxCvDbLabelStyleArrow::linetype() const
{
    return impObj()->linetype();
}

void PyBrxCvDbLabelStyleArrow::setLinetype(const PyDbObjectId& objId)
{
    PyThrowBadEs(impObj()->setLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyleArrow::lineweight() const
{
    return impObj()->lineweight();
}

void PyBrxCvDbLabelStyleArrow::setLineweight(AcDb::LineWeight lineweight)
{
    PyThrowBadEs(impObj()->setLineweight(lineweight));
}

BrxCvDbLabelStyleArrow* PyBrxCvDbLabelStyleArrow::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleArrow*>(m_pyImp.get());
}

void makeBrxCvDbLabelStyleBlockWrapper()
{
    {
        PyDocString DS("CvDbLabelStyleBlock");
        class_<PyBrxCvDbLabelStyleBlock, bases<BrxCvDbLabelStyleBlock>>("CvDbLabelStyleBlock", boost::python::no_init)
            .def("blockId", &PyBrxCvDbLabelStyleBlock::blockId, DS.ARGS())
            .def("setBlockId", &PyBrxCvDbLabelStyleBlock::setBlockId, DS.ARGS({ "id: PyDb.ObjectId" }))
            .def("height", &PyBrxCvDbLabelStyleBlock::height, DS.ARGS())
            .def("setHeight", &PyBrxCvDbLabelStyleBlock::setHeight, DS.ARGS({ "val: float" }))
            .def("heightExprIndex", &PyBrxCvDbLabelStyleBlock::heightExprIndex, DS.ARGS())
            .def("setHeightExprIndex", &PyBrxCvDbLabelStyleBlock::setHeightExprIndex, DS.ARGS({ "val: int" }))
            .def("angle", &PyBrxCvDbLabelStyleBlock::angle, DS.ARGS())
            .def("setAngle", &PyBrxCvDbLabelStyleBlock::setAngle, DS.ARGS({ "val: float" }))
            .def("angleExprIndex", &PyBrxCvDbLabelStyleBlock::angleExprIndex, DS.ARGS())
            .def("setAngleExprIndex", &PyBrxCvDbLabelStyleBlock::setAngleExprIndex, DS.ARGS({ "val: int" }))
            .def("attachment", &PyBrxCvDbLabelStyleBlock::attachment, DS.ARGS()) //SSC
            .def("setAttachment", &PyBrxCvDbLabelStyleBlock::setAttachment, DS.ARGS()) //SSC
            .def("offset", &PyBrxCvDbLabelStyleBlock::offset, DS.ARGS())
            .def("setOffset", &PyBrxCvDbLabelStyleBlock::setOffset, DS.ARGS({ "val: AcGeVector2d" }))
            .def("linetype", &PyBrxCvDbLabelStyleBlock::linetype, DS.ARGS())
            .def("setLinetype", &PyBrxCvDbLabelStyleBlock::setLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
            .def("lineweight", &PyBrxCvDbLabelStyleBlock::lineweight, DS.ARGS())
            .def("setLineweight", &PyBrxCvDbLabelStyleBlock::setLineweight, DS.ARGS()) //SSC
            ;
    }
}

PyBrxCvDbLabelStyleBlock::PyBrxCvDbLabelStyleBlock(BrxCvDbLabelStyleBlock* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbLabelStyleBlock::blockId() const
{
    return impObj()->blockId();
}

void PyBrxCvDbLabelStyleBlock::setBlockId(const AcDbObjectId& objId)
{
    PyThrowBadEs(impObj()->setBlockId(objId));
}

double PyBrxCvDbLabelStyleBlock::height() const
{
    return impObj()->height();
}

void PyBrxCvDbLabelStyleBlock::setHeight(double height)
{
    PyThrowBadEs(impObj()->setHeight(height));
}

Adesk::UInt32 PyBrxCvDbLabelStyleBlock::heightExprIndex() const
{
    return impObj()->heightExprIndex();
}

void PyBrxCvDbLabelStyleBlock::setHeightExprIndex(Adesk::Int32 index)
{
    PyThrowBadEs(impObj()->setHeightExprIndex(index));
}

double PyBrxCvDbLabelStyleBlock::angle() const
{
    return impObj()->angle();
}

void PyBrxCvDbLabelStyleBlock::setAngle(double radAngle)
{
    PyThrowBadEs(impObj()->setAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleBlock::angleExprIndex() const
{
    return impObj()->angleExprIndex();
}

void PyBrxCvDbLabelStyleBlock::setAngleExprIndex(Adesk::Int32 index)
{
    PyThrowBadEs(impObj()->setAngleExprIndex(index));
}

BrxCvDbLabelStyleBlock::BlockAttachment PyBrxCvDbLabelStyleBlock::attachment() const
{
    return impObj()->attachment();
}

void PyBrxCvDbLabelStyleBlock::setAttachment(BrxCvDbLabelStyleBlock::BlockAttachment attachment)
{
    PyThrowBadEs(impObj()->setAttachment(attachment));
}

AcGeVector2d PyBrxCvDbLabelStyleBlock::offset() const
{
    return impObj()->offset();
}

void PyBrxCvDbLabelStyleBlock::setOffset(const AcGeVector2d& offset)
{
    PyThrowBadEs(impObj()->setOffset(offset));
}

PyDbObjectId PyBrxCvDbLabelStyleBlock::linetype() const
{
    return impObj()->linetype();
}

void PyBrxCvDbLabelStyleBlock::setLinetype(const AcDbObjectId& objId)
{
    PyThrowBadEs(impObj()->setLinetype(objId));
}

AcDb::LineWeight PyBrxCvDbLabelStyleBlock::lineweight() const
{
    return impObj()->lineweight();
}

void PyBrxCvDbLabelStyleBlock::setLineweight(AcDb::LineWeight lineweight)
{
    PyThrowBadEs(impObj()->setLineweight(lineweight));
}

BrxCvDbLabelStyleBlock* PyBrxCvDbLabelStyleBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleBlock*>(m_pyImp.get());
}


#endif

#endif//BRXAPP

