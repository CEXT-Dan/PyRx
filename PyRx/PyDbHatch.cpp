#include "stdafx.h"
#include "PyDbHatch.h"
#include "PyDbObjectId.h"
#include "PyGeCurve2d.h"

using namespace boost::python;

void makePyDbHatchWrapper()
{
    class_<PyDbHatch, bases<PyDbEntity>>("Hatch")
        .def(init<>())
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
#ifndef BRXAPP
        .value("kIsAnnotative", AcDbHatch::HatchLoopType::kIsAnnotative)
        .value("kDoesNotSupportScale", AcDbHatch::HatchLoopType::kDoesNotSupportScale)
        .value("kForceAnnoAllVisible", AcDbHatch::HatchLoopType::kForceAnnoAllVisible)
        .value("kOrientToPaper", AcDbHatch::HatchLoopType::kOrientToPaper)
        .value("kIsAnnotativeBlock", AcDbHatch::HatchLoopType::kIsAnnotativeBlock)
#endif // !BRXAPP
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
    : PyDbEntity(nullptr, false)
{
    AcDbHatch* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbHatch>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

double PyDbHatch::elevation() const
{
    return impObj()->elevation();
}

Acad::ErrorStatus PyDbHatch::setElevation(double elevation)
{
    return impObj()->setElevation(elevation);
}

AcGeVector3d PyDbHatch::normal() const
{
    return impObj()->normal();
}

Acad::ErrorStatus PyDbHatch::setNormal(const AcGeVector3d& normal)
{
    return impObj()->setNormal(normal);
}

AcCmColor PyDbHatch::backgroundColor() const
{
    return impObj()->backgroundColor();
}

Acad::ErrorStatus PyDbHatch::setBackgroundColor(const AcCmColor& color)
{
    return impObj()->setBackgroundColor(color);
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
    if (auto es = impObj()->getLoopAt(loopIndex, loopType, edgePtrs, edgeTypes); es != eOk)
        throw PyAcadErrorStatus(es);
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
    if (auto es = impObj()->getLoopAt(loopIndex, loopType, vertices, bulges); es != eOk)
        throw PyAcadErrorStatus(es);
    PyAutoLockGIL lock;
    boost::python::list verticesList;
    for (auto p : vertices)
        verticesList.append(p);
    boost::python::list bulgesList;
    for (auto b : bulges)
        bulgesList.append(b);
    return boost::python::make_tuple(loopType, verticesList, bulgesList);
}

Acad::ErrorStatus PyDbHatch::appendLoopEdges(Adesk::Int32 loopType, const boost::python::list& edgePtrs, const boost::python::list& edgeTypes)
{
    PyAutoLockGIL lock;
    AcGeVoidPointerArray _edgePtrs;
    AcGeIntArray _edgeTypes;
    auto curves = py_list_to_std_vector<PyGeCurve2d>(edgePtrs);
    for (const auto& curve : curves)
        _edgePtrs.append(curve.impObj()->copy());
    auto ints = py_list_to_std_vector<Int32>(edgeTypes);
    for (auto i : ints)
        _edgeTypes.append(i);
    return impObj()->appendLoop(loopType, _edgePtrs, _edgeTypes);
}

Acad::ErrorStatus PyDbHatch::appendLoopBulges(Adesk::Int32 loopType, const boost::python::list& vertices, const boost::python::list& bulges)
{
    PyAutoLockGIL lock;
    AcGePoint2dArray _vertices;
    AcGeDoubleArray _bulges;
    auto verts = py_list_to_std_vector<AcGePoint2d>(vertices);
    for (const auto& vert : verts)
        _vertices.append(vert);
    auto doubles = py_list_to_std_vector<double>(bulges);
    for (auto dbl : doubles)
        _bulges.append(dbl);
    return impObj()->appendLoop(loopType, _vertices, _bulges);
}

Acad::ErrorStatus PyDbHatch::removeLoopAt(int loopIndex)
{
    return impObj()->removeLoopAt(loopIndex);
}

bool PyDbHatch::associative() const
{
    return impObj()->associative();
}

Acad::ErrorStatus PyDbHatch::setAssociative(bool isAssociative)
{
    return impObj()->setAssociative(isAssociative);
}

Acad::ErrorStatus PyDbHatch::appendLoop(Adesk::Int32 loopType, const boost::python::list& dbObjIds)
{
    auto idsList = py_list_to_std_vector<PyDbObjectId>(dbObjIds);
    AcDbObjectIdArray ids;
    for (auto& id : idsList)
        ids.append(id.m_id);
    return impObj()->appendLoop(loopType, ids);
}

Acad::ErrorStatus PyDbHatch::insertLoopAt(int loopIndex, Adesk::Int32 loopType, const boost::python::list& dbObjIds)
{
    auto idsList = py_list_to_std_vector<PyDbObjectId>(dbObjIds);
    AcDbObjectIdArray ids;
    for (auto& id : idsList)
        ids.append(id.m_id);
    return impObj()->insertLoopAt(loopIndex, loopType, ids);
}

boost::python::list PyDbHatch::getAssocObjIdsAt(int loopIndex) const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list idsList;
    if (auto es = impObj()->getAssocObjIdsAt(loopIndex, ids); es != eOk)
        throw PyAcadErrorStatus(es);
    for (const auto& id : ids)
        idsList.append(PyDbObjectId(id));
    return idsList;
}

boost::python::list PyDbHatch::getAssocObjIds() const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list idsList;
    if (auto es = impObj()->getAssocObjIds(ids); es != eOk)
        throw PyAcadErrorStatus(es);
    for (const auto& id : ids)
        idsList.append(PyDbObjectId(id));
    return idsList;
}

