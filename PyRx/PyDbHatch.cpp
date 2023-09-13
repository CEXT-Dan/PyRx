#include "stdafx.h"
#include "PyDbHatch.h"
#include "PyDbObjectId.h"
#include "PyGeCurve2d.h"

using namespace boost::python;

void makePyDbHatchWrapper()
{
    class_<PyDbHatch, bases<PyDbEntity>>("Hatch")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("elevation", &PyDbHatch::elevation)
        .def("setElevation", &PyDbHatch::setElevation)
        .def("normal", &PyDbHatch::normal)
        .def("setNormal", &PyDbHatch::setNormal)
        .def("backgroundColor", &PyDbHatch::backgroundColor)
        .def("setBackgroundColor", &PyDbHatch::setBackgroundColor)
        .def("numLoops", &PyDbHatch::numLoops)
        .def("getLoopEdgesAt", &PyDbHatch::getLoopEdgesAt)
        .def("getLoopBulgesAt", &PyDbHatch::getLoopBulgesAt)
        .def("appendLoopEdges", &PyDbHatch::appendLoopEdges)
        .def("appendLoopBulges", &PyDbHatch::appendLoopBulges)
        .def("removeLoopAt", &PyDbHatch::removeLoopAt)
        .def("associative", &PyDbHatch::associative)
        .def("setAssociative", &PyDbHatch::setAssociative)
        .def("appendLoop", &PyDbHatch::appendLoop)
        .def("insertLoopAt", &PyDbHatch::insertLoopAt)
        .def("getAssocObjIdsAt", &PyDbHatch::getAssocObjIdsAt)
        .def("getAssocObjIds", &PyDbHatch::getAssocObjIds)
        .def("removeAssocObjIds", &PyDbHatch::removeAssocObjIds)
        .def("hatchObjectType", &PyDbHatch::hatchObjectType)
        .def("setHatchObjectType", &PyDbHatch::setHatchObjectType)
        .def("isGradient", &PyDbHatch::isGradient)
        .def("isHatch", &PyDbHatch::isHatch)
        .def("gradientType", &PyDbHatch::gradientType)
        .def("gradientName", &PyDbHatch::gradientName)
        .def("setGradient", &PyDbHatch::setGradient)
        .def("gradientAngle", &PyDbHatch::gradientAngle)
        .def("setGradientAngle", &PyDbHatch::setGradientAngle)
        .def("getGradientColors", &PyDbHatch::getGradientColors)
        .def("setGradientColors", &PyDbHatch::setGradientColors)
        .def("getGradientOneColorMode", &PyDbHatch::getGradientOneColorMode)
        .def("setGradientOneColorMode", &PyDbHatch::setGradientOneColorMode)
        .def("getShadeTintValue", &PyDbHatch::getShadeTintValue)
        .def("setShadeTintValue", &PyDbHatch::setShadeTintValue)
        .def("setShadeTintValueAndColor2", &PyDbHatch::setShadeTintValueAndColor2)
        .def("gradientShift", &PyDbHatch::gradientShift)
        .def("setGradientShift", &PyDbHatch::setGradientShift)
        .def("evaluateGradientColorAt", &PyDbHatch::evaluateGradientColorAt)
        .def("patternType", &PyDbHatch::patternType)
        .def("patternName", &PyDbHatch::patternName)
        .def("setPattern", &PyDbHatch::setPattern)
        .def("patternAngle", &PyDbHatch::patternAngle)
        .def("setPatternAngle", &PyDbHatch::setPatternAngle)
        .def("patternSpace", &PyDbHatch::patternSpace)
        .def("setPatternSpace", &PyDbHatch::setPatternSpace)
        .def("patternScale", &PyDbHatch::patternScale)
        .def("setPatternScale", &PyDbHatch::setPatternScale)
        .def("patternDouble", &PyDbHatch::patternDouble)
        .def("setPatternDouble", &PyDbHatch::setPatternDouble)
        .def("numPatternDefinitions", &PyDbHatch::numPatternDefinitions)
        .def("getPatternDefinitionAt", &PyDbHatch::getPatternDefinitionAt)
        .def("hatchStyle", &PyDbHatch::hatchStyle)
        .def("setHatchStyle", &PyDbHatch::setHatchStyle)
        .def("evaluateHatch", &PyDbHatch::evaluateHatch1)
        .def("evaluateHatch", &PyDbHatch::evaluateHatch2)
        .def("evaluateHatchAllScales1", &PyDbHatch::evaluateHatchAllScales1)
        .def("evaluateHatchAllScales2", &PyDbHatch::evaluateHatchAllScales2)
        .def("lineGenerationEnabled", &PyDbHatch::lineGenerationEnabled)
        .def("setLineGenerationEnabled", &PyDbHatch::setLineGenerationEnabled)
        .def("numHatchLines", &PyDbHatch::numHatchLines)
        .def("isSolidFill", &PyDbHatch::isSolidFill)
        .def("getHatchLineDataAt", &PyDbHatch::getHatchLineDataAt)
        .def("getHatchLinesData", &PyDbHatch::getHatchLinesData)
        .def("getArea", &PyDbHatch::getArea)
        .def("setOriginPoint", &PyDbHatch::setOriginPoint)
        .def("originPoint", &PyDbHatch::originPoint)
        .def("getRegionArea", &PyDbHatch::getRegionArea)
        .def("removeHatchLines", &PyDbHatch::removeHatchLines)
        .def("className", &PyDbHatch::className).staticmethod("className")
        .def("desc", &PyDbHatch::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbHatch::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbHatch::cast).staticmethod("cast")
        ;

    enum_<AcDbHatch::HatchObjectType>("HatchObjectType")
        .value("kHatchObject", AcDbHatch::HatchObjectType::kHatchObject)
        .value("kGradientObject", AcDbHatch::HatchObjectType::kGradientObject)
        .export_values()
        ;

    enum_<AcDbHatch::HatchLoopType>("HatchLoopType")
        .value("kDefault", AcDbHatch::HatchLoopType::kDefault)
        .value("kExternal", AcDbHatch::HatchLoopType::kExternal)
        .value("kPolyline", AcDbHatch::HatchLoopType::kPolyline)
        .value("kDerived", AcDbHatch::HatchLoopType::kDerived)
        .value("kTextbox", AcDbHatch::HatchLoopType::kTextbox)
        .value("kOutermost", AcDbHatch::HatchLoopType::kOutermost)
        .value("kNotClosed", AcDbHatch::HatchLoopType::kNotClosed)
        .value("kSelfIntersecting", AcDbHatch::HatchLoopType::kSelfIntersecting)
        .value("kTextIsland", AcDbHatch::HatchLoopType::kTextIsland)
        .value("kDuplicate", AcDbHatch::HatchLoopType::kDuplicate)
        .value("kIsAnnotative", AcDbHatch::HatchLoopType::kIsAnnotative)
        .value("kDoesNotSupportScale", AcDbHatch::HatchLoopType::kDoesNotSupportScale)
        .value("kForceAnnoAllVisible", AcDbHatch::HatchLoopType::kForceAnnoAllVisible)
        .value("kOrientToPaper", AcDbHatch::HatchLoopType::kOrientToPaper)
        .value("kIsAnnotativeBlock", AcDbHatch::HatchLoopType::kIsAnnotativeBlock)
        .export_values()
        ;

    enum_<AcDbHatch::HatchEdgeType>("HatchEdgeType")
        .value("kLine", AcDbHatch::HatchEdgeType::kLine)
        .value("kCirArc", AcDbHatch::HatchEdgeType::kCirArc)
        .value("kEllArc", AcDbHatch::HatchEdgeType::kEllArc)
        .value("kSpline", AcDbHatch::HatchEdgeType::kSpline)
        .export_values()
        ;

    enum_<AcDbHatch::HatchPatternType>("HatchPatternType")
        .value("kUserDefined", AcDbHatch::HatchPatternType::kUserDefined)
        .value("kPreDefined", AcDbHatch::HatchPatternType::kPreDefined)
        .value("kCustomDefined", AcDbHatch::HatchPatternType::kCustomDefined)
        .export_values()
        ;

    enum_<AcDbHatch::HatchStyle>("HatchStyle")
        .value("kNormal", AcDbHatch::HatchStyle::kNormal)
        .value("kOuter", AcDbHatch::HatchStyle::kOuter)
        .value("kIgnore", AcDbHatch::HatchStyle::kIgnore)
        .export_values()
        ;

    enum_<AcDbHatch::GradientPatternType>("HatchGradientPatternType")
        .value("kPreDefinedGradient", AcDbHatch::GradientPatternType::kPreDefinedGradient)
        .value("kUserDefinedGradient", AcDbHatch::GradientPatternType::kUserDefinedGradient)
        .export_values()
        ;
}

