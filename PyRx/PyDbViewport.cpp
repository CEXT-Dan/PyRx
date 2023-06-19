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

bool PyDbViewport::isSnapIsometric() const
{
    return impObj()->isSnapIsometric();
}

Acad::ErrorStatus PyDbViewport::setSnapIsometric1()
{
    return impObj()->setSnapIsometric();
}

Acad::ErrorStatus PyDbViewport::setSnapStandard()
{
    return impObj()->setSnapStandard();
}

Acad::ErrorStatus PyDbViewport::setSnapIsometric2(bool bOn)
{
    return impObj()->setSnapIsometric(bOn);
}

double PyDbViewport::snapAngle() const
{
    return impObj()->snapAngle();
}

Acad::ErrorStatus PyDbViewport::setSnapAngle(double val)
{
    return impObj()->setSnapAngle(val);
}

AcGePoint2d PyDbViewport::snapBasePoint() const
{
    return impObj()->snapBasePoint();
}

Acad::ErrorStatus PyDbViewport::setSnapBasePoint(const AcGePoint2d& val)
{
    return impObj()->setSnapBasePoint(val);
}

AcGeVector2d PyDbViewport::snapIncrement() const
{
    return impObj()->snapIncrement();
}

Acad::ErrorStatus PyDbViewport::setSnapIncrement(const AcGeVector2d& val)
{
    return impObj()->setSnapIncrement(val);
}

Adesk::UInt16 PyDbViewport::snapIsoPair() const
{
    return impObj()->snapIsoPair();
}

Acad::ErrorStatus PyDbViewport::setSnapIsoPair(Adesk::UInt16 val)
{
    return impObj()->setSnapIsoPair(val);
}

bool PyDbViewport::isGridOn() const
{
    return impObj()->isGridOn();
}

Acad::ErrorStatus PyDbViewport::setGridOn1()
{
    return impObj()->setGridOn();
}

Acad::ErrorStatus PyDbViewport::setGridOff()
{
    return impObj()->setGridOff();
}

Acad::ErrorStatus PyDbViewport::setGridOn2(bool val)
{
    return impObj()->setGridOn(val);
}

bool PyDbViewport::isGridBoundToLimits() const
{
    return impObj()->isGridBoundToLimits();
}

Acad::ErrorStatus PyDbViewport::setGridBoundToLimits(bool bNewVal)
{
    return impObj()->setGridBoundToLimits(bNewVal);
}

bool PyDbViewport::isGridAdaptive() const
{
    return impObj()->isGridAdaptive();
}

Acad::ErrorStatus PyDbViewport::setGridAdaptive(bool bNewVal)
{
    return impObj()->setGridAdaptive(bNewVal);
}

bool PyDbViewport::isGridSubdivisionRestricted() const
{
    return impObj()->isGridSubdivisionRestricted();
}

Acad::ErrorStatus PyDbViewport::setGridSubdivisionRestricted(bool bNewVal)
{
    return impObj()->setGridSubdivisionRestricted(bNewVal);
}

bool PyDbViewport::isGridFollow() const
{
    return impObj()->isGridFollow();
}

Acad::ErrorStatus PyDbViewport::setGridFollow(bool bNewVal)
{
    return impObj()->setGridFollow(bNewVal);
}

Adesk::UInt16 PyDbViewport::gridMajor() const
{
    return impObj()->gridMajor();
}

Acad::ErrorStatus PyDbViewport::setGridMajor(Adesk::UInt16 val)
{
    return impObj()->setGridMajor(val);
}

AcGeVector2d PyDbViewport::gridIncrement() const
{
    return impObj()->gridIncrement();
}

Acad::ErrorStatus PyDbViewport::setGridIncrement(const AcGeVector2d& val)
{
    return impObj()->setGridIncrement(val);
}

bool PyDbViewport::hiddenLinesRemoved() const
{
    return impObj()->hiddenLinesRemoved();
}

Acad::ErrorStatus PyDbViewport::showHiddenLines()
{
    return impObj()->showHiddenLines();
}

Acad::ErrorStatus PyDbViewport::removeHiddenLines1()
{
    return impObj()->removeHiddenLines();
}

Acad::ErrorStatus PyDbViewport::removeHiddenLines2(bool val)
{
    return impObj()->removeHiddenLines(val);
}

Acad::ErrorStatus PyDbViewport::freezeLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids;
    auto vec = py_list_to_std_vector<PyDbObjectId>(pyids);
    for (auto& id : vec)
        ids.append(id.m_id);
    return impObj()->freezeLayersInViewport(ids);
}

Acad::ErrorStatus PyDbViewport::thawLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids;
    auto vec = py_list_to_std_vector<PyDbObjectId>(pyids);
    for (auto& id : vec)
        ids.append(id.m_id);
    return impObj()->thawLayersInViewport(ids);
}

Acad::ErrorStatus PyDbViewport::thawAllLayersInViewport()
{
    return impObj()->thawAllLayersInViewport();
}

