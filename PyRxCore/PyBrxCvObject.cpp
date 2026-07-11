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

std::string PyBrxCvDbStringLine::className()
{
    return "PyBrxCvDbStringLine";
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

#endif

#endif//BRXAPP
