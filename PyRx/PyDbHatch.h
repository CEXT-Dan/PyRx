#pragma once
#include "PyDbEntity.h"
#include "PyDb3dSolid.h"

class PyDbObjectId;

void makePyDbHatchWrapper();
class PyDbHatch : public PyDbEntity
{
public:
    PyDbHatch();
    PyDbHatch(AcDbHatch* ptr, bool autoDelete);
    PyDbHatch(const PyDbObjectId& id);
    PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbHatch() override = default;
    double				elevation() const;
    void	            setElevation(double elevation);
    AcGeVector3d		normal() const;
    void	            setNormal(const AcGeVector3d& normal);
    AcCmColor			backgroundColor() const;
    void	            setBackgroundColor(const AcCmColor& color);
    int					numLoops() const;
    boost::python::tuple getLoopEdgesAt(int loopIndex);
    boost::python::tuple getLoopBulgesAt(int loopIndex);
    void                appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes);
    void                appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges);
    void	            removeLoopAt(int loopIndex);
    bool				associative() const;
    void	            setAssociative(bool isAssociative);
    void	            appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds);
    void	            insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds);
    boost::python::list	getAssocObjIdsAt(int loopIndex) const;
    boost::python::list	getAssocObjIds() const;
    void                removeAssocObjIds();
    AcDbHatch::HatchObjectType hatchObjectType() const;
    void	            setHatchObjectType(AcDbHatch::HatchObjectType type);
    Adesk::Boolean		isGradient() const;
    Adesk::Boolean		isHatch() const;
    AcDbHatch::GradientPatternType gradientType() const;
    std::string			gradientName() const;
    void                setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName);
    double				gradientAngle() const;
    void	            setGradientAngle(double angle);
    boost::python::tuple getGradientColors();
    void	            setGradientColors(const boost::python::list& colors, const boost::python::list& values);
    Adesk::Boolean		getGradientOneColorMode() const;
    void	            setGradientOneColorMode(Adesk::Boolean oneColorMode);
    float				getShadeTintValue() const;
    void	            setShadeTintValue(float value);
    void	            setShadeTintValueAndColor2(float value);
    float				gradientShift() const;
    void	            setGradientShift(float shiftValue);
    AcCmColor			evaluateGradientColorAt(float value);
    AcDbHatch::HatchPatternType patternType() const;
    std::string			patternName() const;
    void	            setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName);
    double				patternAngle() const;
    void	            setPatternAngle(double angle);
    double				patternSpace() const;
    void	            setPatternSpace(double space);
    double				patternScale() const;
    void	            setPatternScale(double scale);
    bool				patternDouble() const;
    void	            setPatternDouble(bool isDouble);
    int					numPatternDefinitions() const;
    boost::python::tuple getPatternDefinitionAt(int index);
    AcDbHatch::HatchStyle hatchStyle() const;
    void	            setHatchStyle(AcDbHatch::HatchStyle hstyle);
    void                evaluateHatch1();
    void                evaluateHatch2(bool bUnderestimateNumLines);
    void                evaluateHatchAllScales1();
    void                evaluateHatchAllScales2(bool bUnderestimateNumLines);
    bool                lineGenerationEnabled() const;
    bool                setLineGenerationEnabled(bool bEnable);
    int				    numHatchLines() const;
    bool			    isSolidFill() const;
    boost::python::tuple getHatchLineDataAt(int index) const;
    boost::python::tuple getHatchLinesData() const;
    double			    getArea() const;
    void  setOriginPoint(const AcGePoint2d& pt);
    AcGePoint2d         originPoint() const;
    PyDbRegion          getRegionArea() const;
    void                removeHatchLines();
    static std::string  className();
    static PyRxClass    desc();
    static PyDbHatch    cloneFrom(const PyRxObject& src);
    static PyDbHatch    cast(const PyRxObject& src);
public:
    AcDbHatch* impObj(const std::source_location& src = std::source_location::current()) const;
};

