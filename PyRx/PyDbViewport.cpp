#include "stdafx.h"
#include "PyDbViewport.h"
#include "PyDbObjectId.h"


void makePyDbViewportWrapper()
{

}

PyDbViewport::PyDbViewport()
  : PyDbViewport(new AcDbViewport(), true)
{
}

PyDbViewport::PyDbViewport(AcDbViewport* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbViewport::PyDbViewport(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbViewport* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbViewport>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Acad::ErrorStatus PyDbViewport::setModelView(const PyDbXrefObjectId& xrefObjId)
{
    return impObj()->setModelView(xrefObjId.m_imp);
}

PyDbXrefObjectId PyDbViewport::getModelView() const
{
    PyDbXrefObjectId id;
    if (auto es = impObj()->getModelView(id.m_imp); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

Acad::ErrorStatus PyDbViewport::removeModelView(void)
{
    return impObj()->removeModelView();
}

Acad::ErrorStatus PyDbViewport::setSheetView(PyDbObjectId objId)
{
    return impObj()->setSheetView(objId.m_id);
}

PyDbObjectId PyDbViewport::getSheetView() const
{
    PyDbObjectId id;
    if (auto es = impObj()->getSheetView(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

Acad::ErrorStatus PyDbViewport::removeSheetView(void)
{
    return impObj()->removeSheetView();
}

Acad::ErrorStatus PyDbViewport::setLabelBlock(PyDbObjectId& objId)
{
    return impObj()->setLabelBlock(objId.m_id);
}

PyDbObjectId PyDbViewport::getLabelBlock() const
{
    PyDbObjectId id;
    if (auto es = impObj()->getLabelBlock(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

Acad::ErrorStatus PyDbViewport::removeLabelBlock(void)
{
    return impObj()->removeLabelBlock();
}

Acad::ErrorStatus PyDbViewport::syncModelView(void)
{
    return impObj()->syncModelView();
}

double PyDbViewport::height() const
{
    return impObj()->height();
}

Acad::ErrorStatus PyDbViewport::setHeight(double val)
{
    return impObj()->setHeight(val);
}

double PyDbViewport::width() const
{
    return impObj()->width();
}

Acad::ErrorStatus PyDbViewport::setWidth(double val)
{
    return impObj()->setWidth(val);
}

AcGePoint3d PyDbViewport::centerPoint() const
{
    return impObj()->centerPoint();
}

Acad::ErrorStatus PyDbViewport::setCenterPoint(const AcGePoint3d& val)
{
    return impObj()->setCenterPoint(val);
}

Adesk::Int16 PyDbViewport::number() const
{
    return impObj()->number();
}

bool PyDbViewport::isOn() const
{
    return impObj()->isOn();
}

Acad::ErrorStatus PyDbViewport::setOn()
{
    return impObj()->setOn();
}

Acad::ErrorStatus PyDbViewport::setOff()
{
    return impObj()->setOff();
}

Acad::ErrorStatus PyDbViewport::setIsOn(bool bOn)
{
    return impObj()->setIsOn(bOn);
}

AcGePoint3d PyDbViewport::viewTarget() const
{
    return impObj()->viewTarget();
}

Acad::ErrorStatus PyDbViewport::setViewTarget(const AcGePoint3d& val)
{
    return impObj()->setViewTarget(val);
}

AcGeVector3d PyDbViewport::viewDirection() const
{
    return impObj()->viewDirection();
}

Acad::ErrorStatus PyDbViewport::setViewDirection(const AcGeVector3d& val)
{
    return impObj()->setViewDirection(val);
}

double PyDbViewport::viewHeight() const
{
    return impObj()->viewHeight();
}

Acad::ErrorStatus PyDbViewport::setViewHeight(double ht)
{
    return impObj()->setViewHeight(ht);
}

AcGePoint2d PyDbViewport::viewCenter() const
{
    return impObj()->viewCenter();
}

Acad::ErrorStatus PyDbViewport::setViewCenter(const AcGePoint2d& pt)
{
    return impObj()->setViewCenter(pt);
}

double PyDbViewport::twistAngle() const
{
    return impObj()->twistAngle();
}

Acad::ErrorStatus PyDbViewport::setTwistAngle(double val)
{
    return impObj()->setTwistAngle(val);
}

double PyDbViewport::lensLength() const
{
    return impObj()->lensLength();
}

Acad::ErrorStatus PyDbViewport::setLensLength(double val)
{
    return impObj()->setLensLength(val);
}

bool PyDbViewport::isFrontClipOn() const
{
    return impObj()->isFrontClipOn();
}

Acad::ErrorStatus PyDbViewport::setFrontClipOn1()
{
    return impObj()->setFrontClipOn();
}

Acad::ErrorStatus PyDbViewport::setFrontClipOn2(bool bOn)
{
    return impObj()->setFrontClipOn(bOn);
}

bool PyDbViewport::isBackClipOn() const
{
    return impObj()->isBackClipOn();
}

Acad::ErrorStatus PyDbViewport::setFrontClipOff()
{
    return impObj()->setFrontClipOff();
}

Acad::ErrorStatus PyDbViewport::setBackClipOn1()
{
    return impObj()->setBackClipOn();
}

Acad::ErrorStatus PyDbViewport::setBackClipOn2(bool bOn)
{
    return impObj()->setBackClipOn(bOn);
}

bool PyDbViewport::isFrontClipAtEyeOn() const
{
    return impObj()->isFrontClipAtEyeOn();
}

Acad::ErrorStatus PyDbViewport::setFrontClipAtEyeOn1()
{
    return impObj()->setFrontClipAtEyeOn();
}

Acad::ErrorStatus PyDbViewport::setFrontClipAtEyeOff()
{
    return impObj()->setFrontClipAtEyeOff();
}

Acad::ErrorStatus PyDbViewport::setFrontClipAtEyeOn2(bool bOn)
{
    return impObj()->setFrontClipAtEyeOn(bOn);
}

double PyDbViewport::frontClipDistance() const
{
    return impObj()->frontClipDistance();
}

Acad::ErrorStatus PyDbViewport::setFrontClipDistance(double newVal)
{
    return impObj()->setFrontClipDistance(newVal);
}

double PyDbViewport::backClipDistance() const
{
    return impObj()->backClipDistance();
}

Acad::ErrorStatus PyDbViewport::setBackClipDistance(double newVal)
{
    return impObj()->setBackClipDistance(newVal);
}

bool PyDbViewport::isPerspectiveOn() const
{
    return impObj()->isPerspectiveOn();
}

Acad::ErrorStatus PyDbViewport::setPerspectiveOn1()
{
    return impObj()->setPerspectiveOn();
}

Acad::ErrorStatus PyDbViewport::setPerspectiveOff()
{
    return impObj()->setPerspectiveOff();
}

Acad::ErrorStatus PyDbViewport::setPerspectiveOn2(bool bOn)
{
    return impObj()->setPerspectiveOn(bOn);
}

bool PyDbViewport::isUcsFollowModeOn() const
{
    return impObj()->isUcsFollowModeOn();
}

Acad::ErrorStatus PyDbViewport::setUcsFollowModeOn1()
{
    return impObj()->setUcsFollowModeOn();
}

Acad::ErrorStatus PyDbViewport::setUcsFollowModeOff()
{
    return impObj()->setUcsFollowModeOff();
}

Acad::ErrorStatus PyDbViewport::setUcsFollowModeOn2(bool bOn)
{
    return impObj()->setUcsFollowModeOn(bOn);
}

bool PyDbViewport::isUcsIconVisible() const
{
    return impObj()->isUcsIconVisible();
}

Acad::ErrorStatus PyDbViewport::setUcsIconVisible1()
{
    return impObj()->setUcsIconVisible();
}

Acad::ErrorStatus PyDbViewport::setUcsIconInvisible()
{
    return impObj()->setUcsIconInvisible();
}

Acad::ErrorStatus PyDbViewport::setUcsIconVisible2(bool bOn)
{
    return impObj()->setUcsIconVisible(bOn);
}

bool PyDbViewport::isUcsIconAtOrigin() const
{
    return impObj()->isUcsIconAtOrigin();
}

Acad::ErrorStatus PyDbViewport::setUcsIconAtOrigin1()
{
    return impObj()->setUcsIconAtOrigin();
}

Acad::ErrorStatus PyDbViewport::setUcsIconAtCorner()
{
    return impObj()->setUcsIconAtCorner();
}

Acad::ErrorStatus PyDbViewport::setUcsIconAtOrigin2(bool bOn)
{
    return impObj()->setUcsIconAtOrigin(bOn);
}

bool PyDbViewport::isFastZoomOn() const
{
    return impObj()->isFastZoomOn();
}

Acad::ErrorStatus PyDbViewport::setBackClipOff()
{
    return impObj()->setBackClipOff();
}

Acad::ErrorStatus PyDbViewport::setFastZoomOn1()
{
    return impObj()->setFastZoomOn();
}

Acad::ErrorStatus PyDbViewport::setFastZoomOff()
{
    return impObj()->setFastZoomOff();
}

Acad::ErrorStatus PyDbViewport::setFastZoomOn2(bool bOn)
{
    return impObj()->setFastZoomOn(bOn);
}

Adesk::UInt16 PyDbViewport::circleSides() const
{
    return impObj()->circleSides();
}

Acad::ErrorStatus PyDbViewport::setCircleSides(Adesk::UInt16 val)
{
    return impObj()->setCircleSides(val);
}

bool PyDbViewport::isSnapOn() const
{
    return impObj()->isSnapOn();
}

Acad::ErrorStatus PyDbViewport::setSnapOn1()
{
    return impObj()->setSnapOn();
}

Acad::ErrorStatus PyDbViewport::setSnapOff()
{
    return impObj()->setSnapOff();
}

Acad::ErrorStatus PyDbViewport::setSnapOn2(bool bOn)
{
    return impObj()->setSnapOn(bOn);
}

std::string PyDbViewport::className()
{
    return "AcDbViewport";
}

PyRxClass PyDbViewport::desc()
{
    return PyRxClass(AcDbViewport::desc(), false);
}

PyDbViewport PyDbViewport::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewport::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewport(static_cast<AcDbViewport*>(src.impObj()->clone()), true);
}

PyDbViewport PyDbViewport::cast(const PyRxObject& src)
{
    PyDbViewport dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewport* PyDbViewport::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbViewport*>(m_pyImp.get());
}
