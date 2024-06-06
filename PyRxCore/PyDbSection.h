#pragma once
#include "PyDbEntity.h"
#include "DbSection.h"
#include "DbSectionManager.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyDbSectionManager
void makePyDbSectionManagerWrapper();
class PyDbSectionManager : public PyDbObject
{
public:
    PyDbSectionManager(const PyDbObjectId&);
    PyDbSectionManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSectionManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSectionManager(AcDbSectionManager* ptr, bool autoDelete);
    inline virtual ~PyDbSectionManager() override = default;

    PyDbObjectId        getSection(const std::string& name);
    PyDbObjectId        getLiveSection() const;
    int                 numSections(void) const;
    std::string         getUniqueSectionName(const std::string& pszBaseName) const;
    boost::python::list objectIds() const;


    static PyRxClass    desc();
    static std::string  className();
    static PyDbSectionManager   cloneFrom(const PyRxObject& src);
    static PyDbSectionManager   cast(const PyRxObject& src);
public:
    inline AcDbSectionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbSectionSettings
void makePyDbSectionSettingsWrapper();
class PyDbSectionSettings : public PyDbObject
{
public:
    PyDbSectionSettings();
    PyDbSectionSettings(AcDbSectionSettings* ptr, bool autoDelete);
    PyDbSectionSettings(const PyDbObjectId&);
    PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    inline virtual ~PyDbSectionSettings() override = default;

    void                reset1(void);
    void                reset2(AcDbSectionSettings::SectionType nSecType);
    AcDbSectionSettings::SectionType currentSectionType(void) const;
    void                setCurrentSectionType(AcDbSectionSettings::SectionType nSecType);
    AcDbSectionSettings::Generation generationOptions(AcDbSectionSettings::SectionType nSecType) const;
    void                setGenerationOptions(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Generation nOptions);
    boost::python::list getSourceObjects(AcDbSectionSettings::SectionType nSecType) const;
    void                setSourceObjects(AcDbSectionSettings::SectionType nSecType, const boost::python::list& ids);
    PyDbObjectId        destinationBlock(AcDbSectionSettings::SectionType nSecType) const;
    void                setDestinationBlock(AcDbSectionSettings::SectionType nSecType, const PyDbObjectId& id);
    std::string         destinationFile(AcDbSectionSettings::SectionType nSecType) const; 
    void                setDestinationFile(AcDbSectionSettings::SectionType nSecType, const std::string& pszFileName);
    bool                visibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setVisibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bVisible);
    AcCmColor           color(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setColor(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const AcCmColor& color);
    std::string         layer(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setLayer(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const std::string& pszLayer);
    std::string         linetype(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setLinetype(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const std::string& pszLinetype);
    double              linetypeScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setLinetypeScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fScale);
    std::string         plotStyleName(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setPlotStyleName(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry,const std::string& pszPlotStyleName);
    AcDb::LineWeight    lineWeight(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setLineWeight(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, AcDb::LineWeight nLineWeight);
    int                 faceTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setFaceTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, int nTransparency);
    int                 edgeTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setEdgeTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, int nTransparency);
    bool                hatchVisibility(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry) const;
    void                setHatchVisibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bVisible);
    boost::python::tuple getHatchPattern(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry) const;
    void                setHatchPattern(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry,AcDbHatch::HatchPatternType nPatternType,const std::string& pszPatternName);
    double              hatchAngle(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry) const;
    void                setHatchAngle(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry,double fAngle);
    double              hatchSpacing(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setHatchSpacing(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fSpacing);
    double              hatchScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setHatchScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fScale);
    bool                hiddenLine(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setHiddenLine(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bHiddenLine);
    bool                divisionLines(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const;
    void                setDivisionLines(AcDbSectionSettings::SectionType nSecType,AcDbSectionSettings::Geometry nGeometry,bool bShow);

    static PyRxClass    desc();
    static std::string  className();
    static PyDbSectionSettings   cloneFrom(const PyRxObject& src);
    static PyDbSectionSettings   cast(const PyRxObject& src);
public:
    inline AcDbSectionSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};

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
