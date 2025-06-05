#include "stdafx.h"
#include "PyDbHatch.h"
#include "PyDbObjectId.h"
#include "PyGeCurve2d.h"
#include "PyDbEnts.h"

using namespace boost::python;

void makePyDbHatchWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("Hatch");
    class_<PyDbHatch, bases<PyDbEntity>>("Hatch")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 5278)))
        .def("elevation", &PyDbHatch::elevation, DS.ARGS(5284))
        .def("setElevation", &PyDbHatch::setElevation, DS.ARGS({ "val : float" }, 5335))
        .def("normal", &PyDbHatch::normal, DS.ARGS(5320))
        .def("setNormal", &PyDbHatch::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 5344))
        .def("backgroundColor", &PyDbHatch::backgroundColor, DS.ARGS(5283))
        .def("setBackgroundColor", &PyDbHatch::setBackgroundColor, DS.ARGS({ "val : PyDb.AcCmColor" }, 5334))
        .def("numLoops", &PyDbHatch::numLoops, DS.ARGS(5322))
        .def("getLoopEdgesAt", &PyDbHatch::getLoopEdgesAt, DS.ARGS({ "val : int" }, 5295))
        .def("getLoopBulgesAt", &PyDbHatch::getLoopBulgesAt, DS.ARGS({ "val : int" }, 5295))
        .def("appendLoop", &PyDbHatch::appendLoop, DS.ARGS({ "loopType : int", "ids : list[PyDb.ObjectId]" }, 5281))
        .def("appendLoopEdges", &PyDbHatch::appendLoopEdges, DS.ARGS({ "loopType : int", "edges : list","edgeTypes : list" }, 5281))
        .def("appendLoopBulges", &PyDbHatch::appendLoopBulges, DS.ARGS({ "loopType : int", "vertices : list","bulges : list" }, 5281))
        .def("removeLoopAt", &PyDbHatch::removeLoopAt, DS.ARGS({ "idx : int" }, 5332))
        .def("associative", &PyDbHatch::associative, DS.ARGS(5282))
        .def("setAssociative", &PyDbHatch::setAssociative, DS.ARGS({ "val : bool" }, 5333))
        .def("insertLoopAt", &PyDbHatch::insertLoopAt, DS.ARGS({ "idx : int", "loopType : int", "ids : list[PyDb.ObjectId]" }, 5312))
        .def("getAssocObjIdsAt", &PyDbHatch::getAssocObjIdsAt, DS.ARGS({ "val: int" }, 5290))
        .def("getAssocObjIds", &PyDbHatch::getAssocObjIds, DS.ARGS(5289))
        .def("removeAssocObjIds", &PyDbHatch::removeAssocObjIds, DS.ARGS(5330))
        .def("hatchObjectType", &PyDbHatch::hatchObjectType, DS.ARGS(5307))
        .def("setHatchObjectType", &PyDbHatch::setHatchObjectType, DS.ARGS({ "val: PyDb.HatchObjectType" }, 5341))
        .def("isGradient", &PyDbHatch::isGradient, DS.ARGS(5313))
        .def("isHatch", &PyDbHatch::isHatch, DS.ARGS(5314))
        .def("gradientType", &PyDbHatch::gradientType, DS.ARGS(5304))
        .def("gradientName", &PyDbHatch::gradientName, DS.ARGS(5301))
        .def("setGradient", &PyDbHatch::setGradient, DS.ARGS({ "val: PyDb.HatchGradientPatternType","name: str" }, 5336))
        .def("gradientAngle", &PyDbHatch::gradientAngle, DS.ARGS(5300))
        .def("setGradientAngle", &PyDbHatch::setGradientAngle, DS.ARGS({ "val : float" }, 5337))
        .def("getGradientColors", &PyDbHatch::getGradientColors, DS.ARGS(5291))
        .def("setGradientColors", &PyDbHatch::setGradientColors, DS.ARGS({ "colors : list","values : list" }, 5338))
        .def("getGradientOneColorMode", &PyDbHatch::getGradientOneColorMode, DS.ARGS(5292))
        .def("setGradientOneColorMode", &PyDbHatch::setGradientOneColorMode, DS.ARGS({ "val : bool" }, 5339))
        .def("getShadeTintValue", &PyDbHatch::getShadeTintValue, DS.ARGS(5299))
        .def("setShadeTintValue", &PyDbHatch::setShadeTintValue, DS.ARGS({ "val : float" }, 5351))
        .def("setShadeTintValueAndColor2", &PyDbHatch::setShadeTintValueAndColor2, DS.ARGS({ "val: float" }, 5352))
        .def("gradientShift", &PyDbHatch::gradientShift, DS.ARGS(5303))
        .def("setGradientShift", &PyDbHatch::setGradientShift, DS.ARGS({ "val : float" }, 5340))
        .def("evaluateGradientColorAt", &PyDbHatch::evaluateGradientColorAt, DS.ARGS({ "val: float" }, 5285))
        .def("patternType", &PyDbHatch::patternType, DS.ARGS(5329))
        .def("patternName", &PyDbHatch::patternName, DS.ARGS())
        .def("setPattern", &PyDbHatch::setPattern, DS.ARGS({ "val: PyDb.HatchPatternType","name: str" }, 5346))
        .def("patternAngle", &PyDbHatch::patternAngle, DS.ARGS(5325))
        .def("setPatternAngle", &PyDbHatch::setPatternAngle, DS.ARGS({ "val : float" }, 5347))
        .def("patternSpace", &PyDbHatch::patternSpace, DS.ARGS(5328))
        .def("setPatternSpace", &PyDbHatch::setPatternSpace, DS.ARGS({ "val : float" }, 5350))
        .def("patternScale", &PyDbHatch::patternScale, DS.ARGS(5327))
        .def("setPatternScale", &PyDbHatch::setPatternScale, DS.ARGS({ "val : float" }, 5349))
        .def("patternDouble", &PyDbHatch::patternDouble, DS.ARGS(5326))
        .def("setPatternDouble", &PyDbHatch::setPatternDouble, DS.ARGS({ "val : bool" }, 5348))
        .def("numPatternDefinitions", &PyDbHatch::numPatternDefinitions, DS.ARGS(5323))
        .def("getPatternDefinitionAt", &PyDbHatch::getPatternDefinitionAt, DS.ARGS({ "val : int" }, 5296))
        .def("hatchStyle", &PyDbHatch::hatchStyle, DS.ARGS(5310))
        .def("setHatchStyle", &PyDbHatch::setHatchStyle, DS.ARGS({ "val: PyDb.HatchStyle" }, 5342))
        .def("evaluateHatch", &PyDbHatch::evaluateHatch1)
        .def("evaluateHatch", &PyDbHatch::evaluateHatch2, DS.ARGS({ "val : bool=False" }, 5286))
        .def("evaluateHatchAllScales", &PyDbHatch::evaluateHatchAllScales1)
        .def("evaluateHatchAllScales", &PyDbHatch::evaluateHatchAllScales2, DS.ARGS({ "val : bool=False" }, 5287))
        .def("lineGenerationEnabled", &PyDbHatch::lineGenerationEnabled, DS.ARGS(5317))
        .def("setLineGenerationEnabled", &PyDbHatch::setLineGenerationEnabled, DS.ARGS({ "val : bool" }, 5343))
        .def("numHatchLines", &PyDbHatch::numHatchLines, DS.ARGS(5321))
        .def("isSolidFill", &PyDbHatch::isSolidFill, DS.ARGS(5316))
        .def("getHatchLineDataAt", &PyDbHatch::getHatchLineDataAt, DS.ARGS({ "val : int" }, 5293))
        .def("getHatchLinesData", &PyDbHatch::getHatchLinesData, DS.ARGS(5294))
        .def("getArea", &PyDbHatch::getArea, DS.ARGS(5288))
        .def("setOriginPoint", &PyDbHatch::setOriginPoint, DS.ARGS({ "val : PyGe.Point2d" }, 5345))
        .def("originPoint", &PyDbHatch::originPoint, DS.ARGS(5324))
        .def("getRegionArea", &PyDbHatch::getRegionArea, DS.ARGS(5298))
        .def("removeHatchLines", &PyDbHatch::removeHatchLines, DS.ARGS(5331))
        .def("className", &PyDbHatch::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbHatch::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbHatch::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbHatch::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
#if !defined (_BRXTARGET250)
        .value("kIsAnnotative", AcDbHatch::HatchLoopType::kIsAnnotative)
        .value("kDoesNotSupportScale", AcDbHatch::HatchLoopType::kDoesNotSupportScale)
        .value("kForceAnnoAllVisible", AcDbHatch::HatchLoopType::kForceAnnoAllVisible)
        .value("kOrientToPaper", AcDbHatch::HatchLoopType::kOrientToPaper)
        .value("kIsAnnotativeBlock", AcDbHatch::HatchLoopType::kIsAnnotativeBlock)
#endif
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
    : PyDbEntity(openAcDbObject<AcDbHatch>(id, mode), false)
{
}

PyDbHatch::PyDbHatch(const PyDbObjectId& id)
    : PyDbHatch(id, AcDb::OpenMode::kForRead)
{
}

PyDbHatch::PyDbHatch(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbHatch>(id, mode, erased), false)
{
}

double PyDbHatch::elevation() const
{
    return impObj()->elevation();
}

void PyDbHatch::setElevation(double elevation) const
{
    return PyThrowBadEs(impObj()->setElevation(elevation));
}

AcGeVector3d PyDbHatch::normal() const
{
    return impObj()->normal();
}

void PyDbHatch::setNormal(const AcGeVector3d& normal) const
{
    return PyThrowBadEs(impObj()->setNormal(normal));
}

AcCmColor PyDbHatch::backgroundColor() const
{
    return impObj()->backgroundColor();
}

void PyDbHatch::setBackgroundColor(const AcCmColor& color) const
{
    return PyThrowBadEs(impObj()->setBackgroundColor(color));
}

int PyDbHatch::numLoops() const
{
    return impObj()->numLoops();
}

boost::python::tuple PyDbHatch::getLoopEdgesAt(int loopIndex) const
{
    Adesk::Int32 loopType;
    AcGeVoidPointerArray edgePtrs;
    AcGeIntArray edgeTypes;
    PyThrowBadEs(impObj()->getLoopAt(loopIndex, loopType, edgePtrs, edgeTypes));

    PyAutoLockGIL lock;
    boost::python::list edgePtrsList;
    for (auto ep : edgePtrs)
        edgePtrsList.append(PyGeCurve2d((AcGeCurve2d*)ep));

    return boost::python::make_tuple(loopType, edgePtrsList, IntArrayToPyList(edgeTypes));
}

boost::python::tuple PyDbHatch::getLoopBulgesAt(int loopIndex) const
{
    Adesk::Int32 loopType;
    AcGePoint2dArray vertices;
    AcGeDoubleArray bulges;
    PyThrowBadEs(impObj()->getLoopAt(loopIndex, loopType, vertices, bulges));
    return boost::python::make_tuple(loopType, Point2dArrayToPyList(vertices), DoubleArrayToPyList(bulges));
}

void PyDbHatch::appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes) const
{
    //TODO: hatch seems to take ownership of the curve
    AcGeVoidPointerArray _edgePtrs;
    const auto& curves = py_list_to_std_vector<PyGeCurve2d>(edgePtrs);
    for (const auto& curve : curves)
        _edgePtrs.append(curve.impObj()->copy());
    const auto& _edgeTypes = PyListToIntArray(edgeTypes);
    PyThrowBadEs(impObj()->appendLoop(loopType, _edgePtrs, _edgeTypes));
}

