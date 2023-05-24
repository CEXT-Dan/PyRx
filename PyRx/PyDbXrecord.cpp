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
	class_<PyDbXrecord, bases<PyDbObject>>("Xrecord")
		.def(init<>())
		.def(init<const PyDbObjectId&, AcDb::OpenMode>())
		.def("rbChain", &PyDbXrecord::rbChain1)
		.def("rbChain", &PyDbXrecord::rbChain2)
		.def("setFromRbChain", &PyDbXrecord::setFromRbChain1)
		.def("setFromRbChain", &PyDbXrecord::setFromRbChain2)
		.def("isXlateReferences", &PyDbXrecord::isXlateReferences)
		.def("setXlateReferences", &PyDbXrecord::setXlateReferences)
		.def("mergeStyle", &PyDbXrecord::mergeStyle)
		.def("setMergeStyle", &PyDbXrecord::setMergeStyle)
		.def("className", &PyDbXrecord::className).staticmethod("className")
		.def("desc", &PyDbXrecord::desc).staticmethod("desc")
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

PyDbXrecord::PyDbXrecord(const PyDbObjectId& id, AcDb::OpenMode mode)
	: PyDbObject(nullptr, false)
{
	AcDbXrecord* pobj = nullptr;
	if (auto es = acdbOpenObject<AcDbXrecord>(pobj, id.m_id, mode); es != eOk)
		throw PyAcadErrorStatus(es);
	this->resetImp(pobj, false, true);
}

boost::python::list PyDbXrecord::rbChain1() const
{
	PyAutoLockGIL lock;
	resbuf* pRb = nullptr;
	if (auto es = impObj()->rbChain(&pRb); es != eOk)
		throw PyAcadErrorStatus(es);
	AcResBufPtr rb(pRb);
	return resbufToList(pRb);
}

boost::python::list PyDbXrecord::rbChain2(PyDbDatabase& auxDb) const
{
	PyAutoLockGIL lock;
	resbuf* pRb = nullptr;
	if (auto es = impObj()->rbChain(&pRb, auxDb.impObj()); es != eOk)
		throw PyAcadErrorStatus(es);
	AcResBufPtr rb(pRb);
	return resbufToList(pRb);
}

Acad::ErrorStatus PyDbXrecord::setFromRbChain1(const boost::python::list& pRb)
{
	AcResBufPtr ptr(listToResbuf(pRb));
	if (ptr == nullptr)
		return eInvalidInput;
	return impObj()->setFromRbChain(*ptr.get());
}

Acad::ErrorStatus PyDbXrecord::setFromRbChain2(const boost::python::list& pRb, PyDbDatabase& auxDb)
{
	AcResBufPtr ptr(listToResbuf(pRb));
	if (ptr == nullptr)
		return eInvalidInput;
	return impObj()->setFromRbChain(*ptr.get(), auxDb.impObj());
}

bool PyDbXrecord::isXlateReferences() const
{
#ifdef BRXAPP
	throw PyNotimplementedByHost();
#else
	return impObj()->isXlateReferences();
#endif
}

void PyDbXrecord::setXlateReferences(bool translate)
{
#ifdef BRXAPP
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

AcDbXrecord* PyDbXrecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcDbXrecord*>(m_pyImp.get());
}