Acad::ErrorStatus PyDbHatch::removeAssocObjIds()
{
    return impObj()->removeAssocObjIds();
}

AcDbHatch::HatchObjectType PyDbHatch::hatchObjectType() const
{
    return impObj()->hatchObjectType();
}

Acad::ErrorStatus PyDbHatch::setHatchObjectType(AcDbHatch::HatchObjectType type)
{
    return impObj()->setHatchObjectType(type);
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

Acad::ErrorStatus PyDbHatch::setGradient(AcDbHatch::GradientPatternType gradType, const std::string& gradName)
{
    return impObj()->setGradient(gradType, utf8_to_wstr(gradName).c_str());
}

double PyDbHatch::gradientAngle() const
{
    return impObj()->gradientAngle();
}

Acad::ErrorStatus PyDbHatch::setGradientAngle(double angle)
{
    return impObj()->setGradientAngle(angle);
}

boost::python::tuple PyDbHatch::getGradientColors()
{
    PyAutoLockGIL lock;
    unsigned int count = 0;
    float* values = nullptr;
    AcCmColor* clrs = nullptr;
    if (auto es = impObj()->getGradientColors(count, clrs, values); es != eOk)
        throw PyAcadErrorStatus(es);
    boost::python::list colorList;
    boost::python::list valueList;
    for (unsigned int idx = 0; idx < count; idx++)
    {
        colorList.append(clrs[idx]);
        valueList.append(values[idx]);
    }
    return boost::python::make_tuple(colorList, valueList);
}

Acad::ErrorStatus PyDbHatch::setGradientColors(const boost::python::list& colors, const boost::python::list& values)
{
    PyAutoLockGIL lock;
    auto _colors = py_list_to_std_vector<AcCmColor>(colors);
    auto _values = py_list_to_std_vector<float>(values);
    if (_colors.size() != _values.size())
        return eInvalidInput;
    return impObj()->setGradientColors(_colors.size(), _colors.data(), _values.data());
}

Adesk::Boolean PyDbHatch::getGradientOneColorMode() const
{
    return impObj()->getGradientOneColorMode();
}

Acad::ErrorStatus PyDbHatch::setGradientOneColorMode(Adesk::Boolean oneColorMode)
{
    return impObj()->setGradientOneColorMode(oneColorMode);
}

float PyDbHatch::getShadeTintValue() const
{
    return impObj()->getShadeTintValue();
}

Acad::ErrorStatus PyDbHatch::setShadeTintValue(float value)
{
    return impObj()->setShadeTintValue(value);
}

Acad::ErrorStatus PyDbHatch::setShadeTintValueAndColor2(float value)
{
    return impObj()->setShadeTintValueAndColor2(value);
}

float PyDbHatch::gradientShift() const
{
    return impObj()->gradientShift();
}

Acad::ErrorStatus PyDbHatch::setGradientShift(float shiftValue)
{
    return impObj()->setGradientShift(shiftValue);
}

AcCmColor PyDbHatch::evaluateGradientColorAt(float value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcCmColor clr;
    if (auto es = impObj()->evaluateGradientColorAt(value, clr); es != eOk)
        throw	PyAcadErrorStatus(es);
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

Acad::ErrorStatus PyDbHatch::setPattern(AcDbHatch::HatchPatternType patType, const std::string& patName)
{
    return impObj()->setPattern(patType, utf8_to_wstr(patName).c_str());
}

double PyDbHatch::patternAngle() const
{
    return impObj()->patternAngle();
}

Acad::ErrorStatus PyDbHatch::setPatternAngle(double angle)
{
    return impObj()->setPatternAngle(angle);
}

double PyDbHatch::patternSpace() const
{
    return impObj()->patternSpace();
}

Acad::ErrorStatus PyDbHatch::setPatternSpace(double space)
{
    return impObj()->setPatternSpace(space);
}

double PyDbHatch::patternScale() const
{
    return impObj()->patternScale();
}

Acad::ErrorStatus PyDbHatch::setPatternScale(double scale)
{
    return impObj()->setPatternScale(scale);
}

bool PyDbHatch::patternDouble() const
{
    return impObj()->patternDouble();
}

Acad::ErrorStatus PyDbHatch::setPatternDouble(bool isDouble)
{
    return impObj()->setPatternDouble(isDouble);
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
    if (auto es = impObj()->getPatternDefinitionAt(index, angle, baseX, baseY, offsetX, offsetY, dashes); es != eOk)
        throw PyAcadErrorStatus(es);
    boost::python::list _dashes;
    for (auto d : dashes)
        _dashes.append(d);
    return boost::python::make_tuple(angle, baseX, baseY, offsetX, offsetY, dashes);
}

AcDbHatch::HatchStyle PyDbHatch::hatchStyle() const
{
    return impObj()->hatchStyle();
}

Acad::ErrorStatus PyDbHatch::setHatchStyle(AcDbHatch::HatchStyle hstyle)
{
    return impObj()->setHatchStyle(hstyle);
}

Acad::ErrorStatus PyDbHatch::evaluateHatch1()
{
    return impObj()->evaluateHatch();
}

Acad::ErrorStatus PyDbHatch::evaluateHatch2(bool bUnderestimateNumLines)
{
    return impObj()->evaluateHatch(bUnderestimateNumLines);
}

Acad::ErrorStatus PyDbHatch::evaluateHatchAllScales1()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->evaluateHatchAllScales();
#endif
}

Acad::ErrorStatus PyDbHatch::evaluateHatchAllScales2(bool bUnderestimateNumLines)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->evaluateHatchAllScales(bUnderestimateNumLines);
#endif
}

