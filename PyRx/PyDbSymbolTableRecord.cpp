#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "PyDbObjectContext.h"
#include <wx/mstream.h>
using namespace boost::python;
//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makePyDbSymbolTableRecordWrapper()
{
    PyDocString DS("SymbolTableRecord");
    class_<PyDbSymbolTableRecord, bases<PyDbObject>>("SymbolTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead" })))
        .def("getName", &PyDbSymbolTableRecord::getName, DS.ARGS())
        .def("setName", &PyDbSymbolTableRecord::setName, DS.ARGS({ "name: str" }))
        .def("isDependent", &PyDbSymbolTableRecord::isDependent, DS.ARGS())
        .def("isResolved", &PyDbSymbolTableRecord::isResolved, DS.ARGS())
        .def("isRenamable", &PyDbSymbolTableRecord::isRenamable, DS.ARGS())
        .def("className", &PyDbSymbolTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSymbolTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbSymbolTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSymbolTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbSymbolTableRecord>(id,mode), false)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    impObj()->getName(arxName);
    return wstr_to_utf8(arxName);
}

void PyDbSymbolTableRecord::setName(const std::string name)
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbSymbolTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makePyDbDimStyleTableRecordWrapper()
{
    PyDocString DS("DimStyleTableRecord");
    class_<PyDbDimStyleTableRecord, bases<PyDbSymbolTableRecord>>("DimStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbDimStyleTableRecord>(id,mode), false)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id)
    : PyDbDimStyleTableRecord(id, AcDb::OpenMode::kForRead)
{
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbDimStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper()
{
    PyDocString DS("PyDbAbstractViewTableRecord");
    class_<PyDbAbstractViewTableRecord, bases<PyDbSymbolTableRecord>>("AbstractViewTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbAbstractViewTableRecord>(id,mode), false)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id)
    : PyDbAbstractViewTableRecord(id, AcDb::OpenMode::kForRead)
{
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

void PyDbAbstractViewTableRecord::setViewDirection2(AcDb::OrthographicView view)
{
    return PyThrowBadEs(impObj()->setViewDirection(view));
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

void PyDbAbstractViewTableRecord::setBackground(const PyDbObjectId& backgroundId)
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbAbstractViewTableRecord::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

void PyDbAbstractViewTableRecord::setVisualStyle(const PyDbObjectId& visualStyleId)
{
    return PyThrowBadEs(impObj()->setVisualStyle(visualStyleId.m_id));
}

bool PyDbAbstractViewTableRecord::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

void PyDbAbstractViewTableRecord::setDefaultLightingOn(bool on)
{
    return PyThrowBadEs(impObj()->setDefaultLightingOn(on));
}

AcGiViewportTraits::DefaultLightingType PyDbAbstractViewTableRecord::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

void PyDbAbstractViewTableRecord::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ)
{
    return PyThrowBadEs(impObj()->setDefaultLightingType(typ));
}

double PyDbAbstractViewTableRecord::brightness() const
{
    return impObj()->brightness();
}

void PyDbAbstractViewTableRecord::setBrightness(double val)
{
    return PyThrowBadEs(impObj()->setBrightness(val));
}

double PyDbAbstractViewTableRecord::contrast() const
{
    return impObj()->contrast();
}

void PyDbAbstractViewTableRecord::setContrast(double val)
{
    return PyThrowBadEs(impObj()->setContrast(val));
}

AcCmColor PyDbAbstractViewTableRecord::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

void PyDbAbstractViewTableRecord::setAmbientLightColor(const AcCmColor& clr)
{
    return PyThrowBadEs(impObj()->setAmbientLightColor(clr));
}

PyDbObjectId PyDbAbstractViewTableRecord::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbAbstractViewTableRecord::setSun1(PyDbObjectId& retId, PyDbObject& pSun)
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbAbstractViewTableRecord::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
}

void PyDbAbstractViewTableRecord::getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const
{
    return PyThrowBadEs(impObj()->getUcs(origin, xAxis, yAxis));
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

void PyDbAbstractViewTableRecord::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis)
{
    return PyThrowBadEs(impObj()->setUcs(origin, xAxis, yAxis));
}

void PyDbAbstractViewTableRecord::setUcs2(AcDb::OrthographicView view)
{
    return PyThrowBadEs(impObj()->setUcs(view));
}

void PyDbAbstractViewTableRecord::setUcs3(const PyDbObjectId& ucsId)
{
    return PyThrowBadEs(impObj()->setUcs(ucsId.m_id));
}

void PyDbAbstractViewTableRecord::setUcsToWorld()
{
    return PyThrowBadEs(impObj()->setUcsToWorld());
}

void PyDbAbstractViewTableRecord::setElevation(double elev)
{
    return PyThrowBadEs(impObj()->setElevation(elev));
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbAbstractViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper()
{
    PyDocString DS("ViewportTableRecord");
    class_<PyDbViewportTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewportTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewportTableRecord>(id,mode), false)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id)
    : PyDbViewportTableRecord(id, AcDb::OpenMode::kForRead)
{
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewportTableRecord::setGridBoundToLimits(bool enabled)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridBoundToLimits(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridAdaptive() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewportTableRecord::setGridAdaptive(bool enabled)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridAdaptive(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridSubdivisionRestricted() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewportTableRecord::setGridSubdivisionRestricted(bool enabled)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridSubdivisionRestricted(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridFollow() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewportTableRecord::setGridFollow(bool enabled)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridFollow(enabled);
#endif
}

Adesk::Int16 PyDbViewportTableRecord::gridMajor() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewportTableRecord::setGridMajor(Adesk::Int16 value)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridMajor(value);
#endif
}

void PyDbViewportTableRecord::setBackground(const PyDbObjectId& backgroundId)
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbViewportTableRecord::previousBackground1() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewportTableRecord::previousBackground2(AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

void PyDbViewportTableRecord::setPreviousBackground1(PyDbObjectId& backgroundId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
#endif
}

void PyDbViewportTableRecord::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, bForcedSwitch));
#endif
}

bool PyDbViewportTableRecord::previousBackgroundForcedSwitch(void) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbViewportTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper()
{
    PyDocString DS("ViewTableRecord");
    class_<PyDbViewTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("annotationScale", &PyDbViewTableRecord::annotationScale)
        .def("setAnnotationScale", &PyDbViewTableRecord::setAnnotationScale)
        .def("setParametersFromViewport", &PyDbViewTableRecord::setParametersFromViewport)
        .def("isPaperspaceView", &PyDbViewTableRecord::isPaperspaceView)
        .def("setIsPaperspaceView", &PyDbViewTableRecord::setIsPaperspaceView)
        .def("isUcsAssociatedToView", &PyDbViewTableRecord::isUcsAssociatedToView)
        .def("disassociateUcsFromView", &PyDbViewTableRecord::disassociateUcsFromView)
        .def("getCategoryName", &PyDbViewTableRecord::getCategoryName)
        .def("setCategoryName", &PyDbViewTableRecord::setCategoryName)
        .def("getLayerState", &PyDbViewTableRecord::getLayerState)
        .def("setLayerState", &PyDbViewTableRecord::setLayerState)
        .def("getLayout", &PyDbViewTableRecord::getLayout)
        .def("setLayout", &PyDbViewTableRecord::setLayout)
        .def("isViewAssociatedToViewport", &PyDbViewTableRecord::isViewAssociatedToViewport)
        .def("setViewAssociatedToViewport", &PyDbViewTableRecord::setViewAssociatedToViewport)
        .def("isCameraPlottable", &PyDbViewTableRecord::isCameraPlottable)
        .def("setIsCameraPlottable", &PyDbViewTableRecord::setIsCameraPlottable)
        .def("liveSection", &PyDbViewTableRecord::liveSection)
        .def("setLiveSection", &PyDbViewTableRecord::setLiveSection)
        .def("camera", &PyDbViewTableRecord::camera)
        .def("setCamera", &PyDbViewTableRecord::setCamera)
        .def("sunId", &PyDbViewTableRecord::sunId)
        .def("setSun", &PyDbViewTableRecord::setSun1)
        .def("setSun", &PyDbViewTableRecord::setSun2)
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
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewTableRecord>(id,mode), false)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id)
    : PyDbViewTableRecord(id, AcDb::OpenMode::kForRead)
{
}

void PyDbViewTableRecord::setParametersFromViewport(PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->setParametersFromViewport(objId.m_id));
}

bool PyDbViewTableRecord::isPaperspaceView() const
{
    return impObj()->isPaperspaceView();
}

void PyDbViewTableRecord::setIsPaperspaceView(bool pspace)
{
    return impObj()->setIsPaperspaceView(pspace);
}

bool PyDbViewTableRecord::isUcsAssociatedToView() const
{
    return impObj()->isUcsAssociatedToView();
}

void PyDbViewTableRecord::disassociateUcsFromView()
{
    return PyThrowBadEs(impObj()->disassociateUcsFromView());
}

std::string PyDbViewTableRecord::getCategoryName() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString str;
    if (auto es = impObj()->getCategoryName(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
#endif
}

void PyDbViewTableRecord::setCategoryName(const std::string& categoryName)
{
    return PyThrowBadEs(impObj()->setCategoryName(utf8_to_wstr(categoryName).c_str()));
}

std::string PyDbViewTableRecord::getLayerState() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString str;
    if (auto es = impObj()->getLayerState(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
#endif
}

void PyDbViewTableRecord::setLayerState(const std::string& layerStateName)
{
    return PyThrowBadEs(impObj()->setLayerState(utf8_to_wstr(layerStateName).c_str()));
}

PyDbObjectId PyDbViewTableRecord::getLayout() const
{
    PyDbObjectId id;
    if (auto es = impObj()->getLayout(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

void PyDbViewTableRecord::setLayout(const PyDbObjectId& layoutId)
{
    return PyThrowBadEs(impObj()->setLayout(layoutId.m_id));
}

bool PyDbViewTableRecord::isViewAssociatedToViewport() const
{
    return impObj()->isViewAssociatedToViewport();
}

void PyDbViewTableRecord::setViewAssociatedToViewport(bool bVPflag)
{
    return PyThrowBadEs(impObj()->setViewAssociatedToViewport(bVPflag));
}

bool PyDbViewTableRecord::isCameraPlottable() const
{
    return impObj()->isCameraPlottable();
}

void PyDbViewTableRecord::setIsCameraPlottable(bool plottable)
{
    return PyThrowBadEs(impObj()->setIsCameraPlottable(plottable));
}

PyDbObjectId PyDbViewTableRecord::liveSection() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->liveSection());
#endif
}

void PyDbViewTableRecord::setLiveSection(const PyDbObjectId& liveSectionId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLiveSection(liveSectionId.m_id));
#endif
}

PyDbObjectId PyDbViewTableRecord::camera() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->camera());
#endif
}

void PyDbViewTableRecord::setCamera(const PyDbObjectId& cameraId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCamera(cameraId.m_id));
#endif
}

PyDbAnnotationScale PyDbViewTableRecord::annotationScale() const
{
#ifdef ZRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbAnnotationScale(impObj()->annotationScale());
#endif
}

void PyDbViewTableRecord::setAnnotationScale(const PyDbAnnotationScale& pScaleObj)
{
#ifdef ZRXAPP
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
#endif
}

PyDbObjectId PyDbViewTableRecord::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbViewTableRecord::setSun1(PyDbObjectId& retId, PyDbObject& pSun)
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbViewTableRecord::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makePyDbBlockTableRecordWrapper()
{
    PyDocString DS("BlockTableRecord");
    class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("BlockTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId=kNull", "mode: OpenMode=kForRead" })))
        .def("appendAcDbEntity", &PyDbBlockTableRecord::appendAcDbEntity, DS.ARGS({ "entity :PyDb.Entity" }))
        .def("objectIds", &PyDbBlockTableRecord::objectIds)
        .def("objectIds", &PyDbBlockTableRecord::objectIdsOfType, DS.ARGS({"desc:PyRx.RxClass=AcDbEntity"}))
        .def("comments", &PyDbBlockTableRecord::comments)
        .def("setComments", &PyDbBlockTableRecord::setComments)
        .def("pathName", &PyDbBlockTableRecord::pathName)
        .def("setPathName", &PyDbBlockTableRecord::setPathName)
        .def("origin", &PyDbBlockTableRecord::origin)
        .def("setOrigin", &PyDbBlockTableRecord::setOrigin)
        .def("openBlockBegin", &PyDbBlockTableRecord::openBlockBegin)
        .def("openBlockEnd", &PyDbBlockTableRecord::openBlockEnd)
        .def("hasAttributeDefinitions", &PyDbBlockTableRecord::hasAttributeDefinitions)
        .def("hasPreviewIcon", &PyDbBlockTableRecord::hasPreviewIcon)
        .def("getPreviewIcon", &PyDbBlockTableRecord::getPreviewIcon)
        .def("clearPreviewIcon", &PyDbBlockTableRecord::clearPreviewIcon)
        .def("isAnonymous", &PyDbBlockTableRecord::isAnonymous)
        .def("isFromExternalReference", &PyDbBlockTableRecord::isFromExternalReference)
        .def("isFromOverlayReference", &PyDbBlockTableRecord::isFromOverlayReference)
        .def("setIsFromOverlayReference", &PyDbBlockTableRecord::setIsFromOverlayReference)
        .def("isLayout", &PyDbBlockTableRecord::isLayout)
        .def("getLayoutId", &PyDbBlockTableRecord::getLayoutId)
        .def("setLayoutId", &PyDbBlockTableRecord::setLayoutId)
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds1)
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds2)
        .def("getErasedBlockReferenceIds", &PyDbBlockTableRecord::getErasedBlockReferenceIds)
        .def("xrefDatabase", &PyDbBlockTableRecord::xrefDatabase)
        .def("isUnloaded", &PyDbBlockTableRecord::isUnloaded)
        .def("setIsUnloaded", &PyDbBlockTableRecord::setIsUnloaded)
        .def("xrefStatus", &PyDbBlockTableRecord::xrefStatus)
        .def("assumeOwnershipOf", &PyDbBlockTableRecord::assumeOwnershipOf)
        .def("blockScaling", &PyDbBlockTableRecord::blockScaling)
        .def("setBlockScaling", &PyDbBlockTableRecord::setBlockScaling)
        .def("setExplodable", &PyDbBlockTableRecord::setExplodable)
        .def("explodable", &PyDbBlockTableRecord::explodable)
        .def("setBlockInsertUnits", &PyDbBlockTableRecord::setBlockInsertUnits)
        .def("blockInsertUnits", &PyDbBlockTableRecord::blockInsertUnits)
        .def("postProcessAnnotativeBTR", &PyDbBlockTableRecord::postProcessAnnotativeBTR)
        .def("addAnnoScalestoBlkRefs", &PyDbBlockTableRecord::addAnnoScalestoBlkRefs)
        .def("className", &PyDbBlockTableRecord::className).staticmethod("className")
        .def("desc", &PyDbBlockTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockTableRecord::cast).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord
