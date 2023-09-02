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
    : PyDbObject(openAcDbObject<AcDbSymbolTableRecord>(id, mode), false)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    PyThrowBadEs(impObj()->getName(arxName));
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
    return impObj()->isRenamable();
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
        .def("className", &PyDbDimStyleTableRecord::className,DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimStyleTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbDimStyleTableRecord>(id, mode), false)
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
        .def("centerPoint", &PyDbAbstractViewTableRecord::centerPoint, DS.ARGS())
        .def("setCenterPoint", &PyDbAbstractViewTableRecord::setCenterPoint, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("height", &PyDbAbstractViewTableRecord::height, DS.ARGS())
        .def("setHeight", &PyDbAbstractViewTableRecord::setHeight, DS.ARGS({ "val : real" }))
        .def("width", &PyDbAbstractViewTableRecord::width, DS.ARGS())
        .def("setWidth", &PyDbAbstractViewTableRecord::setWidth, DS.ARGS({ "val : real" }))
        .def("target", &PyDbAbstractViewTableRecord::target, DS.ARGS())
        .def("setTarget", &PyDbAbstractViewTableRecord::setTarget, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("viewDirection", &PyDbAbstractViewTableRecord::viewDirection, DS.ARGS())
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection1)
        .def("viewTwist", &PyDbAbstractViewTableRecord::viewTwist, DS.ARGS())
        .def("setViewTwist", &PyDbAbstractViewTableRecord::setViewTwist, DS.ARGS({ "val : real" }))
        .def("lensLength", &PyDbAbstractViewTableRecord::lensLength, DS.ARGS())
        .def("setLensLength", &PyDbAbstractViewTableRecord::setLensLength, DS.ARGS({ "val : real" }))
        .def("frontClipDistance", &PyDbAbstractViewTableRecord::frontClipDistance, DS.ARGS())
        .def("setFrontClipDistance", &PyDbAbstractViewTableRecord::setFrontClipDistance, DS.ARGS({ "val : real" }))
        .def("backClipDistance", &PyDbAbstractViewTableRecord::backClipDistance, DS.ARGS())
        .def("setBackClipDistance", &PyDbAbstractViewTableRecord::setBackClipDistance, DS.ARGS({ "val : real" }))
        .def("perspectiveEnabled", &PyDbAbstractViewTableRecord::perspectiveEnabled, DS.ARGS())
        .def("setPerspectiveEnabled", &PyDbAbstractViewTableRecord::setPerspectiveEnabled, DS.ARGS({ "val : bool" }))
        .def("frontClipEnabled", &PyDbAbstractViewTableRecord::frontClipEnabled, DS.ARGS())
        .def("setFrontClipEnabled", &PyDbAbstractViewTableRecord::setFrontClipEnabled, DS.ARGS({ "val : bool" }))
        .def("backClipEnabled", &PyDbAbstractViewTableRecord::backClipEnabled, DS.ARGS())
        .def("setBackClipEnabled", &PyDbAbstractViewTableRecord::setBackClipEnabled, DS.ARGS({ "val : bool" }))
        .def("frontClipAtEye", &PyDbAbstractViewTableRecord::frontClipAtEye, DS.ARGS())
        .def("setFrontClipAtEye", &PyDbAbstractViewTableRecord::setFrontClipAtEye, DS.ARGS({ "val : bool" }))
        .def("background", &PyDbAbstractViewTableRecord::background, DS.ARGS())
        .def("setBackground", &PyDbAbstractViewTableRecord::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("visualStyle", &PyDbAbstractViewTableRecord::visualStyle, DS.ARGS())
        .def("setVisualStyle", &PyDbAbstractViewTableRecord::setVisualStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("isDefaultLightingOn", &PyDbAbstractViewTableRecord::isDefaultLightingOn, DS.ARGS())
        .def("setDefaultLightingOn", &PyDbAbstractViewTableRecord::setDefaultLightingOn, DS.ARGS({ "val : bool" }))
        .def("defaultLightingType", &PyDbAbstractViewTableRecord::defaultLightingType, DS.ARGS())
        .def("setDefaultLightingType", &PyDbAbstractViewTableRecord::setDefaultLightingType)
        .def("brightness", &PyDbAbstractViewTableRecord::brightness, DS.ARGS())
        .def("setBrightness", &PyDbAbstractViewTableRecord::setBrightness, DS.ARGS({ "val : real" }))
        .def("contrast", &PyDbAbstractViewTableRecord::contrast, DS.ARGS())
        .def("setContrast", &PyDbAbstractViewTableRecord::setContrast, DS.ARGS({ "val : real" }))
        .def("ambientLightColor", &PyDbAbstractViewTableRecord::ambientLightColor, DS.ARGS())
        .def("setAmbientLightColor", &PyDbAbstractViewTableRecord::setAmbientLightColor, DS.ARGS({ "val : PyDb.Color" }))
        .def("sunId", &PyDbAbstractViewTableRecord::sunId, DS.ARGS())
        .def("setSun", &PyDbAbstractViewTableRecord::setSun1)
        .def("setSun", &PyDbAbstractViewTableRecord::setSun2, DS.ARGS({ "retId : PyDb.ObjectId","pSun : PyDb.Object","eraseOldSun : bool=True" }))
        .def("getUcs", &PyDbAbstractViewTableRecord::getUcs, DS.ARGS())
        .def("isUcsOrthographic", &PyDbAbstractViewTableRecord::isUcsOrthographic, DS.ARGS())
        .def("ucsName", &PyDbAbstractViewTableRecord::ucsName, DS.ARGS())
        .def("elevation", &PyDbAbstractViewTableRecord::elevation, DS.ARGS())
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs1)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs2)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs3)
        .def("setUcsToWorld", &PyDbAbstractViewTableRecord::setUcsToWorld, DS.ARGS())
        .def("setElevation", &PyDbAbstractViewTableRecord::setElevation, DS.ARGS({ "val : real" }))
        .def("isViewOrthographic", &PyDbAbstractViewTableRecord::isViewOrthographic, DS.ARGS())
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection2)
        .def("className", &PyDbAbstractViewTableRecord::className,DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAbstractViewTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbAbstractViewTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAbstractViewTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbAbstractViewTableRecord>(id, mode), false)
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
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
}

