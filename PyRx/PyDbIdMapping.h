#pragma once

void makePyDbIdMappingWrapper();

class PyDbIdMapping
{
public:
    PyDbIdMapping();
    PyDbIdMapping(const AcDbIdMapping& mapping);

public:
    std::shared_ptr<AcDbIdMapping> m_imp;
};