PyDbBlockTableRecord::PyDbBlockTableRecord()
    : PyDbSymbolTableRecord(new AcDbBlockTableRecord(), true)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbBlockTableRecord>(id,mode), false)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id)
    : PyDbBlockTableRecord(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent)
{
    AcDbObjectId _id;
    if (auto es = impObj()->appendAcDbEntity(_id, ent.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(_id);
}

boost::python::list PyDbBlockTableRecord::objectIds()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es == eOk)
    {
        PyDbObjectId id;
        for (iter->start(); !iter->done(); iter->step())
        {
            if (iter->getEntityId(id.m_id) == eOk)
                pyList.append(id);
        }
    }
    return pyList;
}

boost::python::list PyDbBlockTableRecord::objectIdsOfType(const PyRxClass& _class)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto _desc = _class.impObj();
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es == eOk)
    {
        PyDbObjectId id;
        for (iter->start(); !iter->done(); iter->step())
        {
            if (iter->getEntityId(id.m_id) == eOk)
            {
                if (id.m_id.objectClass()->isDerivedFrom(_desc))
                    pyList.append(id);
            }
        }
    }
    return pyList;
}

std::string PyDbBlockTableRecord::comments()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->comments(str);
    return wstr_to_utf8(str);
#endif
}

void PyDbBlockTableRecord::setComments(const std::string& pString)
{
    return PyThrowBadEs(impObj()->setComments(utf8_to_wstr(pString).c_str()));
}

