#pragma once
#include "PyDbEntity.h"

#if defined(_ARXTARGET)
#include "dbViewSymbol.h"
#include "dbDetailSymbol.h"
#include "dbSectionSymbol.h"
#endif

#pragma pack (push, 8)

class PyDbObjectId;

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol
void makePyDbViewSymbolWrapper();

class PyDbViewSymbol : public PyDbEntity
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
public:
    PyDbViewSymbol(AcDbViewSymbol* ptr, bool autoDelete);
    PyDbViewSymbol(const PyDbObjectId& id);
    PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbViewSymbol() override = default;

    PyDbObjectId        symbolStyleId() const;
    void                setSymbolStyleId(const PyDbObjectId& styleId) const;
    double              scale() const;
    void                setScale(double val) const;
    std::string         getIdentifier() const;
    void                setIdentifier(const std::string& sName) const;

    PyDbObjectId        owningViewRep() const;
    void                setOwningViewRep(const PyDbObjectId& owner) const;

    boost::python::list exportSymbolGeometry(const PyDbObjectId& viewRepId) const;
    void                setSymbolGeometry(const boost::python::list& entIds) const;
    void                setSymbolGeometryEntities(const boost::python::list& pyentities) const;
    void			    updateDefinition() const;


    static PyRxClass    desc();
    static std::string  className();
    static PyDbViewSymbol   cloneFrom(const PyRxObject& src);
    static PyDbViewSymbol   cast(const PyRxObject& src);
public:
    AcDbViewSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol
void makePyDbDetailSymbolWrapper();

class PyDbDetailSymbol : public PyDbViewSymbol
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
public:
    PyDbDetailSymbol();
    PyDbDetailSymbol(AcDbDetailSymbol* ptr, bool autoDelete);
    PyDbDetailSymbol(const PyDbObjectId& id);
    PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbDetailSymbol() override = default;

    static PyRxClass    desc();
    static std::string  className();
    static PyDbDetailSymbol   cloneFrom(const PyRxObject& src);
    static PyDbDetailSymbol   cast(const PyRxObject& src);
public:
    AcDbDetailSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol
void makePyDbSectionSymbolWrapper();

class PyDbSectionSymbol : public PyDbViewSymbol
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
public:
    PyDbSectionSymbol();
    PyDbSectionSymbol(AcDbSectionSymbol* ptr, bool autoDelete);
    PyDbSectionSymbol(const PyDbObjectId& id);
    PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbSectionSymbol() override = default;


    static PyRxClass    desc();
    static std::string  className();
    static PyDbSectionSymbol   cloneFrom(const PyRxObject& src);
    static PyDbSectionSymbol   cast(const PyRxObject& src);
public:
    AcDbSectionSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

#pragma pack (pop)