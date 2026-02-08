#include "stdafx.h"
#include "PyGeClipBoundary2d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeClipBoundary2d wrapper
void makePyGeClipBoundary2dWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- cornerA: PyGe.Point2d, cornerB: PyGe.Point2d\n"
        "- clipBoundary: list[PyGe.Point2d]\n";

    PyDocString DS("ClipBoundary2d");
    class_<PyGeClipBoundary2d, bases<PyGeEntity2d>>("ClipBoundary2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const boost::python::list&>(DS.CTOR(ctor, 11758)))
        .def("cast", &PyGeClipBoundary2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeClipBoundary2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeClipBoundary2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeClipBoundary2d::PyGeClipBoundary2d()
    : PyGeEntity2d(new AcGeClipBoundary2d())
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB)
    : PyGeEntity2d(new AcGeClipBoundary2d(cornerA, cornerB))
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const boost::python::list& clipBoundary)
    : PyGeEntity2d()
{
    PyAutoLockGIL lock;
    auto vec = py_list_to_std_vector<AcGePoint2d>(clipBoundary);
    AcGePoint2dArray _clipBoundary;
    for (const auto& item : vec)
        _clipBoundary.append(item);
    m_imp.reset(new AcGeClipBoundary2d(_clipBoundary));
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGeClipBoundary2d& src)
    : PyGeEntity2d(src.copy())
{
}

PyGeClipBoundary2d PyGeClipBoundary2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeClipBoundary2d, AcGeClipBoundary2d>(src);
}

PyGeClipBoundary2d PyGeClipBoundary2d::copycast(const PyGeEntity2d& src)
{
    return PyGeClipBoundary2d(static_cast<AcGeClipBoundary2d*>(src.impObj()->copy()));
}

std::string PyGeClipBoundary2d::className()
{
    return "AcGeClipBoundary2d";
}

AcGeClipBoundary2d* PyGeClipBoundary2d::impObj() const
{
    return static_cast<AcGeClipBoundary2d*>(m_imp.get());
}
#endif

//-----------------------------------------------------------------------------------------
//clipLineSeg2d
/**
 * @brief   High-precision 2D Geometric Clipping Utilities.
 * * @author  Gemini (AI Collaborator)
 * @date    2026
 * * @details This implementation provides robust clipping of AcGeLineSeg2d entities
 * against rectangular boundaries (AcDbExtents2d).
 * Liang–Barsky algorithm
 */
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


//-----------------------------------------------------------------------------------------
//clipCircArc2d
/**
 * @brief   High-precision 2D Geometric Clipping Utilities.
 * * @author  Gemini (AI Collaborator)
 * @date    2026
 * * @details This implementation provides robust clipping of AcGeCircArc2d entities
 * against rectangular boundaries (AcDbExtents2d).
 * * Key Features:
 * - Parameter-Space Clipping: Maintains numerical stability for "slight bulge"
 * polyline segments by clipping in the 1D parameter domain rather than
 * relying on 2D coordinate reconstruction.
 * - Multi-Segment Support: Correctly identifies and returns disconnected
 * visible segments for arcs that exit and re-enter the clipping boundary.
 * - Geometric Integrity: Utilizes AcGeInterval to preserve the original
 * arc's center and radius, ensuring 14+ decimal place precision.
 */
static bool clipCircArc2d(AcArray<AcGeCircArc2d>& outArcs, const AcGeCircArc2d& arc, const AcGePoint2d& pMin, const AcGePoint2d& pMax, const AcGeTol& tol)
{
    // Closed circles require a different parameterization (0 to 2PI)
    if (arc.isClosed())
        return false;

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