PyDbHatch::PyDbHatch()
    : PyDbEntity(new AcDbHatch(), true)
{
}

PyDbHatch::PyDbHatch(AcDbHatch* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbHatch::PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbHatch>(id,mode), false)
{
}

PyDbHatch::PyDbHatch(const PyDbObjectId& id)
    : PyDbHatch(id, AcDb::OpenMode::kForRead)
{
}

double PyDbHatch::elevation() const
{
    return impObj()->elevation();
}

void PyDbHatch::setElevation(double elevation)
{
    return PyThrowBadEs(impObj()->setElevation(elevation));
}

AcGeVector3d PyDbHatch::normal() const
{
    return impObj()->normal();
}

void PyDbHatch::setNormal(const AcGeVector3d& normal)
{
    return PyThrowBadEs(impObj()->setNormal(normal));
}

AcCmColor PyDbHatch::backgroundColor() const
{
    return impObj()->backgroundColor();
}

void PyDbHatch::setBackgroundColor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setBackgroundColor(color));
}

int PyDbHatch::numLoops() const
{
    return impObj()->numLoops();
}

boost::python::tuple PyDbHatch::getLoopEdgesAt(int loopIndex)
{
    Adesk::Int32 loopType;
    AcGeVoidPointerArray edgePtrs;
    AcGeIntArray edgeTypes;
    PyThrowBadEs(impObj()->getLoopAt(loopIndex, loopType, edgePtrs, edgeTypes));
    PyAutoLockGIL lock;
    boost::python::list edgePtrsList;
    for (auto ep : edgePtrs)
        edgePtrsList.append(PyGeCurve2d((AcGeCurve2d*)ep));
    boost::python::list edgeTypesList;
    for (auto et : edgeTypes)
        edgeTypes.append(et);
    return boost::python::make_tuple(loopType, edgePtrsList, edgeTypesList);
}

