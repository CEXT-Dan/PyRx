#include "stdafx.h"
#include "PyGeBoundBlock2d.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeClipBoundary2d.h"
#include "PyGeCurve3d.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- pt1: PyGe.Point2d, pt2: PyGe.Point2d\n"
        "- base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- pt1: PyGe.Point2d, pt2: PyGe.Point2d\n"
        "- base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d\n";

    PyDocString DS("BoundBlock2d");
    class_<PyGeBoundBlock2d, bases<PyGeEntity2d>>("BoundBlock2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&>(DS.CTOR(ctor, 11687)))
        .def("getMinPoint", &PyGeBoundBlock2d::getMinPoint, DS.ARGS())
        .def("getMaxPoint", &PyGeBoundBlock2d::getMaxPoint, DS.ARGS())
        .def("getBasePoint", &PyGeBoundBlock2d::getBasePoint, DS.ARGS())
        .def("getDirection1", &PyGeBoundBlock2d::getDirection1, DS.ARGS())
        .def("getDirection2", &PyGeBoundBlock2d::getDirection2, DS.ARGS())
        .def("set", &PyGeBoundBlock2d::set1)
        .def("set", &PyGeBoundBlock2d::set2, DS.OVRL(setOverloads))
        .def("extend", &PyGeBoundBlock2d::extend, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("swell", &PyGeBoundBlock2d::swell, DS.ARGS({ "val: float" }))
        .def("contains", &PyGeBoundBlock2d::contains, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("isDisjoint", &PyGeBoundBlock2d::isDisjoint, DS.ARGS({ "block: PyGe.BoundBlock2d" }))
        .def("clipLineSeg2d", &PyGeBoundBlock2d::clipLineSeg2d, DS.ARGS({ "seg2d: PyGe.LineSeg2d" }, 19140))
        .def("clipCircArc2d", &PyGeBoundBlock2d::clipCircArc2d, DS.ARGS({ "seg2d: PyGe.CircArc2d" }, 19141))
        .def("clipLineSeg3d", &PyGeBoundBlock2d::clipLineSeg3d, DS.ARGS({ "seg2d: PyGe.LineSeg3d" }, 19140))
        .def("clipCircArc3d", &PyGeBoundBlock2d::clipCircArc3d, DS.ARGS({ "seg2d: PyGe.CircArc3d" }, 19141))
        .def("isBox", &PyGeBoundBlock2d::isBox, DS.ARGS())
        .def("setToBox", &PyGeBoundBlock2d::setToBox, DS.ARGS({ "val: bool" }))
        .def("cast", &PyGeBoundBlock2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeBoundBlock2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeBoundBlock2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeBoundBlock2d::PyGeBoundBlock2d()
    : PyGeEntity2d(new AcGeBoundBlock2d())
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2)
    : PyGeEntity2d(new AcGeBoundBlock2d(point1, point2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2)
    : PyGeEntity2d(new AcGeBoundBlock2d(base, dir1, dir2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGeBoundBlock2d& block)
    : PyGeEntity2d(new AcGeBoundBlock2d(block))
{
}

AcGePoint2d PyGeBoundBlock2d::getMinPoint() const
{
    AcGePoint2d min, max;
    impObj()->getMinMaxPoints(min, max);
    return min;
}

AcGePoint2d PyGeBoundBlock2d::getMaxPoint() const
{
    AcGePoint2d min, max;
    impObj()->getMinMaxPoints(min, max);
    return max;
}

AcGePoint2d PyGeBoundBlock2d::getBasePoint() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return base;
}

AcGeVector2d PyGeBoundBlock2d::getDirection1() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return dir1;
}

AcGeVector2d PyGeBoundBlock2d::getDirection2() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return dir2;
}

void PyGeBoundBlock2d::set1(const AcGePoint2d& point1, const AcGePoint2d& point2) const
{
    impObj()->set(point1, point2);
}

void PyGeBoundBlock2d::set2(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2) const
{
    impObj()->set(base, dir1, dir2);
}

void PyGeBoundBlock2d::extend(const AcGePoint2d& point) const
{
    impObj()->extend(point);
}

void PyGeBoundBlock2d::swell(double distance) const
{
    impObj()->swell(distance);
}

Adesk::Boolean PyGeBoundBlock2d::contains(const AcGePoint2d& point) const
{
    return impObj()->contains(point);
}

Adesk::Boolean PyGeBoundBlock2d::isDisjoint(const PyGeBoundBlock2d& block) const
{
    return impObj()->isDisjoint(*block.impObj());
}

Adesk::Boolean PyGeBoundBlock2d::isBox() const
{
    return impObj()->isBox();
}

void PyGeBoundBlock2d::setToBox(Adesk::Boolean val) const
{
    impObj()->setToBox(val);
}

boost::python::tuple PyGeBoundBlock2d::clipLineSeg2d(const PyGeLineSeg2d& seg) const
{
    AcGeLineSeg2d outseg;
    bool flag = ::clipLineSeg2d(outseg, *seg.impObj(), *impObj());
    return boost::python::make_tuple(flag, PyGeLineSeg2d(outseg));
}

boost::python::tuple PyGeBoundBlock2d::clipLineSeg3d(const PyGeLineSeg3d& seg) const
{
    AcGeLineSeg3d outseg;
    bool flag = ::clipLineSeg3d(outseg, *seg.impObj(), *impObj());
    return boost::python::make_tuple(flag, PyGeLineSeg3d(outseg));
}

boost::python::tuple PyGeBoundBlock2d::clipCircArc2d(const PyGeCircArc2d& seg) const
{
    AcArray<AcGeCircArc2d> outsegs;
    bool flag = ::clipCircArc2d(outsegs, *seg.impObj(), *impObj());
    boost::python::list _pylist;
    for (const auto& outseg : outsegs)
        _pylist.append(PyGeCircArc2d(outseg));
    return boost::python::make_tuple(flag, _pylist);
}

boost::python::tuple PyGeBoundBlock2d::clipCircArc3d(const PyGeCircArc3d& seg) const
{
    AcArray<AcGeCircArc3d> outsegs;
    bool flag = ::clipCircArc3d(outsegs, *seg.impObj(), *impObj());
    boost::python::list _pylist;
    for (const auto& outseg : outsegs)
        _pylist.append(PyGeCircArc3d(outseg));
    return boost::python::make_tuple(flag, _pylist);
}

PyGeBoundBlock2d PyGeBoundBlock2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeBoundBlock2d, AcGeBoundBlock2d>(src);
}

PyGeBoundBlock2d PyGeBoundBlock2d::copycast(const PyGeEntity2d& src)
{
    return PyGeBoundBlock2d(static_cast<AcGeBoundBlock2d*>(src.impObj()->copy()));
}

std::string PyGeBoundBlock2d::className()
{
    return "AcGeBoundBlock2d";
}

AcGeBoundBlock2d* PyGeBoundBlock2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeBoundBlock2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//clipLineSeg2d
static bool clipTest(double p, double q, double& u1, double& u2, const AcGeTol& tol)
{
    const double eps = tol.equalPoint();

    if (fabs(p) <= eps)
    {
        // Line is parallel to clipping edge
        return q >= -eps;
    }

    const double r = q / p;

    if (p < 0.0)
    {
        if (r > u2 + eps) return false;
        if (r > u1) u1 = r;
    }
    else
    {
        if (r < u1 - eps) return false;
        if (r < u2) u2 = r;
    }

    return true;
}

static bool clipLineSeg2d(AcGeLineSeg2d& outSeg, const AcGeLineSeg2d& seg, const AcGePoint2d& min, const AcGePoint2d& max, const AcGeTol& tol)
{
    const AcGePoint2d& p0 = seg.startPoint();
    const AcGePoint2d& p1 = seg.endPoint();

    const double dx = p1.x - p0.x;
    const double dy = p1.y - p0.y;

    double u1 = 0.0;
    double u2 = 1.0;

    const double xmin = min.x;
    const double ymin = min.y;
    const double xmax = max.x;
    const double ymax = max.y;

    if (!clipTest(-dx, p0.x - xmin, u1, u2, tol)) return false;
    if (!clipTest(dx, xmax - p0.x, u1, u2, tol)) return false;
    if (!clipTest(-dy, p0.y - ymin, u1, u2, tol)) return false;
    if (!clipTest(dy, ymax - p0.y, u1, u2, tol)) return false;

    if (u2 < u1)
        return false;

    outSeg.set(
        AcGePoint2d(
            p0.x + u1 * dx,
            p0.y + u1 * dy),
        AcGePoint2d(
            p0.x + u2 * dx,
            p0.y + u2 * dy));

    return outSeg.length() > 0;
}

static bool clipLineSeg3d(AcGeLineSeg3d& outSeg, const AcGeLineSeg3d& seg, const AcGePoint2d& min, const AcGePoint2d& max, const AcGeTol& tol)
{
    AcGeLineSeg2d inSeg2d(AcGePoint2d(seg.startPoint().x, seg.startPoint().y), AcGePoint2d(seg.endPoint().x, seg.endPoint().y));
    AcGeLineSeg2d outSeg2d;
    bool flag = clipLineSeg2d(outSeg2d, inSeg2d, min, max, tol);
    outSeg.set(AcGePoint3d(seg.startPoint().x, seg.startPoint().y, 0), AcGePoint3d(seg.endPoint().x, seg.endPoint().y, 0));
    return flag;
}

bool clipLineSeg2d(AcGeLineSeg2d& outSeg, const AcGeLineSeg2d& seg, const AcDbExtents2d& extents, const AcGeTol& tol)
{
    return clipLineSeg2d(outSeg, seg, extents.minPoint(), extents.maxPoint(), tol);
}

bool clipLineSeg2d(AcGeLineSeg2d& outSeg, const AcGeLineSeg2d& seg, const AcGeBoundBlock2d& extents, const AcGeTol& tol /*= AcGeContext::gTol*/)
{
    AcGePoint2d min;
    AcGePoint2d max;
    extents.getMinMaxPoints(min, max);
    return clipLineSeg2d(outSeg, seg, min, max, tol);
}

bool clipLineSeg3d(AcGeLineSeg3d& outSeg, const AcGeLineSeg3d& seg, const AcDbExtents2d& extents, const AcGeTol& tol /*= AcGeContext::gTol*/)
{
    return clipLineSeg3d(outSeg, seg, extents.minPoint(), extents.maxPoint(), tol);
}

bool clipLineSeg3d(AcGeLineSeg3d& outSeg, const AcGeLineSeg3d& seg, const AcGeBoundBlock2d& extents, const AcGeTol& tol /*= AcGeContext::gTol*/)
{
    AcGePoint2d min;
    AcGePoint2d max;
    extents.getMinMaxPoints(min, max);
    return clipLineSeg3d(outSeg, seg, min, max, tol);
}
//-----------------------------------------------------------------------------------------
//clipCircArc2d
static bool clipClosedCircle2d(AcArray<AcGeCircArc2d>& outArcs, const AcGeCircArc2d& arc, const AcGePoint2d& pMin, const AcGePoint2d& pMax, const AcGeTol& tol)
{
    // 1. Fetch domain boundaries (usually 0 to 2PI)
    AcGeInterval interval;
    arc.getInterval(interval);
    double startT, endT;
    interval.getBounds(startT, endT);
    const double period = endT - startT;
    const double eps = tol.equalPoint();

    const AcGeLineSeg2d edges[4] = {
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMin.y), AcGePoint2d(pMax.x, pMin.y)), // Bottom
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMin.y), AcGePoint2d(pMax.x, pMax.y)), // Right
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMax.y), AcGePoint2d(pMin.x, pMax.y)), // Top
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMax.y), AcGePoint2d(pMin.x, pMin.y))  // Left
    };

    // 2. Find all intersection parameters along the curve
    std::vector<double> params;
    for (const auto& edge : edges) {
        int found = 0;
        AcGePoint2d p1, p2;
        if (arc.intersectWith(edge, found, p1, p2, tol)) {
            if (found >= 1) params.push_back(arc.paramOf(p1, tol));
            if (found >= 2) params.push_back(arc.paramOf(p2, tol));
        }
    }

    // 3. Handle non-intersecting circles (Fully Inside or Fully Outside)
    if (params.empty()) {
        AcGePoint2d center = arc.center();
        if (center.x >= pMin.x - eps && center.x <= pMax.x + eps &&
            center.y >= pMin.y - eps && center.y <= pMax.y + eps)
        {
            outArcs.append(arc);
            return true;
        }
        return false;
    }

    // 4. Sort and remove duplicate intersection points
    std::sort(params.begin(), params.end());
    params.erase(std::unique(params.begin(), params.end(), [&](double a, double b) {
        return std::abs(a - b) < eps;
        }), params.end());

    bool foundAny = false;

    // 5. Evaluate regular intervals between consecutive intersections
    for (size_t i = 0; i < params.size() - 1; ++i)
    {
        double midT = (params[i] + params[i + 1]) * 0.5;
        AcGePoint2d midPt = arc.evalPoint(midT);

        if (midPt.x >= pMin.x - eps && midPt.x <= pMax.x + eps &&
            midPt.y >= pMin.y - eps && midPt.y <= pMax.y + eps)
        {
            AcGeCircArc2d segment{ arc };
            segment.setInterval(AcGeInterval(params[i], params[i + 1]));
            outArcs.append(segment);
            foundAny = true;
        }
    }

    // 6. Handle the critical wrap-around interval (from last param back to first param)
    double wrapMidT = (params.back() + (params.front() + period)) * 0.5;
    if (wrapMidT > endT) {
        wrapMidT -= period;
    }

    AcGePoint2d wrapMidPt = arc.evalPoint(wrapMidT);
    if (wrapMidPt.x >= pMin.x - eps && wrapMidPt.x <= pMax.x + eps &&
        wrapMidPt.y >= pMin.y - eps && wrapMidPt.y <= pMax.y + eps)
    {
        AcGeCircArc2d segment{ arc };
        // Front boundary parameter shifted by 2PI creates a valid continuous arc tracking forward
        segment.setInterval(AcGeInterval(params.back(), params.front() + period));
        outArcs.append(segment);
        foundAny = true;
    }

    return foundAny;
}