std::string PyDbBlockTableRecord::pathName()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->pathName(str);
    return wstr_to_utf8(str);
#endif
}

void PyDbBlockTableRecord::setPathName(const std::string& pString)
{
    return PyThrowBadEs(impObj()->setPathName(utf8_to_wstr(pString).c_str()));
}

AcGePoint3d PyDbBlockTableRecord::origin() const
{
    return impObj()->origin();
}

void PyDbBlockTableRecord::setOrigin(const AcGePoint3d& pt)
{
    return PyThrowBadEs(impObj()->setOrigin(pt));
}

//TODO: wrong
void PyDbBlockTableRecord::openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode)
{
    AcDbBlockBegin* pObj = nullptr;
    PyThrowBadEs(impObj()->openBlockBegin(pObj, openMode));
    pBlockBegin = PyDbBlockBegin(pObj, false);
}

void PyDbBlockTableRecord::openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode)
{
    AcDbBlockEnd* pObj = nullptr;
    PyThrowBadEs(impObj()->openBlockEnd(pObj, openMode));
    pBlockBegin = PyDbBlockEnd(pObj, false);
}

bool PyDbBlockTableRecord::hasAttributeDefinitions() const
{
    return impObj()->hasAttributeDefinitions();
}

bool PyDbBlockTableRecord::hasPreviewIcon() const
{
    return impObj()->hasPreviewIcon();
}

//TODO remove hack
static void addBITMAPFILEHEADER(AcDbBlockTableRecord::PreviewIcon& ico)
{
    //BITMAPFILEHEADER
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x36);//offset BITMAPFILEHEADER + BITMAPINFO
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);//0 file size? ico.length()ok
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x4D);
    ico.insertAt(0, 0x42);//BM0
}

boost::python::object PyDbBlockTableRecord::getPreviewIcon() const
{
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt8> previewIcon;
    previewIcon.setLogicalLength(2048);
    PyThrowBadEs(impObj()->getPreviewIcon(previewIcon));
    addBITMAPFILEHEADER(previewIcon);
    wxMemoryInputStream stream(previewIcon.asArrayPtr(), previewIcon.length());
    wxImage img(stream);
    wxBitmap* bmp = new wxBitmap(img);
    if (!bmp->IsOk())
        PyThrowBadEs(Acad::eInvalidPreviewImage);
    return boost::python::object(boost::python::handle<>(wxPyConstructObject(bmp, "wxBitmap", true)));
}

void PyDbBlockTableRecord::clearPreviewIcon() const
{
    static AcArray<Adesk::UInt8> previewIcon;
    PyThrowBadEs(impObj()->setPreviewIcon(previewIcon));
}

bool PyDbBlockTableRecord::isAnonymous() const
{
    return impObj()->isAnonymous();
}

bool PyDbBlockTableRecord::isFromExternalReference() const
{
    return impObj()->isFromExternalReference();
}

bool PyDbBlockTableRecord::isFromOverlayReference() const
{
    return impObj()->isFromOverlayReference();
}

void PyDbBlockTableRecord::setIsFromOverlayReference(bool bIsOverlay)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIsFromOverlayReference(bIsOverlay));
#endif
}

bool PyDbBlockTableRecord::isLayout() const
{
    return impObj()->isLayout();
}

PyDbObjectId PyDbBlockTableRecord::getLayoutId() const
{
    return PyDbObjectId(impObj()->getLayoutId());
}

