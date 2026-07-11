#include "stdafx.h"

#ifdef BRXAPP
#include "PyBrxCvObject.h"
#include "PyDbObjectId.h"
#include "PyGeInterval.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbSubObject
void makePyBrxCvDbSubObjectWrapper()
{
    PyDocString DS("CvDbSubObject");
    class_<PyBrxCvDbSubObject, bases<PyRxObject>>("CvDbSubObject", boost::python::no_init)
        .def("name", &PyBrxCvDbSubObject::name, DS.ARGS())
        .def("setName", &PyBrxCvDbSubObject::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbSubObject::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbSubObject::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbSubObject::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSubObject::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbSubObject::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSubObject::PyBrxCvDbSubObject(BrxCvDbSubObject* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

std::string PyBrxCvDbSubObject::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbSubObject::setName(const std::string& szName) const
{
    return impObj()->setName(AsWStr(szName));
}

std::string PyBrxCvDbSubObject::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbSubObject::setDescription(const std::string& szDescription) const
{
    return impObj()->setDescription(AsWStr(szDescription));
}

std::string PyBrxCvDbSubObject::className()
{
    return "BrxCvDbSubObject";
}

PyRxClass PyBrxCvDbSubObject::desc()
{
    return PyRxClass(BrxCvDbSubObject::desc(), false);
}

PyBrxCvDbSubObject PyBrxCvDbSubObject::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSubObject>(src);
}

BrxCvDbSubObject* PyBrxCvDbSubObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSubObject*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbObject
void makePyBrxCvDbObjectWrapper()
{
    PyDocString DS("CvDbObject");
    class_<PyBrxCvDbObject, bases<PyDbObject>>("CvDbObject", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbObject::name, DS.ARGS())
        .def("setName", &PyBrxCvDbObject::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbObject::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbObject::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbObject::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbObject::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbObject::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbObject::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbObject::PyBrxCvDbObject(const PyDbObjectId& id)
    : PyBrxCvDbObject(openAcDbObject<BrxCvDbObject>(id, AcDb::OpenMode::kForRead), false)
{
}

PyBrxCvDbObject::PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbObject(openAcDbObject<BrxCvDbObject>(id, mode), false)
{
}

PyBrxCvDbObject::PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbObject(openAcDbObject<BrxCvDbObject>(id, mode, erased), false)
{
}

PyBrxCvDbObject::PyBrxCvDbObject(BrxCvDbObject* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

std::string PyBrxCvDbObject::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbObject::setName(const std::string& szName) const
{
    return impObj()->setName(AsWStr(szName));
}

std::string PyBrxCvDbObject::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbObject::setDescription(const std::string& szDescription) const
{
    return impObj()->setDescription(AsWStr(szDescription));
}

std::string PyBrxCvDbObject::className()
{
    return "BrxCvDbObject";
}

PyRxClass PyBrxCvDbObject::desc()
{
    return PyRxClass(BrxCvDbObject::desc(), false);
}

PyBrxCvDbObject PyBrxCvDbObject::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbObject::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbObject(static_cast<BrxCvDbObject*>(src.impObj()->clone()), true);
}

PyBrxCvDbObject PyBrxCvDbObject::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbObject>(src);
}

BrxCvDbObject* PyBrxCvDbObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbObject*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbEntity
void makePyBrxCvDbEntityWrapper()
{
    PyDocString DS("CvDbEntity");
    class_<PyBrxCvDbEntity, bases<PyDbEntity>>("CvDbEntity", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbEntity::name, DS.ARGS())
        .def("setName", &PyBrxCvDbEntity::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbEntity::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbEntity::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbEntity::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbEntity::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbEntity::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbEntity::PyBrxCvDbEntity(const PyDbObjectId& id)
    : PyBrxCvDbEntity(openAcDbObject<BrxCvDbEntity>(id, AcDb::OpenMode::kForRead), false)
{
}

PyBrxCvDbEntity::PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbEntity(openAcDbObject<BrxCvDbEntity>(id, mode), false)
{
}

PyBrxCvDbEntity::PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbEntity(openAcDbObject<BrxCvDbEntity>(id, mode, erased), false)
{
}

PyBrxCvDbEntity::PyBrxCvDbEntity(BrxCvDbEntity* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

std::string PyBrxCvDbEntity::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbEntity::setName(const std::string& szName) const
{
    return impObj()->setName(AsWStr(szName));
}

std::string PyBrxCvDbEntity::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbEntity::setDescription(const std::string& szDescription) const
{
    return impObj()->setDescription(AsWStr(szDescription));
}

std::string PyBrxCvDbEntity::className()
{
    return "BrxCvDbEntity";
}

PyRxClass PyBrxCvDbEntity::desc()
{
    return PyRxClass(BrxCvDbEntity::desc(), false);
}

PyBrxCvDbEntity PyBrxCvDbEntity::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbEntity::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbEntity(static_cast<BrxCvDbEntity*>(src.impObj()->clone()), true);
}

PyBrxCvDbEntity PyBrxCvDbEntity::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbEntity>(src);
}

BrxCvDbEntity* PyBrxCvDbEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbEntity*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbCurve
void makePyBrxCvDbCurveWrapper()
{
    PyDocString DS("CvDbCurve");
    class_<PyBrxCvDbCurve, bases<PyDbCurve>>("CvDbCurve", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbCurve::name, DS.ARGS())
        .def("setName", &PyBrxCvDbCurve::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbCurve::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbCurve::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbCurve::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbCurve::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbCurve::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbCurve::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbCurve::PyBrxCvDbCurve(const PyDbObjectId& id)
    : PyBrxCvDbCurve(openAcDbObject<BrxCvDbCurve>(id, AcDb::OpenMode::kForRead), false)
{
}

PyBrxCvDbCurve::PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbCurve(openAcDbObject<BrxCvDbCurve>(id, mode), false)
{
}

PyBrxCvDbCurve::PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbCurve(openAcDbObject<BrxCvDbCurve>(id, mode, erased), false)
{
}

PyBrxCvDbCurve::PyBrxCvDbCurve(BrxCvDbCurve* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

std::string PyBrxCvDbCurve::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbCurve::setName(const std::string& szName) const
{
    return impObj()->setName(AsWStr(szName));
}

std::string PyBrxCvDbCurve::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbCurve::setDescription(const std::string& szDescription) const
{
    return impObj()->setDescription(AsWStr(szDescription));
}

std::string PyBrxCvDbCurve::className()
{
    return "BrxCvDbCurve";
}

PyRxClass PyBrxCvDbCurve::desc()
{
    return PyRxClass(BrxCvDbCurve::desc(), false);
}

PyBrxCvDbCurve PyBrxCvDbCurve::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbCurve::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbCurve(static_cast<BrxCvDbCurve*>(src.impObj()->clone()), true);
}

PyBrxCvDbCurve PyBrxCvDbCurve::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbCurve>(src);
}

BrxCvDbCurve* PyBrxCvDbCurve::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbCurve*>(m_pyImp.get());
}

//TODO: move to own .h .cpp
#if defined(_BRXTARGET) && (_BRXTARGET >= 270)
//-----------------------------------------------------------------------------------
//PyBrxCvDbStringLine

void makePyBrxCvDbStringLineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("CvDbStringLine");
    class_<PyBrxCvDbStringLine, bases<PyBrxCvDbCurve>>("CvDbStringLine")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.OVRL(ctords)))
        .def("numberOfPoints", &PyBrxCvDbStringLine::numberOfPoints1)
        .def("numberOfPoints", &PyBrxCvDbStringLine::numberOfPoints2, DS.ARGS({ "ptype: PyBrxCv.StringLinePointType = ..." }))
        .def("getPoint", &PyBrxCvDbStringLine::getPoint, DS.ARGS({ "index: int" }))
        .def("getBulge", &PyBrxCvDbStringLine::getBulge, DS.ARGS({ "index: int" }))
        .def("getRadius", &PyBrxCvDbStringLine::getRadius, DS.ARGS({ "index: int" }))
        .def("findPoint", &PyBrxCvDbStringLine::findPoint1)
        .def("findPoint", &PyBrxCvDbStringLine::findPoint2, DS.ARGS({ "pointLocation: PyGe.Point2d","pInterval: PyGe.Interval = ..." }))
        .def("surfaceId", &PyBrxCvDbStringLine::surfaceId, DS.ARGS())
        .def("creationSource", &PyBrxCvDbStringLine::creationSource, DS.ARGS())
        .def("maxGrade", &PyBrxCvDbStringLine::maxGrade, DS.ARGS())
        .def("minGrade", &PyBrxCvDbStringLine::minGrade, DS.ARGS())
        .def("maxElevation", &PyBrxCvDbStringLine::maxElevation, DS.ARGS())
        .def("minElevation", &PyBrxCvDbStringLine::minElevation, DS.ARGS())
        .def("length2d", &PyBrxCvDbStringLine::length2d, DS.ARGS())
        .def("length3d", &PyBrxCvDbStringLine::length3d, DS.ARGS())
        .def("isRelativeToSurface", &PyBrxCvDbStringLine::isRelativeToSurface, DS.ARGS({ "index: int" }))
        .def("getRelativeElevation", &PyBrxCvDbStringLine::getRelativeElevation, DS.ARGS({ "index: int" }))
        .def("getPoints", &PyBrxCvDbStringLine::getPoints1)
        .def("getPoints", &PyBrxCvDbStringLine::getPoints2, DS.ARGS({ "ptype: PyBrxCv.StringLinePointType = ..." }))
        .def("get3dDistanceAtPoint", &PyBrxCvDbStringLine::get3dDistanceAtPoint, DS.ARGS({ "point: PyGe.Point3d" }))
        .def("get2dDistanceAtPoint", &PyBrxCvDbStringLine::get2dDistanceAtPoint, DS.ARGS({ "point: PyGe.Point2d" }))
        .def("get2dDistanceAtParam", &PyBrxCvDbStringLine::get2dDistanceAtParam, DS.ARGS({ "param: float" }))
        .def("get2dDistancesAtPoints", &PyBrxCvDbStringLine::get2dDistancesAtPoints, DS.ARGS({ "points: list[PyGe.Point2d]" }))
        .def("getGradeInAtPoint", &PyBrxCvDbStringLine::getGradeInAtPoint, DS.ARGS({ "pointOnCurve: PyGe.Point2d" }))
        .def("getGradeInAtParam", &PyBrxCvDbStringLine::getGradeInAtParam, DS.ARGS({ "param: float" }))
        .def("getGradeOutAtPoint", &PyBrxCvDbStringLine::getGradeOutAtPoint, DS.ARGS({ "pointOnCurve: PyGe.Point2d" }))
        .def("getGradeOutAtParam", &PyBrxCvDbStringLine::getGradeOutAtParam, DS.ARGS({ "param: float" }))
        .def("getElevationAtPoint", &PyBrxCvDbStringLine::getElevationAtPoint, DS.ARGS({ "pointOnCurve: PyGe.Point2d" }))
        .def("getElevationsAt2dIntersections", &PyBrxCvDbStringLine::getElevationsAt2dIntersections, DS.ARGS({ "stringline: PyBrxCv.CvDbStringLine" }))
        .def("addPI", &PyBrxCvDbStringLine::addPI1)
        .def("addPI", &PyBrxCvDbStringLine::addPI2, DS.ARGS({ "point: PyGe.Point3d", "bulge:float = ..." }))
        .def("insertElevationPoint", &PyBrxCvDbStringLine::insertElevationPoint, DS.ARGS({ "param: float", "elevation:float" }))
        .def("insertPI", &PyBrxCvDbStringLine::insertPI1)
        .def("insertPI", &PyBrxCvDbStringLine::insertPI2, DS.ARGS({ "index:int", "point: PyGe.Point3d", "bulge:float = ..." }))
        .def("insertCurve", &PyBrxCvDbStringLine::insertCurve, DS.ARGS({ "index:int","radius: float" }))
        .def("deletePoint", &PyBrxCvDbStringLine::deletePoint, DS.ARGS({ "index:int" }))
        .def("deletePI", &PyBrxCvDbStringLine::deletePI1)
        .def("deletePI", &PyBrxCvDbStringLine::deletePI2, DS.ARGS({ "val:int|PyGe.Point3d" }))
        .def("deleteElevationPoint", &PyBrxCvDbStringLine::deleteElevationPoint1)
        .def("deleteElevationPoint", &PyBrxCvDbStringLine::deleteElevationPoint2, DS.ARGS({ "val:int|PyGe.Point3d" }))
        .def("setLocation", &PyBrxCvDbStringLine::setLocation, DS.ARGS({ "index:int" , "location:PyGe.Point3d" }))
        .def("setElevation", &PyBrxCvDbStringLine::setElevation, DS.ARGS({ "index:int" , "elevation:float" }))
        .def("setBulge", &PyBrxCvDbStringLine::setBulge, DS.ARGS({ "index:int" , "bulge:float" }))
        .def("setRadius", &PyBrxCvDbStringLine::setRadius, DS.ARGS({ "index:int", "radius:float", "isClockwise:bool" }))
        .def("setRelativeToSurface", &PyBrxCvDbStringLine::setRelativeToSurface, DS.ARGS({ "index:int", "isRelative:bool" }))
        .def("setRelativeElevation", &PyBrxCvDbStringLine::setRelativeElevation, DS.ARGS({ "index:int", "isInputRelative:bool", "elevation:float" }))
        .def("setSurfaceId", &PyBrxCvDbStringLine::setSurfaceId, DS.ARGS({ "surfaceId:PyDb.ObjectId" }))
        .def("setGradeIn", &PyBrxCvDbStringLine::setGradeIn, DS.ARGS({ "index:int", "grade:float" }))
        .def("setGradeOut", &PyBrxCvDbStringLine::setGradeOut, DS.ARGS({ "index:int", "grade:float" }))
        .def("update", &PyBrxCvDbStringLine::update1)
        .def("update", &PyBrxCvDbStringLine::update2, DS.ARGS({ "forceUpdate:bool=True" }))
        .def("className", &PyBrxCvDbStringLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStringLine::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbStringLine::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbStringLine::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStringLine::PyBrxCvDbStringLine()
    : PyBrxCvDbStringLine(new BrxCvDbStringLine(), false)
{
}

PyBrxCvDbStringLine::PyBrxCvDbStringLine(const PyDbObjectId& id)
    : PyBrxCvDbStringLine(openAcDbObject<BrxCvDbStringLine>(id, AcDb::OpenMode::kForRead), false)
{
}

PyBrxCvDbStringLine::PyBrxCvDbStringLine(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStringLine(openAcDbObject<BrxCvDbStringLine>(id, mode), false)
{
}

PyBrxCvDbStringLine::PyBrxCvDbStringLine(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStringLine(openAcDbObject<BrxCvDbStringLine>(id, mode, erased), false)
{
}

PyBrxCvDbStringLine::PyBrxCvDbStringLine(BrxCvDbStringLine* ptr, bool autoDelete)
    : PyBrxCvDbCurve(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbStringLine::numberOfPoints1() const
{
    return impObj()->numberOfPoints();
}

Adesk::UInt32 PyBrxCvDbStringLine::numberOfPoints2(BrxCvDbStringLine::PointType type) const
{
    return impObj()->numberOfPoints(type);
}

boost::python::tuple PyBrxCvDbStringLine::getPoint(Adesk::UInt32 index) const
{
    PyAutoLockGIL lock;
    AcGePoint3d point;
    double bulge = 0;
    BrxCvDbStringLine::PointType ptype = BrxCvDbStringLine::PointType::ePI;
    PyThrowBadEs(impObj()->getPoint(index, point, &bulge, &ptype));
    return boost::python::make_tuple(point, bulge, ptype);
}

boost::python::tuple PyBrxCvDbStringLine::findPoint1(const AcGePoint2d& pointLocation) const
{
    PyAutoLockGIL lock;
    Adesk::UInt32 idx = 0;
    if (impObj()->findPoint(pointLocation, nullptr, &idx) == Acad::eOk)
        return boost::python::make_tuple(true, idx);
    return boost::python::make_tuple(false, idx);
}

boost::python::tuple PyBrxCvDbStringLine::findPoint2(const AcGePoint2d& pointLocation, const PyGeInterval& pInterval) const
{
    PyAutoLockGIL lock;
    Adesk::UInt32 idx = 0;
    if (impObj()->findPoint(pointLocation, &pInterval.imp, &idx) == Acad::eOk)
        return boost::python::make_tuple(true, idx);
    return boost::python::make_tuple(false, idx);
}

double PyBrxCvDbStringLine::getBulge(Adesk::UInt32 index) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getBulge(index, val));
    return val;
}

double PyBrxCvDbStringLine::getRadius(Adesk::UInt32 index) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getRadius(index, val));
    return val;
}

PyDbObjectId PyBrxCvDbStringLine::surfaceId() const
{
    return impObj()->surfaceId();
}

BrxCvDbStringLine::CreationSource PyBrxCvDbStringLine::creationSource() const
{
    return impObj()->creationSource();
}

double PyBrxCvDbStringLine::maxGrade() const
{
    return impObj()->maxGrade();
}

double PyBrxCvDbStringLine::minGrade() const
{
    return impObj()->minGrade();
}

double PyBrxCvDbStringLine::maxElevation() const
{
    return impObj()->maxElevation();
}

double PyBrxCvDbStringLine::minElevation() const
{
    return impObj()->minElevation();
}

double PyBrxCvDbStringLine::length2d() const
{
    return impObj()->length2d();
}

double PyBrxCvDbStringLine::length3d() const
{
    return impObj()->length3d();
}

bool PyBrxCvDbStringLine::isRelativeToSurface(Adesk::UInt32 index) const
{
    return impObj()->isRelativeToSurface(index);
}

double PyBrxCvDbStringLine::getRelativeElevation(Adesk::UInt32 index) const
{
    double elevationOffset = 0;
    PyThrowBadEs(impObj()->getRelativeElevation(index, elevationOffset));
    return elevationOffset;
}

boost::python::tuple PyBrxCvDbStringLine::getPoints1() const
{
    return getPoints2(BrxCvDbStringLine::PointType::eAll);
}

boost::python::tuple PyBrxCvDbStringLine::getPoints2(BrxCvDbStringLine::PointType type) const
{
    PyAutoLockGIL lock;
    using PType = BrxCvDbStringLine::PointType;
    AcGePoint3dArray points;
    AcArray<double> bulges;
    AcArray<BrxCvDbStringLine::PointType> types;
    AcArray<Adesk::UInt32> indices;
    PyThrowBadEs(impObj()->getPoints(points, type, &bulges, &types, &indices));
    const auto pypoints = Point3dArrayToPyList(points);
    const auto pybulges = DoubleArrayToPyList(bulges);
    const auto pyindices = UInt32ArrayToPyList(indices);
    boost::python::list pytypes;
    for (auto item : types)
        pytypes.append(item);
    return boost::python::make_tuple(pypoints, pybulges, pytypes, pyindices);
}

double PyBrxCvDbStringLine::get3dDistanceAtPoint(const AcGePoint3d& point) const
{
    double val = 0;
    PyThrowBadEs(impObj()->get3dDistanceAtPoint(point, val));
    return val;
}

double PyBrxCvDbStringLine::get2dDistanceAtPoint(const AcGePoint2d& point) const
{
    double val = 0;
    PyThrowBadEs(impObj()->get2dDistanceAtPoint(point, val));
    return val;
}

double PyBrxCvDbStringLine::get2dDistanceAtParam(double param) const
{
    double val = 0;
    PyThrowBadEs(impObj()->get2dDistanceAtParam(param, val));
    return val;
}

boost::python::list PyBrxCvDbStringLine::get2dDistancesAtPoints(const boost::python::list& points)
{
    AcGeDoubleArray vals;
    PyThrowBadEs(impObj()->get2dDistancesAtPoints(PyListToPoint3dArray(points), vals));
    return DoubleArrayToPyList(vals);
}

double PyBrxCvDbStringLine::getGradeInAtPoint(const AcGePoint2d& pointOnCurve) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getGradeInAtPoint(pointOnCurve, val));
    return val;
}