static bool clipCircArc2d(AcArray<AcGeCircArc2d>& outArcs, const AcGeCircArc2d& arc, const AcGePoint2d& pMin, const AcGePoint2d& pMax, const AcGeTol& tol)
{
    // Closed circles require a different parameterization (0 to 2PI)
    if (arc.isClosed())
        return clipClosedCircle2d(outArcs, arc, pMin, pMax, tol);

    // 1. Initialize parameter collection with the arc's existing bounds
    AcGeInterval interval;
    arc.getInterval(interval);
    double startT, endT;
    interval.getBounds(startT, endT);

    std::vector<double> params;
    params.push_back(startT);
    params.push_back(endT);

    const AcGeLineSeg2d edges[4] = {
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMin.y), AcGePoint2d(pMax.x, pMin.y)), // Bottom
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMin.y), AcGePoint2d(pMax.x, pMax.y)), // Right
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMax.y), AcGePoint2d(pMin.x, pMax.y)), // Top
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMax.y), AcGePoint2d(pMin.x, pMin.y))  // Left
    };

    // 3. Find all intersection parameters along the curve
    for (const auto& edge : edges) {
        int found = 0;
        AcGePoint2d p1, p2;
        // intersectWith on CircArc2d correctly respects the arc's current interval
        if (arc.intersectWith(edge, found, p1, p2, tol)) {
            if (found >= 1) params.push_back(arc.paramOf(p1, tol));
            if (found >= 2) params.push_back(arc.paramOf(p2, tol));
        }
    }

    // 4. Sort and remove duplicates to create clean sub-intervals
    std::sort(params.begin(), params.end());
    params.erase(std::unique(params.begin(), params.end(), [&](double a, double b) {
        return std::abs(a - b) < tol.equalPoint();
        }), params.end());

    // 5. Evaluate the midpoint of each sub-interval against the boundary
    const double eps = tol.equalPoint();
    bool foundAny = false;

    for (size_t i = 0; i < params.size() - 1; ++i)
    {
        const double midT = (params[i] + params[i + 1]) * 0.5;
        const AcGePoint2d midPt = arc.evalPoint(midT);

        // Check if the segment midpoint is within the view boundary
        if (midPt.x >= pMin.x - eps && midPt.x <= pMax.x + eps &&
            midPt.y >= pMin.y - eps && midPt.y <= pMax.y + eps)
        {
            AcGeCircArc2d segment{ arc }; // copy ctor original geometry (center, radius, orientation)
            segment.setInterval(AcGeInterval(params[i], params[i + 1])); // Trim to the clip interval
            outArcs.append(segment);
            foundAny = true;
        }
    }

    return foundAny;
}

