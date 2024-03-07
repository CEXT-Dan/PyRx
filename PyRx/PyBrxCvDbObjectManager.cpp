#include "stdafx.h"
#include "PyBrxCvDbObjectManager.h"
#include "PyDbObjectId.h"

#ifdef BRXAPP
using namespace boost::python;

void makePyBrxCvDbObjectManagerWrapper()
{
    PyDocString DS("CvDbObjectManager");
    class_<PyBrxCvDbObjectManager, bases<PyBrxCvDbObject>>("CvDbObjectManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))

        .def("elementCount", &PyBrxCvDbObjectManager::elementCount, DS.ARGS())
        .def("ids", &PyBrxCvDbObjectManager::ids, DS.ARGS())
        .def("names", &PyBrxCvDbObjectManager::names, DS.ARGS())
        .def("idAt", &PyBrxCvDbObjectManager::idAt1)
        .def("idAt", &PyBrxCvDbObjectManager::idAt2, DS.ARGS({ "val : int|str" }))
        .def("nameAt", &PyBrxCvDbObjectManager::nameAt, DS.ARGS({ "val : int" }))
        .def("has1", &PyBrxCvDbObjectManager::has1)
        .def("has2", &PyBrxCvDbObjectManager::has2, DS.ARGS({ "id : str|PyDb.ObjectId" }))
        .def("remove1", &PyBrxCvDbObjectManager::remove1, DS.ARGS())
        .def("remove2", &PyBrxCvDbObjectManager::remove2, DS.ARGS({ "id : str|PyDb.ObjectId" }))

        .def("className", &PyBrxCvDbObjectManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbObjectManager::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbObjectManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbObjectManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")

        .def("__getitem__", &PyBrxCvDbObjectManager::idAt1)
        .def("__getitem__", &PyBrxCvDbObjectManager::idAt2)
        .def("__contains__", &PyBrxCvDbObjectManager::has1)
        .def("__contains__", &PyBrxCvDbObjectManager::has2)
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbObjectManager(static_cast<BrxCvDbObjectManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbObjectManager PyBrxCvDbObjectManager::cast(const PyRxObject& src)
{
    PyBrxCvDbObjectManager dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))

        .def("applicableFileFormats", &PyBrxCvDbFileFormatManager::applicableFileFormats, DS.ARGS({ "val : str" }))
        .def("allFileFormats", &PyBrxCvDbFileFormatManager::allFileFormats, DS.ARGS())
        .def("getManager", &PyBrxCvDbFileFormatManager::getManager, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManager")
        .def("openManager", &PyBrxCvDbFileFormatManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")

        .def("className", &PyBrxCvDbFileFormatManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbFileFormatManager::desc, DS.SARGS()).staticmethod("desc")
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbFileFormatManager(static_cast<BrxCvDbFileFormatManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbFileFormatManager PyBrxCvDbFileFormatManager::cast(const PyRxObject& src)
{
    PyBrxCvDbFileFormatManager dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))
        .def("getManager", &PyBrxCvDbStyleManager::getManager, DS.SARGS({ "db: PyDb.Database" , "PyBrxCv.EStyleManagerType" })).staticmethod("getManager")
        .def("openManager", &PyBrxCvDbStyleManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode","PyBrxCv.EStyleManagerType" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbStyleManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStyleManager::desc, DS.SARGS()).staticmethod("desc")
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
    case PyBrxCvDbStyleManager::ePointLabel:
        PyThrowBadEs(BrxCvDbPointLabelStyleManager::getManager(id.m_id, db.impObj()));
        break;
    case PyBrxCvDbStyleManager::eContourLabel:
        PyThrowBadEs(BrxCvDbSurfaceContourLabelStyleManager::getManager(id.m_id, db.impObj()));
        break;
    case PyBrxCvDbStyleManager::eSurfaceElevationLabel:
        PyThrowBadEs(BrxCvDbSurfaceElevationLabelStyleManager::getManager(id.m_id, db.impObj()));
        break;
    case PyBrxCvDbStyleManager::eSurfaceSlopeLabel:
        PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::getManager(id.m_id, db.impObj()));
        break;
    case PyBrxCvDbStyleManager::eSymbolStyle:
        PyThrowBadEs(BrxCvDbSymbolStyleManager::getManager(id.m_id, db.impObj()));
        break;
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
        BrxCvDbSurfaceSlopeLabelStyleManager* ptr = nullptr;
        PyThrowBadEs(BrxCvDbSurfaceSlopeLabelStyleManager::openManager(ptr, db.impObj(), mode));
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbStyleManager(static_cast<BrxCvDbStyleManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbStyleManager PyBrxCvDbStyleManager::cast(const PyRxObject& src)
{
    PyBrxCvDbStyleManager dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))
        .def("getManager", &PyBrxCvDbPointGroupManager::getManager, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getManager")
        .def("openManager", &PyBrxCvDbPointGroupManager::openManager, DS.SARGS({ "db: PyDb.Database","mode: PyDb.OpenMode" })).staticmethod("openManager")
        .def("className", &PyBrxCvDbPointGroupManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointGroupManager::desc, DS.SARGS()).staticmethod("desc")
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

PyDbObjectId PyBrxCvDbPointGroupManager::getManager(PyDbDatabase& db)
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
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbPointGroupManager(static_cast<BrxCvDbPointGroupManager*>(src.impObj()->clone()), true);
}

PyBrxCvDbPointGroupManager PyBrxCvDbPointGroupManager::cast(const PyRxObject& src)
{
    PyBrxCvDbPointGroupManager dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbPointGroupManager* PyBrxCvDbPointGroupManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbPointGroupManager*>(m_pyImp.get());
}
#endif//BRXAPP