bool PyDbViewport::isLayerFrozenInViewport(const PyDbObjectId& layerId) const
{
    return impObj()->isLayerFrozenInViewport(layerId.m_id);
}

boost::python::list PyDbViewport::getFrozenLayerList() const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list pyids;
    if (auto es = impObj()->getFrozenLayerList(ids); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto& id : ids)
        pyids.append(PyDbObjectId(id));
    return pyids;
}

Acad::ErrorStatus PyDbViewport::updateDisplay() const
{
    return impObj()->updateDisplay();
}

PyDbObjectId PyDbViewport::background() const
{
    return PyDbObjectId(impObj()->background());
}

Acad::ErrorStatus PyDbViewport::setBackground(PyDbObjectId& backgroundId)
{
    return impObj()->setBackground(backgroundId.m_id);
}

PyDbObjectId PyDbViewport::previousBackground1() const
{
    return PyDbObjectId(impObj()->previousBackground());
}

PyDbObjectId PyDbViewport::previousBackground2(AcGiDrawable::DrawableType type) const
{
    return PyDbObjectId(impObj()->previousBackground(type));
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground1(PyDbObjectId& backgroundId)
{
    return impObj()->setPreviousBackground(backgroundId.m_id);
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type)
{
    return impObj()->setPreviousBackground(backgroundId.m_id, type);
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground3(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool force)
{
    return impObj()->setPreviousBackground(backgroundId.m_id, type, force);
}

bool PyDbViewport::previousBackgroundForcedSwitch(void) const
{
    return impObj()->previousBackgroundForcedSwitch();
}

PyDbObjectId PyDbViewport::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

Acad::ErrorStatus PyDbViewport::setVisualStyle(const PyDbObjectId& oidVisualStyle)
{
    return impObj()->setVisualStyle(oidVisualStyle.m_id);
}

bool PyDbViewport::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

Acad::ErrorStatus PyDbViewport::setDefaultLightingOn(bool on)
{
    return impObj()->setDefaultLightingOn(on);
}

AcGiViewportTraits::DefaultLightingType PyDbViewport::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

Acad::ErrorStatus PyDbViewport::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ)
{
    return impObj()->setDefaultLightingType(typ);
}

double PyDbViewport::brightness() const
{
    return impObj()->brightness();
}

Acad::ErrorStatus PyDbViewport::setBrightness(double val)
{
    return impObj()->setBrightness(val);
}

double PyDbViewport::contrast() const
{
    return impObj()->contrast();
}

Acad::ErrorStatus PyDbViewport::setContrast(double val)
{
    return impObj()->setContrast(val);
}

AcCmColor PyDbViewport::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

Acad::ErrorStatus PyDbViewport::setAmbientLightColor(const AcCmColor& clr)
{
    return impObj()->setAmbientLightColor(clr);
}

PyDbObjectId PyDbViewport::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

Acad::ErrorStatus PyDbViewport::setSun1(PyDbObjectId& retId, PyDbObject& pSun)
{
    return impObj()->setSun(retId.m_id, pSun.impObj());
}

Acad::ErrorStatus PyDbViewport::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun)
{
    return impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun);
}

bool PyDbViewport::isLocked() const
{
    return impObj()->isLocked();
}

Acad::ErrorStatus PyDbViewport::setLocked1()
{
    return impObj()->setLocked();
}

Acad::ErrorStatus PyDbViewport::setUnlocked()
{
    return impObj()->setUnlocked();
}

Acad::ErrorStatus PyDbViewport::setLocked2(bool val)
{
    return impObj()->setLocked(val);
}

bool PyDbViewport::isTransparent() const
{
    return impObj()->isTransparent();
}

Acad::ErrorStatus PyDbViewport::setTransparent1()
{
    return impObj()->setTransparent();
}

Acad::ErrorStatus PyDbViewport::setOpaque()
{
    return impObj()->setOpaque();
}

Acad::ErrorStatus PyDbViewport::setTransparent2(bool val)
{
    return impObj()->setTransparent(val);
}

double PyDbViewport::customScale() const
{
    return impObj()->customScale();
}

Acad::ErrorStatus PyDbViewport::setCustomScale(double val)
{
    return impObj()->setCustomScale(val);
}

AcDbViewport::StandardScaleType PyDbViewport::standardScale() const
{
    return impObj()->standardScale();
}

Acad::ErrorStatus PyDbViewport::setStandardScale(const AcDbViewport::StandardScaleType val)
{
    return impObj()->setStandardScale(val);
}

std::string PyDbViewport::plotStyleSheet() const
{
    const ACHAR* val = nullptr;
    if (auto es = impObj()->plotStyleSheet(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

std::string PyDbViewport::effectivePlotStyleSheet()
{
    const ACHAR* val = nullptr;
    if (auto es = impObj()->effectivePlotStyleSheet(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

Acad::ErrorStatus PyDbViewport::setPlotStyleSheet(const std::string& val)
{
    return impObj()->setPlotStyleSheet(utf8_to_wstr(val).c_str());
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
