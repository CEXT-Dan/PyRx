#include "stdafx.h"
#include "PyBrxCvBase.h"
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
        ;
}

PyBrxCvDbSubObject::PyBrxCvDbSubObject(BrxCvDbSubObject* ptr, bool autoDelete)
  : PyRxObject(ptr, autoDelete,false)
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
        .def(init<const PyDbDatabase&, PyDbDatabase&, BrxCvCivil3dConverter::Civil3dLabels>(DS.ARGS({ "sourceDb: PyDb.Database=None", "targetDb: PyDb.Database=None", "doLabels: PyBrxCv.Civil3dLabels=eDefaultLabels" })))
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

//-----------------------------------------------------------------------------------
//PyBrxCvDbView
void makePyBrxCvDbViewWrapper()
{
    PyDocString DS("CvDbView");
    class_<PyBrxCvDbView, bases<PyBrxCvDbEntity>>("CvDbView")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))

        .def("graphCount", &PyBrxCvDbView::graphCount, DS.ARGS())
        .def("graphAt", &PyBrxCvDbView::graphAt, DS.ARGS({ "val : int" }))
        .def("removeGraph", &PyBrxCvDbView::removeGraph)
        .def("baseHAlignment", &PyBrxCvDbView::baseHAlignment, DS.ARGS())
        .def("setBaseHAlignment", &PyBrxCvDbView::setBaseHAlignment, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("origin", &PyBrxCvDbView::origin, DS.ARGS())
        .def("setOrigin", &PyBrxCvDbView::setOrigin, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("baseElevation", &PyBrxCvDbView::baseElevation, DS.ARGS())
        .def("setBaseElevation", &PyBrxCvDbView::setBaseElevation, DS.ARGS({ "val : float" }))
        .def("verticalScale", &PyBrxCvDbView::verticalScale, DS.ARGS())
        .def("setVerticalScale", &PyBrxCvDbView::setVerticalScale, DS.ARGS({ "val : float" }))
        .def("horizontalScale", &PyBrxCvDbView::horizontalScale, DS.ARGS())
        .def("setHorizontalScale", &PyBrxCvDbView::setHorizontalScale, DS.ARGS({ "val : float" }))
        .def("length", &PyBrxCvDbView::length, DS.ARGS())
        .def("setLength", &PyBrxCvDbView::setLength, DS.ARGS({ "val : float" }))
        .def("height", &PyBrxCvDbView::height, DS.ARGS())
        .def("setHeight", &PyBrxCvDbView::setHeight, DS.ARGS({ "val : float" }))
        .def("addGraph", &PyBrxCvDbView::addGraph, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("toWCSX", &PyBrxCvDbView::toWCSX, DS.ARGS({ "val : float" }))
        .def("toWCSY", &PyBrxCvDbView::toWCSY, DS.ARGS({ "val : float" }))
        .def("toWCSPoint2d", &PyBrxCvDbView::toWCSPoint2d, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("fromWCSX", &PyBrxCvDbView::fromWCSX, DS.ARGS({ "val : float" }))
        .def("fromWCSY", &PyBrxCvDbView::fromWCSY, DS.ARGS({ "val : float" }))
        .def("fromWCSPoint2d", &PyBrxCvDbView::fromWCSPoint2d, DS.ARGS({ "pt : PyGe.Point2d" }))

        .def("className", &PyBrxCvDbView::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbView::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbView::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbView::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbView::PyBrxCvDbView()
    : PyBrxCvDbView(new BrxCvDbView(),true)
{
}

PyBrxCvDbView::PyBrxCvDbView(const PyDbObjectId& id)
    : PyBrxCvDbView(openAcDbObject<BrxCvDbView>(id, AcDb::kForRead), false)
{
}

PyBrxCvDbView::PyBrxCvDbView(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbView(openAcDbObject<BrxCvDbView>(id, mode), false)
{
}

PyBrxCvDbView::PyBrxCvDbView(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbView(openAcDbObject<BrxCvDbView>(id, mode, erased), false)
{
}

PyBrxCvDbView::PyBrxCvDbView(BrxCvDbView* ptr, bool autoDelete)
    : PyBrxCvDbEntity(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbView::graphCount() const
{
    return impObj()->graphCount();
}

PyDbObjectId PyBrxCvDbView::graphAt(Adesk::UInt32 idx) const
{
    return PyDbObjectId(impObj()->graphAt(idx));
}

bool PyBrxCvDbView::removeGraph(const PyDbObjectId& idGraph)
{
    return impObj()->removeGraph(idGraph.m_id);
}

PyDbObjectId PyBrxCvDbView::baseHAlignment() const
{
    return PyDbObjectId(impObj()->baseHAlignment());
}

bool PyBrxCvDbView::setBaseHAlignment(const PyDbObjectId& id)
{
    return impObj()->setBaseHAlignment(id.m_id);
}

AcGePoint2d PyBrxCvDbView::origin() const
{
    return impObj()->origin();
}

bool PyBrxCvDbView::setOrigin(const AcGePoint2d& pnt)
{
    return impObj()->setOrigin(pnt);
}

double PyBrxCvDbView::baseElevation() const
{
    return impObj()->baseElevation();
}

bool PyBrxCvDbView::setBaseElevation(double elevation)
{
    return impObj()->setBaseElevation(elevation);
}

double PyBrxCvDbView::verticalScale() const
{
    return impObj()->baseElevation();
}

bool PyBrxCvDbView::setVerticalScale(double vScale)
{
    return impObj()->setVerticalScale(vScale);
}

double PyBrxCvDbView::horizontalScale() const
{
    return impObj()->horizontalScale();
}

bool PyBrxCvDbView::setHorizontalScale(double hScale)
{
    return impObj()->setHorizontalScale(hScale);
}

double PyBrxCvDbView::length() const
{
    return impObj()->length();
}

bool PyBrxCvDbView::setLength(double viewLength)
{
    return impObj()->setLength(viewLength);
}

double PyBrxCvDbView::height() const
{
    return impObj()->height();
}

bool PyBrxCvDbView::setHeight(double viewHeight)
{
    return impObj()->setHeight(viewHeight);
}

bool PyBrxCvDbView::addGraph(const PyDbObjectId& idGraph)
{
    return impObj()->addGraph(idGraph.m_id);
}

double PyBrxCvDbView::toWCSX(double x) const
{
    return impObj()->toWCSX(x);
}

double PyBrxCvDbView::toWCSY(double y) const
{
    return impObj()->toWCSY(y);
}

AcGePoint2d PyBrxCvDbView::toWCSPoint2d(const AcGePoint2d& point) const
{
    return impObj()->toWCSPoint2d(point);
}

double PyBrxCvDbView::fromWCSX(double x) const
{
    return impObj()->fromWCSX(x);
}

double PyBrxCvDbView::fromWCSY(double y) const
{
    return impObj()->fromWCSY(y);
}

AcGePoint2d PyBrxCvDbView::fromWCSPoint2d(const AcGePoint2d& point) const
{
    return impObj()->fromWCSPoint2d(point);
}

std::string PyBrxCvDbView::className()
{
    return "BrxCvDbView";
}

PyRxClass PyBrxCvDbView::desc()
{
    return PyRxClass(BrxCvDbCurve::desc(), false);
}

PyBrxCvDbView PyBrxCvDbView::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbView::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbView(static_cast<BrxCvDbView*>(src.impObj()->clone()), true);
}

PyBrxCvDbView PyBrxCvDbView::cast(const PyRxObject& src)
{
    PyBrxCvDbView dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbView* PyBrxCvDbView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbView*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentView
void makePyBrxCvDbVAlignmentViewWrapper()
{
    PyDocString DS("CvDbVAlignmentView");
    class_<PyBrxCvDbVAlignmentView, bases<PyBrxCvDbView>>("CvDbVAlignmentView")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))

        .def("update", &PyBrxCvDbVAlignmentView::update1)
        .def("update", &PyBrxCvDbVAlignmentView::update2, DS.ARGS({ "bUpdateDependencies : bool=True","updateOrigin : bool=True" }))

        .def("className", &PyBrxCvDbVAlignmentView::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentView::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbVAlignmentView::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbVAlignmentView::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView()
    : PyBrxCvDbVAlignmentView(new BrxCvDbVAlignmentView(), true)
{
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView(const PyDbObjectId& id)
    : PyBrxCvDbVAlignmentView(openAcDbObject<BrxCvDbVAlignmentView>(id,AcDb::kForRead), false)
{
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbVAlignmentView(openAcDbObject<BrxCvDbVAlignmentView>(id, mode), false)
{
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbVAlignmentView(openAcDbObject<BrxCvDbVAlignmentView>(id, mode, erased), false)
{
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView(BrxCvDbVAlignmentView* ptr, bool autoDelete)
    : PyBrxCvDbView(ptr, autoDelete)
{
}

bool PyBrxCvDbVAlignmentView::update1()
{
    return impObj()->update();
}

bool PyBrxCvDbVAlignmentView::update2(bool bUpdateDependencies, bool updateOrigin)
{
    return impObj()->update(bUpdateDependencies, updateOrigin);
}

std::string PyBrxCvDbVAlignmentView::className()
{
    return "BrxCvDbVAlignmentView";
}

PyRxClass PyBrxCvDbVAlignmentView::desc()
{
    return PyRxClass(BrxCvDbVAlignmentView::desc(), false);
}

PyBrxCvDbVAlignmentView PyBrxCvDbVAlignmentView::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbVAlignmentView::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbVAlignmentView(static_cast<BrxCvDbVAlignmentView*>(src.impObj()->clone()), true);
}

PyBrxCvDbVAlignmentView PyBrxCvDbVAlignmentView::cast(const PyRxObject& src)
{
    PyBrxCvDbVAlignmentView dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbVAlignmentView* PyBrxCvDbVAlignmentView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbVAlignmentView*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvStationEquation
void makePyBrxCvStationEquationWrapper()
{
    PyDocString DS("CvStationEquation");
    class_<PyBrxCvStationEquation>("CvStationEquation")
        .def(init<>())
        .def(init<double, double, BrxCvStationEquation::EStationEquationType>())
        .def("isNull", &PyBrxCvStationEquation::isNull, DS.ARGS())
        .def("getRawStation", &PyBrxCvStationEquation::getRawStation, DS.ARGS())
        .def("getStationForward", &PyBrxCvStationEquation::getStationForward, DS.ARGS())
        .def("getType", &PyBrxCvStationEquation::getType, DS.ARGS())
        .def("setRawStation", &PyBrxCvStationEquation::setRawStation, DS.ARGS({ "val : float" }))
        .def("setStationForward", &PyBrxCvStationEquation::setStationForward, DS.ARGS({ "val : float" }))
        .def("setType", &PyBrxCvStationEquation::setType, DS.ARGS({ "val : PyBrxCv.EStationEquationType" }))
        .def("className", &PyBrxCvStationEquation::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvStationEquation::PyBrxCvStationEquation()
    : m_pyImp(new BrxCvStationEquation())
{
}

PyBrxCvStationEquation::PyBrxCvStationEquation(double rawStation, double stationForward, BrxCvStationEquation::EStationEquationType type)
    : m_pyImp(new BrxCvStationEquation(rawStation, stationForward, type))
{
}

PyBrxCvStationEquation::PyBrxCvStationEquation(const BrxCvStationEquation& equation)
    : m_pyImp(new BrxCvStationEquation(equation))
{
}

bool PyBrxCvStationEquation::isNull() const
{
    return impObj()->isNull();
}

double PyBrxCvStationEquation::getRawStation() const
{
    return impObj()->getRawStation();
}

double PyBrxCvStationEquation::getStationForward() const
{
    return impObj()->getStationForward();
}

BrxCvStationEquation::EStationEquationType PyBrxCvStationEquation::getType() const
{
    return impObj()->getType();
}

bool PyBrxCvStationEquation::setRawStation(double rawStation)
{
    return impObj()->setRawStation(rawStation);
}

bool PyBrxCvStationEquation::setStationForward(double stationForward)
{
    return impObj()->setStationForward(stationForward);
}

bool PyBrxCvStationEquation::setType(BrxCvStationEquation::EStationEquationType type)
{
    return impObj()->setType(type);
}

std::string PyBrxCvStationEquation::className()
{
    return "BrxCvStationEquation";
}

BrxCvStationEquation* PyBrxCvStationEquation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvStationEquation*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvStationEquations
void makePyBrxCvStationEquationsWrapper()
{
    PyDocString DS("CvStationEquations");
    class_<PyBrxCvStationEquations>("CvStationEquations")
        .def(init<>())
        .def(init<PyBrxCvDbHAlignment&>())
        .def("stationEquationsCount", &PyBrxCvStationEquations::stationEquationsCount, DS.ARGS())
        .def("getRefStartingLength", &PyBrxCvStationEquations::getRefStartingLength, DS.ARGS())
        .def("getRefRawStartingStation", &PyBrxCvStationEquations::getRefRawStartingStation, DS.ARGS())
        .def("getStartingStation", &PyBrxCvStationEquations::getStartingStation, DS.ARGS())
        .def("getStation", &PyBrxCvStationEquations::getStation, DS.ARGS({ "rawStation : float" }))
        .def("getRawStationFromLength", &PyBrxCvStationEquations::getRawStationFromLength, DS.ARGS({ "length : float" }))
        .def("getLengthFromRawStation", &PyBrxCvStationEquations::getLengthFromRawStation, DS.ARGS({ "rawStation : float" }))
        .def("getStationBack", &PyBrxCvStationEquations::getStationBack, DS.ARGS({ "idx : int" }))
        .def("getRawStation", &PyBrxCvStationEquations::getRawStation, DS.ARGS({ "station : float" }))
        .def("getStationEquation", &PyBrxCvStationEquations::getStationEquation, DS.ARGS({ "idx : int" }))
        .def("setRefStartingLength", &PyBrxCvStationEquations::setRefStartingLength, DS.ARGS({ "startingStation : float" }))
        .def("setRefRawStartingStation", &PyBrxCvStationEquations::setRefRawStartingStation, DS.ARGS({ "rawStartingStation : float" }))
        .def("addStationEquation", &PyBrxCvStationEquations::addStationEquation, DS.ARGS({ "equation : PyBrxCv.CvStationEquation" }))
        .def("removeStationEquation", &PyBrxCvStationEquations::removeStationEquation, DS.ARGS({ "idx : int" }))
        .def("removeAllStationEquations", &PyBrxCvStationEquations::removeAllStationEquations, DS.ARGS())
        .def("update", &PyBrxCvStationEquations::update)
        .def("className", &PyBrxCvStationEquations::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvStationEquations::PyBrxCvStationEquations()
    : m_pyImp(new BrxCvStationEquations())
{
}

PyBrxCvStationEquations::PyBrxCvStationEquations(PyBrxCvDbHAlignment& alignmentPtr)
    : m_pyImp(new BrxCvStationEquations(alignmentPtr.impObj()))
{
}

PyBrxCvStationEquations::PyBrxCvStationEquations(const BrxCvStationEquations& other)
    : m_pyImp(new BrxCvStationEquations(other))
{
}

Adesk::UInt64 PyBrxCvStationEquations::stationEquationsCount() const
{
    return impObj()->stationEquationsCount();
}

double PyBrxCvStationEquations::getRefStartingLength() const
{
    return impObj()->getRefStartingLength();
}

double PyBrxCvStationEquations::getRefRawStartingStation() const
{
    return impObj()->getRefRawStartingStation();
}

double PyBrxCvStationEquations::getStartingStation() const
{
    return impObj()->getStartingStation();
}

double PyBrxCvStationEquations::getStation(double rawStation) const
{
    return impObj()->getStation(rawStation);
}

double PyBrxCvStationEquations::getRawStationFromLength(double length) const
{
    return impObj()->getRawStationFromLength(length);
}

double PyBrxCvStationEquations::getLengthFromRawStation(double rawStation) const
{
    return impObj()->getLengthFromRawStation(rawStation);
}

double PyBrxCvStationEquations::getStationBack(Adesk::UInt64 idx)
{
    return impObj()->getStationBack(idx);
}

boost::python::list PyBrxCvStationEquations::getRawStation(double station) const
{
    return DoubleArrayToPyList(impObj()->getRawStation(station));
}

PyBrxCvStationEquation PyBrxCvStationEquations::getStationEquation(Adesk::UInt64 idx) const
{
    return PyBrxCvStationEquation(impObj()->getStationEquation(idx));
}

bool PyBrxCvStationEquations::setRefStartingLength(double startingStation)
{
    return impObj()->setRefStartingLength(startingStation);
}

bool PyBrxCvStationEquations::setRefRawStartingStation(double rawStartingStation)
{
    return impObj()->setRefRawStartingStation(rawStartingStation);
}

bool PyBrxCvStationEquations::addStationEquation(const PyBrxCvStationEquation& equation)
{
    return impObj()->addStationEquation(*equation.impObj());
}

bool PyBrxCvStationEquations::removeStationEquation(Adesk::UInt64 idx)
{
    return impObj()->removeStationEquation(idx);
}

bool PyBrxCvStationEquations::removeAllStationEquations()
{
    return impObj()->removeAllStationEquations();
}

bool PyBrxCvStationEquations::update()
{
    return impObj()->update();
}

std::string PyBrxCvStationEquations::className()
{
    return "BrxCvStationEquations";
}

BrxCvStationEquations* PyBrxCvStationEquations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvStationEquations*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignment
void makePyBrxCvDbHAlignmentWrapper()
{
    PyDocString DS("CvDbHAlignment");
    class_<PyBrxCvDbHAlignment, bases<PyBrxCvDbCurve>>("CvDbHAlignment")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))

        .def("verticalAlignmentCount", &PyBrxCvDbHAlignment::verticalAlignmentCount)
        .def("verticalAlignmentAt", &PyBrxCvDbHAlignment::verticalAlignmentAt)
        .def("alignment3dCount", &PyBrxCvDbHAlignment::alignment3dCount)
        .def("alignment3dAt", &PyBrxCvDbHAlignment::alignment3dAt)
        .def("verticalAlignmentViewCount", &PyBrxCvDbHAlignment::verticalAlignmentViewCount)
        .def("verticalAlignmentViewAt", &PyBrxCvDbHAlignment::verticalAlignmentViewAt)
        .def("length", &PyBrxCvDbHAlignment::length)
        .def("elementCount", &PyBrxCvDbHAlignment::elementCount)
        .def("getStationAtPoint", &PyBrxCvDbHAlignment::getStationAtPoint1)
        .def("getStationAtPoint", &PyBrxCvDbHAlignment::getStationAtPoint2)
        .def("getPointAtStation", &PyBrxCvDbHAlignment::getPointAtStation)
        .def("firstElementId", &PyBrxCvDbHAlignment::firstElementId)
        .def("lastElementId", &PyBrxCvDbHAlignment::lastElementId)
        .def("firstLineElementId", &PyBrxCvDbHAlignment::firstLineElementId)
        .def("nextLineElementId", &PyBrxCvDbHAlignment::nextLineElementId)
        .def("previousLineElementId", &PyBrxCvDbHAlignment::previousLineElementId)
        .def("getUnorderedElementIds", &PyBrxCvDbHAlignment::getUnorderedElementIds)
        .def("getElementId", &PyBrxCvDbHAlignment::getElementId)
        .def("update", &PyBrxCvDbHAlignment::update)
        .def("getRadius", &PyBrxCvDbHAlignment::getRadius)
        .def("addLineFixed", &PyBrxCvDbHAlignment::addLineFixed1)
        .def("addLineFixed", &PyBrxCvDbHAlignment::addLineFixed2)
        .def("addLineTo", &PyBrxCvDbHAlignment::addLineTo1)
        .def("addLineFrom", &PyBrxCvDbHAlignment::addLineFrom1)
        .def("addLineTo", &PyBrxCvDbHAlignment::addLineTo2)
        .def("addLineFrom", &PyBrxCvDbHAlignment::addLineFrom2)
        .def("addLineBetween", &PyBrxCvDbHAlignment::addLineBetween)
        .def("insertLineFixed", &PyBrxCvDbHAlignment::insertLineFixed)
        .def("addArcAuto", &PyBrxCvDbHAlignment::addArcAuto)
        .def("addArcFixed", &PyBrxCvDbHAlignment::addArcFixed1)
        .def("addArcFixed", &PyBrxCvDbHAlignment::addArcFixed2)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo1)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom1)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo2)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom2)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo3)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom3)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo4)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom4)
        .def("addArcBetween", &PyBrxCvDbHAlignment::addArcBetween1)
        .def("addArcBetween", &PyBrxCvDbHAlignment::addArcBetween2)
        .def("addSCSBetween", &PyBrxCvDbHAlignment::addSCSBetween)
        .def("addSTSBetween", &PyBrxCvDbHAlignment::addSTSBetween)
        .def("addSSBetween", &PyBrxCvDbHAlignment::addSSBetween)
        .def("addSpiralFrom", &PyBrxCvDbHAlignment::addSpiralFrom)
        .def("addSpiralTo", &PyBrxCvDbHAlignment::addSpiralTo)
        .def("addSpiralBetween", &PyBrxCvDbHAlignment::addSpiralBetween)
        .def("addSTFrom", &PyBrxCvDbHAlignment::addSTFrom1)
        .def("addTSTo", &PyBrxCvDbHAlignment::addTSTo1)
        .def("addSTFrom", &PyBrxCvDbHAlignment::addSTFrom2)
        .def("addTSTo", &PyBrxCvDbHAlignment::addTSTo2)
        .def("addSCFrom", &PyBrxCvDbHAlignment::addSCFrom1)
        .def("addCSTo", &PyBrxCvDbHAlignment::addCSTo1)
        .def("addSCFrom", &PyBrxCvDbHAlignment::addSCFrom2)
        .def("addCSTo", &PyBrxCvDbHAlignment::addCSTo2)
        .def("addSSCFrom", &PyBrxCvDbHAlignment::addSSCFrom)
        .def("addCSSTo", &PyBrxCvDbHAlignment::addCSSTo)
        .def("addSCSAuto", &PyBrxCvDbHAlignment::addSCSAuto)
        .def("deleteElement", &PyBrxCvDbHAlignment::deleteElement)
        .def("style", &PyBrxCvDbHAlignment::style)
        .def("setStyle", &PyBrxCvDbHAlignment::setStyle)
        .def("elementExtensionColor", &PyBrxCvDbHAlignment::elementExtensionColor)
        .def("tangentExtensionColor", &PyBrxCvDbHAlignment::tangentExtensionColor)
        .def("lineElementColor", &PyBrxCvDbHAlignment::lineElementColor)
        .def("curveElementColor", &PyBrxCvDbHAlignment::curveElementColor)
        .def("spiralElementColor", &PyBrxCvDbHAlignment::spiralElementColor)
        .def("setElementExtensionColor", &PyBrxCvDbHAlignment::setElementExtensionColor)
        .def("setTangentExtensionColor", &PyBrxCvDbHAlignment::setTangentExtensionColor)
        .def("setLineElementColor", &PyBrxCvDbHAlignment::setLineElementColor)
        .def("setCurveElementColor", &PyBrxCvDbHAlignment::setCurveElementColor)
        .def("setSpiralElementColor", &PyBrxCvDbHAlignment::setSpiralElementColor)
        .def("stationEquations", &PyBrxCvDbHAlignment::stationEquations)
        .def("setStationEquations", &PyBrxCvDbHAlignment::setStationEquations)

        .def("className", &PyBrxCvDbHAlignment::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignment::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbHAlignment::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbHAlignment::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment()
  : PyBrxCvDbHAlignment(new BrxCvDbHAlignment(),true)
{
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment(const PyDbObjectId& id)
    : PyBrxCvDbHAlignment(openAcDbObject<BrxCvDbHAlignment>(id), false)
{
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbHAlignment(openAcDbObject<BrxCvDbHAlignment>(id, mode), false)
{
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbHAlignment(openAcDbObject<BrxCvDbHAlignment>(id, mode, erased), false)
{
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment(BrxCvDbHAlignment* ptr, bool autoDelete)
    :PyBrxCvDbCurve(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbHAlignment::verticalAlignmentCount() const
{
    return impObj()->verticalAlignmentCount();
}

PyDbObjectId PyBrxCvDbHAlignment::verticalAlignmentAt(Adesk::UInt32 index) const
{
    return PyDbObjectId(impObj()->verticalAlignmentAt(index));
}

Adesk::UInt32 PyBrxCvDbHAlignment::alignment3dCount() const
{
    return impObj()->alignment3dCount();
}

PyDbObjectId PyBrxCvDbHAlignment::alignment3dAt(Adesk::UInt32 index) const
{
    return PyDbObjectId(impObj()->alignment3dAt(index));
}

Adesk::UInt32 PyBrxCvDbHAlignment::verticalAlignmentViewCount() const
{
    return impObj()->verticalAlignmentViewCount();
}

PyDbObjectId PyBrxCvDbHAlignment::verticalAlignmentViewAt(Adesk::UInt32 index) const
{
    return PyDbObjectId(impObj()->verticalAlignmentViewAt(index));
}

double PyBrxCvDbHAlignment::length() const
{
    return impObj()->length();
}

size_t PyBrxCvDbHAlignment::elementCount() const
{
    return impObj()->elementCount();
}

boost::python::tuple PyBrxCvDbHAlignment::getStationAtPoint1(const AcGePoint2d& point) const
{
    double station;
    double offset;
    bool flag = impObj()->getStationAtPoint(point, station, offset);
    return boost::python::make_tuple(flag, station, offset);
}

boost::python::tuple PyBrxCvDbHAlignment::getStationAtPoint2(const AcGePoint2d& point, double fromStation, double toStation) const
{
    double station;
    double offset;
    bool flag = impObj()->getStationAtPoint(point, station, offset, &fromStation, &toStation);
    return boost::python::make_tuple(flag, station, offset);
}

boost::python::tuple PyBrxCvDbHAlignment::getPointAtStation(const double station) const
{
    AcGePoint2d pt;
    bool flag = impObj()->getPointAtStation(station, pt);
    return boost::python::make_tuple(flag, pt);
}

Adesk::UInt64 PyBrxCvDbHAlignment::firstElementId() const
{
    return impObj()->firstElementId();
}

Adesk::UInt64 PyBrxCvDbHAlignment::lastElementId() const
{
    return impObj()->lastElementId();
}

Adesk::UInt64 PyBrxCvDbHAlignment::firstLineElementId() const
{
    return impObj()->firstLineElementId();
}

Adesk::UInt64 PyBrxCvDbHAlignment::nextLineElementId(Adesk::UInt64 id) const
{
    return impObj()->nextLineElementId(id);
}

Adesk::UInt64 PyBrxCvDbHAlignment::previousLineElementId(Adesk::UInt64 id) const
{
    return impObj()->previousLineElementId(id);
}

boost::python::list PyBrxCvDbHAlignment::getUnorderedElementIds() const
{
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt64> elementIds;
    PyThrowBadEs(impObj()->getUnorderedElementIds(elementIds));
    return Int64ArrayToPyList(elementIds);
}

Adesk::UInt64 PyBrxCvDbHAlignment::getElementId(Adesk::GsMarker gsMarker) const
{
    return impObj()->getElementId(gsMarker);
}

bool PyBrxCvDbHAlignment::update()
{
    return impObj()->update();
}

double PyBrxCvDbHAlignment::getRadius(double param) const
{
    double r = 0;
    PyThrowBadEs(impObj()->getRadius(param, r));
    return r;
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFixed1(Adesk::UInt64 prevId, double length)
{
    return impObj()->addLineFixed(prevId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint)
{
    return impObj()->addLineFixed(startPoint, endPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineTo1(Adesk::UInt64 nextId, const AcGePoint2d& point)
{
    return impObj()->addLineTo(nextId, point);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFrom1(Adesk::UInt64 prevId, const AcGePoint2d& point)
{
    return impObj()->addLineFrom(prevId, point);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineTo2(Adesk::UInt64 nextId, double length)
{
    return impObj()->addLineTo(nextId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFrom2(Adesk::UInt64 prevId, double length)
{
    return impObj()->addLineFrom(prevId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId)
{
    return impObj()->addLineBetween(prevId, nextId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::insertLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId)
{
    return impObj()->insertLineFixed(startPoint, endPoint, prevId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId)
{
    return impObj()->addArcAuto(prevId, nextId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFixed1(const AcGePoint2d& center, double radius, bool isClockwise)
{
    return impObj()->addArcFixed(center, radius, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& midPoint, const AcGePoint2d& endPoint)
{
    return impObj()->addArcFixed(startPoint, midPoint, endPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo1(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint)
{
    return impObj()->addArcTo(nextId, passThroughPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom1(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint)
{
    return impObj()->addArcFrom(prevId, passThroughPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo2(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction)
{
    return impObj()->addArcTo(nextId, passThroughPoint, direction);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom2(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction)
{
    return impObj()->addArcFrom(prevId, passThroughPoint, direction);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo3(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, double radius, bool isGreaterThan180, EArcType arcType)
{
    return impObj()->addArcTo(nextId, passThroughPoint, radius, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom3(Adesk::UInt64 previous, const AcGePoint2d& passThroughPoint, double radius, bool isGreaterThan180, EArcType arcType)
{
    return impObj()->addArcFrom(previous, passThroughPoint, radius, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo4(Adesk::UInt64 nextId, double radius, double paramValue, EArcParameterType paramType, bool isClockwise)
{
    return impObj()->addArcTo(nextId, radius, paramValue, paramType, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom4(Adesk::UInt64 prevId, double radius, double paramValue, EArcParameterType paramType, bool isClockwise)
{
    return impObj()->addArcFrom(prevId, radius, paramValue, paramType, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcBetween1(Adesk::UInt64 prevId, Adesk::UInt64 nextId, const AcGePoint2d& passThrough)
{
    return impObj()->addArcBetween(prevId, nextId, passThrough);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcBetween2(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double parameter, EArcParameterType paramType, bool isGreaterThan180, EArcType arcType)
{
    return impObj()->addArcBetween(prevId, nextId, parameter, paramType, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiral1, double spiral2, ESpiralParameterType spiralType, double radius, ESpiralDefinitionType spiralDef)
{
    return impObj()->addSCSBetween(prevId, nextId, spiral1, spiral2, spiralType, radius, spiralDef);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiral1Param, double spiral2Param,ESpiralParameterType spiralParamType,ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSTSBetween(prevId, nextId, spiral1Param, spiral2Param, spiralParamType, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiralRatio, ESpiralParameterType spiralParamType, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSSBetween(prevId, nextId, spiralRatio, spiralParamType, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralFrom(Adesk::UInt64 prevId, double radius, double length, bool isClockwise, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSpiralFrom(prevId, radius, length, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralTo(Adesk::UInt64 nextId, double radius, double length, bool isClockwise,ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSpiralTo(nextId, radius, length, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSpiralBetween(prevId, nextId, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTFrom1(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSTFrom(prevId, spiralParam, spiralParamType, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addTSTo1(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addTSTo(nextId, spiralParam, spiralParamType, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addTSTo2(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double tangentLength, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addTSTo(nextId, spiralParam, spiralParamType, tangentLength, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCFrom1(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, bool isGreaterThan180, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSCFrom(prevId, spiralParam, spiralParamType, radius, passThroughPoint, isGreaterThan180, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSTo1(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, bool isGreaterThan180,ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addCSTo(nextId, spiralParam, spiralParamType, radius, passThroughPoint, isGreaterThan180, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCFrom2(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double radius, double arcLength, bool isClockwise, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSCFrom(prevId, spiralParam, spiralParamType, radius, arcLength, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSTo2(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double radius, double arcLength, bool isClockwise, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addCSTo(nextId, spiralParam, spiralParamType, radius, arcLength, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSSCFrom(Adesk::UInt64 prevId, double spiral1Param, double spiral2Param, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSSCFrom(prevId, spiral1Param, spiral2Param, spiralParamType, radius, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSSTo(Adesk::UInt64 nextId, double spiral1Param, double spiral2Param, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addCSSTo(nextId, spiral1Param, spiral2Param, spiralParamType, radius, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCSAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId)
{
    return impObj()->addSCSAuto(nextId, nextId);
}

bool PyBrxCvDbHAlignment::deleteElement(Adesk::UInt64 id)
{
    return impObj()->deleteElement(id);
}

Adesk::UInt32 PyBrxCvDbHAlignment::style() const
{
    return impObj()->style();
}

bool PyBrxCvDbHAlignment::setStyle(const Adesk::UInt32 style)
{
    return impObj()->setStyle(style);
}

Adesk::UInt32 PyBrxCvDbHAlignment::elementExtensionColor() const
{
    return impObj()->elementExtensionColor();
}

Adesk::UInt32 PyBrxCvDbHAlignment::tangentExtensionColor() const
{
    return impObj()->tangentExtensionColor();
}

Adesk::UInt32 PyBrxCvDbHAlignment::lineElementColor() const
{
    return impObj()->lineElementColor();
}

Adesk::UInt32 PyBrxCvDbHAlignment::curveElementColor() const
{
    return impObj()->curveElementColor();
}

Adesk::UInt32 PyBrxCvDbHAlignment::spiralElementColor() const
{
    return impObj()->spiralElementColor();
}

bool PyBrxCvDbHAlignment::setElementExtensionColor(const Adesk::UInt32 color)
{
    return impObj()->setElementExtensionColor(color);
}

bool PyBrxCvDbHAlignment::setTangentExtensionColor(const Adesk::UInt32 color)
{
    return impObj()->setTangentExtensionColor(color);
}

bool PyBrxCvDbHAlignment::setLineElementColor(const Adesk::UInt32 color)
{
    return impObj()->setLineElementColor(color);
}

bool PyBrxCvDbHAlignment::setCurveElementColor(const Adesk::UInt32 color)
{
    return impObj()->setCurveElementColor(color);
}

bool PyBrxCvDbHAlignment::setSpiralElementColor(const Adesk::UInt32 color)
{
    return impObj()->setSpiralElementColor(color);
}

PyBrxCvStationEquations PyBrxCvDbHAlignment::stationEquations() const
{
    return PyBrxCvStationEquations(impObj()->stationEquations());
}

bool PyBrxCvDbHAlignment::setStationEquations(const PyBrxCvStationEquations& stationEquations)
{
    return impObj()->setStationEquations(*stationEquations.impObj());
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTFrom2(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double tangentLength,ESpiralDefinitionType spiralDefinition)
{
    return impObj()->addSTFrom(prevId, spiralParam, spiralParamType, tangentLength, spiralDefinition);
}

std::string PyBrxCvDbHAlignment::className()
{
    return "BrxCvDbHAlignment";
}

PyRxClass PyBrxCvDbHAlignment::desc()
{
    return PyRxClass(BrxCvDbHAlignment::desc(), false);
}

PyBrxCvDbHAlignment PyBrxCvDbHAlignment::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbHAlignment::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbHAlignment(static_cast<BrxCvDbHAlignment*>(src.impObj()->clone()), true);
}

PyBrxCvDbHAlignment PyBrxCvDbHAlignment::cast(const PyRxObject& src)
{
    PyBrxCvDbHAlignment dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbHAlignment* PyBrxCvDbHAlignment::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbHAlignment*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentElement
void makePyBrxCvDbHAlignmentElementWrapper()
{
    PyDocString DS("CvDbHAlignmentElement");
    class_<PyBrxCvDbHAlignmentElement, bases<PyBrxCvDbSubObject>>("CvDbHAlignmentElement", boost::python::no_init)
        .def("id", &PyBrxCvDbHAlignmentElement::id, DS.ARGS())
        .def("previousId", &PyBrxCvDbHAlignmentElement::previousId, DS.ARGS())
        .def("nextId", &PyBrxCvDbHAlignmentElement::nextId, DS.ARGS())
        .def("type", &PyBrxCvDbHAlignmentElement::type, DS.ARGS())
        .def("tangencyConstraint", &PyBrxCvDbHAlignmentElement::tangencyConstraint, DS.ARGS())
        .def("parameterConstraint", &PyBrxCvDbHAlignmentElement::parameterConstraint, DS.ARGS())
        .def("isSubentity", &PyBrxCvDbHAlignmentElement::isSubentity, DS.ARGS())
        .def("setPreviousId", &PyBrxCvDbHAlignmentElement::setPreviousId, DS.ARGS({ "val : int" }))
        .def("setNextId", &PyBrxCvDbHAlignmentElement::setNextId, DS.ARGS({ "val : int" }))
        .def("setTangencyConstraint", &PyBrxCvDbHAlignmentElement::setTangencyConstraint, DS.ARGS({ "val : PyBrxCv.ETangencyConstraint" }))
        .def("setParameterConstraint", &PyBrxCvDbHAlignmentElement::setParameterConstraint, DS.ARGS({ "val : PyBrxCv.EParameterConstraint" }))
        .def("className", &PyBrxCvDbHAlignmentElement::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentElement::desc, DS.SARGS()).staticmethod("desc")
        ;
}

Adesk::UInt64 PyBrxCvDbHAlignmentElement::id() const
{
    return impObj()->id();
}

Adesk::UInt64 PyBrxCvDbHAlignmentElement::previousId() const
{
    return impObj()->previousId();
}

Adesk::UInt64 PyBrxCvDbHAlignmentElement::nextId() const
{
    return impObj()->nextId();
}

PyBrxCvDbHAlignmentElement::EElementType PyBrxCvDbHAlignmentElement::type() const
{
    return impObj()->type();
}

PyBrxCvDbHAlignmentElement::ETangencyConstraint PyBrxCvDbHAlignmentElement::tangencyConstraint() const
{
    return impObj()->tangencyConstraint();
}

PyBrxCvDbHAlignmentElement::EParameterConstraint PyBrxCvDbHAlignmentElement::parameterConstraint() const
{
    return impObj()->parameterConstraint();
}

bool PyBrxCvDbHAlignmentElement::isSubentity() const
{
    return impObj()->isSubentity();
}

bool PyBrxCvDbHAlignmentElement::setPreviousId(Adesk::UInt64 id)
{
    return impObj()->setPreviousId(id);
}

bool PyBrxCvDbHAlignmentElement::setNextId(Adesk::UInt64 id)
{
    return impObj()->setNextId(id);
}

bool PyBrxCvDbHAlignmentElement::setTangencyConstraint(ETangencyConstraint constraint)
{
    return impObj()->setTangencyConstraint(constraint);
}

bool PyBrxCvDbHAlignmentElement::setParameterConstraint(EParameterConstraint constraint)
{
    return impObj()->setParameterConstraint(constraint);
}

std::string PyBrxCvDbHAlignmentElement::className()
{
    return "BrxCvDbHAlignmentElement";
}

PyRxClass PyBrxCvDbHAlignmentElement::desc()
{
    return PyRxClass(BrxCvDbHAlignmentElement::desc(), false);
}

BrxCvDbHAlignmentElement* PyBrxCvDbHAlignmentElement::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbHAlignmentElement*>(m_pyImp.get());
}

#endif//BRXAPP