bool PyDbHatch::lineGenerationEnabled() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->lineGenerationEnabled();
#endif
}

bool PyDbHatch::setLineGenerationEnabled(bool bEnable)
{
#ifdef BRXAPP
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
    if (auto es = impObj()->getHatchLineDataAt(index, startPt, endPt); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(startPt, endPt);
}

boost::python::tuple PyDbHatch::getHatchLinesData() const
{
    PyAutoLockGIL lock;
    AcGePoint2dArray startPts;
    AcGePoint2dArray endPts;
    if (auto es = impObj()->getHatchLinesData(startPts, endPts); es != eOk)
        throw PyAcadErrorStatus(es);
    boost::python::list _startPts;
    for (auto p : startPts)
        _startPts.append(p);
    boost::python::list _endPts;
    for (auto p : endPts)
        _endPts.append(p);
    return boost::python::make_tuple(_startPts, _endPts);
}

double PyDbHatch::getArea() const
{
    double a = 0.0;
    if (auto es = impObj()->getArea(a); es != eOk)
        throw PyAcadErrorStatus(es);
    return a;
}

Acad::ErrorStatus PyDbHatch::setOriginPoint(const AcGePoint2d& pt)
{
    return impObj()->setOriginPoint(pt);
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbHatch*>(m_pyImp.get());
}