void PyDbHatch::appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges) const
{
    const auto& _vertices = PyListToPoint2dArray(vertices);
    const auto& _bulges = PyListToDoubleArray(bulges);
    return PyThrowBadEs(impObj()->appendLoop(loopType, _vertices, _bulges));
}

void PyDbHatch::removeLoopAt(int loopIndex) const
{
    return PyThrowBadEs(impObj()->removeLoopAt(loopIndex));
}

bool PyDbHatch::associative() const
{
    return impObj()->associative();
}

void PyDbHatch::setAssociative(bool isAssociative) const
{
    return PyThrowBadEs(impObj()->setAssociative(isAssociative));
}

void PyDbHatch::appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds) const
{
    return PyThrowBadEs(impObj()->appendLoop(loopType, PyListToObjectIdArray(dbObjIds)));
}

void PyDbHatch::insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds) const
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

void PyDbHatch::removeAssocObjIds() const
{
    return PyThrowBadEs(impObj()->removeAssocObjIds());
}

AcDbHatch::HatchObjectType PyDbHatch::hatchObjectType() const
{
    return impObj()->hatchObjectType();
}

void PyDbHatch::setHatchObjectType(AcDbHatch::HatchObjectType type) const
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

void PyDbHatch::setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName) const
{
    return PyThrowBadEs(impObj()->setGradient(gradType, utf8_to_wstr(gradName).c_str()));
}

