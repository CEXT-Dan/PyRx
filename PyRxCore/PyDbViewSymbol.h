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

    AcDbDetailSymbol::BoundaryType  boundaryType() const;
    AcDbDetailViewStyle::ModelEdge	modelEdgeType() const;
    bool							isOverriddenProperty(AcDbDetailSymbol::OverriddenProperty property) const;
    bool							displayIdentifier() const;
    AcGePoint3d						origin() const;
    AcGeVector3d                    direction() const;
    AcGeVector2d                    boundarySize() const;
    AcGePoint3d                     modelEdgeOrigin() const;
    double							owningViewScale() const;
    double							detailViewScale() const;
    AcGeVector3d                    modelEdgeDirection() const;
    AcGePoint3d				        identifierPosition() const;

    void				            setBoundaryType(AcDbDetailSymbol::BoundaryType bndType) const;
    void				            setModelEdgeType(AcDbDetailViewStyle::ModelEdge modelEdgeType) const;
    void				            setPickPoints(const boost::python::list& pickPoints) const;
    void				            setModelEdgeOrigin(const AcGePoint3d& pt) const;
    void				            setOwningViewScale(double viewScale) const;
    void				            setDetailViewScale(double viewScale) const;
    void				            setModelEdgeDirection(const AcGeVector3d& dir) const;
    void				            setIdentifierPosition(const AcGePoint3d& pt) const;
    void				            initializeIdentifierPositionAt(const AcGePoint3d& pt) const;
    void				            resetIdentifierPosition() const;
    void				            setDisplayIdentifier(const bool displayIdentifier) const;
    void				            setOrigin(const AcGePoint3d& pt) const;
    void				            setBoundarySize(const AcGeVector2d& size) const;
    AcDbExtents		                modelEdgeBorderExtents() const;

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