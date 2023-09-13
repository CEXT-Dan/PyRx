#pragma once

void makePyDbIdMappingWrapper();

class PyDbIdMapping
{
public:
    PyDbIdMapping();
    PyDbIdMapping(const AcDbIdMapping& mapping);

    AcDbIdMapping* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbIdMapping> m_pyImp;
};