double PyDbHatch::gradientAngle() const
{
    return impObj()->gradientAngle();
}

void PyDbHatch::setGradientAngle(double angle) const
{
    return PyThrowBadEs(impObj()->setGradientAngle(angle));
}

boost::python::tuple PyDbHatch::getGradientColors() const
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

void PyDbHatch::setGradientColors(const boost::python::list& colors, const boost::python::list& values) const
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

void PyDbHatch::setGradientOneColorMode(Adesk::Boolean oneColorMode) const
{
    return PyThrowBadEs(impObj()->setGradientOneColorMode(oneColorMode));
}

float PyDbHatch::getShadeTintValue() const
{
    return impObj()->getShadeTintValue();
}

void PyDbHatch::setShadeTintValue(float value) const
{
    return PyThrowBadEs(impObj()->setShadeTintValue(value));
}

void PyDbHatch::setShadeTintValueAndColor2(float value) const
{
    return PyThrowBadEs(impObj()->setShadeTintValueAndColor2(value));
}

float PyDbHatch::gradientShift() const
{
    return impObj()->gradientShift();
}

void PyDbHatch::setGradientShift(float shiftValue) const
{
    return PyThrowBadEs(impObj()->setGradientShift(shiftValue));
}

AcCmColor PyDbHatch::evaluateGradientColorAt(float value) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcCmColor clr;
    PyThrowBadEs(impObj()->evaluateGradientColorAt(value, clr));
    return clr;
