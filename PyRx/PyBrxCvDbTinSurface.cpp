#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"

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
    :PyBrxCvDbTinSurfaceDefinitionTransform(new BrxCvDbTinSurfaceDefinitionTransform(mtx),true)
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
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionAddPoint::position, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionAddPoint::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
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
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionAddPoints::positions, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionAddPoints::setPositions, DS.ARGS({ "pt : PyGe.Point3d" }))
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
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::position, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionDeletePoint::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
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
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::positions, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionDeletePoints::setPositions, DS.ARGS({ "pt : PyGe.Point3d" }))
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
        .def("transformationMatrix", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::position, DS.ARGS())
        .def("setTransformationMatrix", &PyBrxCvDbTinSurfaceDefinitionSwapEdge::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
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
#endif //BRXAPP
