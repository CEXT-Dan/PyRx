#pragma once

#include "PyBrxCvObject.h"
#include "BrxCvDbTinSurfaceDefinition.h"

#ifdef BRXAPP

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinition
void makePyBrxCvDbTinSurfaceDefinitionWrapper();

class PyBrxCvDbTinSurfaceDefinition : public PyBrxCvDbSubObject
{
    using EType = BrxCvDbTinSurfaceDefinition::EType;
public:
    PyBrxCvDbTinSurfaceDefinition(BrxCvDbTinSurfaceDefinition* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinition() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);
    EType                   type() const;
    bool                    isUpdateNeeded() const;
    bool                    isSubDefinition() const;
    bool                    isValid() const;
    bool                    isEnabled() const;
    bool                    setEnabled(const bool enabled);
    bool                    isReadOnly() const;
    bool                    setReadOnly(const bool readOnly);
    Adesk::UInt64           id() const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinition cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif //BRXAPP
