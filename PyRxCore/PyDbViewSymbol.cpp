#include "stdafx.h"
#include "PyDbViewSymbol.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol wrapper
void makePyDbViewSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("ViewSymbol");
    class_<PyDbViewSymbol, bases<PyDbEntity>>("ViewSymbol", no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))

        .def("className", &PyDbViewSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbViewSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbViewSymbol::PyDbViewSymbol(AcDbViewSymbol* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, mode), false)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, mode, erased), false)
{
}

PyDbObjectId PyDbViewSymbol::symbolStyleId() const
{
    return PyDbObjectId{ impObj()->symbolStyleId() };
}

void PyDbViewSymbol::setSymbolStyleId(const PyDbObjectId& styleId) const
{
    impObj()->setSymbolStyleId(styleId.m_id);
}

double PyDbViewSymbol::scale() const
{
    return impObj()->scale();
}

void PyDbViewSymbol::setScale(double val) const
{
    impObj()->setScale(val);
}

std::string PyDbViewSymbol::getIdentifier() const
{
    AcString sName;
    PyThrowBadEs(impObj()->getIdentifier(sName));
    return wstr_to_utf8(sName);
}

void PyDbViewSymbol::setIdentifier(const std::string& sName) const
{
    PyThrowBadEs(impObj()->setIdentifier(utf8_to_wstr(sName).c_str()));
}

PyDbObjectId PyDbViewSymbol::owningViewRep() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId{ impObj()->owningViewRep() };
#endif
}

void PyDbViewSymbol::setOwningViewRep(const PyDbObjectId& owner) const
{
    impObj()->setSymbolStyleId(owner.m_id);
}

boost::python::list PyDbViewSymbol::exportSymbolGeometry(const PyDbObjectId& viewRepId) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    AcArray<AcGeCurve3d*> geomArr;
    PyThrowBadEs(impObj()->exportSymbolGeometry(geomArr, viewRepId.m_id));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto item : geomArr)
        pylist.append(PyGeCurve3d(item));
    return pylist;
#endif
}

void PyDbViewSymbol::setSymbolGeometry(const boost::python::list& entIds) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSymbolGeometry(PyListToObjectIdArray(entIds)));
#endif
}

void PyDbViewSymbol::setSymbolGeometryEntities(const boost::python::list& pyentities) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    using Iter = boost::python::stl_input_iterator<PyDbObject>;
    AcArray<AcDbObject*> _entities;
    int length = boost::python::len(pyentities);
    _entities.setPhysicalLength(length);
    for (Iter it(pyentities), end; it != end; ++it) 
        _entities.append(it->impObj());
    PyThrowBadEs(impObj()->setSymbolGeometry(_entities));
#endif
}

void PyDbViewSymbol::updateDefinition() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateDefinition());
#endif
}

PyRxClass PyDbViewSymbol::desc()
{
    return PyRxClass(AcDbViewSymbol::desc(), false);
}

std::string PyDbViewSymbol::className()
{
    return "AcDbViewSymbol";
}

PyDbViewSymbol PyDbViewSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewSymbol, AcDbViewSymbol>(src);
}

PyDbViewSymbol PyDbViewSymbol::cast(const PyRxObject& src)
{
    return PyDbViewSymbol(AcDbViewSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbViewSymbol* PyDbViewSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbViewSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol wrapper
void makePyDbDetailSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("DetailSymbol");
    class_<PyDbDetailSymbol, bases<PyDbViewSymbol>>("DetailSymbol")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))
      
        .def("className", &PyDbDetailSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDetailSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbDetailSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDetailSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbDetailSymbol::PyDbDetailSymbol()
    : PyDbViewSymbol(new AcDbDetailSymbol(), true)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(AcDbDetailSymbol* ptr, bool autoDelete)
    : PyDbViewSymbol(ptr, autoDelete)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, mode), false)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, mode, erased), false)
{
}

PyRxClass PyDbDetailSymbol::desc()
{
    return PyRxClass(AcDbDetailSymbol::desc(), false);
}

std::string PyDbDetailSymbol::className()
{
    return "AcDbDetailSymbol";
}

PyDbDetailSymbol PyDbDetailSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbDetailSymbol, AcDbDetailSymbol>(src);
}

PyDbDetailSymbol PyDbDetailSymbol::cast(const PyRxObject& src)
{
    return PyDbDetailSymbol(AcDbDetailSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbDetailSymbol* PyDbDetailSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbDetailSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol wrapper
void makePyDbSectionSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("SectionSymbol");
    class_<PyDbSectionSymbol, bases<PyDbViewSymbol>>("SectionSymbol")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))
       
        .def("className", &PyDbSectionSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSectionSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbSectionSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSectionSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbSectionSymbol::PyDbSectionSymbol()
    : PyDbViewSymbol(new AcDbSectionSymbol(), true)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(AcDbSectionSymbol* ptr, bool autoDelete)
    : PyDbViewSymbol(ptr, autoDelete)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, mode), false)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, mode, erased), false)
{
}

PyRxClass PyDbSectionSymbol::desc()
{
    return PyRxClass(AcDbSectionSymbol::desc(), false);
}

std::string PyDbSectionSymbol::className()
{
    return "AcDbSectionSymbol";
}

PyDbSectionSymbol PyDbSectionSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSectionSymbol, AcDbSectionSymbol>(src);
}

PyDbSectionSymbol PyDbSectionSymbol::cast(const PyRxObject& src)
{
    return PyDbSectionSymbol(AcDbSectionSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbSectionSymbol* PyDbSectionSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbSectionSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif