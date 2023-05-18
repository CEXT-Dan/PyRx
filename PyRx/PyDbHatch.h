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
	PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode);
	virtual ~PyDbHatch() override = default;

	double				elevation() const;
	Acad::ErrorStatus	setElevation(double elevation);
	AcGeVector3d		normal() const;
	Acad::ErrorStatus	setNormal(const AcGeVector3d& normal);
	AcCmColor			backgroundColor() const;
	Acad::ErrorStatus	setBackgroundColor(const AcCmColor& color);
	int					numLoops() const;
	boost::python::tuple getLoopEdgesAt(int loopIndex);
	boost::python::tuple getLoopBulgesAt(int loopIndex);
	Acad::ErrorStatus   appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes);
	Acad::ErrorStatus   appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges);
	Acad::ErrorStatus	removeLoopAt(int loopIndex);
	bool				associative() const;
	Acad::ErrorStatus	setAssociative(bool isAssociative);
	Acad::ErrorStatus	appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds);
	Acad::ErrorStatus	insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds);
	boost::python::list	getAssocObjIdsAt(int loopIndex) const;
	boost::python::list	getAssocObjIds() const;
	Acad::ErrorStatus   removeAssocObjIds();
	AcDbHatch::HatchObjectType hatchObjectType() const;
	Acad::ErrorStatus	setHatchObjectType(AcDbHatch::HatchObjectType type);
	Adesk::Boolean		isGradient() const;
	Adesk::Boolean		isHatch() const;
	AcDbHatch::GradientPatternType gradientType() const;
	std::string			gradientName() const;
	Acad::ErrorStatus   setGradient(AcDbHatch::GradientPatternType gradType,const std::string& gradName);
	double				gradientAngle() const;
	Acad::ErrorStatus	setGradientAngle(double angle);
	boost::python::tuple getGradientColors();
	Acad::ErrorStatus	setGradientColors(const boost::python::list& colors, const boost::python::list& values);
	Adesk::Boolean		getGradientOneColorMode() const;
	Acad::ErrorStatus	setGradientOneColorMode(Adesk::Boolean oneColorMode);
	float				getShadeTintValue() const;
	Acad::ErrorStatus	setShadeTintValue(float value);
	Acad::ErrorStatus	setShadeTintValueAndColor2(float value);
	float				gradientShift() const;
	Acad::ErrorStatus	setGradientShift(float shiftValue);
	AcCmColor			evaluateGradientColorAt(float value);
	AcDbHatch::HatchPatternType patternType() const;
	std::string			patternName() const;
	Acad::ErrorStatus	setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName);
	double				patternAngle() const;
	Acad::ErrorStatus	setPatternAngle(double angle);
	double				patternSpace() const;
	Acad::ErrorStatus	setPatternSpace(double space);
	double				patternScale() const;
	Acad::ErrorStatus	setPatternScale(double scale);
	bool				patternDouble() const;
	Acad::ErrorStatus	setPatternDouble(bool isDouble);
	int					numPatternDefinitions() const;
	boost::python::tuple getPatternDefinitionAt(int index);
	AcDbHatch::HatchStyle hatchStyle() const;
	Acad::ErrorStatus	setHatchStyle(AcDbHatch::HatchStyle hstyle);
	Acad::ErrorStatus  evaluateHatch1();
	Acad::ErrorStatus  evaluateHatch2(bool bUnderestimateNumLines);
	Acad::ErrorStatus  evaluateHatchAllScales1();
	Acad::ErrorStatus  evaluateHatchAllScales2(bool bUnderestimateNumLines);
	bool               lineGenerationEnabled() const;
	bool               setLineGenerationEnabled(bool bEnable);
	int				   numHatchLines() const;
	bool			   isSolidFill() const;
	boost::python::tuple getHatchLineDataAt(int index) const;
	boost::python::tuple getHatchLinesData() const;
	double			   getArea() const;
	Acad::ErrorStatus  setOriginPoint(const AcGePoint2d& pt);
	AcGePoint2d        originPoint() const;
	PyDbRegion         getRegionArea() const;
	void               removeHatchLines();
	static std::string className();
	static PyRxClass   desc();
public:
	AcDbHatch* impObj(const std::source_location& src = std::source_location::current()) const;

};