double PyBrxCvDbStringLine::getGradeInAtParam(double param) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getGradeInAtParam(param, val));
    return val;
}

double PyBrxCvDbStringLine::getGradeOutAtPoint(const AcGePoint2d& pointOnCurve) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getGradeOutAtPoint(pointOnCurve, val));
    return val;
}

double PyBrxCvDbStringLine::getGradeOutAtParam(double param) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getGradeOutAtParam(param, val));
    return val;
}

double PyBrxCvDbStringLine::getElevationAtPoint(const AcGePoint2d& pointOnCurve) const
{
    double val = 0;
    PyThrowBadEs(impObj()->getElevationAtPoint(pointOnCurve, val));
    return val;
}

boost::python::list PyBrxCvDbStringLine::getElevationsAt2dIntersections(const PyBrxCvDbStringLine& stringline) const
{
    AcGePoint3dArray val;
    PyThrowBadEs(impObj()->getElevationsAt2dIntersections(*stringline.impObj(), val));
    return Point3dArrayToPyList(val);
}

void PyBrxCvDbStringLine::addPI1(const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->addPI(point));
}

void PyBrxCvDbStringLine::addPI2(const AcGePoint3d& point, double bulge) const
{
    PyThrowBadEs(impObj()->addPI(point, bulge));
}

