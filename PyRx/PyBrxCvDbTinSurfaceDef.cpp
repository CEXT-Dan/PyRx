#include "stdafx.h"

#ifdef BRXAPP
#include "PyBrxCvDbTinSurfaceDef.h"
#include "PyGeLinearEnt2d.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinition
void makePyBrxCvDbTinSurfaceDefinitionWrapper()
{
    PyDocString DS("CvDbSubObject");
    class_<PyBrxCvDbTinSurfaceDefinition, bases<PyBrxCvDbSubObject>>("CvDbTinSurfaceDefinition", boost::python::no_init)
        .def("name", &PyBrxCvDbTinSurfaceDefinition::name, DS.ARGS())
        .def("setName", &PyBrxCvDbTinSurfaceDefinition::setName, DS.ARGS({ "name : str" }))
        .def("description", &PyBrxCvDbTinSurfaceDefinition::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbTinSurfaceDefinition::setDescription, DS.ARGS({ "desc : str" }))
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinition::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinition>(src);
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
        .def("findSubDefinition", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::findSubDefinition, DS.ARGS({ "defid : int" }))
        .def("addSubDefinition", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::addSubDefinition, DS.ARGS({ "val : PyBrxCv.CvDbTinSurfaceDefinition" }))
        .def("getSubDefinitionAt", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::getSubDefinitionAt, DS.ARGS({ "index : int" }))
        .def("removeSubDefinitionAt", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::removeSubDefinitionAt, DS.ARGS({ "index : int" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionGroupDefs::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionGroupDefs>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionTransform::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionTransform>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddPoint::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddPoint>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddPoints::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddPoints>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionDeletePoint>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionDeletePoints>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionSwapEdge>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionMovePoint::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionMovePoint>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionMovePoints::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionMovePoints>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeleteEdge::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionDeleteEdge>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionDeleteEdges::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionDeleteEdges>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddLine::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddLine>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddLines::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddLines>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointElevation::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionModifyPointElevation>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations>(src);
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
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionCreateFromFaces>(src);
}

BrxCvDbTinSurfaceDefinitionCreateFromFaces* PyBrxCvDbTinSurfaceDefinitionCreateFromFaces::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionCreateFromFaces*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects
void makePyBrxCvDbTinSurfaceDefinitionAddDrawingObjectsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddDrawingObjects");
    class_<PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddDrawingObjects")
        .def(init<>())
        .def(init<const boost::python::list&, double, bool, BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation>())
        .def("addEntity", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::addEntity, DS.ARGS({ "entity: PyDb.Entity" }))
        .def("addEntityId", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::addEntityId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("drawingObjectsCount", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::drawingObjectsCount, DS.ARGS())
        .def("drawingObjectAt", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::drawingObjectAt, DS.ARGS({ "idx : int" }))
        .def("crossingsElevation", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::crossingsElevation, DS.ARGS())
        .def("setCrossingsElevation", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::setCrossingsElevation, DS.ARGS({ "val : PyBrxCv.TinIntersectionElevation" }))
        .def("isApplyEdges", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::isApplyEdges, DS.ARGS())
        .def("setIsApplyEdges", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::setIsApplyEdges, DS.ARGS({ "val : bool" }))
        .def("removeDrawingObjectAt", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::removeDrawingObjectAt, DS.ARGS({ "idx : int" }))
        .def("removeAllDrawingObjects", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::removeAllDrawingObjects, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects()
    :PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(new BrxCvDbTinSurfaceDefinitionAddDrawingObjects(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(const boost::python::list& ents, double midOrdinateDistance, bool applyEdges, ETinIntersectionElevation crossingsElevation)
    :PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(new BrxCvDbTinSurfaceDefinitionAddDrawingObjects(PyListToPyDbEntityPtrArray(ents), midOrdinateDistance, applyEdges, crossingsElevation), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(BrxCvDbTinSurfaceDefinitionAddDrawingObjects* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::addEntity(const PyDbEntity& pEntity)
{
    return impObj()->addEntity(pEntity.impObj());
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::addEntityId(const PyDbObjectId& entityId)
{
    return impObj()->addEntity(entityId.m_id);
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::drawingObjectsCount() const
{
    return impObj()->drawingObjectsCount();
}

boost::python::tuple PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::drawingObjectAt(const Adesk::UInt32 index) const
{
    PyAutoLockGIL lock;
    EDrawingObjectType type;
    AcGePoint3dArray points;
    bool flag = impObj()->drawingObjectAt(index, type, points);
    return boost::python::make_tuple(flag, type, Point3dArrayToPyList(points));
}

PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::crossingsElevation() const
{
    return impObj()->crossingsElevation();
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::setCrossingsElevation(const ETinIntersectionElevation crossingsElevation)
{
    return impObj()->setCrossingsElevation(crossingsElevation);
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::isApplyEdges() const
{
    return impObj()->isApplyEdges();
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::setIsApplyEdges(bool isApplyEdges)
{
    return impObj()->setIsApplyEdges(isApplyEdges);
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::removeDrawingObjectAt(const Adesk::UInt32 index)
{
    return impObj()->removeDrawingObjectAt(index);
}

bool PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::removeAllDrawingObjects()
{
    return impObj()->removeAllDrawingObjects();
}

std::string PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddDrawingObjects";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddDrawingObjects::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects>(src);
}

BrxCvDbTinSurfaceDefinitionAddDrawingObjects* PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddDrawingObjects*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRiseLower
void makePyBrxCvDbTinSurfaceDefinitionRiseLowerWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionRiseLower");
    class_<PyBrxCvDbTinSurfaceDefinitionRiseLower, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionRiseLower")
        .def(init<>())
        .def(init<double>())
        .def("offset", &PyBrxCvDbTinSurfaceDefinitionRiseLower::offset, DS.ARGS())
        .def("setOffset", &PyBrxCvDbTinSurfaceDefinitionRiseLower::setOffset, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionRiseLower::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionRiseLower::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionRiseLower::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionRiseLower::PyBrxCvDbTinSurfaceDefinitionRiseLower()
    :PyBrxCvDbTinSurfaceDefinitionRiseLower(new BrxCvDbTinSurfaceDefinitionRiseLower(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRiseLower::PyBrxCvDbTinSurfaceDefinitionRiseLower(double mtx)
    :PyBrxCvDbTinSurfaceDefinitionRiseLower(new BrxCvDbTinSurfaceDefinitionRiseLower(mtx), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRiseLower::PyBrxCvDbTinSurfaceDefinitionRiseLower(BrxCvDbTinSurfaceDefinitionRiseLower* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

double PyBrxCvDbTinSurfaceDefinitionRiseLower::offset() const
{
    return impObj()->offset();
}

bool PyBrxCvDbTinSurfaceDefinitionRiseLower::setOffset(double offset)
{
    return impObj()->setOffset(offset);
}

std::string PyBrxCvDbTinSurfaceDefinitionRiseLower::className()
{
    return "BrxCvDbTinSurfaceDefinitionRiseLower";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionRiseLower::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionRiseLower::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionRiseLower PyBrxCvDbTinSurfaceDefinitionRiseLower::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionRiseLower>(src);
}

BrxCvDbTinSurfaceDefinitionRiseLower* PyBrxCvDbTinSurfaceDefinitionRiseLower::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionRiseLower*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML
void makePyBrxCvDbTinSurfaceDefinitionCreateFromLandXMLWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionCreateFromLandXML");
    class_<PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionCreateFromLandXML")
        .def(init<>())
        .def(init<const std::string&, const std::string&, AcDb::UnitsValue, bool>())
        .def("filePath", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::filePath, DS.ARGS())
        .def("setFilePath", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setFilePath, DS.ARGS({ "val : str" }))
        .def("surfaceName", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::surfaceName, DS.ARGS())
        .def("setSurfaceName", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setSurfaceName, DS.ARGS({ "val : str" }))
        .def("scaleToDwgUnits", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::scaleToDwgUnits, DS.ARGS())
        .def("setScaleToDwgUnits", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setScaleToDwgUnits, DS.ARGS({ "val : bool" }))
        .def("dwgUnits", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::dwgUnits, DS.ARGS())
        .def("dwgUnits", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::dwgUnits, DS.ARGS({ "units : PyDb.UnitsValue" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML()
    :PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(new BrxCvDbTinSurfaceDefinitionCreateFromLandXML(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(const std::string& path, const std::string& name, AcDb::UnitsValue dwgUnits, bool scaleToDwgUnits)
    :PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(new BrxCvDbTinSurfaceDefinitionCreateFromLandXML(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str(), dwgUnits, scaleToDwgUnits), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(BrxCvDbTinSurfaceDefinitionCreateFromLandXML* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::filePath() const
{
    return wstr_to_utf8(impObj()->filePath());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setFilePath(const std::string& filePath)
{
    return impObj()->setFilePath(utf8_to_wstr(filePath).c_str());
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::surfaceName() const
{
    return wstr_to_utf8(impObj()->surfaceName());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setSurfaceName(const std::string& surfaceName)
{
    return impObj()->setSurfaceName(utf8_to_wstr(surfaceName).c_str());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::scaleToDwgUnits() const
{
    return impObj()->scaleToDwgUnits();
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setScaleToDwgUnits(bool scaleToDwgUnits)
{
    return impObj()->setScaleToDwgUnits(scaleToDwgUnits);
}

AcDb::UnitsValue PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::dwgUnits() const
{
    return impObj()->dwgUnits();
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::setDwgUnits(const AcDb::UnitsValue dwgUnits)
{
    return impObj()->setDwgUnits(dwgUnits);
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::className()
{
    return "BrxCvDbTinSurfaceDefinitionCreateFromLandXML";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionCreateFromLandXML::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML>(src);
}

BrxCvDbTinSurfaceDefinitionCreateFromLandXML* PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionCreateFromLandXML*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddFromFiles
void makePyBrxCvDbTinSurfaceDefinitionAddFromFilesWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddFromFiles");
    class_<PyBrxCvDbTinSurfaceDefinitionAddFromFiles, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddFromFiles")
        .def(init<>())
        .def(init<const boost::python::list&, const PyDbObjectId&>())
        .def("filesPaths", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::filesPaths, DS.ARGS())
        .def("setFilesPaths", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::setFilesPaths, DS.ARGS({ "val : list[str]" }))
        .def("fileFormatId", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::fileFormatId, DS.ARGS())
        .def("setFileFormatId", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::setFileFormatId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddFromFiles::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddFromFiles::PyBrxCvDbTinSurfaceDefinitionAddFromFiles()
    :PyBrxCvDbTinSurfaceDefinitionAddFromFiles(new BrxCvDbTinSurfaceDefinitionAddFromFiles(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddFromFiles::PyBrxCvDbTinSurfaceDefinitionAddFromFiles(const boost::python::list& paths, const PyDbObjectId& fileFormatId)
    :PyBrxCvDbTinSurfaceDefinitionAddFromFiles(new BrxCvDbTinSurfaceDefinitionAddFromFiles(PyListToAcStringArray(paths), fileFormatId.m_id), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddFromFiles::PyBrxCvDbTinSurfaceDefinitionAddFromFiles(BrxCvDbTinSurfaceDefinitionAddFromFiles* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionAddFromFiles::filesPaths() const
{
    return AcStringArrayToPyList(impObj()->filesPaths());
}

bool PyBrxCvDbTinSurfaceDefinitionAddFromFiles::setFilesPaths(const boost::python::list& filesPaths)
{
    return impObj()->setFilesPaths(PyListToAcStringArray(filesPaths));
}

PyDbObjectId PyBrxCvDbTinSurfaceDefinitionAddFromFiles::fileFormatId() const
{
    return PyDbObjectId(impObj()->fileFormatId());
}

bool PyBrxCvDbTinSurfaceDefinitionAddFromFiles::setFileFormatId(const PyDbObjectId& fileFormatId)
{
    return impObj()->setFileFormatId(fileFormatId.m_id);
}

std::string PyBrxCvDbTinSurfaceDefinitionAddFromFiles::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddFromFiles";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddFromFiles::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddFromFiles::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddFromFiles PyBrxCvDbTinSurfaceDefinitionAddFromFiles::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddFromFiles>(src);
}

BrxCvDbTinSurfaceDefinitionAddFromFiles* PyBrxCvDbTinSurfaceDefinitionAddFromFiles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddFromFiles*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds
void makePyBrxCvDbTinSurfaceDefinitionAddFromPointCloudsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddFromPointClouds");
    class_<PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddFromPointClouds")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def("pcObjectIds", &PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::pcObjectIds, DS.ARGS())
        .def("setPcObjectIds", &PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::setPcObjectIds, DS.ARGS({ "val : list[PyDb.ObjectId]" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds()
    :PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(new BrxCvDbTinSurfaceDefinitionAddFromPointClouds(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(const boost::python::list& ids)
    :PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(new BrxCvDbTinSurfaceDefinitionAddFromPointClouds(PyListToObjectIdArray(ids)), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(BrxCvDbTinSurfaceDefinitionAddFromPointClouds* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::pcObjectIds() const
{
    return ObjectIdArrayToPyList(impObj()->pcObjectIds());
}

bool PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::setPcObjectIds(const boost::python::list& pcObjectIds)
{
    return impObj()->setPcObjectIds(PyListToObjectIdArray(pcObjectIds));
}

std::string PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddFromPointClouds";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddFromPointClouds::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds>(src);
}

BrxCvDbTinSurfaceDefinitionAddFromPointClouds* PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddFromPointClouds*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPointGroups
void makePyBrxCvDbTinSurfaceDefinitionAddPointGroupsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionAddPointGroups");
    class_<PyBrxCvDbTinSurfaceDefinitionAddPointGroups, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionAddPointGroups")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def("pointGroupsIds", &PyBrxCvDbTinSurfaceDefinitionAddPointGroups::pointGroupsIds, DS.ARGS())
        .def("setPointGroupsIds", &PyBrxCvDbTinSurfaceDefinitionAddPointGroups::setPointGroupsIds, DS.ARGS({ "val : list[PyDb.ObjectId]" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionAddPointGroups::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionAddPointGroups::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionAddPointGroups::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionAddPointGroups::PyBrxCvDbTinSurfaceDefinitionAddPointGroups()
    :PyBrxCvDbTinSurfaceDefinitionAddPointGroups(new BrxCvDbTinSurfaceDefinitionAddPointGroups(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPointGroups::PyBrxCvDbTinSurfaceDefinitionAddPointGroups(const boost::python::list& ids)
    :PyBrxCvDbTinSurfaceDefinitionAddPointGroups(new BrxCvDbTinSurfaceDefinitionAddPointGroups(PyListToObjectIdArray(ids)), true)
{
}

PyBrxCvDbTinSurfaceDefinitionAddPointGroups::PyBrxCvDbTinSurfaceDefinitionAddPointGroups(BrxCvDbTinSurfaceDefinitionAddPointGroups* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionAddPointGroups::pointGroupsIds() const
{
    return ObjectIdArrayToPyList(impObj()->pointGroupsIds());
}

bool PyBrxCvDbTinSurfaceDefinitionAddPointGroups::setPointGroupsIds(const boost::python::list& pointGroupsIds)
{
    return impObj()->setPointGroupsIds(PyListToObjectIdArray(pointGroupsIds));
}

std::string PyBrxCvDbTinSurfaceDefinitionAddPointGroups::className()
{
    return "BrxCvDbTinSurfaceDefinitionAddPointGroups";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionAddPointGroups::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionAddPointGroups::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionAddPointGroups PyBrxCvDbTinSurfaceDefinitionAddPointGroups::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionAddPointGroups>(src);
}

BrxCvDbTinSurfaceDefinitionAddPointGroups* PyBrxCvDbTinSurfaceDefinitionAddPointGroups::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionAddPointGroups*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromC3D
void makePyBrxCvDbTinSurfaceDefinitionCreateFromC3DWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionCreateFromC3D");
    class_<PyBrxCvDbTinSurfaceDefinitionCreateFromC3D, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionCreateFromC3D")
        .def(init<>())
        .def(init<const std::string&, const std::string&>())
        .def("filePath", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::filePath, DS.ARGS())
        .def("setFilePath", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::setFilePath, DS.ARGS({ "val : str" }))
        .def("surfaceName", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::surfaceName, DS.ARGS())
        .def("setSurfaceName", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::setSurfaceName, DS.ARGS({ "val : str" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::PyBrxCvDbTinSurfaceDefinitionCreateFromC3D()
    :PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(new BrxCvDbTinSurfaceDefinitionCreateFromC3D(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(const std::string& path, const std::string& name)
    :PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(new BrxCvDbTinSurfaceDefinitionCreateFromC3D(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str()), true)
{
}

PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(BrxCvDbTinSurfaceDefinitionCreateFromC3D* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::filePath() const
{
    return wstr_to_utf8(impObj()->filePath());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::setFilePath(const std::string& filePath)
{
    return impObj()->setFilePath(utf8_to_wstr(filePath).c_str());
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::surfaceName() const
{
    return wstr_to_utf8(impObj()->surfaceName());
}

bool PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::setSurfaceName(const std::string& surfaceName)
{
    return impObj()->setSurfaceName(utf8_to_wstr(surfaceName).c_str());
}

std::string PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::className()
{
    return "BrxCvDbTinSurfaceDefinitionCreateFromC3D";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionCreateFromC3D::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionCreateFromC3D PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionCreateFromC3D>(src);
}

BrxCvDbTinSurfaceDefinitionCreateFromC3D* PyBrxCvDbTinSurfaceDefinitionCreateFromC3D::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionCreateFromC3D*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges
void makePyBrxCvDbTinSurfaceDefinitionRemoveOuterEdgesWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionRemoveOuterEdges");
    class_<PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionRemoveOuterEdges")
        .def(init<>())
        .def(init<bool, double, bool, double, bool, double>())
        .def("useMaxEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMaxEdgeLength, DS.ARGS())
        .def("setUseMaxEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMaxEdgeLength, DS.ARGS({ "val : bool" }))
        .def("maxEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::maxEdgeLength, DS.ARGS())
        .def("setMaxEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMaxEdgeLength, DS.ARGS({ "val : float" }))
        .def("useMinEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMinEdgeLength, DS.ARGS())
        .def("setUseMinEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMinEdgeLength, DS.ARGS({ "val : bool" }))
        .def("minEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::minEdgeLength, DS.ARGS())
        .def("setMinEdgeLength", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMinEdgeLength, DS.ARGS({ "val : float" }))
        .def("useMaxAdjAngle", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMaxAdjAngle, DS.ARGS())
        .def("setUseMaxAdjAngle", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMaxAdjAngle, DS.ARGS({ "val : bool" }))
        .def("maxAdjAngle", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::maxAdjAngle, DS.ARGS())
        .def("setMaxAdjAngle", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMaxAdjAngle, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges()
    :PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(new BrxCvDbTinSurfaceDefinitionRemoveOuterEdges(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(bool useMinLength, double minLength, bool useMaxLength, double maxLength, bool useMaxAdjAngle, double maxAdjAngle)
    :PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(new BrxCvDbTinSurfaceDefinitionRemoveOuterEdges(useMinLength, minLength, useMaxLength, maxLength, useMaxAdjAngle, maxAdjAngle), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(BrxCvDbTinSurfaceDefinitionRemoveOuterEdges* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMaxEdgeLength() const
{
    return impObj()->useMaxEdgeLength();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMaxEdgeLength(bool useMaxEdgeLength)
{
    return impObj()->setUseMaxEdgeLength(useMaxEdgeLength);
}

double PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::maxEdgeLength() const
{
    return impObj()->maxEdgeLength();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMaxEdgeLength(double maxEdgeLength)
{
    return impObj()->setMaxEdgeLength(maxEdgeLength);
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMinEdgeLength() const
{
    return impObj()->useMinEdgeLength();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMinEdgeLength(bool useMinEdgeLength)
{
    return impObj()->setUseMinEdgeLength(useMinEdgeLength);
}

double PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::minEdgeLength() const
{
    return impObj()->minEdgeLength();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMinEdgeLength(double minEdgeLength)
{
    return impObj()->setMinEdgeLength(minEdgeLength);
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::useMaxAdjAngle() const
{
    return impObj()->useMaxAdjAngle();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setUseMaxAdjAngle(bool useMaxAdjAngle)
{
    return impObj()->setUseMaxAdjAngle(useMaxAdjAngle);
}

double PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::maxAdjAngle() const
{
    return impObj()->maxAdjAngle();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::setMaxAdjAngle(double maxAdjAngle)
{
    return impObj()->setMaxAdjAngle(maxAdjAngle);
}

std::string PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::className()
{
    return "BrxCvDbTinSurfaceDefinitionRemoveOuterEdges";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionRemoveOuterEdges::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges>(src);
}

BrxCvDbTinSurfaceDefinitionRemoveOuterEdges* PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionRemoveOuterEdges*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility
void makePyBrxCvDbTinSurfaceDefinitionTrianglesVisibilityWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionTrianglesVisibility");
    class_<PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionTrianglesVisibility")
        .def(init<>())
        .def(init<const boost::python::list&, bool>())
        .def("positions", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::positions, DS.ARGS())
        .def("setPositions", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::setPositions, DS.ARGS({ "val : list[PyGe.Point2d]" }))
        .def("visible", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::visible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::setVisible, DS.ARGS({ "val : bool" }))
        .def("className", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility()
    :PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(new BrxCvDbTinSurfaceDefinitionTrianglesVisibility(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(const boost::python::list& positions, bool visible)
    :PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(new BrxCvDbTinSurfaceDefinitionTrianglesVisibility(PyListToPoint2dArray(positions), visible), true)
{
}

PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(BrxCvDbTinSurfaceDefinitionTrianglesVisibility* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::positions() const
{
    return Point2dArrayToPyList(impObj()->positions());
}

bool PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::setPositions(const boost::python::list& positions)
{
    return impObj()->setPositions(PyListToPoint2dArray(positions));
}

bool PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::visible() const
{
    return impObj()->visible();
}

bool PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::setVisible(bool visible)
{
    return impObj()->setVisible(visible);
}

std::string PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::className()
{
    return "BrxCvDbTinSurfaceDefinitionTrianglesVisibility";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionTrianglesVisibility::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility>(src);
}

BrxCvDbTinSurfaceDefinitionTrianglesVisibility* PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionTrianglesVisibility*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRemoveElevations
void makePyBrxCvDbTinSurfaceDefinitionRemoveElevationsWrapper()
{
    PyDocString DS("CvDbTinSurfaceDefinitionRemoveElevations");
    class_<PyBrxCvDbTinSurfaceDefinitionRemoveElevations, bases<PyBrxCvDbTinSurfaceDefinition>>("CvDbTinSurfaceDefinitionRemoveElevations")
        .def(init<>())
        .def(init<bool, double, bool, double>())
        .def("removeBelow", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeBelow, DS.ARGS())
        .def("setRemoveBelow", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveBelow, DS.ARGS({ "val : bool" }))
        .def("removeBelowElevation", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeBelowElevation, DS.ARGS())
        .def("setRemoveBelowElevation", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveBelowElevation, DS.ARGS({ "val : float" }))
        .def("removeAbove", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeAbove, DS.ARGS())
        .def("setRemoveAbove", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveAbove, DS.ARGS({ "val : bool" }))
        .def("removeAboveElevation", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeAboveElevation, DS.ARGS())
        .def("setRemoveAboveElevation", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveAboveElevation, DS.ARGS({ "val : float" }))
        .def("removedPointsCount", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removedPointsCount, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinitionRemoveElevations::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinitionRemoveElevations::PyBrxCvDbTinSurfaceDefinitionRemoveElevations()
    :PyBrxCvDbTinSurfaceDefinitionRemoveElevations(new BrxCvDbTinSurfaceDefinitionRemoveElevations(), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRemoveElevations::PyBrxCvDbTinSurfaceDefinitionRemoveElevations(bool removeBelow, double removeBelowElevation, bool removeAbove, double removeAboveElevation)
    :PyBrxCvDbTinSurfaceDefinitionRemoveElevations(new BrxCvDbTinSurfaceDefinitionRemoveElevations(removeBelow, removeBelowElevation, removeAbove, removeAboveElevation), true)
{
}

PyBrxCvDbTinSurfaceDefinitionRemoveElevations::PyBrxCvDbTinSurfaceDefinitionRemoveElevations(BrxCvDbTinSurfaceDefinitionRemoveElevations* ptr, bool autoDelete)
    :PyBrxCvDbTinSurfaceDefinition(ptr, autoDelete)
{
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeBelow() const
{
    return impObj()->removeBelow();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveBelow(bool removeBelow)
{
    return impObj()->setRemoveBelow(removeBelow);
}

double PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeBelowElevation() const
{
    return impObj()->removeBelowElevation();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveBelowElevation(double removeBelowElevation)
{
    return impObj()->setRemoveBelowElevation(removeBelowElevation);
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeAbove() const
{
    return impObj()->removeAbove();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveAbove(bool removeAbove)
{
    return impObj()->setRemoveAbove(removeAbove);
}

double PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removeAboveElevation() const
{
    return impObj()->removeAboveElevation();
}

bool PyBrxCvDbTinSurfaceDefinitionRemoveElevations::setRemoveAboveElevation(double removeAboveElevation)
{
    return impObj()->setRemoveAboveElevation(removeAboveElevation);
}

Adesk::UInt32 PyBrxCvDbTinSurfaceDefinitionRemoveElevations::removedPointsCount() const
{
    return impObj()->removedPointsCount();
}

std::string PyBrxCvDbTinSurfaceDefinitionRemoveElevations::className()
{
    return "BrxCvDbTinSurfaceDefinitionRemoveElevations";
}

PyRxClass PyBrxCvDbTinSurfaceDefinitionRemoveElevations::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinitionRemoveElevations::desc(), false);
}

PyBrxCvDbTinSurfaceDefinitionRemoveElevations PyBrxCvDbTinSurfaceDefinitionRemoveElevations::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbTinSurfaceDefinitionRemoveElevations>(src);
}

BrxCvDbTinSurfaceDefinitionRemoveElevations* PyBrxCvDbTinSurfaceDefinitionRemoveElevations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinitionRemoveElevations*>(m_pyImp.get());
}
#endif //BRXAPP
