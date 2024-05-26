#include "stdafx.h"
#include "PyDbSection.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbSectionSettingsWrapper()
{
    PyDocString DS("PyDb.SectionSettings");
    class_<PyDbSectionSettings, bases<PyDbObject>>("SectionSettings")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def("className", &PyDbSectionSettings::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSectionSettings::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSectionSettings::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSectionSettings::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbSectionSettings::SectionType>("SectionSectionType")
        .value("kLiveSection", AcDbSectionSettings::SectionType::kLiveSection)
        .value("k2dSection", AcDbSectionSettings::SectionType::k2dSection)
        .value("k3dSection", AcDbSectionSettings::SectionType::k3dSection)
        .export_values()
        ;
    enum_<AcDbSectionSettings::Geometry>("SectionGeometry")
        .value("kIntersectionBoundary", AcDbSectionSettings::Geometry::kIntersectionBoundary)
        .value("kIntersectionFill", AcDbSectionSettings::Geometry::kIntersectionFill)
        .value("kBackgroundGeometry", AcDbSectionSettings::Geometry::kBackgroundGeometry)
        .value("kForegroundGeometry", AcDbSectionSettings::Geometry::kForegroundGeometry)
        .value("kCurveTangencyLines", AcDbSectionSettings::Geometry::kCurveTangencyLines)
        .export_values()
        ;
    enum_<AcDbSectionSettings::Generation>("SectionGeneration")
        .value("kSourceAllObjects", AcDbSectionSettings::Generation::kSourceAllObjects)
        .value("kSourceSelectedObjects", AcDbSectionSettings::Generation::kSourceSelectedObjects)
        .value("kDestinationNewBlock", AcDbSectionSettings::Generation::kDestinationNewBlock)
        .value("kDestinationReplaceBlock", AcDbSectionSettings::Generation::kDestinationReplaceBlock)
        .value("kDestinationFile", AcDbSectionSettings::Generation::kDestinationFile)
        .export_values()
        ;
}

PyDbSectionSettings::PyDbSectionSettings()
    : PyDbSectionSettings(new AcDbSectionSettings(), true)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, mode), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, mode, erased), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(AcDbSectionSettings* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyRxClass PyDbSectionSettings::desc()
{
    return PyRxClass(AcDbSectionSettings::desc(), false);
}

std::string PyDbSectionSettings::className()
{
    return "AcDbSectionSettings";
}

PyDbSectionSettings PyDbSectionSettings::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSectionSettings, AcDbSectionSettings>(src);
}

PyDbSectionSettings PyDbSectionSettings::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSectionSettings>(src);
}

AcDbSectionSettings* PyDbSectionSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSectionSettings*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbSection
void makePyDbSectionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d, vecViewingDir: PyGe.Vector3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Section");
    class_<PyDbSection, bases<PyDbEntity>>("Section")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector3d&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("state", &PyDbSection::state)
        .def("setState", &PyDbSection::setState)
        .def("getName", &PyDbSection::getName)
        .def("setName", &PyDbSection::setName)
        .def("viewingDirection", &PyDbSection::viewingDirection)
        .def("setViewingDirection", &PyDbSection::setViewingDirection)
        .def("verticalDirection", &PyDbSection::verticalDirection)
        .def("setVerticalDirection", &PyDbSection::setVerticalDirection)
        .def("normal", &PyDbSection::normal)
        .def("plane", &PyDbSection::plane)
        .def("indicatorTransparency", &PyDbSection::indicatorTransparency)
        .def("setIndicatorTransparency", &PyDbSection::setIndicatorTransparency)
        .def("indicatorFillColor", &PyDbSection::indicatorFillColor)
        .def("setIndicatorFillColor", &PyDbSection::setIndicatorFillColor)
        .def("numVertices", &PyDbSection::numVertices)
        .def("getVertex", &PyDbSection::getVertex)
        .def("setVertex", &PyDbSection::setVertex)
        .def("addVertex", &PyDbSection::addVertex)
        .def("removeVertex", &PyDbSection::removeVertex)
        .def("getVertices", &PyDbSection::getVertices)
        .def("setVertices", &PyDbSection::setVertices)
        .def("height", &PyDbSection::height)
        .def("setHeight", &PyDbSection::setHeight)
        .def("hitTest", &PyDbSection::hitTest)
        .def("createJog", &PyDbSection::createJog)
        .def("getSettings", &PyDbSection::getSettings)
        .def("isLiveSectionEnabled", &PyDbSection::isLiveSectionEnabled)
        .def("enableLiveSection", &PyDbSection::enableLiveSection)
        .def("generateSectionGeometry", &PyDbSection::generateSectionGeometry)
        .def("elevation", &PyDbSection::elevation)
        .def("setElevation", &PyDbSection::setElevation)
        .def("topPlane", &PyDbSection::topPlane)
        .def("setTopPlane", &PyDbSection::setTopPlane)
        .def("bottomPlane", &PyDbSection::bottomPlane)
        .def("setBottomPlane", &PyDbSection::setBottomPlane)
        .def("isSlice", &PyDbSection::isSlice)
        .def("setIsSlice", &PyDbSection::setIsSlice)
        .def("thicknessDepth", &PyDbSection::thicknessDepth)
        .def("setThicknessDepth", &PyDbSection::setThicknessDepth)
        .def("hasJogs", &PyDbSection::hasJogs)
        .def("sectionPlaneOffset", &PyDbSection::sectionPlaneOffset)
        .def("setSectionPlaneOffset", &PyDbSection::setSectionPlaneOffset)
        .def("className", &PyDbSection::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSection::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSection::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSection::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbSection::State>("SectionState")
        .value("kPlane", AcDbSection::State::kPlane)
        .value("kBoundary", AcDbSection::State::kBoundary)
        .value("kVolume", AcDbSection::State::kVolume)
        .export_values()
        ;
    enum_<AcDbSection::SubItem>("SectionSubItem")
        .value("kNone", AcDbSection::SubItem::kNone)
        .value("kSectionLine", AcDbSection::SubItem::kSectionLine)
        .value("kSectionLineTop", AcDbSection::SubItem::kSectionLineTop)
        .value("kSectionLineBottom", AcDbSection::SubItem::kSectionLineBottom)
        .value("kBackLine", AcDbSection::SubItem::kBackLine)
        .value("kBackLineTop", AcDbSection::SubItem::kBackLineTop)
        .value("kBackLineBottom", AcDbSection::SubItem::kBackLineBottom)
        .value("kVerticalLineTop", AcDbSection::SubItem::kVerticalLineTop)
        .value("kVerticalLineBottom", AcDbSection::SubItem::kVerticalLineBottom)
        .export_values()
        ;
    enum_<AcDbSection::Height>("SectionHeight")
        .value("kHeightAboveSectionLine", AcDbSection::Height::kHeightAboveSectionLine)
        .value("kHeightBelowSectionLine", AcDbSection::Height::kHeightBelowSectionLine)
        .export_values()
        ;
}

