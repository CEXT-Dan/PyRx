#include "stdafx.h"
#include "PyBrxCvBase.h"
#include "PyDbObjectId.h"

#ifdef BRXAPP
using namespace boost::python;

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

//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dEntityInfo

void makePyBrxCvCivil3dEntityInfoWrapper()
{
    PyDocString DS("CvCivil3dEntityInfo");
    class_<PyBrxCvCivil3dEntityInfo>("CvCivil3dEntityInfo")
        .def(init<>())
        .def("isNull", &PyBrxCvCivil3dEntityInfo::isNull)
        .def("name", &PyBrxCvCivil3dEntityInfo::name)
        .def("description", &PyBrxCvCivil3dEntityInfo::description)
        .def("objectId", &PyBrxCvCivil3dEntityInfo::objectId)
        .def("type", &PyBrxCvCivil3dEntityInfo::type)
        .def("alignmentType", &PyBrxCvCivil3dEntityInfo::alignmentType)
        .def("profileType", &PyBrxCvCivil3dEntityInfo::profileType)
        .def("baseAlignment", &PyBrxCvCivil3dEntityInfo::baseAlignment)
        .def("baseSurface", &PyBrxCvCivil3dEntityInfo::baseSurface)
        .def("profiles", &PyBrxCvCivil3dEntityInfo::profiles)
        .def("className", &PyBrxCvCivil3dEntityInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvCivil3dEntityInfo::PyBrxCvCivil3dEntityInfo()
    :pimpl(new BrxCvCivil3dEntityInfo())
{
}

PyBrxCvCivil3dEntityInfo::PyBrxCvCivil3dEntityInfo(const BrxCvCivil3dEntityInfo& info)
    :pimpl(new BrxCvCivil3dEntityInfo(info))
{
}

bool PyBrxCvCivil3dEntityInfo::isNull() const
{
    return impObj()->isNull();
}

std::string PyBrxCvCivil3dEntityInfo::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyBrxCvCivil3dEntityInfo::description() const
{
    return wstr_to_utf8(impObj()->description());
}

PyDbObjectId PyBrxCvCivil3dEntityInfo::objectId() const
{
    return PyDbObjectId(impObj()->objectId());
}

BrxCvCivil3dEntityInfo::Civil3dEntityType PyBrxCvCivil3dEntityInfo::type() const
{
    return impObj()->type();
}

BrxCvCivil3dEntityInfo::Civil3dAlignmentType PyBrxCvCivil3dEntityInfo::alignmentType() const
{
    return impObj()->alignmentType();
}

BrxCvCivil3dEntityInfo::Civil3dProfileType PyBrxCvCivil3dEntityInfo::profileType() const
{
    return impObj()->profileType();
}

PyBrxCvCivil3dEntityInfo PyBrxCvCivil3dEntityInfo::baseAlignment() const
{
    return PyBrxCvCivil3dEntityInfo(impObj()->baseAlignment());
}

PyBrxCvCivil3dEntityInfo PyBrxCvCivil3dEntityInfo::baseSurface() const
{
    return PyBrxCvCivil3dEntityInfo(impObj()->baseSurface());
}

boost::python::list PyBrxCvCivil3dEntityInfo::profiles() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->profiles())
        _pylist.append(PyBrxCvCivil3dEntityInfo(item));
    return _pylist;
}

std::string PyBrxCvCivil3dEntityInfo::className()
{
    return "BrxCvCivil3dEntityInfo";
}

BrxCvCivil3dEntityInfo* PyBrxCvCivil3dEntityInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return pimpl.get();
}

//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dConverter
void makePyBrxCvCivil3dConverterWrapper()
{
    PyDocString DS("CvCivil3dConverter");
    class_<PyBrxCvCivil3dConverter>("CvCivil3dConverter")
        .def(init<>())
        .def(init<const PyDbDatabase&, PyDbDatabase&, BrxCvCivil3dConverter::Civil3dLabels>())
        .def("getCivilEntities", &PyBrxCvCivil3dConverter::getCivilEntities)
        .def("convert", &PyBrxCvCivil3dConverter::convert, DS.ARGS({ "entitiesToConvert : list" }))
        .def("attachedLabels", &PyBrxCvCivil3dConverter::attachedLabels, DS.ARGS({ "civilEntity: PyBrxCv.CvCivil3dEntityInfo" }))
        .def("unattachedLabels", &PyBrxCvCivil3dConverter::unattachedLabels)
        .def("getInsertedEntities", &PyBrxCvCivil3dConverter::getInsertedEntities)
        .def("getInsertedEntities", &PyBrxCvCivil3dConverter::getInsertedEntities)
        .def("className", &PyBrxCvCivil3dConverter::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvCivil3dConverter::PyBrxCvCivil3dConverter()
    : impl(new BrxCvCivil3dConverter())
{
}

PyBrxCvCivil3dConverter::PyBrxCvCivil3dConverter(const PyDbDatabase& sourceDb, PyDbDatabase& targetDb, BrxCvCivil3dConverter::Civil3dLabels doLabels)
    : impl(new BrxCvCivil3dConverter(sourceDb.impObj(), targetDb.impObj(), doLabels))
{
}

bool PyBrxCvCivil3dConverter::isValid() const
{
    return impObj()->isValid();
}

boost::python::list PyBrxCvCivil3dConverter::getCivilEntities() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->getCivilEntities())
        _pylist.append(PyBrxCvCivil3dEntityInfo(item));
    return _pylist;
}

boost::python::list PyBrxCvCivil3dConverter::convert(const boost::python::list& entitiesToConvert)
{
    PyAutoLockGIL lock;
    BrxCvCivil3dEntityInfos infos;

    auto vec = std::vector<PyBrxCvCivil3dEntityInfo>(boost::python::stl_input_iterator<PyBrxCvCivil3dEntityInfo>(entitiesToConvert),
        boost::python::stl_input_iterator<PyBrxCvCivil3dEntityInfo>());

    for (const auto& pyinfo : vec)
        infos.push_back(*pyinfo.impObj());


    boost::python::list _pylist;
    for (const auto& pair_ : impObj()->convert(infos))
        _pylist.append(boost::python::make_tuple(BrxCvCivil3dEntityInfo(pair_.first), PyDbObjectId(pair_.second)));

    return _pylist;
}

boost::python::list PyBrxCvCivil3dConverter::attachedLabels(const PyBrxCvCivil3dEntityInfo& civilEntity) const
{
    return ObjectIdArrayToPyList(impObj()->attachedLabels(*civilEntity.impObj()));
}

boost::python::list PyBrxCvCivil3dConverter::unattachedLabels() const
{
    return ObjectIdArrayToPyList(impObj()->unattachedLabels());
}

boost::python::list PyBrxCvCivil3dConverter::getInsertedEntities() const
{
    return ObjectIdArrayToPyList(impObj()->getInsertedEntities());
}

std::string PyBrxCvCivil3dConverter::className()
{
    return "BrxCvCivil3dConverter";
}

BrxCvCivil3dConverter* PyBrxCvCivil3dConverter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (impl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return impl.get();
}

#endif//BRXAPP
