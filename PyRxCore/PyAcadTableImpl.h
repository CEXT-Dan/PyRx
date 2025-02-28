#pragma once
#include "PyAcadEntityImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
class PyIAcadTableImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTableImpl(IAcadTable* ptr);
    virtual ~PyIAcadTableImpl() override = default;
    IAcadTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTablePtr = std::unique_ptr<PyIAcadTableImpl>;