Adesk::UInt32 PyBrxCvDbStringLine::insertElevationPoint(double param, double elevation) const
{
    Adesk::UInt32 insertedIndex = 0;
    PyThrowBadEs(impObj()->insertElevationPoint(param, elevation, &insertedIndex));
    return insertedIndex;
}

void PyBrxCvDbStringLine::insertPI1(Adesk::UInt32 index, const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->insertPI(index, point));
}

void PyBrxCvDbStringLine::insertPI2(Adesk::UInt32 index, const AcGePoint3d& point, double bulge) const
{
    PyThrowBadEs(impObj()->insertPI(index, point, bulge));
}

void PyBrxCvDbStringLine::insertCurve(Adesk::UInt32 index, double radius) const
{
    PyThrowBadEs(impObj()->insertCurve(index, radius));
}

void PyBrxCvDbStringLine::deletePoint(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->deletePoint(index));
}

void PyBrxCvDbStringLine::deletePI1(const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->deletePI(point));
}

void PyBrxCvDbStringLine::deletePI2(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->deletePI(index));
}

void PyBrxCvDbStringLine::deleteElevationPoint1(const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->deleteElevationPoint(point));
}

void PyBrxCvDbStringLine::deleteElevationPoint2(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->deleteElevationPoint(index));
}

