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

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionGroupDefs
void makePyBrxCvDbTinSurfaceDefinitionGroupDefsWrapper();

class PyBrxCvDbTinSurfaceDefinitionGroupDefs : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionGroupDefs();
    PyBrxCvDbTinSurfaceDefinitionGroupDefs(BrxCvDbTinSurfaceDefinitionGroupDefs* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionGroupDefs() override = default;

    Adesk::UInt32           numSubDefinitions() const;
    Adesk::UInt32           findSubDefinition(const Adesk::UInt64 definitionId) const;
    Adesk::UInt32           addSubDefinition(const PyBrxCvDbTinSurfaceDefinition& subDefinition);
    PyBrxCvDbTinSurfaceDefinition getSubDefinitionAt(const Adesk::UInt32 index) const;
    bool                    removeSubDefinitionAt(const Adesk::UInt32 index);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionGroupDefs cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionGroupDefs* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionTransform
void makePyBrxCvDbTinSurfaceDefinitionTransformWrapper();

class PyBrxCvDbTinSurfaceDefinitionTransform : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionTransform();
    PyBrxCvDbTinSurfaceDefinitionTransform(const AcGeMatrix3d& mtx);
    PyBrxCvDbTinSurfaceDefinitionTransform(BrxCvDbTinSurfaceDefinitionTransform* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionTransform() override = default;

    AcGeMatrix3d            transformationMatrix() const;
    bool                    setTransformationMatrix(const AcGeMatrix3d& mtx);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionTransform cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionTransform* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif //BRXAPP
