#include "stdafx.h"
#include "PyDbIdMapping.h"

using namespace boost::python;

void makePyDbIdMappingWrapper()
{
    class_<PyDbIdMapping, boost::noncopyable>("IdMapping")
        .def(init<>())
        ;
}

PyDbIdMapping::PyDbIdMapping()
    : m_imp(new AcDbIdMapping())
{
}

PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping)
    : m_imp(new AcDbIdMapping())
{
    if (auto es = m_imp->copyFrom(&mapping); es != eOk)
        throw PyAcadErrorStatus(es);
}