boost::python::tuple PyDbHatch::getLoopBulgesAt(int loopIndex)
{
    Adesk::Int32 loopType;
    AcGePoint2dArray vertices;
    AcGeDoubleArray bulges;
    PyThrowBadEs(impObj()->getLoopAt(loopIndex, loopType, vertices, bulges));
    PyAutoLockGIL lock;
    boost::python::list verticesList;
    for (auto p : vertices)
        verticesList.append(p);
    boost::python::list bulgesList;
    for (auto b : bulges)
        bulgesList.append(b);
    return boost::python::make_tuple(loopType, verticesList, bulgesList);
}

void PyDbHatch::appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes)
{
    AcGeVoidPointerArray _edgePtrs;
    const auto& curves = py_list_to_std_vector<PyGeCurve2d>(edgePtrs);
    for (const auto& curve : curves)
        _edgePtrs.append(curve.impObj()->copy());

    const auto& _edgeTypes = PyListToIntArray(edgeTypes);
    return PyThrowBadEs(impObj()->appendLoop(loopType, _edgePtrs, _edgeTypes));
}

void PyDbHatch::appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges)
{
    const auto& _vertices = PyListToPoint2dArray(vertices);
    const auto& _bulges = PyListToDoubleArray(bulges);
    return PyThrowBadEs(impObj()->appendLoop(loopType, _vertices, _bulges));
}

void PyDbHatch::removeLoopAt(int loopIndex)
{
    return PyThrowBadEs(impObj()->removeLoopAt(loopIndex));
}

bool PyDbHatch::associative() const
{
    return impObj()->associative();
}

void PyDbHatch::setAssociative(bool isAssociative)
{
    return PyThrowBadEs(impObj()->setAssociative(isAssociative));
}

void PyDbHatch::appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds)
{
    return PyThrowBadEs(impObj()->appendLoop(loopType, PyListToObjectIdArray(dbObjIds)));
}

void PyDbHatch::insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds)
{
    return PyThrowBadEs(impObj()->insertLoopAt(loopIndex, loopType, PyListToObjectIdArray(dbObjIds)));
}

boost::python::list PyDbHatch::getAssocObjIdsAt(int loopIndex) const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getAssocObjIdsAt(loopIndex, ids));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbHatch::getAssocObjIds() const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getAssocObjIds(ids));
    return ObjectIdArrayToPyList(ids);
}

