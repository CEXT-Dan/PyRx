#include "stdafx.h"
#include "PyDbPointRef.h"


void makePyDbPointRefWrapper()
{

}

PyDbPointRef::PyDbPointRef(const AcDbPointRef* ptr)
    : PyDbPointRef(const_cast<AcDbPointRef*>(ptr), false)
{
}

PyDbPointRef::PyDbPointRef(AcDbPointRef* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

PyRxClass PyDbPointRef::desc()
{
    return PyRxClass(AcDbPointRef::desc(), false);
}

std::string PyDbPointRef::className()
{
    return std::string{ "AcDbPointRef" };
}

AcDbPointRef* PyDbPointRef::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPointRef*>(m_pyImp.get());
}