void PyBrxCvDbStringLine::setLocation(Adesk::UInt32 index, const AcGePoint2d& location) const
{
    PyThrowBadEs(impObj()->setLocation(index, location));
}

void PyBrxCvDbStringLine::setElevation(Adesk::UInt32 index, double elevation) const
{
    PyThrowBadEs(impObj()->setElevation(index, elevation));
}

void PyBrxCvDbStringLine::setBulge(Adesk::UInt32 index, double bulge) const
{
    PyThrowBadEs(impObj()->setBulge(index, bulge));
}

void PyBrxCvDbStringLine::setRadius(Adesk::UInt32 piIndex, double radius, bool isClockwise) const
{
    PyThrowBadEs(impObj()->setRadius(piIndex, radius, isClockwise));
}

void PyBrxCvDbStringLine::setRelativeToSurface(Adesk::UInt32 index, bool isRelative) const
{
    PyThrowBadEs(impObj()->setRelativeToSurface(index, isRelative));
}

void PyBrxCvDbStringLine::setRelativeElevation(Adesk::UInt32 index, bool isInputRelative, double elevation) const
{
    PyThrowBadEs(impObj()->setRelativeElevation(index, isInputRelative, elevation));
}

void PyBrxCvDbStringLine::setSurfaceId(const PyDbObjectId& surfaceId) const
{
    PyThrowBadEs(impObj()->setSurfaceId(surfaceId));
}

