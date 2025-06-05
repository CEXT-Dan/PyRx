#include "stdafx.h"
#include "PyDbSpatialFilter.h"
#include "PyDbObjectId.h"
#include "PyDbEnts.h"

using namespace boost::python;

void makePyDbSpatialFilterWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("SpatialFilter");
    class_<PyDbSpatialFilter, bases<PyDbObject>>("SpatialFilter")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 8701)))
        .def("indexClass", &PyDbSpatialFilter::indexClass, DS.ARGS(8709))
        .def("queryBounds", &PyDbSpatialFilter::queryBounds1)
        .def("queryBounds", &PyDbSpatialFilter::queryBounds2, DS.ARGS({ "ref : PyDb.BlockReference = ..." }, 8711))
        .def("getVolume", &PyDbSpatialFilter::getVolume, DS.ARGS(8707))
        .def("setDefinition", &PyDbSpatialFilter::setDefinition, DS.ARGS({ "pnt2d: list[PyGe.Point2d]","normal: PyGe.Vector3d","elev: float","frontclip: float","backclip: float","enabled: bool" }, 8712))
        .def("getDefinition", &PyDbSpatialFilter::getDefinition, DS.ARGS(8705))
        .def("getClipSpaceToWCSMatrix", &PyDbSpatialFilter::getClipSpaceToWCSMatrix, DS.ARGS(8704))
        .def("getOriginalInverseBlockXform", &PyDbSpatialFilter::getOriginalInverseBlockXform, DS.ARGS(8706))
        .def("setPerspectiveCamera", &PyDbSpatialFilter::setPerspectiveCamera, DS.ARGS({ "val : PyGe.Point3d" }, 8714))
        .def("clipVolumeIntersectsExtents", &PyDbSpatialFilter::clipVolumeIntersectsExtents, DS.ARGS({ "val : PyDb.Extents" }, 8703))
        .def("hasPerspectiveCamera", &PyDbSpatialFilter::hasPerspectiveCamera, DS.ARGS(8708))
        .def("isInverted", &PyDbSpatialFilter::isInverted, DS.ARGS(8710))
        .def("setInverted", &PyDbSpatialFilter::setInverted, DS.ARGS({ "val : bool" }, 8713))
        .def("desc", &PyDbSpatialFilter::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbSpatialFilter::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbSpatialFilter::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSpatialFilter::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSpatialFilter::PyDbSpatialFilter()
    : PyDbSpatialFilter(new AcDbSpatialFilter(), true)
{
}

PyDbSpatialFilter::PyDbSpatialFilter(const PyDbObjectId& id)
    : PyDbSpatialFilter(openAcDbObject<AcDbSpatialFilter>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSpatialFilter::PyDbSpatialFilter(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSpatialFilter(openAcDbObject<AcDbSpatialFilter>(id, mode), false)
{
}

PyDbSpatialFilter::PyDbSpatialFilter(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSpatialFilter(openAcDbObject<AcDbSpatialFilter>(id, mode, erased), false)
{
}

PyDbSpatialFilter::PyDbSpatialFilter(AcDbSpatialFilter* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

#ifdef NEVER
PyDbSpatialFilter::PyDbSpatialFilter(const boost::python::list& pts, const AcGeVector3d& normal, double elevation, double frontClip, double backClip, Adesk::Boolean enabled)
    : PyDbSpatialFilter(new AcDbSpatialFilter(PyListToPoint2dArray(pts), normal, elevation, frontClip, backClip, enabled), true)
{
}
#endif

PyRxClass PyDbSpatialFilter::indexClass() const
{
    return PyRxClass(impObj()->indexClass(), false);
}

AcDbExtents PyDbSpatialFilter::queryBounds1() const
{
    AcDbExtents ext;
    impObj()->queryBounds(ext);
    return ext;
}

AcDbExtents PyDbSpatialFilter::queryBounds2(const PyDbBlockReference& pRefBlkRef) const
{
    AcDbExtents ext;
    impObj()->queryBounds(ext, pRefBlkRef.impObj());
    return ext;
}

boost::python::tuple PyDbSpatialFilter::getVolume() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGePoint3d fromPt;
    AcGePoint3d toPt;
    AcGeVector3d upDir;
    AcGeVector2d viewField;
    PyThrowBadEs(impObj()->getVolume(fromPt, toPt, upDir, viewField));
    return boost::python::make_tuple(fromPt, toPt, upDir, viewField);
#endif
}

void PyDbSpatialFilter::setDefinition(const boost::python::list& pts, const AcGeVector3d& normal, double elevation, double frontClip, double backClip, Adesk::Boolean enabled) const
{
    PyThrowBadEs(impObj()->setDefinition(PyListToPoint2dArray(pts), normal, elevation, frontClip, backClip, enabled));
}

boost::python::tuple PyDbSpatialFilter::getDefinition() const
{
    PyAutoLockGIL lock;
    AcGePoint2dArray pts;
    AcGeVector3d normal;
    double elevation;
    double frontClip;
    double backClip;
    Adesk::Boolean enable;
    PyThrowBadEs(impObj()->getDefinition(pts, normal, elevation, frontClip, backClip, enable));
    return boost::python::make_tuple(Point2dArrayToPyList(pts), normal, elevation, frontClip, backClip, enable);
}

AcGeMatrix3d PyDbSpatialFilter::getClipSpaceToWCSMatrix() const
{
    AcGeMatrix3d mat;
    impObj()->getClipSpaceToWCSMatrix(mat);
    return mat;
}

AcGeMatrix3d PyDbSpatialFilter::getOriginalInverseBlockXform() const
{
    AcGeMatrix3d mat;
    impObj()->getOriginalInverseBlockXform(mat);
    return mat;
}

void PyDbSpatialFilter::setPerspectiveCamera(const AcGePoint3d& fromPt) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setPerspectiveCamera(fromPt));
#endif
}

Adesk::Boolean PyDbSpatialFilter::clipVolumeIntersectsExtents(const AcDbExtents& ext) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->clipVolumeIntersectsExtents(ext);
#endif
}

Adesk::Boolean PyDbSpatialFilter::hasPerspectiveCamera() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->hasPerspectiveCamera();
#endif
}

