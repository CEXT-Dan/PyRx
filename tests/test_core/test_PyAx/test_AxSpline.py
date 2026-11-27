from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxSpline:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_spline(self, pnts=None, start_tangent=None, end_tangent=None):
        axSpace = self.axDoc.modelSpace()
        if pnts is None:
            pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        if start_tangent is None:
            start_tangent = Ge.Vector3d(1, 0, 0)
        if end_tangent is None:
            end_tangent = Ge.Vector3d(1, 0, 0)
        return axSpace.addSpline(pnts, start_tangent, end_tangent)

    # --- creation / identity ---

    def test_create(self):
        ent = self._add_spline()
        assert ent.objectName() == "AcDbSpline"
        assert ent.entityType() == Ax.AcEntityName.acSpline

    def test_cast(self):
        ent = self._add_spline()
        spline = Ax.AcadSpline.cast(ent)
        assert spline is not None
        assert isinstance(spline, Ax.AcadSpline)
        assert spline.objectName() == "AcDbSpline"

    def test_className(self):
        assert Ax.AcadSpline.className() == "AcadSpline"

    # --- fit points ---

    def test_fitPoints(self):
        pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        ent = self._add_spline(pnts)
        assert ent.fitPoints() == pnts

    def test_fitPoint(self):
        pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        ent = self._add_spline(pnts)
        assert ent.fitPoint(1) == pnts[1]

    def test_setFitPoint(self):
        pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        ent = self._add_spline(pnts)
        new_pt = Ge.Point3d(6, 6, 0)
        ent.setFitPoint(1, new_pt)
        assert ent.fitPoint(1) == new_pt

    def test_setFitPoints(self):
        ent = self._add_spline()
        new_pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 10, 0)]
        ent.setFitPoints(new_pnts)
        assert ent.fitPoints() == new_pnts

    def test_addFitPoint(self):
        ent = self._add_spline()
        n = len(ent.fitPoints())
        ent.addFitPoint(n, Ge.Point3d(20, 0, 0))
        assert len(ent.fitPoints()) == n + 1

    def test_deleteFitPoint(self):
        ent = self._add_spline()
        n = len(ent.fitPoints())
        ent.deleteFitPoint(1)
        assert len(ent.fitPoints()) == n - 1

    # --- control points ---

    def test_controlPoints(self):
        ent = self._add_spline()
        pts = ent.controlPoints()
        assert len(pts) > 0

    def test_controlPoint(self):
        ent = self._add_spline()
        assert ent.controlPoint(0) == ent.controlPoints()[0]

    def test_setControlPoint(self):
        ent = self._add_spline()
        new_pt = Ge.Point3d(100, 100, 0)
        ent.setControlPoint(0, new_pt)
        assert ent.controlPoint(0) == new_pt

    def test_setControlPoints(self):
        ent = self._add_spline()
        n = ent.numberOfControlPoints()
        new_pts = [Ge.Point3d(i, i, 0) for i in range(n)]
        ent.setControlPoints(new_pts)
        assert len(ent.controlPoints()) == n

    def test_numberOfControlPoints(self):
        ent = self._add_spline()
        assert ent.numberOfControlPoints() == len(ent.controlPoints())

    # --- degree ---

    def test_degree(self):
        ent = self._add_spline()
        assert ent.degree() in (2, 3)

    def test_elevateOrder(self):
        ent = self._add_spline()
        original = ent.degree()
        ent.elevateOrder(original + 2)
        assert ent.degree() > original

    # --- rationality / weights ---

    def test_isRational(self):
        ent = self._add_spline()
        assert ent.isRational() == False

    @pytest.mark.known_failure_ARX
    def test_weights(self):
        ent = self._add_spline()
        ws = ent.weights()
        assert len(ws) == ent.numberOfControlPoints()
        for w in ws:
            assert w == 1.0

    @pytest.mark.known_failure_ARX
    def test_weight(self):
        ent = self._add_spline()
        assert ent.weight(0) == 1.0

    def test_setWeight(self):
        ent = self._add_spline()
        ent.setWeight(0, 2.0)
        assert ent.weight(0) == 2.0

    @pytest.mark.known_failure_ARX
    def test_setWeights(self):
        ent = self._add_spline()
        n = ent.numberOfControlPoints()
        weights = [1.0] * n
        weights[0] = 2.0
        ent.setWeights(weights)
        assert ent.isRational() == True
        assert ent.weight(0) == 2.0

    # --- knots ---

    def test_knots(self):
        ent = self._add_spline()
        knots = ent.knots()
        assert len(knots) > 0

    # --- closed / periodic / planar ---

    def test_closed(self):
        ent = self._add_spline()
        assert ent.closed() == False

    @pytest.mark.known_failure_ARX
    def test_setClosed2(self):
        ent = self._add_spline()
        ent.setClosed2(True)
        assert ent.closed2() == True

    def test_isPeriodic(self):
        ent = self._add_spline()
        assert ent.isPeriodic() == False

    @pytest.mark.known_failure_ARX
    def test_isPlanar(self):
        ent = self._add_spline()
        result = ent.isPlanar()
        # Stub declares tuple[bool, Plane]; implementation may return plain bool
        if isinstance(result, tuple):
            assert result[0] == True
        else:
            assert result == True

    # --- tangents ---

    def test_startTangent(self):
        tangent = Ge.Vector3d(1, 0, 0)
        ent = self._add_spline(start_tangent=tangent)
        assert ent.startTangent().isParallelTo(tangent)

    def test_endTangent(self):
        tangent = Ge.Vector3d(0, 1, 0)
        ent = self._add_spline(end_tangent=tangent)
        assert ent.endTangent().isParallelTo(tangent)

    def test_setStartTangent(self):
        ent = self._add_spline()
        tangent = Ge.Vector3d(1, 1, 0)
        ent.setStartTangent(tangent)
        assert ent.startTangent().isParallelTo(tangent)

    def test_setEndTangent(self):
        ent = self._add_spline()
        tangent = Ge.Vector3d(1, 1, 0)
        ent.setEndTangent(tangent)
        assert ent.endTangent().isParallelTo(tangent)

    # --- method / frame / parameterization ---

    def test_splineMethod(self):
        ent = self._add_spline()
        assert ent.splineMethod() == Ax.AcSplineMethodType.acFit

    def test_setSplineMethod(self):
        ent = self._add_spline()
        ent.setSplineMethod(Ax.AcSplineMethodType.acControlVertices)
        assert ent.splineMethod() == Ax.AcSplineMethodType.acControlVertices

    def test_splineFrame(self):
        ent = self._add_spline()
        assert isinstance(ent.splineFrame(), Ax.AcSplineFrameType)

    def test_setSplineFrame(self):
        ent = self._add_spline()
        ent.setSplineFrame(Ax.AcSplineFrameType.acShow)
        assert ent.splineFrame() == Ax.AcSplineFrameType.acShow
        ent.setSplineFrame(Ax.AcSplineFrameType.acHide)
        assert ent.splineFrame() == Ax.AcSplineFrameType.acHide

    def test_knotParameterization(self):
        ent = self._add_spline()
        assert isinstance(ent.knotParameterization(), Ax.AcSplineKnotParameterizationType)

    def test_setKnotParameterization(self):
        ent = self._add_spline()
        ent.setKnotParameterization(Ax.AcSplineKnotParameterizationType.acChord)
        assert ent.knotParameterization() == Ax.AcSplineKnotParameterizationType.acChord

    # --- fit tolerance ---

    def test_fitTolerance(self):
        ent = self._add_spline()
        assert ent.fitTolerance() >= 0

    def test_setFitTolerance(self):
        ent = self._add_spline()
        ent.setFitTolerance(0.1)
        assert ent.fitTolerance() == 0.1

    # --- other ---

    def test_reverse(self):
        pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        ent = self._add_spline(pnts)
        ent.reverse()
        assert ent.fitPoints() == list(reversed(pnts))

    def test_offset(self):
        ent = self._add_spline()
        offsets = ent.offset(5)
        assert len(offsets) > 0

    def test_area(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        ent = self._add_spline(pnts)
        ent.setClosed2(True)
        assert ent.area() > 0

    def test_purgeFitData(self):
        ent = self._add_spline()
        ent.purgeFitData()
        assert len(ent.fitPoints()) == 0
