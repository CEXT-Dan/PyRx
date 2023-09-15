#include "stdafx.h"
#include "PyDbIdMapping.h"

using namespace boost::python;

void makePyDbIdMappingWrapper()
{
    class_<PyDbIdMapping>("IdMapping")
        .def(init<>())
        ;
}

PyDbIdMapping::PyDbIdMapping()
    : m_pyImp(new AcDbIdMapping())
{
}

PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping)
    : m_pyImp(new AcDbIdMapping())
{
    PyThrowBadEs(m_pyImp->copyFrom(&mapping));
}

AcDbIdMapping* PyDbIdMapping::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbIdMapping*>(m_pyImp.get());
}