//-----------------------------------------------------------------------------------------
//clipCircArc3d
static bool clipClosedCircle3d(AcArray<AcGeCircArc3d>& outArcs, const AcGeCircArc3d& arc, const AcGePoint2d& pMin, const AcGePoint2d& pMax, const AcGeTol& tol)
{
    if (!arc.isClosed())
        return false;

    // 1. Project the 3D closed circle to 2D
    AcGePoint3d center3d = arc.center();
    AcGePoint2d center2d(center3d.x, center3d.y);

    AcGeInterval interval;
    arc.getInterval(interval);
    double startT, endT;
    interval.getBounds(startT, endT);
    const double period = endT - startT;
    const double eps = tol.equalPoint();

    // Recreate a full closed circle in 2D
    AcGeCircArc2d arc2d(center2d, arc.radius());

    const AcGeLineSeg2d edges[4] = {
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMin.y), AcGePoint2d(pMax.x, pMin.y)), // Bottom
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMin.y), AcGePoint2d(pMax.x, pMax.y)), // Right
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMax.y), AcGePoint2d(pMin.x, pMax.y)), // Top
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMax.y), AcGePoint2d(pMin.x, pMin.y))  // Left
    };

    // 2. Compute intersection points in 2D
    std::vector<double> params;
    for (const auto& edge : edges) {
        int found = 0;
        AcGePoint2d p1, p2;
        if (arc2d.intersectWith(edge, found, p1, p2, tol)) {
            if (found >= 1) params.push_back(arc2d.paramOf(p1, tol));
            if (found >= 2) params.push_back(arc2d.paramOf(p2, tol));
        }
    }

    // 3. Handle non-intersecting full circles
    if (params.empty()) {
        if (center2d.x >= pMin.x - eps && center2d.x <= pMax.x + eps &&
            center2d.y >= pMin.y - eps && center2d.y <= pMax.y + eps)
        {
            outArcs.append(arc);
            return true;
        }
        return false;
    }

    // 4. Sort and deduplicate parameters
    std::sort(params.begin(), params.end());
    params.erase(std::unique(params.begin(), params.end(), [&](double a, double b) {
        return std::abs(a - b) < eps;
        }), params.end());

    bool foundAny = false;

    // 5. Evaluate consecutive standard intervals
    for (size_t i = 0; i < params.size() - 1; ++i)
    {
        double midT = (params[i] + params[i + 1]) * 0.5;
        AcGePoint2d midPt = arc2d.evalPoint(midT);

        if (midPt.x >= pMin.x - eps && midPt.x <= pMax.x + eps &&
            midPt.y >= pMin.y - eps && midPt.y <= pMax.y + eps)
        {
            AcGeCircArc3d segment{ arc };
            segment.setInterval(AcGeInterval(params[i], params[i + 1]));
            outArcs.append(segment);
            foundAny = true;
        }
    }

    // 6. Evaluate the critical periodic wrap-around boundary segment
    double wrapMidT = (params.back() + (params.front() + period)) * 0.5;
    if (wrapMidT > endT) {
        wrapMidT -= period;
    }

    AcGePoint2d wrapMidPt = arc2d.evalPoint(wrapMidT);
    if (wrapMidPt.x >= pMin.x - eps && wrapMidPt.x <= pMax.x + eps &&
        wrapMidPt.y >= pMin.y - eps && wrapMidPt.y <= pMax.y + eps)
    {
        AcGeCircArc3d segment{ arc };
        segment.setInterval(AcGeInterval(params.back(), params.front() + period));
        outArcs.append(segment);
        foundAny = true;
    }

    return foundAny;
}