void PyDbHatch::removeAssocObjIds()
{
    return PyThrowBadEs(impObj()->removeAssocObjIds());
}

AcDbHatch::HatchObjectType PyDbHatch::hatchObjectType() const
{
    return impObj()->hatchObjectType();
}

void PyDbHatch::setHatchObjectType(AcDbHatch::HatchObjectType type)
{
    return PyThrowBadEs(impObj()->setHatchObjectType(type));
}

Adesk::Boolean PyDbHatch::isGradient() const
{
    return impObj()->isGradient();
}

Adesk::Boolean PyDbHatch::isHatch() const
{
    return impObj()->isHatch();
}

AcDbHatch::GradientPatternType PyDbHatch::gradientType() const
{
    return impObj()->gradientType();
}

std::string PyDbHatch::gradientName() const
{
    return wstr_to_utf8(impObj()->gradientName());
}

void PyDbHatch::setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName)
{
    return PyThrowBadEs(impObj()->setGradient(gradType, utf8_to_wstr(gradName).c_str()));
}

double PyDbHatch::gradientAngle() const
{
    return impObj()->gradientAngle();
}

void PyDbHatch::setGradientAngle(double angle)
{
    return PyThrowBadEs(impObj()->setGradientAngle(angle));
}

boost::python::tuple PyDbHatch::getGradientColors()
{
    PyAutoLockGIL lock;
    unsigned int count = 0;
    float* values = nullptr;
    AcCmColor* clrs = nullptr;
    PyThrowBadEs(impObj()->getGradientColors(count, clrs, values));
    boost::python::list colorList;
    boost::python::list valueList;
    for (unsigned int idx = 0; idx < count; idx++)
    {
        colorList.append(clrs[idx]);
        valueList.append(values[idx]);
    }
    return boost::python::make_tuple(colorList, valueList);
}

void PyDbHatch::setGradientColors(const boost::python::list& colors, const boost::python::list& values)
{
    PyAutoLockGIL lock;
    auto _colors = py_list_to_std_vector<AcCmColor>(colors);
    auto _values = py_list_to_std_vector<float>(values);
    if (_colors.size() != _values.size())
        PyThrowBadEs(eInvalidInput);
    return PyThrowBadEs(impObj()->setGradientColors(_colors.size(), _colors.data(), _values.data()));
}

Adesk::Boolean PyDbHatch::getGradientOneColorMode() const
{
    return impObj()->getGradientOneColorMode();
}

void PyDbHatch::setGradientOneColorMode(Adesk::Boolean oneColorMode)
{
    return PyThrowBadEs(impObj()->setGradientOneColorMode(oneColorMode));
}

float PyDbHatch::getShadeTintValue() const
{
    return impObj()->getShadeTintValue();
}

void PyDbHatch::setShadeTintValue(float value)
{
    return PyThrowBadEs(impObj()->setShadeTintValue(value));
}

void PyDbHatch::setShadeTintValueAndColor2(float value)
{
    return PyThrowBadEs(impObj()->setShadeTintValueAndColor2(value));
}

float PyDbHatch::gradientShift() const
{
    return impObj()->gradientShift();
}

void PyDbHatch::setGradientShift(float shiftValue)
{
    return PyThrowBadEs(impObj()->setGradientShift(shiftValue));
}

AcCmColor PyDbHatch::evaluateGradientColorAt(float value)
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->evaluateGradientColorAt(value, clr));
    return clr;
}

AcDbHatch::HatchPatternType PyDbHatch::patternType() const
{
    return impObj()->patternType();
}

std::string PyDbHatch::patternName() const
{
    return wstr_to_utf8(impObj()->patternName());
}

void PyDbHatch::setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName)
{
    return PyThrowBadEs(impObj()->setPattern(patType, utf8_to_wstr(patName).c_str()));
}

double PyDbHatch::patternAngle() const
{
    return impObj()->patternAngle();
}

void PyDbHatch::setPatternAngle(double angle)
{
    return PyThrowBadEs(impObj()->setPatternAngle(angle));
}

double PyDbHatch::patternSpace() const
{
    return impObj()->patternSpace();
}

void PyDbHatch::setPatternSpace(double space)
{
    return PyThrowBadEs(impObj()->setPatternSpace(space));
}

double PyDbHatch::patternScale() const
{
    return impObj()->patternScale();
}

