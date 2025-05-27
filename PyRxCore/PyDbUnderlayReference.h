#pragma once
#include "PyDbEntity.h"
#include "dbunderlayref.h"
#include "dbunderlaydef.h"
#include "dbunderlayhost.h"

#pragma pack (push, 8)
class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyUnderlayLayer
void makePyUnderlayLayerWrapper();
class PyUnderlayLayer
{
public:
    PyUnderlayLayer();
    PyUnderlayLayer(const AcUnderlayLayer& layer);
    ~PyUnderlayLayer() = default;
    std::string name() const;
    bool state() const;
    void setName(const std::string& name);
    void setState(bool state);
public:
    AcUnderlayLayer imp;
};

//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper();

class PyDbUnderlayDefinition : public PyDbObject
{
public:
    PyDbUnderlayDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete);
    PyDbUnderlayDefinition(const PyDbObjectId& id);
    PyDbUnderlayDefinition(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbUnderlayDefinition() override = default;

    void                setSourceFileName(const std::string& file) const;
    const std::string   getSourceFileName() const;
    std::string         getActiveFileName() const;
    void                setItemName(const std::string& item) const;
    std::string         getItemName() const;
#ifdef NEVER //TODO
    void                setUnderlayItem(const ACHAR* sourceFileName, const ACHAR* activeFileName, AcDbUnderlayItem* pItem) const;
    const AcDbUnderlayItem* getUnderlayItem() const;
#endif // NEVER //TODO
    void                load1() const;
    void                load2(const std::string& password) const;
    void                unload() const;
    bool                isLoaded() const;
    static std::string  dictionaryKey(const PyRxClass& underlayDefinitionType);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUnderlayDefinition   cloneFrom(const PyRxObject& src);
    static PyDbUnderlayDefinition   cast(const PyRxObject& src);
public:
    AcDbUnderlayDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbUnderlayReference
void makePyDbUnderlayReferenceWrapper();

class PyDbUnderlayReference : public PyDbEntity
{
public:
    PyDbUnderlayReference(AcDbUnderlayReference* ptr, bool autoDelete);
    PyDbUnderlayReference(const PyDbObjectId& id);
    PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbUnderlayReference() override = default;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& position) const;
    AcGeScale3d         scaleFactors() const;
    void                setScaleFactors(const AcGeScale3d& scale) const;
    double              rotation() const;
    void                setRotation(double rotation) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& normal) const;
    AcGeMatrix3d        transform() const;
    void                setTransform(const AcGeMatrix3d& transform) const;
    PyDbObjectId        definitionId() const;
    void                setDefinitionId(const PyDbObjectId& id) const;
    void                setWidth(double width) const;
    double              width() const;
    void                setHeight(double width) const;
    double              height() const;
    boost::python::list clipBoundary() const;
    void                setClipBoundary(const boost::python::list& clip) const;
    bool                isClipped() const;
    void                setIsClipped(bool value) const;
    Adesk::UInt8        contrast() const;
    void                setContrast(Adesk::UInt8 value) const;
    Adesk::UInt8        fade() const;
    void                setFade(Adesk::UInt8 value) const;
    bool                isOn() const;
    void                setIsOn(bool value) const;
    bool                isMonochrome() const;
    void                setIsMonochrome(bool value) const;
    bool                isAdjustedForBackground() const;
    void                setIsAdjustedForBackground(bool value) const;
    bool                isFrameVisible() const;
    bool                isFramePlottable() const;
    Adesk::UInt32       underlayLayerCount() const;
    PyUnderlayLayer     getUnderlayLayer(int index) const;
    void                setUnderlayLayer(int index, const PyUnderlayLayer& layer) const;
    bool                isClipInverted() const;
    void                setClipInverted(bool value) const;
    void                generateClipBoundaryFromPline(PyDbObjectId& polyId) const;

public:
    static Adesk::UInt8 contrastLowerLimit();
    static Adesk::UInt8 contrastDefault();
    static Adesk::UInt8 fadeLowerLimit();
    static Adesk::UInt8 fadeUpperLimit();
    static Adesk::UInt8 fadeDefault();
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUnderlayReference	 cloneFrom(const PyRxObject& src);
    static PyDbUnderlayReference     cast(const PyRxObject& src);
public:
    AcDbUnderlayReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbPdfDefinition
void makePyDbPdfDefinitionWrapper();

class PyDbPdfDefinition : public PyDbUnderlayDefinition
{
public:
    PyDbPdfDefinition();
    PyDbPdfDefinition(AcDbPdfDefinition* ptr, bool autoDelete);
    PyDbPdfDefinition(const PyDbObjectId& id);
    PyDbPdfDefinition(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPdfDefinition() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPdfDefinition   cloneFrom(const PyRxObject& src);
    static PyDbPdfDefinition   cast(const PyRxObject& src);
public:
    AcDbPdfDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbPdfReference
void makePyDbPdfReferenceWrapper();

class PyDbPdfReference : public PyDbUnderlayReference
{
public:
    PyDbPdfReference();
    PyDbPdfReference(AcDbPdfReference* ptr, bool autoDelete);
    PyDbPdfReference(const PyDbObjectId& id);
    PyDbPdfReference(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPdfReference() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPdfReference	 cloneFrom(const PyRxObject& src);
    static PyDbPdfReference     cast(const PyRxObject& src);
public:
    AcDbPdfReference* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
