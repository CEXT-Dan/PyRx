#include "stdafx.h"
#include "PyDbXrecord.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "PyDbDatabase.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//makePyDbXrecordWrapper
void makePyDbXrecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("Xrecord");
    class_<PyDbXrecord, bases<PyDbObject>>("Xrecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 10347)))
        .def("rbChain", &PyDbXrecord::rbChain1)
        .def("rbChain", &PyDbXrecord::rbChain2, DS.ARGS({ "auxDb : PyDb.Database = ... " }, 10367))
        .def("setFromRbChain", &PyDbXrecord::setFromRbChain1)
        .def("setFromRbChain", &PyDbXrecord::setFromRbChain2, DS.ARGS({ "resbuf : list", "auxDb : PyDb.Database = ... " }, 10368))
        .def("isXlateReferences", &PyDbXrecord::isXlateReferences, DS.ARGS(10365))
        .def("setXlateReferences", &PyDbXrecord::setXlateReferences, DS.ARGS({ "val : bool" }, 10370))
        .def("mergeStyle", &PyDbXrecord::mergeStyle, DS.ARGS(10366))
        .def("setMergeStyle", &PyDbXrecord::setMergeStyle, DS.ARGS({ "style: PyDb.DuplicateRecordCloning" }, 10369))
        .def("className", &PyDbXrecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbXrecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbXrecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbXrecord::PyDbXrecord()
    : PyDbObject(new AcDbXrecord(), true)
{
}

PyDbXrecord::PyDbXrecord(AcDbObject* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbXrecord::PyDbXrecord(const PyDbObjectId& id)
    : PyDbXrecord(id, AcDb::OpenMode::kForRead)
{
}

PyDbXrecord::PyDbXrecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbXrecord>(id, mode), false)
{
}

PyDbXrecord::PyDbXrecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbXrecord>(id, mode, erased), false)
{
}

boost::python::list PyDbXrecord::rbChain1() const
{
    PyAutoLockGIL lock;
    resbuf* pRb = nullptr;
    PyThrowBadEs(impObj()->rbChain(&pRb));
    AcResBufPtr rb(pRb);
    return resbufToList(pRb);
}

boost::python::list PyDbXrecord::rbChain2(PyDbDatabase& auxDb) const
{
    PyAutoLockGIL lock;
    resbuf* pRb = nullptr;
    PyThrowBadEs(impObj()->rbChain(&pRb, auxDb.impObj()));
    AcResBufPtr rb(pRb);
    return resbufToList(pRb);
}

void PyDbXrecord::setFromRbChain1(const boost::python::list& pRb) const
{
    AcResBufPtr ptr(listToResbuf(pRb));
    if (ptr == nullptr)
        PyThrowBadEs(eInvalidInput);
    return PyThrowBadEs(impObj()->setFromRbChain(*ptr.get()));
}

void PyDbXrecord::setFromRbChain2(const boost::python::list& pRb, PyDbDatabase& auxDb) const
{
    AcResBufPtr ptr(listToResbuf(pRb));
    if (ptr == nullptr)
        PyThrowBadEs(eInvalidInput);
    PyThrowBadEs(impObj()->setFromRbChain(*ptr.get(), auxDb.impObj()));
}

bool PyDbXrecord::isXlateReferences() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isXlateReferences();
#endif
}

void PyDbXrecord::setXlateReferences(bool translate) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setXlateReferences(translate);
#endif
}

AcDb::DuplicateRecordCloning PyDbXrecord::mergeStyle() const
{
    return impObj()->mergeStyle();
}

void PyDbXrecord::setMergeStyle(AcDb::DuplicateRecordCloning style) const
{
    impObj()->setMergeStyle(style);
}

std::string PyDbXrecord::className()
{
    return "AcDbXrecord";
}

PyRxClass PyDbXrecord::desc()
{
    return PyRxClass(AcDbXrecord::desc(), false);
}

PyDbXrecord PyDbXrecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbXrecord, AcDbXrecord>(src);
}

PyDbXrecord PyDbXrecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbXrecord>(src);
}

AcDbXrecord* PyDbXrecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbXrecord*>(m_pyImp.get());
}
