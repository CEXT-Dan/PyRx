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
    void	            setElevation(double elevation) const;
    AcGeVector3d		normal() const;
    void	            setNormal(const AcGeVector3d& normal) const;
    AcCmColor			backgroundColor() const;
    void	            setBackgroundColor(const AcCmColor& color) const;
    int					numLoops() const;
    boost::python::tuple getLoopEdgesAt(int loopIndex) const;
    boost::python::tuple getLoopBulgesAt(int loopIndex) const;
    void                appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes) const;
    void                appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges) const;
    void	            removeLoopAt(int loopIndex) const;
    bool				associative() const;
    void	            setAssociative(bool isAssociative) const;
    void	            appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds) const;
    void	            insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds) const;
    boost::python::list	getAssocObjIdsAt(int loopIndex) const;
    boost::python::list	getAssocObjIds() const;
    void                removeAssocObjIds() const;
    AcDbHatch::HatchObjectType hatchObjectType() const;
    void	            setHatchObjectType(AcDbHatch::HatchObjectType type) const;
    Adesk::Boolean		isGradient() const;
    Adesk::Boolean		isHatch() const;
    AcDbHatch::GradientPatternType gradientType() const;
    std::string			gradientName() const;
    void                setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName) const;
    double				gradientAngle() const;
    void	            setGradientAngle(double angle) const;
    boost::python::tuple getGradientColors() const;
    void	            setGradientColors(const boost::python::list& colors, const boost::python::list& values) const;
    Adesk::Boolean		getGradientOneColorMode() const;
    void	            setGradientOneColorMode(Adesk::Boolean oneColorMode) const;
    float				getShadeTintValue() const;
    void	            setShadeTintValue(float value) const;
    void	            setShadeTintValueAndColor2(float value) const;
    float				gradientShift() const;
    void	            setGradientShift(float shiftValue) const;
    AcCmColor			evaluateGradientColorAt(float value) const;
    AcDbHatch::HatchPatternType patternType() const;
    std::string			patternName() const;
    void	            setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName) const;
    double				patternAngle() const;
    void	            setPatternAngle(double angle) const;
    double				patternSpace() const;
    void	            setPatternSpace(double space) const;
    double				patternScale() const;
    void	            setPatternScale(double scale) const;
    bool				patternDouble() const;
    void	            setPatternDouble(bool isDouble) const;
    int					numPatternDefinitions() const;
    boost::python::tuple getPatternDefinitionAt(int index) const;
    AcDbHatch::HatchStyle hatchStyle() const;
    void	            setHatchStyle(AcDbHatch::HatchStyle hstyle) const;
    void                evaluateHatch1() const;
    void                evaluateHatch2(bool bUnderestimateNumLines) const;
    void                evaluateHatchAllScales1() const;
    void                evaluateHatchAllScales2(bool bUnderestimateNumLines) const;
    bool                lineGenerationEnabled() const;
    bool                setLineGenerationEnabled(bool bEnable) const;
    int				    numHatchLines() const;
    bool			    isSolidFill() const;
    boost::python::tuple getHatchLineDataAt(int index) const;
    boost::python::tuple getHatchLinesData() const;
    double			    getArea() const;
    void  setOriginPoint(const AcGePoint2d& pt) const;
    AcGePoint2d         originPoint() const;
    PyDbRegion          getRegionArea() const;
    void                removeHatchLines() const;
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
    PyDbMPolygon(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbMPolygon() override = default;

    PyDbHatch               hatch() const;
    double				    elevation() const;
    void	                setElevation(double elevation) const;
    AcGeVector3d		    normal() const;
    void	                setNormal(const AcGeVector3d& normal) const;
    void                    evaluateHatch1() const;
    void                    evaluateHatch2(bool bUnderestimateNumLines) const;
    AcDbHatch::HatchPatternType patternType() const;
    std::string             patternName() const;
    void                    setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName) const;
    double                  patternAngle() const;
    void                    setPatternAngle(double angle) const;
    double                  patternSpace() const;
    void                    setPatternSpace(double space) const;
    double                  patternScale() const;
    void                    setPatternScale(double scale) const;
    bool                    patternDouble() const;
    void                    setPatternDouble(bool isDouble) const;
    int                     numPatternDefinitions() const;
    boost::python::tuple    getPatternDefinitionAt(int index) const;
    void                    setGradientAngle(double angle) const;
    void                    setGradientShift(float shiftValue) const;
    void                    setGradientOneColorMode(Adesk::Boolean oneColorMode) const;
    void	                setGradientColors(const boost::python::list& colors, const boost::python::list& values) const;
    void                    setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName) const;
    AcCmColor               patternColor() const;
    void                    setPatternColor(const AcCmColor& pc) const;
    double                  getArea() const;
    double                  getPerimeter() const;
    bool                    isBalanced() const;
    AcGeVector2d            getOffsetVector() const;
    //Acad::ErrorStatus     getMPolygonTree(AcDbMPolygonNode*& loopNode) const;
    //void                  deleteMPolygonTree(AcDbMPolygonNode* loopNode) const;
    void                    appendLoopFromBoundary1(const PyDbCircle& pCircle, bool excludeCrossing, double tol) const;
    void                    appendLoopFromBoundary2(const PyDbPolyline& pPoly, bool excludeCrossing, double tol) const;
    void                    appendLoopFromBoundary3(const PyDb2dPolyline& pPoly, bool excludeCrossing, double tol) const;
    int                     numMPolygonLoops() const;
    boost::python::tuple    getMPolygonLoopAt(int loopIndex) const;
    void                    insertMPolygonLoopAt(int loopIndex, const boost::python::list& vertices, const boost::python::list& bulges, bool excludeCrossing, double tol) const;
    void                    appendMPolygonLoop(const boost::python::list& vertices, const boost::python::list& bulges, bool excludeCrossing, double tol) const;
    void                    removeMPolygonLoopAt(int loopIndex) const;
    void                    balanceTree() const;
    void                    balanceDisplay() const;
    AcDbMPolygon::loopDir   getLoopDirection(int lindex) const;
    void                    setLoopDirection(int lindex, AcDbMPolygon::loopDir dir) const;
    int                     getLoopAtGsMarker(int gsMark) const;
    boost::python::list     getChildLoops(int curLoop) const;
    int                     getParentLoop(int curLoop) const;
    int                     getClosestLoopTo(const AcGePoint3d& worldPt) const;
    boost::python::list     isPointInsideMPolygon(const AcGePoint3d& worldPt, double tol) const;
    bool                    isPointOnLoopBoundary(const AcGePoint3d& worldPt, int loop, double tol) const;
    bool                    loopCrossesItself(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const;
    bool                    selfCrosses(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const;
    bool                    includesTouchingLoops(double tol) const;
    boost::python::list     createLoopsFromBoundaries(const AcDbObjectIdArray& ids, bool excludeCrossing, double tol) const;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbMPolygon     cloneFrom(const PyRxObject& src);
    static PyDbMPolygon     cast(const PyRxObject& src);

public:
    AcDbMPolygon* impObj(const std::source_location& src = std::source_location::current()) const;
private:
};
#pragma pack (pop)