void PyBrxCvDbStringLine::setGradeIn(Adesk::UInt32 index, double grade) const
{
    PyThrowBadEs(impObj()->setGradeIn(index, grade));
}

void PyBrxCvDbStringLine::setGradeOut(Adesk::UInt32 index, double grade) const
{
    PyThrowBadEs(impObj()->setGradeOut(index, grade));
}

void PyBrxCvDbStringLine::update1() const
{
    PyThrowBadEs(impObj()->update());
}

void PyBrxCvDbStringLine::update2(bool forceUpdate) const
{
    PyThrowBadEs(impObj()->update(forceUpdate));
}

std::string PyBrxCvDbStringLine::className()
{
    return "BrxCvDbStringLine";
}

PyRxClass PyBrxCvDbStringLine::desc()
{
    return PyRxClass(BrxCvDbStringLine::desc(), false);
}

PyBrxCvDbStringLine PyBrxCvDbStringLine::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbStringLine::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbStringLine(static_cast<BrxCvDbStringLine*>(src.impObj()->clone()), true);
}

PyBrxCvDbStringLine PyBrxCvDbStringLine::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbStringLine>(src);
}

BrxCvDbStringLine* PyBrxCvDbStringLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStringLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbStringLineManager
void makePyBrxCvDbStringLineManagerWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("CvDbStringLineManager");
    class_<PyBrxCvDbStringLineManager, bases<PyDbObject>>("CvDbStringLineManager")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.OVRL(ctords)))
        .def("addGroup", &PyBrxCvDbStringLineManager::addGroup, DS.ARGS({ "groupName: str" }))
        .def("eraseGroup", &PyBrxCvDbStringLineManager::eraseGroup, DS.ARGS({ "groupName: str" }))
        .def("renameGroup", &PyBrxCvDbStringLineManager::renameGroup, DS.ARGS({ "groupName: str", "newName: str" }))
        .def("setIntersectionInteraction", &PyBrxCvDbStringLineManager::setIntersectionInteraction, DS.ARGS({ "groupName: str" , "isOn:bool" }))
        .def("updateInteractionGeometry", &PyBrxCvDbStringLineManager::updateInteractionGeometry, DS.ARGS({ "groupName: str" }))
        .def("intersectionInteractionEnabled", &PyBrxCvDbStringLineManager::intersectionInteractionEnabled, DS.ARGS({ "groupName: str" }))
        .def("groupCount", &PyBrxCvDbStringLineManager::groupCount, DS.ARGS())
        .def("groupAt", &PyBrxCvDbStringLineManager::groupAt, DS.ARGS({ "index: int" }))
        .def("addStringlineToGroup", &PyBrxCvDbStringLineManager::addStringlineToGroup, DS.ARGS({ "groupName: str","stringlineId:PyDb.ObjectId" }))
        .def("removeStringlineFromGroup", &PyBrxCvDbStringLineManager::removeStringlineFromGroup1)
        .def("removeStringlineFromGroup", &PyBrxCvDbStringLineManager::removeStringlineFromGroup2, DS.ARGS({ "groupName: str","stringlineId:PyDb.ObjectId","addToDefault:bool = True" }))
        .def("getStringlineGroup", &PyBrxCvDbStringLineManager::getStringlineGroup, DS.ARGS({ "stringlineId:PyDb.ObjectId" }))
        .def("setPriorityOrder", &PyBrxCvDbStringLineManager::setPriorityOrder, DS.ARGS({ "groupName: str","stringlineId:PyDb.ObjectId", "order:int" }))
        .def("getPriorityOrder", &PyBrxCvDbStringLineManager::getPriorityOrder, DS.ARGS({ "groupName: str","stringlineId:PyDb.ObjectId" }))
        .def("getStringlineIds", &PyBrxCvDbStringLineManager::getStringlineIds, DS.ARGS({ "groupName: str" }))
        .def("getStringlineCount", &PyBrxCvDbStringLineManager::getStringlineCount, DS.ARGS({ "groupName: str" }))
        .def("getInstanceFromDatabase", &PyBrxCvDbStringLineManager::getInstanceFromDatabase1)
        .def("getInstanceFromDatabase", &PyBrxCvDbStringLineManager::getInstanceFromDatabase2, DS.SARGS({ "db:PyDb.Database", "createIfNotExists:bool=True" })).staticmethod("getInstanceFromDatabase")
        .def("openInstanceFromDatabase", &PyBrxCvDbStringLineManager::openInstanceFromDatabase1)
        .def("openInstanceFromDatabase", &PyBrxCvDbStringLineManager::openInstanceFromDatabase2, DS.SARGS({ "db:PyDb.Database","openMode:PyDb.OpenMode", "createIfNotExists:bool=True" })).staticmethod("openInstanceFromDatabase")
        .def("className", &PyBrxCvDbStringLineManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStringLineManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbStringLineManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbStringLineManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStringLineManager::PyBrxCvDbStringLineManager()
    : PyBrxCvDbStringLineManager(new BrxCvDbStringLineManager(), true)
{
}

PyBrxCvDbStringLineManager::PyBrxCvDbStringLineManager(const PyDbObjectId& id)
    : PyBrxCvDbStringLineManager(openAcDbObject<BrxCvDbStringLineManager>(id), false)
{
}

PyBrxCvDbStringLineManager::PyBrxCvDbStringLineManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStringLineManager(openAcDbObject<BrxCvDbStringLineManager>(id, mode), false)
{
}

PyBrxCvDbStringLineManager::PyBrxCvDbStringLineManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStringLineManager(openAcDbObject<BrxCvDbStringLineManager>(id, mode, erased), false)
{
}

PyBrxCvDbStringLineManager::PyBrxCvDbStringLineManager(BrxCvDbStringLineManager* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

void PyBrxCvDbStringLineManager::addGroup(const std::string& groupName) const
{
    PyThrowBadEs(impObj()->addGroup(AsWStr(groupName)));
}

void PyBrxCvDbStringLineManager::eraseGroup(const std::string& groupName) const
{
    PyThrowBadEs(impObj()->eraseGroup(AsWStr(groupName)));
}

void PyBrxCvDbStringLineManager::renameGroup(const std::string& groupName, const std::string& newName) const
{
    PyThrowBadEs(impObj()->renameGroup(AsWStr(groupName), AsWStr(newName)));
}

void PyBrxCvDbStringLineManager::setIntersectionInteraction(const std::string& groupName, bool isOn) const
{
    PyThrowBadEs(impObj()->setIntersectionInteraction(AsWStr(groupName), isOn));
}

void PyBrxCvDbStringLineManager::updateInteractionGeometry(const std::string& groupName) const
{
    PyThrowBadEs(impObj()->updateInteractionGeometry(AsWStr(groupName)));
}

bool PyBrxCvDbStringLineManager::intersectionInteractionEnabled(const std::string& groupName) const
{
    return impObj()->intersectionInteractionEnabled(AsWStr(groupName));
}

Adesk::UInt32 PyBrxCvDbStringLineManager::groupCount() const
{
    return impObj()->groupCount();
}

std::string PyBrxCvDbStringLineManager::groupAt(Adesk::UInt32 index) const
{
    return wstr_to_utf8(impObj()->groupAt(index));
}

void PyBrxCvDbStringLineManager::addStringlineToGroup(const std::string& groupName, const PyDbObjectId& stringlineId) const
{
    PyThrowBadEs(impObj()->addStringlineToGroup(AsWStr(groupName), stringlineId));
}

void PyBrxCvDbStringLineManager::removeStringlineFromGroup1(const std::string& groupName, const PyDbObjectId& stringlineId) const
{
    PyThrowBadEs(impObj()->removeStringlineFromGroup(AsWStr(groupName), stringlineId));
}

void PyBrxCvDbStringLineManager::removeStringlineFromGroup2(const std::string& groupName, const PyDbObjectId& stringlineId, bool addToDefault) const
{
    PyThrowBadEs(impObj()->removeStringlineFromGroup(AsWStr(groupName), stringlineId, addToDefault));
}

std::string PyBrxCvDbStringLineManager::getStringlineGroup(const PyDbObjectId& stringlineId) const
{
    AcString val;
    PyThrowBadEs(impObj()->getStringlineGroup(stringlineId, val));
    return wstr_to_utf8(val);
}

void PyBrxCvDbStringLineManager::setPriorityOrder(const std::string& groupName, const PyDbObjectId& stringlineId, Adesk::UInt32 order) const
{
    PyThrowBadEs(impObj()->setPriorityOrder(AsWStr(groupName), stringlineId, order));
}

Adesk::UInt32 PyBrxCvDbStringLineManager::getPriorityOrder(const std::string& groupName, const PyDbObjectId& stringlineId) const
{
    Adesk::UInt32 val;
    PyThrowBadEs(impObj()->getPriorityOrder(AsWStr(groupName), stringlineId, val));
    return val;
}

boost::python::list PyBrxCvDbStringLineManager::getStringlineIds(const std::string& groupName) const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getStringlineIds(AsWStr(groupName), ids));
    return ObjectIdArrayToPyList(ids);
}