void PyDbBlockTableRecord::setLayoutId(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setLayoutId(id.m_id));
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds1()
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list lids;
    impObj()->getBlockReferenceIds(ids);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity)
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list lids;
    impObj()->getBlockReferenceIds(ids, bDirectOnly, bForceValidity);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

boost::python::list PyDbBlockTableRecord::getErasedBlockReferenceIds()
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list lids;
    impObj()->getErasedBlockReferenceIds(ids);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

PyDbDatabase PyDbBlockTableRecord::xrefDatabase(bool incUnres) const
{
    return PyDbDatabase(impObj()->xrefDatabase(incUnres));
}

bool PyDbBlockTableRecord::isUnloaded() const
{
    return impObj()->isUnloaded();
}

void PyDbBlockTableRecord::setIsUnloaded(bool isUnloaded)
{
    return PyThrowBadEs(impObj()->setIsUnloaded(isUnloaded));
}

AcDb::XrefStatus PyDbBlockTableRecord::xrefStatus() const
{
    return impObj()->xrefStatus();
}

void PyDbBlockTableRecord::assumeOwnershipOf(const boost::python::list& entitiesToMove)
{
    try
    {
        PyAutoLockGIL lock;
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(entitiesToMove);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);
        return PyThrowBadEs(impObj()->assumeOwnershipOf(ids));
    }
    catch (...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

AcDbBlockTableRecord::BlockScaling PyDbBlockTableRecord::blockScaling() const
{
    return impObj()->blockScaling();
}

void PyDbBlockTableRecord::setBlockScaling(AcDbBlockTableRecord::BlockScaling _blockScaling)
{
    return PyThrowBadEs(impObj()->setBlockScaling(_blockScaling));
}

void PyDbBlockTableRecord::setExplodable(bool bExplodable)
{
    return PyThrowBadEs(impObj()->setExplodable(bExplodable));
}

bool PyDbBlockTableRecord::explodable() const
{
    return impObj()->explodable();
}

void PyDbBlockTableRecord::setBlockInsertUnits(AcDb::UnitsValue insunits)
{
    return PyThrowBadEs(impObj()->setBlockInsertUnits(insunits));
}

AcDb::UnitsValue PyDbBlockTableRecord::blockInsertUnits() const
{
    return impObj()->blockInsertUnits();
}

int PyDbBlockTableRecord::postProcessAnnotativeBTR(bool bqueryOnly, bool bScale)
{
    int stripCnt = 0;
    if (auto stat = impObj()->postProcessAnnotativeBTR(stripCnt, bqueryOnly, bScale); stat != eOk)
        throw PyAcadErrorStatus(stat);
    return stripCnt;
}

void PyDbBlockTableRecord::addAnnoScalestoBlkRefs(bool bScale /*= false*/)
{
    return PyThrowBadEs(impObj()->addAnnoScalestoBlkRefs(bScale));
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

PyRxClass PyDbBlockTableRecord::desc()
{
    return PyRxClass(AcDbBlockTableRecord::desc(), false);
}

PyDbBlockTableRecord PyDbBlockTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbBlockTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBlockTableRecord(static_cast<AcDbBlockTableRecord*>(src.impObj()->clone()), true);
}

PyDbBlockTableRecord PyDbBlockTableRecord::cast(const PyRxObject& src)
{
    PyDbBlockTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbBlockTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
void makePyDbLayerTableRecordWrapper()
{
    PyDocString DS("LayerTableRecord");
    class_<PyDbLayerTableRecord, bases<PyDbSymbolTableRecord>>("LayerTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("isFrozen", &PyDbLayerTableRecord::isFrozen)
        .def("setIsFrozen", &PyDbLayerTableRecord::setIsFrozen)
        .def("isOff", &PyDbLayerTableRecord::isOff)
        .def("setIsOff", &PyDbLayerTableRecord::setIsOff)
        .def("VPDFLT", &PyDbLayerTableRecord::VPDFLT)
        .def("setVPDFLT", &PyDbLayerTableRecord::setVPDFLT)
        .def("isLocked", &PyDbLayerTableRecord::isLocked)
        .def("setIsLocked", &PyDbLayerTableRecord::setIsLocked)
        .def<AcCmColor(PyDbLayerTableRecord::*)(void)const>("color", &PyDbLayerTableRecord::color)
        .def<AcCmColor(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("color", &PyDbLayerTableRecord::color)
        .def<void(PyDbLayerTableRecord::*)(const AcCmColor& color)>("setColor", &PyDbLayerTableRecord::setColor)
        .def<void(PyDbLayerTableRecord::*)(const AcCmColor& color, const PyDbObjectId&)>("setColor", &PyDbLayerTableRecord::setColor)
        .def("entityColor", &PyDbLayerTableRecord::entityColor)
        .def<AcCmTransparency(PyDbLayerTableRecord::*)(void)const>("transparency", &PyDbLayerTableRecord::transparency)
        .def<AcCmTransparency(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("transparency", &PyDbLayerTableRecord::transparency)
        .def<void(PyDbLayerTableRecord::*)(const AcCmTransparency&)>("setTransparency", &PyDbLayerTableRecord::setTransparency)
        .def<void(PyDbLayerTableRecord::*)(const AcCmTransparency&, const PyDbObjectId&)>("setTransparency", &PyDbLayerTableRecord::setTransparency)
        .def("linetypeObjectId", &PyDbLayerTableRecord::linetypeObjectId)
        .def("setLinetypeObjectId", &PyDbLayerTableRecord::setLinetypeObjectId)
        .def("materialId", &PyDbLayerTableRecord::materialId)
        .def("setMaterialId", &PyDbLayerTableRecord::setMaterialId)
        .def("isPlottable", &PyDbLayerTableRecord::isPlottable)
        .def("setIsPlottable", &PyDbLayerTableRecord::setIsPlottable)
        .def<AcDb::LineWeight(PyDbLayerTableRecord::*)(void)const>("lineWeight", &PyDbLayerTableRecord::lineWeight)
        .def<AcDb::LineWeight(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("lineWeight", &PyDbLayerTableRecord::lineWeight)
        .def<void(PyDbLayerTableRecord::*)(AcDb::LineWeight)>("setLineWeight", &PyDbLayerTableRecord::setLineWeight)
        .def<void(PyDbLayerTableRecord::*)(AcDb::LineWeight, const PyDbObjectId&)>("setLineWeight", &PyDbLayerTableRecord::setLineWeight)
        .def<std::string(PyDbLayerTableRecord::*)(void)const>("plotStyleName", &PyDbLayerTableRecord::plotStyleName)
        .def<std::string(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("plotStyleName", &PyDbLayerTableRecord::plotStyleName)
        .def<PyDbObjectId(PyDbLayerTableRecord::*)(void)const>("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId)
        .def<PyDbObjectId(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId)
        .def<void(PyDbLayerTableRecord::*)(const std::string&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<void(PyDbLayerTableRecord::*)(const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<void(PyDbLayerTableRecord::*)(const PyDbObjectId&, const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<void(PyDbLayerTableRecord::*)(const std::string&, const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def("isInUse", &PyDbLayerTableRecord::isInUse)
        .def("description", &PyDbLayerTableRecord::description)
        .def("setDescription", &PyDbLayerTableRecord::setDescription)
        .def("setIsHidden", &PyDbLayerTableRecord::setIsHidden)
        .def("isHidden", &PyDbLayerTableRecord::isHidden)
        .def("isHidden", &PyDbLayerTableRecord::isHiddenS).staticmethod("isHidden")//TODO: can't override with a static
        .def("removeColorOverride", &PyDbLayerTableRecord::removeColorOverride)
        .def("removeLinetypeOverride", &PyDbLayerTableRecord::removeLinetypeOverride)
        .def("removeLineWeightOverride", &PyDbLayerTableRecord::removeLineWeightOverride)
        .def("removePlotStyleOverride", &PyDbLayerTableRecord::removePlotStyleOverride)
        .def("removeTransparencyOverride", &PyDbLayerTableRecord::removeTransparencyOverride)
        .def("removeViewportOverrides", &PyDbLayerTableRecord::removeViewportOverrides)
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides)
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides)
        .def("hasOverrides", &PyDbLayerTableRecord::hasOverrides)
        .def("hasAnyOverrides", &PyDbLayerTableRecord::hasAnyOverrides)
        .def("isReconciled", &PyDbLayerTableRecord::isReconciled)
        .def("isReconciled", &PyDbLayerTableRecord::isReconciledS).staticmethod("isReconciled")//TODO: can't override with a static test
        .def("className", &PyDbLayerTableRecord::className).staticmethod("className")
        .def("desc", &PyDbLayerTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLayerTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLayerTableRecord::cast).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
PyDbLayerTableRecord::PyDbLayerTableRecord()
    :PyDbSymbolTableRecord(new AcDbLayerTableRecord(), true)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(AcDbLayerTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, false)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLayerTableRecord>(id,mode), false)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id)
    : PyDbLayerTableRecord(id, AcDb::OpenMode::kForRead)
{
}

bool PyDbLayerTableRecord::isFrozen() const
{
    return impObj()->isFrozen();
}

void PyDbLayerTableRecord::setIsFrozen(bool frozen)
{
    return PyThrowBadEs(impObj()->setIsFrozen(frozen));
}

bool PyDbLayerTableRecord::isOff() const
{
    return impObj()->isOff();
}

void PyDbLayerTableRecord::setIsOff(bool off)
{
    return impObj()->setIsOff(off);
}

bool PyDbLayerTableRecord::VPDFLT() const
{
    return impObj()->VPDFLT();
}

void PyDbLayerTableRecord::setVPDFLT(bool frozen)
{
    return impObj()->setVPDFLT(frozen);
}

bool PyDbLayerTableRecord::isLocked() const
{
    return impObj()->isLocked();
}

void PyDbLayerTableRecord::setIsLocked(bool locked)
{
    return impObj()->setIsLocked(locked);
}

AcCmColor PyDbLayerTableRecord::color() const
{
    return impObj()->color();
}

AcCmColor PyDbLayerTableRecord::color(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->color(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setColor(const AcCmColor& _color)
{
    return impObj()->setColor(_color);
}

void PyDbLayerTableRecord::setColor(const AcCmColor& color, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setColor(color, viewportId.m_id));
}

AcCmEntityColor PyDbLayerTableRecord::entityColor(void) const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbLayerTableRecord::transparency(void) const
{
    return impObj()->transparency();
}

AcCmTransparency PyDbLayerTableRecord::transparency(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->transparency(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans)
{
    return PyThrowBadEs(impObj()->setTransparency(trans));
}

void PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setTransparency(trans, viewportId.m_id));
}

void PyDbLayerTableRecord::removeColorOverride(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removeColorOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeLinetypeOverride(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removeLinetypeOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeLineWeightOverride(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removeLineWeightOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removePlotStyleOverride(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removePlotStyleOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeTransparencyOverride(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removeTransparencyOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeViewportOverrides(const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->removeViewportOverrides(viewportId.m_id));
}

void PyDbLayerTableRecord::removeAllOverrides()
{
    return PyThrowBadEs(impObj()->removeAllOverrides());
}

bool PyDbLayerTableRecord::hasOverrides(const PyDbObjectId& viewportId) const
{
    return impObj()->hasOverrides(viewportId.m_id);
}

bool PyDbLayerTableRecord::hasAnyOverrides() const
{
    return impObj()->hasAnyOverrides();
}

PyDbObjectId PyDbLayerTableRecord::linetypeObjectId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

void PyDbLayerTableRecord::setLinetypeObjectId(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    impObj()->setLinetypeObjectId(id.m_id);
#else
    return PyThrowBadEs(impObj()->setLinetypeObjectId(id.m_id));
#endif // BRXAPP
}

PyDbObjectId PyDbLayerTableRecord::materialId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

void PyDbLayerTableRecord::setMaterialId(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setMaterialId(id.m_id));
}

bool PyDbLayerTableRecord::isPlottable() const
{
    return impObj()->isPlottable();
}

void PyDbLayerTableRecord::setIsPlottable(bool plot)
{
    return PyThrowBadEs(impObj()->setIsPlottable(plot));
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight() const
{
    return impObj()->lineWeight();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->lineWeight(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight)
{
    return PyThrowBadEs(impObj()->setLineWeight(weight));
}

void PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setLineWeight(weight, viewportId.m_id));
}

std::string PyDbLayerTableRecord::plotStyleName() const
{
    return wstr_to_utf8(impObj()->plotStyleName());
}

std::string PyDbLayerTableRecord::plotStyleName(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return wstr_to_utf8(impObj()->plotStyleName(viewportId.m_id, flag));
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId() const
{
    return PyDbObjectId(impObj()->plotStyleNameId());
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return PyDbObjectId(impObj()->plotStyleNameId(viewportId.m_id, flag));
}

void PyDbLayerTableRecord::setPlotStyleName(const std::string& newName)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str()));
}

void PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(newId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName(const std::string& newName, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str(), viewportId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(newId.m_id, viewportId.m_id));
}

bool PyDbLayerTableRecord::isInUse() const
{
    return impObj()->isInUse();
}

std::string PyDbLayerTableRecord::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbLayerTableRecord::setDescription(const std::string& description)
{
    return PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(description).c_str()));
}

bool PyDbLayerTableRecord::isHidden() const
{
    return impObj()->isHidden();
}

bool PyDbLayerTableRecord::isHiddenS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isHidden(id.m_id);
}

void PyDbLayerTableRecord::setIsHidden(bool on)
{
    return PyThrowBadEs(impObj()->setIsHidden(on));
}

bool PyDbLayerTableRecord::isReconciled() const
{
    return impObj()->isReconciled();
}

bool PyDbLayerTableRecord::isReconciledS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isReconciled(id.m_id);
}

void PyDbLayerTableRecord::setIsReconciled(bool bReconcile /*= true*/)
{
    return PyThrowBadEs(impObj()->setIsReconciled(bReconcile));
}

std::string PyDbLayerTableRecord::className()
{
    return "AcDbLayerTableRecord";
}

PyRxClass PyDbLayerTableRecord::desc()
{
    return PyRxClass(AcDbLayerTableRecord::desc(), false);
}

PyDbLayerTableRecord PyDbLayerTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbLayerTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLayerTableRecord(static_cast<AcDbLayerTableRecord*>(src.impObj()->clone()), true);

}

PyDbLayerTableRecord PyDbLayerTableRecord::cast(const PyRxObject& src)
{
    PyDbLayerTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLayerTableRecord* PyDbLayerTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbLayerTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbTextStyleTableRecord
void makePyDbTextStyleTableRecordWrapper()
{
    PyDocString DS("TextStyleTableRecord");
    class_<PyDbTextStyleTableRecord, bases<PyDbSymbolTableRecord>>("TextStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("isShapeFile", &PyDbTextStyleTableRecord::isShapeFile)
        .def("setIsShapeFile", &PyDbTextStyleTableRecord::setIsShapeFile)
        .def("isVertical", &PyDbTextStyleTableRecord::isVertical)
        .def("setIsVertical", &PyDbTextStyleTableRecord::setIsVertical)
        .def("textSize", &PyDbTextStyleTableRecord::textSize)
        .def("setTextSize", &PyDbTextStyleTableRecord::setTextSize)
        .def("xScale", &PyDbTextStyleTableRecord::xScale)
        .def("setXScale", &PyDbTextStyleTableRecord::setXScale)
        .def("obliquingAngle", &PyDbTextStyleTableRecord::obliquingAngle)
        .def("setObliquingAngle", &PyDbTextStyleTableRecord::setObliquingAngle)
        .def("flagBits", &PyDbTextStyleTableRecord::flagBits)
        .def("setFlagBits", &PyDbTextStyleTableRecord::setFlagBits)
        .def("priorSize", &PyDbTextStyleTableRecord::priorSize)
        .def("setPriorSize", &PyDbTextStyleTableRecord::setPriorSize)
        .def("fileName", &PyDbTextStyleTableRecord::fileName)
        .def("setFileName", &PyDbTextStyleTableRecord::setFileName)
        .def("bigFontFileName", &PyDbTextStyleTableRecord::bigFontFileName)
        .def("setBigFontFileName", &PyDbTextStyleTableRecord::setBigFontFileName)
        .def("setFont", &PyDbTextStyleTableRecord::setFont)
        .def("font", &PyDbTextStyleTableRecord::font)
        .def("className", &PyDbTextStyleTableRecord::className).staticmethod("className")
        .def("desc", &PyDbTextStyleTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbTextStyleTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbTextStyleTableRecord::cast).staticmethod("cast")
        ;
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbTextStyleTableRecord(), true)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(AcDbTextStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbTextStyleTableRecord>(id,mode), false)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id)
    : PyDbTextStyleTableRecord(id, AcDb::OpenMode::kForRead)
{
}

Adesk::Boolean PyDbTextStyleTableRecord::isShapeFile() const
{
    return impObj()->isShapeFile();
}

void PyDbTextStyleTableRecord::setIsShapeFile(Adesk::Boolean shape)
{
    return impObj()->setIsShapeFile(shape);
}

Adesk::Boolean PyDbTextStyleTableRecord::isVertical() const
{
    return impObj()->isVertical();
}

void PyDbTextStyleTableRecord::setIsVertical(Adesk::Boolean vertical)
{
    return impObj()->setIsVertical(vertical);
}

double PyDbTextStyleTableRecord::textSize() const
{
    return impObj()->textSize();
}

void PyDbTextStyleTableRecord::setTextSize(double size)
{
    return PyThrowBadEs(impObj()->setTextSize(size));
}

double PyDbTextStyleTableRecord::xScale() const
{
    return impObj()->xScale();
}

void PyDbTextStyleTableRecord::setXScale(double xScale)
{
    return PyThrowBadEs(impObj()->setXScale(xScale));
}

double PyDbTextStyleTableRecord::obliquingAngle() const
{
    return impObj()->obliquingAngle();
}

void PyDbTextStyleTableRecord::setObliquingAngle(double obliquingAngle)
{
    return PyThrowBadEs(impObj()->setObliquingAngle(obliquingAngle));
}

Adesk::UInt8 PyDbTextStyleTableRecord::flagBits() const
{
    return impObj()->flagBits();
}

void PyDbTextStyleTableRecord::setFlagBits(Adesk::UInt8 flagBits)
{
    return impObj()->setFlagBits(flagBits);
}

double PyDbTextStyleTableRecord::priorSize() const
{
    return impObj()->priorSize();
}

void PyDbTextStyleTableRecord::setPriorSize(double priorSize)
{
    return PyThrowBadEs(impObj()->setPriorSize(priorSize));
}

std::string PyDbTextStyleTableRecord::fileName()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString path;
    if (auto es = impObj()->fileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
#endif
}

void PyDbTextStyleTableRecord::setFileName(const std::string& path)
{
    return PyThrowBadEs(impObj()->setFileName(utf8_to_wstr(path).c_str()));
}

std::string PyDbTextStyleTableRecord::bigFontFileName()
{
    AcString path;
    if (auto es = impObj()->bigFontFileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
}

void PyDbTextStyleTableRecord::setBigFontFileName(const std::string& path)
{
    return PyThrowBadEs(impObj()->setBigFontFileName(utf8_to_wstr(path).c_str()));
}

void PyDbTextStyleTableRecord::setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont)
{
    return PyThrowBadEs(impObj()->setFont(
        utf8_to_wstr(pTypeface).c_str(),
        bold,
        italic,
        (Charset)charset,
        (Autodesk::AutoCAD::PAL::FontUtils::FontPitch)pitch,
        (Autodesk::AutoCAD::PAL::FontUtils::FontFamily)family, bAllowMissingFont));
}

boost::python::tuple PyDbTextStyleTableRecord::font()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    bool bold = false;
    bool italic = false;
    Charset charset = kAnsiCharset;
    AcString sTypeface;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch = Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family = Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare;
    if (auto es = impObj()->font(sTypeface, bold, italic, charset, pitch, family); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string tf = wstr_to_utf8(sTypeface);
    return boost::python::make_tuple(tf, bold, italic, (int)charset, (int)pitch, (int)family);
#endif
}

std::string PyDbTextStyleTableRecord::className()
{
    return "AcDbTextStyleTableRecord";
}

PyRxClass PyDbTextStyleTableRecord::desc()
{
    return PyRxClass(AcDbTextStyleTableRecord::desc(), false);
}

PyDbTextStyleTableRecord PyDbTextStyleTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbTextStyleTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbTextStyleTableRecord(static_cast<AcDbTextStyleTableRecord*>(src.impObj()->clone()), true);
}

PyDbTextStyleTableRecord PyDbTextStyleTableRecord::cast(const PyRxObject& src)
{
    PyDbTextStyleTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbTextStyleTableRecord* PyDbTextStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbTextStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbUCSTableRecord
void makePyDbUCSTableRecordWrapper()
{
    PyDocString DS("UCSTableRecord");
    class_<PyDbUCSTableRecord, bases<PyDbSymbolTableRecord>>("UCSTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("origin", &PyDbUCSTableRecord::origin)
        .def("setOrigin", &PyDbUCSTableRecord::setOrigin)
        .def("xAxis", &PyDbUCSTableRecord::xAxis)
        .def("setXAxis", &PyDbUCSTableRecord::setXAxis)
        .def("yAxis", &PyDbUCSTableRecord::yAxis)
        .def("setYAxis", &PyDbUCSTableRecord::setYAxis)
        .def("ucsBaseOrigin", &PyDbUCSTableRecord::ucsBaseOrigin)
        .def("setUcsBaseOrigin", &PyDbUCSTableRecord::setUcsBaseOrigin)
        .def("className", &PyDbUCSTableRecord::className).staticmethod("className")
        .def("desc", &PyDbUCSTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUCSTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUCSTableRecord::cast).staticmethod("cast")
        ;
}

PyDbUCSTableRecord::PyDbUCSTableRecord()
    : PyDbSymbolTableRecord(new AcDbUCSTableRecord(), true)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(AcDbUCSTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbUCSTableRecord>(id,mode), false)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(const PyDbObjectId& id)
    : PyDbUCSTableRecord(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbUCSTableRecord::origin() const
{
    return impObj()->origin();
}

void PyDbUCSTableRecord::setOrigin(const AcGePoint3d& newOrigin)
{
    return impObj()->setOrigin(newOrigin);
}

AcGeVector3d PyDbUCSTableRecord::xAxis() const
{
    return impObj()->xAxis();
}

void PyDbUCSTableRecord::setXAxis(const AcGeVector3d& xAxis)
{
    return impObj()->setXAxis(xAxis);
}

AcGeVector3d PyDbUCSTableRecord::yAxis() const
{
    return impObj()->yAxis();
}

void PyDbUCSTableRecord::setYAxis(const AcGeVector3d& yAxis)
{
    return impObj()->setXAxis(yAxis);
}

AcGePoint3d PyDbUCSTableRecord::ucsBaseOrigin(AcDb::OrthographicView view) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->ucsBaseOrigin(view);
#endif
}

void PyDbUCSTableRecord::setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsBaseOrigin(origin, view));
#endif
}

std::string PyDbUCSTableRecord::className()
{
    return "AcDbUCSTableRecord";
}

PyRxClass PyDbUCSTableRecord::desc()
{
    return PyRxClass(AcDbUCSTableRecord::desc(), false);
}

PyDbUCSTableRecord PyDbUCSTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbUCSTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUCSTableRecord(static_cast<AcDbUCSTableRecord*>(src.impObj()->clone()), true);
}

PyDbUCSTableRecord PyDbUCSTableRecord::cast(const PyRxObject& src)
{
    PyDbUCSTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbUCSTableRecord* PyDbUCSTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbUCSTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbRegAppTableRecord
void makePyDbRegAppTableRecordWrapper()
{
    PyDocString DS("RegAppTableRecord");
    class_<PyDbRegAppTableRecord, bases<PyDbSymbolTableRecord>>("RegAppTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRegAppTableRecord::className).staticmethod("className")
        .def("desc", &PyDbRegAppTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRegAppTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRegAppTableRecord::cast).staticmethod("cast")
        ;
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord()
    : PyDbSymbolTableRecord(new AcDbRegAppTableRecord(), true)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(AcDbRegAppTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbRegAppTableRecord>(id,mode), false)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(const PyDbObjectId& id)
    : PyDbRegAppTableRecord(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbRegAppTableRecord::className()
{
    return "AcDbRegAppTableRecord";
}

PyRxClass PyDbRegAppTableRecord::desc()
{
    return PyRxClass(AcDbRegAppTableRecord::desc(), false);
}

PyDbRegAppTableRecord PyDbRegAppTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRegAppTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRegAppTableRecord(static_cast<AcDbRegAppTableRecord*>(src.impObj()->clone()), true);
}

PyDbRegAppTableRecord PyDbRegAppTableRecord::cast(const PyRxObject& src)
{
    PyDbRegAppTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRegAppTableRecord* PyDbRegAppTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbRegAppTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbLinetypeTableRecord
void makePyDbLinetypeTableRecordWrapper()
{
    PyDocString DS("LinetypeTableRecord");
    class_<PyDbLinetypeTableRecord, bases<PyDbSymbolTableRecord>>("LinetypeTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("comments", &PyDbLinetypeTableRecord::comments)
        .def("setComments", &PyDbLinetypeTableRecord::setComments)
        .def("patternLength", &PyDbLinetypeTableRecord::patternLength)
        .def("setPatternLength", &PyDbLinetypeTableRecord::setPatternLength)
        .def("numDashes", &PyDbLinetypeTableRecord::numDashes)
        .def("setNumDashes", &PyDbLinetypeTableRecord::setNumDashes)
        .def("dashLengthAt", &PyDbLinetypeTableRecord::dashLengthAt)
        .def("setDashLengthAt", &PyDbLinetypeTableRecord::setDashLengthAt)
        .def("shapeStyleAt", &PyDbLinetypeTableRecord::shapeStyleAt)
        .def("setShapeStyleAt", &PyDbLinetypeTableRecord::setShapeStyleAt)
        .def("shapeNumberAt", &PyDbLinetypeTableRecord::shapeNumberAt)
        .def("setShapeNumberAt", &PyDbLinetypeTableRecord::setShapeNumberAt)
        .def("shapeOffsetAt", &PyDbLinetypeTableRecord::shapeOffsetAt)
        .def("setShapeOffsetAt", &PyDbLinetypeTableRecord::setShapeOffsetAt)
        .def("shapeScaleAt", &PyDbLinetypeTableRecord::shapeScaleAt)
        .def("setShapeScaleAt", &PyDbLinetypeTableRecord::setShapeScaleAt)
        .def("isScaledToFit", &PyDbLinetypeTableRecord::isScaledToFit)
        .def("setIsScaledToFit", &PyDbLinetypeTableRecord::setIsScaledToFit)
        .def("shapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::shapeIsUcsOrientedAt)
        .def("setShapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::setShapeIsUcsOrientedAt)
        .def("shapeIsUprightAt", &PyDbLinetypeTableRecord::shapeIsUprightAt)
        .def("setShapeIsUprightAt", &PyDbLinetypeTableRecord::setShapeIsUprightAt)
        .def("shapeRotationAt", &PyDbLinetypeTableRecord::shapeRotationAt)
        .def("setShapeRotationAt", &PyDbLinetypeTableRecord::setShapeRotationAt)
        .def("textAt", &PyDbLinetypeTableRecord::textAt)
        .def("setTextAt", &PyDbLinetypeTableRecord::setTextAt)
        .def("className", &PyDbLinetypeTableRecord::className).staticmethod("className")
        .def("desc", &PyDbLinetypeTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLinetypeTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLinetypeTableRecord::cast).staticmethod("cast")
        ;
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord()
    : PyDbSymbolTableRecord(new AcDbLinetypeTableRecord(), true)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(AcDbLinetypeTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLinetypeTableRecord>(id,mode), false)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id)
    : PyDbLinetypeTableRecord(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbLinetypeTableRecord::comments() const
{
    const wchar_t* val = nullptr;
    if (auto es = impObj()->comments(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

void PyDbLinetypeTableRecord::setComments(const std::string& pstring)
{
    return PyThrowBadEs(impObj()->setComments(utf8_to_wstr(pstring).c_str()));
}

double PyDbLinetypeTableRecord::patternLength() const
{
    return impObj()->patternLength();
}

void PyDbLinetypeTableRecord::setPatternLength(double patternLength)
{
    return PyThrowBadEs(impObj()->setPatternLength(patternLength));
}

int PyDbLinetypeTableRecord::numDashes() const
{
    return impObj()->numDashes();
}

void PyDbLinetypeTableRecord::setNumDashes(int count)
{
    return PyThrowBadEs(impObj()->setNumDashes(count));
}

double PyDbLinetypeTableRecord::dashLengthAt(int index) const
{
    return impObj()->dashLengthAt(index);
}

void PyDbLinetypeTableRecord::setDashLengthAt(int index, double value)
{
    return PyThrowBadEs(impObj()->setDashLengthAt(index, value));
}

PyDbObjectId PyDbLinetypeTableRecord::shapeStyleAt(int index) const
{
    return PyDbObjectId(impObj()->shapeStyleAt(index));
}

void PyDbLinetypeTableRecord::setShapeStyleAt(int index, PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setShapeStyleAt(index, id.m_id));
}

int PyDbLinetypeTableRecord::shapeNumberAt(int index) const
{
    return impObj()->shapeNumberAt(index);
}

void PyDbLinetypeTableRecord::setShapeNumberAt(int index, int shapeNumber)
{
    return PyThrowBadEs(impObj()->setShapeNumberAt(index, shapeNumber));
}

AcGeVector2d PyDbLinetypeTableRecord::shapeOffsetAt(int index) const
{
    return impObj()->shapeOffsetAt(index);
}

void PyDbLinetypeTableRecord::setShapeOffsetAt(int index, const AcGeVector2d& offset)
{
    return PyThrowBadEs(impObj()->setShapeOffsetAt(index, offset));
}

double PyDbLinetypeTableRecord::shapeScaleAt(int index) const
{
    return impObj()->shapeScaleAt(index);
}

void PyDbLinetypeTableRecord::setShapeScaleAt(int index, double scale)
{
    return PyThrowBadEs(impObj()->setShapeScaleAt(index, scale));
}

bool PyDbLinetypeTableRecord::isScaledToFit() const
{
    return impObj()->isScaledToFit();
}

void PyDbLinetypeTableRecord::setIsScaledToFit(bool scaledToFit)
{
    return impObj()->setIsScaledToFit(scaledToFit);
}

bool PyDbLinetypeTableRecord::shapeIsUcsOrientedAt(int index) const
{
    return impObj()->shapeIsUcsOrientedAt(index);
}

void PyDbLinetypeTableRecord::setShapeIsUcsOrientedAt(int index, bool isUcsOriented)
{
    return PyThrowBadEs(impObj()->setShapeIsUcsOrientedAt(index, isUcsOriented));
}

bool PyDbLinetypeTableRecord::shapeIsUprightAt(int index) const
{
    return impObj()->shapeIsUprightAt(index);
}

void PyDbLinetypeTableRecord::setShapeIsUprightAt(int index, bool isUpright)
{
    return PyThrowBadEs(impObj()->setShapeIsUprightAt(index, isUpright));
}

double PyDbLinetypeTableRecord::shapeRotationAt(int index) const
{
    return impObj()->shapeRotationAt(index);
}

void PyDbLinetypeTableRecord::setShapeRotationAt(int index, double rotation)
{
    return PyThrowBadEs(impObj()->setShapeRotationAt(index, rotation));
}

std::string PyDbLinetypeTableRecord::textAt(int index)
{
    const wchar_t* val = nullptr;
    if (auto es = impObj()->textAt(index, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

void PyDbLinetypeTableRecord::setTextAt(int index, const std::string& pstring)
{
    return PyThrowBadEs(impObj()->setTextAt(index, utf8_to_wstr(pstring).c_str()));
}

std::string PyDbLinetypeTableRecord::className()
{
    return "AcDbLinetypeTableRecord";
}

PyRxClass PyDbLinetypeTableRecord::desc()
{
    return PyRxClass(AcDbLinetypeTableRecord::desc(), false);
}

PyDbLinetypeTableRecord PyDbLinetypeTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbLinetypeTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLinetypeTableRecord(static_cast<AcDbLinetypeTableRecord*>(src.impObj()->clone()), true);
}

PyDbLinetypeTableRecord PyDbLinetypeTableRecord::cast(const PyRxObject& src)
{
    PyDbLinetypeTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLinetypeTableRecord* PyDbLinetypeTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbLinetypeTableRecord*>(m_pyImp.get());
}