static bool clipCircArc3d(AcArray<AcGeCircArc3d>& outArcs, const AcGeCircArc3d& arc, const AcGePoint2d& pMin, const AcGePoint2d& pMax, const AcGeTol& tol)
{
    // Route closed circles out immediately
    if (arc.isClosed())
        return clipClosedCircle3d(outArcs, arc, pMin, pMax, tol);

    // 1. Convert the 3D arc to its flat 2D projection on the XY plane
    // (Drops the Z component of the center, preserves radius and planar orientation)
    AcGePoint3d center3d = arc.center();
    AcGePoint2d center2d(center3d.x, center3d.y);

    // Retrieve the open bounds from the 3D curve
    AcGeInterval interval;
    arc.getInterval(interval);
    double startT, endT;
    interval.getBounds(startT, endT);

    // Build the projected 2D arc representing our 3D curve geometry
    // Project the 3D reference vector to 2D by extracting its X and Y components
    AcGeVector3d refVec3d = arc.refVec();
    AcGeVector2d refVec2d(refVec3d.x, refVec3d.y);

    // Correctly instantiate the 2D arc
    AcGeCircArc2d arc2d(center2d, arc.radius(), startT, endT, refVec2d, false);

    std::vector<double> params;
    params.push_back(startT);
    params.push_back(endT);

    const AcGeLineSeg2d edges[4] = {
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMin.y), AcGePoint2d(pMax.x, pMin.y)), // Bottom
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMin.y), AcGePoint2d(pMax.x, pMax.y)), // Right
        AcGeLineSeg2d(AcGePoint2d(pMax.x, pMax.y), AcGePoint2d(pMin.x, pMax.y)), // Top
        AcGeLineSeg2d(AcGePoint2d(pMin.x, pMax.y), AcGePoint2d(pMin.x, pMin.y))  // Left
    };

    // 2. Perform intersection checks in 2D
    for (const auto& edge : edges) {
        int found = 0;
        AcGePoint2d p1, p2;
        if (arc2d.intersectWith(edge, found, p1, p2, tol)) {
            if (found >= 1) params.push_back(arc2d.paramOf(p1, tol));
            if (found >= 2) params.push_back(arc2d.paramOf(p2, tol));
        }
    }

    // 3. Sort and deduplicate parameters
    std::sort(params.begin(), params.end());
    const double eps = tol.equalPoint();
    params.erase(std::unique(params.begin(), params.end(), [&](double a, double b) {
        return std::abs(a - b) < eps;
        }), params.end());

    bool foundAny = false;

    // 4. Test intervals and trim the 3D curves
    for (size_t i = 0; i < params.size() - 1; ++i)
    {
        const double midT = (params[i] + params[i + 1]) * 0.5;
        const AcGePoint2d midPt = arc2d.evalPoint(midT);

        if (midPt.x >= pMin.x - eps && midPt.x <= pMax.x + eps &&
            midPt.y >= pMin.y - eps && midPt.y <= pMax.y + eps)
        {
            AcGeCircArc3d segment{ arc }; // Copy full native 3D geometry (plane, normal, center)
            segment.setInterval(AcGeInterval(params[i], params[i + 1])); // Apply the 2D computed bounds
            outArcs.append(segment);
            foundAny = true;
        }
    }

    return foundAny;
}