#endif
}

AcDbHatch::HatchPatternType PyDbHatch::patternType() const
{
    return impObj()->patternType();
}

std::string PyDbHatch::patternName() const
{
    return wstr_to_utf8(impObj()->patternName());
}

void PyDbHatch::setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName) const
{
    return PyThrowBadEs(impObj()->setPattern(patType, utf8_to_wstr(patName).c_str()));
}

double PyDbHatch::patternAngle() const
{
    return impObj()->patternAngle();
}

void PyDbHatch::setPatternAngle(double angle) const
{
    return PyThrowBadEs(impObj()->setPatternAngle(angle));
}

double PyDbHatch::patternSpace() const
{
    return impObj()->patternSpace();
}

void PyDbHatch::setPatternSpace(double space) const
{
    return PyThrowBadEs(impObj()->setPatternSpace(space));
}

double PyDbHatch::patternScale() const
{
    return impObj()->patternScale();
}

void PyDbHatch::setPatternScale(double scale) const
{
    return PyThrowBadEs(impObj()->setPatternScale(scale));
}

bool PyDbHatch::patternDouble() const
{
    return impObj()->patternDouble();
}

void PyDbHatch::setPatternDouble(bool isDouble) const
{
    return PyThrowBadEs(impObj()->setPatternDouble(isDouble));
}

int PyDbHatch::numPatternDefinitions() const
{
    return impObj()->numPatternDefinitions();
}

boost::python::tuple PyDbHatch::getPatternDefinitionAt(int index) const
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

void PyDbHatch::setHatchStyle(AcDbHatch::HatchStyle hstyle) const
{
    return PyThrowBadEs(impObj()->setHatchStyle(hstyle));
}

void PyDbHatch::evaluateHatch1() const
{
    return PyThrowBadEs(impObj()->evaluateHatch());
}

void PyDbHatch::evaluateHatch2(bool bUnderestimateNumLines) const
{
    return PyThrowBadEs(impObj()->evaluateHatch(bUnderestimateNumLines));
}

void PyDbHatch::evaluateHatchAllScales1() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->evaluateHatchAllScales());
#endif
}

void PyDbHatch::evaluateHatchAllScales2(bool bUnderestimateNumLines) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->evaluateHatchAllScales(bUnderestimateNumLines));
#endif
}

bool PyDbHatch::lineGenerationEnabled() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->lineGenerationEnabled();
#endif
}

bool PyDbHatch::setLineGenerationEnabled(bool bEnable) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setLineGenerationEnabled(bEnable);
#endif
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

void PyDbHatch::setOriginPoint(const AcGePoint2d& pt) const
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

void PyDbHatch::removeHatchLines() const
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
    return PyDbObjectCloneFrom<PyDbHatch, AcDbHatch>(src);
}

PyDbHatch PyDbHatch::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbHatch>(src);
}

