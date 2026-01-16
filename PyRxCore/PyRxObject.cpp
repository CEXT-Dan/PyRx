#include "stdafx.h"
#include "PyRxObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxObject wrapper
void makePyRxObjectWrapper()
{
    PyDocString DS("PyRx.RxObject");
    class_<PyRxObject>("RxObject", boost::python::no_init)
        .def("isA", &PyRxObject::isA, DS.ARGS(15561))
        .def("isKindOf", &PyRxObject::isKindOf, DS.ARGS({ "rhs: PyRx.RxClass" }, 15563))
        .def("isDerivedFrom", &PyRxObject::isDerivedFrom, DS.ARGS({ "other : PyRx.RxClass" }, 15281))
        .def("isNullObj", &PyRxObject::isNullObj, DS.ARGS())
        .def("implRefCount", &PyRxObject::implRefCount, DS.ARGS())
        .def("keepAlive", &PyRxObject::forceKeepAlive, DS.ARGS({ "flag: bool" }))
        .def("dispose", &PyRxObject::dispose, DS.ARGS())
        .def("intPtr", &PyRxObject::intPtr, DS.ARGS())
        .def("queryX", &PyRxObject::queryX, DS.ARGS({ "protocolClass: PyRx.RxClass" }, 15564))
        .def("copyFrom", &PyRxObject::copyFrom, DS.ARGS({ "other: PyRx.RxObject" }, 15559))
        .def("comparedTo", &PyRxObject::comparedTo, DS.ARGS({ "other: PyRx.RxObject" }, 15558))
        .def("__eq__", &PyRxObject::operator==, DS.ARGS({ "rhs: PyRx.RxObject" }))
        .def("__ne__", &PyRxObject::operator!=, DS.ARGS({ "rhs: PyRx.RxObject" }))
        .def("__hash__", &PyRxObject::hash)
        .def("desc", &PyRxObject::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyRxObject::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
    {
        if (m_isDbObject)
        {
            AcDbObject* pDbo = static_cast<AcDbObject*>(p);
            if (!pDbo->objectId().isNull())
            {
                if (const auto es = pDbo->close(); es != eOk) [[unlikely]]
                    acutPrintf(_T("\nStatus = %ls in %ls: "), acadErrorStatusText(es), __FUNCTIONW__);
                return true;
            }
        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (p == nullptr)
            return;
        if (m_forceKeepAlive)
            return;
        else if (isDbroThenClose(p))
            return;
        else if (!m_autoDelete)
            return;
        else
            delete p;
    }

    bool m_autoDelete = true;
    bool m_isDbObject = false;
    bool m_forceKeepAlive = false;
};

PyRxObject::PyRxObject(const AcRxObject* ptr)
    : m_pyImp(const_cast<AcRxObject*>(ptr), PyRxObjectDeleter(false, false))
{
}

PyRxObject::PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbOject)
    : m_pyImp(ptr, PyRxObjectDeleter(autoDelete, isDbOject))
{
}

bool PyRxObject::operator==(const PyRxObject& rhs) const
{
    if (isNullObj())
        return rhs.isNullObj();
    else if (rhs.isNullObj())
        return false;
    return (m_pyImp->isEqualTo(rhs.m_pyImp.get()));
}

bool PyRxObject::operator!=(const PyRxObject& rhs) const
{
    if (isNullObj())
        return !rhs.isNullObj();
    else if (rhs.isNullObj())
        return true;
    return !(m_pyImp->isEqualTo(rhs.m_pyImp.get()));
}

PyRxClass PyRxObject::isA() const
{
    return PyRxClass(m_pyImp->isA(), false);
}

bool PyRxObject::isDerivedFrom(const PyRxClass& other) const
{
    return impObj()->isA()->isDerivedFrom(other.impObj());
}

bool PyRxObject::isKindOf(const PyRxClass& aClass) const
{
    return impObj()->isKindOf(aClass.impObj());
}

void PyRxObject::forceKeepAlive(bool flag) const
{
    auto del_p = std::get_deleter<PyRxObjectDeleter>(m_pyImp);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_forceKeepAlive = flag;
}

void PyRxObject::dispose()
{
    m_pyImp.reset();
}

bool PyRxObject::isNullObj() const
{
    return m_pyImp == nullptr;
}

int PyRxObject::implRefCount() const
{
    return m_pyImp.use_count();
}

INT_PTR PyRxObject::intPtr()
{
    return (INT_PTR)m_pyImp.get();
}

void PyRxObject::copyFrom(PyRxObject& obj) const
{
    PyThrowBadEs(impObj()->copyFrom(obj.impObj()));
}

PyRxObject PyRxObject::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyErrorStatusException(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

AcRx::Ordering PyRxObject::comparedTo(const PyRxObject& other) const
{
    return impObj()->comparedTo(other.impObj());
}

std::size_t PyRxObject::hash() const
{
    return std::hash<AcRxObject*>{}(m_pyImp.get());
}

PyRxClass PyRxObject::desc()
{
    return PyRxClass(AcRxObject::desc(), false);
}

std::string PyRxObject::className()
{
    return "AcRxObject";
}

AcRxObject* PyRxObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyRxClass Wrapper
void makePyRxClassWrapper()
{
    PyDocString DS("PyRx.RxClass");
    class_<PyRxClass, bases<PyRxObject>>("RxClass", boost::python::no_init)
        .def("isDerivedFrom", &PyRxClass::isDerivedFrom, DS.ARGS({ "other : PyRx.RxClass" }, 15281))
        .def("appName", &PyRxClass::appName, DS.ARGS(15269))
        .def("dxfName", &PyRxClass::dxfName, DS.ARGS(15278))
        .def("name", &PyRxClass::name, DS.ARGS(15284))
        .def("myParent", &PyRxClass::myParent, DS.ARGS(15283))
        .def("queryX", &PyRxObject::queryX, DS.ARGS({ "protocolClass :  PyRx.RxClass" }, 15288))
        .def("desc", &PyRxClass::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyRxClass::className, DS.SARGS()).staticmethod("className")
        ;
}

PyRxClass::PyRxClass(AcRxClass* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

bool PyRxClass::isDerivedFrom(const PyRxClass& other) const
{
    return impObj()->isDerivedFrom(other.impObj());
}

std::string PyRxClass::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyRxClass::appName() const
{
    return wstr_to_utf8(impObj()->appName());
}

std::string PyRxClass::dxfName() const
{
    return wstr_to_utf8(impObj()->dxfName());
}

PyRxObject PyRxClass::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyErrorStatusException(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

PyRxClass PyRxClass::myParent() const
{
    return PyRxClass(impObj()->myParent(), false);
}

PyRxClass PyRxClass::desc()
{
    return PyRxClass(AcRxClass::desc(), false);
}

std::string PyRxClass::className()
{
    return std::string{ "AcRxClass" };
}

AcRxClass* PyRxClass::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcRxClass*>(m_pyImp.get());
}
