#include "stdafx.h"

#ifdef BRXAPP
#include "PyBrxCvDbObjectManager.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyBrxCvDbObjectManagerWrapper()
{
    PyDocString DS("CvDbObjectManager");
    class_<PyBrxCvDbObjectManager, bases<PyBrxCvDbObject>>("CvDbObjectManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("elementCount", &PyBrxCvDbObjectManager::elementCount, DS.ARGS())
        .def("ids", &PyBrxCvDbObjectManager::ids)
        .def("names", &PyBrxCvDbObjectManager::names, DS.ARGS())
        .def("idAt", &PyBrxCvDbObjectManager::idAt1)
        .def("idAt", &PyBrxCvDbObjectManager::idAt2, DS.ARGS({ "val : int|str" }))
        .def("nameAt", &PyBrxCvDbObjectManager::nameAt, DS.ARGS({ "val : int" }))
        .def("has", &PyBrxCvDbObjectManager::has1)
        .def("has", &PyBrxCvDbObjectManager::has2, DS.ARGS({ "id : str|PyDb.ObjectId" }))
        .def("toDict", &PyBrxCvDbObjectManager::toDict, DS.ARGS())
        .def("remove", &PyBrxCvDbObjectManager::remove1)
        .def("remove", &PyBrxCvDbObjectManager::remove2, DS.ARGS({ "id : str|PyDb.ObjectId" }))
        .def("className", &PyBrxCvDbObjectManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbObjectManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbObjectManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbObjectManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("__getitem__", &PyBrxCvDbObjectManager::idAt1)
        .def("__getitem__", &PyBrxCvDbObjectManager::idAt2, DS.ARGS({ "val : int|str" }))
        .def("__contains__", &PyBrxCvDbObjectManager::has1)
        .def("__contains__", &PyBrxCvDbObjectManager::has2, DS.ARGS({ "id : str|PyDb.ObjectId" }))
        ;
}

PyBrxCvDbObjectManager::PyBrxCvDbObjectManager(const PyDbObjectId& id)
    : PyBrxCvDbObjectManager(openAcDbObject<BrxCvDbObjectManager>(id), false)
{
}

PyBrxCvDbObjectManager::PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbObjectManager(openAcDbObject<BrxCvDbObjectManager>(id, mode), false)
{
}

PyBrxCvDbObjectManager::PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbObjectManager(openAcDbObject<BrxCvDbObjectManager>(id, mode, erased), false)
{
}

PyBrxCvDbObjectManager::PyBrxCvDbObjectManager(BrxCvDbObjectManager* ptr, bool autoDelete)
    :PyBrxCvDbObject(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbObjectManager::elementCount()
{
    return impObj()->elementCount();
}

boost::python::list PyBrxCvDbObjectManager::ids()
{
    return ObjectIdArrayToPyList(impObj()->ids());
}

boost::python::list PyBrxCvDbObjectManager::names()
{
    return AcStringArrayToPyList(impObj()->names());
}

PyDbObjectId PyBrxCvDbObjectManager::idAt1(const Adesk::UInt32 index)
{
    return PyDbObjectId(impObj()->idAt(index));
}

PyDbObjectId PyBrxCvDbObjectManager::idAt2(const std::string& szName)
{
    return PyDbObjectId(impObj()->idAt(utf8_to_wstr(szName).c_str()));
}

std::string PyBrxCvDbObjectManager::nameAt(const Adesk::UInt32 index)
{
    return wstr_to_utf8(impObj()->nameAt(index));
}

bool PyBrxCvDbObjectManager::has1(const PyDbObjectId& id)
{
    return impObj()->has(id.m_id);
}

bool PyBrxCvDbObjectManager::has2(const std::string& szName)
{
    return impObj()->has(utf8_to_wstr(szName).c_str());
}

bool PyBrxCvDbObjectManager::remove1(const PyDbObjectId& id)
{
    return impObj()->remove(id.m_id);
}

bool PyBrxCvDbObjectManager::remove2(const std::string& szName)
{
    return impObj()->remove(utf8_to_wstr(szName).c_str());
}

boost::python::dict PyBrxCvDbObjectManager::toDict()
{
    PyAutoLockGIL lock;
    boost::python::dict _dict;
#if defined(_BRXTARGET240)
    PyThrowBadEs(eNotImplemented);
#else
    auto iter = impObj()->objectIterator();
    for (iter->start(); !iter->done(); iter->step())
        _dict[wstr_to_utf8(iter->name())] = PyDbObjectId{ iter->objectId() };
#endif
    return _dict;
}

std::string PyBrxCvDbObjectManager::className()
{
    return "BrxCvDbObjectManager";
}

PyRxClass PyBrxCvDbObjectManager::desc()
{
    return PyRxClass(BrxCvDbObjectManager::desc(), false);
}

PyBrxCvDbObjectManager PyBrxCvDbObjectManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbObjectManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbObjectManager(static_cast<BrxCvDbObjectManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbObjectManager PyBrxCvDbObjectManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbObjectManager>(src);
}

BrxCvDbObjectManager* PyBrxCvDbObjectManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbObjectManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbFileFormatManager
void makePyBrxCvDbFileFormatManagerWrapper()
{
    PyDocString DS("CvDbFileFormatManager");
    class_<PyBrxCvDbFileFormatManager, bases<PyBrxCvDbObjectManager>>("CvDbFileFormatManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id:  PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("applicableFileFormats", &PyBrxCvDbFileFormatManager::applicableFileFormats, DS.ARGS({ "val : str" }))
        .def("allFileFormats", &PyBrxCvDbFileFormatManager::allFileFormats, DS.ARGS())
        .def("getManager", &PyBrxCvDbFileFormatManager::getManager, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManager")
        .def("openManager", &PyBrxCvDbFileFormatManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")

        .def("className", &PyBrxCvDbFileFormatManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbFileFormatManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbFileFormatManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbFileFormatManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbFileFormatManager::PyBrxCvDbFileFormatManager(const PyDbObjectId& id)
    : PyBrxCvDbFileFormatManager(openAcDbObject<BrxCvDbFileFormatManager>(id), false)
{
}

PyBrxCvDbFileFormatManager::PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbFileFormatManager(openAcDbObject<BrxCvDbFileFormatManager>(id, mode), false)
{
}

PyBrxCvDbFileFormatManager::PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbFileFormatManager(openAcDbObject<BrxCvDbFileFormatManager>(id, mode, erased), false)
{
}

PyBrxCvDbFileFormatManager::PyBrxCvDbFileFormatManager(BrxCvDbFileFormatManager* ptr, bool autoDelete)
    : PyBrxCvDbObjectManager(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbFileFormatManager::applicableFileFormats(const std::string& fileName)
{
    return ObjectIdArrayToPyList(impObj()->applicableFileFormats(utf8_to_wstr(fileName).c_str()));
}

boost::python::list PyBrxCvDbFileFormatManager::allFileFormats()
{
    return ObjectIdArrayToPyList(impObj()->allFileFormats());
}

PyDbObjectId PyBrxCvDbFileFormatManager::getManager(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbFileFormatManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbFileFormatManager PyBrxCvDbFileFormatManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbFileFormatManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbFileFormatManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbFileFormatManager(ptr, true);
}

std::string PyBrxCvDbFileFormatManager::className()
{
    return "BrxCvDbFileFormatManager";
}

PyRxClass PyBrxCvDbFileFormatManager::desc()
{
    return PyRxClass(BrxCvDbFileFormatManager::desc(), false);
}

PyBrxCvDbFileFormatManager PyBrxCvDbFileFormatManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbFileFormatManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbFileFormatManager(static_cast<BrxCvDbFileFormatManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbFileFormatManager PyBrxCvDbFileFormatManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbFileFormatManager>(src);
}

BrxCvDbFileFormatManager* PyBrxCvDbFileFormatManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbFileFormatManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbStyleManager

void makePyBrxCvDbStyleManagerWrapper()
{
    PyDocString DS("CvDbStyleManager");
    class_<PyBrxCvDbStyleManager, bases<PyBrxCvDbObjectManager>>("CvDbStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("getManager", &PyBrxCvDbStyleManager::getManager, DS.SARGS({ "db: PyDb.Database" , "styleType: PyBrxCv.StyleManagerType" })).staticmethod("getManager")
        .def("openManager", &PyBrxCvDbStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode","styleType: PyBrxCv.StyleManagerType" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStyleManager::PyBrxCvDbStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbStyleManager(openAcDbObject<BrxCvDbStyleManager>(id), false)
{
}

PyBrxCvDbStyleManager::PyBrxCvDbStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStyleManager(openAcDbObject<BrxCvDbStyleManager>(id, mode), false)
{
}

PyBrxCvDbStyleManager::PyBrxCvDbStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStyleManager(openAcDbObject<BrxCvDbStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbStyleManager::PyBrxCvDbStyleManager(BrxCvDbStyleManager* ptr, bool autoDelete)
    : PyBrxCvDbObjectManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbStyleManager::getManager(PyDbDatabase& db, EStyleManagerType styleType)
{
    PyDbObjectId id;
    switch (styleType)
    {
        case PyBrxCvDbStyleManager::eSymbolStyle:
        {
            PyThrowBadEs(BrxCvDbSymbolStyleManager::getManager(id.m_id, db.impObj()));
            break;
        }
        case PyBrxCvDbStyleManager::eLineLabel:
        {
#if defined(_BRXTARGET240)
            PyThrowBadEs(eNotImplemented);
#else
            PyThrowBadEs(BrxCvDbLineLabelStyleManager::getManager(id.m_id, db.impObj()));
#endif
            break;
        }
        case PyBrxCvDbStyleManager::eCurveLabel:
        {
#if defined(_BRXTARGET240)
            PyThrowBadEs(eNotImplemented);
#else
            PyThrowBadEs(BrxCvDbCurveLabelStyleManager::getManager(id.m_id, db.impObj()));
#endif
            break;
        }
        case PyBrxCvDbStyleManager::ePointLabel:
        {
            PyThrowBadEs(BrxCvDbPointLabelStyleManager::getManager(id.m_id, db.impObj()));
            break;
        }
        case PyBrxCvDbStyleManager::eContourLabel:
        {
            PyThrowBadEs(BrxCvDbSurfaceContourLabelStyleManager::getManager(id.m_id, db.impObj()));
            break;
        }
        case PyBrxCvDbStyleManager::eSurfaceElevationLabel:
        {
            PyThrowBadEs(BrxCvDbSurfaceElevationLabelStyleManager::getManager(id.m_id, db.impObj()));
            break;
        }
        case PyBrxCvDbStyleManager::eSurfaceSlopeLabel:
        {
            PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::getManager(id.m_id, db.impObj()));
            break;
        }
        default:
            PyThrowBadEs(eInvalidInput);
            break;
    }
    return id;
}

PyBrxCvDbObjectManager PyBrxCvDbStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode, EStyleManagerType styleType)
{
    switch (styleType)
    {
        case PyBrxCvDbStyleManager::ePointLabel:
        {
            BrxCvDbPointLabelStyleManager* ptr = nullptr;
            PyThrowBadEs(BrxCvDbPointLabelStyleManager::openManager(ptr, db.impObj(), mode));
            return PyBrxCvDbObjectManager(ptr, true);
        }
        case PyBrxCvDbStyleManager::eContourLabel:
        {
            BrxCvDbSurfaceContourLabelStyleManager* ptr = nullptr;
            PyThrowBadEs(BrxCvDbSurfaceContourLabelStyleManager::openManager(ptr, db.impObj(), mode));
            return PyBrxCvDbObjectManager(ptr, true);
        }
        case PyBrxCvDbStyleManager::eSurfaceElevationLabel:
        {
            BrxCvDbSurfaceElevationLabelStyleManager* ptr = nullptr;
            PyThrowBadEs(BrxCvDbSurfaceElevationLabelStyleManager::openManager(ptr, db.impObj(), mode));
            return PyBrxCvDbObjectManager(ptr, true);
        }
        case PyBrxCvDbStyleManager::eSurfaceSlopeLabel:
        {
            BrxCvDbSurfaceSlopeLabelStyleManager* ptr = nullptr;
            PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::openManager(ptr, db.impObj(), mode));
            return PyBrxCvDbObjectManager(ptr, true);
        }
        case PyBrxCvDbStyleManager::eSymbolStyle:
        {
            BrxCvDbSymbolStyleManager* ptr = nullptr;
            PyThrowBadEs(BrxCvDbSymbolStyleManager::openManager(ptr, db.impObj(), mode));
            return PyBrxCvDbObjectManager(ptr, true);
        }
        default:
            PyThrowBadEs(eInvalidInput);
            break;
    }
    return PyBrxCvDbObjectManager(nullptr, false);;
}

std::string PyBrxCvDbStyleManager::className()
{
    return "BrxCvDbStyleManager";
}

PyRxClass PyBrxCvDbStyleManager::desc()
{
    return PyRxClass(BrxCvDbStyleManager::desc(), false);
}

PyBrxCvDbStyleManager PyBrxCvDbStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbStyleManager(static_cast<BrxCvDbStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbStyleManager PyBrxCvDbStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbStyleManager>(src);
}

BrxCvDbStyleManager* PyBrxCvDbStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbPointGroupManager
void makePyBrxCvDbPointGroupManagerWrapper()
{
    PyDocString DS("CvDbPointGroupManager");
    class_<PyBrxCvDbPointGroupManager, bases<PyBrxCvDbObjectManager>>("CvDbPointGroupManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("createPointGroup", &PyBrxCvDbPointGroupManager::createPointGroup, DS.ARGS({ "val : str" }))
        .def("groupsWithPoint", &PyBrxCvDbPointGroupManager::groupsWithPoint, DS.ARGS({ "val : int" }))
        .def("updatePointGroups", &PyBrxCvDbPointGroupManager::updatePointGroups, DS.ARGS())
        .def("nextPointNumber", &PyBrxCvDbPointGroupManager::nextPointNumber, DS.ARGS())
        .def("setNextPointNumber", &PyBrxCvDbPointGroupManager::setNextPointNumber, DS.ARGS({ "val : int" }))

        .def("getManagerId", &PyBrxCvDbPointGroupManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbPointGroupManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbPointGroupManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointGroupManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbPointGroupManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbPointGroupManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPointGroupManager::PyBrxCvDbPointGroupManager(const PyDbObjectId& id)
    : PyBrxCvDbPointGroupManager(openAcDbObject<BrxCvDbPointGroupManager>(id), false)
{
}

PyBrxCvDbPointGroupManager::PyBrxCvDbPointGroupManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbPointGroupManager(openAcDbObject<BrxCvDbPointGroupManager>(id, mode), false)
{
}

PyBrxCvDbPointGroupManager::PyBrxCvDbPointGroupManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbPointGroupManager(openAcDbObject<BrxCvDbPointGroupManager>(id, mode, erased), false)
{
}

PyBrxCvDbPointGroupManager::PyBrxCvDbPointGroupManager(BrxCvDbPointGroupManager* ptr, bool autoDelete)
    :PyBrxCvDbObjectManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbPointGroupManager::createPointGroup(const std::string& szName)
{
    return PyDbObjectId(impObj()->createPointGroup(utf8_to_wstr(szName).c_str()));
}

boost::python::list PyBrxCvDbPointGroupManager::groupsWithPoint(Adesk::UInt32 number) const
{
    return ObjectIdArrayToPyList(impObj()->groupsWithPoint(number));
}

Adesk::UInt32 PyBrxCvDbPointGroupManager::updatePointGroups()
{
    return impObj()->updatePointGroups();
}

Adesk::UInt32 PyBrxCvDbPointGroupManager::nextPointNumber() const
{
    return impObj()->nextPointNumber();
}

bool PyBrxCvDbPointGroupManager::setNextPointNumber(Adesk::UInt32 number)
{
    return impObj()->setNextPointNumber(number);
}

PyDbObjectId PyBrxCvDbPointGroupManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbPointGroupManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbPointGroupManager PyBrxCvDbPointGroupManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbPointGroupManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbPointGroupManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbPointGroupManager(ptr, true);
}

std::string PyBrxCvDbPointGroupManager::className()
{
    return "BrxCvDbPointGroupManager";
}

PyRxClass PyBrxCvDbPointGroupManager::desc()
{
    return PyRxClass(BrxCvDbPointGroupManager::desc(), false);
}

PyBrxCvDbPointGroupManager PyBrxCvDbPointGroupManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbPointGroupManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbPointGroupManager(static_cast<BrxCvDbPointGroupManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbPointGroupManager PyBrxCvDbPointGroupManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbPointGroupManager>(src);
}

BrxCvDbPointGroupManager* PyBrxCvDbPointGroupManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbPointGroupManager*>(m_pyImp.get());
}

#if !defined(_BRXTARGET240)
//-----------------------------------------------------------------------------------
// PyBrxCvDbSymbolStyleManager
void makePyBrxCvDbSymbolStyleManagerWrapper()
{
    PyDocString DS("CvDbSymbolStyleManager");
    class_<PyBrxCvDbSymbolStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbSymbolStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createSymbolStyle", &PyBrxCvDbSymbolStyleManager::createSymbolStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbSymbolStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbSymbolStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbSymbolStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbSymbolStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSymbolStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbSymbolStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbSymbolStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSymbolStyleManager::PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbSymbolStyleManager(openAcDbObject<BrxCvDbSymbolStyleManager>(id), false)
{
}

PyBrxCvDbSymbolStyleManager::PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbSymbolStyleManager(openAcDbObject<BrxCvDbSymbolStyleManager>(id, mode), false)
{
}

PyBrxCvDbSymbolStyleManager::PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbSymbolStyleManager(openAcDbObject<BrxCvDbSymbolStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbSymbolStyleManager::PyBrxCvDbSymbolStyleManager(BrxCvDbSymbolStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbSymbolStyleManager::createSymbolStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createSymbolStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbSymbolStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbSymbolStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbSymbolStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbSymbolStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbSymbolStyleManager PyBrxCvDbSymbolStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbSymbolStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbSymbolStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbSymbolStyleManager(ptr, true);
}

std::string PyBrxCvDbSymbolStyleManager::className()
{
    return "BrxCvDbSymbolStyleManager";
}

PyRxClass PyBrxCvDbSymbolStyleManager::desc()
{
    return PyRxClass(BrxCvDbSymbolStyleManager::desc(), false);
}

PyBrxCvDbSymbolStyleManager PyBrxCvDbSymbolStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbSymbolStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbSymbolStyleManager(static_cast<BrxCvDbSymbolStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbSymbolStyleManager PyBrxCvDbSymbolStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSymbolStyleManager>(src);
}

BrxCvDbSymbolStyleManager* PyBrxCvDbSymbolStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSymbolStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbLineLabelStyleManager
void makePyBrxCvDbLineLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbLineLabelStyleManager");
    class_<PyBrxCvDbLineLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbLineLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbLineLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbLineLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbLineLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbLineLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbLineLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLineLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbLineLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbLineLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLineLabelStyleManager::PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbLineLabelStyleManager(openAcDbObject<BrxCvDbLineLabelStyleManager>(id), false)
{
}

PyBrxCvDbLineLabelStyleManager::PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbLineLabelStyleManager(openAcDbObject<BrxCvDbLineLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbLineLabelStyleManager::PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbLineLabelStyleManager(openAcDbObject<BrxCvDbLineLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbLineLabelStyleManager::PyBrxCvDbLineLabelStyleManager(BrxCvDbLineLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbLineLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbLineLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbLineLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbLineLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbLineLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbLineLabelStyleManager PyBrxCvDbLineLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbLineLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbLineLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbLineLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbLineLabelStyleManager::className()
{
    return "BrxCvDbLineLabelStyleManager";
}

PyRxClass PyBrxCvDbLineLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbLineLabelStyleManager::desc(), false);
}

PyBrxCvDbLineLabelStyleManager PyBrxCvDbLineLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbLineLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbLineLabelStyleManager(static_cast<BrxCvDbLineLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbLineLabelStyleManager PyBrxCvDbLineLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLineLabelStyleManager>(src);
}

BrxCvDbLineLabelStyleManager* PyBrxCvDbLineLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLineLabelStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbCurveLabelStyleManager
void makePyBrxCvDbCurveLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbCurveLabelStyleManager");
    class_<PyBrxCvDbCurveLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbCurveLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbCurveLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbCurveLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbCurveLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbCurveLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbCurveLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbCurveLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbCurveLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbCurveLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbCurveLabelStyleManager::PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbCurveLabelStyleManager(openAcDbObject<BrxCvDbCurveLabelStyleManager>(id), false)
{
}

PyBrxCvDbCurveLabelStyleManager::PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbCurveLabelStyleManager(openAcDbObject<BrxCvDbCurveLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbCurveLabelStyleManager::PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbCurveLabelStyleManager(openAcDbObject<BrxCvDbCurveLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbCurveLabelStyleManager::PyBrxCvDbCurveLabelStyleManager(BrxCvDbCurveLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbCurveLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbCurveLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbCurveLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbCurveLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbCurveLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbCurveLabelStyleManager PyBrxCvDbCurveLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbCurveLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbCurveLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbCurveLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbCurveLabelStyleManager::className()
{
    return "BrxCvDbCurveLabelStyleManager";
}

PyRxClass PyBrxCvDbCurveLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbCurveLabelStyleManager::desc(), false);
}

PyBrxCvDbCurveLabelStyleManager PyBrxCvDbCurveLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbCurveLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbCurveLabelStyleManager(static_cast<BrxCvDbCurveLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbCurveLabelStyleManager PyBrxCvDbCurveLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbCurveLabelStyleManager>(src);
}

BrxCvDbCurveLabelStyleManager* PyBrxCvDbCurveLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbCurveLabelStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbPointLabelStyleManager
void makePyBrxCvDbPointLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbPointLabelStyleManager");
    class_<PyBrxCvDbPointLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbPointLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbPointLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbPointLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbPointLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbPointLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbPointLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbPointLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbPointLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPointLabelStyleManager::PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbPointLabelStyleManager(openAcDbObject<BrxCvDbPointLabelStyleManager>(id), false)
{
}

PyBrxCvDbPointLabelStyleManager::PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbPointLabelStyleManager(openAcDbObject<BrxCvDbPointLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbPointLabelStyleManager::PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbPointLabelStyleManager(openAcDbObject<BrxCvDbPointLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbPointLabelStyleManager::PyBrxCvDbPointLabelStyleManager(BrxCvDbPointLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbPointLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbPointLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbPointLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbPointLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbPointLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbPointLabelStyleManager PyBrxCvDbPointLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbPointLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbPointLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbPointLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbPointLabelStyleManager::className()
{
    return "BrxCvDbPointLabelStyleManager";
}

PyRxClass PyBrxCvDbPointLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbPointLabelStyleManager::desc(), false);
}

PyBrxCvDbPointLabelStyleManager PyBrxCvDbPointLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbPointLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbPointLabelStyleManager(static_cast<BrxCvDbPointLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbPointLabelStyleManager PyBrxCvDbPointLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbPointLabelStyleManager>(src);
}

BrxCvDbPointLabelStyleManager* PyBrxCvDbPointLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbPointLabelStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceContourLabelStyleManager
void makePyBrxCvDbSurfaceContourLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbSurfaceContourLabelStyleManager");
    class_<PyBrxCvDbSurfaceContourLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbSurfaceContourLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbSurfaceContourLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbSurfaceContourLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbSurfaceContourLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbSurfaceContourLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbSurfaceContourLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSurfaceContourLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbSurfaceContourLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbSurfaceContourLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSurfaceContourLabelStyleManager::PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbSurfaceContourLabelStyleManager(openAcDbObject<BrxCvDbSurfaceContourLabelStyleManager>(id), false)
{
}

PyBrxCvDbSurfaceContourLabelStyleManager::PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbSurfaceContourLabelStyleManager(openAcDbObject<BrxCvDbSurfaceContourLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbSurfaceContourLabelStyleManager::PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbSurfaceContourLabelStyleManager(openAcDbObject<BrxCvDbSurfaceContourLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbSurfaceContourLabelStyleManager::PyBrxCvDbSurfaceContourLabelStyleManager(BrxCvDbSurfaceContourLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbSurfaceContourLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbSurfaceContourLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbSurfaceContourLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbSurfaceContourLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbSurfaceContourLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbSurfaceContourLabelStyleManager PyBrxCvDbSurfaceContourLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbSurfaceContourLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbSurfaceContourLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbSurfaceContourLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbSurfaceContourLabelStyleManager::className()
{
    return "BrxCvDbSurfaceContourLabelStyleManager";
}

PyRxClass PyBrxCvDbSurfaceContourLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbSurfaceContourLabelStyleManager::desc(), false);
}

PyBrxCvDbSurfaceContourLabelStyleManager PyBrxCvDbSurfaceContourLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbSurfaceContourLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbSurfaceContourLabelStyleManager(static_cast<BrxCvDbSurfaceContourLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbSurfaceContourLabelStyleManager PyBrxCvDbSurfaceContourLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSurfaceContourLabelStyleManager>(src);
}

BrxCvDbSurfaceContourLabelStyleManager* PyBrxCvDbSurfaceContourLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSurfaceContourLabelStyleManager*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceSlopeLabelStyleManager
void makePyBrxCvDbSurfaceSlopeLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbSurfaceSlopeLabelStyleManager");
    class_<PyBrxCvDbSurfaceSlopeLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbSurfaceSlopeLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbSurfaceSlopeLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbSurfaceSlopeLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbSurfaceSlopeLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbSurfaceSlopeLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbSurfaceSlopeLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSurfaceSlopeLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbSurfaceSlopeLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbSurfaceSlopeLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSurfaceSlopeLabelStyleManager::PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbSurfaceSlopeLabelStyleManager(openAcDbObject<BrxCvDbSurfaceSlopeLabelStyleManager>(id), false)
{
}

PyBrxCvDbSurfaceSlopeLabelStyleManager::PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbSurfaceSlopeLabelStyleManager(openAcDbObject<BrxCvDbSurfaceSlopeLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbSurfaceSlopeLabelStyleManager::PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbSurfaceSlopeLabelStyleManager(openAcDbObject<BrxCvDbSurfaceSlopeLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbSurfaceSlopeLabelStyleManager::PyBrxCvDbSurfaceSlopeLabelStyleManager(BrxCvDbSurfaceSlopeLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbSurfaceSlopeLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbSurfaceSlopeLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbSurfaceSlopeLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbSurfaceSlopeLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbSurfaceSlopeLabelStyleManager PyBrxCvDbSurfaceSlopeLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbSurfaceSlopeLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbSurfaceSlopeLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbSurfaceSlopeLabelStyleManager::className()
{
    return "BrxCvDbSurfaceSlopeLabelStyleManager";
}

PyRxClass PyBrxCvDbSurfaceSlopeLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbSurfaceSlopeLabelStyleManager::desc(), false);
}

PyBrxCvDbSurfaceSlopeLabelStyleManager PyBrxCvDbSurfaceSlopeLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbSurfaceSlopeLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbSurfaceSlopeLabelStyleManager(static_cast<BrxCvDbSurfaceSlopeLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbSurfaceSlopeLabelStyleManager PyBrxCvDbSurfaceSlopeLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSurfaceSlopeLabelStyleManager>(src);
}

BrxCvDbSurfaceSlopeLabelStyleManager* PyBrxCvDbSurfaceSlopeLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSurfaceSlopeLabelStyleManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceElevationLabelStyleManager
void makePyBrxCvDbSurfaceElevationLabelStyleManagerWrapper()
{
    PyDocString DS("CvDbSurfaceElevationLabelStyleManager");
    class_<PyBrxCvDbSurfaceElevationLabelStyleManager, bases<PyBrxCvDbStyleManager>>("CvDbSurfaceElevationLabelStyleManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("createLabelStyle", &PyBrxCvDbSurfaceElevationLabelStyleManager::createLabelStyle, DS.ARGS({ "name: str" }))
        .def("managerId", &PyBrxCvDbSurfaceElevationLabelStyleManager::className, DS.SARGS()).staticmethod("managerId")
        .def("getManagerId", &PyBrxCvDbSurfaceElevationLabelStyleManager::getManagerId, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManagerId")
        .def("openManager", &PyBrxCvDbSurfaceElevationLabelStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbSurfaceElevationLabelStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSurfaceElevationLabelStyleManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbSurfaceElevationLabelStyleManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbSurfaceElevationLabelStyleManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSurfaceElevationLabelStyleManager::PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id)
    : PyBrxCvDbSurfaceElevationLabelStyleManager(openAcDbObject<BrxCvDbSurfaceElevationLabelStyleManager>(id), false)
{
}

PyBrxCvDbSurfaceElevationLabelStyleManager::PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbSurfaceElevationLabelStyleManager(openAcDbObject<BrxCvDbSurfaceElevationLabelStyleManager>(id, mode), false)
{
}

PyBrxCvDbSurfaceElevationLabelStyleManager::PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbSurfaceElevationLabelStyleManager(openAcDbObject<BrxCvDbSurfaceElevationLabelStyleManager>(id, mode, erased), false)
{
}

PyBrxCvDbSurfaceElevationLabelStyleManager::PyBrxCvDbSurfaceElevationLabelStyleManager(BrxCvDbSurfaceElevationLabelStyleManager* ptr, bool autoDelete)
    :PyBrxCvDbStyleManager(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbSurfaceElevationLabelStyleManager::createLabelStyle(const std::string& szName)
{
    return PyDbObjectId{ impObj()->createLabelStyle(utf8_to_wstr(szName).c_str()) };
}

std::string PyBrxCvDbSurfaceElevationLabelStyleManager::managerId()
{
    return wstr_to_utf8(BrxCvDbSurfaceElevationLabelStyleManager::managerId());
}

PyDbObjectId PyBrxCvDbSurfaceElevationLabelStyleManager::getManagerId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(BrxCvDbSurfaceElevationLabelStyleManager::getManager(id.m_id, db.impObj()));
    return id;
}

PyBrxCvDbSurfaceElevationLabelStyleManager PyBrxCvDbSurfaceElevationLabelStyleManager::openManager(PyDbDatabase& db, AcDb::OpenMode mode)
{
    BrxCvDbSurfaceElevationLabelStyleManager* ptr = nullptr;
    PyThrowBadEs(BrxCvDbSurfaceElevationLabelStyleManager::openManager(ptr, db.impObj(), mode));
    return PyBrxCvDbSurfaceElevationLabelStyleManager(ptr, true);
}

std::string PyBrxCvDbSurfaceElevationLabelStyleManager::className()
{
    return "BrxCvDbSurfaceElevationLabelStyleManager";
}

PyRxClass PyBrxCvDbSurfaceElevationLabelStyleManager::desc()
{
    return PyRxClass(BrxCvDbSurfaceElevationLabelStyleManager::desc(), false);
}

PyBrxCvDbSurfaceElevationLabelStyleManager PyBrxCvDbSurfaceElevationLabelStyleManager::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbSurfaceElevationLabelStyleManager::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbSurfaceElevationLabelStyleManager(static_cast<BrxCvDbSurfaceElevationLabelStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbSurfaceElevationLabelStyleManager PyBrxCvDbSurfaceElevationLabelStyleManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSurfaceElevationLabelStyleManager>(src);
}

BrxCvDbSurfaceElevationLabelStyleManager* PyBrxCvDbSurfaceElevationLabelStyleManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSurfaceElevationLabelStyleManager*>(m_pyImp.get());
}


#endif

#endif//BRXAPP