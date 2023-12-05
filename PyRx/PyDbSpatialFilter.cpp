#include "stdafx.h"
#include "PyDbSpatialFilter.h"
#include "PyDbObjectId.h"
#include "PyDbEnts.h"

using namespace boost::python;

void makePyDbSpatialFilterWrapper()
{
    PyDocString DS("SpatialFilter");
    class_<PyDbSpatialFilter, bases<PyDbObject>>("SpatialFilter")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))

        .def("indexClass", &PyDbSpatialFilter::indexClass, DS.ARGS())
        .def("queryBounds", &PyDbSpatialFilter::queryBounds1)
        .def("queryBounds", &PyDbSpatialFilter::queryBounds2, DS.ARGS({ "ref : PyDbBlockReference=None" }))
        .def("getVolume", &PyDbSpatialFilter::getVolume, DS.ARGS())
        .def("setDefinition", &PyDbSpatialFilter::setDefinition, DS.ARGS({ "pnt2d: List[PyGe.Point2d]","normal: PyGe.Vector3d","elev: real","frontclip: real","backclip: real","enabled: bool" }))
        .def("getDefinition", &PyDbSpatialFilter::getDefinition, DS.ARGS())
        .def("getClipSpaceToWCSMatrix", &PyDbSpatialFilter::getClipSpaceToWCSMatrix, DS.ARGS())
        .def("getOriginalInverseBlockXform", &PyDbSpatialFilter::getOriginalInverseBlockXform, DS.ARGS())
        .def("setPerspectiveCamera", &PyDbSpatialFilter::setPerspectiveCamera, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("clipVolumeIntersectsExtents", &PyDbSpatialFilter::clipVolumeIntersectsExtents, DS.ARGS({ "val : PyDb.Extents" }))
        .def("hasPerspectiveCamera", &PyDbSpatialFilter::hasPerspectiveCamera, DS.ARGS())
        .def("isInverted", &PyDbSpatialFilter::isInverted, DS.ARGS())
        .def("setInverted", &PyDbSpatialFilter::setInverted, DS.ARGS({ "val : bool" }))

        .def("desc", &PyDbSpatialFilter::desc, DS.SARGS()).staticmethod("desc")
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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

void PyDbSpatialFilter::setDefinition(const boost::python::list& pts, const AcGeVector3d& normal, double elevation, double frontClip, double backClip, Adesk::Boolean enabled)
{
    PyThrowBadEs(impObj()->setDefinition(PyListToPoint2dArray(pts), normal, elevation, frontClip, backClip, enabled));
}

boost::python::tuple PyDbSpatialFilter::getDefinition()
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

void PyDbSpatialFilter::setPerspectiveCamera(const AcGePoint3d& fromPt)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setPerspectiveCamera(fromPt));
#endif
}

Adesk::Boolean PyDbSpatialFilter::clipVolumeIntersectsExtents(const AcDbExtents& ext) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->clipVolumeIntersectsExtents(ext);
#endif
}

Adesk::Boolean PyDbSpatialFilter::hasPerspectiveCamera() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->hasPerspectiveCamera();
#endif
}

bool PyDbSpatialFilter::isInverted() const
{
    return impObj()->isInverted();
}

void PyDbSpatialFilter::setInverted(bool bInverted)
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
    if (!src.impObj()->isKindOf(AcDbSpatialFilter::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSpatialFilter(static_cast<AcDbSpatialFilter*>(src.impObj()->clone()), true);
}

PyDbSpatialFilter PyDbSpatialFilter::cast(const PyRxObject& src)
{
    PyDbSpatialFilter dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSpatialFilter* PyDbSpatialFilter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSpatialFilter*>(m_pyImp.get());
}
