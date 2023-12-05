#pragma once
#include "PyDbObject.h"


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
    inline virtual ~PyDbSpatialFilter() override = default;


    PyRxClass                   indexClass() const;
    AcDbExtents                 queryBounds1() const;
    AcDbExtents                 queryBounds2(const PyDbBlockReference& pRefBlkRef) const;

    boost::python::tuple        getVolume() const;
    void                        setDefinition(const boost::python::list& pts,
        const AcGeVector3d& normal,
        double                  elevation,
        double                  frontClip,
        double                  backClip,
        Adesk::Boolean          enabled);

    boost::python::tuple        getDefinition();

    AcGeMatrix3d                getClipSpaceToWCSMatrix() const;
    AcGeMatrix3d                getOriginalInverseBlockXform() const;
    void                        setPerspectiveCamera(const AcGePoint3d& fromPt);
    Adesk::Boolean              clipVolumeIntersectsExtents(const AcDbExtents& ext) const;
    Adesk::Boolean              hasPerspectiveCamera() const;
    bool                        isInverted() const;
    void                        setInverted(bool bInverted);

    static PyRxClass            desc();
    static std::string          className();
    static PyDbSpatialFilter    cloneFrom(const PyRxObject& src);
    static PyDbSpatialFilter    cast(const PyRxObject& src);
public:
    inline AcDbSpatialFilter* impObj(const std::source_location& src = std::source_location::current()) const;
};

