#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makeAcDbSymbolTableRecordWrapper()
{
    class_<PyDbSymbolTableRecord, bases<PyDbObject>>("SymbolTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getName", &PyDbSymbolTableRecord::getName)
        .def("setName", &PyDbSymbolTableRecord::setName)
        .def("isDependent", &PyDbSymbolTableRecord::isDependent)
        .def("isResolved", &PyDbSymbolTableRecord::isResolved)
        .def("isRenamable", &PyDbSymbolTableRecord::isRenamable)
        .def("className", &PyDbSymbolTableRecord::className).staticmethod("className")
        .def("desc", &PyDbSymbolTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSymbolTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSymbolTableRecord::cast).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbSymbolTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSymbolTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    impObj()->getName(arxName);
    return wstr_to_utf8(arxName);
}

Acad::ErrorStatus PyDbSymbolTableRecord::setName(const std::string name)
{
    return impObj()->setName(utf8_to_wstr(name).c_str());
}

bool PyDbSymbolTableRecord::isDependent() const
{
    return impObj()->isDependent();
}

bool PyDbSymbolTableRecord::isResolved() const
{
    return impObj()->isResolved();
}

bool PyDbSymbolTableRecord::isRenamable() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isRenamable();
#endif
}

std::string PyDbSymbolTableRecord::className()
{
    return "AcDbSymbolTableRecord";
}