PyDbSection::PyDbSection()
    : PyDbSection::PyDbSection(new AcDbSection(), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir, const AcGeVector3d& vecViewingDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir, vecViewingDir), true)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id)
    : PyDbSection(openAcDbObject<AcDbSection>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode, erased), false)
{
}

PyDbSection::PyDbSection(AcDbSection* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcDbSection::State PyDbSection::state(void) const
{
    return impObj()->state();
}

void PyDbSection::setState(AcDbSection::State nState)
{
    PyThrowBadEs(impObj()->setState(nState));
}

std::string PyDbSection::getName()
{
    return wstr_to_utf8(impObj()->getName());
}

void PyDbSection::setName(const std::string& name)
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

AcGeVector3d PyDbSection::viewingDirection(void) const
{
    return impObj()->viewingDirection();
}

void PyDbSection::setViewingDirection(const AcGeVector3d& dir)
{
    PyThrowBadEs(impObj()->setViewingDirection(dir));
}

AcGeVector3d PyDbSection::verticalDirection(void) const
{
    return impObj()->verticalDirection();
}

void PyDbSection::setVerticalDirection(const AcGeVector3d& dir)
{
    PyThrowBadEs(impObj()->setVerticalDirection(dir));
}

AcGeVector3d PyDbSection::normal(void) const
{
    return impObj()->normal();
}

boost::python::tuple PyDbSection::plane() const
{
    PyAutoLockGIL lock;
    AcGeVector3d uAxis;
    AcGeVector3d vAxis;
    PyThrowBadEs(impObj()->plane(uAxis, vAxis));
    return boost::python::make_tuple(uAxis, vAxis);
}

int PyDbSection::indicatorTransparency(void) const
{
    return impObj()->indicatorTransparency();
}

void PyDbSection::setIndicatorTransparency(int nTransparency)
{
    PyThrowBadEs(impObj()->setIndicatorTransparency(nTransparency));
}

AcCmColor PyDbSection::indicatorFillColor(void) const
{
    return impObj()->indicatorFillColor();
}

void PyDbSection::setIndicatorFillColor(const AcCmColor& color)
{
    PyThrowBadEs(impObj()->setIndicatorFillColor(color));
}

int PyDbSection::numVertices(void) const
{
    return impObj()->numVertices();
}

AcGePoint3d PyDbSection::getVertex(int nIndex)
{
    AcGePoint3d pt;
    PyThrowBadEs(impObj()->getVertex(nIndex, pt));
    return pt;
}

void PyDbSection::setVertex(int nIndex, const AcGePoint3d& pt)
{
    PyThrowBadEs(impObj()->setVertex(nIndex, pt));
}

void PyDbSection::addVertex(int nInsertAt, const AcGePoint3d& pt)
{
    PyThrowBadEs(impObj()->addVertex(nInsertAt, pt));
}

void PyDbSection::removeVertex(int nIndex)
{
    PyThrowBadEs(impObj()->removeVertex(nIndex));
}

boost::python::list PyDbSection::getVertices() const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pts;
    PyThrowBadEs(impObj()->getVertices(pts));
    return Point3dArrayToPyList(pts);
}