boost::python::tuple PyDbAbstractViewTableRecord::getUcs() const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d xAxis; 
    AcGeVector3d yAxis;
    PyThrowBadEs(impObj()->getUcs(origin, xAxis, yAxis));
    return boost::python::make_tuple(origin, xAxis, yAxis);
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
        .def("number", &PyDbViewportTableRecord::number, DS.ARGS())
        .def("lowerLeftCorner", &PyDbViewportTableRecord::lowerLeftCorner, DS.ARGS())
        .def("setLowerLeftCorner", &PyDbViewportTableRecord::setLowerLeftCorner, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("upperRightCorner", &PyDbViewportTableRecord::upperRightCorner, DS.ARGS())
        .def("setUpperRightCorner", &PyDbViewportTableRecord::setUpperRightCorner, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("ucsFollowMode", &PyDbViewportTableRecord::ucsFollowMode, DS.ARGS())
        .def("setUcsFollowMode", &PyDbViewportTableRecord::setUcsFollowMode, DS.ARGS({ "val : bool" }))
        .def("circleSides", &PyDbViewportTableRecord::circleSides, DS.ARGS())
        .def("setCircleSides", &PyDbViewportTableRecord::setCircleSides, DS.ARGS({ "val : int" }))
        .def("fastZoomsEnabled", &PyDbViewportTableRecord::fastZoomsEnabled, DS.ARGS())
        .def("setFastZoomsEnabled", &PyDbViewportTableRecord::setFastZoomsEnabled, DS.ARGS({ "val : bool" }))
        .def("iconEnabled", &PyDbViewportTableRecord::iconEnabled, DS.ARGS())
        .def("setIconEnabled", &PyDbViewportTableRecord::setIconEnabled, DS.ARGS({ "val : bool" }))
        .def("iconAtOrigin", &PyDbViewportTableRecord::iconAtOrigin, DS.ARGS())
        .def("setIconAtOrigin", &PyDbViewportTableRecord::setIconAtOrigin, DS.ARGS({ "val : bool" }))
        .def("gridEnabled", &PyDbViewportTableRecord::gridEnabled, DS.ARGS())
        .def("setGridEnabled", &PyDbViewportTableRecord::setGridEnabled, DS.ARGS({ "val : bool" }))
        .def("gridIncrements", &PyDbViewportTableRecord::gridIncrements, DS.ARGS())
        .def("setGridIncrements", &PyDbViewportTableRecord::setGridIncrements, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("snapEnabled", &PyDbViewportTableRecord::snapEnabled, DS.ARGS())
        .def("setSnapEnabled", &PyDbViewportTableRecord::setSnapEnabled, DS.ARGS({ "val : bool" }))
        .def("isometricSnapEnabled", &PyDbViewportTableRecord::isometricSnapEnabled, DS.ARGS())
        .def("setIsometricSnapEnabled", &PyDbViewportTableRecord::setIsometricSnapEnabled, DS.ARGS({ "val : bool" }))
        .def("snapPair", &PyDbViewportTableRecord::snapPair, DS.ARGS())
        .def("setSnapPair", &PyDbViewportTableRecord::setSnapPair, DS.ARGS({ "val : int" }))
        .def("snapAngle", &PyDbViewportTableRecord::snapAngle, DS.ARGS())
        .def("setSnapAngle", &PyDbViewportTableRecord::setSnapAngle, DS.ARGS({ "val : real" }))
        .def("snapBase", &PyDbViewportTableRecord::snapBase, DS.ARGS())
        .def("setSnapBase", &PyDbViewportTableRecord::setSnapBase, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("snapIncrements", &PyDbViewportTableRecord::snapIncrements, DS.ARGS())
        .def("setSnapIncrements", &PyDbViewportTableRecord::setSnapIncrements, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("isUcsSavedWithViewport", &PyDbViewportTableRecord::isUcsSavedWithViewport, DS.ARGS())
        .def("setUcsPerViewport", &PyDbViewportTableRecord::setUcsPerViewport, DS.ARGS({ "val : bool" }))
        .def("isGridBoundToLimits", &PyDbViewportTableRecord::isGridBoundToLimits, DS.ARGS())
        .def("setGridBoundToLimits", &PyDbViewportTableRecord::setGridBoundToLimits, DS.ARGS({ "val : bool" }))
        .def("isGridAdaptive", &PyDbViewportTableRecord::isGridAdaptive, DS.ARGS())
        .def("setGridAdaptive", &PyDbViewportTableRecord::setGridAdaptive, DS.ARGS({ "val : bool" }))
        .def("isGridSubdivisionRestricted", &PyDbViewportTableRecord::isGridSubdivisionRestricted, DS.ARGS())
        .def("setGridSubdivisionRestricted", &PyDbViewportTableRecord::setGridSubdivisionRestricted, DS.ARGS({ "val : bool" }))
        .def("isGridFollow", &PyDbViewportTableRecord::isGridFollow, DS.ARGS())
        .def("setGridFollow", &PyDbViewportTableRecord::setGridFollow, DS.ARGS({ "val : bool" }))
        .def("gridMajor", &PyDbViewportTableRecord::gridMajor, DS.ARGS())
        .def("setGridMajor", &PyDbViewportTableRecord::setGridMajor, DS.ARGS({ "val : int" }))
        .def("setBackground", &PyDbViewportTableRecord::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground1)
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground2)
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground2)
        .def("previousBackgroundForcedSwitch", &PyDbViewportTableRecord::previousBackgroundForcedSwitch, DS.ARGS())
        .def("className", &PyDbViewportTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewportTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbViewportTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewportTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewportTableRecord>(id, mode), false)
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
    return impObj()->isGridBoundToLimits();
}

void PyDbViewportTableRecord::setGridBoundToLimits(bool enabled)
{
    return impObj()->setGridBoundToLimits(enabled);
}

bool PyDbViewportTableRecord::isGridAdaptive() const
{
    return impObj()->isGridAdaptive();
}

void PyDbViewportTableRecord::setGridAdaptive(bool enabled)
{
    return impObj()->setGridAdaptive(enabled);
}

bool PyDbViewportTableRecord::isGridSubdivisionRestricted() const
{
    return impObj()->isGridSubdivisionRestricted();
}

void PyDbViewportTableRecord::setGridSubdivisionRestricted(bool enabled)
{
    return impObj()->setGridSubdivisionRestricted(enabled);
}

bool PyDbViewportTableRecord::isGridFollow() const
{
    return impObj()->isGridFollow();
}

void PyDbViewportTableRecord::setGridFollow(bool enabled)
{
    return impObj()->setGridFollow(enabled);
}

Adesk::Int16 PyDbViewportTableRecord::gridMajor() const
{
    return impObj()->gridMajor();
}

void PyDbViewportTableRecord::setGridMajor(Adesk::Int16 value)
{
    return impObj()->setGridMajor(value);
}

void PyDbViewportTableRecord::setBackground(const PyDbObjectId& backgroundId)
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbViewportTableRecord::previousBackground1() const
{
    return PyDbObjectId(impObj()->previousBackground());
}

PyDbObjectId PyDbViewportTableRecord::previousBackground2(AcGiDrawable::DrawableType type) const
{
    return PyDbObjectId(impObj()->previousBackground(type));
}

void PyDbViewportTableRecord::setPreviousBackground1(PyDbObjectId& backgroundId)
{
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
}

void PyDbViewportTableRecord::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch)
{
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, bForcedSwitch));
}

