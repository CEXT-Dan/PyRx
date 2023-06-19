#include "stdafx.h"
#include "PyDbViewport.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbViewportWrapper()
{
    class_<PyDbViewport, bases<PyDbEntity>>("Entity")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        ;
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setModelView(xrefObjId.m_imp);
#endif
}

PyDbXrefObjectId PyDbViewport::getModelView() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyDbXrefObjectId id;
    if (auto es = impObj()->getModelView(id.m_imp); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

Acad::ErrorStatus PyDbViewport::removeModelView(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeModelView();
#endif
}

Acad::ErrorStatus PyDbViewport::setSheetView(PyDbObjectId objId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSheetView(objId.m_id);
#endif
}

PyDbObjectId PyDbViewport::getSheetView() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    if (auto es = impObj()->getSheetView(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

Acad::ErrorStatus PyDbViewport::removeSheetView(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeSheetView();
#endif
}

Acad::ErrorStatus PyDbViewport::setLabelBlock(PyDbObjectId& objId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLabelBlock(objId.m_id);
#endif
}

PyDbObjectId PyDbViewport::getLabelBlock() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    if (auto es = impObj()->getLabelBlock(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

Acad::ErrorStatus PyDbViewport::removeLabelBlock(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeLabelBlock();
#endif
}

Acad::ErrorStatus PyDbViewport::syncModelView(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->syncModelView();
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIsOn(bOn);
#endif
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

Acad::ErrorStatus PyDbViewport::setViewDirection1(const AcGeVector3d& val)
{
    return impObj()->setViewDirection(val);
}

Acad::ErrorStatus PyDbViewport::setViewDirection2(AcDb::OrthographicView view)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setViewDirection(view);
#endif
}

bool PyDbViewport::isUcsSavedWithViewport() const
{
    return impObj()->isUcsSavedWithViewport();
}

void PyDbViewport::setUcsPerViewport(bool ucsvp)
{
    return impObj()->setUcsPerViewport(ucsvp);
}

AcDbViewport::ShadePlotType PyDbViewport::shadePlot() const
{
    return impObj()->shadePlot();
}

Acad::ErrorStatus PyDbViewport::setShadePlot(const AcDbViewport::ShadePlotType val)
{
    return impObj()->setShadePlot(val);
}

Acad::ErrorStatus PyDbViewport::setShadePlot(const AcDbViewport::ShadePlotType type, const PyDbObjectId shadePlotId)
{
    return impObj()->setShadePlot(type, shadePlotId.m_id);
}

bool PyDbViewport::plotWireframe() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->plotWireframe();
#endif
}

bool PyDbViewport::plotAsRaster() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->plotAsRaster();
#endif
}

PyDbObjectId PyDbViewport::shadePlotId() const
{
    return PyDbObjectId(impObj()->shadePlotId());
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setFrontClipOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setBackClipOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setFrontClipAtEyeOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPerspectiveOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUcsFollowModeOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUcsIconVisible(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUcsIconAtOrigin(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setFastZoomOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSnapOn(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSnapIsometric(bOn);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridOn(val);
#endif
}

bool PyDbViewport::isGridBoundToLimits() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridBoundToLimits(bool bNewVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridBoundToLimits(bNewVal);
#endif
}

bool PyDbViewport::isGridAdaptive() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridAdaptive(bool bNewVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridAdaptive(bNewVal);
#endif
}

bool PyDbViewport::isGridSubdivisionRestricted() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridSubdivisionRestricted(bool bNewVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridSubdivisionRestricted(bNewVal);
#endif
}

bool PyDbViewport::isGridFollow() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridFollow(bool bNewVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridFollow(bNewVal);
#endif
}

Adesk::UInt16 PyDbViewport::gridMajor() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridMajor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridMajor(val);
#endif
}

AcGeVector2d PyDbViewport::gridIncrement() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridIncrement();
#endif
}

Acad::ErrorStatus PyDbViewport::setGridIncrement(const AcGeVector2d& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridIncrement(val);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeHiddenLines(val);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewport::previousBackground2(AcGiDrawable::DrawableType type) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground1(PyDbObjectId& backgroundId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviousBackground(backgroundId.m_id);
#endif
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviousBackground(backgroundId.m_id, type);
#endif
}

Acad::ErrorStatus PyDbViewport::setPreviousBackground3(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool force)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviousBackground(backgroundId.m_id, type, force);
#endif
}

bool PyDbViewport::previousBackgroundForcedSwitch(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->previousBackgroundForcedSwitch();
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLocked(val);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setTransparent(val);
#endif
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

bool PyDbViewport::isNonRectClipOn() const
{
    return impObj()->isNonRectClipOn();
}

Acad::ErrorStatus PyDbViewport::setNonRectClipOn1()
{
    return impObj()->setNonRectClipOn();
}

Acad::ErrorStatus PyDbViewport::setNonRectClipOff()
{
    return impObj()->setNonRectClipOff();
}

Acad::ErrorStatus PyDbViewport::setNonRectClipOn2(bool bOn)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setNonRectClipOn(bOn);
#endif
}

PyDbObjectId PyDbViewport::nonRectClipEntityId() const
{
    return PyDbObjectId(impObj()->nonRectClipEntityId());
}

Acad::ErrorStatus PyDbViewport::setNonRectClipEntityId(const PyDbObjectId& val)
{
    return impObj()->setNonRectClipEntityId(val.m_id);
}

void PyDbViewport::erased(const PyDbObject& id, Adesk::Boolean val)
{
    return impObj()->erased(id.impObj(), val);
}

void PyDbViewport::modified(const PyDbObject& obj)
{
    return impObj()->modified(obj.impObj());
}

void PyDbViewport::copied(const PyDbObject& pDbObj, const PyDbObject& pNewObj)
{
    return impObj()->copied(pDbObj.impObj(), pNewObj.impObj());
}

void PyDbViewport::subObjModified(const PyDbObject& pDbObj, const PyDbObject& pSubObj)
{
    return impObj()->subObjModified(pDbObj.impObj(), pSubObj.impObj());
}

Acad::ErrorStatus PyDbViewport::getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const
{
    return impObj()->getUcs(origin, xAxis, yAxis);
}

boost::python::tuple PyDbViewport::isUcsOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view = AcDb::OrthographicView::kNonOrthoView;
    bool flag = impObj()->isUcsOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

PyDbObjectId PyDbViewport::ucsName() const
{
    return PyDbObjectId(impObj()->ucsName());
}

double PyDbViewport::elevation() const
{
    return impObj()->elevation();
}

Acad::ErrorStatus PyDbViewport::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis)
{
    return impObj()->setUcs(origin, xAxis, yAxis);
}

Acad::ErrorStatus PyDbViewport::setUcs2(AcDb::OrthographicView view)
{
    return impObj()->setUcs(view);
}

Acad::ErrorStatus PyDbViewport::setUcs3(const PyDbObjectId& ucsId)
{
    return impObj()->setUcs(ucsId.m_id);
}

Acad::ErrorStatus PyDbViewport::setUcsToWorld()
{
    return impObj()->setUcsToWorld();
}

Acad::ErrorStatus PyDbViewport::setElevation(double elev)
{
    return impObj()->setElevation(elev);
}

boost::python::tuple PyDbViewport::isViewOrthographic() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcDb::OrthographicView view = AcDb::OrthographicView::kNonOrthoView;
    bool flag = impObj()->isViewOrthographic(view);
    return boost::python::make_tuple(flag, view);
#endif
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