PyRxClass PyDbSymbolTableRecord::desc()
{
    return PyRxClass(AcDbSymbolTableRecord::desc(), false);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSymbolTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSymbolTableRecord(static_cast<AcDbSymbolTableRecord*>(src.impObj()->clone()), true);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cast(const PyRxObject& src)
{
    PyDbSymbolTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSymbolTableRecord* PyDbSymbolTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSymbolTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper()
{
    class_<PyDbDimStyleTableRecord, bases<PyDbSymbolTableRecord>>("DimStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbDimStyleTableRecord::className).staticmethod("className")
        .def("desc", &PyDbDimStyleTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTableRecord::cast).staticmethod("cast")
        ;
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbDimStyleTableRecord(), true)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbDimStyleTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDimStyleTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbDimStyleTableRecord::className()
{
    return "AcDbDimStyleTableRecord";
}

PyRxClass PyDbDimStyleTableRecord::desc()
{
    return PyRxClass(AcDbDimStyleTableRecord::desc(), false);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDimStyleTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDimStyleTableRecord(static_cast<AcDbDimStyleTableRecord*>(src.impObj()->clone()), true);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cast(const PyRxObject& src)
{
    PyDbDimStyleTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbDimStyleTableRecord* PyDbDimStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDimStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper()
{
    class_<PyDbAbstractViewTableRecord, bases<PyDbSymbolTableRecord>>("AbstractViewTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("centerPoint", &PyDbAbstractViewTableRecord::centerPoint)
        .def("setCenterPoint", &PyDbAbstractViewTableRecord::setCenterPoint)
        .def("height", &PyDbAbstractViewTableRecord::height)
        .def("setHeight", &PyDbAbstractViewTableRecord::setHeight)
        .def("width", &PyDbAbstractViewTableRecord::width)
        .def("setWidth", &PyDbAbstractViewTableRecord::setWidth)
        .def("target", &PyDbAbstractViewTableRecord::target)
        .def("setTarget", &PyDbAbstractViewTableRecord::setTarget)
        .def("viewDirection", &PyDbAbstractViewTableRecord::viewDirection)
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection1)
        .def("viewTwist", &PyDbAbstractViewTableRecord::viewTwist)
        .def("setViewTwist", &PyDbAbstractViewTableRecord::setViewTwist)
        .def("lensLength", &PyDbAbstractViewTableRecord::lensLength)
        .def("setLensLength", &PyDbAbstractViewTableRecord::setLensLength)
        .def("frontClipDistance", &PyDbAbstractViewTableRecord::frontClipDistance)
        .def("setFrontClipDistance", &PyDbAbstractViewTableRecord::setFrontClipDistance)
        .def("backClipDistance", &PyDbAbstractViewTableRecord::backClipDistance)
        .def("setBackClipDistance", &PyDbAbstractViewTableRecord::setBackClipDistance)
        .def("perspectiveEnabled", &PyDbAbstractViewTableRecord::perspectiveEnabled)
        .def("setPerspectiveEnabled", &PyDbAbstractViewTableRecord::setPerspectiveEnabled)
        .def("frontClipEnabled", &PyDbAbstractViewTableRecord::frontClipEnabled)
        .def("setFrontClipEnabled", &PyDbAbstractViewTableRecord::setFrontClipEnabled)
        .def("backClipEnabled", &PyDbAbstractViewTableRecord::backClipEnabled)
        .def("setBackClipEnabled", &PyDbAbstractViewTableRecord::setBackClipEnabled)
        .def("frontClipAtEye", &PyDbAbstractViewTableRecord::frontClipAtEye)
        .def("setFrontClipAtEye", &PyDbAbstractViewTableRecord::setFrontClipAtEye)
        .def("background", &PyDbAbstractViewTableRecord::background)
        .def("setBackground", &PyDbAbstractViewTableRecord::setBackground)
        .def("visualStyle", &PyDbAbstractViewTableRecord::visualStyle)
        .def("setVisualStyle", &PyDbAbstractViewTableRecord::setVisualStyle)
        .def("isDefaultLightingOn", &PyDbAbstractViewTableRecord::isDefaultLightingOn)
        .def("setDefaultLightingOn", &PyDbAbstractViewTableRecord::setDefaultLightingOn)
        .def("defaultLightingType", &PyDbAbstractViewTableRecord::defaultLightingType)
        .def("setDefaultLightingType", &PyDbAbstractViewTableRecord::setDefaultLightingType)
        .def("brightness", &PyDbAbstractViewTableRecord::brightness)
        .def("setBrightness", &PyDbAbstractViewTableRecord::setBrightness)
        .def("contrast", &PyDbAbstractViewTableRecord::contrast)
        .def("setContrast", &PyDbAbstractViewTableRecord::setContrast)
        .def("ambientLightColor", &PyDbAbstractViewTableRecord::ambientLightColor)
        .def("setAmbientLightColor", &PyDbAbstractViewTableRecord::setAmbientLightColor)
        .def("sunId", &PyDbAbstractViewTableRecord::sunId)
        .def("setSun", &PyDbAbstractViewTableRecord::setSun1)
        .def("setSun", &PyDbAbstractViewTableRecord::setSun2)
        .def("getUcs", &PyDbAbstractViewTableRecord::getUcs)
        .def("isUcsOrthographic", &PyDbAbstractViewTableRecord::isUcsOrthographic)
        .def("ucsName", &PyDbAbstractViewTableRecord::ucsName)
        .def("elevation", &PyDbAbstractViewTableRecord::elevation)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs1)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs2)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs3)
        .def("setUcsToWorld", &PyDbAbstractViewTableRecord::setUcsToWorld)
        .def("setElevation", &PyDbAbstractViewTableRecord::setElevation)
        .def("isViewOrthographic", &PyDbAbstractViewTableRecord::isViewOrthographic)
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection2)
        .def("className", &PyDbAbstractViewTableRecord::className).staticmethod("className")
        .def("desc", &PyDbAbstractViewTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbAbstractViewTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbAbstractViewTableRecord::cast).staticmethod("cast")
        ;
}
#ifdef NEVER
PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord()
    : PyDbSymbolTableRecord(new AcDbAbstractViewTableRecord(), true)
{
}
#endif

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(AcDbAbstractViewTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbAbstractViewTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAbstractViewTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

AcGePoint2d PyDbAbstractViewTableRecord::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDbAbstractViewTableRecord::setCenterPoint(const AcGePoint2d& val)
{
    return impObj()->setCenterPoint(val);
}

double PyDbAbstractViewTableRecord::height() const
{
    return impObj()->height();
}

void PyDbAbstractViewTableRecord::setHeight(double val)
{
    return impObj()->setHeight(val);
}

double PyDbAbstractViewTableRecord::width() const
{
    return impObj()->width();
}

void PyDbAbstractViewTableRecord::setWidth(double val)
{
    return impObj()->setWidth(val);
}

AcGePoint3d PyDbAbstractViewTableRecord::target() const
{
    return impObj()->target();
}

void PyDbAbstractViewTableRecord::setTarget(const AcGePoint3d& target)
{
    return impObj()->setTarget(target);
}

AcGeVector3d PyDbAbstractViewTableRecord::viewDirection() const
{
    return impObj()->viewDirection();
}

void PyDbAbstractViewTableRecord::setViewDirection1(const AcGeVector3d& viewDirection)
{
    return impObj()->setViewDirection(viewDirection);
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setViewDirection2(AcDb::OrthographicView view)
{
    return impObj()->setViewDirection(view);
}

double PyDbAbstractViewTableRecord::viewTwist() const
{
    return impObj()->viewTwist();
}

void PyDbAbstractViewTableRecord::setViewTwist(double angle)
{
    return impObj()->setViewTwist(angle);
}

double PyDbAbstractViewTableRecord::lensLength() const
{
    return impObj()->lensLength();
}

void PyDbAbstractViewTableRecord::setLensLength(double length)
{
    return impObj()->setLensLength(length);
}

double PyDbAbstractViewTableRecord::frontClipDistance() const
{
    return impObj()->frontClipDistance();
}

void PyDbAbstractViewTableRecord::setFrontClipDistance(double distance)
{
    return impObj()->setFrontClipDistance(distance);
}

double PyDbAbstractViewTableRecord::backClipDistance() const
{
    return impObj()->backClipDistance();
}

void PyDbAbstractViewTableRecord::setBackClipDistance(double distance)
{
    return impObj()->setBackClipDistance(distance);
}

bool PyDbAbstractViewTableRecord::perspectiveEnabled() const
{
    return impObj()->perspectiveEnabled();
}

void PyDbAbstractViewTableRecord::setPerspectiveEnabled(bool enabled)
{
    return impObj()->setPerspectiveEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::frontClipEnabled() const
{
    return impObj()->frontClipEnabled();
}

void PyDbAbstractViewTableRecord::setFrontClipEnabled(bool enabled)
{
    return impObj()->setFrontClipEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::backClipEnabled() const
{
    return impObj()->backClipEnabled();
}

void PyDbAbstractViewTableRecord::setBackClipEnabled(bool enabled)
{
    return impObj()->setBackClipEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::frontClipAtEye() const
{
    return impObj()->frontClipAtEye();
}

void PyDbAbstractViewTableRecord::setFrontClipAtEye(bool atEye)
{
    return impObj()->setFrontClipAtEye(atEye);
}

PyDbObjectId PyDbAbstractViewTableRecord::background() const
{
    return PyDbObjectId(impObj()->background());
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setBackground(const PyDbObjectId& backgroundId)
{
    return impObj()->setBackground(backgroundId.m_id);
}

PyDbObjectId PyDbAbstractViewTableRecord::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setVisualStyle(const PyDbObjectId& visualStyleId)
{
    return impObj()->setVisualStyle(visualStyleId.m_id);
}

bool PyDbAbstractViewTableRecord::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setDefaultLightingOn(bool on)
{
    return impObj()->setDefaultLightingOn(on);
}

AcGiViewportTraits::DefaultLightingType PyDbAbstractViewTableRecord::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ)
{
    return impObj()->setDefaultLightingType(typ);
}

double PyDbAbstractViewTableRecord::brightness() const
{
    return impObj()->brightness();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setBrightness(double val)
{
    return impObj()->setBrightness(val);
}

double PyDbAbstractViewTableRecord::contrast() const
{
    return impObj()->contrast();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setContrast(double val)
{
    return impObj()->setContrast(val);
}

AcCmColor PyDbAbstractViewTableRecord::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setAmbientLightColor(const AcCmColor& clr)
{
    return impObj()->setAmbientLightColor(clr);
}

PyDbObjectId PyDbAbstractViewTableRecord::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setSun1(PyDbObjectId& retId, PyDbObject& pSun)
{
    return impObj()->setSun(retId.m_id, pSun.impObj());
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun);
#endif
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const
{
    return impObj()->getUcs(origin, xAxis, yAxis);
}

boost::python::tuple PyDbAbstractViewTableRecord::isUcsOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view;
    bool flag = impObj()->isUcsOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

PyDbObjectId PyDbAbstractViewTableRecord::ucsName() const
{
    return PyDbObjectId(impObj()->ucsName());
}

double PyDbAbstractViewTableRecord::elevation() const
{
    return impObj()->elevation();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis)
{
    return impObj()->setUcs(origin, xAxis, yAxis);
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setUcs2(AcDb::OrthographicView view)
{
    return impObj()->setUcs(view);
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setUcs3(const PyDbObjectId& ucsId)
{
    return impObj()->setUcs(ucsId.m_id);
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setUcsToWorld()
{
    return impObj()->setUcsToWorld();
}

Acad::ErrorStatus PyDbAbstractViewTableRecord::setElevation(double elev)
{
    return impObj()->setElevation(elev);
}

boost::python::tuple PyDbAbstractViewTableRecord::isViewOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view;
    bool flag = impObj()->isViewOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

std::string PyDbAbstractViewTableRecord::className()
{
    return "AcDbAbstractViewTableRecord";
}

PyRxClass PyDbAbstractViewTableRecord::desc()
{
    return PyRxClass(AcDbAbstractViewTableRecord::desc(), false);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbAbstractViewTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAbstractViewTableRecord(static_cast<AcDbAbstractViewTableRecord*>(src.impObj()->clone()), true);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cast(const PyRxObject& src)
{
    PyDbAbstractViewTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbAbstractViewTableRecord* PyDbAbstractViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbAbstractViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper()
{
    class_<PyDbViewportTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewportTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("number", &PyDbViewportTableRecord::number)
        .def("lowerLeftCorner", &PyDbViewportTableRecord::lowerLeftCorner)
        .def("setLowerLeftCorner", &PyDbViewportTableRecord::setLowerLeftCorner)
        .def("upperRightCorner", &PyDbViewportTableRecord::upperRightCorner)
        .def("setUpperRightCorner", &PyDbViewportTableRecord::setUpperRightCorner)
        .def("ucsFollowMode", &PyDbViewportTableRecord::ucsFollowMode)
        .def("setUcsFollowMode", &PyDbViewportTableRecord::setUcsFollowMode)
        .def("circleSides", &PyDbViewportTableRecord::circleSides)
        .def("setCircleSides", &PyDbViewportTableRecord::setCircleSides)
        .def("fastZoomsEnabled", &PyDbViewportTableRecord::fastZoomsEnabled)
        .def("setFastZoomsEnabled", &PyDbViewportTableRecord::setFastZoomsEnabled)
        .def("iconEnabled", &PyDbViewportTableRecord::iconEnabled)
        .def("setIconEnabled", &PyDbViewportTableRecord::setIconEnabled)
        .def("iconAtOrigin", &PyDbViewportTableRecord::iconAtOrigin)
        .def("setIconAtOrigin", &PyDbViewportTableRecord::setIconAtOrigin)
        .def("gridEnabled", &PyDbViewportTableRecord::gridEnabled)
        .def("setGridEnabled", &PyDbViewportTableRecord::setGridEnabled)
        .def("gridIncrements", &PyDbViewportTableRecord::gridIncrements)
        .def("setGridIncrements", &PyDbViewportTableRecord::setGridIncrements)
        .def("snapEnabled", &PyDbViewportTableRecord::snapEnabled)
        .def("setSnapEnabled", &PyDbViewportTableRecord::setSnapEnabled)
        .def("isometricSnapEnabled", &PyDbViewportTableRecord::isometricSnapEnabled)
        .def("setIsometricSnapEnabled", &PyDbViewportTableRecord::setIsometricSnapEnabled)
        .def("snapPair", &PyDbViewportTableRecord::snapPair)
        .def("setSnapPair", &PyDbViewportTableRecord::setSnapPair)
        .def("snapAngle", &PyDbViewportTableRecord::snapAngle)
        .def("setSnapAngle", &PyDbViewportTableRecord::setSnapAngle)
        .def("snapBase", &PyDbViewportTableRecord::snapBase)
        .def("setSnapBase", &PyDbViewportTableRecord::setSnapBase)
        .def("snapIncrements", &PyDbViewportTableRecord::snapIncrements)
        .def("setSnapIncrements", &PyDbViewportTableRecord::setSnapIncrements)
        .def("isUcsSavedWithViewport", &PyDbViewportTableRecord::isUcsSavedWithViewport)
        .def("setUcsPerViewport", &PyDbViewportTableRecord::setUcsPerViewport)
        .def("isGridBoundToLimits", &PyDbViewportTableRecord::isGridBoundToLimits)
        .def("setGridBoundToLimits", &PyDbViewportTableRecord::setGridBoundToLimits)
        .def("isGridAdaptive", &PyDbViewportTableRecord::isGridAdaptive)
        .def("setGridAdaptive", &PyDbViewportTableRecord::setGridAdaptive)
        .def("isGridSubdivisionRestricted", &PyDbViewportTableRecord::isGridSubdivisionRestricted)
        .def("setGridSubdivisionRestricted", &PyDbViewportTableRecord::setGridSubdivisionRestricted)
        .def("isGridFollow", &PyDbViewportTableRecord::isGridFollow)
        .def("setGridFollow", &PyDbViewportTableRecord::setGridFollow)
        .def("gridMajor", &PyDbViewportTableRecord::gridMajor)
        .def("setGridMajor", &PyDbViewportTableRecord::setGridMajor)
        .def("setBackground", &PyDbViewportTableRecord::setBackground)
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground1)
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground2)
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground2)
        .def("previousBackgroundForcedSwitch", &PyDbViewportTableRecord::previousBackgroundForcedSwitch)
        .def("className", &PyDbViewportTableRecord::className).staticmethod("className")
        .def("desc", &PyDbViewportTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbViewportTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbViewportTableRecord::cast).staticmethod("cast")
        ;
}

PyDbViewportTableRecord::PyDbViewportTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewportTableRecord(), true)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(AcDbViewportTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(nullptr, false)
{
    AcDbViewportTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbViewportTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Adesk::Int16 PyDbViewportTableRecord::number() const
{
    return impObj()->number();
}

AcGePoint2d PyDbViewportTableRecord::lowerLeftCorner() const
{
    return impObj()->lowerLeftCorner();
}

void PyDbViewportTableRecord::setLowerLeftCorner(const AcGePoint2d& pt)
{
    return impObj()->setLowerLeftCorner(pt);
}

AcGePoint2d PyDbViewportTableRecord::upperRightCorner() const
{
    return impObj()->upperRightCorner();
}

void PyDbViewportTableRecord::setUpperRightCorner(const AcGePoint2d& pt)
{
    return impObj()->setUpperRightCorner(pt);
}

bool PyDbViewportTableRecord::ucsFollowMode() const
{
    return impObj()->ucsFollowMode();
}

void PyDbViewportTableRecord::setUcsFollowMode(bool enabled)
{
    return impObj()->setUcsFollowMode(enabled);
}

Adesk::UInt16 PyDbViewportTableRecord::circleSides() const
{
    return impObj()->circleSides();
}

void PyDbViewportTableRecord::setCircleSides(Adesk::UInt16 circleSides)
{
    return impObj()->setCircleSides(circleSides);
}

bool PyDbViewportTableRecord::fastZoomsEnabled() const
{
    return impObj()->fastZoomsEnabled();
}

void PyDbViewportTableRecord::setFastZoomsEnabled(bool enabled)
{
    return impObj()->setFastZoomsEnabled(enabled);
}

bool PyDbViewportTableRecord::iconEnabled() const
{
    return impObj()->iconEnabled();
}

void PyDbViewportTableRecord::setIconEnabled(bool enabled)
{
    return impObj()->setIconEnabled(enabled);
}

bool PyDbViewportTableRecord::iconAtOrigin() const
{
    return impObj()->iconAtOrigin();
}

void PyDbViewportTableRecord::setIconAtOrigin(bool atOrigin)
{
    return impObj()->setIconAtOrigin(atOrigin);
}

bool PyDbViewportTableRecord::gridEnabled() const
{
    return impObj()->gridEnabled();
}

void PyDbViewportTableRecord::setGridEnabled(bool enabled)
{
    return impObj()->setGridEnabled(enabled);
}

AcGePoint2d PyDbViewportTableRecord::gridIncrements() const
{
    return impObj()->gridIncrements();
}

void PyDbViewportTableRecord::setGridIncrements(const AcGePoint2d& base)
{
    return impObj()->setGridIncrements(base);
}

bool PyDbViewportTableRecord::snapEnabled() const
{
    return impObj()->snapEnabled();
}

void PyDbViewportTableRecord::setSnapEnabled(bool enabled)
{
    return impObj()->setSnapEnabled(enabled);
}

bool PyDbViewportTableRecord::isometricSnapEnabled() const
{
    return impObj()->isometricSnapEnabled();
}

void PyDbViewportTableRecord::setIsometricSnapEnabled(bool enabled)
{
    return impObj()->setIsometricSnapEnabled(enabled);
}

Adesk::Int16 PyDbViewportTableRecord::snapPair() const
{
    return impObj()->snapPair();
}

void PyDbViewportTableRecord::setSnapPair(Adesk::Int16 pairType)
{
    return impObj()->setSnapPair(pairType);
}

double PyDbViewportTableRecord::snapAngle() const
{
    return impObj()->snapAngle();
}

void PyDbViewportTableRecord::setSnapAngle(double angle)
{
    return impObj()->setSnapAngle(angle);
}

AcGePoint2d PyDbViewportTableRecord::snapBase() const
{
    return impObj()->snapBase();
}

void PyDbViewportTableRecord::setSnapBase(const AcGePoint2d& base)
{
    return impObj()->setSnapBase(base);
}

AcGePoint2d PyDbViewportTableRecord::snapIncrements() const
{
    return impObj()->snapIncrements();
}

void PyDbViewportTableRecord::setSnapIncrements(const AcGePoint2d& base)
{
    return impObj()->setSnapIncrements(base);
}

bool PyDbViewportTableRecord::isUcsSavedWithViewport() const
{
    return impObj()->isUcsSavedWithViewport();
}

void PyDbViewportTableRecord::setUcsPerViewport(bool ucsvp)
{
    return impObj()->setUcsPerViewport(ucsvp);
}

bool PyDbViewportTableRecord::isGridBoundToLimits() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewportTableRecord::setGridBoundToLimits(bool enabled)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridBoundToLimits(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridAdaptive() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewportTableRecord::setGridAdaptive(bool enabled)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridAdaptive(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridSubdivisionRestricted() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewportTableRecord::setGridSubdivisionRestricted(bool enabled)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridSubdivisionRestricted(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridFollow() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewportTableRecord::setGridFollow(bool enabled)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridFollow(enabled);
#endif
}

Adesk::Int16 PyDbViewportTableRecord::gridMajor() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewportTableRecord::setGridMajor(Adesk::Int16 value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridMajor(value);
#endif
}

Acad::ErrorStatus PyDbViewportTableRecord::setBackground(const PyDbObjectId& backgroundId)
{
    return impObj()->setBackground(backgroundId.m_id);
}

PyDbObjectId PyDbViewportTableRecord::previousBackground1() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewportTableRecord::previousBackground2(AcGiDrawable::DrawableType type) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

Acad::ErrorStatus PyDbViewportTableRecord::setPreviousBackground1(PyDbObjectId& backgroundId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviousBackground(backgroundId.m_id);
#endif
}

Acad::ErrorStatus PyDbViewportTableRecord::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviousBackground(backgroundId.m_id, type, bForcedSwitch);
#endif
}

bool PyDbViewportTableRecord::previousBackgroundForcedSwitch(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->previousBackgroundForcedSwitch();
#endif
}

std::string PyDbViewportTableRecord::className()
{
    return "AcDbViewportTableRecord";
}

PyRxClass PyDbViewportTableRecord::desc()
{
    return PyRxClass(AcDbViewportTableRecord::desc(), false);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewportTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewportTableRecord(static_cast<AcDbViewportTableRecord*>(src.impObj()->clone()), true);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cast(const PyRxObject& src)
{
    PyDbViewportTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewportTableRecord* PyDbViewportTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbViewportTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper()
{
    class_<PyDbViewTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getLayout", &PyDbViewTableRecord::getLayout)
        .def("setLayout", &PyDbViewTableRecord::setLayout)
        .def("className", &PyDbViewTableRecord::className).staticmethod("className")
        .def("desc", &PyDbViewTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbViewTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbViewTableRecord::cast).staticmethod("cast")
        ;
}

PyDbViewTableRecord::PyDbViewTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewTableRecord(), true)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(AcDbViewTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(nullptr, false)
{
    AcDbViewTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbViewTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbViewTableRecord::getLayout() const
{
    PyDbObjectId id;
    if (auto es = impObj()->getLayout(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

Acad::ErrorStatus PyDbViewTableRecord::setLayout(const PyDbObjectId& layoutId)
{
    return impObj()->setLayout(layoutId.m_id);
}

std::string PyDbViewTableRecord::className()
{
    return "AcDbViewTableRecord";
}

PyRxClass PyDbViewTableRecord::desc()
{
    return PyRxClass(AcDbViewTableRecord::desc(), false);
}

PyDbViewTableRecord PyDbViewTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewTableRecord(static_cast<AcDbViewTableRecord*>(src.impObj()->clone()), true);
}

PyDbViewTableRecord PyDbViewTableRecord::cast(const PyRxObject& src)
{
    PyDbViewTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewTableRecord* PyDbViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbViewTableRecord*>(m_pyImp.get());
}