bool PyDbViewportTableRecord::previousBackgroundForcedSwitch(void) const
{
    return impObj()->previousBackgroundForcedSwitch();
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
        .def("annotationScale", &PyDbViewTableRecord::annotationScale, DS.ARGS())
        .def("setAnnotationScale", &PyDbViewTableRecord::setAnnotationScale)
        .def("setParametersFromViewport", &PyDbViewTableRecord::setParametersFromViewport)
        .def("isPaperspaceView", &PyDbViewTableRecord::isPaperspaceView, DS.ARGS())
        .def("setIsPaperspaceView", &PyDbViewTableRecord::setIsPaperspaceView, DS.ARGS({ "val : bool" }))
        .def("isUcsAssociatedToView", &PyDbViewTableRecord::isUcsAssociatedToView, DS.ARGS())
        .def("disassociateUcsFromView", &PyDbViewTableRecord::disassociateUcsFromView, DS.ARGS())
        .def("getCategoryName", &PyDbViewTableRecord::getCategoryName, DS.ARGS())
        .def("setCategoryName", &PyDbViewTableRecord::setCategoryName, DS.ARGS({ "val : str" }))
        .def("getLayerState", &PyDbViewTableRecord::getLayerState, DS.ARGS())
        .def("setLayerState", &PyDbViewTableRecord::setLayerState, DS.ARGS({ "val : str" }))
        .def("getLayout", &PyDbViewTableRecord::getLayout, DS.ARGS())
        .def("setLayout", &PyDbViewTableRecord::setLayout, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("isViewAssociatedToViewport", &PyDbViewTableRecord::isViewAssociatedToViewport, DS.ARGS())
        .def("setViewAssociatedToViewport", &PyDbViewTableRecord::setViewAssociatedToViewport, DS.ARGS({ "val : bool" }))
        .def("isCameraPlottable", &PyDbViewTableRecord::isCameraPlottable, DS.ARGS())
        .def("setIsCameraPlottable", &PyDbViewTableRecord::setIsCameraPlottable, DS.ARGS({ "val : bool" }))
        .def("liveSection", &PyDbViewTableRecord::liveSection, DS.ARGS())
        .def("setLiveSection", &PyDbViewTableRecord::setLiveSection, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("camera", &PyDbViewTableRecord::camera, DS.ARGS())
        .def("setCamera", &PyDbViewTableRecord::setCamera, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("sunId", &PyDbViewTableRecord::sunId, DS.ARGS())
        .def("setSun", &PyDbViewTableRecord::setSun1)
        .def("setSun", &PyDbViewTableRecord::setSun2, DS.ARGS({ "retId : PyDb.ObjectId","pSun : PyDb.Object","eraseOldSun : bool=True" }))
        .def("className", &PyDbViewTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbViewTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewTableRecord>(id, mode), false)
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
    AcString str;
    PyThrowBadEs(impObj()->getCategoryName(str));
    return wstr_to_utf8(str);
}

void PyDbViewTableRecord::setCategoryName(const std::string& categoryName)
{
    return PyThrowBadEs(impObj()->setCategoryName(utf8_to_wstr(categoryName).c_str()));
}

std::string PyDbViewTableRecord::getLayerState() const
{
    AcString str;
    PyThrowBadEs(impObj()->getLayerState(str));
    return wstr_to_utf8(str);
}

void PyDbViewTableRecord::setLayerState(const std::string& layerStateName)
{
    return PyThrowBadEs(impObj()->setLayerState(utf8_to_wstr(layerStateName).c_str()));
}

PyDbObjectId PyDbViewTableRecord::getLayout() const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getLayout(id.m_id));
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
    return PyDbObjectId(impObj()->liveSection());
}

void PyDbViewTableRecord::setLiveSection(const PyDbObjectId& liveSectionId)
{
    return PyThrowBadEs(impObj()->setLiveSection(liveSectionId.m_id));
}

PyDbObjectId PyDbViewTableRecord::camera() const
{
    return PyDbObjectId(impObj()->camera());
}

void PyDbViewTableRecord::setCamera(const PyDbObjectId& cameraId)
{
    return PyThrowBadEs(impObj()->setCamera(cameraId.m_id));
}

PyDbAnnotationScale PyDbViewTableRecord::annotationScale() const
{
    return PyDbAnnotationScale(impObj()->annotationScale());
}

void PyDbViewTableRecord::setAnnotationScale(const PyDbAnnotationScale& pScaleObj)
{
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
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
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
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
        .def("objectIds", &PyDbBlockTableRecord::objectIdsOfType, DS.ARGS({ "desc:PyRx.RxClass=AcDbEntity" }))
        .def("comments", &PyDbBlockTableRecord::comments, DS.ARGS())
        .def("setComments", &PyDbBlockTableRecord::setComments, DS.ARGS({ "val : str" }))
        .def("pathName", &PyDbBlockTableRecord::pathName, DS.ARGS())
        .def("setPathName", &PyDbBlockTableRecord::setPathName, DS.ARGS({ "val : str" }))
        .def("origin", &PyDbBlockTableRecord::origin, DS.ARGS())
        .def("setOrigin", &PyDbBlockTableRecord::setOrigin, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("openBlockBegin", &PyDbBlockTableRecord::openBlockBegin)
        .def("openBlockEnd", &PyDbBlockTableRecord::openBlockEnd)
        .def("hasAttributeDefinitions", &PyDbBlockTableRecord::hasAttributeDefinitions, DS.ARGS())
        .def("hasPreviewIcon", &PyDbBlockTableRecord::hasPreviewIcon, DS.ARGS())
        .def("getPreviewIcon", &PyDbBlockTableRecord::getPreviewIcon, DS.ARGS())
        .def("clearPreviewIcon", &PyDbBlockTableRecord::clearPreviewIcon, DS.ARGS())
        .def("isAnonymous", &PyDbBlockTableRecord::isAnonymous, DS.ARGS())
        .def("isFromExternalReference", &PyDbBlockTableRecord::isFromExternalReference, DS.ARGS())
        .def("isFromOverlayReference", &PyDbBlockTableRecord::isFromOverlayReference, DS.ARGS())
        .def("setIsFromOverlayReference", &PyDbBlockTableRecord::setIsFromOverlayReference, DS.ARGS({ "val : bool" }))
        .def("isLayout", &PyDbBlockTableRecord::isLayout, DS.ARGS())
        .def("getLayoutId", &PyDbBlockTableRecord::getLayoutId, DS.ARGS())
        .def("setLayoutId", &PyDbBlockTableRecord::setLayoutId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds1)
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds2)
        .def("getErasedBlockReferenceIds", &PyDbBlockTableRecord::getErasedBlockReferenceIds, DS.ARGS())
        .def("xrefDatabase", &PyDbBlockTableRecord::xrefDatabase, DS.ARGS({ "val : bool" }))
        .def("isUnloaded", &PyDbBlockTableRecord::isUnloaded, DS.ARGS())
        .def("setIsUnloaded", &PyDbBlockTableRecord::setIsUnloaded, DS.ARGS({ "val : bool" }))
        .def("xrefStatus", &PyDbBlockTableRecord::xrefStatus, DS.ARGS())
        .def("assumeOwnershipOf", &PyDbBlockTableRecord::assumeOwnershipOf, DS.ARGS({ "entities : list[PyDb.Entity]" }))
        .def("blockScaling", &PyDbBlockTableRecord::blockScaling, DS.ARGS())
        .def("setBlockScaling", &PyDbBlockTableRecord::setBlockScaling)
        .def("setExplodable", &PyDbBlockTableRecord::setExplodable, DS.ARGS({ "val : bool" }))
        .def("explodable", &PyDbBlockTableRecord::explodable, DS.ARGS())
        .def("setBlockInsertUnits", &PyDbBlockTableRecord::setBlockInsertUnits)
        .def("blockInsertUnits", &PyDbBlockTableRecord::blockInsertUnits, DS.ARGS())
        .def("postProcessAnnotativeBTR", &PyDbBlockTableRecord::postProcessAnnotativeBTR)
        .def("addAnnoScalestoBlkRefs", &PyDbBlockTableRecord::addAnnoScalestoBlkRefs, DS.ARGS({ "scale : bool" }))
        .def("className", &PyDbBlockTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbBlockTableRecord>(id, mode), false)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id)
    : PyDbBlockTableRecord(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->appendAcDbEntity(id.m_id, ent.impObj()));
    return id;
}