AcDbHatch* PyDbHatch::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbHatch*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbMPolygon
void makePyDbMPolygonWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view appendLoopFromBoundaryOverloads = "Overloads:\n"
        "- circle: PyDb.Circle, excludeCrossing: bool, tol: float\n"
        "- pline: PyDb.Polyline, excludeCrossing: bool, tol: float\n"
        "- pline2d: PyDb.Polyline2d, excludeCrossing: bool, tol: float\n";

    PyDocString DS("MPolygon");
    class_<PyDbMPolygon, bases<PyDbEntity>>("MPolygon")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("hatch", &PyDbMPolygon::hatch, DS.ARGS())
        .def("elevation", &PyDbMPolygon::elevation, DS.ARGS())
        .def("setElevation", &PyDbMPolygon::setElevation, DS.ARGS({ "val : float" }))
        .def("normal", &PyDbMPolygon::normal, DS.ARGS())
        .def("setNormal", &PyDbMPolygon::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("evaluateHatch", &PyDbMPolygon::evaluateHatch1)
        .def("evaluateHatch", &PyDbMPolygon::evaluateHatch2, DS.ARGS({ "val : bool=False" }))
        .def("patternType", &PyDbMPolygon::patternType, DS.ARGS())
        .def("patternName", &PyDbMPolygon::patternName, DS.ARGS())
        .def("setPattern", &PyDbMPolygon::setPattern, DS.ARGS({ "val : PyDb.HatchPatternType","name : str" }))
        .def("patternAngle", &PyDbMPolygon::patternAngle, DS.ARGS())
        .def("setPatternAngle", &PyDbMPolygon::setPatternAngle, DS.ARGS({ "val : float" }))
        .def("patternSpace", &PyDbMPolygon::patternSpace, DS.ARGS())
        .def("setPatternSpace", &PyDbMPolygon::setPatternSpace, DS.ARGS({ "val : float" }))
        .def("patternScale", &PyDbMPolygon::patternScale, DS.ARGS())
        .def("setPatternScale", &PyDbMPolygon::setPatternScale, DS.ARGS({ "val : float" }))
        .def("patternDouble", &PyDbMPolygon::patternDouble, DS.ARGS())
        .def("setPatternDouble", &PyDbMPolygon::setPatternDouble, DS.ARGS({ "val : float" }))
        .def("numPatternDefinitions", &PyDbMPolygon::numPatternDefinitions, DS.ARGS())
        .def("getPatternDefinitionAt", &PyDbMPolygon::getPatternDefinitionAt, DS.ARGS({ "val : int" }))
        .def("setGradientAngle", &PyDbMPolygon::setGradientAngle, DS.ARGS({ "val : float" }))
        .def("setGradientShift", &PyDbMPolygon::setGradientShift, DS.ARGS({ "val : float" }))
        .def("setGradientOneColorMode", &PyDbMPolygon::setGradientOneColorMode, DS.ARGS({ "val : bool" }))
        .def("setGradientColors", &PyDbMPolygon::setGradientColors, DS.ARGS({ "colors: list[PyDb.AcCmColor]", "values: list[float]" }))
        .def("setGradient", &PyDbMPolygon::setGradient, DS.ARGS({ "val: PyDb.HatchGradientPatternType", "name: str" }))
        .def("patternColor", &PyDbMPolygon::patternColor, DS.ARGS())
        .def("setPatternColor", &PyDbMPolygon::setPatternColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("getArea", &PyDbMPolygon::getArea, DS.ARGS())
        .def("getPerimeter", &PyDbMPolygon::getPerimeter, DS.ARGS())
        .def("isBalanced", &PyDbMPolygon::isBalanced, DS.ARGS())
        .def("getOffsetVector", &PyDbMPolygon::getOffsetVector, DS.ARGS())
        .def("appendLoopFromBoundary", &PyDbMPolygon::appendLoopFromBoundary1)
        .def("appendLoopFromBoundary", &PyDbMPolygon::appendLoopFromBoundary2)
        .def("appendLoopFromBoundary", &PyDbMPolygon::appendLoopFromBoundary3, DS.OVRL(appendLoopFromBoundaryOverloads))
        .def("numMPolygonLoops", &PyDbMPolygon::numMPolygonLoops, DS.ARGS())
        .def("getMPolygonLoopAt", &PyDbMPolygon::getMPolygonLoopAt, DS.ARGS({ "loopIndex : int" }))
        .def("insertMPolygonLoopAt", &PyDbMPolygon::insertMPolygonLoopAt, DS.ARGS({ "loopIndex: int","vertices: list[PyGe.Point2d]", "bulges: list[float]","excludeCrossing: bool","tol: float" }))
        .def("appendMPolygonLoop", &PyDbMPolygon::appendMPolygonLoop, DS.ARGS({ "vertices: list[PyGe.Point2d]", "bulges: list[float]","excludeCrossing: bool","tol: float" }))
        .def("removeMPolygonLoopAt", &PyDbMPolygon::removeMPolygonLoopAt, DS.ARGS({ "val : int" }))
        .def("balanceTree", &PyDbMPolygon::balanceTree, DS.ARGS())
        .def("balanceDisplay", &PyDbMPolygon::balanceDisplay, DS.ARGS())
        .def("getLoopDirection", &PyDbMPolygon::getLoopDirection, DS.ARGS({ "val : int" }))
        .def("setLoopDirection", &PyDbMPolygon::setLoopDirection, DS.ARGS({ "lindex: int","dir: PyDb.MPolygonloopDir" }))
        .def("getLoopAtGsMarker", &PyDbMPolygon::getLoopAtGsMarker, DS.ARGS({ "gsMark : int" }))
        .def("getChildLoops", &PyDbMPolygon::getChildLoops, DS.ARGS({ "curLoop : int" }))
        .def("getParentLoop", &PyDbMPolygon::getParentLoop, DS.ARGS({ "curLoop : int" }))
        .def("getClosestLoopTo", &PyDbMPolygon::getClosestLoopTo, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("isPointInsideMPolygon", &PyDbMPolygon::isPointInsideMPolygon, DS.ARGS({ "val : PyGe.Point3d","tol : float" }))
        .def("isPointOnLoopBoundary", &PyDbMPolygon::isPointOnLoopBoundary, DS.ARGS({ "val : PyGe.Point3d","loop : int", "tol : float" }))
        .def("loopCrossesItself", &PyDbMPolygon::loopCrossesItself, DS.ARGS({ "vertices: list[PyGe.Point2d]", "bulges: list[float]","tol: float" }))
        .def("selfCrosses", &PyDbMPolygon::selfCrosses, DS.ARGS({ "vertices: list[PyGe.Point2d]", "bulges: list[float]","tol: float" }))
        .def("includesTouchingLoops", &PyDbMPolygon::includesTouchingLoops, DS.ARGS({ "val : float" }))
        .def("createLoopsFromBoundaries", &PyDbMPolygon::createLoopsFromBoundaries, DS.ARGS({ "ids: list[PyDb.ObjectId]" ,"excludeCrossing: bool","tol: float" }))
        .def("className", &PyDbMPolygon::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMPolygon::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMPolygon::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMPolygon::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbMPolygon::loopDir>("MPolygonloopDir")
        .value("kExterior", AcDbMPolygon::loopDir::kExterior)
        .value("kInterior", AcDbMPolygon::loopDir::kInterior)
        .value("kAnnotation", AcDbMPolygon::loopDir::kAnnotation)
        .export_values()
        ;
}

PyDbMPolygon::PyDbMPolygon()
    : PyDbEntity(new AcDbMPolygon(), true)
{
}

PyDbMPolygon::PyDbMPolygon(AcDbMPolygon* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMPolygon::PyDbMPolygon(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbMPolygon>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMPolygon::PyDbMPolygon(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMPolygon>(id, mode), false)
{
}

PyDbMPolygon::PyDbMPolygon(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMPolygon>(id, mode, erased), false)
{
}

PyDbHatch PyDbMPolygon::hatch() const
{
    PyDbHatch hatch(impObj()->hatch(), false);
    hatch.forceKeepAlive(true);
    return hatch;
}

double PyDbMPolygon::elevation() const
{
    return impObj()->elevation();
}

void PyDbMPolygon::setElevation(double elevation) const
{
    PyThrowBadEs(impObj()->setElevation(elevation));
}

AcGeVector3d PyDbMPolygon::normal() const
{
    return impObj()->normal();
}

void PyDbMPolygon::setNormal(const AcGeVector3d& normal) const
{
    PyThrowBadEs(impObj()->setNormal(normal));
}

void PyDbMPolygon::evaluateHatch1() const
{
    PyThrowBadEs(impObj()->evaluateHatch());
}

void PyDbMPolygon::evaluateHatch2(bool bUnderestimateNumLines) const
{
    PyThrowBadEs(impObj()->evaluateHatch(bUnderestimateNumLines));
}

AcDbHatch::HatchPatternType PyDbMPolygon::patternType() const
{
    return impObj()->patternType();
}

std::string PyDbMPolygon::patternName() const
{
    return wstr_to_utf8(impObj()->patternName());
}

void PyDbMPolygon::setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName) const
{
    PyThrowBadEs(impObj()->setPattern(patType, utf8_to_wstr(patName).c_str()));
}

double PyDbMPolygon::patternAngle() const
{
    return impObj()->patternAngle();
}

void PyDbMPolygon::setPatternAngle(double angle) const
{
    PyThrowBadEs(impObj()->setPatternAngle(angle));
}

double PyDbMPolygon::patternSpace() const
{
    return impObj()->patternSpace();
}

void PyDbMPolygon::setPatternSpace(double space) const
{
    PyThrowBadEs(impObj()->setPatternSpace(space));
}

double PyDbMPolygon::patternScale() const
{
    return impObj()->patternScale();
}

void PyDbMPolygon::setPatternScale(double scale) const
{
    PyThrowBadEs(impObj()->setPatternScale(scale));
}

bool PyDbMPolygon::patternDouble() const
{
    return impObj()->patternDouble();
}

void PyDbMPolygon::setPatternDouble(bool isDouble) const
{
    PyThrowBadEs(impObj()->setPatternDouble(isDouble));
}

int PyDbMPolygon::numPatternDefinitions() const
{
    return impObj()->numPatternDefinitions();
}

boost::python::tuple PyDbMPolygon::getPatternDefinitionAt(int index) const
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

void PyDbMPolygon::setGradientAngle(double angle) const
{
    PyThrowBadEs(impObj()->setGradientAngle(angle));
}

void PyDbMPolygon::setGradientShift(float shiftValue) const
{
    PyThrowBadEs(impObj()->setGradientShift(shiftValue));
}

void PyDbMPolygon::setGradientOneColorMode(Adesk::Boolean oneColorMode) const
{
    PyThrowBadEs(impObj()->setGradientOneColorMode(oneColorMode));
}

void PyDbMPolygon::setGradientColors(const boost::python::list& colors, const boost::python::list& values) const
{
    PyAutoLockGIL lock;
    auto _colors = py_list_to_std_vector<AcCmColor>(colors);
    auto _values = py_list_to_std_vector<float>(values);
    if (_colors.size() != _values.size())
        PyThrowBadEs(eInvalidInput);
    return PyThrowBadEs(impObj()->setGradientColors(_colors.size(), _colors.data(), _values.data()));
}

void PyDbMPolygon::setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName) const
{
    PyThrowBadEs(impObj()->setGradient(gradType, utf8_to_wstr(gradName).c_str()));
}

AcCmColor PyDbMPolygon::patternColor() const
{
    return impObj()->patternColor();
}

void PyDbMPolygon::setPatternColor(const AcCmColor& pc) const
{
    PyThrowBadEs(impObj()->setPatternColor(pc));
}

double PyDbMPolygon::getArea() const
{
    return impObj()->getArea();
}

double PyDbMPolygon::getPerimeter() const
{
    return impObj()->getPerimeter();
}

bool PyDbMPolygon::isBalanced() const
{
    return impObj()->isBalanced();
}

AcGeVector2d PyDbMPolygon::getOffsetVector() const
{
    return impObj()->getOffsetVector();
}

void PyDbMPolygon::appendLoopFromBoundary1(const PyDbCircle& pCircle, bool excludeCrossing, double tol) const
{
    PyThrowBadEs(impObj()->appendLoopFromBoundary(pCircle.impObj(), excludeCrossing, tol));
}

void PyDbMPolygon::appendLoopFromBoundary2(const PyDbPolyline& pPoly, bool excludeCrossing, double tol) const
{
    PyThrowBadEs(impObj()->appendLoopFromBoundary(pPoly.impObj(), excludeCrossing, tol));
}

void PyDbMPolygon::appendLoopFromBoundary3(const PyDb2dPolyline& pPoly, bool excludeCrossing, double tol) const
{
    PyThrowBadEs(impObj()->appendLoopFromBoundary(pPoly.impObj(), excludeCrossing, tol));
}

int PyDbMPolygon::numMPolygonLoops() const
{
    return impObj()->numMPolygonLoops();
}

boost::python::tuple PyDbMPolygon::getMPolygonLoopAt(int loopIndex) const
{
    AcGePoint2dArray vertices;
    AcGeDoubleArray bulges;
    PyThrowBadEs(impObj()->getMPolygonLoopAt(loopIndex, vertices, bulges));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(Point2dArrayToPyList(vertices), DoubleArrayToPyList(bulges));
}

void PyDbMPolygon::insertMPolygonLoopAt(int loopIndex, const boost::python::list& vertices, const boost::python::list& bulges, bool excludeCrossing, double tol) const
{
    PyThrowBadEs(impObj()->insertMPolygonLoopAt(loopIndex, PyListToPoint2dArray(vertices), PyListToDoubleArray(bulges), excludeCrossing, tol));
}

void PyDbMPolygon::appendMPolygonLoop(const boost::python::list& vertices, const boost::python::list& bulges, bool excludeCrossing, double tol) const
{
    PyThrowBadEs(impObj()->appendMPolygonLoop(PyListToPoint2dArray(vertices), PyListToDoubleArray(bulges), excludeCrossing, tol));
}

void PyDbMPolygon::removeMPolygonLoopAt(int loopIndex) const
{
    PyThrowBadEs(impObj()->removeMPolygonLoopAt(loopIndex));
}

void PyDbMPolygon::balanceTree() const
{
    PyThrowBadEs(impObj()->balanceTree());
}

void PyDbMPolygon::balanceDisplay() const
{
    PyThrowBadEs(impObj()->balanceDisplay());
}

AcDbMPolygon::loopDir PyDbMPolygon::getLoopDirection(int lindex) const
{
    AcDbMPolygon::loopDir dir = AcDbMPolygon::kExterior;
    PyThrowBadEs(impObj()->getLoopDirection(lindex, dir));
    return dir;
}

void PyDbMPolygon::setLoopDirection(int lindex, AcDbMPolygon::loopDir dir) const
{
    PyThrowBadEs(impObj()->setLoopDirection(lindex, dir));
}

int PyDbMPolygon::getLoopAtGsMarker(int gsMark) const
{
    int loop = -1;
    PyThrowBadEs(impObj()->getLoopAtGsMarker(gsMark, loop));
    return loop;
}

boost::python::list PyDbMPolygon::getChildLoops(int curLoop) const
{
    AcGeIntArray selectedLoopIndexes;
    impObj()->getChildLoops(curLoop, selectedLoopIndexes);
    return IntArrayToPyList(selectedLoopIndexes);
}

int PyDbMPolygon::getParentLoop(int curLoop) const
{
    return impObj()->getParentLoop(curLoop);
}

int PyDbMPolygon::getClosestLoopTo(const AcGePoint3d& worldPt) const
{
    return impObj()->getClosestLoopTo(worldPt);
}

boost::python::list PyDbMPolygon::isPointInsideMPolygon(const AcGePoint3d& worldPt, double tol) const
{
    AcGeIntArray loopsArray;
    impObj()->isPointInsideMPolygon(worldPt, loopsArray, tol);
    return IntArrayToPyList(loopsArray);
}

bool PyDbMPolygon::isPointOnLoopBoundary(const AcGePoint3d& worldPt, int loop, double tol) const
{
    return impObj()->isPointOnLoopBoundary(worldPt, loop, tol);
}

bool PyDbMPolygon::loopCrossesItself(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const
{
    return impObj()->loopCrossesItself(PyListToPoint2dArray(vertexPts), PyListToDoubleArray(vertexBulges), tol);
}

bool PyDbMPolygon::selfCrosses(const boost::python::list& vertexPts, const boost::python::list& vertexBulges, double tol) const
{
    return impObj()->selfCrosses(PyListToPoint2dArray(vertexPts), PyListToDoubleArray(vertexBulges), tol);
}

bool PyDbMPolygon::includesTouchingLoops(double tol) const
{
    return impObj()->includesTouchingLoops(tol);
}

boost::python::list PyDbMPolygon::createLoopsFromBoundaries(const AcDbObjectIdArray& ids, bool excludeCrossing, double tol) const
{
    AcDbIntArray rejectedObjs;
    PyThrowBadEs(impObj()->createLoopsFromBoundaries(ids, rejectedObjs, excludeCrossing, tol));
    return IntArrayToPyList(rejectedObjs);
}

std::string PyDbMPolygon::className()
{
    return "AcDbMPolygon";
}

PyRxClass PyDbMPolygon::desc()
{
    return PyRxClass(AcDbMPolygon::desc(), false);
}

PyDbMPolygon PyDbMPolygon::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbMPolygon, AcDbMPolygon>(src);
}

PyDbMPolygon PyDbMPolygon::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMPolygon>(src);
}

AcDbMPolygon* PyDbMPolygon::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMPolygon*>(m_pyImp.get());
}
