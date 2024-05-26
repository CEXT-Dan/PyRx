#pragma once
#include "PyDbEntity.h"
#include "DbSection.h"

class PyDbObjectId;

// AcDbSectionManager
// AcDbSectionSettings

//-----------------------------------------------------------------------------------
//PyDbSection
void makePyDbSectionWrapper();
class PyDbSection : public PyDbEntity
{
public:
    PyDbSection();
    PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir);
    PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir, const AcGeVector3d& vecViewingDir);
    PyDbSection(const PyDbObjectId& id);
    PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSection(AcDbSection* ptr, bool autoDelete);
    virtual ~PyDbSection() override = default;

    AcDbSection::State  state(void) const;
    void                setState(AcDbSection::State nState);
    std::string         getName();
    void                setName(const std::string& name);
    AcGeVector3d        viewingDirection(void) const;
    void                setViewingDirection(const AcGeVector3d& dir);
    AcGeVector3d        verticalDirection(void) const;
    void                setVerticalDirection(const AcGeVector3d& dir);
    AcGeVector3d        normal(void) const;
    boost::python::tuple plane() const;
    int                 indicatorTransparency(void) const;
    void                setIndicatorTransparency(int nTransparency);
    AcCmColor           indicatorFillColor(void) const;
    void                setIndicatorFillColor(const AcCmColor& color);
    int                 numVertices(void) const;
    AcGePoint3d         getVertex(int nIndex);
    void                setVertex(int nIndex, const AcGePoint3d& pt);
    void                addVertex(int nInsertAt, const AcGePoint3d& pt);
    void                removeVertex(int nInsertAt);
    boost::python::list getVertices() const;
    void                setVertices(const boost::python::list& pts);
    double              height(AcDbSection::Height nHeightType) const;
    void                setHeight(AcDbSection::Height nHeightType,double fHeight);
    boost::python::tuple hitTest(const AcGePoint3d& ptHit);
    void                createJog(const AcGePoint3d& ptOnSection);
    PyDbObjectId        getSettings(void) const;
    bool                isLiveSectionEnabled(void) const;
    void                enableLiveSection(bool bEnable);
    boost::python::tuple generateSectionGeometry(const PyDbEntity& pEnt);
    double              elevation() const;
    void                setElevation(double elev);
    double              topPlane() const;
    void                setTopPlane(double val);
    double              bottomPlane() const;
    void                setBottomPlane(double);
    bool                isSlice() const;
    void                setIsSlice(bool value);
    double              thicknessDepth() const;
    void                setThicknessDepth(double fThickness);
    bool                hasJogs() const;
    double              sectionPlaneOffset() const;
    void                setSectionPlaneOffset(double offset);

    static std::string  className();
    static PyRxClass    desc();
    static PyDbSection	cloneFrom(const PyRxObject& src);
    static PyDbSection  cast(const PyRxObject& src);
public:
    inline AcDbSection* impObj(const std::source_location& src = std::source_location::current()) const;
};