boost::python::list PyDbBlockTableRecord::objectIds()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es != eOk)
        return pyList;

    PyDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (iter->getEntityId(id.m_id) == eOk)
            pyList.append(id);
    }
    return pyList;
}

boost::python::list PyDbBlockTableRecord::objectIdsOfType(const PyRxClass& _class)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto _desc = _class.impObj();
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es != eOk)
        return pyList;

    PyDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (const auto es = iter->getEntityId(id.m_id); es == eOk && id.m_id.objectClass()->isDerivedFrom(_desc))
            pyList.append(id);
    }
    return pyList;
}

std::string PyDbBlockTableRecord::comments()
{
    AcString str;
    impObj()->comments(str);
    return wstr_to_utf8(str);
}

void PyDbBlockTableRecord::setComments(const std::string& pString)
{
    return PyThrowBadEs(impObj()->setComments(utf8_to_wstr(pString).c_str()));
}

std::string PyDbBlockTableRecord::pathName()
{
    AcString str;
    impObj()->pathName(str);
    return wstr_to_utf8(str);
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
    return PyThrowBadEs(impObj()->setIsFromOverlayReference(bIsOverlay));
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
    AcDbObjectIdArray ids;
    impObj()->getBlockReferenceIds(ids);
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity)
{
    AcDbObjectIdArray ids;
    impObj()->getBlockReferenceIds(ids, bDirectOnly, bForceValidity);
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbBlockTableRecord::getErasedBlockReferenceIds()
{
    AcDbObjectIdArray ids;
    impObj()->getErasedBlockReferenceIds(ids);
    return ObjectIdArrayToPyList(ids);
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
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids = PyListToObjectIdArray(entitiesToMove);
    return PyThrowBadEs(impObj()->assumeOwnershipOf(ids));
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
    PyThrowBadEs(impObj()->postProcessAnnotativeBTR(stripCnt, bqueryOnly, bScale));
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
        .def("isFrozen", &PyDbLayerTableRecord::isFrozen, DS.ARGS())
        .def("setIsFrozen", &PyDbLayerTableRecord::setIsFrozen)
        .def("isOff", &PyDbLayerTableRecord::isOff, DS.ARGS())
        .def("setIsOff", &PyDbLayerTableRecord::setIsOff)
        .def("VPDFLT", &PyDbLayerTableRecord::VPDFLT, DS.ARGS())
        .def("setVPDFLT", &PyDbLayerTableRecord::setVPDFLT)
        .def("isLocked", &PyDbLayerTableRecord::isLocked, DS.ARGS())
        .def("setIsLocked", &PyDbLayerTableRecord::setIsLocked)
        .def("color", &PyDbLayerTableRecord::color1)
        .def("color", &PyDbLayerTableRecord::color2)
        .def("setColor", &PyDbLayerTableRecord::setColor1)
        .def("setColor", &PyDbLayerTableRecord::setColor2)
        .def("entityColor", &PyDbLayerTableRecord::entityColor, DS.ARGS())
        .def("transparency", &PyDbLayerTableRecord::transparency1)
        .def("transparency", &PyDbLayerTableRecord::transparency2)
        .def("setTransparency", &PyDbLayerTableRecord::setTransparency1)
        .def("setTransparency", &PyDbLayerTableRecord::setTransparency2)
        .def("linetypeObjectId", &PyDbLayerTableRecord::linetypeObjectId)
        .def("setLinetypeObjectId", &PyDbLayerTableRecord::setLinetypeObjectId)
        .def("materialId", &PyDbLayerTableRecord::materialId, DS.ARGS())
        .def("setMaterialId", &PyDbLayerTableRecord::setMaterialId)
        .def("isPlottable", &PyDbLayerTableRecord::isPlottable, DS.ARGS())
        .def("setIsPlottable", &PyDbLayerTableRecord::setIsPlottable)
        .def("lineWeight", &PyDbLayerTableRecord::lineWeight1)
        .def("lineWeight", &PyDbLayerTableRecord::lineWeight2)
        .def("setLineWeight", &PyDbLayerTableRecord::setLineWeight1)
        .def("setLineWeight", &PyDbLayerTableRecord::setLineWeight2)
        .def("plotStyleName", &PyDbLayerTableRecord::plotStyleName1)
        .def("plotStyleName", &PyDbLayerTableRecord::plotStyleName2)
        .def("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId1)
        .def("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId2)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName1)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName2)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName3)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName4)
        .def("isInUse", &PyDbLayerTableRecord::isInUse, DS.ARGS())
        .def("description", &PyDbLayerTableRecord::description, DS.ARGS())
        .def("setDescription", &PyDbLayerTableRecord::setDescription)
        .def("setIsHidden", &PyDbLayerTableRecord::setIsHidden)
        .def("isHidden", &PyDbLayerTableRecord::isHidden, DS.ARGS())
        .def("isHiddenS", &PyDbLayerTableRecord::isHiddenS, DS.SARGS()).staticmethod("isHiddenS")//TODO: can't override with a static
        .def("removeColorOverride", &PyDbLayerTableRecord::removeColorOverride)
        .def("removeLinetypeOverride", &PyDbLayerTableRecord::removeLinetypeOverride)
        .def("removeLineWeightOverride", &PyDbLayerTableRecord::removeLineWeightOverride)
        .def("removePlotStyleOverride", &PyDbLayerTableRecord::removePlotStyleOverride)
        .def("removeTransparencyOverride", &PyDbLayerTableRecord::removeTransparencyOverride)
        .def("removeViewportOverrides", &PyDbLayerTableRecord::removeViewportOverrides)
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides)
        .def("hasOverrides", &PyDbLayerTableRecord::hasOverrides)
        .def("hasAnyOverrides", &PyDbLayerTableRecord::hasAnyOverrides)
        .def("isReconciled", &PyDbLayerTableRecord::isReconciled, DS.ARGS())
        .def("isReconciledS", &PyDbLayerTableRecord::isReconciledS, DS.SARGS()).staticmethod("isReconciledS")//TODO: can't override with a static test
        .def("className", &PyDbLayerTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLayerTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbLayerTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLayerTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLayerTableRecord>(id, mode), false)
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

AcCmColor PyDbLayerTableRecord::color1() const
{
    return impObj()->color();
}

AcCmColor PyDbLayerTableRecord::color2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->color(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setColor1(const AcCmColor& _color)
{
    return impObj()->setColor(_color);
}

void PyDbLayerTableRecord::setColor2(const AcCmColor& color, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setColor(color, viewportId.m_id));
}

AcCmEntityColor PyDbLayerTableRecord::entityColor(void) const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbLayerTableRecord::transparency1(void) const
{
    return impObj()->transparency();
}

AcCmTransparency PyDbLayerTableRecord::transparency2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->transparency(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setTransparency1(const AcCmTransparency& trans)
{
    return PyThrowBadEs(impObj()->setTransparency(trans));
}

void PyDbLayerTableRecord::setTransparency2(const AcCmTransparency& trans, const PyDbObjectId& viewportId)
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
    return PyThrowBadEs(impObj()->setLinetypeObjectId(id.m_id));
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

AcDb::LineWeight PyDbLayerTableRecord::lineWeight1() const
{
    return impObj()->lineWeight();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->lineWeight(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setLineWeight1(AcDb::LineWeight weight)
{
    return PyThrowBadEs(impObj()->setLineWeight(weight));
}

void PyDbLayerTableRecord::setLineWeight2(AcDb::LineWeight weight, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setLineWeight(weight, viewportId.m_id));
}

std::string PyDbLayerTableRecord::plotStyleName1() const
{
    return wstr_to_utf8(impObj()->plotStyleName());
}

std::string PyDbLayerTableRecord::plotStyleName2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return wstr_to_utf8(impObj()->plotStyleName(viewportId.m_id, flag));
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId1() const
{
    return PyDbObjectId(impObj()->plotStyleNameId());
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return PyDbObjectId(impObj()->plotStyleNameId(viewportId.m_id, flag));
}

void PyDbLayerTableRecord::setPlotStyleName1(const std::string& newName)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str()));
}

void PyDbLayerTableRecord::setPlotStyleName2(const PyDbObjectId& newId)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(newId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName3(const std::string& newName, const PyDbObjectId& viewportId)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str(), viewportId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName4(const PyDbObjectId& newId, const PyDbObjectId& viewportId)
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
        .def("isShapeFile", &PyDbTextStyleTableRecord::isShapeFile, DS.ARGS())
        .def("setIsShapeFile", &PyDbTextStyleTableRecord::setIsShapeFile)
        .def("isVertical", &PyDbTextStyleTableRecord::isVertical, DS.ARGS())
        .def("setIsVertical", &PyDbTextStyleTableRecord::setIsVertical)
        .def("textSize", &PyDbTextStyleTableRecord::textSize, DS.ARGS())
        .def("setTextSize", &PyDbTextStyleTableRecord::setTextSize)
        .def("xScale", &PyDbTextStyleTableRecord::xScale, DS.ARGS())
        .def("setXScale", &PyDbTextStyleTableRecord::setXScale)
        .def("obliquingAngle", &PyDbTextStyleTableRecord::obliquingAngle, DS.ARGS())
        .def("setObliquingAngle", &PyDbTextStyleTableRecord::setObliquingAngle)
        .def("flagBits", &PyDbTextStyleTableRecord::flagBits, DS.ARGS())
        .def("setFlagBits", &PyDbTextStyleTableRecord::setFlagBits)
        .def("priorSize", &PyDbTextStyleTableRecord::priorSize, DS.ARGS())
        .def("setPriorSize", &PyDbTextStyleTableRecord::setPriorSize)
        .def("fileName", &PyDbTextStyleTableRecord::fileName, DS.ARGS())
        .def("setFileName", &PyDbTextStyleTableRecord::setFileName)
        .def("bigFontFileName", &PyDbTextStyleTableRecord::bigFontFileName, DS.ARGS())
        .def("setBigFontFileName", &PyDbTextStyleTableRecord::setBigFontFileName)
        .def("setFont", &PyDbTextStyleTableRecord::setFont)
        .def("font", &PyDbTextStyleTableRecord::font, DS.ARGS())
        .def("className", &PyDbTextStyleTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTextStyleTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbTextStyleTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTextStyleTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbTextStyleTableRecord>(id, mode), false)
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
    AcString path;
    PyThrowBadEs(impObj()->fileName(path));
    return wstr_to_utf8(path);
}

void PyDbTextStyleTableRecord::setFileName(const std::string& path)
{
    return PyThrowBadEs(impObj()->setFileName(utf8_to_wstr(path).c_str()));
}

std::string PyDbTextStyleTableRecord::bigFontFileName()
{
    AcString path;
    PyThrowBadEs(impObj()->bigFontFileName(path));
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
    PyAutoLockGIL lock;
    bool bold = false;
    bool italic = false;
    Charset charset = kAnsiCharset;
    AcString sTypeface;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch = Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family = Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare;
    PyThrowBadEs(impObj()->font(sTypeface, bold, italic, charset, pitch, family));
    std::string tf = wstr_to_utf8(sTypeface);
    return boost::python::make_tuple(tf, bold, italic, (int)charset, (int)pitch, (int)family);
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
        .def("origin", &PyDbUCSTableRecord::origin, DS.ARGS())
        .def("setOrigin", &PyDbUCSTableRecord::setOrigin)
        .def("xAxis", &PyDbUCSTableRecord::xAxis, DS.ARGS())
        .def("setXAxis", &PyDbUCSTableRecord::setXAxis)
        .def("yAxis", &PyDbUCSTableRecord::yAxis, DS.ARGS())
        .def("setYAxis", &PyDbUCSTableRecord::setYAxis)
        .def("ucsBaseOrigin", &PyDbUCSTableRecord::ucsBaseOrigin)
        .def("setUcsBaseOrigin", &PyDbUCSTableRecord::setUcsBaseOrigin)
        .def("className", &PyDbUCSTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUCSTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbUCSTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbUCSTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbUCSTableRecord>(id, mode), false)
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
    return impObj()->ucsBaseOrigin(view);
}

void PyDbUCSTableRecord::setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view)
{
    return PyThrowBadEs(impObj()->setUcsBaseOrigin(origin, view));
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
        .def("className", &PyDbRegAppTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRegAppTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbRegAppTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRegAppTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbRegAppTableRecord>(id, mode), false)
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
        .def("comments", &PyDbLinetypeTableRecord::comments, DS.ARGS())
        .def("setComments", &PyDbLinetypeTableRecord::setComments)
        .def("patternLength", &PyDbLinetypeTableRecord::patternLength, DS.ARGS())
        .def("setPatternLength", &PyDbLinetypeTableRecord::setPatternLength)
        .def("numDashes", &PyDbLinetypeTableRecord::numDashes, DS.ARGS())
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
        .def("isScaledToFit", &PyDbLinetypeTableRecord::isScaledToFit, DS.ARGS())
        .def("setIsScaledToFit", &PyDbLinetypeTableRecord::setIsScaledToFit)
        .def("shapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::shapeIsUcsOrientedAt)
        .def("setShapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::setShapeIsUcsOrientedAt)
        .def("shapeIsUprightAt", &PyDbLinetypeTableRecord::shapeIsUprightAt)
        .def("setShapeIsUprightAt", &PyDbLinetypeTableRecord::setShapeIsUprightAt)
        .def("shapeRotationAt", &PyDbLinetypeTableRecord::shapeRotationAt)
        .def("setShapeRotationAt", &PyDbLinetypeTableRecord::setShapeRotationAt)
        .def("textAt", &PyDbLinetypeTableRecord::textAt)
        .def("setTextAt", &PyDbLinetypeTableRecord::setTextAt)
        .def("className", &PyDbLinetypeTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLinetypeTableRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbLinetypeTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLinetypeTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLinetypeTableRecord>(id, mode), false)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id)
    : PyDbLinetypeTableRecord(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbLinetypeTableRecord::comments() const
{
    const wchar_t* val = nullptr;
    PyThrowBadEs(impObj()->comments(val));
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
    PyThrowBadEs(impObj()->textAt(index, val));
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
