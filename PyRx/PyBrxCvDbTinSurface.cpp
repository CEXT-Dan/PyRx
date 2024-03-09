#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"
#include "PyGeLinearEnt2d.h"
#include "PyDbEnts.h"

#ifdef BRXAPP
using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinition
void makePyBrxCvDbTinSurfaceDefinitionWrapper()
{
    PyDocString DS("CvDbSubObject");
    class_<PyBrxCvDbTinSurfaceDefinition, bases<PyBrxCvDbSubObject>>("CvDbTinSurfaceDefinition", boost::python::no_init)
        .def("name", &PyBrxCvDbTinSurfaceDefinition::name, DS.ARGS())
        .def("setName", &PyBrxCvDbTinSurfaceDefinition::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbTinSurfaceDefinition::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbTinSurfaceDefinition::setDescription, DS.ARGS({ "val : str" }))
        .def("type", &PyBrxCvDbTinSurfaceDefinition::type, DS.ARGS())
        .def("isUpdateNeeded", &PyBrxCvDbTinSurfaceDefinition::isUpdateNeeded, DS.ARGS())
        .def("isSubDefinition", &PyBrxCvDbTinSurfaceDefinition::isSubDefinition, DS.ARGS())
        .def("isValid", &PyBrxCvDbTinSurfaceDefinition::isValid, DS.ARGS())
        .def("isEnabled", &PyBrxCvDbTinSurfaceDefinition::isEnabled, DS.ARGS())
        .def("setEnabled", &PyBrxCvDbTinSurfaceDefinition::setEnabled, DS.ARGS({ "val : bool" }))
        .def("isReadOnly", &PyBrxCvDbTinSurfaceDefinition::isReadOnly, DS.ARGS())
        .def("setReadOnly", &PyBrxCvDbTinSurfaceDefinition::setReadOnly, DS.ARGS({ "val : bool" }))
        .def("id", &PyBrxCvDbTinSurfaceDefinition::id, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinition::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinition::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}


PyBrxCvDbTinSurfaceDefinition::PyBrxCvDbTinSurfaceDefinition(BrxCvDbTinSurfaceDefinition* ptr, bool autoDelete)
    :PyBrxCvDbSubObject(ptr, autoDelete)
{
}

std::string PyBrxCvDbTinSurfaceDefinition::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbTinSurfaceDefinition::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbTinSurfaceDefinition::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbTinSurfaceDefinition::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
}

PyBrxCvDbTinSurfaceDefinition::EType PyBrxCvDbTinSurfaceDefinition::type() const
{
    return impObj()->type();
}

bool PyBrxCvDbTinSurfaceDefinition::isUpdateNeeded() const
{
    return impObj()->isUpdateNeeded();
}

bool PyBrxCvDbTinSurfaceDefinition::isSubDefinition() const
{
    return impObj()->isSubDefinition();
}

bool PyBrxCvDbTinSurfaceDefinition::isValid() const
{
    return impObj()->isValid();
}

bool PyBrxCvDbTinSurfaceDefinition::isEnabled() const
{
    return impObj()->isEnabled();
}

bool PyBrxCvDbTinSurfaceDefinition::setEnabled(const bool enabled)
{
    return impObj()->setEnabled(enabled);
}

bool PyBrxCvDbTinSurfaceDefinition::isReadOnly() const
{
    return impObj()->isReadOnly();
}

bool PyBrxCvDbTinSurfaceDefinition::setReadOnly(const bool readOnly)
{
    return impObj()->setReadOnly(readOnly);
}

Adesk::UInt64 PyBrxCvDbTinSurfaceDefinition::id() const
{
    return impObj()->id();
}

std::string PyBrxCvDbTinSurfaceDefinition::className()
{
    return "BrxCvDbTinSurfaceDefinition";
}

PyRxClass PyBrxCvDbTinSurfaceDefinition::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinition::desc(), false);
}

