#pragma once
#include "PyDbObject.h"
#pragma pack (push, 8)

class PyDbObjectId;
class PyDbBlockReference;
//----------------------------------------------------------------------------------------
//PyDbSpatialFilter
void makePyDbSpatialFilterWrapper();

class PyDbSpatialFilter : public PyDbObject
{
public:
    PyDbSpatialFilter();
    PyDbSpatialFilter(const PyDbObjectId&);
    PyDbSpatialFilter(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSpatialFilter(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

#ifdef NEVER
    PyDbSpatialFilter(const boost::python::list& pts,
        const AcGeVector3d& normal,
        double                  elevation,
        double                  frontClip,
        double                  backClip,
        Adesk::Boolean          enabled);
#endif

    PyDbSpatialFilter(AcDbSpatialFilter* ptr, bool autoDelete);
    virtual ~PyDbSpatialFilter() override = default;


    PyRxClass                   indexClass() const;
    AcDbExtents                 queryBounds1() const;
    AcDbExtents                 queryBounds2(const PyDbBlockReference& pRefBlkRef) const;

    boost::python::tuple        getVolume() const;
    void                        setDefinition(const boost::python::list& pts,
        const AcGeVector3d& normal,
        double                  elevation,
        double                  frontClip,
        double                  backClip,
        Adesk::Boolean          enabled) const;

    boost::python::tuple        getDefinition() const;

    AcGeMatrix3d                getClipSpaceToWCSMatrix() const;
    AcGeMatrix3d                getOriginalInverseBlockXform() const;
    void                        setPerspectiveCamera(const AcGePoint3d& fromPt) const;
    Adesk::Boolean              clipVolumeIntersectsExtents(const AcDbExtents& ext) const;
    Adesk::Boolean              hasPerspectiveCamera() const;
    bool                        isInverted() const;
    void                        setInverted(bool bInverted) const;

    static PyRxClass            desc();
    static std::string          className();
    static PyDbSpatialFilter    cloneFrom(const PyRxObject& src);
    static PyDbSpatialFilter    cast(const PyRxObject& src);
public:
    AcDbSpatialFilter* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyDbLayerFilter
void makePyDbLayerFilterWrapper();

class PyDbLayerFilter : public PyDbObject
{
public:
    PyDbLayerFilter();
    PyDbLayerFilter(const PyDbObjectId&);
    PyDbLayerFilter(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLayerFilter(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbLayerFilter(AcDbLayerFilter* ptr, bool autoDelete);
    virtual ~PyDbLayerFilter() override = default;
    PyRxClass                 indexClass() const;
    Adesk::Boolean            isValid() const;
    void                      add(const std::string& pLayer) const;
    void                      remove(const std::string& pLayer) const;
    std::string               getAt(int index) const;
    int                       layerCount() const;
    static PyRxClass          desc();
    static std::string        className();
    static PyDbLayerFilter    cloneFrom(const PyRxObject& src);
    static PyDbLayerFilter    cast(const PyRxObject& src);
public:
    AcDbLayerFilter* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
