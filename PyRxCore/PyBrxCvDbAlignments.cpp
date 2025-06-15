#include "stdafx.h"


#ifdef BRXAPP
#include "PyBrxCvDbAlignments.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dEntityInfo

void makePyBrxCvCivil3dEntityInfoWrapper()
{
    PyDocString DS("CvCivil3dEntityInfo");
    class_<PyBrxCvCivil3dEntityInfo>("CvCivil3dEntityInfo")
        .def(init<>(DS.ARGS()))
        .def("isNull", &PyBrxCvCivil3dEntityInfo::isNull, DS.ARGS())
        .def("name", &PyBrxCvCivil3dEntityInfo::name, DS.ARGS())
        .def("description", &PyBrxCvCivil3dEntityInfo::description, DS.ARGS())
        .def("objectId", &PyBrxCvCivil3dEntityInfo::objectId, DS.ARGS())
        .def("type", &PyBrxCvCivil3dEntityInfo::type, DS.ARGS())
        .def("alignmentType", &PyBrxCvCivil3dEntityInfo::alignmentType, DS.ARGS())
        .def("profileType", &PyBrxCvCivil3dEntityInfo::profileType, DS.ARGS())
        .def("baseAlignment", &PyBrxCvCivil3dEntityInfo::baseAlignment, DS.ARGS())
        .def("baseSurface", &PyBrxCvCivil3dEntityInfo::baseSurface, DS.ARGS())
        .def("profiles", &PyBrxCvCivil3dEntityInfo::profiles, DS.ARGS())
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
    for (auto& item : impObj()->profiles())
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
constexpr const std::string_view ctor = "Overloads:\n"
"- None: Any\n"
"- sourceDb: PyDb.Database, targetDb: PyDb.Database, doLabels: PyBrxCv.Civil3dLabels\n";

void makePyBrxCvCivil3dConverterWrapper()
{
    PyDocString DS("CvCivil3dConverter");
    class_<PyBrxCvCivil3dConverter>("CvCivil3dConverter")
        .def(init<>())
        .def(init<const PyDbDatabase&, PyDbDatabase&, BrxCvCivil3dConverter::Civil3dLabels>(DS.CTOR(ctor)))
        .def("getCivilEntities", &PyBrxCvCivil3dConverter::getCivilEntities, DS.ARGS())
        .def("convert", &PyBrxCvCivil3dConverter::convert, DS.ARGS({ "entitiesToConvert : list" }))
        .def("attachedLabels", &PyBrxCvCivil3dConverter::attachedLabels, DS.ARGS({ "civilEntity: PyBrxCv.CvCivil3dEntityInfo" }))
        .def("unattachedLabels", &PyBrxCvCivil3dConverter::unattachedLabels, DS.ARGS())
        .def("getInsertedEntities", &PyBrxCvCivil3dConverter::getInsertedEntities, DS.ARGS())
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
    for (auto& item : impObj()->getCivilEntities())
        _pylist.append(PyBrxCvCivil3dEntityInfo(item));
    return _pylist;
}

boost::python::list PyBrxCvCivil3dConverter::convert(const boost::python::list& entitiesToConvert) const
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("graphCount", &PyBrxCvDbView::graphCount, DS.ARGS())
        .def("graphAt", &PyBrxCvDbView::graphAt, DS.ARGS({ "val : int" }))
        .def("removeGraph", &PyBrxCvDbView::removeGraph, DS.ARGS({ "id: PyDb.ObjectId" }))
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
        .def("desc", &PyBrxCvDbView::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbView::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbView::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbView::PyBrxCvDbView()
    : PyBrxCvDbView(new BrxCvDbView(), true)
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

bool PyBrxCvDbView::removeGraph(const PyDbObjectId& idGraph) const
{
    return impObj()->removeGraph(idGraph.m_id);
}

PyDbObjectId PyBrxCvDbView::baseHAlignment() const
{
    return PyDbObjectId(impObj()->baseHAlignment());
}

bool PyBrxCvDbView::setBaseHAlignment(const PyDbObjectId& id) const
{
    return impObj()->setBaseHAlignment(id.m_id);
}

AcGePoint2d PyBrxCvDbView::origin() const
{
    return impObj()->origin();
}

bool PyBrxCvDbView::setOrigin(const AcGePoint2d& pnt) const
{
    return impObj()->setOrigin(pnt);
}

double PyBrxCvDbView::baseElevation() const
{
    return impObj()->baseElevation();
}

bool PyBrxCvDbView::setBaseElevation(double elevation) const
{
    return impObj()->setBaseElevation(elevation);
}

double PyBrxCvDbView::verticalScale() const
{
    return impObj()->verticalScale();
}

bool PyBrxCvDbView::setVerticalScale(double vScale) const
{
    return impObj()->setVerticalScale(vScale);
}

double PyBrxCvDbView::horizontalScale() const
{
    return impObj()->horizontalScale();
}

bool PyBrxCvDbView::setHorizontalScale(double hScale) const
{
    return impObj()->setHorizontalScale(hScale);
}

double PyBrxCvDbView::length() const
{
    return impObj()->length();
}

bool PyBrxCvDbView::setLength(double viewLength) const
{
    return impObj()->setLength(viewLength);
}

double PyBrxCvDbView::height() const
{
    return impObj()->height();
}

bool PyBrxCvDbView::setHeight(double viewHeight) const
{
    return impObj()->setHeight(viewHeight);
}

bool PyBrxCvDbView::addGraph(const PyDbObjectId& idGraph) const
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
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbView(static_cast<BrxCvDbView*>(src.impObj()->clone()), true);
}

PyBrxCvDbView PyBrxCvDbView::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbView>(src);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("update", &PyBrxCvDbVAlignmentView::update1)
        .def("update", &PyBrxCvDbVAlignmentView::update2, DS.ARGS({ "bUpdateDependencies : bool=True","updateOrigin : bool=True" }))

        .def("className", &PyBrxCvDbVAlignmentView::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentView::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbVAlignmentView::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbVAlignmentView::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView()
    : PyBrxCvDbVAlignmentView(new BrxCvDbVAlignmentView(), true)
{
}

PyBrxCvDbVAlignmentView::PyBrxCvDbVAlignmentView(const PyDbObjectId& id)
    : PyBrxCvDbVAlignmentView(openAcDbObject<BrxCvDbVAlignmentView>(id, AcDb::kForRead), false)
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

bool PyBrxCvDbVAlignmentView::update1() const
{
    return impObj()->update();
}

bool PyBrxCvDbVAlignmentView::update2(bool bUpdateDependencies, bool updateOrigin) const
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
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbVAlignmentView(static_cast<BrxCvDbVAlignmentView*>(src.impObj()->clone()), true);
}

PyBrxCvDbVAlignmentView PyBrxCvDbVAlignmentView::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentView>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- rawStation: float, stationForward: float, type: StationEquationType\n";

    PyDocString DS("CvStationEquation");
    class_<PyBrxCvStationEquation>("CvStationEquation")
        .def(init<>())
        .def(init<double, double, BrxCvStationEquation::EStationEquationType>(DS.CTOR(ctords)))
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

bool PyBrxCvStationEquation::setRawStation(double rawStation) const
{
    return impObj()->setRawStation(rawStation);
}

bool PyBrxCvStationEquation::setStationForward(double stationForward) const
{
    return impObj()->setStationForward(stationForward);
}

bool PyBrxCvStationEquation::setType(BrxCvStationEquation::EStationEquationType type) const
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- alignment: PyBrxCv.CvDbHAlignment\n";

    PyDocString DS("CvStationEquations");
    class_<PyBrxCvStationEquations>("CvStationEquations")
        .def(init<>())
        .def(init<PyBrxCvDbHAlignment&>(DS.CTOR(ctords)))
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

double PyBrxCvStationEquations::getStationBack(Adesk::UInt64 idx) const
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

bool PyBrxCvStationEquations::setRefStartingLength(double startingStation) const
{
    return impObj()->setRefStartingLength(startingStation);
}

bool PyBrxCvStationEquations::setRefRawStartingStation(double rawStartingStation) const
{
    return impObj()->setRefRawStartingStation(rawStartingStation);
}

bool PyBrxCvStationEquations::addStationEquation(const PyBrxCvStationEquation& equation) const
{
    return impObj()->addStationEquation(*equation.impObj());
}

bool PyBrxCvStationEquations::removeStationEquation(Adesk::UInt64 idx) const
{
    return impObj()->removeStationEquation(idx);
}

bool PyBrxCvStationEquations::removeAllStationEquations() const
{
    return impObj()->removeAllStationEquations();
}

bool PyBrxCvStationEquations::update() const
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
    constexpr const std::string_view getStationAtPointOverloads = "Overloads:\n"
        "- station: PyGe.Point2d\n"
        "- station: PyGe.Point2d,fromStation: float, toStation: float\n";

    constexpr const std::string_view addLineFixedOverloads = "Overloads:\n"
        "- prevId : int, length: float\n"
        "- start: PyGe.Point2d, end: PyGe.Point2d\n";

    constexpr const std::string_view addLineToOverloads = "Overloads:\n"
        "- nextId : int, length: float\n"
        "- nextId : int, to: PyGe.Point2d\n";

    constexpr const std::string_view addLineFromOverloads = "Overloads:\n"
        "- prevId : int, length: float\n"
        "- prevId : int, to: PyGe.Point2d\n";

    constexpr const std::string_view addArcFixedOverloads = "Overloads:\n"
        "- center: PyGe.Point2d, radius: float, clockwise: bool\n"
        "- startPoint: PyGe.Point2d, midPoint: PyGe.Point2d, endPoint: PyGe.Point2d\n";

    constexpr const std::string_view addArcToOverloads = "Overloads:\n"
        "- nextId: int, passThroughPoint: PyGe.Point2d\n"
        "- nextId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d\n"
        "- nextId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType\n"
        "- nextId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool\n";

    constexpr const std::string_view addArcFromOverloads = "Overloads:\n"
        "- prevId: int, passThroughPoint: PyGe.Point2d\n"
        "- prevId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d\n"
        "- prevId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType\n"
        "- prevId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool\n";

    constexpr const std::string_view addArcBetweenOverloads = "Overloads:\n"
        "- prevId: int, nextId: int, passThroughPoint: PyGe.Point2d\n"
        "- prevId: int, nextId: int, parameter: float, paramType: PyBrxCv.EArcParameterType, isGreaterThan180: bool, arcType: PyBrxCv.ArcType\n";

    constexpr const std::string_view addTSToOverloads = "Overloads:\n"
        "- nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType\n"
        "- nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType\n";

    constexpr const std::string_view addSTFromOverloads = "Overloads:\n"
        "- prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType\n"
        "- prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType\n";

    constexpr const std::string_view addCSToOverloads = "Overloads:\n"
        "- nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType\n"
        "- nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType\n";

    constexpr const std::string_view addSCFromOverloads = "Overloads:\n"
        "- prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType\n"
        "- prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType\n";


    PyDocString DS("CvDbHAlignment");
    class_<PyBrxCvDbHAlignment, bases<PyBrxCvDbCurve>>("CvDbHAlignment")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("verticalAlignmentCount", &PyBrxCvDbHAlignment::verticalAlignmentCount, DS.ARGS())
        .def("verticalAlignmentAt", &PyBrxCvDbHAlignment::verticalAlignmentAt, DS.ARGS({ "index: int" }))
        .def("alignment3dCount", &PyBrxCvDbHAlignment::alignment3dCount, DS.ARGS())
        .def("alignment3dAt", &PyBrxCvDbHAlignment::alignment3dAt, DS.ARGS({ "index: int" }))
        .def("verticalAlignmentViewCount", &PyBrxCvDbHAlignment::verticalAlignmentViewCount, DS.ARGS())
        .def("verticalAlignmentViewAt", &PyBrxCvDbHAlignment::verticalAlignmentViewAt, DS.ARGS({ "index: int" }))
        .def("length", &PyBrxCvDbHAlignment::length, DS.ARGS())
        .def("elementCount", &PyBrxCvDbHAlignment::elementCount, DS.ARGS())
        .def("getStationAtPoint", &PyBrxCvDbHAlignment::getStationAtPoint1)
        .def("getStationAtPoint", &PyBrxCvDbHAlignment::getStationAtPoint2, DS.OVRL(getStationAtPointOverloads))
        .def("getPointAtStation", &PyBrxCvDbHAlignment::getPointAtStation, DS.ARGS({ "station: float" }))
        .def("firstElementId", &PyBrxCvDbHAlignment::firstElementId, DS.ARGS())
        .def("lastElementId", &PyBrxCvDbHAlignment::lastElementId, DS.ARGS())
        .def("firstLineElementId", &PyBrxCvDbHAlignment::firstLineElementId, DS.ARGS())
        .def("nextLineElementId", &PyBrxCvDbHAlignment::nextLineElementId, DS.ARGS({ "Id: int" }))
        .def("previousLineElementId", &PyBrxCvDbHAlignment::previousLineElementId, DS.ARGS({ "Id: int" }))
        .def("elementAtId", &PyBrxCvDbHAlignment::elementAtId, DS.ARGS({ "Id: int" }))
        .def("elementAtStation", &PyBrxCvDbHAlignment::elementAtStation, DS.ARGS({ "station: float" }))
        .def("curveAtPI", &PyBrxCvDbHAlignment::curveAtPI, DS.ARGS({ "pi: PyBrxCv.CvDbHAlignmentPI" }))
        .def("getPIsArray", &PyBrxCvDbHAlignment::getPIsArray, DS.ARGS())
        .def("getUnorderedElementIds", &PyBrxCvDbHAlignment::getUnorderedElementIds, DS.ARGS())
        .def("getElementId", &PyBrxCvDbHAlignment::getElementId, DS.ARGS({ "gsMarker: int" }))
        .def("update", &PyBrxCvDbHAlignment::update, DS.ARGS())
        .def("getRadius", &PyBrxCvDbHAlignment::getRadius, DS.ARGS({ "param: float" }))
        .def("addLineFixed", &PyBrxCvDbHAlignment::addLineFixed1)
        .def("addLineFixed", &PyBrxCvDbHAlignment::addLineFixed2, DS.OVRL(addLineFixedOverloads))
        .def("addLineTo", &PyBrxCvDbHAlignment::addLineTo1)
        .def("addLineTo", &PyBrxCvDbHAlignment::addLineTo2, DS.OVRL(addLineToOverloads))
        .def("addLineFrom", &PyBrxCvDbHAlignment::addLineFrom1)
        .def("addLineFrom", &PyBrxCvDbHAlignment::addLineFrom2, DS.OVRL(addLineFromOverloads))
        .def("addLineBetween", &PyBrxCvDbHAlignment::addLineBetween, DS.ARGS({ "prevId: int","nextId: int" }))
        .def("insertLineFixed", &PyBrxCvDbHAlignment::insertLineFixed, DS.ARGS({ "start: PyGe.Point2d","end: PyGe.Point2d","prevId: int" }))
        .def("addArcAuto", &PyBrxCvDbHAlignment::addArcAuto, DS.ARGS({ "prevId: int","nextId: int" }))
        .def("addArcFixed", &PyBrxCvDbHAlignment::addArcFixed1)
        .def("addArcFixed", &PyBrxCvDbHAlignment::addArcFixed2, DS.OVRL(addArcFixedOverloads))
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo1)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo2)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo3)
        .def("addArcTo", &PyBrxCvDbHAlignment::addArcTo4, DS.OVRL(addArcToOverloads))
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom1)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom2)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom3)
        .def("addArcFrom", &PyBrxCvDbHAlignment::addArcFrom4, DS.OVRL(addArcFromOverloads))
        .def("addArcBetween", &PyBrxCvDbHAlignment::addArcBetween1)
        .def("addArcBetween", &PyBrxCvDbHAlignment::addArcBetween2, DS.OVRL(addArcBetweenOverloads))
        .def("addSCSBetween", &PyBrxCvDbHAlignment::addSCSBetween,
            DS.ARGS({ "prevId: int","nextId: int","spiral1: float","spiral2: float","spiralType: PyBrxCv.SpiralParameterType","radius: float","spiralDef: PyBrxCv.SpiralDefinitionType" }))
        .def("addSTSBetween", &PyBrxCvDbHAlignment::addSTSBetween,
            DS.ARGS({ "prevId: int","nextId: int","spiral1Param: float","spiral2Param: float","spiralType : PyBrxCv.SpiralParameterType","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSSBetween", &PyBrxCvDbHAlignment::addSSBetween,
            DS.ARGS({ "prevId: int","nextId: int","spiralRatio: float","spiralParamType : PyBrxCv.SpiralParameterType","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSpiralFrom", &PyBrxCvDbHAlignment::addSpiralFrom,
            DS.ARGS({ "prevId: int","radius: float","length: float","isClockwise: bool","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSpiralTo", &PyBrxCvDbHAlignment::addSpiralTo,
            DS.ARGS({ "nextId: int","radius: float","length: float","isClockwise: bool","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSpiralBetween", &PyBrxCvDbHAlignment::addSpiralBetween,
            DS.ARGS({ "prevId: int","nextId: int","spiralDef: PyBrxCv.SpiralDefinitionType" }))
        .def("addTSTo", &PyBrxCvDbHAlignment::addTSTo1)
        .def("addTSTo", &PyBrxCvDbHAlignment::addTSTo2, DS.OVRL(addTSToOverloads))
        .def("addSTFrom", &PyBrxCvDbHAlignment::addSTFrom1)
        .def("addSTFrom", &PyBrxCvDbHAlignment::addSTFrom2, DS.OVRL(addSTFromOverloads))
        .def("addCSTo", &PyBrxCvDbHAlignment::addCSTo1)
        .def("addCSTo", &PyBrxCvDbHAlignment::addCSTo2, DS.OVRL(addCSToOverloads))
        .def("addSCFrom", &PyBrxCvDbHAlignment::addSCFrom1)
        .def("addSCFrom", &PyBrxCvDbHAlignment::addSCFrom2, DS.OVRL(addSCFromOverloads))
        .def("addCSSTo", &PyBrxCvDbHAlignment::addCSSTo,
            DS.ARGS({ "nextId: int", "spiral1Param: float","spiral2Param: float","spiralParamType","radius: float","passThroughPoint: PyGe.Point2d","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSSCFrom", &PyBrxCvDbHAlignment::addSSCFrom,
            DS.ARGS({ "prevId: int", "spiral1Param: float","spiral2Param: float","spiralParamType","radius: float","passThroughPoint: PyGe.Point2d","spiralDef : PyBrxCv.SpiralDefinitionType" }))
        .def("addSCSAuto", &PyBrxCvDbHAlignment::addSCSAuto, DS.ARGS({ "prevId: int","nextId: int" }))
        .def("deleteElement", &PyBrxCvDbHAlignment::deleteElement, DS.ARGS({ "id: int" }))
        .def("style", &PyBrxCvDbHAlignment::style, DS.ARGS())
        .def("setStyle", &PyBrxCvDbHAlignment::setStyle, DS.ARGS({ "style: int" }))
        .def("elementExtensionColor", &PyBrxCvDbHAlignment::elementExtensionColor, DS.ARGS())
        .def("tangentExtensionColor", &PyBrxCvDbHAlignment::tangentExtensionColor, DS.ARGS())
        .def("lineElementColor", &PyBrxCvDbHAlignment::lineElementColor, DS.ARGS())
        .def("curveElementColor", &PyBrxCvDbHAlignment::curveElementColor, DS.ARGS())
        .def("spiralElementColor", &PyBrxCvDbHAlignment::spiralElementColor, DS.ARGS())
        .def("setElementExtensionColor", &PyBrxCvDbHAlignment::setElementExtensionColor, DS.ARGS({ "colACI: int" }))
        .def("setTangentExtensionColor", &PyBrxCvDbHAlignment::setTangentExtensionColor, DS.ARGS({ "colACI: int" }))
        .def("setLineElementColor", &PyBrxCvDbHAlignment::setLineElementColor, DS.ARGS({ "colACI: int" }))
        .def("setCurveElementColor", &PyBrxCvDbHAlignment::setCurveElementColor, DS.ARGS({ "colACI: int" }))
        .def("setSpiralElementColor", &PyBrxCvDbHAlignment::setSpiralElementColor, DS.ARGS({ "colACI: int" }))
        .def("stationEquations", &PyBrxCvDbHAlignment::stationEquations, DS.ARGS())
        .def("setStationEquations", &PyBrxCvDbHAlignment::setStationEquations, DS.ARGS({ "val: PyBrxCv.CvStationEquations" }))

        .def("className", &PyBrxCvDbHAlignment::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignment::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbHAlignment::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbHAlignment::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignment::PyBrxCvDbHAlignment()
    : PyBrxCvDbHAlignment(new BrxCvDbHAlignment(), true)
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

boost::python::tuple PyBrxCvDbHAlignment::getPointAtStation(double station) const
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

PyBrxCvDbHAlignmentElement PyBrxCvDbHAlignment::elementAtId(Adesk::UInt64 id) const
{
    auto ptr = impObj()->elementAtId(id);//NOLINT
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentElement(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentElement PyBrxCvDbHAlignment::elementAtStation(double station) const
{
    auto ptr = impObj()->elementAtStation(station);//NOLINT
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentElement(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

Adesk::UInt64 PyBrxCvDbHAlignment::curveAtPI(const PyBrxCvDbHAlignmentPI& pi) const
{
    return impObj()->curveAtPI(pi.impObj());
}

boost::python::list PyBrxCvDbHAlignment::getPIsArray() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& ptr : impObj()->getPIsArray())
    {
        if (ptr.refCount() == 1)
            pylist.append(PyBrxCvDbHAlignmentPI(ptr.detach(), true));
        else
            throw PyErrorStatusException(Acad::eInvalidOpenState);
    }
    return pylist;
}

boost::python::list PyBrxCvDbHAlignment::getUnorderedElementIds() const
{
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt64> elementIds;
    PyThrowBadEs(impObj()->getUnorderedElementIds(elementIds));
    return IntU64ArrayToPyList(elementIds);
}

Adesk::UInt64 PyBrxCvDbHAlignment::getElementId(Adesk::GsMarker gsMarker) const
{
    return impObj()->getElementId(gsMarker);
}

bool PyBrxCvDbHAlignment::update() const
{
    return impObj()->update();
}

double PyBrxCvDbHAlignment::getRadius(double param) const
{
    double r = 0;
    PyThrowBadEs(impObj()->getRadius(param, r));
    return r;
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFixed1(Adesk::UInt64 prevId, double length) const
{
    return impObj()->addLineFixed(prevId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint) const
{
    return impObj()->addLineFixed(startPoint, endPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineTo1(Adesk::UInt64 nextId, const AcGePoint2d& point) const
{
    return impObj()->addLineTo(nextId, point);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFrom1(Adesk::UInt64 prevId, const AcGePoint2d& point) const
{
    return impObj()->addLineFrom(prevId, point);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineTo2(Adesk::UInt64 nextId, double length) const
{
    return impObj()->addLineTo(nextId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineFrom2(Adesk::UInt64 prevId, double length) const
{
    return impObj()->addLineFrom(prevId, length);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addLineBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const
{
    return impObj()->addLineBetween(prevId, nextId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::insertLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId) const
{
    return impObj()->insertLineFixed(startPoint, endPoint, prevId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const
{
    return impObj()->addArcAuto(prevId, nextId);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFixed1(const AcGePoint2d& center, double radius, bool isClockwise) const
{
    return impObj()->addArcFixed(center, radius, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& midPoint, const AcGePoint2d& endPoint) const
{
    return impObj()->addArcFixed(startPoint, midPoint, endPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo1(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint) const
{
    return impObj()->addArcTo(nextId, passThroughPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom1(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint) const
{
    return impObj()->addArcFrom(prevId, passThroughPoint);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo2(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction) const
{
    return impObj()->addArcTo(nextId, passThroughPoint, direction);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom2(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction) const
{
    return impObj()->addArcFrom(prevId, passThroughPoint, direction);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo3(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, double radius, bool isGreaterThan180, EArcType arcType) const
{
    return impObj()->addArcTo(nextId, passThroughPoint, radius, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom3(Adesk::UInt64 previous, const AcGePoint2d& passThroughPoint, double radius, bool isGreaterThan180, EArcType arcType) const
{
    return impObj()->addArcFrom(previous, passThroughPoint, radius, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcTo4(Adesk::UInt64 nextId, double radius, double paramValue, EArcParameterType paramType, bool isClockwise) const
{
    return impObj()->addArcTo(nextId, radius, paramValue, paramType, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcFrom4(Adesk::UInt64 prevId, double radius, double paramValue, EArcParameterType paramType, bool isClockwise) const
{
    return impObj()->addArcFrom(prevId, radius, paramValue, paramType, isClockwise);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcBetween1(Adesk::UInt64 prevId, Adesk::UInt64 nextId, const AcGePoint2d& passThrough) const
{
    return impObj()->addArcBetween(prevId, nextId, passThrough);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addArcBetween2(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double parameter, EArcParameterType paramType, bool isGreaterThan180, EArcType arcType) const
{
    return impObj()->addArcBetween(prevId, nextId, parameter, paramType, isGreaterThan180, arcType);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiral1, double spiral2, ESpiralParameterType spiralType, double radius, ESpiralDefinitionType spiralDef) const
{
    return impObj()->addSCSBetween(prevId, nextId, spiral1, spiral2, spiralType, radius, spiralDef);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiral1Param, double spiral2Param, ESpiralParameterType spiralParamType, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSTSBetween(prevId, nextId, spiral1Param, spiral2Param, spiralParamType, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiralRatio, ESpiralParameterType spiralParamType, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSSBetween(prevId, nextId, spiralRatio, spiralParamType, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralFrom(Adesk::UInt64 prevId, double radius, double length, bool isClockwise, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSpiralFrom(prevId, radius, length, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralTo(Adesk::UInt64 nextId, double radius, double length, bool isClockwise, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSpiralTo(nextId, radius, length, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSpiralBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSpiralBetween(prevId, nextId, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTFrom1(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSTFrom(prevId, spiralParam, spiralParamType, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addTSTo1(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addTSTo(nextId, spiralParam, spiralParamType, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addTSTo2(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double tangentLength, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addTSTo(nextId, spiralParam, spiralParamType, tangentLength, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCFrom1(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, bool isGreaterThan180, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSCFrom(prevId, spiralParam, spiralParamType, radius, passThroughPoint, isGreaterThan180, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSTo1(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, bool isGreaterThan180, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addCSTo(nextId, spiralParam, spiralParamType, radius, passThroughPoint, isGreaterThan180, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCFrom2(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double radius, double arcLength, bool isClockwise, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSCFrom(prevId, spiralParam, spiralParamType, radius, arcLength, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSTo2(Adesk::UInt64 nextId, double spiralParam, ESpiralParameterType spiralParamType, double radius, double arcLength, bool isClockwise, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addCSTo(nextId, spiralParam, spiralParamType, radius, arcLength, isClockwise, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSSCFrom(Adesk::UInt64 prevId, double spiral1Param, double spiral2Param, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addSSCFrom(prevId, spiral1Param, spiral2Param, spiralParamType, radius, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addCSSTo(Adesk::UInt64 nextId, double spiral1Param, double spiral2Param, ESpiralParameterType spiralParamType, double radius, const AcGePoint2d& passThroughPoint, ESpiralDefinitionType spiralDefinition) const
{
    return impObj()->addCSSTo(nextId, spiral1Param, spiral2Param, spiralParamType, radius, passThroughPoint, spiralDefinition);
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSCSAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const
{
    return impObj()->addSCSAuto(prevId, nextId);
}

bool PyBrxCvDbHAlignment::deleteElement(Adesk::UInt64 id) const
{
    return impObj()->deleteElement(id);
}

Adesk::UInt32 PyBrxCvDbHAlignment::style() const
{
    return impObj()->style();
}

bool PyBrxCvDbHAlignment::setStyle(const Adesk::UInt32 style) const
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

bool PyBrxCvDbHAlignment::setElementExtensionColor(const Adesk::UInt32 color) const
{
    return impObj()->setElementExtensionColor(color);
}

bool PyBrxCvDbHAlignment::setTangentExtensionColor(const Adesk::UInt32 color) const
{
    return impObj()->setTangentExtensionColor(color);
}

bool PyBrxCvDbHAlignment::setLineElementColor(const Adesk::UInt32 color) const
{
    return impObj()->setLineElementColor(color);
}

bool PyBrxCvDbHAlignment::setCurveElementColor(const Adesk::UInt32 color) const
{
    return impObj()->setCurveElementColor(color);
}

bool PyBrxCvDbHAlignment::setSpiralElementColor(const Adesk::UInt32 color) const
{
    return impObj()->setSpiralElementColor(color);
}

PyBrxCvStationEquations PyBrxCvDbHAlignment::stationEquations() const
{
    return PyBrxCvStationEquations(impObj()->stationEquations());
}

bool PyBrxCvDbHAlignment::setStationEquations(const PyBrxCvStationEquations& stationEquations) const
{
    return impObj()->setStationEquations(*stationEquations.impObj());
}

Adesk::UInt64 PyBrxCvDbHAlignment::addSTFrom2(Adesk::UInt64 prevId, double spiralParam, ESpiralParameterType spiralParamType, double tangentLength, ESpiralDefinitionType spiralDefinition) const
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
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbHAlignment(static_cast<BrxCvDbHAlignment*>(src.impObj()->clone()), true);
}

PyBrxCvDbHAlignment PyBrxCvDbHAlignment::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignment>(src);
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
        .def("desc", &PyBrxCvDbHAlignmentElement::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentElement::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentElement::PyBrxCvDbHAlignmentElement(const BrxCvDbHAlignmentElement& ref)
    : PyBrxCvDbSubObject(new BrxCvDbHAlignmentElement(ref), true)
{
}

PyBrxCvDbHAlignmentElement::PyBrxCvDbHAlignmentElement(BrxCvDbHAlignmentElement* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
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

bool PyBrxCvDbHAlignmentElement::setPreviousId(Adesk::UInt64 id) const
{
    return impObj()->setPreviousId(id);
}

bool PyBrxCvDbHAlignmentElement::setNextId(Adesk::UInt64 id) const
{
    return impObj()->setNextId(id);
}

bool PyBrxCvDbHAlignmentElement::setTangencyConstraint(ETangencyConstraint constraint) const
{
    return impObj()->setTangencyConstraint(constraint);
}

bool PyBrxCvDbHAlignmentElement::setParameterConstraint(EParameterConstraint constraint) const
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

PyBrxCvDbHAlignmentElement PyBrxCvDbHAlignmentElement::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentElement>(src);
}

BrxCvDbHAlignmentElement* PyBrxCvDbHAlignmentElement::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentElement*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentPI
void makePyBrxCvDbHAlignmentPIWrapper()
{
    PyDocString DS("CvDbHAlignmentPI");
    class_<PyBrxCvDbHAlignmentPI, bases<PyBrxCvDbHAlignmentElement>>("CvDbHAlignmentPI")
        .def(init<>(DS.ARGS()))
        .def("location", &PyBrxCvDbHAlignmentPI::location, DS.ARGS())
        .def("className", &PyBrxCvDbHAlignmentPI::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentPI::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentPI::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentPI::PyBrxCvDbHAlignmentPI()
    : PyBrxCvDbHAlignmentPI(new BrxCvDbHAlignmentPI(), true)
{
}

PyBrxCvDbHAlignmentPI::PyBrxCvDbHAlignmentPI(BrxCvDbHAlignmentPI* ptr, bool autoDelete)
    : PyBrxCvDbHAlignmentElement(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbHAlignmentPI::location() const
{
    return impObj()->location();
}

std::string PyBrxCvDbHAlignmentPI::className()
{
    return "BrxCvDbHAlignmentPI";
}

PyRxClass PyBrxCvDbHAlignmentPI::desc()
{
    return PyRxClass(BrxCvDbHAlignmentPI::desc(), false);
}

PyBrxCvDbHAlignmentPI PyBrxCvDbHAlignmentPI::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentPI>(src);
}

BrxCvDbHAlignmentPI* PyBrxCvDbHAlignmentPI::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentPI*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentCurve
void makePyBrxCvDbHAlignmentCurveWrapper()
{
    PyDocString DS("CvDbHAlignmentCurve");
    class_<PyBrxCvDbHAlignmentCurve, bases<PyBrxCvDbHAlignmentElement>>("CvDbHAlignmentCurve", boost::python::no_init)
        .def("startPoint", &PyBrxCvDbHAlignmentCurve::startPoint, DS.ARGS())
        .def("endPoint", &PyBrxCvDbHAlignmentCurve::endPoint, DS.ARGS())
        .def("startStation", &PyBrxCvDbHAlignmentCurve::startStation, DS.ARGS())
        .def("endStation", &PyBrxCvDbHAlignmentCurve::endStation, DS.ARGS())
        .def("length", &PyBrxCvDbHAlignmentCurve::length, DS.ARGS())
        .def("className", &PyBrxCvDbHAlignmentCurve::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentCurve::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentCurve::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentCurve::PyBrxCvDbHAlignmentCurve(BrxCvDbHAlignmentCurve* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentElement(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbHAlignmentCurve::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyBrxCvDbHAlignmentCurve::endPoint() const
{
    return impObj()->endPoint();
}

double PyBrxCvDbHAlignmentCurve::startStation() const
{
    return impObj()->startStation();
}

double PyBrxCvDbHAlignmentCurve::endStation() const
{
    return impObj()->endStation();
}

double PyBrxCvDbHAlignmentCurve::length() const
{
    return impObj()->length();
}

std::string PyBrxCvDbHAlignmentCurve::className()
{
    return "BrxCvDbHAlignmentCurve";
}

PyRxClass PyBrxCvDbHAlignmentCurve::desc()
{
    return PyRxClass(BrxCvDbHAlignmentCurve::desc(), false);
}

PyBrxCvDbHAlignmentCurve PyBrxCvDbHAlignmentCurve::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentCurve>(src);
}

BrxCvDbHAlignmentCurve* PyBrxCvDbHAlignmentCurve::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentCurve*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentLine
void makePyBrxCvDbHAlignmentLineWrapper()
{
    PyDocString DS("CvDbHAlignmentLine");
    class_<PyBrxCvDbHAlignmentLine, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentLine")
        .def(init<>(DS.ARGS()))
        .def("passThroughPoint1", &PyBrxCvDbHAlignmentLine::passThroughPoint1, DS.ARGS())
        .def("passThroughPoint2", &PyBrxCvDbHAlignmentLine::passThroughPoint2, DS.ARGS())
        .def("paramLength", &PyBrxCvDbHAlignmentLine::paramLength, DS.ARGS())
        .def("setParamLength", &PyBrxCvDbHAlignmentLine::setParamLength, DS.ARGS({ "val : float" }))
        .def("setPassThroughPoint1", &PyBrxCvDbHAlignmentLine::setPassThroughPoint1, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setPassThroughPoint2", &PyBrxCvDbHAlignmentLine::setPassThroughPoint2, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbHAlignmentLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentLine::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentLine::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentLine::PyBrxCvDbHAlignmentLine()
    :PyBrxCvDbHAlignmentLine(new BrxCvDbHAlignmentLine(), true)
{
}

PyBrxCvDbHAlignmentLine::PyBrxCvDbHAlignmentLine(BrxCvDbHAlignmentLine* ptr, bool autoDelete)
    : PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbHAlignmentLine::passThroughPoint1() const
{
    return impObj()->passThroughPoint1();
}

AcGePoint2d PyBrxCvDbHAlignmentLine::passThroughPoint2() const
{
    return impObj()->passThroughPoint2();
}

double PyBrxCvDbHAlignmentLine::paramLength() const
{
    return impObj()->paramLength();
}

bool PyBrxCvDbHAlignmentLine::setParamLength(double length) const
{
    return impObj()->setParamLength(length);
}

bool PyBrxCvDbHAlignmentLine::setPassThroughPoint1(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint1(point);
}

bool PyBrxCvDbHAlignmentLine::setPassThroughPoint2(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint2(point);
}

std::string PyBrxCvDbHAlignmentLine::className()
{
    return "BrxCvDbHAlignmentLine";
}

PyRxClass PyBrxCvDbHAlignmentLine::desc()
{
    return PyRxClass(BrxCvDbHAlignmentLine::desc(), false);
}

PyBrxCvDbHAlignmentLine PyBrxCvDbHAlignmentLine::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentLine>(src);
}

BrxCvDbHAlignmentLine* PyBrxCvDbHAlignmentLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
// PyBrxCvDbHAlignmentArc
void makePyBrxCvDbHAlignmentArcWrapper()
{
    PyDocString DS("CvDbHAlignmentArc");
    class_<PyBrxCvDbHAlignmentArc, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentArc")
        .def(init<>(DS.ARGS()))
        .def("radius", &PyBrxCvDbHAlignmentArc::radius, DS.ARGS())
        .def("center", &PyBrxCvDbHAlignmentArc::center, DS.ARGS())
        .def("isClockwise", &PyBrxCvDbHAlignmentArc::isClockwise, DS.ARGS())
        .def("setRadius", &PyBrxCvDbHAlignmentArc::setRadius, DS.ARGS({ "val : float" }))
        .def("setCenter", &PyBrxCvDbHAlignmentArc::setCenter, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setClockwise", &PyBrxCvDbHAlignmentArc::setClockwise, DS.ARGS({ "val : bool" }))
        .def("isLessThan180", &PyBrxCvDbHAlignmentArc::isLessThan180, DS.ARGS())
        .def("setLessThan180", &PyBrxCvDbHAlignmentArc::setLessThan180, DS.ARGS({ "val : bool" }))
        .def("isCompound", &PyBrxCvDbHAlignmentArc::isCompound, DS.ARGS())
        .def("setCompound", &PyBrxCvDbHAlignmentArc::setCompound, DS.ARGS({ "val : bool" }))
        .def("passThroughPoint1", &PyBrxCvDbHAlignmentArc::passThroughPoint1, DS.ARGS())
        .def("passThroughPoint2", &PyBrxCvDbHAlignmentArc::passThroughPoint2, DS.ARGS())
        .def("passThroughPoint3", &PyBrxCvDbHAlignmentArc::passThroughPoint3, DS.ARGS())
        .def("setPassThroughPoint1", &PyBrxCvDbHAlignmentArc::setPassThroughPoint1, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setPassThroughPoint2", &PyBrxCvDbHAlignmentArc::setPassThroughPoint2, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setPassThroughPoint3", &PyBrxCvDbHAlignmentArc::setPassThroughPoint3, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("paramLength", &PyBrxCvDbHAlignmentArc::paramLength, DS.ARGS())
        .def("setParamLength", &PyBrxCvDbHAlignmentArc::setParamLength, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbHAlignmentArc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentArc::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentArc::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentArc::PyBrxCvDbHAlignmentArc()
    :PyBrxCvDbHAlignmentArc(new BrxCvDbHAlignmentArc(), true)
{
}

PyBrxCvDbHAlignmentArc::PyBrxCvDbHAlignmentArc(BrxCvDbHAlignmentArc* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

double PyBrxCvDbHAlignmentArc::radius() const
{
    return impObj()->radius();
}

AcGePoint2d PyBrxCvDbHAlignmentArc::center() const
{
    return impObj()->center();
}

bool PyBrxCvDbHAlignmentArc::isClockwise() const
{
    return impObj()->isClockwise();
}

bool PyBrxCvDbHAlignmentArc::setRadius(double rad) const
{
    return impObj()->setRadius(rad);
}

bool PyBrxCvDbHAlignmentArc::setCenter(const AcGePoint2d& center) const
{
    return impObj()->setCenter(center);
}

bool PyBrxCvDbHAlignmentArc::setClockwise(bool isClockwise) const
{
    return impObj()->setClockwise(isClockwise);
}

bool PyBrxCvDbHAlignmentArc::isLessThan180() const
{
    return impObj()->isLessThan180();
}

bool PyBrxCvDbHAlignmentArc::setLessThan180(bool isLessThan180) const
{
    return impObj()->setLessThan180(isLessThan180);
}

bool PyBrxCvDbHAlignmentArc::isCompound() const
{
    return impObj()->isCompound();
}

bool PyBrxCvDbHAlignmentArc::setCompound(bool isCompound) const
{
    return impObj()->setCompound(isCompound);
}

AcGePoint2d PyBrxCvDbHAlignmentArc::passThroughPoint1() const
{
    return impObj()->passThroughPoint1();
}

AcGePoint2d PyBrxCvDbHAlignmentArc::passThroughPoint2() const
{
    return impObj()->passThroughPoint2();
}

AcGePoint2d PyBrxCvDbHAlignmentArc::passThroughPoint3() const
{
    return impObj()->passThroughPoint3();
}

bool PyBrxCvDbHAlignmentArc::setPassThroughPoint1(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint1(point);
}

bool PyBrxCvDbHAlignmentArc::setPassThroughPoint2(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint2(point);
}

bool PyBrxCvDbHAlignmentArc::setPassThroughPoint3(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint3(point);
}

double PyBrxCvDbHAlignmentArc::paramLength() const
{
    return impObj()->paramLength();
}

bool PyBrxCvDbHAlignmentArc::setParamLength(double length) const
{
    return impObj()->setParamLength(length);
}

std::string PyBrxCvDbHAlignmentArc::className()
{
    return "BrxCvDbHAlignmentArc";
}

PyRxClass PyBrxCvDbHAlignmentArc::desc()
{
    return PyRxClass(BrxCvDbHAlignmentArc::desc(), false);
}

PyBrxCvDbHAlignmentArc PyBrxCvDbHAlignmentArc::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentArc>(src);
}

BrxCvDbHAlignmentArc* PyBrxCvDbHAlignmentArc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentArc*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSpiral
void makePyBrxCvDbHAlignmentSpiralWrapper()
{
    PyDocString DS("CvDbHAlignmentSpiral");
    class_<PyBrxCvDbHAlignmentSpiral, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentSpiral")
        .def(init<>(DS.ARGS()))
        .def("radiusIn", &PyBrxCvDbHAlignmentSpiral::radiusIn, DS.ARGS())
        .def("radiusOut", &PyBrxCvDbHAlignmentSpiral::radiusOut, DS.ARGS())
        .def("isCompound", &PyBrxCvDbHAlignmentSpiral::isCompound, DS.ARGS())
        .def("spiralCurveType", &PyBrxCvDbHAlignmentSpiral::spiralCurveType, DS.ARGS())
        .def("spiralDefinition", &PyBrxCvDbHAlignmentSpiral::spiralDefinition, DS.ARGS())
        .def("startDirection", &PyBrxCvDbHAlignmentSpiral::startDirection, DS.ARGS())
        .def("endDirection", &PyBrxCvDbHAlignmentSpiral::endDirection, DS.ARGS())
        .def("paramA", &PyBrxCvDbHAlignmentSpiral::paramA, DS.ARGS())
        .def("paramLength", &PyBrxCvDbHAlignmentSpiral::paramLength, DS.ARGS())
        .def("setRadiusIn", &PyBrxCvDbHAlignmentSpiral::setRadiusIn, DS.ARGS({ "val : float" }))
        .def("setRadiusOut", &PyBrxCvDbHAlignmentSpiral::setRadiusOut, DS.ARGS({ "val : float" }))
        .def("setCompound", &PyBrxCvDbHAlignmentSpiral::setCompound, DS.ARGS({ "val : float" }))
        .def("setClockwise", &PyBrxCvDbHAlignmentSpiral::setClockwise, DS.ARGS({ "val : bool" }))
        .def("setSpiralCurveType", &PyBrxCvDbHAlignmentSpiral::setSpiralCurveType, DS.ARGS({ "val : PyBrxCv.ESpiralCurveType" }))
        .def("setSpiralDefinition", &PyBrxCvDbHAlignmentSpiral::setSpiralDefinition, DS.ARGS({ "val : PyBrxCv.ESpiralDefinitionType" }))
        .def("setEndDirection", &PyBrxCvDbHAlignmentSpiral::setEndDirection, DS.ARGS({ "val : float" }))
        .def("setParamA", &PyBrxCvDbHAlignmentSpiral::setParamA, DS.ARGS({ "val : float" }))
        .def("setParamLength", &PyBrxCvDbHAlignmentSpiral::setParamLength, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbHAlignmentSpiral::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentSpiral::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentSpiral::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentSpiral::PyBrxCvDbHAlignmentSpiral()
    :PyBrxCvDbHAlignmentSpiral(new BrxCvDbHAlignmentSpiral(), true)
{
}

PyBrxCvDbHAlignmentSpiral::PyBrxCvDbHAlignmentSpiral(BrxCvDbHAlignmentSpiral* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

double PyBrxCvDbHAlignmentSpiral::radiusIn() const
{
    return impObj()->radiusIn();
}

double PyBrxCvDbHAlignmentSpiral::radiusOut() const
{
    return impObj()->radiusOut();
}

bool PyBrxCvDbHAlignmentSpiral::isCompound() const
{
    return impObj()->isCompound();
}

PyBrxCvDbHAlignmentSpiral::ESpiralCurveType PyBrxCvDbHAlignmentSpiral::spiralCurveType() const
{
    return impObj()->spiralCurveType();
}

bool PyBrxCvDbHAlignmentSpiral::isClockwise() const
{
    return impObj()->isClockwise();
}

PyBrxCvDbHAlignmentSpiral::ESpiralDefinitionType PyBrxCvDbHAlignmentSpiral::spiralDefinition() const
{
    return impObj()->spiralDefinition();
}

double PyBrxCvDbHAlignmentSpiral::startDirection() const
{
    return impObj()->startDirection();
}

double PyBrxCvDbHAlignmentSpiral::endDirection() const
{
    return impObj()->endDirection();
}

double PyBrxCvDbHAlignmentSpiral::paramA() const
{
    return impObj()->paramA();
}

double PyBrxCvDbHAlignmentSpiral::paramLength() const
{
    return impObj()->paramLength();
}

bool PyBrxCvDbHAlignmentSpiral::setRadiusIn(double rad) const
{
    return impObj()->setRadiusIn(rad);
}

bool PyBrxCvDbHAlignmentSpiral::setRadiusOut(double rad) const
{
    return impObj()->setRadiusOut(rad);
}

bool PyBrxCvDbHAlignmentSpiral::setCompound(bool isCompound) const
{
    return impObj()->setCompound(isCompound);
}

bool PyBrxCvDbHAlignmentSpiral::setClockwise(bool isClockwise) const
{
    return impObj()->setClockwise(isClockwise);
}

bool PyBrxCvDbHAlignmentSpiral::setSpiralCurveType(ESpiralCurveType spiralCurveType) const
{
    return impObj()->setSpiralCurveType(spiralCurveType);
}

bool PyBrxCvDbHAlignmentSpiral::setSpiralDefinition(ESpiralDefinitionType spiralCurveDefinition) const
{
    return impObj()->setSpiralDefinition(spiralCurveDefinition);
}

bool PyBrxCvDbHAlignmentSpiral::setStartDirection(double direction) const
{
    return impObj()->setStartDirection(direction);
}

bool PyBrxCvDbHAlignmentSpiral::setEndDirection(double direction) const
{
    return impObj()->setEndDirection(direction);
}

bool PyBrxCvDbHAlignmentSpiral::setParamA(double paramA) const
{
    return impObj()->setParamA(paramA);
}

bool PyBrxCvDbHAlignmentSpiral::setParamLength(double paramLength) const
{
    return impObj()->setParamLength(paramLength);
}

std::string PyBrxCvDbHAlignmentSpiral::className()
{
    return "BrxCvDbHAlignmentSpiral";
}

PyRxClass PyBrxCvDbHAlignmentSpiral::desc()
{
    return PyRxClass(BrxCvDbHAlignmentSpiral::desc(), false);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSpiral::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentSpiral>(src);
}

BrxCvDbHAlignmentSpiral* PyBrxCvDbHAlignmentSpiral::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentSpiral*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSCS
void makePyBrxCvDbHAlignmentSCSWrapper()
{
    PyDocString DS("CvDbHAlignmentSCS");
    class_<PyBrxCvDbHAlignmentSCS, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentSCS")
        .def(init<>(DS.ARGS()))
        .def("arc", &PyBrxCvDbHAlignmentSCS::arc, DS.ARGS())
        .def("spiralIn", &PyBrxCvDbHAlignmentSCS::spiralIn, DS.ARGS())
        .def("spiralOut", &PyBrxCvDbHAlignmentSCS::spiralOut, DS.ARGS())
        .def("className", &PyBrxCvDbHAlignmentSCS::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentSCS::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentSCS::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentSCS::PyBrxCvDbHAlignmentSCS()
    : PyBrxCvDbHAlignmentSCS(new BrxCvDbHAlignmentSCS(), true)
{
}

PyBrxCvDbHAlignmentSCS::PyBrxCvDbHAlignmentSCS(BrxCvDbHAlignmentSCS* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

PyBrxCvDbHAlignmentArc PyBrxCvDbHAlignmentSCS::arc() const
{
    auto ptr = impObj()->arc();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentArc(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSCS::spiralIn() const
{
    auto ptr = impObj()->spiralIn();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSCS::spiralOut() const
{
    auto ptr = impObj()->spiralOut();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

std::string PyBrxCvDbHAlignmentSCS::className()
{
    return "BrxCvDbHAlignmentSCS";
}

PyRxClass PyBrxCvDbHAlignmentSCS::desc()
{
    return PyRxClass(BrxCvDbHAlignmentSCS::desc(), false);
}

PyBrxCvDbHAlignmentSCS PyBrxCvDbHAlignmentSCS::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentSCS>(src);
}

BrxCvDbHAlignmentSCS* PyBrxCvDbHAlignmentSCS::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentSCS*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSTS
void makePyBrxCvDbHAlignmentSTSWrapper()
{
    PyDocString DS("CvDbHAlignmentSTS");
    class_<PyBrxCvDbHAlignmentSTS, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentSTS")
        .def(init<>(DS.ARGS()))
        .def("line", &PyBrxCvDbHAlignmentSTS::line, DS.ARGS())
        .def("spiralIn", &PyBrxCvDbHAlignmentSTS::spiralIn, DS.ARGS())
        .def("spiralOut", &PyBrxCvDbHAlignmentSTS::spiralOut, DS.ARGS())
        .def("spiralRatio", &PyBrxCvDbHAlignmentSTS::spiralRatio, DS.ARGS())
        .def("className", &PyBrxCvDbHAlignmentSTS::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentSTS::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentSTS::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentSTS::PyBrxCvDbHAlignmentSTS()
    :PyBrxCvDbHAlignmentSTS(new BrxCvDbHAlignmentSTS(), true)
{
}

PyBrxCvDbHAlignmentSTS::PyBrxCvDbHAlignmentSTS(BrxCvDbHAlignmentSTS* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

PyBrxCvDbHAlignmentLine PyBrxCvDbHAlignmentSTS::line() const
{
    auto ptr = impObj()->line();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentLine(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSTS::spiralIn() const
{
    auto ptr = impObj()->spiralIn();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSTS::spiralOut() const
{
    auto ptr = impObj()->spiralOut();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

double PyBrxCvDbHAlignmentSTS::spiralRatio() const
{
    return impObj()->spiralRatio();
}

std::string PyBrxCvDbHAlignmentSTS::className()
{
    return "BrxCvDbHAlignmentSTS";
}

PyRxClass PyBrxCvDbHAlignmentSTS::desc()
{
    return PyRxClass(BrxCvDbHAlignmentSTS::desc(), false);
}

PyBrxCvDbHAlignmentSTS PyBrxCvDbHAlignmentSTS::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentSTS>(src);
}

BrxCvDbHAlignmentSTS* PyBrxCvDbHAlignmentSTS::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentSTS*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSSCSS
void makePyBrxCvDbHAlignmentSSCSSWrapper()
{
    PyDocString DS("CvDbHAlignmentSSCSS");
    class_<PyBrxCvDbHAlignmentSSCSS, bases<PyBrxCvDbHAlignmentCurve>>("CvDbHAlignmentSSCSS")
        .def(init<>(DS.ARGS()))
        .def("arc", &PyBrxCvDbHAlignmentSSCSS::arc, DS.ARGS())
        .def("spiral1", &PyBrxCvDbHAlignmentSSCSS::spiral1, DS.ARGS())
        .def("spiral2", &PyBrxCvDbHAlignmentSSCSS::spiral2, DS.ARGS())
        .def("spiral3", &PyBrxCvDbHAlignmentSSCSS::spiral3, DS.ARGS())
        .def("spiral4", &PyBrxCvDbHAlignmentSSCSS::spiral4, DS.ARGS())
        .def("className", &PyBrxCvDbHAlignmentSSCSS::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbHAlignmentSSCSS::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbHAlignmentSSCSS::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbHAlignmentSSCSS::PyBrxCvDbHAlignmentSSCSS()
    :PyBrxCvDbHAlignmentSSCSS(new BrxCvDbHAlignmentSSCSS(), true)
{
}

PyBrxCvDbHAlignmentSSCSS::PyBrxCvDbHAlignmentSSCSS(BrxCvDbHAlignmentSSCSS* ptr, bool autoDelete)
    :PyBrxCvDbHAlignmentCurve(ptr, autoDelete)
{
}

PyBrxCvDbHAlignmentArc PyBrxCvDbHAlignmentSSCSS::arc() const
{
    auto ptr = impObj()->arc();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentArc(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSSCSS::spiral1() const
{
    auto ptr = impObj()->spiral1();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSSCSS::spiral2() const
{
    auto ptr = impObj()->spiral2();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSSCSS::spiral3() const
{
    auto ptr = impObj()->spiral3();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

PyBrxCvDbHAlignmentSpiral PyBrxCvDbHAlignmentSSCSS::spiral4() const
{
    auto ptr = impObj()->spiral4();
    if (ptr.refCount() == 1)
        return PyBrxCvDbHAlignmentSpiral(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

std::string PyBrxCvDbHAlignmentSSCSS::className()
{
    return "BrxCvDbHAlignmentSSCSS";
}

PyRxClass PyBrxCvDbHAlignmentSSCSS::desc()
{
    return PyRxClass(BrxCvDbHAlignmentSSCSS::desc(), false);
}

PyBrxCvDbHAlignmentSSCSS PyBrxCvDbHAlignmentSSCSS::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbHAlignmentSSCSS>(src);
}

BrxCvDbHAlignmentSSCSS* PyBrxCvDbHAlignmentSSCSS::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbHAlignmentSSCSS*>(m_pyImp.get());
}

void makePyBrxCvDbVAlignmentWrapper()
{
    PyDocString DS("CvDbVAlignment");
    class_<PyBrxCvDbVAlignment, bases<PyBrxCvDbCurve>>("CvDbVAlignment")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("baseHAlignment", &PyBrxCvDbVAlignment::baseHAlignment, DS.ARGS())
        .def("baseSurface", &PyBrxCvDbVAlignment::baseSurface, DS.ARGS())
        .def("elevationMin", &PyBrxCvDbVAlignment::elevationMin, DS.ARGS())
        .def("elevationMax", &PyBrxCvDbVAlignment::elevationMax, DS.ARGS())
        .def("getElevationAt", &PyBrxCvDbVAlignment::getElevationAt, DS.ARGS({ "station: float" }))
        .def("length", &PyBrxCvDbVAlignment::length, DS.ARGS())
        .def("elementCount", &PyBrxCvDbVAlignment::elementCount, DS.ARGS())
        .def("type", &PyBrxCvDbVAlignment::type, DS.ARGS())
        .def("firstElementId", &PyBrxCvDbVAlignment::firstElementId, DS.ARGS())
        .def("lastElementId", &PyBrxCvDbVAlignment::lastElementId, DS.ARGS())
        .def("firstTangentElementId", &PyBrxCvDbVAlignment::firstTangentElementId, DS.ARGS())
        .def("nextTangentElementId", &PyBrxCvDbVAlignment::nextTangentElementId, DS.ARGS({ "id: int" }))
        .def("previousTangentElementId", &PyBrxCvDbVAlignment::previousTangentElementId, DS.ARGS({ "id: int" }))
        .def("elementAtId", &PyBrxCvDbVAlignment::elementAtId, DS.ARGS({ "id: int" }))
        .def("curveAtPVI", &PyBrxCvDbVAlignment::curveAtPVI, DS.ARGS({ "pvi: PyBrxCv.CvDbVAlignmentPVI" }))
        .def("pviAtCurve", &PyBrxCvDbVAlignment::pviAtCurve, DS.ARGS({ "curve: PyBrxCv.CvDbVAlignmentCurve" }))
        .def("getPVIsArrays", &PyBrxCvDbVAlignment::getPVIsArrays, DS.ARGS())
        .def("getUnorderedElementIds", &PyBrxCvDbVAlignment::getUnorderedElementIds, DS.ARGS())
        .def("getElementId", &PyBrxCvDbVAlignment::getElementId, DS.ARGS({ "gsMarker: int" }))
        .def("getRadius", &PyBrxCvDbVAlignment::getRadius, DS.ARGS({ "param: float" }))
        .def("getElevations", &PyBrxCvDbVAlignment::getElevations, DS.ARGS())
        .def("style", &PyBrxCvDbVAlignment::style, DS.ARGS())
        .def("tangentPolygonColor", &PyBrxCvDbVAlignment::tangentPolygonColor, DS.ARGS())
        .def("lineElementColor", &PyBrxCvDbVAlignment::lineElementColor, DS.ARGS())
        .def("curveElementColor", &PyBrxCvDbVAlignment::curveElementColor, DS.ARGS())
        .def("setBaseHAlignment", &PyBrxCvDbVAlignment::setBaseHAlignment, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setBaseSurface", &PyBrxCvDbVAlignment::setBaseSurface, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setType", &PyBrxCvDbVAlignment::setType, DS.ARGS({ "val: VAlignmentType" }))
        .def("setStyle", &PyBrxCvDbVAlignment::setStyle, DS.ARGS({ "val: int" }))
        .def("setTangentPolygonColor", &PyBrxCvDbVAlignment::setTangentPolygonColor, DS.ARGS({ "val: int" }))
        .def("setLineElementColor", &PyBrxCvDbVAlignment::setLineElementColor, DS.ARGS({ "val: int" }))
        .def("setCurveElementColor", &PyBrxCvDbVAlignment::setCurveElementColor, DS.ARGS({ "val: int" }))
        .def("addTangentFixed", &PyBrxCvDbVAlignment::addTangentFixed, DS.ARGS({ "startPoint: PyGe.Point2d","endPoint: PyGe.Point2d" }))
        .def("insertTangentFixed", &PyBrxCvDbVAlignment::insertTangentFixed, DS.ARGS({ "startPoint: PyGe.Point2d","endPoint: PyGe.Point2d","val: int" }))
        .def("addArcBetween", &PyBrxCvDbVAlignment::addArcBetween, DS.ARGS({ "prevId: int","nextId: int","radius: float" }))
        .def("addArcAuto", &PyBrxCvDbVAlignment::addArcAuto, DS.ARGS({ "prevId: int","nextId: int" }))
        .def("addParabolaBetween", &PyBrxCvDbVAlignment::addParabolaBetween, DS.ARGS({ "prevId: int","nextId: int","radius: float" }))
        .def("addParabolaAuto", &PyBrxCvDbVAlignment::addParabolaAuto, DS.ARGS({ "prevId: int","nextId: int" }))
        .def("deleteElement", &PyBrxCvDbVAlignment::deleteElement, DS.ARGS({ "id: int" }))
        .def("update", &PyBrxCvDbVAlignment::update, DS.ARGS({ "updateDependencies: bool" }))

        .def("className", &PyBrxCvDbVAlignment::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignment::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbVAlignment::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbVAlignment::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignment::PyBrxCvDbVAlignment()
    :PyBrxCvDbVAlignment(new BrxCvDbVAlignment(), true)
{
}

PyBrxCvDbVAlignment::PyBrxCvDbVAlignment(const PyDbObjectId& id)
    : PyBrxCvDbVAlignment(openAcDbObject<BrxCvDbVAlignment>(id), false)
{
}

PyBrxCvDbVAlignment::PyBrxCvDbVAlignment(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbVAlignment(openAcDbObject<BrxCvDbVAlignment>(id, mode), false)
{
}

PyBrxCvDbVAlignment::PyBrxCvDbVAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbVAlignment(openAcDbObject<BrxCvDbVAlignment>(id, mode, erased), false)
{
}

PyBrxCvDbVAlignment::PyBrxCvDbVAlignment(BrxCvDbVAlignment* ptr, bool autoDelete)
    :PyBrxCvDbCurve(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbVAlignment::baseHAlignment() const
{
    return PyDbObjectId(impObj()->baseHAlignment());
}

PyDbObjectId PyBrxCvDbVAlignment::baseSurface() const
{
    return PyDbObjectId(impObj()->baseSurface());
}

double PyBrxCvDbVAlignment::elevationMin() const
{
    return impObj()->elevationMin();
}

double PyBrxCvDbVAlignment::elevationMax() const
{
    return impObj()->elevationMax();
}

boost::python::tuple PyBrxCvDbVAlignment::getElevationAt(double station) const
{
    PyAutoLockGIL lock;
    double elevation;
    bool flag = impObj()->getElevationAt(station, elevation);
    return boost::python::make_tuple(flag, elevation);
}

double PyBrxCvDbVAlignment::length() const
{
    return impObj()->length();
}

size_t PyBrxCvDbVAlignment::elementCount() const
{
    return impObj()->elementCount();
}

BrxCvDbVAlignment::EVAlignmentType PyBrxCvDbVAlignment::type() const
{
    return impObj()->type();
}

Adesk::UInt64 PyBrxCvDbVAlignment::firstElementId() const
{
    return impObj()->firstElementId();
}

Adesk::UInt64 PyBrxCvDbVAlignment::lastElementId() const
{
    return impObj()->lastElementId();
}

Adesk::UInt64 PyBrxCvDbVAlignment::firstTangentElementId() const
{
    return impObj()->firstTangentElementId();
}

Adesk::UInt64 PyBrxCvDbVAlignment::nextTangentElementId(Adesk::UInt64 id) const
{
    return impObj()->nextTangentElementId(id);
}

Adesk::UInt64 PyBrxCvDbVAlignment::previousTangentElementId(Adesk::UInt64 id) const
{
    return impObj()->previousTangentElementId(id);
}

PyBrxCvDbVAlignmentElement PyBrxCvDbVAlignment::elementAtId(Adesk::UInt64 id) const
{
    auto ptr = impObj()->elementAtId(id);
    if (ptr.refCount() == 1)
        return PyBrxCvDbVAlignmentElement(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

Adesk::UInt64 PyBrxCvDbVAlignment::curveAtPVI(const PyBrxCvDbVAlignmentPVI& pvi) const
{
    return impObj()->curveAtPVI(pvi.impObj());
}

PyBrxCvDbVAlignmentPVI PyBrxCvDbVAlignment::pviAtCurve(const PyBrxCvDbVAlignmentCurve& curve) const
{
    auto ptr = impObj()->pviAtCurve(curve.impObj());
    if (ptr.refCount() == 1)
        return PyBrxCvDbVAlignmentPVI(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

boost::python::list PyBrxCvDbVAlignment::getPVIsArrays() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& ptr : impObj()->getPVIsArrays())
    {
        if (ptr.refCount() == 1)
            pylist.append(PyBrxCvDbVAlignmentPVI(ptr.detach(), true));
        else
            throw PyErrorStatusException(Acad::eInvalidOpenState);
    }
    return pylist;
}

boost::python::list PyBrxCvDbVAlignment::getUnorderedElementIds() const
{
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt64> elementIds;
    PyThrowBadEs(impObj()->getUnorderedElementIds(elementIds));
    return IntU64ArrayToPyList(elementIds);
}

Adesk::UInt64 PyBrxCvDbVAlignment::getElementId(Adesk::GsMarker gsMarker) const
{
    return impObj()->getElementId(gsMarker);
}

double PyBrxCvDbVAlignment::getRadius(double param) const
{
    double radius = 0;
    PyThrowBadEs(impObj()->getRadius(param, radius));
    return radius;
}

boost::python::list PyBrxCvDbVAlignment::getElevations() const
{
    AcGePoint2dArray elevations;
    impObj()->getElevations(elevations);
    return Point2dArrayToPyList(elevations);
}

Adesk::UInt32 PyBrxCvDbVAlignment::style() const
{
    return impObj()->style();
}

Adesk::UInt32 PyBrxCvDbVAlignment::tangentPolygonColor() const
{
    return impObj()->tangentPolygonColor();
}

Adesk::UInt32 PyBrxCvDbVAlignment::lineElementColor() const
{
    return impObj()->lineElementColor();
}

Adesk::UInt32 PyBrxCvDbVAlignment::curveElementColor() const
{
    return impObj()->curveElementColor();
}

bool PyBrxCvDbVAlignment::setBaseHAlignment(const PyDbObjectId& id) const
{
    return impObj()->setBaseHAlignment(id.m_id);
}

bool PyBrxCvDbVAlignment::setBaseSurface(const PyDbObjectId& id) const
{
    return impObj()->setBaseSurface(id.m_id);
}

bool PyBrxCvDbVAlignment::setType(const BrxCvDbVAlignment::EVAlignmentType type) const
{
    return impObj()->setType(type);
}

bool PyBrxCvDbVAlignment::setStyle(Adesk::UInt32 style) const
{
    return impObj()->setStyle(style);
}

bool PyBrxCvDbVAlignment::setTangentPolygonColor(Adesk::UInt32 color) const
{
    return impObj()->setTangentPolygonColor(color);
}

bool PyBrxCvDbVAlignment::setLineElementColor(Adesk::UInt32 color) const
{
    return impObj()->setLineElementColor(color);
}

bool PyBrxCvDbVAlignment::setCurveElementColor(Adesk::UInt32 color) const
{
    return impObj()->setCurveElementColor(color);
}

Adesk::UInt64 PyBrxCvDbVAlignment::addTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint) const
{
    return impObj()->addTangentFixed(startPoint, endPoint);
}

Adesk::UInt64 PyBrxCvDbVAlignment::insertTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId) const
{
    return impObj()->insertTangentFixed(startPoint, endPoint, prevId);
}

Adesk::UInt64 PyBrxCvDbVAlignment::addArcBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius) const
{
    return impObj()->addArcBetween(prevId, nextId, radius);
}

Adesk::UInt64 PyBrxCvDbVAlignment::addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const
{
    return impObj()->addArcAuto(prevId, nextId);
}

Adesk::UInt64 PyBrxCvDbVAlignment::addParabolaBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius) const
{
    return impObj()->addParabolaBetween(prevId, nextId, radius);
}

Adesk::UInt64 PyBrxCvDbVAlignment::addParabolaAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const
{
    return impObj()->addParabolaAuto(prevId, nextId);
}

bool PyBrxCvDbVAlignment::deleteElement(Adesk::UInt64 id) const
{
    return impObj()->deleteElement(id);
}

bool PyBrxCvDbVAlignment::update(bool updateDependencies) const
{
    return impObj()->update(updateDependencies);
}

std::string PyBrxCvDbVAlignment::className()
{
    return "BrxCvDbVAlignment";
}

PyRxClass PyBrxCvDbVAlignment::desc()
{
    return PyRxClass(BrxCvDbVAlignment::desc(), false);
}

PyBrxCvDbVAlignment PyBrxCvDbVAlignment::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbVAlignment::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDbVAlignment(static_cast<BrxCvDbVAlignment*>(src.impObj()->clone()), true);
}

PyBrxCvDbVAlignment PyBrxCvDbVAlignment::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignment>(src);
}

BrxCvDbVAlignment* PyBrxCvDbVAlignment::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignment*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentElement
void makePyBrxCvDbVAlignmentElementWrapper()
{
    PyDocString DS("CvDbVAlignmentElement");
    class_<PyBrxCvDbVAlignmentElement, bases<PyBrxCvDbSubObject>>("CvDbVAlignmentElement", boost::python::no_init)
        .def("id", &PyBrxCvDbVAlignmentElement::id, DS.ARGS())
        .def("previousId", &PyBrxCvDbVAlignmentElement::previousId, DS.ARGS())
        .def("nextId", &PyBrxCvDbVAlignmentElement::nextId, DS.ARGS())
        .def("type", &PyBrxCvDbVAlignmentElement::type, DS.ARGS())
        .def("tangencyConstraint", &PyBrxCvDbVAlignmentElement::tangencyConstraint, DS.ARGS())
        .def("parameterConstraint", &PyBrxCvDbVAlignmentElement::parameterConstraint, DS.ARGS())
        .def("setPreviousId", &PyBrxCvDbVAlignmentElement::setPreviousId, DS.ARGS({ "val : int" }))
        .def("setNextId", &PyBrxCvDbVAlignmentElement::setNextId, DS.ARGS({ "val : int" }))
        .def("setTangencyConstraint", &PyBrxCvDbVAlignmentElement::setTangencyConstraint, DS.ARGS({ "val : PyBrxCv.VAlignmentTangencyConstraint" }))
        .def("setParameterConstraint", &PyBrxCvDbVAlignmentElement::setParameterConstraint, DS.ARGS({ "val : PyBrxCv.VAlignmentParameterConstraint" }))
        .def("className", &PyBrxCvDbVAlignmentElement::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentElement::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentElement::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentElement::PyBrxCvDbVAlignmentElement(BrxCvDbVAlignmentElement* ptr, bool autoDelete)
    :PyBrxCvDbSubObject(ptr, autoDelete)
{
}

Adesk::UInt64 PyBrxCvDbVAlignmentElement::id() const
{
    return impObj()->id();
}

Adesk::UInt64 PyBrxCvDbVAlignmentElement::previousId() const
{
    return impObj()->previousId();
}

Adesk::UInt64 PyBrxCvDbVAlignmentElement::nextId() const
{
    return impObj()->nextId();
}

PyBrxCvDbVAlignmentElement::EElementType PyBrxCvDbVAlignmentElement::type() const
{
    return impObj()->type();
}

PyBrxCvDbVAlignmentElement::ETangencyConstraint PyBrxCvDbVAlignmentElement::tangencyConstraint() const
{
    return impObj()->tangencyConstraint();
}

PyBrxCvDbVAlignmentElement::EParameterConstraint PyBrxCvDbVAlignmentElement::parameterConstraint() const
{
    return impObj()->parameterConstraint();
}

bool PyBrxCvDbVAlignmentElement::setPreviousId(Adesk::UInt64 id) const
{
    return impObj()->setPreviousId(id);
}

bool PyBrxCvDbVAlignmentElement::setNextId(Adesk::UInt64 id) const
{
    return impObj()->setNextId(id);
}

bool PyBrxCvDbVAlignmentElement::setTangencyConstraint(ETangencyConstraint constraint) const
{
    return impObj()->setTangencyConstraint(constraint);
}

bool PyBrxCvDbVAlignmentElement::setParameterConstraint(EParameterConstraint constraint) const
{
    return impObj()->setParameterConstraint(constraint);
}

std::string PyBrxCvDbVAlignmentElement::className()
{
    return "BrxCvDbVAlignmentElement";
}

PyRxClass PyBrxCvDbVAlignmentElement::desc()
{
    return PyRxClass(BrxCvDbVAlignmentElement::desc(), false);
}

PyBrxCvDbVAlignmentElement PyBrxCvDbVAlignmentElement::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentElement>(src);
}

BrxCvDbVAlignmentElement* PyBrxCvDbVAlignmentElement::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentElement*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentPVI
void makePyBrxCvDbVAlignmentPVIWrapper()
{
    PyDocString DS("CvDbVAlignmentPVI");
    class_<PyBrxCvDbVAlignmentPVI, bases<PyBrxCvDbVAlignmentElement>>("CvDbVAlignmentPVI")
        .def(init<>(DS.ARGS()))
        .def("location", &PyBrxCvDbVAlignmentPVI::location, DS.ARGS())
        .def("className", &PyBrxCvDbVAlignmentPVI::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentPVI::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentPVI::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentPVI::PyBrxCvDbVAlignmentPVI()
    : PyBrxCvDbVAlignmentPVI(new BrxCvDbVAlignmentPVI(), true)
{
}

PyBrxCvDbVAlignmentPVI::PyBrxCvDbVAlignmentPVI(BrxCvDbVAlignmentPVI* ptr, bool autoDelete)
    : PyBrxCvDbVAlignmentElement(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbVAlignmentPVI::location() const
{
    return impObj()->location();
}

std::string PyBrxCvDbVAlignmentPVI::className()
{
    return "BrxCvDbVAlignmentPVI";
}

PyRxClass PyBrxCvDbVAlignmentPVI::desc()
{
    return PyRxClass(BrxCvDbVAlignmentPVI::desc(), false);
}

PyBrxCvDbVAlignmentPVI PyBrxCvDbVAlignmentPVI::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentPVI>(src);
}

BrxCvDbVAlignmentPVI* PyBrxCvDbVAlignmentPVI::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentPVI*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//BrxCvDbVAlignmentCurve
void makePyBrxCvDbVAlignmentCurveWrapper()
{
    PyDocString DS("CvDbVAlignmentCurve");
    class_<PyBrxCvDbVAlignmentCurve, bases<PyBrxCvDbVAlignmentElement>>("CvDbVAlignmentCurve", boost::python::no_init)
        .def("startPoint", &PyBrxCvDbVAlignmentCurve::startPoint, DS.ARGS())
        .def("endPoint", &PyBrxCvDbVAlignmentCurve::endPoint, DS.ARGS())
        .def("length", &PyBrxCvDbVAlignmentCurve::length, DS.ARGS())
        .def("className", &PyBrxCvDbVAlignmentCurve::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentCurve::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentCurve::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentCurve::PyBrxCvDbVAlignmentCurve(BrxCvDbVAlignmentCurve* ptr, bool autoDelete)
    : PyBrxCvDbVAlignmentElement(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbVAlignmentCurve::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyBrxCvDbVAlignmentCurve::endPoint() const
{
    return impObj()->endPoint();
}

double PyBrxCvDbVAlignmentCurve::length() const
{
    return impObj()->length();
}

std::string PyBrxCvDbVAlignmentCurve::className()
{
    return "BrxCvDbVAlignmentCurve";
}

PyRxClass PyBrxCvDbVAlignmentCurve::desc()
{
    return PyRxClass(BrxCvDbVAlignmentCurve::desc(), false);
}

PyBrxCvDbVAlignmentCurve PyBrxCvDbVAlignmentCurve::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentCurve>(src);
}

BrxCvDbVAlignmentCurve* PyBrxCvDbVAlignmentCurve::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentCurve*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentTangent
void makePyBrxCvDbVAlignmentTangentWrapper()
{
    PyDocString DS("CvDbVAlignmentTangent");
    class_<PyBrxCvDbVAlignmentTangent, bases<PyBrxCvDbVAlignmentCurve>>("CvDbVAlignmentTangent")
        .def(init<>(DS.ARGS()))
        .def("passThroughPoint1", &PyBrxCvDbVAlignmentTangent::passThroughPoint1, DS.ARGS())
        .def("passThroughPoint2", &PyBrxCvDbVAlignmentTangent::passThroughPoint2, DS.ARGS())
        .def("setPassThroughPoint1", &PyBrxCvDbVAlignmentTangent::setPassThroughPoint1, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setPassThroughPoint2", &PyBrxCvDbVAlignmentTangent::setPassThroughPoint2, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbVAlignmentTangent::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentTangent::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentTangent::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentTangent::PyBrxCvDbVAlignmentTangent()
    : PyBrxCvDbVAlignmentTangent(new BrxCvDbVAlignmentTangent(), true)
{
}

PyBrxCvDbVAlignmentTangent::PyBrxCvDbVAlignmentTangent(BrxCvDbVAlignmentTangent* ptr, bool autoDelete)
    : PyBrxCvDbVAlignmentCurve(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbVAlignmentTangent::passThroughPoint1() const
{
    return impObj()->passThroughPoint1();
}

AcGePoint2d PyBrxCvDbVAlignmentTangent::passThroughPoint2() const
{
    return impObj()->passThroughPoint2();
}

bool PyBrxCvDbVAlignmentTangent::setPassThroughPoint1(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint1(point);
}

bool PyBrxCvDbVAlignmentTangent::setPassThroughPoint2(const AcGePoint2d& point) const
{
    return impObj()->setPassThroughPoint2(point);
}

std::string PyBrxCvDbVAlignmentTangent::className()
{
    return "BrxCvDbVAlignmentTangent";
}

PyRxClass PyBrxCvDbVAlignmentTangent::desc()
{
    return PyRxClass(BrxCvDbVAlignmentTangent::desc(), false);
}

PyBrxCvDbVAlignmentTangent PyBrxCvDbVAlignmentTangent::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentTangent>(src);
}

BrxCvDbVAlignmentTangent* PyBrxCvDbVAlignmentTangent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentTangent*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentArc
void makePyBrxCvDbVAlignmentArcWrapper()
{
    PyDocString DS("CvDbVAlignmentArc");
    class_<PyBrxCvDbVAlignmentArc, bases<PyBrxCvDbVAlignmentCurve>>("CvDbVAlignmentArc")
        .def(init<>(DS.ARGS()))
        .def("radius", &PyBrxCvDbVAlignmentArc::radius, DS.ARGS())
        .def("gradeIn", &PyBrxCvDbVAlignmentArc::gradeIn, DS.ARGS())
        .def("gradeOut", &PyBrxCvDbVAlignmentArc::gradeOut, DS.ARGS())
        .def("center", &PyBrxCvDbVAlignmentArc::center, DS.ARGS())
        .def("isClockwise", &PyBrxCvDbVAlignmentArc::isClockwise, DS.ARGS())
        .def("setRadius", &PyBrxCvDbVAlignmentArc::setRadius, DS.ARGS({ "val : float" }))
        .def("setCenter", &PyBrxCvDbVAlignmentArc::setCenter, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("setClockwise", &PyBrxCvDbVAlignmentArc::setClockwise, DS.ARGS({ "val : bool" }))
        .def("className", &PyBrxCvDbVAlignmentArc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentArc::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentArc::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentArc::PyBrxCvDbVAlignmentArc()
    : PyBrxCvDbVAlignmentArc(new BrxCvDbVAlignmentArc(), true)
{
}

PyBrxCvDbVAlignmentArc::PyBrxCvDbVAlignmentArc(BrxCvDbVAlignmentArc* ptr, bool autoDelete)
    :PyBrxCvDbVAlignmentCurve(ptr, autoDelete)
{
}

double PyBrxCvDbVAlignmentArc::radius() const
{
    return impObj()->radius();
}

double PyBrxCvDbVAlignmentArc::gradeIn() const
{
    return impObj()->gradeIn();
}

double PyBrxCvDbVAlignmentArc::gradeOut() const
{
    return impObj()->gradeOut();
}

AcGePoint2d PyBrxCvDbVAlignmentArc::center() const
{
    return impObj()->center();
}

bool PyBrxCvDbVAlignmentArc::isClockwise() const
{
    return impObj()->isClockwise();
}

bool PyBrxCvDbVAlignmentArc::setRadius(double rad) const
{
    return impObj()->setRadius(rad);
}

bool PyBrxCvDbVAlignmentArc::setCenter(const AcGePoint2d& center) const
{
    return impObj()->setCenter(center);
}

bool PyBrxCvDbVAlignmentArc::setClockwise(bool isClockwise) const
{
    return impObj()->setClockwise(isClockwise);
}

std::string PyBrxCvDbVAlignmentArc::className()
{
    return "BrxCvDbVAlignmentArc";
}

PyRxClass PyBrxCvDbVAlignmentArc::desc()
{
    return PyRxClass(BrxCvDbVAlignmentArc::desc(), false);
}

PyBrxCvDbVAlignmentArc PyBrxCvDbVAlignmentArc::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentArc>(src);
}

BrxCvDbVAlignmentArc* PyBrxCvDbVAlignmentArc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentArc*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentParabola
void makePyBrxCvDbVAlignmentParabolaWrapper()
{
    PyDocString DS("CvDbVAlignmentParabola");
    class_<PyBrxCvDbVAlignmentParabola, bases<PyBrxCvDbVAlignmentCurve>>("CvDbVAlignmentParabola")
        .def(init<>(DS.ARGS()))
        .def("radius", &PyBrxCvDbVAlignmentParabola::radius, DS.ARGS())
        .def("gradeIn", &PyBrxCvDbVAlignmentParabola::gradeIn, DS.ARGS())
        .def("gradeOut", &PyBrxCvDbVAlignmentParabola::gradeOut, DS.ARGS())
        .def("setRadius", &PyBrxCvDbVAlignmentParabola::setRadius, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbVAlignmentParabola::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVAlignmentParabola::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbVAlignmentParabola::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVAlignmentParabola::PyBrxCvDbVAlignmentParabola()
    :PyBrxCvDbVAlignmentParabola(new BrxCvDbVAlignmentParabola(), true)
{
}

PyBrxCvDbVAlignmentParabola::PyBrxCvDbVAlignmentParabola(BrxCvDbVAlignmentParabola* ptr, bool autoDelete)
    :PyBrxCvDbVAlignmentCurve(ptr, autoDelete)
{
}

double PyBrxCvDbVAlignmentParabola::radius() const
{
    return impObj()->radius();
}

double PyBrxCvDbVAlignmentParabola::gradeIn() const
{
    return impObj()->gradeIn();
}

double PyBrxCvDbVAlignmentParabola::gradeOut() const
{
    return impObj()->gradeOut();
}

bool PyBrxCvDbVAlignmentParabola::setRadius(double rad) const
{
    return impObj()->setRadius(rad);
}

std::string PyBrxCvDbVAlignmentParabola::className()
{
    return "BrxCvDbVAlignmentParabola";
}

PyRxClass PyBrxCvDbVAlignmentParabola::desc()
{
    return PyRxClass(BrxCvDbVAlignmentParabola::desc(), false);
}

PyBrxCvDbVAlignmentParabola PyBrxCvDbVAlignmentParabola::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbVAlignmentParabola>(src);
}

BrxCvDbVAlignmentParabola* PyBrxCvDbVAlignmentParabola::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbVAlignmentParabola*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyBrxCvDb3dAlignment
void makePyBrxCvDb3dAlignmentWrapper()
{
    PyDocString DS("CvDb3dAlignment");
    class_<PyBrxCvDb3dAlignment, bases<PyBrxCvDbCurve>>("CvDb3dAlignment")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("baseHAlignment", &PyBrxCvDb3dAlignment::baseHAlignment, DS.ARGS())
        .def("vAlignment", &PyBrxCvDb3dAlignment::vAlignment, DS.ARGS())
        .def("length", &PyBrxCvDb3dAlignment::length, DS.ARGS())
        .def("getPointsArray", &PyBrxCvDb3dAlignment::getPointsArray, DS.ARGS())
        .def("setBaseHAlignment", &PyBrxCvDb3dAlignment::setBaseHAlignment, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("setVAlignment", &PyBrxCvDb3dAlignment::setVAlignment, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("className", &PyBrxCvDb3dAlignment::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDb3dAlignment::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDb3dAlignment::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDb3dAlignment::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDb3dAlignment::PyBrxCvDb3dAlignment()
    : PyBrxCvDb3dAlignment(new BrxCvDb3dAlignment(), true)
{
}

PyBrxCvDb3dAlignment::PyBrxCvDb3dAlignment(const PyDbObjectId& id)
    : PyBrxCvDb3dAlignment(openAcDbObject<BrxCvDb3dAlignment>(id), false)
{
}

PyBrxCvDb3dAlignment::PyBrxCvDb3dAlignment(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDb3dAlignment(openAcDbObject<BrxCvDb3dAlignment>(id, mode), false)
{
}

PyBrxCvDb3dAlignment::PyBrxCvDb3dAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDb3dAlignment(openAcDbObject<BrxCvDb3dAlignment>(id, mode, erased), false)
{
}

PyBrxCvDb3dAlignment::PyBrxCvDb3dAlignment(BrxCvDb3dAlignment* ptr, bool autoDelete)
    : PyBrxCvDbCurve(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDb3dAlignment::baseHAlignment() const
{
    return PyDbObjectId(impObj()->baseHAlignment());
}

PyDbObjectId PyBrxCvDb3dAlignment::vAlignment() const
{
    return PyDbObjectId(impObj()->vAlignment());
}

double PyBrxCvDb3dAlignment::length() const
{
    return impObj()->length();
}

boost::python::list PyBrxCvDb3dAlignment::getPointsArray() const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray alignmentPoints;
    impObj()->getPointsArray(alignmentPoints);
    return Point3dArrayToPyList(alignmentPoints);
}

bool PyBrxCvDb3dAlignment::setBaseHAlignment(const PyDbObjectId& id) const
{
    return impObj()->setBaseHAlignment(id.m_id);
}

bool PyBrxCvDb3dAlignment::setVAlignment(const PyDbObjectId& id) const
{
    return impObj()->setVAlignment(id.m_id);
}

std::string PyBrxCvDb3dAlignment::className()
{
    return "BrxCvDb3dAlignment";
}

PyRxClass PyBrxCvDb3dAlignment::desc()
{
    return PyRxClass(BrxCvDb3dAlignment::desc(), false);
}

PyBrxCvDb3dAlignment PyBrxCvDb3dAlignment::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDb3dAlignment::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return PyBrxCvDb3dAlignment(static_cast<BrxCvDb3dAlignment*>(src.impObj()->clone()), true);
}

PyBrxCvDb3dAlignment PyBrxCvDb3dAlignment::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDb3dAlignment>(src);
}

BrxCvDb3dAlignment* PyBrxCvDb3dAlignment::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDb3dAlignment*>(m_pyImp.get());
}

#endif//BRXAPP
