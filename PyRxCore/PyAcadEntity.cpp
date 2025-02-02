#include "stdafx.h"
#include "PyAcadEntity.h"
#include "PyAcadEntityImpl.h"

using namespace boost::python;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper()
{
    PyDocString DS("AcadEntity");
    class_<PyAcadEntity, bases<PyAcadObject>>("AcadEntity", boost::python::no_init)
        .def("transformBy", &PyAcadEntity::transformBy, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("className", &PyAcadEntity::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyAcadEntity::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        ;
}

PyAcadEntity::PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr)
    :PyAcadObject(ptr)
{
}

void PyAcadEntity::transformBy(const AcGeMatrix3d& xform)
{
    impObj()->TransformBy(xform);
}

PyAcadEntity PyAcadEntity::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadEntity>(src);
}

std::string PyAcadEntity::className()
{
    return "AcDbEntity";
}

PyIAcadEntityImpl* PyAcadEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadEntityImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper()
{
    PyDocString DS("AcadBlock");
    class_<PyAcadBlock, bases<PyAcadObject>>("AcadBlock", boost::python::no_init)
        .def("count", &PyAcadBlock::count, DS.ARGS())
        .def("item", &PyAcadBlock::item, DS.SARGS({ "index: int" }))
        .def("entities", &PyAcadBlock::entities, DS.ARGS())
        .def("__getitem__", &PyAcadBlock::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadBlock::begin, &PyAcadBlock::end))
        .def("cast", &PyAcadBlock::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlock::PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadBlock::count() const
{
    return impObj()->GetCount();
}

PyAcadEntity PyAcadBlock::item(long ind) const
{
    if (ind >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadEntity{ impObj()->GetItem(ind) };
}

boost::python::list PyAcadBlock::entities()
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

PyAcadBlock PyAcadBlock::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadBlock>(src);
}

std::string PyAcadBlock::className()
{
    return "AcadBlock";
}

PyIAcadBlockImpl* PyAcadBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadBlockImpl*>(m_pyImp.get());
}

void PyAcadBlock::filliterator()
{
    for (const auto& item : impObj()->GetIter())
        m_iterable.push_back(PyAcadEntity{ item });
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyModelSpace
void makePyModelSpaceWrapper()
{
    PyDocString DS("ModelSpace");
    class_<PyAcadModelSpace, bases<PyAcadBlock>>("ModelSpace", boost::python::no_init)
        .def("cast", &PyAcadModelSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadModelSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadModelSpace::PyAcadModelSpace(std::shared_ptr<PyIAcadModelSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadModelSpace PyAcadModelSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadModelSpace>(src);
}

std::string PyAcadModelSpace::className()
{
    return "AcadModelSpace";
}

PyIAcadModelSpaceImpl* PyAcadModelSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadModelSpaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyPaperSpace
void makePyPaperSpaceWrapper()
{
    PyDocString DS("PaperSpace");
    class_<PyAcadPaperSpace, bases<PyAcadBlock>>("PaperSpace", boost::python::no_init)
        .def("cast", &PyAcadPaperSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPaperSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPaperSpace::PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadPaperSpace PyAcadPaperSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPaperSpace>(src);
}

std::string PyAcadPaperSpace::className()
{
    return "AcadPaperSpace";
}

PyIAcadPaperSpaceImpl* PyAcadPaperSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPaperSpaceImpl*>(m_pyImp.get());
}