Adesk::UInt32 PyBrxCvDbStringLineManager::getStringlineCount(const std::string& groupName) const
{
    Adesk::UInt32 val;
    PyThrowBadEs(impObj()->getStringlineCount(AsWStr(groupName), val));
    return val;
}

PyDbObjectId PyBrxCvDbStringLineManager::getInstanceFromDatabase1(const PyDbDatabase& pDb)
{
    return BrxCvDbStringLineManager::getInstanceFromDatabase(pDb.impObj());
}

PyDbObjectId PyBrxCvDbStringLineManager::getInstanceFromDatabase2(const PyDbDatabase& pDb, bool createIfNotExists)
{
    return BrxCvDbStringLineManager::getInstanceFromDatabase(pDb.impObj(), createIfNotExists);
}

PyBrxCvDbStringLineManager PyBrxCvDbStringLineManager::openInstanceFromDatabase1(const PyDbDatabase& pDb, AcDb::OpenMode openMode)
{
    return PyBrxCvDbStringLineManager(BrxCvDbStringLineManager::getInstanceFromDatabase(pDb.impObj(), openMode), false);
}

PyBrxCvDbStringLineManager PyBrxCvDbStringLineManager::openInstanceFromDatabase2(const PyDbDatabase& pDb, AcDb::OpenMode openMode, bool createIfNotExists)
{
    return PyBrxCvDbStringLineManager(BrxCvDbStringLineManager::getInstanceFromDatabase(pDb.impObj(), openMode, createIfNotExists), false);
}

std::string PyBrxCvDbStringLineManager::className()
{
    return "BrxCvDbStringLineManager";
}

PyRxClass PyBrxCvDbStringLineManager::desc()
{
    return PyRxClass(BrxCvDbStringLine::desc(), false);
}

PyBrxCvDbStringLineManager PyBrxCvDbStringLineManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbStringLineManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbStringLineManager(static_cast<BrxCvDbStringLineManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbStringLineManager PyBrxCvDbStringLineManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbStringLineManager>(src);
}

BrxCvDbStringLineManager* PyBrxCvDbStringLineManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStringLineManager*>(m_pyImp.get());
}
#endif

#endif//BRXAPP