void PyDbHatch::setPatternScale(double scale)
{
    return PyThrowBadEs(impObj()->setPatternScale(scale));
}

bool PyDbHatch::patternDouble() const
{
    return impObj()->patternDouble();
}

void PyDbHatch::setPatternDouble(bool isDouble)
{
    return PyThrowBadEs(impObj()->setPatternDouble(isDouble));
}

int PyDbHatch::numPatternDefinitions() const
{
    return impObj()->numPatternDefinitions();
}

boost::python::tuple PyDbHatch::getPatternDefinitionAt(int index)
{
    PyAutoLockGIL lock;
    double angle;
    double baseX;
    double baseY;
    double offsetX;
    double offsetY;
    AcGeDoubleArray dashes;
    PyThrowBadEs(impObj()->getPatternDefinitionAt(index, angle, baseX, baseY, offsetX, offsetY, dashes));
    return boost::python::make_tuple(angle, baseX, baseY, offsetX, offsetY, DoubleArrayToPyList(dashes));
}

AcDbHatch::HatchStyle PyDbHatch::hatchStyle() const
{
    return impObj()->hatchStyle();
}

void PyDbHatch::setHatchStyle(AcDbHatch::HatchStyle hstyle)
{
    return PyThrowBadEs(impObj()->setHatchStyle(hstyle));
}

void PyDbHatch::evaluateHatch1()
{
    return PyThrowBadEs(impObj()->evaluateHatch());
}

void PyDbHatch::evaluateHatch2(bool bUnderestimateNumLines)
{
    return PyThrowBadEs(impObj()->evaluateHatch(bUnderestimateNumLines));
}

void PyDbHatch::evaluateHatchAllScales1()
{
    return PyThrowBadEs(impObj()->evaluateHatchAllScales());
}

void PyDbHatch::evaluateHatchAllScales2(bool bUnderestimateNumLines)
{
    return PyThrowBadEs(impObj()->evaluateHatchAllScales(bUnderestimateNumLines));
}

bool PyDbHatch::lineGenerationEnabled() const
{
    return impObj()->lineGenerationEnabled();
}

bool PyDbHatch::setLineGenerationEnabled(bool bEnable)
{
    return impObj()->setLineGenerationEnabled(bEnable);
}

int PyDbHatch::numHatchLines() const
{
    return impObj()->numHatchLines();
}

bool PyDbHatch::isSolidFill() const
{
    return impObj()->isSolidFill();
}

boost::python::tuple PyDbHatch::getHatchLineDataAt(int index) const
{
    PyAutoLockGIL lock;
    AcGePoint2d startPt;
    AcGePoint2d endPt;
    PyThrowBadEs(impObj()->getHatchLineDataAt(index, startPt, endPt));
    return boost::python::make_tuple(startPt, endPt);
}

boost::python::tuple PyDbHatch::getHatchLinesData() const
{
    PyAutoLockGIL lock;
    AcGePoint2dArray startPts;
    AcGePoint2dArray endPts;
    PyThrowBadEs(impObj()->getHatchLinesData(startPts, endPts));
    return boost::python::make_tuple(Point2dArrayToPyList(startPts), Point2dArrayToPyList(endPts));
}

double PyDbHatch::getArea() const
{
    double a = 0.0;
    PyThrowBadEs(impObj()->getArea(a));
    return a;
}

void PyDbHatch::setOriginPoint(const AcGePoint2d& pt)
{
    return PyThrowBadEs(impObj()->setOriginPoint(pt));
}

AcGePoint2d PyDbHatch::originPoint() const
{
    return impObj()->originPoint();
}

PyDbRegion PyDbHatch::getRegionArea() const
{
    return PyDbRegion(impObj()->getRegionArea(), true);
}

void PyDbHatch::removeHatchLines()
{
    return impObj()->removeHatchLines();
}

std::string PyDbHatch::className()
{
    return "AcDbHatch";
}

PyRxClass PyDbHatch::desc()
{
    return PyRxClass(AcDbHatch::desc(), false);
}

PyDbHatch PyDbHatch::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbHatch::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbHatch(static_cast<AcDbHatch*>(src.impObj()->clone()), true);
}

PyDbHatch PyDbHatch::cast(const PyRxObject& src)
{
    PyDbHatch dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbHatch* PyDbHatch::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbHatch*>(m_pyImp.get());
}