PyBrxCvDbTinSurfaceDefinition PyBrxCvDbTinSurfaceDefinition::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinition* PyBrxCvDbTinSurfaceDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionGroupDefs
void makePyBrxCvDbTinSurfaceDefinitionGroupDefsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionGroupDefs");
    class_<PyBrxCvDbTinSurfaceDefinitionGroupDefs, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionGroupDefs")
        .def(init<>())
        .def("numSubDefinitions", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::numSubDefinitions, DS.ARGS())
        .def("findSubDefinition", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::findSubDefinition, DS.ARGS({ "val : int" }))
        .def("addSubDefinition", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::addSubDefinition, DS.ARGS({ "val : PyBrxCv.CvDbTinSurfaceDefinition" }))
        .def("getSubDefinitionAt", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::getSubDefinitionAt, DS.ARGS({ "val : int" }))
        .def("removeSubDefinitionAt", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::removeSubDefinitionAt, DS.ARGS({ "val : int" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionGroupDefs::PyBrxCvDbTinSurfaceDefinitionGroupDefs()
    :PyBrxCvDbTinSurfaceDefinitionGroupDefs(new BrxCvDbTinSurfaceDefinitionGroupDefs(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionGroupDefs::PyBrxCvDbTinSurfaceDefinitionGroupDefs(BrxCvDbTinSurfaceDefinitionGroupDefs* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionGroupDefs::numSubDefinitions() const
{
    return impObj()->numSubDefinitions();
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionGroupDefs::findSubDefinition(const Adesk::UInt64 definitionId) const
{
    Adesk::UInt32 idx = 0;
    impObj()->findSubDefinition(definitionId, idx);
    return idx;
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionGroupDefs::addSubDefinition(const PyBrxCvDbTinSurfaceDefinition& subDefinition)
{
    return impObj()->addSubDefinition(*subDefinition.impObj());
}

PyBrxCvDbTinSurfaceDefinition PyBrxCvDbTinSurfaceDefinitionGroupDefs::getSubDefinitionAt(const Adesk::UInt32 index) const
{
    auto ptr = impObj()->getSubDefinitionAt(index);
    if (ptr.refCount() == 1)
        return PyBrxCvDbTinSurfaceDefinition(ptr.detach(), true);
    throw PyAcadErrorStatus(Acad::eInvalidOpenState);
}

bool PyBrxCvDbTinSurfaceDefinitionGroupDefs::removeSubDefinitionAt(const Adesk::UInt32 index)
{
    return impObj()->removeSubDefinitionAt(index);
}

std::string PyBrxCvDbTinSurfaceDefinitionGroupDefs::className()
{
    return "BrxCvDbTinSurfaceDefinitionGroupDefs";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionGroupDefs::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionGroupDefs::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionGroupDefs PyBrxCvDbTinSurfaceDefinitionGroupDefs::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionGroupDefs dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionGroupDefs* PyBrxCvDbTinSurfaceDefinitionGroupDefs::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionGroupDefs*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionTransform
void makePyBrxCvDbTinSurfaceDefinitionTransformWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionTransform");
    class_<PyBrxCvDbTinSurfaceDefinitionTransform, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionTransform")
        .def(init<>())
        .def(init<const AcGeMatrix3d&>())
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionTransform::transformationMatrix, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionTransform::setTransformationMatrix, DS.ARGS({ "xform : PyGe.Matrix3d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionTransform::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionTransform::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionTransform::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionTransform::PyBrxCvDbTinSurfaceDefinitionTransform()
    :PyBrxCvDbTinSurfaceDefinitionTransform(new BrxCvDbTinSurfaceDefinitionTransform(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionTransform::PyBrxCvDbTinSurfaceDefinitionTransform(const AcGeMatrix3d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionTransform(new BrxCvDbTinSurfaceDefinitionTransform(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionTransform::PyBrxCvDbTinSurfaceDefinitionTransform(BrxCvDbTinSurfaceDefinitionTransform* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGeMatrix3d PyBrxCvDbTinSurfaceDefinitionTransform::transformationMatrix() const
{
    return impObj()->transformationMatrix();
}

bool PyBrxCvDbTinSurfaceDefinitionTransform::setTransformationMatrix(const AcGeMatrix3d& mtx)
{
    return impObj()->setTransformationMatrix(mtx);
}

std::string PyBrxCvDbTinSurfaceDefinitionTransform::className()
{
    return "BrxCvDbTinSurfaceDefinitionTransform";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionTransform::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionTransform::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionTransform PyBrxCvDbTinSurfaceDefinitionTransform::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionTransform dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionTransform* PyBrxCvDbTinSurfaceDefinitionTransform::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionTransform*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPoint
void makePyBrxCvDbTinSurfaceDefinitionAddPointWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddPoint");
    class_<PyBrxCvDbTinSurfaceDefinitionAddPoint, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddPoint")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def("position", &PyBrxCvDbTinSurfaceDefinitionAddPoint::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbTinSurfaceDefinitionAddPoint::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddPoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddPoint::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddPoint::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddPoint::PyBrxCvDbTinSurfaceDefinitionAddPoint()
    :PyBrxCvDbTinSurfaceDefinitionAddPoint(new BrxCvDbTinSurfaceDefinitionAddPoint(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPoint::PyBrxCvDbTinSurfaceDefinitionAddPoint(const AcGePoint3d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionAddPoint(new BrxCvDbTinSurfaceDefinitionAddPoint(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPoint::PyBrxCvDbTinSurfaceDefinitionAddPoint(BrxCvDbTinSurfaceDefinitionAddPoint* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint3d PyBrxCvDbTinSurfaceDefinitionAddPoint::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbTinSurfaceDefinitionAddPoint::setPosition(const AcGePoint3d& position)
{
    return impObj()->setPosition(position);
}

std::string PyBrxCvDbTinSurfaceDefinitionAddPoint::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddPoint";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddPoint::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddPoint::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddPoint PyBrxCvDbTinSurfaceDefinitionAddPoint::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionAddPoint dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionAddPoint* PyBrxCvDbTinSurfaceDefinitionAddPoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddPoint*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPoints
void makePyBrxCvDbTinSurfaceDefinitionAddPointsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddPoints");
    class_<PyBrxCvDbTinSurfaceDefinitionAddPoints, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddPoints")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def("positions", &PyBrxCvDbTinSurfaceDefinitionAddPoints::positions, DS.ARGS())
        .def("setPositions", &PyBrxCvDbTinSurfaceDefinitionAddPoints::setPositions, DS.ARGS({ "pt : list[PyGe.Point3d]" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddPoints::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddPoints::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddPoints::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddPoints::PyBrxCvDbTinSurfaceDefinitionAddPoints()
    :PyBrxCvDbTinSurfaceDefinitionAddPoints(new BrxCvDbTinSurfaceDefinitionAddPoints(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPoints::PyBrxCvDbTinSurfaceDefinitionAddPoints(const boost::python::list& positions)
    :PyBrxCvDbTinSurfaceDefinitionAddPoints(new BrxCvDbTinSurfaceDefinitionAddPoints(PyListToPoint3dArray(positions)), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPoints::PyBrxCvDbTinSurfaceDefinitionAddPoints(BrxCvDbTinSurfaceDefinitionAddPoints* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionAddPoints::positions() const
{
    return Point3dArrayToPyList(impObj()->positions());
}

bool PyBrxCvDbTinSurfaceDefinitionAddPoints::setPositions(const boost::python::list& positions)
{
    return impObj()->setPositions(PyListToPoint3dArray(positions));
}

std::string PyBrxCvDbTinSurfaceDefinitionAddPoints::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddPoint";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddPoints::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddPoint::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddPoints PyBrxCvDbTinSurfaceDefinitionAddPoints::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionAddPoints dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionAddPoints* PyBrxCvDbTinSurfaceDefinitionAddPoints::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddPoints*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeletePoint
void makePyBrxCvDbTinSurfaceDefinitionDeletePointWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionDeletePoint");
    class_<PyBrxCvDbTinSurfaceDefinitionDeletePoint, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionDeletePoint")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def("position", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::setPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionDeletePoint::PyBrxCvDbTinSurfaceDefinitionDeletePoint()
    :PyBrxCvDbTinSurfaceDefinitionDeletePoint(new BrxCvDbTinSurfaceDefinitionDeletePoint(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeletePoint::PyBrxCvDbTinSurfaceDefinitionDeletePoint(const AcGePoint2d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionDeletePoint(new BrxCvDbTinSurfaceDefinitionDeletePoint(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeletePoint::PyBrxCvDbTinSurfaceDefinitionDeletePoint(BrxCvDbTinSurfaceDefinitionDeletePoint* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionDeletePoint::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbTinSurfaceDefinitionDeletePoint::setPosition(const AcGePoint2d& position)
{
    return impObj()->setPosition(position);
}

std::string PyBrxCvDbTinSurfaceDefinitionDeletePoint::className()
{
    return "BrxCvDbTinSurfaceDefinitionDeletePoint";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionDeletePoint::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionDeletePoint::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionDeletePoint PyBrxCvDbTinSurfaceDefinitionDeletePoint::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionDeletePoint dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionDeletePoint* PyBrxCvDbTinSurfaceDefinitionDeletePoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionDeletePoint*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeletePoints
void makePyBrxCvDbTinSurfaceDefinitionDeletePointsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionDeletePoints");
    class_<PyBrxCvDbTinSurfaceDefinitionDeletePoints, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionDeletePoints")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def("positions", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::positions, DS.ARGS())
        .def("setPositions", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::setPositions, DS.ARGS({ "pt : list[PyGe.Point2d]" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionDeletePoints::PyBrxCvDbTinSurfaceDefinitionDeletePoints()
    :PyBrxCvDbTinSurfaceDefinitionDeletePoints(new BrxCvDbTinSurfaceDefinitionDeletePoints(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeletePoints::PyBrxCvDbTinSurfaceDefinitionDeletePoints(const boost::python::list& positions)
    :PyBrxCvDbTinSurfaceDefinitionDeletePoints(new BrxCvDbTinSurfaceDefinitionDeletePoints(PyListToPoint2dArray(positions)), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeletePoints::PyBrxCvDbTinSurfaceDefinitionDeletePoints(BrxCvDbTinSurfaceDefinitionDeletePoints* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionDeletePoints::positions() const
{
    return Point2dArrayToPyList(impObj()->positions());
}

bool PyBrxCvDbTinSurfaceDefinitionDeletePoints::setPositions(const boost::python::list& positions)
{
    return impObj()->setPositions(PyListToPoint2dArray(positions));
}

std::string PyBrxCvDbTinSurfaceDefinitionDeletePoints::className()
{
    return "BrxCvDbTinSurfaceDefinitionDeletePoint";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionDeletePoints::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionDeletePoint::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionDeletePoints PyBrxCvDbTinSurfaceDefinitionDeletePoints::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionDeletePoints dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionDeletePoints* PyBrxCvDbTinSurfaceDefinitionDeletePoints::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionDeletePoints*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionSwapEdge
void makePyBrxCvDbTinSurfaceDefinitionSwapEdgeWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionSwapEdge");
    class_<PyBrxCvDbTinSurfaceDefinitionSwapEdge, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionSwapEdge")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def("position", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::setPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionSwapEdge::PyBrxCvDbTinSurfaceDefinitionSwapEdge()
    :PyBrxCvDbTinSurfaceDefinitionSwapEdge(new BrxCvDbTinSurfaceDefinitionSwapEdge(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionSwapEdge::PyBrxCvDbTinSurfaceDefinitionSwapEdge(const AcGePoint2d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionSwapEdge(new BrxCvDbTinSurfaceDefinitionSwapEdge(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionSwapEdge::PyBrxCvDbTinSurfaceDefinitionSwapEdge(BrxCvDbTinSurfaceDefinitionSwapEdge* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionSwapEdge::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbTinSurfaceDefinitionSwapEdge::setPosition(const AcGePoint2d& position)
{
    return impObj()->setPosition(position);
}

std::string PyBrxCvDbTinSurfaceDefinitionSwapEdge::className()
{
    return "BrxCvDbTinSurfaceDefinitionSwapEdge";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionSwapEdge::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionSwapEdge::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionSwapEdge PyBrxCvDbTinSurfaceDefinitionSwapEdge::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionSwapEdge dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionSwapEdge* PyBrxCvDbTinSurfaceDefinitionSwapEdge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionSwapEdge*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionMovePoint
void makePyBrxCvDbTinSurfaceDefinitionMovePointWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionMovePoint");
    class_<PyBrxCvDbTinSurfaceDefinitionMovePoint, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionMovePoint")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def("fromPosition", &PyBrxCvDbTinSurfaceDefinitionMovePoint::fromPosition, DS.ARGS())
        .def("setFromPosition", &PyBrxCvDbTinSurfaceDefinitionMovePoint::setFromPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("toPosition", &PyBrxCvDbTinSurfaceDefinitionMovePoint::toPosition, DS.ARGS())
        .def("setToPosition", &PyBrxCvDbTinSurfaceDefinitionMovePoint::setToPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionMovePoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionMovePoint::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionMovePoint::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionMovePoint::PyBrxCvDbTinSurfaceDefinitionMovePoint()
    :PyBrxCvDbTinSurfaceDefinitionMovePoint(new BrxCvDbTinSurfaceDefinitionMovePoint(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionMovePoint::PyBrxCvDbTinSurfaceDefinitionMovePoint(const AcGePoint2d& from, const AcGePoint2d& to)
    :PyBrxCvDbTinSurfaceDefinitionMovePoint(new BrxCvDbTinSurfaceDefinitionMovePoint(from, to), true)
{
}

PyBrxCvDbTinSurfaceDefinitionMovePoint::PyBrxCvDbTinSurfaceDefinitionMovePoint(BrxCvDbTinSurfaceDefinitionMovePoint* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionMovePoint::fromPosition() const
{
    return impObj()->fromPosition();
}

bool PyBrxCvDbTinSurfaceDefinitionMovePoint::setFromPosition(const AcGePoint2d& fromPoint)
{
    return impObj()->setFromPosition(fromPoint);
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionMovePoint::toPosition() const
{
    return impObj()->toPosition();
}

bool PyBrxCvDbTinSurfaceDefinitionMovePoint::setToPosition(const AcGePoint2d& toPoint)
{
    return impObj()->setToPosition(toPoint);
}

std::string PyBrxCvDbTinSurfaceDefinitionMovePoint::className()
{
    return "BrxCvDbTinSurfaceDefinitionMovePoint";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionMovePoint::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionMovePoint::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionMovePoint PyBrxCvDbTinSurfaceDefinitionMovePoint::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionMovePoint dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionMovePoint* PyBrxCvDbTinSurfaceDefinitionMovePoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionMovePoint*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionMovePoints
void makePyBrxCvDbTinSurfaceDefinitionMovePointsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionMovePoints");
    class_<PyBrxCvDbTinSurfaceDefinitionMovePoints, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionMovePoints")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector2d&>())

        .def("fromPoints", &PyBrxCvDbTinSurfaceDefinitionMovePoints::fromPoints, DS.ARGS())
        .def("setFromPoints", &PyBrxCvDbTinSurfaceDefinitionMovePoints::setFromPoints, DS.ARGS({ "pt : list[PyGe.Point2d]" }))
        .def("displacement", &PyBrxCvDbTinSurfaceDefinitionMovePoints::displacement, DS.ARGS())
        .def("setDisplacement", &PyBrxCvDbTinSurfaceDefinitionMovePoints::setDisplacement, DS.ARGS({ "vec : PyGe.Vector3d" }))

        .def("className", &PyBrxCvDbTinSurfaceDefinitionMovePoints::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionMovePoints::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionMovePoints::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionMovePoints::PyBrxCvDbTinSurfaceDefinitionMovePoints()
    :PyBrxCvDbTinSurfaceDefinitionMovePoints(new BrxCvDbTinSurfaceDefinitionMovePoints(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionMovePoints::PyBrxCvDbTinSurfaceDefinitionMovePoints(const boost::python::list& from, const AcGeVector2d& displacement)
    :PyBrxCvDbTinSurfaceDefinitionMovePoints(new BrxCvDbTinSurfaceDefinitionMovePoints(PyListToPoint2dArray(from), displacement), true)
{
}

PyBrxCvDbTinSurfaceDefinitionMovePoints::PyBrxCvDbTinSurfaceDefinitionMovePoints(BrxCvDbTinSurfaceDefinitionMovePoints* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionMovePoints::fromPoints() const
{
    return Point2dArrayToPyList(impObj()->fromPoints());
}

bool PyBrxCvDbTinSurfaceDefinitionMovePoints::setFromPoints(const boost::python::list& fromPoints)
{
    return impObj()->setFromPoints(PyListToPoint2dArray(fromPoints));
}

AcGeVector2d PyBrxCvDbTinSurfaceDefinitionMovePoints::displacement() const
{
    return impObj()->displacement();
}

bool PyBrxCvDbTinSurfaceDefinitionMovePoints::setDisplacement(const AcGeVector2d& displacement)
{
    return impObj()->setDisplacement(displacement);
}

std::string PyBrxCvDbTinSurfaceDefinitionMovePoints::className()
{
    return "BrxCvDbTinSurfaceDefinitionMovePoints";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionMovePoints::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionMovePoints::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionMovePoints PyBrxCvDbTinSurfaceDefinitionMovePoints::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionMovePoints dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionMovePoints* PyBrxCvDbTinSurfaceDefinitionMovePoints::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionMovePoints*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeleteEdge
void makePyBrxCvDbTinSurfaceDefinitionDeleteEdgeWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionDeleteEdge");
    class_<PyBrxCvDbTinSurfaceDefinitionDeleteEdge, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionDeleteEdge")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def("position", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::setPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdge::PyBrxCvDbTinSurfaceDefinitionDeleteEdge()
    :PyBrxCvDbTinSurfaceDefinitionDeleteEdge(new BrxCvDbTinSurfaceDefinitionDeleteEdge(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdge::PyBrxCvDbTinSurfaceDefinitionDeleteEdge(const AcGePoint2d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionDeleteEdge(new BrxCvDbTinSurfaceDefinitionDeleteEdge(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdge::PyBrxCvDbTinSurfaceDefinitionDeleteEdge(BrxCvDbTinSurfaceDefinitionDeleteEdge* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionDeleteEdge::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbTinSurfaceDefinitionDeleteEdge::setPosition(const AcGePoint2d& position)
{
    return impObj()->setPosition(position);
}

std::string PyBrxCvDbTinSurfaceDefinitionDeleteEdge::className()
{
    return "BrxCvDbTinSurfaceDefinitionDeleteEdge";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionDeleteEdge::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionDeleteEdge::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdge PyBrxCvDbTinSurfaceDefinitionDeleteEdge::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionDeleteEdge dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionDeleteEdge* PyBrxCvDbTinSurfaceDefinitionDeleteEdge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionDeleteEdge*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeleteEdges
void makePyBrxCvDbTinSurfaceDefinitionDeleteEdgesWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionDeleteEdges");
    class_<PyBrxCvDbTinSurfaceDefinitionDeleteEdges, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionDeleteEdges")
        .def(init<>())
        .def("polygonsCount", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::polygonsCount, DS.ARGS())
        .def("polygonAt", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::polygonAt, DS.ARGS({ "index : int" }))
        .def("addPolygon", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::addPolygon, DS.ARGS({ "edgePolygon : list[PyGe.Point2d]", "includeIntersected : bool" }))
        .def("removePolygonAt", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::removePolygonAt, DS.ARGS({ "index : int" }))
        .def("removeAllPolygons", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::removeAllPolygons, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdges::PyBrxCvDbTinSurfaceDefinitionDeleteEdges()
    :PyBrxCvDbTinSurfaceDefinitionDeleteEdges(new BrxCvDbTinSurfaceDefinitionDeleteEdges(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdges::PyBrxCvDbTinSurfaceDefinitionDeleteEdges(BrxCvDbTinSurfaceDefinitionDeleteEdges* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionDeleteEdges::polygonsCount() const
{
    return impObj()->polygonsCount();
}

boost::python::tuple PyBrxCvDbTinSurfaceDefinitionDeleteEdges::polygonAt(const Adesk::UInt32 index) const
{
    PyAutoLockGIL lock;
    bool includeIntersected = false;
    const auto& tmp = Point2dArrayToPyList(impObj()->polygonAt(index, includeIntersected));
    return boost::python::make_tuple(includeIntersected, tmp);
}

bool PyBrxCvDbTinSurfaceDefinitionDeleteEdges::addPolygon(const boost::python::list& edgePolygon, bool includeIntersected)
{
    return impObj()->addPolygon(PyListToPoint2dArray(edgePolygon), includeIntersected);
}

bool PyBrxCvDbTinSurfaceDefinitionDeleteEdges::removePolygonAt(const Adesk::UInt32 index)
{
    return impObj()->removePolygonAt(index);
}

bool PyBrxCvDbTinSurfaceDefinitionDeleteEdges::removeAllPolygons()
{
    return impObj()->removeAllPolygons();
}

std::string PyBrxCvDbTinSurfaceDefinitionDeleteEdges::className()
{
    return "BrxCvDbTinSurfaceDefinitionDeleteEdges";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionDeleteEdges::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionDeleteEdges::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionDeleteEdges PyBrxCvDbTinSurfaceDefinitionDeleteEdges::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionDeleteEdges dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionDeleteEdges* PyBrxCvDbTinSurfaceDefinitionDeleteEdges::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionDeleteEdges*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddLine
void makePyBrxCvDbTinSurfaceDefinitionAddLineWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddLine");
    class_<PyBrxCvDbTinSurfaceDefinitionAddLine, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddLine")
        .def(init<>())
        .def(init<const AcGeLineSeg2d&>())
        .def("line", &PyBrxCvDbTinSurfaceDefinitionAddLine::line, DS.ARGS())
        .def("setLine", &PyBrxCvDbTinSurfaceDefinitionAddLine::setLine, DS.ARGS({ "line : PyGe.LineSeg2d" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddLine::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddLine::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddLine::PyBrxCvDbTinSurfaceDefinitionAddLine()
    :PyBrxCvDbTinSurfaceDefinitionAddLine(new BrxCvDbTinSurfaceDefinitionAddLine(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddLine::PyBrxCvDbTinSurfaceDefinitionAddLine(const AcGeLineSeg2d& mtx)
    :PyBrxCvDbTinSurfaceDefinitionAddLine(new BrxCvDbTinSurfaceDefinitionAddLine(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddLine::PyBrxCvDbTinSurfaceDefinitionAddLine(BrxCvDbTinSurfaceDefinitionAddLine* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

PyGeLineSeg2d PyBrxCvDbTinSurfaceDefinitionAddLine::line() const
{
    return PyGeLineSeg2d(impObj()->line());
}

bool PyBrxCvDbTinSurfaceDefinitionAddLine::setLine(const PyGeLineSeg2d& line)
{
    return impObj()->setLine(*line.impObj());
}

std::string PyBrxCvDbTinSurfaceDefinitionAddLine::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddLine";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddLine::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddLine::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddLine PyBrxCvDbTinSurfaceDefinitionAddLine::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionAddLine dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionAddLine* PyBrxCvDbTinSurfaceDefinitionAddLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddLines
void makePyBrxCvDbTinSurfaceDefinitionAddLinesWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddLines");
    class_<PyBrxCvDbTinSurfaceDefinitionAddLines, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddLines")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def("lines", &PyBrxCvDbTinSurfaceDefinitionAddLines::lines, DS.ARGS())
        .def("setLines", &PyBrxCvDbTinSurfaceDefinitionAddLines::setLines, DS.ARGS({ "lines : list[PyGe.LineSeg2d]" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddLines::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddLines::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddLines::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddLines::PyBrxCvDbTinSurfaceDefinitionAddLines()
    :PyBrxCvDbTinSurfaceDefinitionAddLines(new BrxCvDbTinSurfaceDefinitionAddLines(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddLines::PyBrxCvDbTinSurfaceDefinitionAddLines(const boost::python::list& mtx)
    :PyBrxCvDbTinSurfaceDefinitionAddLines(new BrxCvDbTinSurfaceDefinitionAddLines(PyListAcGeLineSeg2dArray(mtx)), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddLines::PyBrxCvDbTinSurfaceDefinitionAddLines(BrxCvDbTinSurfaceDefinitionAddLines* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionAddLines::lines() const
{
    return AcGeLineSeg2dArrayToPyList(impObj()->lines());
}

bool PyBrxCvDbTinSurfaceDefinitionAddLines::setLines(const boost::python::list& line)
{
    return impObj()->setLines(PyListAcGeLineSeg2dArray(line));
}

std::string PyBrxCvDbTinSurfaceDefinitionAddLines::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddLines";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddLines::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddLines::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddLines PyBrxCvDbTinSurfaceDefinitionAddLines::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionAddLines dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionAddLines* PyBrxCvDbTinSurfaceDefinitionAddLines::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddLines*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointElevation
void makePyBrxCvDbTinSurfaceDefinitionModifyPointElevationWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionModifyPointElevation");
    class_<PyBrxCvDbTinSurfaceDefinitionModifyPointElevation, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionModifyPointElevation")
        .def(init<>())
        .def(init<const AcGePoint2d&, double, bool>())
        .def("position", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setPosition, DS.ARGS({ "pt : PyGe.Point2d" }))
        .def("elevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::elevation, DS.ARGS())
        .def("setElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setElevation, DS.ARGS({ "val : float" }))
        .def("isDeltaElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::isDeltaElevation, DS.ARGS())
        .def("setIsDeltaElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setIsDeltaElevation, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointElevation()
    :PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(new BrxCvDbTinSurfaceDefinitionModifyPointElevation(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(const AcGePoint2d& pt, double elevation, bool isDeltaElevation)
    :PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(new BrxCvDbTinSurfaceDefinitionModifyPointElevation(pt, elevation, isDeltaElevation), true)
{
}

PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(BrxCvDbTinSurfaceDefinitionModifyPointElevation* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

AcGePoint2d PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setPosition(const AcGePoint2d& position)
{
    return impObj()->setPosition(position);
}

double PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::elevation() const
{
    return impObj()->elevation();
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setElevation(double elevation)
{
    return impObj()->setElevation(elevation);
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::isDeltaElevation() const
{
    return impObj()->isDeltaElevation();
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::setIsDeltaElevation(const bool isDeltaElevation)
{
    return impObj()->setIsDeltaElevation(isDeltaElevation);
}

std::string PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::className()
{
    return "BrxCvDbTinSurfaceDefinitionModifyPointElevation";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionModifyPointElevation::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionModifyPointElevation PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionModifyPointElevation dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionModifyPointElevation* PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionModifyPointElevation*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation
void makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionModifyPointsElevation");
    class_<PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionModifyPointsElevation")
        .def(init<>())
        .def(init<const boost::python::list&, double, bool >())
        .def("positions", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::positions, DS.ARGS())
        .def("setPositions", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::setPositions, DS.ARGS({ "pt : list[PyGe.Point2d]" }))
        .def("elevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::elevation, DS.ARGS())
        .def("setElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::setElevation, DS.ARGS({ "val : float" }))
        .def("isDeltaElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::isDeltaElevation, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation()
    :PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(new BrxCvDbTinSurfaceDefinitionModifyPointsElevation(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(const boost::python::list& pos, double elevation, bool isDeltaElevation)
    :PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(new BrxCvDbTinSurfaceDefinitionModifyPointsElevation(PyListToPoint2dArray(pos), elevation, isDeltaElevation), true)
{
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(BrxCvDbTinSurfaceDefinitionModifyPointsElevation* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::positions() const
{
    return Point2dArrayToPyList(impObj()->positions());
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::setPositions(const boost::python::list& position)
{
    return impObj()->setPositions(PyListToPoint2dArray(position));
}

double PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::elevation() const
{
    return impObj()->elevation();
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::setElevation(double elevation)
{
    return impObj()->setElevation(elevation);
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::isDeltaElevation() const
{
    return impObj()->isDeltaElevation();
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::setIsDeltaElevation(bool isDeltaElevation)
{
    return impObj()->setIsDeltaElevation(isDeltaElevation);
}

std::string PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::className()
{
    return "BrxCvDbTinSurfaceDefinitionModifyPointsElevation";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionModifyPointsElevation::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionModifyPointsElevation* PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionModifyPointsElevation*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations
void makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionModifyPointsElevations");
    class_<PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionModifyPointsElevations")
        .def(init<>())
        .def("pointElevationsCount", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::pointElevationsCount)
        .def("pointElevationAt", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::pointElevationAt)
        .def("addPointElevation", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::addPointElevation)
        .def("removePointElevationAt", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::removePointElevationAt)
        .def("removeAllPointElevations", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::removeAllPointElevations)
        .def("className", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations()
    :PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations(new BrxCvDbTinSurfaceDefinitionModifyPointsElevations(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations(BrxCvDbTinSurfaceDefinitionModifyPointsElevations* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::pointElevationsCount() const
{
    return impObj()->pointElevationsCount();
}

boost::python::tuple PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::pointElevationAt(const Adesk::UInt32 index) const
{
    PyAutoLockGIL lock;
    AcGePoint2d position;
    double elevation;
    auto flag = impObj()->pointElevationAt(index, position, elevation);
    return boost::python::make_tuple(flag, position, elevation);
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::addPointElevation(const AcGePoint2d& position, double elevation)
{
    return impObj()->addPointElevation(position, elevation);
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::removePointElevationAt(const Adesk::UInt32 index)
{
    return impObj()->removePointElevationAt(index);
}

bool PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::removeAllPointElevations()
{
    return impObj()->removeAllPointElevations();
}

std::string PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::className()
{
    return "BrxCvDbTinSurfaceDefinitionModifyPointsElevations";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionModifyPointsElevations::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionModifyPointsElevations* PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionModifyPointsElevations*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromFaces
void makePyBrxCvDbTinSurfaceDefinitionCreateFromFacesWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionCreateFromFaces");
    class_<PyBrxCvDbTinSurfaceDefinitionCreateFromFaces, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionCreateFromFaces")
        .def(init<>())
        .def(init<const boost::python::list&, bool>())
        .def("facesCount", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::facesCount)
        .def("faceAt", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::faceAt)
        .def("points", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::points)
        .def("isApplyEdgesVisibility", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::isApplyEdgesVisibility)
        .def("setIsApplyEdgesVisibility", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::setIsApplyEdgesVisibility)
        .def("className", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::PyBrxCvDbTinSurfaceDefinitionCreateFromFaces()
    :PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(new BrxCvDbTinSurfaceDefinitionCreateFromFaces(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(const boost::python::list& pnt, bool applyEdgesVisibility)
    :PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(new BrxCvDbTinSurfaceDefinitionCreateFromFaces(PyListToPoint3dArray(pnt), applyEdgesVisibility), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(BrxCvDbTinSurfaceDefinitionCreateFromFaces* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::facesCount() const
{
    return impObj()->facesCount();
}

boost::python::tuple PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::faceAt(const Adesk::UInt32 index) const
{
    PyAutoLockGIL lock;
    AcDbFace* ptr = nullptr;
    bool flag = impObj()->faceAt(index, ptr);
    return boost::python::make_tuple(flag, PyDbFace(ptr, true));
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::points() const
{
    return Point3dArrayToPyList(impObj()->facesCount());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::isApplyEdgesVisibility() const
{
    return impObj()->isApplyEdgesVisibility();
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::setIsApplyEdgesVisibility(bool isApplyEdges)
{
    return impObj()->setIsApplyEdgesVisibility(isApplyEdges);
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::className()
{
    return "BrxCvDbTinSurfaceDefinitionCreateFromFaces";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionCreateFromFaces::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionCreateFromFaces PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinitionCreateFromFaces dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinitionCreateFromFaces* PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionCreateFromFaces*>(m_pyImp.get());
}
#endif //BRXAPP