bool PyDbSpatialFilter::isInverted() const
{
    return impObj()->isInverted();
}

void PyDbSpatialFilter::setInverted(bool bInverted) const
{
    PyThrowBadEs(impObj()->setInverted(bInverted));
}

PyRxClass PyDbSpatialFilter::desc()
{
    return PyRxClass(AcDbSpatialFilter::desc(), false);
}

std::string PyDbSpatialFilter::className()
{
    return "AcDbSpatialFilter";
}

PyDbSpatialFilter PyDbSpatialFilter::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSpatialFilter, AcDbSpatialFilter>(src);
}

PyDbSpatialFilter PyDbSpatialFilter::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSpatialFilter>(src);
}

AcDbSpatialFilter* PyDbSpatialFilter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSpatialFilter*>(m_pyImp.get());
}


//----------------------------------------------------------------------------------------
//PyDbLayerFilter
void makePyDbLayerFilterWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";


    PyDocString DS("LayerFilter");
    class_<PyDbLayerFilter, bases<PyDbObject>>("LayerFilter")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 5699)))
        .def("indexClass", &PyDbLayerFilter::indexClass, DS.ARGS())
        .def("isValid", &PyDbLayerFilter::isValid, DS.ARGS())
        .def("add", &PyDbLayerFilter::add, DS.ARGS({ "val : str" }))
        .def("remove", &PyDbLayerFilter::remove, DS.ARGS({ "val : str" }))
        .def("getAt", &PyDbLayerFilter::getAt, DS.ARGS({ "val : int" }))
        .def("layerCount", &PyDbLayerFilter::layerCount, DS.ARGS())
        .def("desc", &PyDbLayerFilter::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbLayerFilter::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbLayerFilter::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLayerFilter::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbLayerFilter::PyDbLayerFilter()
    : PyDbLayerFilter(new AcDbLayerFilter(), true)
{
}

PyDbLayerFilter::PyDbLayerFilter(const PyDbObjectId& id)
    : PyDbLayerFilter(openAcDbObject<AcDbLayerFilter>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbLayerFilter::PyDbLayerFilter(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbLayerFilter(openAcDbObject<AcDbLayerFilter>(id, mode), false)
{
}

PyDbLayerFilter::PyDbLayerFilter(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbLayerFilter(openAcDbObject<AcDbLayerFilter>(id, mode, erased), false)
{
}

PyDbLayerFilter::PyDbLayerFilter(AcDbLayerFilter* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyRxClass PyDbLayerFilter::indexClass() const
{
    return PyRxClass(impObj()->indexClass(), false);
}

Adesk::Boolean PyDbLayerFilter::isValid() const
{
    return impObj()->isValid();
}

void PyDbLayerFilter::add(const std::string& pLayer) const
{
    PyThrowBadEs(impObj()->add(utf8_to_wstr(pLayer).c_str()));
}

void PyDbLayerFilter::remove(const std::string& pLayer) const
{
    PyThrowBadEs(impObj()->remove(utf8_to_wstr(pLayer).c_str()));
}

std::string PyDbLayerFilter::getAt(int index) const
{
    const ACHAR* buf = nullptr;
    PyThrowBadEs(impObj()->getAt(index, buf));
    return wstr_to_utf8(buf);
}

int PyDbLayerFilter::layerCount() const
{
    return impObj()->layerCount();
}

PyRxClass PyDbLayerFilter::desc()
{
    return PyRxClass(AcDbSpatialFilter::desc(), false);
}

std::string PyDbLayerFilter::className()
{
    return "AcDbLayerFilter";
}

PyDbLayerFilter PyDbLayerFilter::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLayerFilter, AcDbLayerFilter>(src);
}

PyDbLayerFilter PyDbLayerFilter::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLayerFilter>(src);
}

AcDbLayerFilter* PyDbLayerFilter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLayerFilter*>(m_pyImp.get());
}
