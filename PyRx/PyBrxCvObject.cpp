#include "stdafx.h"
#include "PyBrxCvObject.h"
#include "PyDbObjectId.h"

#ifdef BRXAPP
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
        .def("desc", &PyBrxCvDbSubObject::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbObject::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

bool PyBrxCvDbSubObject::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbSubObject::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbSubObject::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
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
    PyBrxCvDbSubObject dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbObject::name, DS.ARGS())
        .def("setName", &PyBrxCvDbObject::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbObject::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbObject::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbObject::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbObject::desc, DS.SARGS()).staticmethod("desc")
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

bool PyBrxCvDbObject::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbObject::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbObject::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbObject(static_cast<BrxCvDbObject*>(src.impObj()->clone()), true);
}

PyBrxCvDbObject PyBrxCvDbObject::cast(const PyRxObject& src)
{
    PyBrxCvDbObject dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbEntity::name, DS.ARGS())
        .def("setName", &PyBrxCvDbEntity::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbEntity::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbEntity::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbEntity::desc, DS.SARGS()).staticmethod("desc")
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

bool PyBrxCvDbEntity::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbEntity::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbEntity::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbEntity(static_cast<BrxCvDbEntity*>(src.impObj()->clone()), true);
}

PyBrxCvDbEntity PyBrxCvDbEntity::cast(const PyRxObject& src)
{
    PyBrxCvDbEntity dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("name", &PyBrxCvDbCurve::name, DS.ARGS())
        .def("setName", &PyBrxCvDbCurve::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbCurve::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbCurve::setDescription, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbCurve::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbCurve::desc, DS.SARGS()).staticmethod("desc")
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

bool PyBrxCvDbCurve::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbCurve::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbCurve::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbCurve(static_cast<BrxCvDbCurve*>(src.impObj()->clone()), true);
}

PyBrxCvDbCurve PyBrxCvDbCurve::cast(const PyRxObject& src)
{
    PyBrxCvDbCurve dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbCurve* PyBrxCvDbCurve::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbCurve*>(m_pyImp.get());
}
#endif//BRXAPP
