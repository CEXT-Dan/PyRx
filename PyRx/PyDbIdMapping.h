#pragma once

void makePyDbIdMappingWrapper();

class PyDbIdMapping
{
public:
    PyDbIdMapping();
    PyDbIdMapping(const AcDbIdMapping& mapping);

public:
    std::unique_ptr<AcDbIdMapping> m_imp;
};