bool clipCircArc2d(AcArray<AcGeCircArc2d>& outArcs, const AcGeCircArc2d& arc, const AcDbExtents2d& extents, const AcGeTol& tol)
{
    return clipCircArc2d(outArcs, arc, extents.minPoint(), extents.maxPoint(), tol);
}

bool clipCircArc2d(AcArray<AcGeCircArc2d>& outArcs, const AcGeCircArc2d& arc, const AcGeBoundBlock2d& extents, const AcGeTol& tol)
{
    AcGePoint2d min;
    AcGePoint2d max;
    extents.getMinMaxPoints(min, max);
    return clipCircArc2d(outArcs, arc, min, max, tol);
}

bool clipCircArc3d(AcArray<AcGeCircArc3d>& outArcs, const AcGeCircArc3d& arc, const AcDbExtents2d& extents, const AcGeTol& tol /*= AcGeContext::gTol*/)
{
    return clipCircArc3d(outArcs, arc, extents.minPoint(), extents.maxPoint(), tol);
}

bool clipCircArc3d(AcArray<AcGeCircArc3d>& outArcs, const AcGeCircArc3d& arc, const AcGeBoundBlock2d& extents, const AcGeTol& tol /*= AcGeContext::gTol*/)
{
    AcGePoint2d min;
    AcGePoint2d max;
    extents.getMinMaxPoints(min, max);
    return clipCircArc3d(outArcs, arc, min, max, tol);
}

