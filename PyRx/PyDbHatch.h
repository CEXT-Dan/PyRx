#pragma once
#include "PyDbEntity.h"
#include "PyDb3dSolid.h"
#include "dbMPolygon.h"

#pragma pack (push, 8)

class PyDbObjectId;
class PyDbCircle;
class PyDbPolyline;
class PyDb2dPolyline;

//-----------------------------------------------------------------------------------------
//PyDbHatch

void makePyDbHatchWrapper();
class PyDbHatch : public PyDbEntity
{
public:
    PyDbHatch();
    PyDbHatch(AcDbHatch* ptr, bool autoDelete);
    PyDbHatch(const PyDbObjectId& id);
    PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
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

//-----------------------------------------------------------------------------------------
//PyDbMPolygon
void makePyDbMPolygonWrapper();
class PyDbMPolygon : public PyDbEntity
{
public:
    PyDbMPolygon();
    PyDbMPolygon(AcDbMPolygon* ptr, bool autoDelete);
    PyDbMPolygon(const PyDbObjectId& id);
    PyDbMPolygon(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMPolygon(const PyDbObjectId& id, AcDb::OpenMode mode,bool erased);
    virtual ~PyDbMPolygon() override = default;

    PyDbHatch               hatch();
    double				    elevation() const;
    void	                setElevation(double elevation);
    AcGeVector3d		    normal() const;
    void	                setNormal(const AcGeVector3d& normal);
    void                    evaluateHatch1();
    void                    evaluateHatch2(bool bUnderestimateNumLines);
    AcDbHatch::HatchPatternType patternType() const;
    std::string             patternName() const;
    void                    setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName);
    double                  patternAngle() const;
    void                    setPatternAngle(double angle);
    double                  patternSpace() const;
    void                    setPatternSpace(double space);
    double                  patternScale() const;
    void                    setPatternScale(double scale);
    bool                    patternDouble() const;
    void                    setPatternDouble(bool isDouble);
    int                     numPatternDefinitions() const;
    boost::python::tuple    getPatternDefinitionAt(int index) const;
    void                    setGradientAngle(double angle);
    void                    setGradientShift(float shiftValue);
    void                    setGradientOneColorMode(Adesk::Boolean oneColorMode);
    void	                setGradientColors(const boost::python::list& colors, const boost::python::list& values);
    void                    setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName);
    AcCmColor               patternColor() const;
    void                    setPatternColor(const AcCmColor& pc);
    double                  getArea() const;
    double                  getPerimeter() const;
    bool                    isBalanced() const;
    AcGeVector2d            getOffsetVector() const;
    //Acad::ErrorStatus     getMPolygonTree(AcDbMPolygonNode*& loopNode) const;
    //void                  deleteMPolygonTree(AcDbMPolygonNode* loopNode) const;
    void                    appendLoopFromBoundary1(const PyDbCircle& pCircle,bool excludeCrossing, double tol);
    void                    appendLoopFromBoundary2(const PyDbPolyline& pPoly, bool excludeCrossing, double tol);
    void                    appendLoopFromBoundary3(const PyDb2dPolyline& pPoly, bool excludeCrossing, double tol);
    int                     numMPolygonLoops() const;
    boost::python::tuple    getMPolygonLoopAt(int loopIndex) const;
    void                    insertMPolygonLoopAt(int loopIndex, const boost::python::list& vertices, const boost::python::list& bulges,bool excludeCrossing, double tol);
    void                    appendMPolygonLoop(const boost::python::list& vertices, const boost::python::list& bulges, bool excludeCrossing, double tol);
    void                    removeMPolygonLoopAt(int loopIndex);
    void                    balanceTree();
    void                    balanceDisplay();
    AcDbMPolygon::loopDir   getLoopDirection(int lindex) const;
    void                    setLoopDirection(int lindex, AcDbMPolygon::loopDir dir);
    int                     getLoopAtGsMarker(int gsMark) const;
    boost::python::list     getChildLoops(int curLoop) const;
    int                     getParentLoop(int curLoop) const;
    int                     getClosestLoopTo(const AcGePoint3d& worldPt) const;
    boost::python::list     isPointInsideMPolygon(const AcGePoint3d& worldPt, double tol) const;
    bool                    isPointOnLoopBoundary(const AcGePoint3d& worldPt, int loop, double tol) const;
    bool                    loopCrossesItself(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const;
    bool                    selfCrosses(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const;
    bool                    includesTouchingLoops(double tol) const;
    boost::python::list     createLoopsFromBoundaries(const AcDbObjectIdArray& ids, bool excludeCrossing, double tol);
    static std::string      className();
    static PyRxClass        desc();
    static PyDbMPolygon     cloneFrom(const PyRxObject& src);
    static PyDbMPolygon     cast(const PyRxObject& src);

public:
    AcDbMPolygon* impObj(const std::source_location& src = std::source_location::current()) const;
private:
};
#pragma pack (pop)
