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
    PyDocString DS("Xrecord");
    class_<PyDbXrecord, bases<PyDbObject>>("Xrecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode,bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("rbChain", &PyDbXrecord::rbChain1)
        .def("rbChain", &PyDbXrecord::rbChain2, DS.ARGS({ "auxDb : PyDb.Database = None " }))
        .def("setFromRbChain", &PyDbXrecord::setFromRbChain1)
        .def("setFromRbChain", &PyDbXrecord::setFromRbChain2, DS.ARGS({"resbuf : list", "auxDb : PyDb.Database = None " }))
        .def("isXlateReferences", &PyDbXrecord::isXlateReferences, DS.ARGS())
        .def("setXlateReferences", &PyDbXrecord::setXlateReferences, DS.ARGS({ "val : bool" }))
        .def("mergeStyle", &PyDbXrecord::mergeStyle, DS.ARGS())
        .def("setMergeStyle", &PyDbXrecord::setMergeStyle, DS.ARGS({ "style: PyDb.DuplicateRecordCloning" }))
        .def("className", &PyDbXrecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbXrecord::desc, DS.SARGS()).staticmethod("desc")
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

void PyDbXrecord::setFromRbChain1(const boost::python::list& pRb)
{
    AcResBufPtr ptr(listToResbuf(pRb));
    if (ptr == nullptr)
        PyThrowBadEs(eInvalidInput);
    return PyThrowBadEs(impObj()->setFromRbChain(*ptr.get()));
}

void PyDbXrecord::setFromRbChain2(const boost::python::list& pRb, PyDbDatabase& auxDb)
{
    AcResBufPtr ptr(listToResbuf(pRb));
    if (ptr == nullptr)
        PyThrowBadEs(eInvalidInput);
    PyThrowBadEs(impObj()->setFromRbChain(*ptr.get(), auxDb.impObj()));
}

bool PyDbXrecord::isXlateReferences() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isXlateReferences();
#endif
}

void PyDbXrecord::setXlateReferences(bool translate)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->setXlateReferences(translate);
#endif
}

AcDb::DuplicateRecordCloning PyDbXrecord::mergeStyle() const
{
    return impObj()->mergeStyle();
}

void PyDbXrecord::setMergeStyle(AcDb::DuplicateRecordCloning style)
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
    if (!src.impObj()->isKindOf(AcDbXrecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbXrecord(static_cast<AcDbXrecord*>(src.impObj()->clone()), true);
}

PyDbXrecord PyDbXrecord::cast(const PyRxObject& src)
{
    PyDbXrecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbXrecord* PyDbXrecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbXrecord*>(m_pyImp.get());
}