void PyDbSection::setVertices(const boost::python::list& pts)
{
    PyThrowBadEs(impObj()->setVertices(PyListToPoint3dArray(pts)));
}

double PyDbSection::height(AcDbSection::Height nHeightType) const
{
    return impObj()->height(nHeightType);
}

void PyDbSection::setHeight(AcDbSection::Height nHeightType, double fHeight)
{
    PyThrowBadEs(impObj()->setHeight(nHeightType, fHeight));
}

boost::python::tuple PyDbSection::hitTest(const AcGePoint3d& ptHit)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    int pSegmentIndex = -1;
    AcGePoint3d ptOnSegment;
    AcDbSection::SubItem pSubItem = AcDbSection::SubItem::kNone;
    bool res = impObj()->hitTest(ptHit, &pSegmentIndex, &ptOnSegment, &pSubItem);
    return boost::python::make_tuple(res, pSegmentIndex, ptOnSegment, pSubItem);
#endif
}

void PyDbSection::createJog(const AcGePoint3d& ptOnSection)
{
    PyThrowBadEs(impObj()->createJog(ptOnSection));
}

PyDbObjectId PyDbSection::getSettings(void) const
{
    return PyDbObjectId(impObj()->getSettings());
}

bool PyDbSection::isLiveSectionEnabled(void) const
{
    return impObj()->isLiveSectionEnabled();
}

void PyDbSection::enableLiveSection(bool bEnable)
{
    PyThrowBadEs(impObj()->enableLiveSection(bEnable));
}

boost::python::tuple PyDbSection::generateSectionGeometry(const PyDbEntity& pEnt)
{
    PyAutoLockGIL lock;
    AcArray<AcDbEntity*> intBoundaryEnts;
    AcArray<AcDbEntity*> intFillEnts;
    AcArray<AcDbEntity*> backgroundEnts;
    AcArray<AcDbEntity*> foregroundEnts;
    AcArray<AcDbEntity*> curveTangencyEnts;
    PyThrowBadEs(impObj()->generateSectionGeometry(pEnt.impObj(), intBoundaryEnts, intFillEnts, backgroundEnts, foregroundEnts, curveTangencyEnts));
    return boost::python::make_tuple(
        AcDbEntityArrayToPyList(intBoundaryEnts),
        AcDbEntityArrayToPyList(intFillEnts),
        AcDbEntityArrayToPyList(backgroundEnts),
        AcDbEntityArrayToPyList(foregroundEnts),
        AcDbEntityArrayToPyList(curveTangencyEnts));
}

double PyDbSection::elevation() const
{
    return impObj()->elevation();
}

void PyDbSection::setElevation(double elev)
{
    PyThrowBadEs(impObj()->setElevation(elev));
}

double PyDbSection::topPlane() const
{
    return impObj()->topPlane();
}

void PyDbSection::setTopPlane(double val)
{
    PyThrowBadEs(impObj()->setTopPlane(val));
}

double PyDbSection::bottomPlane() const
{
    return impObj()->bottomPlane();
}

void PyDbSection::setBottomPlane(double val)
{
    PyThrowBadEs(impObj()->setBottomPlane(val));
}

bool PyDbSection::isSlice() const
{
    return impObj()->isSlice();
}

void PyDbSection::setIsSlice(bool value)
{
    PyThrowBadEs(impObj()->setIsSlice(value));
}

double PyDbSection::thicknessDepth() const
{
    return impObj()->thicknessDepth();
}

void PyDbSection::setThicknessDepth(double fThickness)
{
    PyThrowBadEs(impObj()->setThicknessDepth(fThickness));
}

bool PyDbSection::hasJogs() const
{
    return impObj()->hasJogs();
}

double PyDbSection::sectionPlaneOffset() const
{
    return impObj()->sectionPlaneOffset();
}

void PyDbSection::setSectionPlaneOffset(double offset)
{
    PyThrowBadEs(impObj()->setSectionPlaneOffset(offset));
}

std::string PyDbSection::className()
{
    return "AcDbSection";
}

PyRxClass PyDbSection::desc()
{
    return PyRxClass(AcDbText::desc(), false);
}

PyDbSection PyDbSection::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSection, AcDbSection>(src);
}

PyDbSection PyDbSection::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSection>(src);
}

AcDbSection* PyDbSection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSection*>(m_pyImp.get());
}
